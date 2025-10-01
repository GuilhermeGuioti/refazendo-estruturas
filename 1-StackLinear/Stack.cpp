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

  x = entry[top]; //armazena em x, o valor que vai ser removido
  top--; //decrementa o top (dessa maneira já removeove o item)
}

void Stack::push(StackEntry x){
  if(full()) abort();

  top++; //incrementa o top (antes de adicionar)
  entry[top] = x; //adiciona em entry, na posicao top, o valor de x
}