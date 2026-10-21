#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, element;
    vector<int> numbers;

    cout << "Enter number of elements (N): ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        numbers.push_back(element);
    }

    cout << "\nUnsorted Vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Sorting vector in ascending order
    sort(numbers.begin(), numbers.end());

    cout << "Sorted Vector  : ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
