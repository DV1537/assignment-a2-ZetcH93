#include "pch.h"
#include "shape.h"
#include <iostream>
#include <string>
#include <cmath>

Shape:: ~Shape()
{
	delete[] yCord;
	yCord = nullptr;
	delete[] xCord;
	xCord = nullptr;
	
}

double Shape::area()
{
	return -1;
}	

double Shape::circumference()
{
	return -1;
}


bool Shape::isConvex()
{
	return false;
}



ShapePosition::ShapePosition(double x,double y)
{
	this->x = x;
	this->y = y;
}