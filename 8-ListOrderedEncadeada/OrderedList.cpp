#include "OrderedList.h"
#include <iostream>

OrderedList::OrderedList(){
  count = 0;

  sentinel = new ListNode;
  if(sentinel == NULL) abort(); //aloca a sentinela no construtor 

  head = sentinel; 
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
  
  sentinel->entry = x; // garante que o laço vai parar no máximo na sentinela

  while(p->entry < x){ // avança até achar onde inserir
    p = p->nextNode;
  }

  ListPointer newNode;
  newNode = new ListNode; //tenta alocar o nó que vamos adicionar
  if(newNode == NULL) abort();

  if(p == sentinel){ //vamos acrescentar o valor no final da fila, transformando o sentinel no valor que adicionamos e o newNode vai ser o sentinela
    p->nextNode = newNode;
    sentinel = newNode;
  }
  else{
    *newNode = *p; //transfere tudo do p para o novo Nó
    p->entry = x;
    p->nextNode = newNode; //faz a ligacao
  }

  count++;
}

void OrderedList::remove(ListEntry &x){
  ListPointer p = head;
  ListPointer q = NULL;

  sentinel->entry = x;

  while(p->entry < x){ //duas variaveis, uma posicionada da posicao e a outra uma posicao atras
    q = p;
    p = p->nextNode;
  }

  if(p == sentinel || p->entry != x) abort(); //verifica se encontrou o valor

  if(p == head){ //se for o primeiro valor, atualiza o head para o proximo
    head = head->nextNode;
  }
  else{ //caso contrario, atualiza o ponteiro de tras para conecatar no proximo
    q->nextNode = p->nextNode;
  }

  x = p->entry;
  delete p; //deleta o nó
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