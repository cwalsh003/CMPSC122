/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2, 
** Program that implements the Small Decimal class and allows decimals to be entered as a string then stored as integers. Then the program overloads most of the 
** operations so that you can manipulate these decimals and get exact answers. 
*/
#include "smallDecimal.h"
#include "math.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
SmallDecimal::SmallDecimal(){// Default constructor
	integer = 0;
	decimal = 0;
	index = 1;
}
SmallDecimal::SmallDecimal(std::string number){ // one string arg constructor.
	int decPoint = number.find("."); //returns position of the decimal point
	string strNum; 
	integer = std::stoi(number.substr (0,decPoint)); // creates substring from the first position up to the decimal point, converts it to integer type and stores it in integer field
	strNum = (number.substr(decPoint + 1, (number.length() - decPoint))); //creates a substring from decomal point to the end of the string 
	index = strNum.length(); //gets the length of the substring above and stores it in the index field
	decimal = std::stoi(strNum); //converts above substring to integer and stores it in decimal field. 
}

SmallDecimal SmallDecimal::operator +(const SmallDecimal& r1){	
	int newDecimal = r1.decimal, oldDecimal = decimal, oldIndex = index;
	
	SmallDecimal resultObj; // create new object to store results
	
// Checks the current position of the decimal value by comparing indexes, then multiplies the smaller index decimal by powers of ten to align it correctly.  
	if(index > r1.index){
		newDecimal *=   static_cast<int>(pow(10, (index - r1.index)));
	}else if(index < r1.index){
		oldDecimal *= static_cast<int>(pow(10, (r1.index - index)));
		oldIndex = r1.index;
	}
	
	resultObj.integer = (integer) + (r1.integer);
	resultObj.decimal = decimal + newDecimal;

//Checks for a carry by checking if index of the resultant decimal is larger than the beginning index, meaning there was an overflow. If that is true you add one to the integer field.
	if(((resultObj.decimal) / (static_cast<int>(pow(10,oldIndex)))) != 0){
		resultObj.integer++;
		resultObj.decimal %= static_cast<int>(pow(10,oldIndex));
	}
	return resultObj;
}

SmallDecimal SmallDecimal::operator -(const SmallDecimal& r1){
	SmallDecimal resultObj;// create new object to store results
	
//Check to see if the number on the right is smaller than the left. If true set to zero as per specs.	
 if ((integer == r1.integer && decimal < r1.decimal) || integer < r1.integer){
		resultObj.integer = 0;
		resultObj.decimal = 0;
		resultObj.index = 0;
	}else{
	int newDecimal = r1.decimal, oldDecimal = decimal, oldIndex = index, oldInt = integer;

// Checks the current position of the decimal value by comparing indexes, then multiplies the smaller index decimal by powers of ten to align it correctly.  
	if(index > r1.index){
		newDecimal *=   static_cast<int>(pow(10, (index - r1.index)));
	}else if(index < r1.index){
		oldDecimal *= static_cast<int>(pow(10, (r1.index - index)));
		oldIndex = r1.index;
	}
/*handles the case where the number on the right is larger than the left, but the decimal portion on the right is smaller than the one on the left. 
If this is the case you have to add back to the resultant negative number, the correct power of 10 which is ten to the index. And if this is the case, 
You also have to borrow one from the integer so you subtract one from the original integer.*/		
	if (decimal < newDecimal){
		resultObj.decimal = pow(10, oldIndex) + (decimal - newDecimal);
		oldInt --;
	}else{
		resultObj.decimal =  decimal - newDecimal;
	}
	
	resultObj.integer = (oldInt) - (r1.integer);
	
//Make a final check to see if any of the values are negative, if so set everything to zero. 
	if( integer < 0 || decimal < 0){
		resultObj.integer = 0;
		resultObj.decimal = 0;
		resultObj.index = 0;
	}
	
	}
	return resultObj;
}

SmallDecimal SmallDecimal::operator *(const SmallDecimal& r1){
	long long number1, number2, product, index2;
	SmallDecimal resultObj; //creates new object to store result
	
	number1 = (integer * static_cast<int>(pow(10, (index)))) + decimal; //concatenates decimal and integer to one long long
	number2 = (r1.integer * static_cast<int>(pow(10,r1.index))) + r1.decimal;
	
	product = number1 * number2;
	index2 = index + r1.index; //new index = the sum of two previous indicies. 

	resultObj.decimal = product % static_cast<int>(pow(10, (index2))); //puts decimal and integer back to seperate fields. 
	resultObj.integer = product / static_cast<int>(pow(10, (index2)));
	
	return resultObj;

}
bool SmallDecimal::operator ==(const SmallDecimal& r1){
	if(integer == r1.integer && decimal == r1.decimal){
		return true;
	}else{
		return false;
	}
}
bool SmallDecimal::operator !=(const SmallDecimal& r1){
	if(integer == r1.integer && decimal == r1.decimal){
		return false;
	}else{
		return true;
	}
}
bool SmallDecimal::operator <(const SmallDecimal& r1){
	if(integer < r1.integer){
		return true;
	
	}else if(integer == r1.integer && decimal < r1.decimal){
		return true;
	}
	else{
		return false;
	}
}
SmallDecimal& SmallDecimal::operator ++(){
	integer++;
	return *this;
}
SmallDecimal SmallDecimal::operator ++(int){
	SmallDecimal temp = *this;
	++*this;
	return temp;
}
std::ostream& operator<<(ostream& outs, const SmallDecimal& source){
		//Handles case where there is a preceding 0 in the decimal field. Such as .0004
		string dec = to_string(source.decimal); 
		if (dec.length() < source.index){
			dec.insert (0, source.index - dec.length(), '0'); //inserts appropriate # of zeros
		}
		
		outs << source.integer <<  "."  << dec;
		return outs;
	
}
istream &operator>>(istream& ins, SmallDecimal& target)
{
	string number;
	ins >> number; 
	
	int decPoint = number.find(".");
	string strNum;
	target.integer = std::stoi(number.substr (0,decPoint));
	strNum = (number.substr(decPoint + 1, (number.length() - decPoint)));
	target.index = strNum.length();
	target.decimal = std::stoi(strNum);
	
return ins;
}
double SmallDecimal::toDouble()const{
	//Handles case where there is a preceding 0 in the decimal field. Such as .0004
	string dec = to_string(decimal); 
	if (dec.length() < index){
		dec.insert (0, index - dec.length(), '0');
		
	}
	string doubleStr = to_string(integer) + "." + dec;
	return stod(doubleStr);
}
string SmallDecimal::toString()const{
	//Handles case where there is a preceding 0 in the decimal field. Such as .0004
	string dec = to_string(decimal); 
	if (dec.length() < index){
		dec.insert (0, index - dec.length(), '0');
		
	}
	return to_string(integer) + "." + dec;
}