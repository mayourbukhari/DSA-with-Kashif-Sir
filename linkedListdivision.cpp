// Problem: Split linked List into two sub linked list even and odd. 
// create a linked list having elements 6,10,13,18,9,24,10
// then divide it into two sub linked list one odd and another with even elements.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* oddHead;
    Node* evenHead;
    
public:
    LinkedList() : head(nullptr), oddHead(nullptr), evenHead(nullptr) {}
    
    void createList() {
        int elements[] = {6, 10, 13, 18, 9, 24, 10};
        int n = sizeof(elements)/sizeof(elements[0]);
        
        for(int i = 0; i < n; i++) {
            Node* newNode = new Node(elements[i]);
            if(!head) {
                head = newNode;
            } else {
                Node* temp = head;
                while(temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }
    
    void splitList() {
        Node* current = head;
        
        while(current) {
            Node* newNode = new Node(current->data);
            
            if(current->data % 2 == 0) {  
                if(!evenHead) {
                    evenHead = newNode;
                } else {
                    Node* temp = evenHead;
                    while(temp->next) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            } else {  
                if(!oddHead) {
                    oddHead = newNode;
                } else {
                    Node* temp = oddHead;
                    while(temp->next) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            current = current->next;
        }
    }
    
    void display(string listName, Node* start) {
        cout << listName << ": ";
        Node* temp = start;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void displayAll() {
        display("Original List", head);
        display("Odd Elements", oddHead);
        display("Remaining Even Elements", evenHead);
    }
    
    ~LinkedList() {
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        while(oddHead) {
            Node* temp = oddHead;
            oddHead = oddHead->next;
            delete temp;
        }
        while(evenHead) {
            Node* temp = evenHead;
            evenHead = evenHead->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    
    list.createList();
    list.splitList();
    list.displayAll();
    
    return 0;
}