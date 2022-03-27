#include "LinkedList.h"

// linked list constructor
LinkedList::LinkedList(){
    // set head, tail and current to null initially
    head = NULL;
    tail = NULL;
    current = NULL;
}

// declare destructor
LinkedList::~LinkedList(){}

// declare getter for current node
Node* LinkedList::get_current() const{
    return current;
}

// setter for current node
void LinkedList::set_current(Node* current_){
    current = current_;
}

// pass value_type data by reference and add to the tail of our linked list
void LinkedList::addToTail(Node::value_type& data){
    // instantiate new Node object
    Node* node_ = new Node();

    // If head is null then that means our linked list is empty
    if (this -> head == NULL){
        // set next and previous pointers and set data to fill node up
        node_ -> set_previous(NULL);
        node_ -> set_next(NULL);
        node_ -> set_data(data);
        // since it is the only node available it is both the head and the tail
        head = node_;
        tail = node_;
        current = head;
    }

    // if the linked list is not empty, we add to the end by 
    // 1) setting the current tail's next to be the new node 2) new node previous = current tail 3) new node next = null
    else{
        // set current tail's next value to the new node
        (this -> tail) -> set_next(node_);
        // set the new node's previous to our current tail
        node_ -> set_previous(this -> tail);
        // set the node's next pointer to null
        node_ -> set_next(NULL);
        // set our node as our new tail
        (this -> tail) = node_;
    }
    
}

// remove node using the object's name attribute
void LinkedList::remove(string name_){

}

void LinkedList::count(string name_) const{

}

void LinkedList::printStatistics() const{

}

void LinkedList::operator +=(LinkedList& list){
    // link the first list's tail to the second list's head
    (this -> tail) -> set_next(list.head);
    list.head -> set_previous(this -> tail);

    // the head node should still be the head of the first list but the new tail node of the concatenated list
    // must be the tail of the second list
    this -> tail = list.tail;
    this -> current = this -> head;
}

// overload << operator - should print (Object name, object age)
ostream& operator <<(ostream& out, const LinkedList& list){
    // set node* variable so we can traverse our linked list
    Node* current_ = list.get_current();
    // while we have nodes left to traverse
    while(current_ != NULL){
        // get data from current node
        Node::value_type object = current_ -> get_data();
        // append output to out
        out << "(" << object.get_name() << "," << object.get_score() << ") ";
        // set the new current to be the current current's next
        current_ = current_ -> get_next();
    }
    return out;
}

