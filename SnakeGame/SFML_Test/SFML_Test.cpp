/*
*James Domingo
*C256
*May 29th 2018
*/
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

//globals
int num_vertBox = 30, num_horzBox = 20;
int size = 16; //number of pixels
int w = size * num_horzBox; //Background number of pixels in width
int h = size * num_vertBox; //Background number of pixels in height

int direction, snake_length = 4;

//Maximum size of snake
struct Snake {
	int x, y;
}s[100];

struct Fruit
{
	int x, y;
}food;

//1st player
void Tick() {
	//Move remaining pieces of snake [s1] - s[99]
	for (int i = snake_length; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	//Head of snake depends on direction of user s[0]
	//User up
	if (direction == 3)
		s[0].y -= 1;
	//User down
	if (direction == 0)
		s[0].y += 1;
	//User left
	if (direction == 1)
		s[0].x -= 1;
	//User right
	if (direction == 2)
		s[0].x += 1;

	//If snake eats a fruti, snake grows
	if (((s[0].x) == food.x) && ((s[0].y) == food.y))
	{
		float time = 1; //Modifies the speed when snake eats fruit
		snake_length++;

		//Rnadomly place food somewhere else
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;

		time = 0;

	}
	//Boundary Checking sccreen - loop back on other side
	//Left and Right
	if (s[0].x > num_horzBox)
		s[0].x = 0;
	if (s[0].x < num_horzBox)
		s[0].x = 0;
	//Top and Bottom
	if (s[0].y > num_vertBox)
		s[0].y = 0;
	if (s[0].y < 0)
		s[0].y = num_vertBox;

	//Check if snakes goes over itself
	for(int i = 1; i < snake_length; i++)
	{
		//Cut sname in half from place eaten
		if (s[0].x == s[i].x && s[0].y == s[i].y)
			snake_length = i;
	}


	
}
//2nd player
void Tick2() {
	//Move remaining pieces of snake [s1] - s[99]
	for (int i = snake_length; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	//Head of snake depends on direction of user s[0]
	//User up
	if (direction == 8)
		s[0].y -= 1;
	//User down
	if (direction == 5)
		s[0].y += 1;
	//User left
	if (direction == 6)
		s[0].x -= 1;
	//User right
	if (direction == 7)
		s[0].x += 1;

	//If snake eats a fruti, snake grows
	if (((s[0].x) == food.x) && ((s[0].y) == food.y))
	{
		float time = 1; //Modifies time when snake eats fruit
		snake_length++;

		//Rnadomly place food somewhere else
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;

		time = 0; // Resets the time
	}
	//Boundary Checking sccreen - loop back on other side
	//Left and Right
	if (s[0].x > num_horzBox)
		s[0].x = 0;
	if (s[0].x < num_horzBox)
		s[0].x = 0;
	//Top and Bottom
	if (s[0].y > num_vertBox)
		s[0].y = 0;
	if (s[0].y < 0)
		s[0].y = num_vertBox;

	//Check if snakes goes over itself
	for (int i = 1; i < snake_length; i++)
	{
		//Cut sname in half from place eaten
		if (s[0].x == s[i].x && s[0].y == s[i].y)
			snake_length = i;
	}

}

int main()
{

	srand(time(0));
	RenderWindow window(VideoMode(w, h), "Snake Game!");

	//Texture - 1st player
	Texture t1, t2, t3;
	t1.loadFromFile("Image/White.png");
	t2.loadFromFile("Image/Red.png");
	t3.loadFromFile("Image/Banana.png");//Changed the image of food to banana

	//Texture - 2nd player
	Texture t4, t5;
	t4.loadFromFile("Image/Pink.png"); //2nd player will be color pink
	t5.loadFromFile("Image/Orange.png"); //2nd fruit


	//Sprite - has physical dimensions
	Sprite sprite1(t1); //Background
	Sprite sprite2(t2); //1st snake
	Sprite sprite3(t3); //Banana as fruit
	Sprite sprite4(t4); //2nd snake
	Sprite sprite5(t5); 

	food.x = 10;
	food.y = 10;

	Clock clock;
	float timer = 0, delay = .1f;

	while (window.isOpen()) 
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		//Event - allows us to check when a user does something
		Event e;

		//Check when window is closed
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close(); //Tells window to close
			}
		}

		//Controls of snake - 1st player
		if (Keyboard::isKeyPressed(Keyboard::Up))
			direction = 3;		
		if (Keyboard::isKeyPressed(Keyboard::Down))
			direction = 0;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			direction = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right))
			direction = 2;

		//Controls of snake - 2nd player
		if (Keyboard::isKeyPressed(Keyboard::Up))
			direction = 8;
		if (Keyboard::isKeyPressed(Keyboard::Down))
			direction = 5;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			direction = 6;
		if (Keyboard::isKeyPressed(Keyboard::Right))
			direction = 7;

		if (timer > delay)
		{
			timer = 0; //Reset timer
			Tick();//Move snake one sprite forward
			Tick2();//Move 2nd snake one sprite forward
		}
		//Draw
		window.clear();

		//Draw Background
		for (int i = 0; i < num_horzBox; i++) {
			for (int j = 0; j < num_vertBox; j++) 
			{
				sprite1.setPosition(i*size, j*size);
				window.draw(sprite1);
			}

			//Draws both snakes
			for (int i = 0; i < snake_length; i++)
			{
				sprite2.setPosition(s[i].x*size, s[i].y*size);
				window.draw(sprite2);
				sprite4.setPosition(s[i].x*size + 1, s[i].y*size);
				window.draw(sprite4);
			}

			//Draw fruit
			sprite3.setPosition(food.x*size, food.y*size);
			window.draw(sprite3); //Shows banana
			sprite5.setPosition(food.x*size, food.y*size);
			window.draw(sprite5); //Shows orange

			window.display();
		}
	}
	
	return 0;
}