/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2, 
** header file for field and method declarations 
*/
#include <string>
#include <iostream>
#include "SmallDecimal.h"

class SmallDecimal{
	private:
		int integer; 
		int decimal;
		int index;
	public:
		SmallDecimal();
		SmallDecimal(std::string);
		int getIndex()const;
		SmallDecimal operator +(const SmallDecimal& r1);
		SmallDecimal operator -(const SmallDecimal& r1);
		SmallDecimal operator *(const SmallDecimal & r1);
		bool operator ==(const SmallDecimal& r1);
		bool operator !=(const SmallDecimal& r1);
		bool operator <(const SmallDecimal& r1);
		SmallDecimal& operator ++();
		SmallDecimal operator ++(int);
		friend std::ostream& operator << (std::ostream& outs, const SmallDecimal& source);
		friend std::istream& operator >> (std::istream& ins,  SmallDecimal& target);
		double toDouble()const;
		std::string toString()const;
		
	
};