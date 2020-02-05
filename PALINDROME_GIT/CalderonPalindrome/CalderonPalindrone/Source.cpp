/*
Author: Miguel Calderon

Date: 3/25/19

File Name: CalderonPalindrome

Purpose: To be able to store items onto a queue in this case,these
items are letters and will be used in comparison with a stack to
see if letters are palindrones

Inputs: letters hardcoded by the user in this case, but later will be
from a file

Outputs: the percentage of the file that is a palindrome (9 word max currently)

Assumptions: nothing but letters count toward palindromes and we have a 9 word max

Error Checking: only takes in letters
*/

//Libraries
#include<iostream>
#include<string>
#include<fstream>
#include"QueueClass.h"
#include"StackClass.h"
#include "ItemType.h"

using namespace std;
//Prototypes
void StoreData(/*in & out*/string strArr[MAX_STR],/*in & out*/QueueClass& q1,/*in & out*/ StackClass& s1,/*in & out*/ ifstream& din, /*int & out*/int& wordCt,/*in*/ short wordCap);
void StoreLetters(/*in*/string word, /*in & out*/QueueClass& q1, /*in & out*/StackClass& s1); 
bool CheckPalindrome(/*in & out*/QueueClass& q1,/*in & out*/ StackClass& s1);
void SetupArray(/*in & out*/string strArr[MAX_STR],/*in & out*/ ifstream& din, /*in & out*/int& wordCt);
void PrintFile(/*in*/string file);
// CONSTANTS 0percent.txt   63percent.txt     100percentv1.txt  100percentv2.txt	test.txt
const string INPUT_FILE = "test.txt"; // while file to test
const string END = "EOF"; // basically a flag in string array saying no more
const short INTIAL_POS = 0; // check for end of information
const double DROME_PERCENT = 60.0f; // % of file that needs to be a palindrome, so it can be published
const double HUNDRED = 100.0f; //  used for percents

int main()
{
	// variables
	// File I/O
	ifstream din;
	ofstream dout;

	// counters
	int wordCt;
	int PalindromeCt;
	int endfileCt=MAX_STR;
	short wordCap;
	// output
	double percent;

	// checks for palindromes
	string file; 

	// Instantiate classes
	QueueClass q1;  // queue
	cout << "QueueClass Instantiated " << endl;
	StackClass s1; // stack
	cout << "StackClass Instantiated " << endl;

	// create array 
	string strArr[MAX_STR];  // string array

	// prime the counters
	wordCt = 0;
	PalindromeCt = 0;

	cout << endl <<  "Please Enter a file for review: " << endl;
	cin >> file; // takes in file
	// open file
	//din.open(INPUT_FILE.c_str());
	din.open(file.c_str());
	if (!din) //if no file
	{
		cout << "File not found" << endl;
		dout << "No file found, no data processed" << endl;

	} // ends din if
	else // if file found
	{
		cout << "file found" << endl << endl; // let user know
		PrintFile(file); //print file
		wordCap = MAX_STR; // set wordCap
		StoreData(strArr, q1, s1, din, wordCt, wordCap);//priming read
		while (strArr[INTIAL_POS]!=END) // while they're still words to check
		{
			
			while (wordCap > 0) // once 0 it can rid of first word in array
			{

				if (CheckPalindrome(q1,s1))//CheckStrings(strQueue, strStack)) // check if equal
				{
					//cout << "word 1 to " <<wordCap << " palindrome" << endl; // let user know
					//cout << "Palindrome at word: " << wordCt<< endl;
					PalindromeCt = PalindromeCt + wordCap; // count palindrome
					
					for (short i = 0; i < wordCap - 1; i++)
					{// clear space in array
						SetupArray(strArr, din, wordCt);  // create space for new word(s)
					} // end for
					wordCap = 0; // end while
				} // end if for palindrome
				else
				{
					wordCap--; // decremente last word per run
					StoreData(strArr, q1, s1, din, wordCt, wordCap); // fill Queue and stack
				
				} // end else for not palindrome

			} // end wordCap while loop
			//cout<< endl << "Next Set" << endl;

			SetupArray(strArr,din,wordCt);  // create space for new word

			
			if (din) // if not EOF, reset to max
			{
				wordCap = MAX_STR; // set to max
			} // end if still data
			else // if not data
			{
				endfileCt--; // counts how many elements to use in array, due to the chain of words ending
				wordCap = endfileCt; // set a new max
			}
			StoreData(strArr, q1, s1, din, wordCt, wordCap); // fill queue and stack for reset

		} // end while din
		percent = HUNDRED*((double)PalindromeCt / (double)wordCt);
		cout << endl << percent  << " percent of the file is a Palindrome" << endl;
		if (percent >DROME_PERCENT-(double)1)
		{
			cout << "APPROVED for <Palindrome Press> Publication!" << endl << endl;
		} // end if good for press
		else
		{
			cout << "NOT to be printed to <Palindrome Press>" << endl << endl;
		} // end if bad for press
		din.close(); // close file
		//PrintFile(file); //print file

	} // end if file found
	system("pause");
	return 0; 
} // end main

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void StoreData(/*in & out*/string strArr[MAX_STR],/*in & out*/QueueClass& q1, /*in & out*/StackClass& s1, /*in & out*/ifstream& din, /*in & out*/int& wordCt, /*in*/short wordCap)
{
	/*
	Pre: needs array to store into, classes to send to store letters
	(cleaner in main) counts the words, and wordCap for filling array
	Post: a filled array, letters stored in stack and queue, updated counter for words
	Purpose: to reset the next set of strings to check
	*/
	if ((wordCap == MAX_STR) && (wordCt==0)) // only goes here on intial fill
	{
		string data; // hold file data
		for (short i = 0; i < wordCap; i++)
		{
			din >> data; // take in data
			if (din)
			{
				strArr[i] = data; // put in array
				StoreLetters(strArr[i], q1, s1); // store characters in stack and queue
				wordCt++; // count words
			}
			else
			{
				strArr[i] =END; // put in array
			}
		
		} // end for
	} // end intial fill
	else if (wordCap == MAX_STR) // if more letters in file go here
	{
		for (short i = 0; i < wordCap; i++)
		{
			StoreLetters(strArr[i], q1, s1); //store charcaters in stack and queue
		} // end for
	} // end fill when EOF not reached
	else // will go here when it nears end of file
	{
		for (short i = 0; i < wordCap; i++)
		{
			StoreLetters(strArr[i], q1, s1);//store charcaters in stack and queue
		} // end for
	} // end fill when near EOF

}// end fill string queue

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void SetupArray(/*in & out*/string strArr[MAX_STR], /*in & out*/ifstream& din,/* in & out*/ int& wordCt)
{
	/*
	Pre: needs array to shift and add one element and adds to wordCt
	Post: a shifted array with one element added and word counter
	Purpose: similar to StoreData, but this is used for shifting and adding one word, not for storing letters
	*/
	string data; // hold data
	for (short i = 0; i < MAX_STR-1; i++)
	{
		strArr[i] = strArr[i + 1]; // set next element to current
	} // end for
	din >> data; // grab next data
	if (din) // if data
	{
		wordCt++; // count word
		strArr[MAX_STR - 1] = data;// insert data
	} // end if
	else // if no data
	{
		strArr[MAX_STR - 1] = END; // place marker
	} // end else
} // end SetupArray

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void StoreLetters(/*in*/string word,/* in & out*/ QueueClass& q1, /* in & out*/StackClass& s1)
{
	/*
	Pre:needs a word to grab characters from, classes to store characters too
	Post: a filled stack and queue with letters from word
	Purpose: fill stack and queue
	*/
	for (short i = 0; i < word.length(); i++)
	{
		 if ((word[i] > 96) && (word[i] < 123)) // if lowercase
		{
			 // fill stack and queue
			q1.Enqueue(word[i]);
			s1.PUSH(word[i]);
		} // end if lowercase
		else if ((word[i] > 64) && (word[i] < 91)) // if uppercase
		{
			// set to lowercase and fill stack and queue
			word[i] = word[i] + 32;
			q1.Enqueue(word[i]);
			s1.PUSH(word[i]);
		} // end if uppercase
	} // end for loop 
} // end store letters

 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool CheckPalindrome(/*in*/QueueClass& q1,/*in*/ StackClass& s1)
{
	/*
	Pre: needs a queue and stack to compare
	Post: returns bool if the same
	Purpose: return if queue and stack are the same
	*/
	bool palindrome = true; // intialize bool
	char queueChar; // hold queue char
	char stackChar; // hold stack char
	while (!s1.IsEmpty()) // while stack isn't empty
	{
		stackChar = s1.Retrieve()->let; // get stack char
		s1.POP(); // pop off the stack
		queueChar = q1.Retrieve()->let; // get queue char
		q1.Dequeue(); // dequeue off the stack
		
		if (stackChar != queueChar) // if not the same
			palindrome = false; // set same

	}
	return palindrome; // return if a palindrome



} // end CheckStrings

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void PrintFile(/*in*/string file)
{
	/*
	Pre: needs file to read
	Post: prints file to terminal
	Purpose: print original file to screen
	*/
	ifstream din; // reader
	string data; // hold line
		din.open(file.c_str()); // open file
		if (din) // if file exist
		{
			cout << endl<< " FILE GIVEN: " << endl;
			do 
			{
				cout << data << endl; // output line
				getline(din,data); // get line
				
			} while (din); // while data
			
			din.close(); // close file
		}
		else
			cout << "No file to Print" << endl; // let user know if no file 
} // end PrintFile

/*
QueueClass Instantiated
StackClass Instantiated
StringQueueClass Instantiated

Please Enter a file for review:
0percent.txt
file found

0 percent of the file is a Palindrome
NOT to be printed to <Palindrome Press>

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

QueueClass Instantiated
StackClass Instantiated
StringQueueClass Instantiated

Please Enter a file for review:
63percent.txt
file found

62.5 percent of the file is a Palindrome
APPROVED for <Palindrome Press> Publication!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

QueueClass Instantiated
StackClass Instantiated
StringQueueClass Instantiated

Please Enter a file for review:
100percentv1.txt
file found

100 percent of the file is a Palindrome
APPROVED for <Palindrome Press> Publication!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

QueueClass Instantiated
StackClass Instantiated
StringQueueClass Instantiated

Please Enter a file for review:
100percentv2.txt
file found

100 percent of the file is a Palindrome
APPROVED for <Palindrome Press> Publication!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

QueueClass Instantiated
StackClass Instantiated
StringQueueClass Instantiated

Please Enter a file for review:
test.txt
file found

29.6 percent of the file is a Palindrome
NOT to be printed to <Palindrome Press>


*/
