
#include "utility.hpp"

float randValFloat(float minVal, float maxVal)
{
	std::random_device dev;

	// generates uniformly distibuted values
	std::mt19937 rng(dev());

	// transforms distributed values into specified range
	std::uniform_real_distribution<> dis(minVal, maxVal);

	return (float)dis(rng);
}

int randValInt(int minVal, int maxVal)
{
	std::random_device dev;

	// generates uniformly distibuted values
	std::mt19937 rng(dev());

	// transforms distributed values into specified range
	std::uniform_int_distribution<> dis(minVal, maxVal);

	return dis(rng);
}