/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 5,
** Program that implements a linked list
*/

#include <iostream>
#include "SDLL.h"

void newList();
void menu(SDLL&);

using namespace std;

int main(int argc, const char * argv[]) {
	SDLL lst;
	menu(lst);

	return 0;
}

void newList(){
	SDLL lst;
	menu(lst);
}

void menu(SDLL& lst){
	int value;
	string Svalue, Snum;

	do{
		cout << "What would you like to do?" << endl;
		cout << "1) Create a String Doubly linked list " << endl;
		cout << "2) Get Size: the current number of nodes in the list " << endl;
		cout << "3) Insert a new element at the head of the linked list" << endl;
		cout << "4) Insert a new element at the tail of the linked list" << endl;
		cout << "5) Delete the first element " << endl;
		cout << "6) Delete the last element " << endl;
		cout << "7) Delete a specific node" << endl;
		cout << "8) Sort the elements in  ascending order" << endl;
		cout << "9) Sort the elements in descending order" << endl;
		cout << "10) Reverse the list" << endl;
		cout << "11) Remove any duplicates" << endl;
		cout << "12) Print all the elements in the list" << endl;
		cout << "13) Quit the program" << endl;
		cin >> value;

		switch (value) {
		case 1:{
			newList();
			break;
		}
		case 2:{
			cout << "The length of the list is: " << lst.getSize() << endl << endl;
			;
			break;
		}
		case 3:{
			cout << "Enter an value to add to head. ";
			cin.ignore();
			getline(cin, Svalue);
			lst.addToHead(Svalue);
			break;
		}
		case 4:{
			cout << "Enter an vale to add to tail. ";
			cin.ignore();
			getline(cin, Svalue);
			lst.addToTail(Svalue);
			break;
		}
		case 5:{
			cout << "The head has been deleted. " << endl << endl;
			lst.deleteFromHead();
			break;
		}

		case 6:{
			cout << "The tail has been deleted. " << endl << endl;
			lst.deleteFromTail();
			break;
		}
		case 7:{
			cout << "Enter an value to delete from the list. ";
			cin >> Snum;
			lst.deleteNode(Snum);
			break;
		}
		case 8:{
			cout << "The list is sorted in Ascending order " << endl << endl;
			lst.sort(1);
			break;
		}
		case 9:{
			cout << "The list is sorted in Descending order  " << endl << endl;
			lst.sort(0);
			break;
		}
		case 10:{
			lst.reverse();
			break;
		}
		case 11:{
			lst.removeDuplicates();
			break;
		}
		case 12:{
			lst.print();
			cout << endl << endl;
			break;
		}
		default:
			continue;

		}

	} while (value != 13);
}
