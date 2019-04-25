
#include <iostream>
#include "app.hpp"
#include <SFML/Graphics.hpp>


#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480
#define WINDOW_TITLE "Training a Perceptron to be a NAND Gate"

int main()
{

	App* app = new App();
	app->init(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);



	while (app->isRunning())
	{
		app->handleEvents();
		app->update();
		app->render();
	}

	app->cleanup();

	delete app;
	app = nullptr;

	return 0;
}