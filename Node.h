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
    Node(const value_type& node_data_);

    // initialise destructor
    ~Node();

    // initialise getters and setters
    void set_next(const Node* next_);
    void set_previous(const Node* previous_);
    void set_data(const value_type& node_data_);

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