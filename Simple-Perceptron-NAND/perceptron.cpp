#include "perceptron.hpp"
#include "utility.hpp"

// initialise random weights 
void Perceptron::initRandomWeights()
{
	mInputAWeight = randValFloat(-1, 1);
	mInputBWeight = randValFloat(-1, 1);
	mBiasWeight = randValFloat(-1, 1);
}


// computes an output guess based on current inputs
int Perceptron::feedForward(int inputA, int inputB)
{
	float sum = 0;

	// multiply and sum all inputs and weights
	sum += inputA * mInputAWeight;
	sum += inputB * mInputBWeight;
	sum += mBias * mBiasWeight;

	// classifies sum
	return activationFunc(sum);
}

// classifies whether result is 0 or 1
int Perceptron::activationFunc(float n)
{
	int result;

	if (n < 0.0f)
	{
		result = 0;
	}

	else
	{
		result = 1;
	}

	return result;
}

// tune weights to optimal values
void Perceptron::train(int inputA, int inputB, int target)
{
	int guess = feedForward(inputA, inputB);

	float error = target - guess;

	// adjusts weights of inputs according to error
	mInputAWeight += error * inputA * mLearningRate;
	mInputBWeight += error * inputB * mLearningRate;
	mBiasWeight += error * mBias * mLearningRate;

}