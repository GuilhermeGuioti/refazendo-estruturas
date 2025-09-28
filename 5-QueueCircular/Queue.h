#ifndef QUEUE_H
#define QUEUE_H

typedef int QueueEntry;

class Queue{
  private:
    static const int maxQueue = 100;
    QueueEntry entry[maxQueue + 1];
    int count;
    int head;
    int tail;

  public:
    Queue();  
    ~Queue();
    bool full();
    bool empty();
    void append(QueueEntry x);
    void serve(QueueEntry &x);
    int size();
    void clear();
    void getFront(QueueEntry &x);  
    void getRear(QueueEntry &x);    
};

       
#endif