#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "shape.h"
#include "line.h"
#include "point.h"
#include "polygon.h"
#include "triangel.h"



using namespace std;


int main(int argc, const char * argv[])
{

	double input = 0;
	int nrOfcords = 0;
	double* cords = new double[nrOfcords];
	double* xCord;
	double* yCord;

	std::ifstream myReadFile;

	myReadFile.open("vertices.txt");

	if (myReadFile.is_open())
	{
		while (myReadFile >> input)
		{
			nrOfcords++;

			double* tempArr = new double[nrOfcords];
			for (int i = 0; i < nrOfcords; i++)
				tempArr[i] = cords[i];
			delete[] cords;
			cords = nullptr;
			cords = new double[nrOfcords];
			
			for (int i = 0; i < nrOfcords; i++)
				cords[i] = tempArr[i];
			delete[] tempArr;
			tempArr = nullptr;


			cords[nrOfcords-1] = input;

		}
		myReadFile.close();

	}
	else
	{
		cout << "Could not open file. \n";
		exit(EXIT_FAILURE);
	}


	int vertices = (nrOfcords / 2);
	xCord = new double[vertices];
	yCord = new double[vertices];

	for (int cordNr = 0; cordNr < nrOfcords; cordNr++)
	{
		int cIndex = (cordNr / 2);
		if (cordNr % 2 == 0)
			xCord[cIndex] = cords[cordNr];
		else
			yCord[cIndex] = cords[cordNr];
	}


	if (nrOfcords > 6)
	{
		if (nrOfcords % 2 == 0)
		{
			Polygon polygon(xCord, yCord, vertices);
			double area = polygon.area();
			double finalArea = (area * 1000) / 1000.0;
			cout << finalArea;
		}
	}
	else if (nrOfcords == 6)
	{
		Triangel triangle(xCord, yCord, vertices);
		double area = triangle.area();
		double finalArea = (area * 1000) / 1000.0;
		cout << finalArea;
	}
	else if (nrOfcords == 4)
	{
		Line line(xCord, yCord, vertices);
		cout << line.area();
	}
	else if (nrOfcords == 2)
	{
		Point point(xCord, yCord, vertices);
		cout << point.area();
	}
	else
	{
		cout << "There is no shape in the file." << endl;
		exit(EXIT_FAILURE);
	}




	delete[] cords;
	cords = nullptr;


	return 0;
}