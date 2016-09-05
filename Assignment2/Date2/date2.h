/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2, 
*/


#include <string>
#include <iostream>


class Date2
{
	private:
		std::string date;
	public:
		Date2();
		Date2(int, int, int);
		std::string getDate() const;
		std::string getMonth() const;
		std::string getDay() const;
		std::string getYear() const;
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		void display();
		bool operator ==(const Date2& r1);
		
};