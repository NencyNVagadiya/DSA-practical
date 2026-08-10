#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    // Effective rotations
    int k = h % n;

    cout << "Final display order: ";

    // Print from k to end
    for (int i = k; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Print from beginning to k-1
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}