#include <iostream>

class LinkedList;

class ListNode {
private:
    int data;
    ListNode *next;
public:
    ListNode() : data(0), next(0){};
    ListNode(int i) : data(i), next(0){};

    friend class LinkedList;
};

class LinkedList {
private:
    ListNode *first;
public:
    LinkedList() : first(0){};
    void PrintList();
    void Push_front(int x);
    void Push_back(int x);
    void Delete(int x);
    void Clear();
    void Reserve();
};

void LinkedList::PrintList() {
    if (first == 0) return;

    ListNode *current = first;
    while (current != 0) {
        cout << current->data << endl;
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Push_front(int x) {
    ListNode *newNode = new ListNode(x);
    newNode->next = first;
    first = newNode;
}

void LinkedList::Push_back(int x) {
    if (first == 0) Push_front(x);

    ListNode *current = first;
    while (current != 0) {
        current = current->next;
    }
    current->next = new ListNode(x);
}

void LinkedList::Delete(int x) {
    ListNode *current = first;
    while (current != 0) {
        if (current->data == x) 
    }
}