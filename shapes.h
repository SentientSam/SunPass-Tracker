/*
    shapes.h
    Samuel Lamb
    cop3330
    project 4
    2/26/2019
*/

#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

class Shape //class Shape
{
public:
    Shape();
    Shape(float,float, float, bool verbose = 0);
    virtual float Volume() const, Area() const; 
    virtual const char* Name() const;
    virtual ~Shape();
protected:
    float x_, y_, z_;
    bool verbose_;
private:
    Shape (const Shape&); //Copy Constructor
    Shape& operator = (const Shape); //assignment operator
};

class Rectangle : public Shape //class rectangle
{
public:
	Rectangle();
	Rectangle(float l,float w,bool v);
	float Area() const;
	const char* Name() const;
    virtual ~Rectangle();
private:
	Rectangle (const Rectangle &); //copy constructor
	Rectangle& operator = (const Rectangle); //assignment operator
};

class Box : public Shape //class Box
{
public:
	Box();
	Box(float w,float l,float h,bool v);
	float Volume() const, Area() const;
	const char* Name() const;
    virtual ~Box();
private:
	Box (const Box &); //copy constructor
	Box& operator = (const Box); //assignment operator
};

class Cylinder : public Shape //class Cylinder
{
public:
	Cylinder();
	Cylinder(float r,float h,bool v);
	float Volume() const, Area() const;
	const char* Name() const;
    virtual ~Cylinder();
private:
	Cylinder (const Cylinder &); //copy constructor
	Cylinder& operator = (const Cylinder); //assignment operator
};
#endif
