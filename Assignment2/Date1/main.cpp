/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2,
** Program to test class date1 
*/
#include <iostream>
#include "date1.h"

using namespace std;
int main(int argc, char *argv[]) {
	Date1 date3;
	Date1 date2(06,3,1991);
	Date1 date1(06,3,1991);
	
 	date2.display();
	date1.display();
	date3.display();
	
	date3.setMonth(12);
	date3.setDay(06);
	date3.setYear(2015);
	
	date1.display();
	
	cout << (date1 == date2) << endl;
	cout << (date3 == date2) << endl;
	
	return 0;
}