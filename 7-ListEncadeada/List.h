#ifndef LIST_H
#define LIST_H

typedef int ListEntry;

class List{
  private:
    struct ListNode;
    typedef ListNode* ListPointer;
    struct ListNode{
      ListEntry entry;
      ListPointer nextNode;
    };

    int count;
    ListPointer head;

    void setPosition(int pos, ListPointer &current);

  public:
    List();  
    ~List();
    bool empty();
    bool full();
    int size();
    void insert(int pos, ListEntry x);  
    void remove(int pos, ListEntry &x);
    void clear();
    void retrieve(int pos, ListEntry &x);
    void replace(int pos, ListEntry x);
};

#endif