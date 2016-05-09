//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::put_in(PuzzleState *elem) {
  // TODO:  Put your code here!
  heap.push_back(elem); 
  int child = (int)heap.size() - 1;
  int p = parent(child);
  
  while (p >= 0 && child >= 0 && heap[child]->getBadness() < heap[p]->getBadness()) {
	swap(child, p);
    child = p; 
    p = parent(child);
  }
}

void HeapPriorityQueue::swap(int child, int parent) {
	PuzzleState* temp = heap[child];
	heap[child] = heap[parent];
	heap[parent] = temp;
}

PuzzleState * HeapPriorityQueue::take_out() {
  assert(!is_empty());

  // TODO:  Put your code here!
  PuzzleState* ps = heap[0];
  
  if (heap.size() == 1) {
	  heap.pop_back();
	  return ps;
  }
  swap(0, heap.size() - 1);
  heap.pop_back();
  int p = 0;
  while (true) {
	  int left_child = first_child(p);
	  if (left_child >= (int)heap.size()) {
		  break; 
	  }
	  int right_child = left_child + 1;
	  int max_child = left_child;
	  if (right_child < (int)heap.size() && heap[left_child] < heap[right_child]) {
		 max_child = right_child;  
	  }
	  
	  if (heap[max_child]->getBadness() >= heap[p]->getBadness()) {
		  swap(max_child, p);
		  p = max_child;
		  
	  } else break;
  }
  
  return heap[p];
}

bool HeapPriorityQueue::is_empty() {
  return (heap.size() == 0);
}

int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

#endif
