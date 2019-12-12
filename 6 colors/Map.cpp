#include "Map.h"



Map::Map()
{
	setBackground();
	
}

RectangleShape Map::getBackground()
{
	return background;
}
RectangleShape Map::getMap()
{
	return map;
}
Map::~Map()
{
}

void Map::setBackground()
{
	Vector2f windowsize(1100, 900);
	background.setPosition(0, 0);
	background.setSize(windowsize);
	backgroundTexture.loadFromFile("1337.jpg");
	background.setTexture(&backgroundTexture);
	map.setFillColor(Color::Black);
	map.setSize(Vector2f(650.f, 652.f));
	map.setPosition(Vector2f(200, 34));
	map.setOutlineColor(Color::Black);
	map.setOutlineThickness(1);
	
}
