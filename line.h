#pragma once
#include "pch.h"
#include "shape.h"
#include <iostream>
#include <string>
#include <cmath>



class Line : public Shape
{
	double *xCord = nullptr;
	double *yCord = nullptr;
	int nrOfPoints = 0;

public:

	Line(double *xCord, double *yCord, int nrOfPoints);
	string getType() override;

	ShapePosition position() override;
	double distance(Shape &sObject) override;

};