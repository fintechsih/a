
#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high) {
    int r = low + rand() % (high - low + 1);
    swap(a[r], a[high]);

    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    srand(time(0));

    int a[] = {8, 3, 1, 7, 0, 10, 2};
    int n = 7;

    quickSort(a, 0, n - 1);

    for (int x : a)
        cout << x << " ";

    return 0;
}
