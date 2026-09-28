#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insert(int x) {
    Node* newNode = new Node{x, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete a student
void remove(int x) {
    if (head == NULL)
        return;

    Node* temp = head;
    Node* prev = NULL;

    // If only one student
    if (head->data == x && head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    // Delete head
    if (head->data == x) {
        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    // Delete other node
    prev = head;
    temp = head->next;

    while (temp != head && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != head) {
        prev->next = temp->next;
        delete temp;
    }
}

// Display circle
void display() {
    if (head == NULL)
        return;

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    display();

    remove(2);
    display();

    insert(4);
    display();

    return 0;
}