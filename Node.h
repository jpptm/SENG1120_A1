#ifndef NODE_H
#define NODE_H

#include "Student.h"
#include <cstdlib>

class Node{
    // initialise typedef
    typedef Student value_type;

    public:
    // initialising constructors
    Node();

    // initialise destructor
    ~Node();

    // initialise getters and setters
    void set_next(Node* next_);
    void set_previous(Node* previous_);
    void set_data(value_type node_data_);

    Node* get_next() const;
    Node* get_previous() const;
    value_type get_data() const;
    
    // declare private member variables
    private:
    Node* next;
    Node* previous;
    value_type node_data;
};
#endif // NODE_H