#ifndef QUEUE_H
#define QUEUE_H

typedef char QueueEntry;
class Queue{
  private:
    struct QueueNode;
    typedef QueueNode* QueuePointer;
    struct QueueNode{
      QueueEntry entry;
      QueuePointer nextNode;
    };

    QueuePointer head;
    QueuePointer tail;

    int count;

  public:
    Queue();  
    ~Queue(); 
    bool empty();  
    int size();
    void clear();
    void append(QueueEntry x);
    void serve(QueueEntry &x);  
    void getFront(QueueEntry &x);
    void getRear(QueueEntry &x);
};

#endif