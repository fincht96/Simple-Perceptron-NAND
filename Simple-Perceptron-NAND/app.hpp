#pragma once

#include "perceptron.hpp"
#include <SFML/Graphics.hpp>

class App
{
private:
	bool m_running = false;
	sf::RenderWindow mRenderWindow;
	sf::RenderTexture mRenderTexture;		// used for off screen drawing


	Perceptron mPerceptron;
	



public:
	void init(sf::Vector2u windowSize, std::string windowTitle);
	void handleEvents();
	void update();
	void render();
	void cleanup();

	bool isRunning() { return m_running; }
	void quit() { m_running = false; }
};


