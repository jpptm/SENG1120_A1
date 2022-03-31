#include <cstdlib>
#include "Node.h"

// constructors
Node::Node(Node* next_node, Node* previous_node, value_type& object_data){
    this->next = next_node;
    this->previous = previous_node;
    this->node_data = object_data;
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