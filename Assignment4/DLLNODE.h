//
//  DLLNODE.h
//  DoublyLinkedList
//
//  Created by Colin Walsh on 4/7/16.
//  Copyright (c) 2016 Colin Walsh. All rights reserved.
//

#ifndef DoublyLinkedList_DLLNODE_h
#define DoublyLinkedList_DLLNODE_h
#include <string>
using namespace std;
class DLLNODE{
public:
	string info;
	DLLNODE();
	DLLNODE(string el, DLLNODE *n = nullptr, DLLNODE *p = nullptr);
	DLLNODE *next, *prev;

};

#endif
