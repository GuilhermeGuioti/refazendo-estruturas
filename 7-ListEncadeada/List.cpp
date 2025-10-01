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
  current = head; //current vai apontar para head, no caso 1 elemento
  for(int i = 2; i <= pos; i++){ //comecamos a comparacao em 2 (pois o 1 ja é o head) e realizmaos loop enquanto i <= pos
    current = current->nextNode; // vamos atualizando o current para o proximo
  }
}

void List::insert(int pos, ListEntry x){
  if (pos < 1 || pos > count + 1) abort(); //verificamos se é uma posicao valida

  ListPointer newNode = new ListNode; //tentamos alocar o novo nó
  if(newNode == NULL) abort();

  if(pos == 1){ // se a pos for 1 (adiconar no primeiro elemento)
    newNode->nextNode = head; //novo nó nextnode vai apontar para o head
    head = newNode; //head vai apontar o newNode (agora primeiro elemento)
  }
  else{
    ListPointer current;
    setPosition(pos - 1, current); //posicionamos o current uma posicao atras
    newNode->nextNode = current->nextNode; //fazemos as ligacoes dos ponteiros
    current->nextNode = newNode;
  }

  newNode->entry = x;
  count++;
}

void List::remove(int pos, ListEntry &x){
  if (empty()) abort();

  if(pos < 1 || pos > count) abort(); //verificamos se é uma posicao valida

  ListPointer q; //ponteiro auxilar que vamos usar para remover
  if(pos == 1){
    q = head; //q vai valer head, ou seja, para remover o primeiro
    head = head->nextNode; //head agora vai ser o proximo nó depois de head
  }
  else{
    ListPointer current;
    setPosition(pos - 1, current); //chamamaos o current uma posicao atras
    q = current->nextNode; 
    current->nextNode = q->nextNode;
  }
  x = q->entry;
  delete q; //deletamos o q (no caso ele foi configurado anteriormente para apontar para o indice que vamos tirar)
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