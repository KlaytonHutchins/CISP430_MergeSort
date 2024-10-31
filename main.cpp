#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
        //Construct new node without value
        Node() {
                value = 0;
                next = nullptr;
        }
        //Construct new node with initial value
        Node(int initValue) {
                value = initValue;
                next = nullptr;
        }
        ~Node() {
                value = 0;
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

void split(Node* head, Node *&a, Node *&b) {
        Node* curr = head;
        int origSize = 0;          // for counting the size of list starting at head variable
        while (curr) {             // loop through list starting at head variable
                origSize++;
                curr = curr->getNext(); 
        }
        curr = head;               // reset curr back to the head of the original list
        a = head;                  // a starts at the head of the original list
                                   // calculate the size of new list a
        int aSize = ( origSize / 2) + (origSize % 2) - 1;
                                   // loop to the end of list a
        for (int i = 0; i < aSize; i++) {
                curr = curr->getNext();
        }
        b = curr->getNext();       // b starts after the middle point of the original list
        curr->setNext(nullptr);    // set the end of list a with a null pointer
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
        }                          // if-else statement above sets the head of the list that
                                   // will be returned, and increments the pointer in the
                                   // list it came from
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
        }                          // first while loop is for comparison while nodes still
                                   // exist in both lists (a & b)
        while (currA) {
                currResult->setNext(currA);
                currA = currA->getNext();
                currResult = currResult->getNext();
        }
        while (currB) {  
                currResult->setNext(currB);
                currB = currB->getNext();
                currResult = currResult->getNext(); 
        }                          // second and third while loops clean up any existing
                                   // nodes, only one (or neither) of these two will execute
                                   // for any given call to the function
        return resultHead;
}

Node* mergeSort(Node* head) {  
        Node* a;
        Node* b;
        Node* c;
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

int main() {
        Node* head = nullptr;
        Node* curr = nullptr;
        int numIn;
        cout << "Enter numbers: ";
        while (cin >> numIn) {
                Node* newNode = new Node;
                newNode->setValue(numIn);
                newNode->setNext(nullptr);
                if (!head) {
                        head = newNode;
                } else {
                        curr->setNext(newNode);
                }
                curr = newNode;
                while (cin.peek() == ' ') {
                        cin.get();
                }
                if (cin.peek() == '\n') {
                        break;
                }
        }

        print(head);
        Node* res = mergeSort(head);
        print(res);
}
