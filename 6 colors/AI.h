#pragma once
#include "inits.h"
#include "ShapeContainer.h"
#define MOVE_MACRO_AI container.shapes[container.index[AI_Tagged[i]][j]]->getOutlineColor() == Color::Black && container.shapes[container.index[AI_Tagged[i]][j]]->getFillColor() == AI_Color

class AI
{
public:
	AI();
	~AI();
	
	void setIndex(int);
	int Calculate(ShapeContainer&  container, vector<int>);
	int CalculateMove(Color& _ignore, ShapeContainer& container, vector<int>);

private:
	int firstIndex;
	Color AI_Color;
	size_t prev_size;
};

