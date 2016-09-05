/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 1, 
** program to swap a pointer
*/



#include <iostream>

using namespace std;

void swap(double, double);

int main(int argc, char *argv[]) {
	double a = 77, b = 25;
	double* p = &a; 
	double* q = &b;
	
	cout << "content of p: " << p << endl;
	cout << "content of q: " << q << endl << endl;
	
	swap(p, q);
	
	cout << "content of p: " << p << endl;
	cout << "content of q: " << q << endl;
	return 0;
	
}

void swap(double &x, double &y){//creates reference to the pointers
	double temp = x;
	x = y;
	y = temp;
}