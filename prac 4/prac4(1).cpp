#include <iostream>
using namespace std;

int main() {
    int q[100], n = 0;

    // Insert at front
    q[n++] = 10;
    for (int i = n - 1; i > 0; i--)
        q[i] = q[i - 1];
    q[0] = 5;

    // Insert at end
    q[n++] = 20;

    // Insert 15 at position 2
    int pos = 2;
    if (pos >= 0 && pos <= n) {
        for (int i = n; i > pos; i--)
            q[i] = q[i - 1];
        q[pos] = 15;
        n++;
    }

    // Print queue
    cout << "Final Queue: ";
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";

    return 0;
}