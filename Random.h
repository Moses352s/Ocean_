#pragma once

#define MAX 32767
#include <iostream>

using namespace std;

class Random
{
public:

	void initialize()
	{
		seed_one = 3797;
		seed_two = 2117;
	}

	void init(int s1, int s2)
	{
		seed_one = s1;
		seed_two = s2;
	}

	float randReal() 
	{
		int c;
		static int first = 1;

		if (first)
		{
			seed_one *= 2;
			seed_two *= 2;
			if (seed_one > MAX) seed_one = MAX;
			if (seed_two > MAX) seed_two = MAX;
			first = 0;
			for (int index = 1; index <= 30; index++)
				randReal();
		}

		c = seed_one + seed_two;
		if (c > MAX)
			c = MAX;
		c *= 2;
		if (c > MAX)
			c = MAX;
		seed_one = seed_two;
		seed_two = c;

		return (float)c / 32767;
	};

	unsigned nextIntBetween(int low, int high)
	{
		return abs(rand() % (++high - low)) + low;
	};

private:
	int seed_one;
	int seed_two;
};

