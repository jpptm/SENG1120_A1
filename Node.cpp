// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
#include <cstdlib>
#include "Node.h"

// constructors
Node::Node(Node* next_node, Node* previous_node, value_type& object_data){
    this -> next = next_node;
    this -> previous = previous_node;
    this -> node_data = object_data;
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

// getters - use const when we can and non const when we must alter the state of the object
const Node* Node::get_next() const{
    return next;
}

const Node* Node::get_previous() const{
    return previous;
}

Node* Node:: getNext(){
    return next;
}

Node* Node::getPrevious(){
    return previous;
}

Node::value_type Node::get_data() const{
    return node_data;
}

bool operator <(const Node::value_type& object_lhs, const Node::value_type& object_rhs){
    if (object_lhs.get_score() < object_rhs.get_score()){
        return true;
    }
    else{
        return false;
    }
}