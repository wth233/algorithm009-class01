#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next; // "type_name" + "*" + "variable_name"
};

void print_fuc(Node* p){
    while(p != nullptr){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

/*********
 * Insert operation
 * *******/

// insert node on the front of list
void push_front(Node** head_ref, int new_data){
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = *head_ref;

    *head_ref = new_node;
}

// insert node after given prev_node
void insert_after(Node* prev, int new_data){

    if(prev == nullptr){
        cout<<"the given previous node cannot be NULL"<<endl;
    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev->next;

    prev->next = new_node;

}

void append(Node** head_ref, int new_data){

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = nullptr;

    if(*head_ref == nullptr){
        *head_ref = new_node;
        return;
    }

    Node* last_node = *head_ref;

    while(last_node->next != nullptr){
        last_node = last_node->next;
    }

    last_node->next = new_node;

}

/*********
 * Delete operation
 * *******/

//Delete node based on value
void delete_node(Node** head_ref, int delete_data){
    Node* temp = *head_ref;
    Node* prev;

    if(temp != nullptr && temp->data == delete_data){
        delete temp;
        *head_ref = temp->next;
        return;
    }

    while(temp != nullptr && temp->data != delete_data){
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    prev->next = temp->next;

    delete temp;
}

int main() {

    Node* p1 = new Node();
    Node* p2 = new Node();
    Node* p3 = new Node();
    p1->next = p2;
    p1->data = 1;
    p2->next = p3;
    p2->data = 2;
    p3->next = nullptr;
    p3->data = 3;

    print_fuc(p1);

    push_front(&p1, 0);

    print_fuc(p1);

    insert_after(p2, 0);

    print_fuc(p1);

    append(&p1, 4);

    print_fuc(p1);

    delete_node(&p1, 4);

    print_fuc(p1);

    return 0;
}
