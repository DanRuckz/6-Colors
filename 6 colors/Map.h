#pragma once
#include "inits.h"
class Map
{
public:
	Map();
	RectangleShape getBackground();
	RectangleShape getMap();
	~Map();

private:
	void setBackground();
	RectangleShape map;
	RectangleShape background;
	Texture backgroundTexture;
};

