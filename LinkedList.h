// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
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

    // add to tail of linked list by passing object as reference
    void addToTail(Node::value_type& node_data);

    // operator overload for += to concatenate lists
    void operator +=(LinkedList& list_rhs);

    // remove node by using the string value of the object as a tag / marker
    Node::value_type remove(string name_);

    // print (lowest score/ mean / highest score)
    void printStatistics() const;

    // count number of students that have the same name by taking a string input
    int count(const string name_) const;

    // return list length
    int get_list_length() const;

    // print function for printStatistics() - this is so we don't have to return a pointer so we don't break encapsulation
    string LinkedList_to_string() const;
    
    // order method -sort nodes from lowest to highest marks
    void order();

    private:
    // include current node tag
    Node* current;

    // head of the linked list
    Node* head;

    // tail of the linked list
    Node* tail;

    // number of nodes within the list
    int list_length;

    // swap function for order()
    void swap(Node* j, Node* jnext);
};


ostream& operator <<(ostream& out, const LinkedList& list);
#endif // LINKED_LIST_H