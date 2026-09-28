#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// Add song at beginning
void addFront(string s) {
    Node* newNode = new Node{s, NULL, head};

    if (head == NULL)
        head = tail = newNode;
    else {
        head->prev = newNode;
        head = newNode;
    }
}

// Add song at end
void addEnd(string s) {
    Node* newNode = new Node{s, tail, NULL};

    if (tail == NULL)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert after a specific song
void insertAfter(string key, string s) {
    Node* temp = head;

    while (temp != NULL && temp->song != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Song not found\n";
        return;
    }

    Node* newNode = new Node{s, temp, temp->next};

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

// Remove first song
void removeFirst() {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    delete temp;
}

// Count songs
int countSongs() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Display playlist
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->song << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    addFront("Song1");
    display();

    addEnd("Song3");
    display();

    insertAfter("Song1", "Song2");
    display();

    removeFirst();
    display();

    cout << "Total songs: " << countSongs() << endl;

    return 0;
}