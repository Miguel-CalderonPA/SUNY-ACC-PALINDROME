// Libraries
#pragma once
#ifndef ITEMTYPE2
#define ITEMTYPE2
//libraries
#include <string>
#include<iostream>
using namespace std;

typedef string Word; // shortcut char to letter
struct node2  // item struct
{
	Word word;	//letter to store
	node2* next;	// link to next record
}; // end struct

#endif ITEMTYPE2