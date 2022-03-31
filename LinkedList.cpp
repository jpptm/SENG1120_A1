#include "LinkedList.h"
#include <sstream>
// linked list constructor
LinkedList::LinkedList(){
    // set head, tail and current to null initially, 
    head = NULL;
    tail = NULL;
    current = NULL;
    list_length = 0;
}


// declare destructor
LinkedList::~LinkedList(){}

// pass value_type data by reference and add to the tail of our linked list
void LinkedList::addToTail(Node::value_type& data){

    // if list is initially emptyy
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
        //cout<<list_length<<endl;
        // current is initialised as head by default
        current = head;
        //cout<<current -> get_data().get_name()<< endl;
        //cout<< "past printing name" << endl;
        //cout<<"temp_current initialised" <<endl;

        while (current != NULL){
            //cout<<"inside while loop" <<endl;
            
            if((current->get_data()).get_name() == name_){
                //cout<<"target found"<<endl;

                // account for three scenarios - deleting head, deleting tail, and deleting within ll

                // account for removing head
                if(current -> get_previous() == NULL){
                    cout<<"Removing head"<<endl;
                    
                    head = current->getNext();
                    delete current;
                    current = head;

                    list_length--;
                    // show outputs
                    //cout<<"Head removed"<<endl;
                    //cout<<"New head" << head -> get_data().get_name()<<endl;
                    //cout<<"New head -> get next " << head -> get_next() -> get_data() .get_name()<<endl;
                }

                // if target node is our tail
                else if(current -> get_next() == NULL){
                    cout<<"removing tail"<<endl;
                    tail = current -> getPrevious();
                    tail -> set_next(NULL);
                    delete current;
                    current = tail;
                    list_length--;

                    //show outputs
                    //cout<<"tail removed"<<endl;
                    //cout << "New tail " << tail -> get_data().get_name()<<endl;
                    //cout<<"New tail -> get next " << tail -> get_next()->get_data().get_name()<<" "<< tail -> get_next()->get_data().get_score()<< endl; 
                    //cout<<"next to michelle 90" <<  tail -> get_next()->get_next()->get_data().get_name()<<endl;

                    //current = current -> getNext();
                }

                // if target node is within ll
                else{
                    // step back by 1 node so we dont have to traverse the list from the beginning again
                    Node* temp_current = current -> getPrevious();

                    cout<<"removing internal node"<<endl;
                    Node* previous_node = current -> getPrevious();
                    Node* next_node = current -> getNext();
                   
                    previous_node -> set_next(next_node);
                    next_node -> set_previous(previous_node);

                    delete current;
                    current = temp_current;
                    //cout<<"internal node removed"<<endl;
                    //show outputs
                    //cout<<"New current "<<current->get_data().get_name()<<endl;
                    //cout<<"current get next " << current -> get_next() -> get_data().get_name() << endl;
                    list_length--;
                }
            }
            // move on to the next node
            //cout<<"move on"<<endl;
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
    Node* temp_current = current;
    //cout<< "current initialised"<< endl;
    double total = 0;
    int max_score = current -> get_data().get_score();
    int min_score = current -> get_data().get_score();
    int current_score;
    //cout<<"variables declared"<<endl;
    //cout<<min_score << " " << max_score<< endl;

    while (temp_current != NULL){
        current_score = temp_current -> get_data().get_score();

        // find min and max at the same time (parallel)
        if(current_score < min_score){
            min_score = current_score;
        }

        if(current_score > max_score){
            max_score = current_score;
        }

        total += current_score;

        temp_current = temp_current -> getNext();
    }

    //cout<<"Total score "<<total<<endl;
    double average = total / list_length;
    cout<< "(" << min_score << " / " << average << " / " << max_score << ")" <<endl;

}

int LinkedList::get_list_length() const{
    return list_length;
}

// CONCATENATE
void LinkedList::operator +=(LinkedList& list_rhs){
    // link the first list's tail to the second list's head
    //(this -> tail) -> set_next(list.head);
    //list.head -> set_previous(this -> tail);

    // the head node should still be the head of the first list but the new tail node of the concatenated list
    // must be the tail of the second list
    //this -> tail = list.tail;
    //this -> current = this -> head;
    //this -> list_length += list.get_list_length();
    // SIMPLY DOING THE CODE ABOVE LINKS LIST 1 AND LIST 2
    // THAT IMPLIES THAT WHEN WE REACH "DELETE JOHN FROM LIST 2", SINCE LIST 1 IS LINKED TO LIST 2
    // THE JOHN FROM LIST 1 (WHICH IS ACTUALLY JUST LIST 2 JOHN) GETS DELETED AS WELL. THIS MESSES EVERYTHING UP
    // NAIVE: ALLOCATE NEW MEMORY (for a new nodes) AND MAKE DIFFERENT COPIES TO LINK TO LIST 1 INSTEAD OF JUST LINKING 1'S TAIL TO 2'S HEAD
    
    Node* temp_current = list_rhs.head;
    
    while (temp_current != NULL){
        Node::value_type object_data = temp_current -> get_data();
        this -> addToTail(object_data);
        temp_current = temp_current -> getNext();
    }
}

// function to use for overloading << operator
string LinkedList::LinkedList_to_string() const{

    Node* temp_current = current;
    string output, object_name, string_object_score;
    //stringstream ss;
    int object_score;

    while (temp_current != NULL){

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

    return output;
}

// overload << operator - should print (Object name ,object age)
ostream& operator <<(ostream& out, const LinkedList& list){
    // set node* variable so we can traverse our linked list
    out << list.LinkedList_to_string();
    return out;
}

// TEMPORARY DELETE LATER all below
Node* LinkedList::get_head() const{
    return head;
}
