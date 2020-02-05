#pragma once
/*
Author: Miguel Calderon
Date: March 23 2019
Modifications:  never ending
Date Last Modified: 3/18/19

Purpose: This specification contains the basis for a queue object in QueueClass.
It currently contains details for one queue. It allows for keeping track of letters
in a queue . It contains 10 public methods. 1 private methods and
3 private data members. A summary of the methods appears below.

Assumptions: We will be storing letters

Summary of Methods
QueueClass() -- create a new queue
QueueClass() -- create a copied queue
IsEmpty() -- check if queue is empty
IsFull() -- check if queue is full
Enqueue() -- insert a new letter into the queue
Dequeue() -- delete a letter in the queue
Clear() -- clear the queue
Retrieve() -- return the head of the queue
GetLength() -- get the length of the queue
~QueueClass() -- destory a queue 
(private) Allocate()-- allocate memory for a new letter

PDMs
-Head -- head of queue
-Tail -- back of queue
-count -- # of letters in the queue

*/

#pragma once
#ifndef  QUEUE
#define QUEUE

//Libaries
#include<string>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<fstream>
#include"ItemType.h"
using namespace std;

//start of class
class QueueClass
{
public:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	QueueClass();
	/*
	Pre: needs to be called
	Post: a queue object
	Purpose: To be able to store letters in a queue fashion
	*/


	QueueClass(/*in & out*/const QueueClass& otherQueue);
	/*
	Pre: needs to be given another queueclass object
	Post: a copied queue object
	Purpose: To be able to store letters in a queue fashion
	*/

	bool IsEmpty();
	/*
	Pre: needs to be called
	Post: returns true if queue is empty and false otherwise
	Purpose: to let the user know if the queue is empty
	*/

	bool IsFull();
	/*
	Pre: needs to be called
	Post: returns true if queue is full and false otherwise
	Purpose: to let the user know if the queue is full
	*/

	void Enqueue(/*in*/Letter letter);
	/*
	Pre: needs a letter to add to queue
	Post: another node is added to the link
	Purpose: to add a letter to the queue
	*/

	void Dequeue();
	/*
    Pre: needs to be called
    Post:  a letter is deleted from the queue
    Purpose:  to delete a letter from the queue
    */

	void Clear();
	/*
	Pre: to be called
	Post: a cleared queue
	Purpose: to clear the entire queue
	*/

	
	node* Retrieve();
	/*
	Pre: needs to be called
	Post: returns the address of the head of the queue
	Purpose: gives the pointer for the front of the line to the user
	*/
	int GetLength();
	/*
	Pre: needs to be called
	Post: gives # of items in the queue
	Purpose: returns the number of letters in a queue
	*/

	~QueueClass(); // not sure if this is supposed to be public
	/*
    Pre: to be called
    Post: a destroyed queue
    Purpose:  to destroy our queue
    */

protected:






private:
	// PDMs
	node* head; // keep track of front of  line
	node* tail; // keep track of back of line
	int count; // keep count of items

node* Allocate();
	/*
    Pre: needs to be called
    Post: allocates new memory for a node
    Purpose: allow the program take up memory efficiently
    */



};

#endif QUEUE