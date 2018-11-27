//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Nick Zimmermann	
//Complier:  g++
//File type: queue function implementation
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
	this->count = 0;
	this->front = 0;
	this->rear = -1;
}

//destructor 
queue::~queue()
{

}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
	if (count == MAX_SIZE - 1)
		return true;
	else
		return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
		if (isFull())
		{
			throw Overflow();
		}
		else
		{
			this->rear = (this->rear + 1) % MAX_SIZE;
			this->el[rear] = newElem;
			count++;
//			cout << "Count: " << count << endl;
//			cout << "REAR: " << this->rear << endl;
		}
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
		if (isEmpty())
		{
			throw Underflow();
		}
		else
		{
			frontElem(removedElem);
//			cout << "REMOVEDELEM: " << removedElem << endl;
			this->front = (this->front + 1) % MAX_SIZE;
			count--;
//			cout << "COUNT: " << count << endl;
//			cout << "FRONT: " << this->front << endl;
		}
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
		if (isEmpty())
		{
			throw Underflow();
		}
		else
		{
			theElem = this->el[front];
		}
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
	return this->count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
	if (count == 0)
	{
		cout << "[ empty ]" << endl;
	}
	else
	{
		int fakeFront = this->front;
		do
		{
			cout << "[ ";
			cout << el[fakeFront] << " ";
			cout << "] ";
			fakeFront = (fakeFront + 1) % MAX_SIZE;
		} while (fakeFront != this->rear);
	}


}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{// ** comment a local variable
		if (isEmpty())
		{
			throw Underflow();
		}
		else if(count == 1)
		{
			//do nothing
		}
		else
		{
			el_t local; //here is the local variable
			add(local);
			remove(local);
		}
}





