#include "List.h"
#include <iostream>

List::List(){
  count = 0;
  head = NULL;
}

List::~List(){
  clear();
}

bool List::full(){
  return false;
}

bool List::empty(){
  return count == 0;
}

int List::size(){
  return count;
}

void List::setPosition(int pos, ListPointer &current){
  current = head;
  for(int i = 2; i <= pos; i++){
    current = current->nextNode;
  }
}

void List::insert(int pos, ListEntry x){
  if (pos < 1 || pos > count + 1) abort();

  ListPointer newNode = new ListNode;
  if(newNode == NULL) abort();

  if(pos == 1){
    newNode->nextNode = head;
    head = newNode;
  }
  else{
    ListPointer current;
    setPosition(pos - 1, current);
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
  }

  newNode->entry = x;
  count++;
}

void List::remove(int pos, ListEntry &x){
  if (empty()) abort();

  if(pos < 1 || pos > count) abort();

  ListPointer q;
  if(pos == 1){
    q = head;
    head = head->nextNode; 
  }
  else{
    ListPointer current;
    setPosition(pos - 1, current);
    q = current->nextNode;
    current->nextNode = q->nextNode;
  }
  x = q->entry;
  delete q;
  count--;
}

void List::clear(){
  if (empty()) abort();

  ListPointer q;
  while(head != NULL){
    q = head;
    head = head->nextNode;
    delete q;
  }
  count = 0;
}

void List::retrieve(int pos, ListEntry &x){
  if (empty()) abort();
  if (pos < 1 || pos > count) abort();

  ListPointer current;
  setPosition(pos, current);
  x = current->entry;
}

void List::replace(int pos, ListEntry x){
  if (empty()) abort();
  if (pos < 1 || pos > count) abort();

  ListPointer current;
  setPosition(pos, current);
  current->entry = x;
}