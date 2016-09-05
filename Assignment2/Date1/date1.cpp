/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2,
** Program to implement the date class 
*/
#include "date1.h"
//#include "date2.h"

#include <iostream>
using namespace std;
Date1::Date1(){
	month = 1;
	day = 1;
	year = 1900;
}
Date1::Date1(int mon, int date, int yer){
if(mon <= 12 && mon > 0){
	month = mon;
}

if(date <= 31 && date > 0){
	day = date;
}

if(yer <= 2025 && yer > 1900){
	year = yer;
}
}
int Date1::getMonth() const{
	return month;
}
int Date1::getDay() const{
	return day;
}
int Date1::getYear() const{
	return year;
}
void Date1::setMonth(int mon){
	month = mon;
}
void Date1::setDay(int dy){
	day = dy;
}
void Date1::setYear(int yr){
	year = yr;
}
void Date1::display(){
	cout << month << "/" << day << "/" << year << endl;
}

bool Date1::operator ==(const Date1& r1)
{
 	if(month == r1.getMonth() && day == r1.getDay() && year == 			r1.getYear()){
				return true;
			}else{
				return false;
			}
}

