#include "AI.h"



AI::AI()
{

}



AI::~AI()
{
}

void AI::setIndex(int index)
{
	firstIndex = index;
}


int AI::Calculate(ShapeContainer& container, vector<int> AI_Tagged)
{
	
	int counter=0;
	int i = -1;
	prev_size = AI_Tagged.size();
	while (true)
	{
		i += 1;
		if (i == AI_Tagged.size())
			break;

		for (int j = 0; j < container.index[AI_Tagged[i]].size(); j++)
		{

			if (MOVE_MACRO_AI)
			{
				container.shapes[container.index[AI_Tagged[i]][j]]->setOutlineColor(Color(0, 1, 0));
				AI_Tagged.push_back(container.index[AI_Tagged[i]][j]);
				counter += 1;
			}
		}
		for (int i = 0; i < prev_size; i++)
		{
			container.shapes[AI_Tagged[i]]->setFillColor(AI_Color);
		}
		

				
	}
	return counter;
}

int AI::CalculateMove(Color& _ignore,ShapeContainer& container, vector<int> AI_Tagged)
{
	int counter = 0;
	int tempval = 0;
	int ID=0;
	AI_Color = Color::Red;
	if (AI_Color != _ignore)
	counter = Calculate(container,AI_Tagged);
	if (counter > tempval)
	{
		tempval = counter;
		ID = 1;
	}

	AI_Color = Color(255, 165, 0);
	if (AI_Color != _ignore)
	counter = Calculate(container,AI_Tagged);
	if (counter > tempval)
	{
		tempval = counter;
		ID = 2;
	}

	AI_Color = Color::Yellow;
	if (AI_Color != _ignore)
	counter = Calculate(container, AI_Tagged);
	if (counter > tempval)
	{
		tempval = counter;
		ID = 3;
	}

	AI_Color = Color::Green;
	if (AI_Color != _ignore)
	counter = Calculate(container, AI_Tagged);
	if (counter > tempval)
	{
		tempval = counter;
		ID = 4;
	}

	AI_Color = Color::Blue;
	if (AI_Color != _ignore)
	counter = Calculate(container, AI_Tagged);
	if (counter > tempval)
	{
		tempval = counter;
		ID = 5;
	}

	AI_Color = Color::Magenta;
	if (AI_Color != _ignore)
	counter = Calculate(container, AI_Tagged);
	if (counter > tempval)
	{
		tempval = counter;
		ID = 6;
	}

	if (ID == 0)
	{
		if (_ignore == Color::Red)
		ID = 2;
		if (_ignore == Color(255, 165, 0))
		ID = 3;
		if (_ignore == Color::Yellow)
			ID = 4;
		if (_ignore == Color::Green)
			ID = 5;
		if (_ignore == Color::Blue)
			ID = 6;
		if (_ignore == Color::Magenta)
			ID = 1;
	}
	return ID;
}
