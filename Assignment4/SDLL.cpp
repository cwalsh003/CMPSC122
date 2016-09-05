//
//  SDLL.cpp
//  
//
//  Created by Colin Walsh on 4/7/16.
//
//
#include <iostream>
#include "SDLL.h"
#include "DLLNODE.h"
#include <cassert>

using namespace std;

DLLNODE::DLLNODE() {
	next = prev = nullptr;
}

DLLNODE::DLLNODE(string el, DLLNODE *n, DLLNODE *p) {
	info = el;
	next = n;
	prev = p;
}

bool SDLL::isEmpty()const {
	if (head == nullptr) {
		return true;
	}
	else return false;
}


void SDLL::addToHead(string el) {
	if (tail == nullptr) {
		tail = head = new DLLNODE(el); //if list is empty, create new node
	}
	else {

		head = new DLLNODE(el, head); //else create new node and change poiters
		head->next->prev = head;
	}
	used++;

}

void SDLL::addToTail(string el) {
	if (tail == nullptr) {
		head = tail = new DLLNODE(el);//if list is empty, create new node
	}
	else {
		tail = new DLLNODE(el, nullptr, tail);//else create new node and change poiters
		tail->prev->next = tail;

	}
	used++;
}

string SDLL::deleteFromHead() {
	string infoS;
	if (!isEmpty()) { //checks if list is empty
		infoS = head->info;
	}
	else {
		infoS = "The list is empty ";
	}

	if (head == tail) {
		delete head; //delete node
		head = tail = nullptr; // fixes the pointers
		used--;
	}
	else {

		head = head->next; //adjusts pointers
		delete head->prev; //deletes node
		head->prev = nullptr; //adjusts pointers
		used--;
	}

	return infoS;
}

string SDLL::deleteFromTail() {
	string infoS;
	if (isEmpty()) {
		infoS = tail->info;
	}
	else {
		infoS = "The list is empty ";
	}

	if (head == tail) {
		delete tail;
		tail = head = nullptr;
		used--;
	}
	else {
		tail = tail->prev;
		delete  tail->next;
		tail->next = nullptr;
		used--;
	}

	return infoS;
}

void SDLL::deleteNode(string el) {
	if (!isEmpty()) {//checks if the list is empty
		if (isInList(el)) { //checks to see if the node is in list
			if (head->info == el) {
				deleteFromHead();
			}
			else {
				DLLNODE* curr = head; //current node pointer
				DLLNODE*  trail = nullptr;//node pointer that trails one behind
				while (curr != nullptr) {
					if (curr->info == el) { //searches for the element
						break;
					}
					else {
						trail = curr; //moves the pointer
						curr = curr->next;
					}
				}
				if (curr->next == nullptr) {
					deleteFromTail();
				}
				else {
					trail->next = curr->next;
					curr->next->prev = trail;
					delete curr;
					used--;
				}
			}
		}
		else {
			cout << "The element was not found in the list" << endl;
		}
	}
	else {
		cout << "The list is empty" << endl;
	}
}

bool SDLL::isInList(string el) {
	DLLNODE* curr = head;
	while (curr != nullptr) {
		if (curr->info == el) {
			break;
		}
		else {
			curr = curr->next;
		}
	}
	if (curr == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

void SDLL::print()const {
	if (!isEmpty()) {
		DLLNODE* curr = head;
		while (curr != nullptr) {
			cout << curr->info << " ";
			curr = curr->next;
		}

	}
	else {
		cout << "The list is empty" << endl;
	}
}

void SDLL::removeDuplicates() {
	DLLNODE* curr = head;
	while (curr != nullptr) {//loop that moves the first pointer
		DLLNODE* curr2 = curr->next;//loop that moves the second pointer
		string value = curr->info;
		DLLNODE* temp = curr->next;
		while (curr2 != nullptr) {
			if (curr2->info == value) {//looks for duplicates
				deleteNode(value);//deletes duplicates
				break;
			}
			curr2 = curr2->next;
		}
		curr = temp;
	}
}

void SDLL::reverse() {
	DLLNODE *ptr = head;
	while (ptr != NULL) {
		DLLNODE *tmp = ptr->next;
		ptr->next = ptr->prev;//switches pointers next equals prev
		ptr->prev = tmp;
		if (tmp == NULL) {
			tail = head;
			head = ptr;
		}
		ptr = tmp;
	}

}

void SDLL::sort(bool asc) {
	DLLNODE* curr = head;
	DLLNODE* ins = head;
	if (!isEmpty()) {
		curr = curr->next;
		if (asc) {
			while (curr != nullptr) {
				ins = head;
				while (ins != curr) {
					if (ins->info > curr->info) {
						swap(ins->info, curr->info);
					}
					else {
						ins = ins->next;
					}
				}
				curr = curr->next;
			}
		}
		else {
			while (curr != nullptr) {
				ins = head;
				while (ins != curr) {
					if (ins->info < curr->info) {
						swap(ins->info, curr->info);
					}
					else {
						ins = ins->next;
					}
				}
				curr = curr->next;
			}
		}

	}
	else {
		cout << "The list is empty" << endl;
	}
}

int SDLL::getSize() {
	return used;
}
string& SDLL::operator[](const int i) {
	DLLNODE* curr = head;
	assert(!isEmpty() || (i < getSize() + 1) || i >= 0);

	for (int j = 1; j < i; j++) {
		curr = curr->next;
	}
	return curr->info;
}


SDLL::SDLL() {
	head = tail = nullptr;
}
SDLL::~SDLL() {
	DLLNODE* curr = head;
	while (curr != nullptr) {
		DLLNODE* temp = curr->next;
		delete curr;
		curr = temp;
	}
}