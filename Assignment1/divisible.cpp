/*
Colin Walsh
cjw254@psu.edu
Assignment 1, 
program to check if numbers are evenly divisible without using local variables. 
.
*/
#include <iostream>

bool divisible(int num1, int num2){ //determines if two numbers are divisible
	if(num1 % num2 == 0){
		return true;
	}else{
		return false;
	}
}
using namespace std;
int main(int argc, char *argv[]) {
	int num1, num2;
	
	cout << "Enter a number... ";
	cin >> num1;
	cout << "Enter another number... ";
	cin >> num2;
	
	cout << divisible(num1, num2);
	
	return 0;
}