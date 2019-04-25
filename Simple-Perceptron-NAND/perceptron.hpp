#pragma once


#include <array>

class Perceptron
{
private:

	int mBias = 1;
	float mLearningRate = 0.1f;

	float mInputAWeight, mInputBWeight, mBiasWeight;


	
	int activationFunc(float n);


public:
	
	void initRandomWeights();
	int feedForward(int inputA, int inputB);
	void train(int inputA, int inputB, int target);


};


// PERHAPS AN ABILITY TO DRAW THE PERCEPTRON




