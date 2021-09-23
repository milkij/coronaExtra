//
// Created by  Milkij on 09.09.2021.
//
#include "iostream"


#include <iostream>
int main() {
	int numbers[15] = {105, 114, 111, 106, 107, 108, 115, 108, 110, 109, 112, 113, 116, 117, 118};

  int n = sizeof(numbers) / sizeof(numbers[0]);
	int min = numbers[0];
	int sum = 0;

	for(int i = 0; i < n; ++i)
	{
		if(min > numbers[i])
			min = numbers[i];

		sum += numbers[i];
	}

	for(int i = min; i < min + n - 1; ++i)
		sum -= i;

	std::cout << sum;
	return 0;
}

