#include "Queue.h"
#include <iostream>

Queue::Queue(){
  head = tail = NULL;
  count = 0;
}

Queue::~Queue(){
  clear();
}

bool Queue::empty(){
  return count == 0;
}

int Queue::size(){
  return count;
}

void Queue::append(QueueEntry x){
  QueuePointer newNode;
  newNode = new QueueNode;
  if(newNode == NULL) abort();

  if(empty()){
    head = newNode;
  }
  else{
    tail->nextNode = newNode;
  }
  newNode->entry = x;
  newNode->nextNode = NULL;
  tail = newNode;

  count++;
}

void Queue::serve(QueueEntry &x){
  if(empty()) abort();

  x = head->entry;

  QueuePointer p;
  p = head;
  head = head->nextNode;
  delete p;

  count --;

  if(head == NULL) tail = NULL;
}

void Queue::getFront(QueueEntry &x){
  if(empty()) abort();

  x = head->entry;
}

void Queue::getRear(QueueEntry &x){
  if(empty()) abort();

  x = tail->entry;
}

void Queue::clear(){
  if(empty()) abort();

  QueuePointer p;
  while(p != tail){
    p = head;
    head = head->nextNode;
    delete p;
  }
  
  tail = NULL;
  count = 0;
}