#pragma once
#include "pch.h"
#include "shape.h"
#include <iostream>
#include <string>
#include <cmath>

class Point : public Shape
{

	double *xCord = nullptr;
	double *yCord = nullptr;
	int nrOfPoints = 0;


public:

	Point(double *xCord, double *yCord, int nrOfPoints);
	string getType() override;
	
	ShapePosition position() override;
	double distance(Shape &sObject) override;

};