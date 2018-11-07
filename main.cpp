#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */

int main(int argc, const char * argv[])
{

	int a = 0;
	int sum = 0;
	int counter = 0;
	int* point = new int[counter];

	std::ifstream myReadFile;

	myReadFile.open(argv[1]);

	if (myReadFile.is_open())
	{
		while (myReadFile >> a)
		{
			counter++;

			int* tempArr = new int[counter];
			for (int i = 0; i < counter; i++)
				tempArr[i] = point[i];
			delete[] point;
			point = new int[counter];
			for (int i = 0; i < counter; i++)
				point[i] = tempArr[i];
			delete[] tempArr;
			tempArr = nullptr;


			point[counter - 1] = a;
			sum += a;

		}
		myReadFile.close();

		for (int i = 0; i < counter; i++)
			if (point[i] > (sum / counter))
				cout << point[i] << " ";
	}
	else
		cout << "Could not open file. \n";

	delete[] point;
	point = nullptr;


	return 0;
}