#include "Queue.h"
#include <iostream>

Queue::Queue(){
  head = tail = NULL;
  count = 0;
}

Queue::~Queue(){
  clear();
}

bool Queue::empty(){
  return count == 0;
}

int Queue::size(){
  return count;
}

void Queue::append(QueueEntry x){
  QueuePointer newNode;
  newNode = new QueueNode; //tentamos uma alocação dinamica do novo nó
  if(newNode == NULL) abort();

  if(empty()){ //se a fila estiver vazia (ou seja, vai ser o primeiro nó a ser inserido)
    head = newNode; //head vai apontar para o novo nó
  }
  else{
    tail->nextNode = newNode; //se nao for o primeiro, vamos colocar sempre no final, ligando o antigo ultimo nó no novo nó
  }
  newNode->entry = x; //guarda o valor de x no campo entry do novo nó
  newNode->nextNode = NULL; //o nextnode do novo nó aponta para nulo, pois nao tem nada depois dele, ou seja, ele é o ultimo
  tail = newNode; //tail vai apontar para o novo nó, pois agora ele é o ultimo

  count++;
}

void Queue::serve(QueueEntry &x){
  if(empty()) abort();

  x = head->entry; //guarda em x o valor que vai ser removido (primeiro item da fila)

  QueuePointer p;
  p = head; //ponteiro auxiliar aponta para head (temos ponteiro auxiliar, para nao deletarmos o head e perder ele)
  head = head->nextNode; //head agora vai ser o proximo nó depois dele (segundo item)
  delete p; //deletamos p (primeiro item da fila)

  count --;

  if(head == NULL) tail = NULL; //se tiver apenas um item e a gente deletou ele, fazemos tail apontar para null tambem, para ficar certo para adicionar algo futuramente
}

void Queue::getFront(QueueEntry &x){
  if(empty()) abort();

  x = head->entry;
}

void Queue::getRear(QueueEntry &x){
  if(empty()) abort();

  x = tail->entry;
}

void Queue::clear(){
  if(empty()) abort();

  QueuePointer p; //ponteiro auxiliar
  while(p != tail){
    p = head; //aponta para head para comecarmos a percorrer
    head = head->nextNode; //head vai ser atualizado para o proximo item, pois vamos deletar o primeiro
    delete p; //deletamos o primeiro item
  }
  
  //voltamos os ponteiros o tail e o count para as condicoes iniciais
  //head já sera null tambem
  tail = NULL;
  count = 0;
}