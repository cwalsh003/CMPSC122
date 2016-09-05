/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2, 
** Implementation of Date2 class using String member only
*/
#include <iostream>
#include "date2.h"

using namespace std;
int main(int argc, char *argv[]) {
	Date2 date3;			//testing no arg construstor 
	Date2 date2(12,12,1900); //testing three arg constructor
	Date2 date1(1,1,1900);
	Date2 date4("1/12/1991");
	
	cout << boolalpha <<(date1 == date3) << endl; //testing over loaded == operator.
	
 	date3.display();//testing display
	date2.display();
	date1.display();
	
	cout << boolalpha <<(date1 == date3) << endl;
	cout << boolalpha <<(date3 == date2) << endl;
	cout << boolalpha <<(date2 == date2) << endl;
	
	date3.setMonth(12);//testing setters 
	date3.setDay(12);
	date3.setYear(1900);
	
	date2.setMonth(1);
	date2.setDay(4);
	date2.setYear(2000);
	
	date1.setMonth(12);
	date1.setDay(5);
	date1.setYear(1900);
	
	date3.display();//showing that the setters worked
	date2.display();
	date1.display();
	date4.display();
	
	
	cout << boolalpha <<(date1 == date3) << endl; //testing compater overloaded operator
	cout << boolalpha <<(date3 == date2) << endl;
	cout << boolalpha <<(date2 == date2) << endl;
	
	date2.setMonth(12);
	date2.setDay(1);
	date2.setYear(1900);
	 
	cout << date3.getDate()<< endl;  //testing all getters. 
	cout << date3.getMonth() << endl;
	cout << date3.getDay() << endl;
	cout << date3.getYear() << endl;
	
	cout << date2.getDate()<< endl;
	cout << date2.getMonth() << endl;
	cout << date2.getDay() << endl;
	cout << date2.getYear() << endl;
	
	cout << date1.getDate()<< endl;
	cout << date1.getMonth() << endl;
	cout << date1.getDay() << endl;
	cout << date1.getYear() << endl;
	
	
	
}