#include "ShapeContainer.h"

ShapeContainer::ShapeContainer()
{
	endmap = Vector2f(map_position_x + END,map_position_y + END);
	setMap();
	SetNeighbors();
	getFirstIndex();
}


ShapeContainer::~ShapeContainer()
{
}

void ShapeContainer::setMap()
{
	int random;
	bool switchen = true;
	bool row_switcher = false;
	bool frame = false;
	Vector2f map_position(map_position_x, map_position_y);
	Vector2f current_position (map_position_x, map_position_y);
	
	while(true)
	{
			if (!frame)
			{
				if (EDGE) 
				{
					ConvexPtr = new ConvexShape;
					ConvexPtr->setPointCount(3);
					ConvexPtr->setOutlineColor(Color::Black);
					ConvexPtr->setOutlineThickness(1);
					setColor(ConvexPtr);
					bound = new RectangleShape;
					bound->setOutlineColor(Color::White);
					bound->setOutlineThickness(1);

					if (TOP_LEFT)
					{
						ConvexPtr->setPoint(0, Vector2f(0,0));
						ConvexPtr->setPoint(1, Vector2f(polygondistance/2-1, 0));
						ConvexPtr->setPoint(2, Vector2f(0, polygondistance / 2-1));
						ConvexPtr->setPosition(Vector2f(current_position));
						shapes.push_back(ConvexPtr);
						bound->setPosition(Vector2f(current_position.x - 5,current_position.y - 5));
						bound->setSize(Vector2f(polygondistance / 2, polygondistance / 2));
						boundvec.push_back(bound);
						current_position = Vector2f(current_position.x + polygondistance / 2, current_position.y);
						continue;
					}

					if (TOP_RIGHT)
					{
						ConvexPtr->setPoint(0, Vector2f(1.5,0));
						ConvexPtr->setPoint(1, Vector2f(polygondistance/2,0));
						ConvexPtr->setPoint(2, Vector2f(polygondistance/2.f, polygondistance / 2-1.5f));
						ConvexPtr->setPosition(Vector2f(current_position));
						shapes.push_back(ConvexPtr);
						bound->setPosition(Vector2f(current_position.x + 5, current_position.y - 5));
						bound->setSize(Vector2f(polygondistance / 2, polygondistance / 2));
						boundvec.push_back(bound);
						current_position = Vector2f(map_position_x, current_position.y + polygondistance / 2);
						continue;
					}

					if (BOTTOM_LEFT)
					{
						ConvexPtr->setPoint(0, Vector2f(0, 3));
						ConvexPtr->setPoint(1, Vector2f(0, polygondistance / 2));
						ConvexPtr->setPoint(2, Vector2f(polygondistance / 2-3, polygondistance / 2));
						ConvexPtr->setPosition(Vector2f(current_position));
						shapes.push_back(ConvexPtr);
						bound->setPosition(Vector2f(current_position.x - 5, current_position.y + 5));
						bound->setSize(Vector2f(polygondistance / 2, polygondistance / 2));
						boundvec.push_back(bound);
						current_position = Vector2f(current_position.x + polygondistance / 2, current_position.y);
						continue;
					}
					if (BOTTOM_RIGHT)
					{
						ConvexPtr->setPoint(0, Vector2f(3, polygondistance / 2));
						ConvexPtr->setPoint(1, Vector2f(polygondistance / 2, polygondistance / 2));
						ConvexPtr->setPoint(2, Vector2f(polygondistance / 2, 3));
						ConvexPtr->setPosition(Vector2f(current_position));
						bound->setPosition(Vector2f(current_position.x + 5, current_position.y + 5));
						bound->setSize(Vector2f(polygondistance / 2, polygondistance / 2));
						boundvec.push_back(bound);
						current_position = Vector2f(endmap.x - polygondistance / 2, map_position_y + polygondistance / 2);
						shapes.push_back(ConvexPtr);
						continue;
					}
				}
				if (WALL)
				{
					ConvexPtr = new ConvexShape;
					ConvexPtr->setPointCount(3);
					setColor(ConvexPtr);
					ConvexPtr->setOutlineThickness(1);
					ConvexPtr->setOutlineColor(Color::Black);
					bound = new RectangleShape;
					bound->setOutlineColor(Color::White);
					bound->setOutlineThickness(1);
					if (UPPER_WALL)
					{
						ConvexPtr->setPoint(0, Vector2f(2.5, 0));
						ConvexPtr->setPoint(1, Vector2f(polygondistance / 2.f, polygondistance / 2-2.5f));
						ConvexPtr->setPoint(2, Vector2f(polygondistance-2.5f,0));
						ConvexPtr->setPosition(Vector2f(current_position));
						bound->setPosition(Vector2f(current_position.x + polygondistance/4,current_position.y-polygondistance/4));
						bound->setSize(Vector2f(polygondistance / 2.f, polygondistance / 2.f));
						boundvec.push_back(bound);
						current_position = Vector2f(current_position.x + polygondistance, current_position.y);
						shapes.push_back(ConvexPtr);
						continue;
					}
					if (LEFT_WALL)
					{
						ConvexPtr->setPoint(0, Vector2f(0, 2.5));
						ConvexPtr->setPoint(1, Vector2f(0, polygondistance-2.5f));
						ConvexPtr->setPoint(2, Vector2f(polygondistance / 2-2.5f, polygondistance / 2.f));
						ConvexPtr->setPosition(Vector2f(current_position));
						bound->setPosition(Vector2f(current_position.x - 4.f, current_position.y + 6.5f));
						bound->setSize(Vector2f(polygondistance / 2, polygondistance / 2));
						boundvec.push_back(bound);
						current_position = Vector2f(current_position.x, current_position.y + polygondistance);
						shapes.push_back(ConvexPtr);
						continue;
					}
					if (BOTTOM_WALL)
					{
						ConvexPtr->setPoint(0, Vector2f(2.5, polygondistance / 2));
						ConvexPtr->setPoint(1, Vector2f(polygondistance / 2, 2.5));
						ConvexPtr->setPoint(2, Vector2f(polygondistance-2.5f, polygondistance / 2.f));
						ConvexPtr->setPosition(Vector2f(current_position));
						bound->setPosition(Vector2f(current_position.x+polygondistance/4,current_position.y + polygondistance/4-3));
						bound->setSize(Vector2f(polygondistance / 2, polygondistance / 2));
						boundvec.push_back(bound);
						current_position = Vector2f(current_position.x + polygondistance, current_position.y);
						shapes.push_back(ConvexPtr);
						continue;
					}
					if (RIGHT_WALL)
					{
						ConvexPtr->setPoint(0, Vector2f(polygondistance / 2, 2.5));
						ConvexPtr->setPoint(1, Vector2f(2.5, polygondistance / 2));
						ConvexPtr->setPoint(2, Vector2f(polygondistance / 2.f, polygondistance-2.5f));
						ConvexPtr->setPosition(Vector2f(current_position));
						bound->setPosition(Vector2f(current_position.x+3,current_position.y +polygondistance/4));
						bound->setSize(Vector2f(polygondistance / 2, polygondistance / 2));
						boundvec.push_back(bound);
						current_position = Vector2f(current_position.x, current_position.y + polygondistance);
						shapes.push_back(ConvexPtr);
						if (current_position.x == endmap.x - polygondistance / 2, current_position.y == endmap.y - polygondistance / 2)
						{
							frame = true;
							current_position = Vector2f(map_position.x,map_position_y);
						}
						continue;
					}

				}
			}

			if (current_position.y > endmap.y - polygondistance)
				break;

			random = Randomize_Shape();
			if (random == 0)
			{
				Circleptr = new CircleShape;
				Circleptr->setOutlineThickness(1);
				Circleptr->setOutlineColor(Color::Black);
				Circleptr->setRadius(polygondistance / 2 - 1.5f);
				Circleptr->setPointCount(4);
				setColor(Circleptr);
				Circleptr->setPosition(Vector2f(current_position.x +1.3f,current_position.y+1.3f));
				bound = new RectangleShape;
				bound->setOutlineColor(Color::White);
				bound->setOutlineThickness(1);
				bound->setPosition(Vector2f(current_position.x + polygondistance/4-1, current_position.y+polygondistance/4-1));
				bound->setSize(Vector2f(polygondistance/2+1, polygondistance/2+1));
				boundvec.push_back(bound);
				current_position = Vector2f(current_position.x + polygondistance, current_position.y);
				shapes.push_back(Circleptr);
			}

			if (random == 1) //horizontal
			{
				ConvexPtr = new ConvexShape;
				ConvexPtr->setOutlineThickness(1);
				ConvexPtr->setOutlineColor(Color::Black);
				ConvexPtr->setPointCount(3);
				ConvexPtr->setPoint(0, Vector2f(1.9f, polygondistance / 2.f));
				ConvexPtr->setPoint(1, Vector2f(polygondistance / 2.f, 1.9f));
				ConvexPtr->setPoint(2, Vector2f(polygondistance-1.9f, polygondistance / 2.f));
				ConvexPtr->setPosition(Vector2f(current_position));
				setColor(ConvexPtr);
				shapes.push_back(ConvexPtr);
				bound = new RectangleShape;
				bound->setOutlineColor(Color::White);
				bound->setOutlineThickness(1);
				bound->setPosition(Vector2f(current_position.x + polygondistance/4 + 2, current_position.y + 3));
				bound->setSize(Vector2f(polygondistance / 3 -1.f, polygondistance / 3-0.5f));
				boundvec.push_back(bound);
				ConvexPtr = new ConvexShape;
				createHalf(ConvexPtr, current_position);
				current_position = Vector2f(current_position.x + polygondistance, current_position.y);
				shapes.push_back(ConvexPtr);
			}
			if (random == 2)
			{
				ConvexPtr = new ConvexShape;
				ConvexPtr->setPointCount(3);
				ConvexPtr->setOutlineThickness(1);
				ConvexPtr->setOutlineColor(Color::Black);
				ConvexPtr->setPoint(0, Vector2f(polygondistance/2.f, 1.9f));
				ConvexPtr->setPoint(1, Vector2f(1.9f, polygondistance/2.f));
				ConvexPtr->setPoint(2, Vector2f(polygondistance/2.f, polygondistance-1.9f));
				ConvexPtr->setPosition(Vector2f(current_position));
				setColor(ConvexPtr);
				shapes.push_back(ConvexPtr);
				bound = new RectangleShape;
				bound->setOutlineColor(Color::White);
				bound->setOutlineThickness(1);
				bound->setPosition(Vector2f(current_position.x +4.5f , current_position.y + 5.f));
				bound->setSize(Vector2f(polygondistance / 3-2, polygondistance / 3 + 5));
				boundvec.push_back(bound);
				ConvexPtr = new ConvexShape;
				createHalf(ConvexPtr, current_position,switchen);
				current_position = Vector2f(current_position.x + polygondistance, current_position.y);
				shapes.push_back(ConvexPtr);
			}
				

				if(row_switcher)
				if (current_position.x > endmap.x - polygondistance) {
					current_position = Vector2f(map_position_x, current_position.y + polygondistance/2);
					row_switcher = false;
				}

				if (!row_switcher)
				if (current_position.x > endmap.x - polygondistance / 2)
				{
					current_position = Vector2f(map_position_x+ polygondistance/2, current_position.y + polygondistance/2);
					row_switcher = true;
				}	
	}
}

void ShapeContainer::setColor(Shape *myshape)
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist;
	
	int random = dist(gen) % 6;

	if (random == 0)
	{myshape->setFillColor(Color::Red);return;}

	if (random == 1)
	{myshape->setFillColor(Color(255, 165, 0));return;}

	if (random == 2)
	{myshape->setFillColor(Color::Yellow);return;}

	if (random == 3)
	{myshape->setFillColor(Color::Green); return;}
	
	if (random == 4)
	{myshape->setFillColor(Color::Blue); return;}
	
	if (random == 5)
	{myshape->setFillColor(Color::Magenta); return;}
}

int ShapeContainer::Randomize_Shape()
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist;

	int random = dist(gen) % 3;

	if (random == 0)
		return 0;
	if (random == 1)
		return 1;
	else return 2;
}

void ShapeContainer::createHalf(Shape* myptr, Vector2f current_position)
{
	ConvexPtr->setPointCount(3);
	ConvexPtr->setPoint(0, Vector2f(1.9f, polygondistance / 2.f));
	ConvexPtr->setPoint(1, Vector2f(polygondistance / 2.f, polygondistance-1.9f));
	ConvexPtr->setPoint(2, Vector2f(polygondistance-1.9f, polygondistance / 2.f));
	ConvexPtr->setPosition(Vector2f(current_position));
	setColor(ConvexPtr);
	ConvexPtr->setOutlineThickness(1);
	ConvexPtr->setOutlineColor(Color::Black);
	bound = new RectangleShape;
	bound->setOutlineColor(Color::White);
	bound->setOutlineThickness(1);
	bound->setPosition(Vector2f(current_position.x + polygondistance / 4 + 2.f, current_position.y + polygondistance/2+1.9f));
	bound->setSize(Vector2f(polygondistance / 3, polygondistance / 3-1));
	boundvec.push_back(bound);
}

void ShapeContainer::createHalf(Shape* myptr, Vector2f current_position,bool)
{
	ConvexPtr->setPointCount(3);
	ConvexPtr->setPoint(0, Vector2f(polygondistance / 2.f, 1.9f));
	ConvexPtr->setPoint(1, Vector2f(polygondistance-1.9f, polygondistance / 2.f));
	ConvexPtr->setPoint(2, Vector2f(polygondistance / 2.f, polygondistance-1.9f));
	ConvexPtr->setPosition(Vector2f(current_position));
	setColor(ConvexPtr);
	ConvexPtr->setOutlineThickness(1);
	ConvexPtr->setOutlineColor(Color::Black);
	bound = new RectangleShape;
	bound->setOutlineColor(Color::White);
	bound->setOutlineThickness(1);
	bound->setPosition(Vector2f(current_position.x+1.9f + polygondistance/2.f, current_position.y + 5.5f));
	bound->setSize(Vector2f(polygondistance / 3-1.5f, polygondistance / 3 + 3.f));
	boundvec.push_back(bound);
}

void ShapeContainer::SetNeighbors() 
{
	Vector2f map_position(map_position_x, map_position_y);
	Vector2f current_position(map_position_x, map_position_y);
	std::vector<int>temp;
	int counter = 0;
	for (int i = 0; i < boundvec.size(); i++)
	{	
		for (int j = 0; j < shapes.size(); j++)
		{
			if (boundvec[i]->getGlobalBounds().intersects(shapes[j]->getGlobalBounds()))
				indexes.push_back(j);
		}
		if (indexes.size() > 0)
		{
			index.push_back(indexes);
			indexes.clear();
		}
	}
}

int ShapeContainer::getFirstIndex()
{
	for (int i = 0; i < shapes.size(); i++)
	if(shapes[i]->getPosition() == Vector2f(map_position_x,endmap.y - polygondistance/2))
		return i;
	return 0;
}

int ShapeContainer::getAIindex()
{

	for (int i = 0; i < shapes.size(); i++)
		if (shapes[i]->getPosition() == Vector2f(endmap.x - polygondistance/2, map_position_y))
	return i;
	return 0;
}

