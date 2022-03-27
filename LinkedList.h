#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <string>
class LinkedList{
    public:
    // methods needed: add to tail, remove, operator +=  << overload, printStatistics, count, order and constructor
    // constructor
    LinkedList();

    // destructor
    ~LinkedList();

    // add getter for current node, must be used to overload << operator
    Node* get_current() const;

    // add setter for current node
    void set_current(Node* current_);

    // add to tail of linked list by passing object as reference
    void addToTail(Node::value_type& node_data);

    // operator overload for += to concatenate lists
    void operator +=(LinkedList& list);

    // remove node by using the string value of the object as a tag / marker
    void remove(string name_);

    // print the details of each node
    void printStatistics() const;

    // count function that takes name as string input
    void count(string name_) const;

    private:
    // include current node tag
    Node* current;
    // head of the linked list
    Node* head;
    // tail of the linked list
    Node* tail;
};

ostream& operator <<(ostream& out, const LinkedList& list);
#endif // LINKED_LIST_H