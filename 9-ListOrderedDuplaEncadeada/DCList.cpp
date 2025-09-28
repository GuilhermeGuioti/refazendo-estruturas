#include "DCList.h"
#include <iostream>

DCList::DCList(){
  count = 0;

  head = new ListNode;
  if(head == NULL) abort();

  head->nextNode = head;
  head->prevsNode;
}

DCList::~DCList(){
  clear();
  delete head;
}

bool DCList::empty(){
  return count == 0;
}

void DCList::insert(ListEntry x){
  ListPointer p;
  
  head->entry = x;

  p = head->nextNode;
  while(p->entry < x){
    p = p->nextNode;
  }

  ListPointer newNode;
  newNode = new ListNode;
  if(newNode == NULL) abort();

  if(p == head){
    p->nextNode = newNode;
    head = newNode;
  }
  else{
    *newNode = *p;
    p->entry = x;
    p->nextNode = newNode;
    newNode->prevsNode = p;
    newNode->nextNode->prevsNode = newNode;
  }

  count++;
}

void DCList::remove(ListEntry &x){
  ListPointer p;
  ListPointer q = NULL;

  head->entry = x;

  p = head->nextNode;
  while(p->entry < x){
    q = p;
    p = p->nextNode;
  }

  if(p == head || p->entry != x) abort(); 

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

int DCList::search(ListEntry x){
  ListPointer p = head->nextNode;
  int pos = 1;

  head->entry = x;

  while(p->entry != x){
    p = p->nextNode;
    pos++;
  }

  if(p == head) abort();

  return pos;
}

void DCList::clear(){
  ListPointer p = head->nextNode;
  ListPointer temp;

  while(p != head){
    temp = p;
    p = p->nextNode;
    delete temp;
  }

  head->nextNode = head;
  head->prevsNode = head;
  count = 0;
}