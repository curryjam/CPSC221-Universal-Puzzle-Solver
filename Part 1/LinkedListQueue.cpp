//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

void LinkedListQueue::put_in(PuzzleState *elem)
{
	node * temp = new node;
	temp->data = elem;
	temp->next = NULL;
	
	if (head == NULL) {
		head = temp;
	} else {
		tail->next = temp;
	}
	tail = temp;
}

PuzzleState *LinkedListQueue::take_out()
{
  assert(head != NULL);
  PuzzleState *ret = head->data;
  node* temp = head->next;
  delete head;
  head = temp;
  size--;
  return ret;
}

bool LinkedListQueue::is_empty()
{
  return head == NULL;
}

LinkedListQueue::~LinkedListQueue()
{
  while(head != NULL)
	take_out();
}

#endif

