// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
#ifndef NODE_H
#define NODE_H

#include "Student.h"
#include <cstdlib>

// this class will serve as data containers for our linked list

class Node{
    public:
    // initialise typedef
    typedef Student value_type;
    
    // initialising constructors
    Node(Node* next_node, Node* previous_node, value_type& object_data);

    // initialise destructor
    ~Node();

    // initialise getters and setters
    void set_next(Node* next_);
    void set_previous(Node* previous_);
    void set_data(value_type& node_data_);

    const Node* get_next() const;
    Node* getNext();
    const Node* get_previous() const;
    Node* getPrevious();
    value_type& get_data();
    
    // declare private member variables
    private:
    Node* next;
    Node* previous;
    value_type node_data;
};

// overload < operator to use for typedef objects
bool operator <(const Node::value_type& object_lhs, const Node::value_type& object_rhs);
#endif // NODE_H