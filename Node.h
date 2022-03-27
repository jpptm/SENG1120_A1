#ifndef NODE_H
#define NODE_H

#include "Student.h"
#include <cstdlib>

class Node{
    public:
    // initialising constructors
    typedef Student value_type;

    // initialise empty constructor
    Node();

    // initialise destructor
    ~Node();

    // initialise getters and setters
    void set_next(Node* next_);
    void set_previous(Node* previous_);
    void set_data(value_type& node_data_);

    Node* get_next() const;
    Node* get_previous() const;
    value_type get_data() const;
    
    // declare private member variables
    private:
    // pointer pointing to next node
    Node* next;
    // pointer pointing to previous node
    Node* previous;
    // data within node
    value_type node_data;
};
#endif // NODE_H