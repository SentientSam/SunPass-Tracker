/*
    shapes.cpp
    Samuel Lamb
    cop3330
    project 4
    2/26/2019
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <shapes.h>
#include <cmath>
#include <fstream>

Shape::Shape() : x_(0), y_(0), z_(0), verbose_(0)
{
    std::cout << "Shape(" << x_ << "," << y_ << "," << z_ << "," << verbose_ << ")" << std::endl;
    if (verbose_)
    {
        std::cout << "Shape()\n";
    }
}
Shape::~Shape()
{
    if (verbose_)
    {
        std::cout << "~Shape()\n";
    }
}

Shape::Shape(float x, float y, float z, bool verbose) : x_(x), y_(y), z_(z), verbose_(verbose)
{
    if (verbose)
    {
        std::cout << "Shape(" << x_ << "," << y_ << "," << z_ << "," << verbose_ << ")" << std::endl;
    }
}

const char* Shape::Name() const
{
    return ("generic");
}

float Shape::Volume() const
{
    return (0);
}

float Shape::Area() const
{
    return (0);
}

Rectangle::Rectangle() : Shape(1, 1, 0, 0)
{
    if(verbose_)
    {
        std::cout << "Rectangle()\n";
    }
}

Rectangle::Rectangle(float width, float length, bool verbose) : Shape(width, length, 0, verbose)
{
    if (verbose_)
    {
        std::cout << "Rectangle(" << width << "," << length << "," << verbose << ")" << std::endl;
    }
}

Rectangle::~Rectangle()
{
    if (verbose_)
    {
        std::cout << "~Rectangle()" << std::endl;
    }
}

float Rectangle::Area() const
{
    return (x_ * y_);
}

const char* Rectangle::Name() const
{
    return ("rectangle");
}

Cylinder::Cylinder() : Shape(1,0,1,0)
{
    if(verbose_)
    {
        std::cout << "Cylinder()\n";
    }
}

Cylinder::~Cylinder()
{
    if (verbose_)
    {
        std::cout << "~Cylinder()\n";
    }
}

Cylinder::Cylinder(float radius, float height, bool verbose) : Shape(radius, 0, height, verbose)
{
    if (verbose_)
    {
        std::cout << "Cylinder(" << radius << "," << height << "," << verbose << ")" << std::endl;
    }
}

float Cylinder::Volume() const
{
    return (M_PI * x_ * x_ * z_);
}

float Cylinder::Area() const
{
    return ((M_PI * x_ * x_ * 2) + (2 * M_PI * x_ * z_));
}

const char * Cylinder::Name() const
{
    return ("cylinder");
}

Box::Box() : Shape(1,1,1,0)
{
    if(verbose_)
    {
        std::cout << "Box()\n";
    }
}

Box::Box(float width, float length, float height, bool verbose) : Shape(width, length, height, verbose)
{
    if (verbose_)
    {
        std::cout << "Box(" << width << "," << length << "," << height << "," << verbose << ")" << std::endl;
    }
}

Box::~Box()
{
    if (verbose_)
    {
        std::cout << "~Box()\n";
    }
}

float Box::Area() const
{
    return ((2 * x_ * z_) + (2 * x_ * y_) + (2 * y_ * z_));
}

float Box::Volume() const
{
    return (x_ * y_ * z_);
}

const char* Box::Name() const
{
    return ("box");
}
