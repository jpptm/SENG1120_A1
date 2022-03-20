#include <cstdlib>
#include "Node.h"

// constructors
Node::Node(){
    next = NULL;
    previous = NULL;
    value_type();
}


Node::Node(const value_type& node_data_){
    node_data = node_data_;
}

// empty destructor
Node::~Node(){}

// setters
void Node::set_next(const Node* next_){
    next_ -> next;
}

void Node::set_previous(const Node* previous_){
    previous_ -> previous;
}

void Node::set_data(const value_type& node_data_){
    node_data = node_data_;
}

// getters
Node* Node::get_next() const{
    return next;
}

Node* Node::get_previous() const{
    return previous;
}

value_type Node::get_data() const{
    return node_data;
}