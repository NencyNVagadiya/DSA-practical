#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    int q[100];
    int front = -1, rear = -1;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    while (operations--) {
        string op;
        cout << "Enter operation (join/serve): ";
        cin >> op;

        if (op == "join") {
            int token;
            cout << "Enter token number: ";
            cin >> token;

            if ((rear + 1) % n == front) {
                cout << "Error: Queue is full" << endl;
            } else {
                if (front == -1)
                    front = 0;

                rear = (rear + 1) % n;
                q[rear] = token;

                cout << "Front token: " << q[front] << endl;
            }
        }
        else if (op == "serve") {
            if (front == -1) {
                cout << "Error: Queue is empty" << endl;
            } else {
                cout << "Served token: " << q[front] << endl;

                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % n;
                }

                if (front != -1)
                    cout << "Front token: " << q[front] << endl;
                else
                    cout << "Queue is empty" << endl;
            }
        }
    }

    return 0;
}
