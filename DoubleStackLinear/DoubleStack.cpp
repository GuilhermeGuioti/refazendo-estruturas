#include "DoubleStack.h"
#include <iostream>

Stack::Stack(){
  top1 = -1;
  top2 = MaxEntry;
}

Stack::~Stack(){
  stack1_clear();
  stack2_clear();
}

bool Stack::full(){
  return top2 - top1 == 1;
}

bool Stack::stack1_empty(){
  return top1 = 0;
}

bool Stack::stack2_empty(){
  return top2 = 0;
}

int Stack::stack1_size(){
  return top1 + 1;
}

int Stack::stack2_size(){
  return MaxEntry - top2;
}

void Stack::stack1_clear(){
  top1 = -1;
}

void Stack::stack2_clear(){
  top1 = MaxEntry;
}

void Stack::stack1_push(StackEntry x){
  if(full()) abort();

  top1++;
  entry[top1];
}

void Stack::stack2_push(StackEntry x){
  if(full()) abort();

  top2--;
  entry[top2];
}

void Stack::stack1_pop(StackEntry &x){
  if(stack1_empty()) abort();

  x = entry[top1];
  top1--;
}

void Stack::stack2_pop(StackEntry &x){
  if(stack2_empty()) abort();

  x = entry[top2];
  top1++;
}