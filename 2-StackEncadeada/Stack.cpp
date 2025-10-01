#include "Stack.h"
#include <iostream>

Stack::Stack(){
  top == NULL; //topo inicia em NULL, pois nao tem nenhum nó para ele apontar
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
  newNode = new StackNode; //ponteiro adicional aponta para o novo nó que estamos criando e adicionando
  if(newNode == NULL) abort();

  newNode->entry = x; //armazena o valor de x no campo entry do novo nó
  newNode->nextNode = top; //nextnode do novo nó aponta para onde top apontava
  top = newNode; //top agora vai ser o novo nó

  count++;
}

void Stack::pop(StackEntry &x){
  if(empty()) abort();
  
  x = top->entry; //armazena em x o valor que vai ser removido

  StackPointer p; 
  p = top; //ponteiro auxiliar aponta para mesmo lugar do top (fazemos isso para poder deletar o primeiro item sem remover o top)
  top = top->nextNode; //topo vai ser o topnextnode agora
  delete p; //deleta o item do topo

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