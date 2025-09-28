#include "List.h"
#include <iostream>

List::List(){
  count = 0;
}

List::~List(){
  clear();
}

bool List::full(){
  return count == MaxList;
}

bool List::empty(){
  return count == 0;
}

int List::size(){
  return count;
}

void List::clear(){
  count = 0;
}

void List::insert(int pos, ListEntry x){
  if(full()) abort();

  if(pos < 1 || pos > count + 1) abort();

  for(int i = count; i >= pos; i--){
    entry[i + 1] = entry[i];
  }

  entry[pos] = x;

  count++;
}

void List::remove(int pos, ListEntry &x){
  if(empty()) abort();

  if (pos < 1 || pos > count) abort();

  x = entry[pos];

  for(int i = pos; i < count; i++){
    entry[i] = entry[i + 1];
  }

  count--;
}

void List::retrieve(int pos, ListEntry &x){
  if(empty()) abort();

  if (pos < 1 || pos > count) abort();

  x = entry[pos];
}

void List::retrieve(int pos, ListEntry &x){
  if(empty()) abort();

  if (pos < 1 || pos > count) abort();

  entry[pos] = x;
}