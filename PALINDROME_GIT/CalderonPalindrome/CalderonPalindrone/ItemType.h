// Libraries
#pragma once
#ifndef ITEMTYPE
#define ITEMTYPE
//libraries
#include <string>
#include<iostream>
using namespace std;
const short MAX_STR = (int)9;
const int MAX = 1638;
typedef char Letter; // shortcut char to letter
struct node  // item struct
{
	Letter let;	//letter to store
	node* next;	// link to next record
}; // end struct

#endif ITEMTYPE