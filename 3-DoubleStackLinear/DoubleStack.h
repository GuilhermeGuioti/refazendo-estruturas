#ifndef STACK_H
#define STACK_H
typedef char StackEntry;
class Stack{
  private:
    static const int MaxEntry = 100;
    StackEntry entry[MaxEntry + 1];
    int top1;
    int top2;

  public:
    Stack(); 
    ~Stack();
    bool full();

    bool stack1_empty();
    bool stack2_empty();

    void stack1_clear();
    void stack2_clear();

    void stack1_push(StackEntry x);
    void stack2_push(StackEntry x);

    void stack1_pop(StackEntry &x);
    void stack2_pop(StackEntry &x);

    void stack1_getTop(StackEntry &x);
    void stack2_getTop(StackEntry &x);

    int stack1_size();
    int stack2_size();
};
#endif