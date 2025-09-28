#include "OrderedList.h"
#include <iostream>

OrderedList::OrderedList(){
  count = 0;

  sentinel = new ListNode;
  if(sentinel == NULL) abort();

  sentinel = head;
}

OrderedList::~OrderedList(){
  clear();
  delete sentinel;
}

bool OrderedList::empty(){
  return count == 0;
}

void OrderedList::insert(ListEntry x){
  ListPointer p = head;
  
  sentinel->entry = x;

  while(p->entry < x){
    p = p->nextNode;
  }

  ListPointer newNode;
  newNode = new ListNode;
  if(newNode == NULL) abort();

  if(p == sentinel){
    p->nextNode = newNode;
    sentinel = newNode;
  }
  else{
    *newNode = *p;
    p->entry = x;
    p->nextNode = newNode;
  }

  count++;
}

void OrderedList::remove(ListEntry &x){
  ListPointer p = head;
  ListPointer q = NULL;

  sentinel->entry = x;

  while(p->entry < x){
    q = p;
    p = p->nextNode;
  }

  if(p == sentinel || p->entry != x) abort(); 

  if(p == head){
    head = head->nextNode;
  }
  else{
    q->nextNode = p->nextNode;
  }

  x = p->entry;
  delete p;
  count--;
}

int OrderedList::search(ListEntry x){
  ListPointer p = head;
  int pos = 1;

  sentinel->entry = x;

  while(p->entry != x){
    p = p->nextNode;
    pos++;
  }

  if(p == sentinel) abort();

  return pos;
}

void OrderedList::clear(){
  ListPointer p;

  while(head != NULL){
    p = head;
    head = head->nextNode;
    delete p;
  }

  count = 0;
}