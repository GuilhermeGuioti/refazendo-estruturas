#ifndef DCLIST_H
#define DCLIST_H

typedef int ListEntry;

class DCList{
  private:
    struct ListNode;
    typedef ListNode* ListPointer;
    struct ListNode{
      ListEntry entry;
      ListPointer nextNode;
      ListPointer prevsNode;
    };

    int count;
    ListPointer head;

  public:
    DCList();  
    ~DCList();
    bool empty();
    bool full();
    int size();
    void insert(ListEntry x);  
    void remove(ListEntry &x);
    void clear();
    int search(ListEntry x);
};

#endif