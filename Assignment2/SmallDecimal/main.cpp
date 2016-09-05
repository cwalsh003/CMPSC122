/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2,
** This is a program to test the SmallDecimal class  
*/
#include <iostream>
#include <cstdlib>
#include "smallDecimal.h"
#include <typeinfo>

using namespace std;
int main(int argc, char *argv[]) {

	SmallDecimal decimal2("8.2"); //Testing one arg construstor
	SmallDecimal decimal1("2.25");
	SmallDecimal decimal3;			//Testing no arg construstor
	SmallDecimal decimal4("86.75");
	SmallDecimal decimal5("3.432");
	SmallDecimal decimal6("32.009");
	
	cout << decimal6 << " - " << decimal5  << " = " << decimal6 - decimal5 << endl; //Testing overloaded - operator with left operand having a smaller decimal value
	cout << decimal6 << " + " << decimal5  << " = "<< decimal6 + decimal5 << endl;  //Testing overloaded + operator with left operand having a smaller decimal value	
	
/*
* Test cases from the assignment guidelines. 
*/
	SmallDecimal x("45.67");
	SmallDecimal y("2.5");
		cout << x << endl;
		cout << y << endl;
	   //Should print 48.17
	   cout << x << " + " << y  << " = " << x + y << endl;
	   cout << x << " - " << y  << " = " << x - y << endl;
	   cout << x << " * " << y  << " = " << x * y << endl;
	   //Should print 2.5
	   cout << y++ << endl;
	   //Should print 4.5
	   cout << ++y << endl;
/*
* Test cases from the assignment guidelines. 
*/

	
	cout << decimal2 << " x " << decimal1  << " = " <<  (decimal2 * decimal1) << endl; //Testing overloaded * operator
	
	cout << boolalpha << decimal2 << " = " << decimal3  <<" "<< (decimal2 == decimal3) << endl; //Testing overloaded == operator false case
	cout << boolalpha << decimal2 << " != " << decimal3  <<" "<< (decimal2 != decimal3) << endl; //Testing overloaded != operator True case
	cout << boolalpha << decimal2 << " = " << decimal2  <<" "<< (decimal2 == decimal2) << endl; //Testing overloaded == operator True case
	cout << boolalpha << decimal2 << " != " << decimal2  <<" "<< (decimal2 != decimal2) << endl; //Testing overloaded != operator  False case
	
	cout << boolalpha << decimal3 << " < " << decimal2  <<" "<< (decimal3 < decimal2) << endl;  //Testing overloaded != operator  False case
	cout << boolalpha << decimal2 << " < " << decimal1  <<" "<< (decimal2 < decimal1) << endl;  //Testing overloaded != operator  False case

	
	
	 cout << typeid(decimal4.toDouble()).name()<< endl; //Shows type id as d for double 
	 cout << "decimal5 as a double is: " << decimal5.toDouble()<< endl;
	cout << typeid(decimal4.toString()).name()<< endl; //Shows type id as NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE for string 
	 cout << "decimal5 as a string is: " << decimal5.toString()<< endl;
	
	
	SmallDecimal decimal7;
	cout << "Enter the decimal for your new decimal object. " << endl; 
	cin >> decimal7;			//testing overloaded instream
	cout << "You new decimal object is: "<< decimal7;
	
	
	
return 0;
	
}