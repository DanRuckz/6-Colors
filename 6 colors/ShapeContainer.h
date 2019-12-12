#pragma once
#include "inits.h"
#include "Map.h"
#include <ctime>
#include <random>

#define EDGE (current_position == map_position) || (current_position.x == endmap.x-polygondistance/2 && current_position.y == map_position_y)|| (current_position.x == map_position_x && current_position.y == endmap.y - polygondistance/2) || (current_position.x == endmap.x-polygondistance/2 && current_position.y == endmap.y - polygondistance/2)

#define TOP_LEFT (current_position == map_position)
#define TOP_RIGHT (current_position.x == endmap.x-polygondistance/2 && current_position.y == map_position_y)
#define BOTTOM_LEFT (current_position.x == map_position_x && current_position.y == endmap.y - polygondistance/2)
#define BOTTOM_RIGHT (current_position.x == endmap.x-polygondistance/2 && current_position.y == endmap.y - polygondistance/2)


#define WALL (current_position.x > map_position_x && current_position.y == map_position_y && current_position.x < endmap.x - polygondistance/2) || (current_position.x == map_position_x && current_position.y > map_position.y) || (current_position.x > map_position_x && current_position.y == endmap.y - polygondistance/2 && current_position.x < endmap.x - polygondistance/2) || (current_position.x == endmap.x-polygondistance/2 && current_position.y > map_position_y && current_position.y < endmap.y -polygondistance/2)

#define UPPER_WALL (current_position.x > map_position_x && current_position.y == map_position_y && current_position.x < endmap.x - polygondistance/2)
#define LEFT_WALL  (current_position.x == map_position_x && current_position.y > map_position.y && current_position.y < endmap.y - polygondistance/2)
#define BOTTOM_WALL (current_position.x > map_position_x && current_position.y == endmap.y - polygondistance/2 && current_position.x < endmap.x - polygondistance/2) 
#define RIGHT_WALL (current_position.x == endmap.x-polygondistance/2 && current_position.y > map_position_y && current_position.y < endmap.y -polygondistance/2)

#define MUTUAL_INTERSECTION shapes[i]->getGlobalBounds().intersects(shapes[j]->getGlobalBounds()) && shapes[j]->getGlobalBounds().intersects(shapes[i]->getGlobalBounds())
#define INTERSECTION shapes[i]->getGlobalBounds().intersects(shapes[j]->getGlobalBounds())
#define DISTANCE abs(shapes[i]->getPosition().x - shapes[j]->getPosition().x <= polygondistance/2) && abs(shapes[i]->getPosition().y - shapes[j]->getPosition().y <= polygondistance/2)
class ShapeContainer
{
public:
	ShapeContainer();
	~ShapeContainer();
	std::vector <int> indexes;
	std::vector<vector<int>> index;
	std::vector<Shape*> shapes;
	vector<RectangleShape*> boundvec;
	int getFirstIndex();
	int getAIindex();
	RectangleShape* bound;
	

private:
	CircleShape* Circleptr;
	ConvexShape* ConvexPtr;
	float polygondistance = 26;
	float map_position_x = 200;
	float map_position_y = 34;
	Vector2f endmap;
	const float END = 650;
	void createHalf(Shape * myptr, Vector2f current_position);
	void createHalf(Shape * myptr, Vector2f current_position,bool);
	void SetNeighbors();
	void setMap();
	void setColor(Shape *);
	int Randomize_Shape();
};
