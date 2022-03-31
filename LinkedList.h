#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <string>
class LinkedList{
    public:
    // methods needed: add to tail, remove, operator +=  << overload, printStatistics, count, order and constructor
    // constructor
    LinkedList();
    LinkedList(Node::value_type& data);

    // destructor
    ~LinkedList();

    // add to tail of linked list by passing object as reference
    void addToTail(Node::value_type& node_data);

    // operator overload for += to concatenate lists
    void operator +=(LinkedList& list_rhs);

    // remove node by using the string value of the object as a tag / marker
    void remove(string name_);

    // print the details of each node - I think that both of the following functions should not be void
    // as we need the current node to be reset to its initial value for future uses
    void printStatistics() const;

    // count number of students that have the same name by taking a string input
    int count(string name_) const;

    // return list length
    int get_list_length() const;

    // print function for printStatistics() - this is so we don't have to return a pointer so we don't break encapsulation
    string LinkedList_to_string() const;

    // TEMPORARY DELETE LATER all below
    Node* get_head() const;

    private:
    // include current node tag
    Node* current;
    // head of the linked list
    Node* head;
    // tail of the linked list
    Node* tail;
    // number of nodes within the list
    int list_length;
};

ostream& operator <<(ostream& out, const LinkedList& list);
#endif // LINKED_LIST_H