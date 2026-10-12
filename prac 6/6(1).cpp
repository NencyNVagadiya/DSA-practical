#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the maximum size of stack: ";
    cin >> n;

    int stack[100];
    int top = -1;

    int operations;
    cout<<"enter how many operation you want.";
    cin >> operations;

    while (operations--) {
        string operation;
         cout << "Enter operation (push/pop): ";
        cin >> operation;

        if (operation == "push") {
            int tray;
            cout << "Enter tray number: ";
            cin >> tray;

            // Check if stack is full
            if (top == n - 1) {
                cout << "Error: Stack is full" << endl;
            } else {
                top++;
                stack[top] = tray;

                cout << "Top: " << stack[top] << endl;
            }
        }
        else if (operation == "pop") {

            // Check if stack is empty
            if (top == -1) {
                cout << "Error: Stack is empty" << endl;
            } else {
                top--;

                if (top == -1)
                    cout << "Stack is empty" << endl;
                else
                    cout << "Top: " << stack[top] << endl;
            }
        }
    }

    return 0;
}
