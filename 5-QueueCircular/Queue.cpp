#include "Queue.h"
#include <iostream>

Queue::Queue(){
  count = 0;
  head = 1;
  tail = maxQueue;
}

Queue::~Queue(){
  clear();
}

bool Queue::full(){
  return count == maxQueue;
}

bool Queue::empty(){
  return count == 0;
}

void Queue::clear(){
  count = 0;
  head = 1;
  tail = maxQueue;
}

int Queue::size(){
  return count;
}

void Queue::append(QueueEntry x){
  if(full()) abort();

  tail = (tail % maxQueue) + 1; //expressao chave para adicionar, sempre usando o tail, pois adicionamos no final da fila
  entry[tail] = x; //com o tail posicionado é so usar acessar o vetor entry na posicao tail e guardar x
  count ++;
}

void Queue::serve(QueueEntry &x){
  if(empty()) abort();

  x = entry[head]; //retoma o valor que vai ser removido
  head = (head % maxQueue) + 1; //expressao chave para remover, sempre usando o head, pois removemos no comeco da fila
  count --;
}

void Queue::getFront(QueueEntry &x){
  if(empty()) abort();

  x = entry[head];
}

void Queue::getRear(QueueEntry &x){
  if(empty()) abort();

  x = entry[tail];
}