#include <stdio.h>
#include <string>
#include "DLLNODE.h"
using namespace std;

class SDLL{
private:
	DLLNODE *head, *tail;
	int used = 0;
public:
	SDLL();
	~SDLL();
	bool isEmpty()const;
	void addToHead(string);
	void addToTail(string);
	string deleteFromHead();
	string deleteFromTail();
	void deleteNode(string);
	bool isInList(string);
	void removeDuplicates();
	void print()const;
	void reverse();
	void sort(bool = true);
	int getSize();
	string& operator[](const int i);


};
