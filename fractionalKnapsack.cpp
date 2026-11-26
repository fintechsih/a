
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], profit[n];
    float ratio[n];

    cout << "Enter weights and profits:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> profit[i];
        ratio[i] = (float)profit[i] / wt[i];
    }

    cout << "Enter capacity: ";
    cin >> W;

    // Sort by profit/weight ratio (descending)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(wt[i], wt[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    float total = 0;

    for (int i = 0; i < n; i++) {
        if (wt[i] <= W) {
            total += profit[i];
            W -= wt[i];
        }
        else {
            total += ratio[i] * W;
            W = 0;
            break;
        }
    }

    cout << "Maximum profit = " << total;

    return 0;
}
