#include <bits/stdc++.h>
using namespace std;

class List
{
    struct Node
    {
        struct Node* next;
        int data;
    };

    struct Node* head;
    struct Node* tail;
    unsigned int size;

public:
    List() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void add(int value);
    void print();
    unsigned int length();
    int shift();
    int remove();
};

void List::add(int value) {
    struct Node* temp = new Node;    
    temp->data = value;
    temp->next = NULL;

    if (head == NULL){
        tail = temp;
        head = temp;
        size++;
    }
    else {
        tail->next = temp;
        tail = temp;
        size++;
    }

    temp = NULL;
    delete temp;
}

void List::print() {
    if (head == NULL)
        cout << "Empty list";
    else {
        struct Node* temp = new Node;
        temp = head;

        while(temp->next != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << temp->data << endl;
    }
}

unsigned int List::length() {
    return size;
}

int List::shift() {
    struct Node* temp = new Node;
    temp = head;
    head = head->next;
    size--;
    temp->next = NULL;
    return temp->data;
}

int List::remove() {
    struct Node* temp = head;

    if(temp == tail) {
        int res = temp->data;
        temp = NULL;
        return res;
    }

    while(temp->next != tail) {
        temp = temp->next;
    }
    size--;
    temp->next = NULL; 
    return temp->data;
}

int main(int argc, char const *argv[])
{
    List l;
    l.add(60);
    l.add(40);
    l.add(30);
    l.add(60);
    l.add(40);
    l.add(30);
    l.print();
    cout << l.length() << endl;
    l.shift();
    l.print();
    cout << l.length() << endl;
    l.remove();
    l.print();
    cout << l.length() << endl;
    return 0;
}
