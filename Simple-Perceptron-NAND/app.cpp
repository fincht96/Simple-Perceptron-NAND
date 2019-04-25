#include "app.hpp"
#include "utility.hpp"
#include <array>
#include <iostream>

void App::init(sf::Vector2u windowSize, std::string windowTitle)
{
	// creates a new render window
	mRenderWindow.create(sf::VideoMode(windowSize.x, windowSize.y), windowTitle);

	// creates off screen render texture
	mRenderTexture.create(windowSize.x, windowSize.y);


	mRenderWindow.setVerticalSyncEnabled(true);

	// sets application running
	m_running = true;


	// initialise all perceptron weights randomly
	mPerceptron.initRandomWeights();



}

void App::handleEvents()
{
	sf::Event event;


	while (mRenderWindow.pollEvent(event))
	{
		// handle user quit event
		if (event.type == sf::Event::Closed)
		{
			this->quit();
		}


	}

}

void App::update()
{
	// clear canvas
	mRenderTexture.clear(sf::Color::White);

	int inputA = randValInt(0, 1);
	int inputB = randValInt(0, 1);

	int desired = !(inputA && inputB);
	int perceptronGuess = mPerceptron.feedForward(inputA, inputB);

	std::string result = (desired == perceptronGuess) ? "Correct" : "Wrong";

	
	
	std::cout << "InputA: " << inputA << " InputB: " << inputB << " Desired: " << desired << " Guess: " << perceptronGuess << " Result: " << result << std::endl;


	mPerceptron.train(inputA, inputB, desired);
	
}

void App::render()
{
	mRenderWindow.clear();
	mRenderWindow.draw(sf::Sprite(mRenderTexture.getTexture()));
	mRenderWindow.display();
}

void App::cleanup()
{
}
