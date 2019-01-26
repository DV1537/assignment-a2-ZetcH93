#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


struct ShapePosition
{
	double x, y;
	ShapePosition(double x, double y);
	
};


class Shape
{

public:
	
	double *xCord = nullptr;
	double *yCord = nullptr;
	int nrOfPoints = 0;

	virtual ~Shape();
	virtual string getType() = 0;	// returns a string denoting the type of a shape(point, line, polygon ..);
	virtual double area();		 // returns area of the object, or -1 if the shape is concave, intersecting, or does not have an area
	virtual double circumference();		 //returns circumference of the object
	virtual ShapePosition position() = 0;		//returns center coordinates of the object, or the center of the bounding box if the shape is not convex.
	virtual bool isConvex();					// returns true if shape is convex
	virtual double distance(Shape &s) = 0;		//returns distance to the center of another shape




};