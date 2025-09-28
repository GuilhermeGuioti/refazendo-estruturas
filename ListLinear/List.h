#ifndef LIST_H
#define LIST_H

typedef int ListEntry;

class List{
  private:
    static const int MaxList = 100;
    ListEntry entry[MaxList + 1];
    int count;

  public:
    List();
    ~List();
    bool full();
    bool empty();
    void insert(int pos, ListEntry x);
    void remove(int pos, ListEntry &x);
    int size();
    void clear();
    void retrieve(int pos, ListEntry &x);
    void replace(int pos, ListEntry x);  
};  

#endif