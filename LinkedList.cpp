// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
#include "LinkedList.h"
#include <sstream>

// linked list constructor
LinkedList::LinkedList(){
    // set head, tail and current and list length to null initially,
    head = NULL;
    tail = NULL;
    current = NULL;
    list_length = 0;
}


// declare destructor
LinkedList::~LinkedList(){
    if(list_length != 0){
        current = head;
        while( current != 0 ) {
            Node* next = current ->getNext();
            delete current;
            current = next;
        }
    }
    head = 0;
}


// pass value_type data by reference and add to the tail of our linked list in the heap
void LinkedList::addToTail(Node::value_type& data){

    // if list is initially empty
    if(list_length == 0){
        Node* new_data = new Node(NULL, NULL, data);

        // set data
        head = new_data;

        // set as new head, tail and current
        tail = head;
        current = head;
        list_length ++;
    }

    else{
        // set data and update tail for linked list
        Node* new_tail = new Node(NULL, tail, data);
        tail -> set_next(new_tail);
        tail = new_tail;
        list_length++;
    }
}


// remove node using the object's name attribute
Node::value_type LinkedList::remove(string name_){
    // if linked list is empty just skip the call
    Node::value_type return_data = Node::value_type();
    if(list_length == 0){
        return return_data;
    }
    else{
        // current is initialised as head by default
        current = head;
        // run through the whole list
        while (current != NULL){
            if((current -> get_data()).get_name() == name_){
                // account for three scenarios - deleting head, deleting tail, and deleting an internal node
                return_data = current -> get_data();
                // account for removing head
                if(current -> get_previous() == NULL){
                    // set head's next to be the new head then delete the old head
                    head = current -> getNext();
                    delete current;
                    // set current back to head
                    current = head;
                    // decrement list length
                    list_length--;
                }

                // if target node is our tail
                else if(current -> get_next() == NULL){
                    // set new tail to old tail's previous node
                    tail = current -> getPrevious();
                    // set new tail's next to null and delete current
                    tail -> set_next(NULL);
                    delete current;
                    // set current back to head
                    current = head;
                    // decrement list length
                    list_length--;
                }

                // if target node is within ll
                else{
                    // step back by 1 node so we dont have to traverse the list from the beginning again
                    Node* temp_current = current -> getPrevious();

                    // get previous node and next node of current
                    Node* previous_node = current -> getPrevious();
                    Node* next_node = current -> getNext();
                   
                    // link previous to next
                    previous_node -> set_next(next_node);
                    next_node -> set_previous(previous_node);

                    // delete current and set it back to temp current
                    delete current;
                    current = temp_current;
                    
                    // decrement list length
                    list_length--;
                }
            }
            // move on to the next node
            current = current -> getNext();
        }
    }
    // revert current back to beginning of linked list
    current = head;
    return return_data;
}


// return the number of students with the same name
int LinkedList::count(const string name_) const{
    // initialise temp node and count variable
    Node* temp_current = head;
    int count = 0;
    // traverse linked list
    while(temp_current != NULL){
        // if the name of the current node's data is the same as target increment current_ by 1
        if((temp_current -> get_data()).get_name() == name_){
            count++;
        }

        temp_current = temp_current -> getNext();
    }
    // destroy temp object and return count
    return count;
}


// print (minimum score/ mean score/ highest score)
void LinkedList::printStatistics() const{
    // declare temp node pointer to current
    Node* temp_current = current;
    // declare temp variables
    double total = 0;
    int max_score = current -> get_data().get_score();
    int min_score = current -> get_data().get_score();
    int current_score;
    // traverse the whole list and get all data while finding mix and max
    while (temp_current != NULL){
        current_score = temp_current -> get_data().get_score();

        // find min and max at the same time
        if(current_score < min_score){
            min_score = current_score;
        }

        if(current_score > max_score){
            max_score = current_score;
        }
        // increment total
        total += current_score;
        // move to the next node
        temp_current = temp_current -> getNext();
    }
    // get average and display total
    double average = total / list_length;
    cout << "(" << min_score << " / " << average << " / " << max_score << ")" << endl;

}


// get number of nodes within the list
int LinkedList::get_list_length() const{
    return list_length;
}


// concatenate 2 linked lists using the += operator
void LinkedList::operator +=(LinkedList& list_rhs){
    // declare temp node pointer
    Node* temp_current = list_rhs.head;
    // traverse the whole list
    while (temp_current != NULL){
        Node::value_type object_data = temp_current -> get_data();
        addToTail(object_data);
        temp_current = temp_current -> getNext();
    }
    // variables declared up above must be declared in the heap
    // if we simply linked the tail of the first list to the head of the second list, 
    // once the program reaches "Delete John from list 2"
    // it will also be deleted from the first list since they are the same node
}


// function to use for overloading << operator
string LinkedList::LinkedList_to_string() const{
    // declare temp variables
    Node* temp_current = head;
    string output, object_name, string_object_score;
    int object_score;
    // traverse the list
    while (temp_current != NULL){
        // get node data
        object_name = temp_current -> get_data().get_name();
        object_score = temp_current -> get_data().get_score();
        // convert score from int to string - reset ss declaration so we don't get the same output everytime
        stringstream ss;
        ss << object_score;
        ss >> string_object_score;
        // get output
        output += "(" + object_name + "," + string_object_score + ") ";
        // move on
        temp_current = temp_current -> getNext();
    }
    // return string for << overload
    return output;
}


// overload << operator - should print (Object name ,object age)
ostream& operator <<(ostream& out, const LinkedList& list){
    // use function above to return each data for each node within the linked list
    out << list.LinkedList_to_string();
    return out;
}


void LinkedList::swap(Node* j, Node* jnext) {
    // activate this function if  current < next 
    // base with the question "is j > jnext?"

    // if j is our head node and j is bigger than jnext, swap and make jnext head
    if (j -> get_previous() == NULL){ 
        // declare temp pointer
        Node* jnextnext = j -> getNext() -> getNext();

        // swap and make sure that pointers are set correctly and point to the right direction
        jnext -> set_next(j);
        j -> set_previous(jnext);
        jnext -> set_previous(NULL);

        jnextnext -> set_previous(j);
        j -> set_next(jnextnext);

        head = jnext;
    }

    // if jnext is tail and j is bigger than j next, swap and make j the new tail
    else if (j -> get_next() -> get_next() == NULL){
        // declare temp node
        Node* jprevious = j -> getPrevious();

        // swap
        jprevious -> set_next(jnext);
        jnext -> set_previous(jprevious);
        
        // make sure pointers point in the right direction and are set correctly
        jnext -> set_next(j);
        j -> set_previous(jnext);
        j -> set_next(NULL);
        
        tail = j;
    }

    // if both nodes are neither tail nor heads i.e., internal nodes swap them
    // also make sure that the neighbouring nodes are now pointing to the swapped values properly
    else{
        // declare temp nodes
        Node* jprevious = j -> getPrevious();
        Node* jnextnext = j -> getNext() -> getNext();

        // swap and make sure pointers point in the right direction and are set correctly
        jnext -> set_next(j);
        j -> set_previous(jnext);

        jprevious -> set_next(jnext);
        jnext -> set_previous(jprevious);

        j -> set_next(jnextnext);
        jnextnext -> set_previous(j);
    }

    // sanity check to make sure heads and tails are always the beginning and end of the linkedlist, respectively
    if(head == j){
        head = jnext;
    }

    if (tail == jnext){
        tail = j;
    }
}


// implement order() to sort nodes by score
void LinkedList::order(){
    // declare temp pointers - must minimise messing with member variables to diminish the risk of 
    // undefined behaviour in the code
    Node* temp_current = head;
    int min_value = head -> get_data().get_score();
     
    // find min value
    while (temp_current != NULL){
        if (temp_current -> get_data().get_score() < min_value){
            min_value = temp_current -> get_data().get_score();
        }
        temp_current = temp_current -> getNext();
    }

    // reset
    temp_current = head;

    // go through the whole list
    while(temp_current -> get_next() != NULL){
        if(temp_current -> getNext() -> get_data() < temp_current -> get_data()){
            swap(temp_current, temp_current -> getNext());
            // since swap() accounts for resetting the value of head, we make sure that origin is always the 
            // beginning of our linked list
            temp_current = head;
        }
        // go next
        temp_current = temp_current -> getNext();
    }

    temp_current = head;

    // if min value is smaller than head's score then we don't have the list fully sorted so go through it again
    if (temp_current -> get_data().get_score() > min_value){
        while(temp_current -> getNext() -> get_data() < temp_current -> get_data()){
            swap(temp_current, temp_current -> getNext());
        }
    }   
}