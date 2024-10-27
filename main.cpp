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

int main() {
        int arr[10] = {32, 4, 17, 3, 21, 2, 19, 29, 25, 6};
        Node* head = new Node(arr[0]);
        Node* curr = head;
        for (int i = 1; i < 10; i++) {
                curr->setNext(new Node(arr[i]));
                curr = curr->getNext();
        }
        print(head);
        Node* res = mergeSort(head);
        print(res);
}
