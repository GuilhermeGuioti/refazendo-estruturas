#include "Queue.h"
#include <iostream>

Queue::Queue(){
  count = 0;
  head = 1;
  tail = maxQueue;
}

Queue::~Queue(){
  clear();
}

bool Queue::full(){
  return count == maxQueue;
}

bool Queue::empty(){
  return count == 0;
}

void Queue::clear(){
  count = 0;
  head = 1;
  tail = maxQueue;
}

int Queue::size(){
  return count;
}

void Queue::append(QueueEntry x){
  if(full()) abort();

  tail = (tail % maxQueue) + 1;
  entry[tail] = x;
  count ++;
}

void Queue::serve(QueueEntry &x){
  if(empty()) abort();

  x = entry[head];
  head = (head % maxQueue) + 1;
  count --;
}

void Queue::getFront(QueueEntry &x){
  if(empty()) abort();

  x = entry[head];
}

void Queue::getRear(QueueEntry &x){
  if(empty()) abort();

  x = entry[tail];
}