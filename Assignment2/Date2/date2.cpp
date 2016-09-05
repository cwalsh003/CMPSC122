/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2, 
** Implementation of the date2 class to set a date as a string, 
** return different parts of the object and compare the object.
*/
#include "date2.h"
#include <string>
#include <iostream>

using namespace std;

Date2::Date2(){ //no arg default constructor
	date = "1/1/1900";
}
Date2::Date2(int mon, int day, int yer){ // three integer constructor.

/*if the month day and year parameters are within appropriate range, change the int to a string and push it onto the date member using the concatenation operator. */
if(mon <= 12 && mon > 0){ 
	date += to_string(mon) + "/";
}

if(day <= 31 && day > 0){
	date += to_string(day) + "/";
}

if(yer <= 2025 && yer >= 1900){
	date += to_string(yer);
}

}
string Date2::getDate() const{//return entire string, date
	return date;
}
/*There are three cases of date format, one with 10 elements, on with 8 and two with nine. The accessor methods check to see which format the date is in and then returns the appropriate substring, using the .substr() function*/
string Date2::getMonth() const{
	
	if(date.length() == 10){
		return date.substr (0,2);
	}else if(date.length() == 8){
		return date.substr (0,1);
	}else if(date.length() == 9 && date.substr (1,1) == "/"){
		return date.substr (0,1);
	}else{
		return date.substr (0,2);
	}
}
string Date2::getDay() const{
	if(date.length() == 10){
		return date.substr (3,2);
	}else if(date.length() == 8){
		return date.substr (2,1);
	}else if(date.length() == 9 && date.substr (1,1) == "/"){
		return date.substr (2,2);
	}else{
		return date.substr (3,1);
	}
}
string Date2::getYear() const{
	if(date.length() == 10){
		return date.substr (6,4);
	}else if(date.length() == 8){
		return date.substr (4,4);
	}else if(date.length() == 9 && date.substr (1,1) == "/"){
		return date.substr (5,4);
	}else{
		return date.substr (5,4);
	}
}
/*The accessor methods check to see which format the date is in and then replaces the appropriate portion of the string, using the replace function*/

void Date2::setYear(int yr){
	if(date.length() == 10){
		date = date.replace(6,4,to_string(yr));
	}else if(date.length() == 8){
		date = date.replace(4,4,to_string(yr));
	}else if(date.length() == 9 && date.substr (1,1) == "/"){
		date = date.replace(5,4,to_string(yr));
	}else{
		date = date.replace(5,4,to_string(yr));
	}
}
void Date2::setDay(int day){
	if(date.length() == 10){
		date = date.replace(3,2,to_string(day));
	}else if(date.length() == 8){
		date = date.replace(2,1,to_string(day));
	}else if(date.length() == 9 && date.substr (1,1) == "/"){
		date = date.replace(2,2,to_string(day));
	}else{
		date = date.replace(3,1,to_string(day));
	}
}
void Date2::setMonth(int mon){
	if(date.length() == 10){
		date = date.replace(0,2,to_string(mon));
	}else if(date.length() == 8){
		date = date.replace(0,1,to_string(mon));
	}else if(date.length() == 9 && date.substr (1,1) == "/"){
		date = date.replace(0,1,to_string(mon));
	}else{
		date = date.replace(0,2,to_string(mon));
	}
}

void Date2::display(){
	cout << date << endl;
}
bool Date2::operator ==(const Date2& r1)
{
	if(date.compare(r1.getDate()) == 0){
				return true;
	}else{
	return false;
	}
}
