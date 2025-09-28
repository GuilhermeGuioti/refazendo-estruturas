#ifndef STACK_H
#define STACK_H
typedef char StackEntry;
class Stack{
  private:
    static const int MaxEntry = 100;
    StackEntry entry[MaxEntry + 1];
    int top;

  public:
    Stack(); 
    ~Stack();
    bool empty(); 
    bool full();
    void push(StackEntry x); 
    void pop(StackEntry &x); 
    int size(); 
    void clear(); 
    void getTop(StackEntry &x);
};
#endif