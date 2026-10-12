#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int operations;

    cout << "Enter number of operations: ";
    cin >> operations;

    while (operations--) {
        string op;

        cout << "Enter operation (arrive/attend): ";
        cin >> op;

        if (op == "arrive") {
            int patient;

            cout << "Enter patient number: ";
            cin >> patient;

            q.push(patient);

            cout << "Front patient: " << q.front() << endl;
        }
        else if (op == "attend") {
            if (q.empty()) {
                cout << "Error: No patients waiting" << endl;
            }
            else {
                cout << "Attended patient: " << q.front() << endl;
                q.pop();

                if (!q.empty())
                    cout << "Front patient: " << q.front() << endl;
                else
                    cout << "No patients waiting" << endl;
            }
        }
    }

    return 0;
}
