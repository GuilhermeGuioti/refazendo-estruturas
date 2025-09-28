#ifndef STACK_H
#define STACK_H

typedef char StackEntry;
class Stack{
  private:
    struct StackNode;
    typedef StackNode* StackPointer;
    struct StackNode{
      StackEntry entry;
      StackPointer nextNode;
    };

    StackPointer top;
    int count;

  public:
    Stack();  
    ~Stack();
    bool full();  
    bool empty();  
    int size();
    void clear();
    void push(StackEntry x);
    void pop(StackEntry &x);  
    void getTop(StackEntry &x);
};

#endif