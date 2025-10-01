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

  if(pos < 1 || pos > count + 1) abort(); //verificamos se uma posicao valida

  for(int i = count; i >= pos; i--){ //abrimos espaco para adiconar um novo item (do final ate a posicao)
    entry[i + 1] = entry[i]; //colocamos na proxima posicao o valor que estava na posicao anterior
  }

  entry[pos] = x; //guradamos o valor na posicao

  count++;
}

void List::remove(int pos, ListEntry &x){
  if(empty()) abort();

  if (pos < 1 || pos > count) abort(); //verificamos se é uma posicao valida


  x = entry[pos]; //guardamos em x o valor que vai ser removido

  for(int i = pos; i < count; i++){ //movemos todos itens a partir da posicao que vamos retirar ate o final
    entry[i] = entry[i + 1]; //guardamos na posicao i, o valor do item da frente
  }

  count--;
}

void List::retrieve(int pos, ListEntry &x){
  if(empty()) abort();

  if (pos < 1 || pos > count) abort();

  x = entry[pos];
}

void List::replace(int pos, ListEntry x){
  if(empty()) abort();

  if (pos < 1 || pos > count) abort();

  entry[pos] = x;
}