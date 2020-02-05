#pragma once
/*
Author: Miguel Calderon
Date: March 23 2019
Modifications:  never ending
Date Last Modified: 3/18/19

Purpose: This specification contains the basis for a stack object in StackClass.
It currently contains details for one stack. It allows for keeping track of letters
in a stack . It contains 10 public methods. 1 private methods and
2 private data members. A summary of the methods appears below.

Assumptions: We will be storing letters

Summary of Methods
StackClass() -- create a new stack
StackClass() -- create a copied stack
IsEmpty() -- check if stack is empty
IsFull() -- check if stack is full
PUSH() -- insert a new letter into the stack
POP() -- delete a letter in the stack
Clear() -- clear the stack
GetLength() -- returns length of the stack
Retrieve() -- returns address to the top of stack
~StackClass() -- destory a stack
(private) Allocate()-- allocate memory for a new letter

PDMs
-Head -- top of stack
-count -- # of letters in the stack

*/

#pragma once
#ifndef  STACK
#define STACK

//Libaries
#include<string>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<fstream>
#include"ItemType.h"
using namespace std;
//contants
//const int MAX = 1638;
//start of class
class StackClass
{
public:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//CONSTRUCTORS (2)
	StackClass();
	/*
	Pre: needs to be called
	Post: a stack object
	Purpose: To be able to store letters in a stack fashion
	*/


	StackClass(/*in & out*/const StackClass& otherstack);
	/*
	Pre: needs to be given another StackClass object
	Post: a copied stack object
	Purpose: To be able to store letters in a stack fashion
	*/

	bool IsEmpty();
	/*
	Pre: needs to be called
	Post: returns true if stack is empty and false otherwise
	Purpose: to let the user know if the stack is empty
	*/

	bool IsFull();
	/*
	Pre: needs to be called
	Post: returns true if stack is full and false otherwise
	Purpose: to let the user know if the stack is full
	*/

	void PUSH(/*in*/Letter letter);
	/*
	Pre: needs a letter to add to stack
	Post: another node is added to the link
	Purpose: to add a letter to the stack
	*/

	void POP();
	/*
	Pre: needs to be called
	Post:  a letter is deleted from the stack
	Purpose:  to delete a letter from the stack
	*/

	void Clear();
	/*
	Pre: to be called
	Post: a cleared stack
	Purpose: to clear the entire stack
	*/
	
	node* Retrieve();
	/*
	Pre: needs to be called
	Post: returns the address of the top of the stack
	Purpose: gives the pointer for the top of the stack to the user
	*/
	int GetLength();
	/*
	Pre: needs to be called
	Post: gives # of items in the stack
	Purpose: returns the number of letters in a stack
	*/

	~StackClass(); // not sure if this is supposed to be public
	/*
	Pre: to be called
	Post: a destroyed stack
	Purpose:  to destroy our stack
	*/

protected:






private:
	// PDMs
	node* head; // keep track of front of  line
	int count; // keep count of items

	node* Allocate();
	/*
	Pre: needs to be called
	Post: allocates new memory for a node
	Purpose: allow the program take up memory efficiently
	*/

};


#endif STACK