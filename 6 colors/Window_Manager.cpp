#include "Window_Manager.h"
#include "ShapeContainer.h"

Window_Manager::Window_Manager()
{
	Setstage();
	tagged.push_back(container.getFirstIndex());
	AI_vec.push_back(container.getAIindex());
	Max_Score = container.shapes.size();
	GameWindow();
}

bool Window_Manager::getAgain()
{
	return again;
}

void Window_Manager::setAgain(bool var)
{
	again = var;
}

void Window_Manager::GameWindow()
{
	bool gameend = false;
	AI oponent;
	oponent.setIndex(container.getAIindex());
	int ID;
	bool clicked;			
	while (window.isOpen())
	{
		if (gameend)
			window.close();
		if (failed)
			window.close();
		if (game_end)
			PlayAgain();
	
		mousepos = Mouse::getPosition(window);
		coords = window.mapPixelToCoords(mousepos);
		size_t prev_size = tagged.size();
		int counter = 0;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					if (yesno[0].getGlobalBounds().contains(coords))
					{
						again = true;
						gameend = true;
					}
					if (yesno[1].getGlobalBounds().contains(coords))
					{
						again = false;
						gameend = true;
					}
					if (!gameend)
					{
						clicked = findColor();

						if (clicked && color != my_prev)
						{
							my_score += movement(tagged);
							nscore[0].setString(std::to_string(my_score));
							my_prev = color;
							ID = oponent.CalculateMove(color, container, AI_vec);
							color = findColor(ID);
							sprite[1].setPosition(colors[ID - 1].getPosition().x, colors[ID - 1].getPosition().y - 4);
							AI_score += movement(AI_vec);
							nscore[1].setString(std::to_string(AI_score));
							prev_color = color;
						}
						if (my_score > Max_Score / 2)
							game_end = true;
						if (AI_score > Max_Score / 2)
							game_end = true;
					}
				}
			}						
			

		}

		

		window.draw(map.getBackground());
		for (int i = 0; i < 6; i++)
		window.draw(colors[i]);
		window.draw(map.getMap());
		for (int i = 0; i < 2; i++)
		{
			window.draw(Tscore[i]);
			window.draw(nscore[i]);
			window.draw(sprite[i]);
		}
		for (int i = 0; i < container.shapes.size(); i++)
			window.draw(*container.shapes[i]);
		window.draw(textBox);
		window.draw(message);
		window.draw(askbox);
		window.draw(asktext);
		for (int i = 0; i < 2; i++)
		{
			window.draw(yesno[i]);
			window.draw(yesnotext[i]);
		}
		//for(int i=0;i<container.boundvec.size();i++)
		//window.draw(*container.boundvec[100]);
		//window.draw(*container.boundvec[103]);
		window.display();
	}
	for (int i = 0; i < container.shapes.size(); i++)
		delete[] container.shapes[i];
	container.shapes.clear();
}




Window_Manager::~Window_Manager()
{
}

void Window_Manager::Setstage()
{
	
	Vector2f windowsize(900, 900);
	Vector2i screenstartpos(0, 0);
	Vector2f screenendpos(screenstartpos.x + windowsize.x, screenstartpos.y + windowsize.y);
	Vector2f SizeAnnoyance((float)screenendpos.x/5-50, (float)screenendpos.y / 5 -30);
	window.create(VideoMode(1050,900), "6-Colors", WINDOW_MODE);
	window.setPosition(screenstartpos);
	
	

	for (int i = 0; i < 6; i++)
	{
		colors[i].setOutlineThickness(1);
		colors[i].setOutlineColor(Color::Black);
		colors[i].setPosition(screenstartpos.x+i*distance+85, screenendpos.y - (screenendpos.y / 6)-20);
		colors[i].setSize(SizeAnnoyance);
	}
	setColors();
	setTexts();
	setX();

}




void Window_Manager::setColors()
{
	colors[0].setFillColor(Color::Red);
	colors[1].setFillColor(Color(255, 165, 0));
	colors[2].setFillColor(Color::Yellow);
	colors[3].setFillColor(Color::Green);
	colors[4].setFillColor(Color::Blue);
	colors[5].setFillColor(Color::Magenta);

	for (int i = 0; i < 6; i++)
	{
		colors[i].setOutlineColor(Color::Black);
		colors[i].setOutlineThickness(2);
	}
}

bool Window_Manager::findColor()
{
	bool clicked = false;
	for (int i = 0; i < 6; i++)
		if (colors[i].getGlobalBounds().contains(coords))
		{
			if (prev_color != colors[i].getFillColor())
			{
				color = colors[i].getFillColor();
				clicked = true;
				sprite[0].setPosition(colors[i].getPosition().x,colors[i].getPosition().y - 4);
				break;
			}
		}
	return clicked;
}

void Window_Manager::FieldCheck()
{
	bool changed = false;

	for (int i = 0; i < container.shapes.size(); i++)
	{
		if (container.shapes[i]->getGlobalBounds().contains(coords))
			for (int j = 0; j < container.index[i].size(); j++)
			{
				container.shapes[container.index[i][j]]->setFillColor(Color::White);
				changed = true;
			}
		if (changed)
			break;
	}
}

int Window_Manager::movement(vector<int>& tagged)
{
	int i = -1;
	int counter = 0;
	size_t prev_size = tagged.size();
	while (true)
	{
		i += 1;
		if (i == tagged.size())
			break;

		for (int j = 0; j < container.index[tagged[i]].size(); j++)
		{

			if (MOVE_MACRO)
			{
				container.shapes[container.index[tagged[i]][j]]->setOutlineColor(Color(0, 80, 0));
				tagged.push_back(container.index[tagged[i]][j]);
				counter += 1;
			}
		}
	}

		for (int i = 0; i < prev_size; i++)
		{
			container.shapes[tagged[i]]->setFillColor(color);
		}
		return counter;
}

Color Window_Manager::findColor(int ID)
{
	Color temp;
	if (ID == 1)
		temp = Color::Red;
	if (ID ==2)
		temp = Color(255, 165, 0);
	if (ID == 3)
		temp = Color::Yellow;
	if (ID == 4)
		temp = Color::Green;
	if (ID == 5)
		temp = Color::Blue;
	if (ID == 6)
		temp = Color::Magenta;

	return temp;
} 

void Window_Manager::setTexts()
{
	std::string fontname("TravelingTypewriter.ttf");
	font.loadFromFile(fontname);
	if (!font.loadFromFile(fontname))
	{
		std::cout << "failed to load font: " << fontname << std::endl;
		failed = true;
	}

	Tscore[0].setFont(font);
	Tscore[0].setPosition(Vector2f(30.f, 34.f));
	Tscore[0].setCharacterSize(25);
	Tscore[0].setString("Your Score:");
	Tscore[0].setFillColor(Color::White);
	Tscore[0].setOutlineColor(Color::Black);
	Tscore[0].setOutlineThickness(2);

	Tscore[1].setFont(font);
	Tscore[1].setPosition(Vector2f(900.f, 34.f));
	Tscore[1].setCharacterSize(25);
	Tscore[1].setString("AI Score:");
	Tscore[1].setFillColor(Color::White);
	Tscore[1].setOutlineColor(Color::Black);
	Tscore[1].setOutlineThickness(2);

	nscore[0].setFont(font);
	nscore[0].setPosition(Vector2f(30.f, 60.f));
	nscore[0].setCharacterSize(25);
	nscore[0].setString("0");
	nscore[0].setFillColor(Color::White);
	nscore[0].setOutlineColor(Color::Black);
	nscore[0].setOutlineThickness(2);

	nscore[1].setFont(font);
	nscore[1].setPosition(Vector2f(900.f, 60.f));
	nscore[1].setCharacterSize(25);
	nscore[1].setString("0");
	nscore[1].setFillColor(Color::White);
	nscore[1].setOutlineColor(Color::Black);
	nscore[1].setOutlineThickness(2);
}

void Window_Manager::setX()
{
	std::string bigx("BIGX.PNG");
	texture.loadFromFile(bigx);
	if (!texture.loadFromFile(bigx))
		failed = true;
	sprite[0].setTexture(texture);
	sprite[1].setTexture(texture);
	sprite[0].setPosition(Vector2f(-50.f, -200.f));
	sprite[1].setPosition(Vector2f(-50.f, -400.f));
}

void Window_Manager::PlayAgain()
{
	textBox.setFillColor(Color::Cyan);
	textBox.setOutlineColor(Color::Black);
	textBox.setOutlineThickness(4);
	textBox.setPosition(Vector2f(365.f, Tscore[0].getPosition().y+5));
	textBox.setSize(Vector2f(300.f, 60.f));
		message.setFont(font);
		message.setCharacterSize(56);
		message.setFillColor(Color::Black);
		message.setPosition(Vector2f(400.f, Tscore[0].getPosition().y));
		if (my_score > AI_score)
			message.setString("You WON! ");
			if (my_score < AI_score)
				message.setString("AI WON! ");
			askbox.setPosition(textBox.getPosition().x, textBox.getPosition().y + 200.f);
			askbox.setSize(textBox.getSize());
			askbox.setFillColor(textBox.getFillColor());
			askbox.setOutlineColor(textBox.getOutlineColor());
			askbox.setOutlineThickness(textBox.getOutlineThickness());
			asktext.setFont(font);
			asktext.setPosition(askbox.getPosition());
			asktext.setCharacterSize(46);
			asktext.setFillColor(Color::Black);
			asktext.setString("Play Again? ");
			int dist = 400;
			for (int i= 0; i < 2 ; i++)
			{
				yesno[i].setSize(Vector2f(askbox.getSize().x-75, askbox.getSize().y + 100));
				yesno[i].setOutlineColor(askbox.getOutlineColor());
				yesno[i].setOutlineThickness(askbox.getOutlineThickness());
				yesno[i].setFillColor(askbox.getFillColor());
				yesno[i].setPosition(askbox.getPosition().x - 150 + dist*i, askbox.getPosition().y + 150);
				yesnotext[i].setCharacterSize(60);
				yesnotext[i].setFont(font);
				yesnotext[i].setFillColor(Color::Black);
				yesnotext[i].setPosition(Vector2f(yesno[i].getPosition().x +55,yesno[i].getPosition().y + 40));
			}
			yesnotext[0].setString("YES");
			yesnotext[1].setString("NO");
			
}