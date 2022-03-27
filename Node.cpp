#include <cstdlib>
#include "Node.h"

// constructors
Node::Node(){
    next = NULL;
    previous = NULL;
    value_type();
}

// empty destructor
Node::~Node(){}

// setters
void Node::set_next(Node* next_){
    next = next_;
}

void Node::set_previous(Node* previous_){
    previous = previous_;
}

void Node::set_data(value_type& node_data_){
    node_data = node_data_;
}

// getters
// NB: set return value of getter as const since they dont alter anything
Node* Node::get_next() const{
    return next;
}

Node* Node::get_previous() const{
    return previous;
}

Node::value_type Node::get_data() const{
    return node_data;
}