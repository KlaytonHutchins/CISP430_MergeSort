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
        void split(Node* head, Node *&a, Node *&b) {
                Node* curr = head;
                int origSize = 0;
                while (curr) {
                        origSize++;
                        curr = curr->getNext();
                }
                curr = head; // reset curr back to the head of the original list
                a = head; // a starts at the head of the original list
                int aSize = ( origSize / 2) + (origSize % 2) - 1; // calculate the size of new list a
                for (int i = 0; i < aSize; i++) { // loop to the end of list a
                        curr = curr->getNext();
                }
                b = curr->getNext(); // b starts after the middle point of the original list
                curr->setNext(nullptr); // set the end of list a with a null pointer
                cout << "list size: " << origSize << endl;
        }

        Node* merge(Node* a, Node* b) {
                Node* resultHead;
                Node* currA = a;
                Node* currB = b;
                if (currA->getValue() < currB->getValue()) {
                        resultHead = currA;
                        currA = currA->getNext();
                } else {
                        resultHead = currB;
                        currB = currB->getNext();
                }
                Node* currResult = resultHead;
                while (currA && currB) {
                        if (currA->getValue() < currB->getValue()) {
                                currResult->setNext(currA);
                                currA = currA->getNext();  
                        } else {
                                currResult->setNext(currB);
                                currB = currB->getNext();
                        }
                        currResult = currResult->getNext();
                }
                while (currA) {
                        currResult->setNext(currA);
                        currA = currA->getNext();
                        currResult = currResult->getNext();
                }
                while (currB) {
                        currResult->setNext(currB);
                        currB = currB->getNext();
                        currResult = currResult->getNext();
                }
                return resultHead;
        }

        Node* mergeSort(Node* head) {
                Node* a;
                Node* b;
                Node* c;
                //for (int i = 0; i < xxx; i++) {}
                if(head == NULL)
                        return NULL;
                if (head->getNext() == NULL)
                        return head;
                split(head, a, b);
                a = mergeSort(a);
                b = mergeSort(b);
                c = merge(a, b);
                return c;
                //return head; //placeholder to compile
        }
private:
        Node* head;
};

// -------------------------------------------------------------------
void split(Node* head, Node *&a, Node *&b) {
        Node* curr = head;
        int origSize = 0;
        while (curr) {
                origSize++;
                curr = curr->getNext(); 
        }
        curr = head; // reset curr back to the head of the original list
        a = head; // a starts at the head of the original list
        int aSize = ( origSize / 2) + (origSize % 2) - 1; // calculate the size of new list a
        for (int i = 0; i < aSize; i++) { // loop to the end of list a
                curr = curr->getNext();
        }
        b = curr->getNext(); // b starts after the middle point of the original list
        curr->setNext(nullptr); // set the end of list a with a null pointer
}

Node* merge(Node* a, Node* b) {
        Node* resultHead; 
        Node* currA = a;
        Node* currB = b;
        if (currA->getValue() < currB->getValue()) {
                resultHead = currA;
                currA = currA->getNext();
        } else {
                resultHead = currB;
                currB = currB->getNext();
        }
        Node* currResult = resultHead;
        while (currA && currB) {
                if (currA->getValue() < currB->getValue()) {
                        currResult->setNext(currA);
                        currA = currA->getNext();
                } else {
                        currResult->setNext(currB);
                        currB = currB->getNext();
                }
                currResult = currResult->getNext();
        }
        while (currA) {
                currResult->setNext(currA);
                currA = currA->getNext();
                currResult = currResult->getNext();
        }
        while (currB) {  
                currResult->setNext(currB);
                currB = currB->getNext();
                currResult = currResult->getNext(); 
        }
        return resultHead;
}

Node* mergeSort(Node* head) {  
        Node* a;
        Node* b;
        Node* c;
        //for (int i = 0; i < xxx; i++) {}
        if(head == NULL)
                return NULL;   
        if (head->getNext() == NULL)
                return head;
        split(head, a, b);
        a = mergeSort(a);
        b = mergeSort(b);
        c = merge(a, b);
        return c;
}

void print(Node* head) {
        Node* curr = head;
        while (curr) {  
                cout << curr->getValue() << " ";
                curr = curr->getNext();
        }
        cout << endl;
}
// -------------------------------------------------------------------

int main() {
        int arr[10] = {32, 4, 17, 3, 21, 2, 19, 29, 25, 6};
        Node* head = new Node(arr[0]);
        Node* curr = head;
        for (int i = 1; i < 10; i++) {
                curr->setNext(new Node(arr[i]));
                curr = curr->getNext();
        }
        print(head);
//        LinkedList myList;
//        for (int i = 0; i < 10; i++) {
//                myList.insertBack(arr[i]);
//        }
//        myList.print();
        Node* res = mergeSort(head);
        print(res);
//        myList.setHead(res);
//        myList.print();
//        Node* a = new Node(0);
//        Node* b = new Node(0);
//        myList.split(myList.getHead(), a, b);
//        LinkedList lista;
//        LinkedList listb;
//        lista.setHead(a);
//        listb.setHead(b);
//        lista.print();
//        listb.print();
//        cout << "a: " << endl;
//        Node* curr = a;
//        while (curr) {
//                cout << curr->getValue() << " "; 
//                curr = curr->getNext();
//        }
//        cout << endl;
//        cout << "b: " << endl;
//        curr = b;
//        while (curr) {
//                cout << curr->getValue() << " ";
//                curr = curr->getNext();
//        }
//        cout << endl;
}
