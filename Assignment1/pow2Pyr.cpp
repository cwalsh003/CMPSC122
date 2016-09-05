/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 1, 
** Program prints a pyramid counting in powers of 2 up to the center then counting down in powers of 2
*/

#include <iostream>
#include "math.h"

using namespace std;
int main(int argc, char *argv[]) {
	int rows, spaces, hash, i = 0;
	bool flag = false;
	for (rows = 0; rows <= 7; rows++ )//iterates through the rows
	{ 
		for(spaces = (7 - rows); spaces > 0; spaces--){ //iterates through the spaces
				printf("    "); // right orients the pyramid by printing the appropriate amount of spaces
			}
		for(hash = (rows + 1) * 2; hash > 1; hash--){
			printf ("%*.0f", 4, pow(2,i));//prints the power of 2 based on the value of i
			if(pow(2,i) >= pow(2,rows)){ //if the 2^i is greater than 2^row i is decremented 
				i--;
				flag = true;
			}
			else if (flag && pow(2,i) != pow(2,rows)){ //once the above if is true i decrements to zero. 
				i--;
			}
			else{//else i is incremented
				i++;
				}
			}
			cout << endl;	
			i = 0;//reset i
			flag = false; //reset flag
	}
	
	return 0;
}