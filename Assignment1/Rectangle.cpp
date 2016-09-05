#include "Rectangle.h"
#include <iostream>
using namespace std;
//**************************************************
// Default Constructor.							   *
//**************************************************

Rectangle::Rectangle()
{
	length = 0;
	width = 0;
}

//**************************************************
// Construct a new instance of Rectangle.		   *
//**************************************************

Rectangle::Rectangle(int l, int w)
{
	length = l;
	width = w;
}

//**************************************************
// setWidth assigns a value to the width member.   *
//**************************************************

void Rectangle::setWidth(int w)
{
	if (w < 0)
	{
		cout << "The width of the rectangle cannot be negative." << endl;
		width = 0;
	}
	else
		width = w;
}

//**************************************************
// setLength assigns a value to the length member. *
//**************************************************

void Rectangle::setLength(int len)
{
   if (len < 0)
	{
		cout << "The length of the rectangle cannot be negative." << endl;
		length = 0;
	}
	else
		length = len;
}

//**************************************************
// getWidth returns the value in the width member. *
//**************************************************

int Rectangle::getWidth() const
{
   return width;
}

//****************************************************
// getLength returns the value in the length member. *
//****************************************************

int Rectangle::getLength() const
{
   return length;
}

//*****************************************************
// calcArea returns the product of width times length. *
//*****************************************************

int Rectangle::calcArea() const
{
   return width * length;
}

//*****************************************************
// calcParam returns the parameter of a rectangle.	  *
//*****************************************************

int Rectangle::calcParam() const
{
   return 2*(width + length);
}