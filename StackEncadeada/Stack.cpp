#include "Stack.h"
#include <iostream>

Stack::Stack(){
  top == NULL;
  count == 0;
}

Stack::~Stack(){
  clear();
}

bool Stack::full(){
  return false;
}

bool Stack::empty(){
  return count == 0; //ou top==NULL;
}

int Stack::size(){
  return count;
}

void Stack::push(StackEntry x){
  StackPointer newNode;
  newNode = new StackNode;
  if(newNode == NULL) abort();

  newNode->entry = x;
  newNode->nextNode = top;
  top = newNode;

  count++;
}

void Stack::pop(StackEntry &x){
  if(empty()) abort();
  
  x = top->entry;

  StackPointer p;
  p = top;
  top = top->nextNode;
  delete p;

  count--;
}

void Stack::getTop(StackEntry &x){
  if(empty()) abort();

  x = top->entry;
}

void Stack::clear(){
  StackPointer p;
  while(top != NULL){
    p = top;
    top = top->nextNode;
    delete p;
  }
  count = 0;
}