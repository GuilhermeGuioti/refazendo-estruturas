#include "Stack.h"
#include <iostream>

Stack::Stack(){
  top = 0;
}

bool Stack::empty(){
  return top == 0;
}

bool Stack::full(){
  return MaxEntry == top;
}

int Stack::size(){
  return top;
}

void Stack::clear(){
  top = 0;
}

void Stack::pop(StackEntry &x){
  if(empty()) abort();

  x = entry[top];
  top--;
}

void Stack::push(StackEntry x){
  if(full()) abort();

  top++;
  entry[top] = x;
}