#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
        //Construct new node with a name
        Node(int initValue) {
                value = initValue;
                next = nullptr;
        }
        //Getters and Setters
        void setValue(int v) {
                value = v;
        }
        int getValue() {
                return value;
        }
        void setNext(Node* n) {
                next = n;
        }
        Node* getNext() {
                return next;
        }
private:
        int value;
        Node* next;
};

class LinkedList {
public:
        //Construct new empty Doubly Linked List
        LinkedList() {
                head = nullptr;
        }
        //Destructor
        ~LinkedList() {
                Node* curr = head;
                while (curr) {
                        Node* tempNext = curr->getNext();
                        delete curr;
                        curr = tempNext;
                }
        }
        //Insert at front of list
        void insertFront(int valueToInsert) {
                Node* newNode = new Node(valueToInsert);
                if (head) {  //not empty list
                        newNode->setNext(head);
                }
                head = newNode;
        }
        //Insert at back of list        
        void insertBack(int valueToInsert) {
                Node* newNode = new Node(valueToInsert);
                if (head) {  //not empty list
                        Node* curr = head;
                        while (curr->getNext()) {
                                curr = curr->getNext();
                        }
                        curr->setNext(newNode);
                } else {  //empty list
                        head = newNode;
                }
        }
        //Delete function
        void deleteNode(int valueToDelete) {
                Node* curr = head;
                while (curr && curr->getNext()) {
                        Node* nextNode = curr->getNext();
                        if (nextNode->getValue() == valueToDelete) {
                                curr->setNext(nextNode->getNext());
                                delete nextNode;
                                break;  //comment out if expecting duplicates and want to delete all instances
                        }
                        curr = nextNode;
                }
        }
        //Getters and Setters
        void setHead(Node* h) {
                head = h;
        }
        Node* getHead() {
                return head;  
        }
        void print() {
                Node* curr = head;
                while (curr) {
                        cout << curr->getValue() << " ";
                        curr = curr->getNext();
                }
                cout << endl;
        }
        void split(Node* head, Node*& a, Node*& b) {
                //
        }

        Node* merge(Node* a, Node* b) {
                //for (int i = 0; i < xxx; i++) {}
                return head; //placeholder to compile
        }

        Node* mergeSort(Node* head) {
                //for (int i = 0; i < xxx; i++) {}
                return head; //placeholder to compile
        }
private:
        Node* head;
};

int main() {
        int arr[9] = {32, 4, 17, 3, 21, 2, 19, 29, 25};
        LinkedList myList;
        for (int i = 0; i < 9; i++) {
                myList.insertBack(arr[i]);
        }
        myList.print();
}
