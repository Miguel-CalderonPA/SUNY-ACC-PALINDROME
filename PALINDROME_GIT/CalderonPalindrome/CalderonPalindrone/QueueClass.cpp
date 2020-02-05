// libraries
#include "QueueClass.h" 
#include"ItemType.h"


QueueClass::QueueClass()
{
	// set PDMs
	head = nullptr; // set front of queue to null
	tail = nullptr; // set back of queue to null
	count = 0; // set # of items to 0

} // end default constructor

QueueClass::QueueClass(const QueueClass& otherQueue)
{
	if (!IsEmpty()) // if not empty
	{
		node* temp = otherQueue.head; // set beginning address
		do
		{
			Enqueue(temp->let); // copy other elements
			temp = temp->next; // point to next
		} while (temp != nullptr); // while not at end
	}
} // end copy contructor


 bool QueueClass::IsEmpty()
{
	 return ((head == nullptr) && (tail == nullptr)); // are back and front queue both null
} // end IsEmpty

 bool QueueClass::IsFull()
 {
	 if (count >= MAX) // if count is greater than max then full
		 return true;
	 else // if less than max then not full
		 return false;
 }// end IsFull

 void QueueClass::Enqueue(/*in*/Letter letter)
 {
	 if (!IsFull()) // if not full
	 {
		 if (IsEmpty()) // if empty
		 {
			 node* temp = Allocate(); // get memory
			 temp->let = letter; // assign letter
			 head = temp; // set front of queue to new letter
			 tail = temp; // set back of queue to new letter
			 tail->next = nullptr; // set next to null
		 } // end if for empty
		 else // if not empty
		 {
			 node* temp = Allocate(); // get memory
			 temp->let = letter; // assign new letter
			 temp->next = nullptr; // set next to null
			 tail->next = temp; // set back of queue to next memory
			 tail = tail->next; // set back of queue to next
			 
		 } // end else for not empty
		 count++; // add 1 to queue counter

		  /* just for testing can comment these out
		 cout << "Head: " << head->let << endl;
		 cout << "Tail: " << tail->let << endl;
		 cout << "Count: " << count << endl;
		 // just for testing can comment these out */

	 } // end if not full
 } // end Enqueue

 void QueueClass::Dequeue()
 {
	 if (!IsEmpty()) // if not empty
	 {
		 if (head == tail) // if back of line == front of line
		 {
			 delete head; // delete front of line
			// delete tail; // delete end of line
			 head = nullptr; // set front of line to null
			 tail = nullptr; // set back of line to null
			 count--; // sub 1 from queue counter
		 } // end if for front == back of line
	 
		 else // if back and front are !=
		{
			 node* temp = head->next; // set temp to 2nd in line
			 delete head; // delete front of line
			 head = temp; // set front of line to 2nd
			 count--; // sub 1 from queue counter
			
		} // end else !Empty

		  /* just for testing can comment these out 
		 if(head != nullptr)
			cout << "Head: " << head->let << endl; 
		 if(tail != nullptr)
			 cout << "Tail: " << tail->let << endl;
			 cout << "Count: " << count << endl;
		// just for testing can comment these out */

	 } // end if !Empty
	
 } // end Dequeue

 void QueueClass::Clear()
 {
	 while (!IsEmpty()) // while not empty
	 {
		 Dequeue(); // repeat delele letter
	 } // end while
 } // end Clear


 node* QueueClass::Allocate()
 {
	 node* temp = new node; // get new memory
	 temp->next = temp; // set temp to the next link
	return (temp); // return new memory
 } // end Allocate

 node* QueueClass::Retrieve()
 {
	 return head;
 }

 int QueueClass::GetLength()
 {
	 return count; // return length of queue
 } // end GetLength
 
 QueueClass::~QueueClass()
 {
	 Clear(); // delete the queue
 } // end Destructor