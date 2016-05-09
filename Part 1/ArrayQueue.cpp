#ifndef _ARRAYQUEUE_CPP
#define _ARRAYQUEUE_CPP

//ArrayQueue.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp file) is here to help get you
// started, but you are free to change function signatures, etc. as
// long as ArrayQueue is derived from BagOfPuzzleStates.
ArrayQueue::ArrayQueue()
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  front = 0;
  back = 0;
  size = 0;
  capacity = INIT_SIZE;
  array =  new PuzzleState*[capacity];
}

void ArrayQueue::put_in(PuzzleState *elem)
{
  ensure_capacity(capacity + 1);
  array[back] = elem;
  back = (back+1) % capacity;
  size++;
}

PuzzleState *ArrayQueue::take_out()
{
  assert(!is_empty());
  PuzzleState *elem = array[front];
  front = (front + 1) % capacity;
  size--;
  return elem;
}

bool ArrayQueue::is_empty()
{
  return front == back;
}

void ArrayQueue::ensure_capacity(int n)
{
  if (capacity < n) {
    // Make plenty of room.
    int target_capacity = (n > 2*capacity+1) ? n : (2*capacity+1);

  // Set the current array aside and make room for the new one.
	PuzzleState **oldarray = array;
	array = new PuzzleState*[target_capacity];

    // Copy each element of the old array over.
    // Update front carefully as you go!  Can you just use front++?

	int i = 0;

    while (front != back) {
		array[i] = oldarray[front];
		front = (front + 1) % capacity;
		i++;
      }

    // Fix front and back and capacity so they correspond to the new array.
	front = 0;
    back = i;
    capacity = target_capacity;

    // Delete the old array.
    delete[] oldarray;
  }
}


ArrayQueue::~ArrayQueue()
{
  delete[] array;
  // do any cleanup like deallocating
  // any dynamically allocated memory
}

#endif
