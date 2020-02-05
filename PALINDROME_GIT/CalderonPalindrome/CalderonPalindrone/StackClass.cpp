// libraries
#include "StackClass.h" 
#include"ItemType.h"


StackClass::StackClass()
{
	// set PDMs
	head = nullptr; // set top  of stack to null
	count = 0; // set count to 0

} // end default constructor

StackClass::StackClass(const StackClass &otherStack)
{
	node* temp = otherStack.head; // address to top of other stack
	node* temp2=head; // copy it
	do
	{
		if (temp = otherStack.head) //intial condition
		{
			head = Allocate(); // allocate new letter
			head->let = temp->let; // copy
			temp2 = head; // set head
		}
		else // after intial condition
		{
			temp2->next = Allocate(); // allocate new letter
			temp2->next->let = temp->let; // copy
			temp = temp2->next; // set pointer to next node
		}
		temp = temp->next; // gets next letter
	} while (temp != nullptr); // if at bottom of stack end
} // end copy contructor


bool StackClass::IsEmpty()
{
	return (head == nullptr); // is top of stack empty
} // end IsEmpty

bool StackClass::IsFull()
{
	if (count >= MAX)
		return true;
	else
		return false;
} // end IsFull

void StackClass::PUSH(/*in*/Letter letter)
{
	if (IsEmpty()) // if empty
	{
		head = Allocate(); // get new memory
		head->let = letter; // save letter in stack
		head->next = nullptr; // set head to null
	} // end if for empty
	else // if not empty
	{
		node* temp = Allocate(); // get memory
		temp->let = letter; // assign new letter
		temp->next = head; // set next to null
		head = temp; // set new memory to head
	} // end else for not empty
	count++; // add 1 to stack counter

	 /* just for testing can comment these out
	cout << "Head: " << head->let << endl;  
	cout << "count: " << count << endl;
	// just for testing can comment these out */

} // end PUSH

void StackClass::POP()
{
	if (!IsEmpty()) // if not empty
	{
			node* temp = head->next; // set temp to next in stack
			delete head; // delete top of stack
			head = temp; // set top of stack to head
			count--; // sub 1 from stack counter

	 /*just for testing can comment out
			if(head!=nullptr) 
			cout << "Head: " << head->let << endl; 
			cout << "count: " << count << endl;
 //just for testing can comment these out  */

	} // end if !Empty

} // end POP

void StackClass::Clear()
{
	while (!IsEmpty()) // while not empty
	{
		POP(); // repeat delele letter
	} // end while
} // end Clear


node* StackClass::Allocate()
{
	node* temp = new node; // get new memory
	temp->next = temp; // set temp to the next link
	return (temp); // return new memory
} // end Allocate

node* StackClass::Retrieve()
{
	return head;
}


int StackClass::GetLength()
{
	return count; // return length of stack
}

StackClass::~StackClass()
{
	Clear(); // delete the Stack
} // end Destructor