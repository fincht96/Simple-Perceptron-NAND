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

	numCycles++;

	int inputA = randValInt(0, 1);
	int inputB = randValInt(0, 1);

	int desired = !(inputA && inputB);
	int perceptronGuess = mPerceptron.feedForward(inputA, inputB);

	std::string result = (desired == perceptronGuess) ? "Correct" : "Wrong";

	if (result == "Wrong") { numWrongCycles++; }
	
	float percentageError = (numWrongCycles / (float)numCycles) * 100;

	

	std::cout 
		<< std::endl << std::endl
		<< "Cycle Num:\t" << numCycles << std::endl
		<< "Input A:\t" << inputA << std::endl
		<< "Input B:\t" << inputB << std::endl
		<< "Desired Output:\t" << desired << std::endl
		<< "Guess Ouput:\t" << perceptronGuess << std::endl
		<< "Result:\t" << result << std::endl
		<< "% Cycles Wrong:\t" << percentageError << std::endl;


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
