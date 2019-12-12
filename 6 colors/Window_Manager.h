#pragma once
#include "inits.h"
#include "ShapeContainer.h"
#include "Map.h"
#include "AI.h"

#define MOVE_MACRO (container.shapes[container.index[tagged[i]][j]]->getOutlineColor() == Color::Black || container.shapes[container.index[tagged[i]][j]]->getOutlineColor() == Color(0,1,0)) && container.shapes[container.index[tagged[i]][j]]->getFillColor() == color



class Window_Manager
{
public:
	Window_Manager();
	static bool getAgain();
	static void setAgain(bool);
	~Window_Manager();

private:
	void GameWindow();
	RenderWindow window;
	Vector2i mousepos;
	void Setstage();
	RectangleShape colors[6];
	float distance = 150;
	void setColors();
	bool findColor();
	float endmap_y = 560;
	Map map;
	ShapeContainer container;
	Shape * ptr;
	vector <int> tagged;
	Color color;
	Vector2f coords;
	void FieldCheck();
	int movement(vector<int>&);
	Color findColor(int);
	void setTexts();
	void setX();
	void PlayAgain();
	Color prev_color;
	vector<int> AI_vec;
	bool Player_moved = false;
	size_t Max_Score;
	Color my_prev;
	int my_score=1;
	int AI_score = 1;
	bool game_end = false;
	Font font;
	Text Tscore[2];
	Text nscore[2];
	bool failed = false;
	Texture texture;
	Sprite sprite[2];
	Text message;
	RectangleShape textBox;
	RectangleShape askbox;
	Text asktext;
	RectangleShape yesno[2];
	Text yesnotext[2];
	static bool again;

};

