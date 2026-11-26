#include <iostream>
#include <vector>
using namespace std;

int n, target;
int arr[20];
vector<int> subset;

void sumOfSubset(int index, int currentSum) {
    // Found a valid subset
    if (currentSum == target) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
        return;
    }

    // Stop if we are out of elements or sum exceeded (works for positive numbers)
    if (index == n || currentSum > target) return;

    // Choice 1: include arr[index]
    subset.push_back(arr[index]);
    sumOfSubset(index + 1, currentSum + arr[index]);

    // Backtrack: remove it
    subset.pop_back();

    // Choice 2: exclude arr[index]
    sumOfSubset(index + 1, currentSum);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    cout << "Subsets with sum " << target << ":\n";
    sumOfSubset(0, 0);

    return 0;
}
