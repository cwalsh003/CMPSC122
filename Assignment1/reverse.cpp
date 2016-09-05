/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 1, 
** Program to reverse an integer 
*/
#include <iostream>

int reverse(int); // function prototype

using namespace std;
int main(int argc, char *argv[]) {
cout << reverse(123456789);

return 0;
}

int reverse(int n){
int number = 0;
string str = to_string(n), str2 =" "; //convert number to string

// for loop loops from length of array to zero and from zero to length of array
for(int i = (str.length() - 1), j = 0; i >= 0 && j < (str.length())  ; i--, j++){
		str2[j] = str[i]; //last element in the first array is the first element in second
	}
return stoi(str2, nullptr, 10);//convert reversed string back to integer
}