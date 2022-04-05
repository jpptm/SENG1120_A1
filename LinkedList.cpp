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
LinkedList::~LinkedList(){}


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
        Node* new_tail = new Node(NULL, this->tail, data);
        this -> tail -> set_next(new_tail);
        this -> tail = new_tail;
        list_length++;
    }
}


// remove node using the object's name attribute
void LinkedList::remove(string name_){
    // if linked list is empty just skip the call
    if(list_length == 0){
        return;
    }
    else{
        // current is initialised as head by default
        current = head;
        // run through the whole list
        while (current != NULL){
            if((current->get_data()).get_name() == name_){
                // account for three scenarios - deleting head, deleting tail, and deleting an internal node

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
}


// return the number of students with the same name
int LinkedList::count(string name_) const{
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
    delete temp_current;
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
    // get average
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
        this -> addToTail(object_data);
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
    Node* temp_current = current;
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
    // set node* variable so we can traverse our linked list
    out << list.LinkedList_to_string();
    return out;
}


// sort linked list using scores of nodes
void LinkedList::order(){
    // FIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIX AND FINALISE
    Node* previous; Node* next; Node* new_start; Node* target;

    Node::value_type minimum_score = current -> get_data();

    new_start = head;
    target = current;

    while(new_start != NULL){

        // find min first    
        while(current != NULL){
            if(current -> get_data() < minimum_score){
                minimum_score = current -> get_data();
                target = current;
            }
            current = current -> getNext();
        }
        // minimum node is found at this point
    
        // if target is the same as new_start it is already where it is meant to be so just go next
        if (target == new_start){
            new_start = new_start -> getNext();
            current = new_start;
        }

        else if (target == tail){
            // if target is the tail and new_start is the head
            if (new_start -> get_previous() == NULL){

                previous = target -> getPrevious();
                previous -> set_next(NULL);
                tail = previous;

                target -> set_next(new_start);
                target -> set_previous(NULL);
                new_start -> set_previous(target);

                head = target;
            }
            // if new_start is not the head but an internal node
            else{
                // swap normally
                previous = target -> getPrevious();
                previous -> set_next(NULL);
                tail = previous;

                target -> set_next(new_start);
                target -> set_previous (new_start -> getPrevious());
                new_start -> getPrevious() ->set_next(target);
                new_start -> set_previous(target);
            }
            new_start = new_start -> getNext();
            current = new_start;
        }

        // account for if a node is internal and new_start is head or otherwise
        else{
            // if new_start is head and target is an internal node
            if(new_start -> get_previous() == NULL){
                previous = target -> getPrevious();
                next = target -> getNext();

                previous -> set_next(next);
                next -> set_previous(previous);
                
                target -> set_next(new_start);
                target -> set_previous(NULL);
                new_start -> set_previous(target);

                head = target;
            }
            // if new_start and target are both internal nodes
            else{
                previous = target -> getPrevious();
                next = target -> getNext();

                previous -> set_next(next);
                next -> set_previous(previous);

                target -> set_next(new_start);
                target -> set_previous(new_start -> getPrevious());
                new_start -> getPrevious() -> set_next(target); 
                new_start -> set_previous(target);
            }
            new_start = new_start -> getNext();
            current = new_start;
        }
    }
}// all pointing to null? SCOPE!
