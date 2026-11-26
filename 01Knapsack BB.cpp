
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, profit;
};

struct Node {
    int level, weight, profit;
    double bound;
};

// Highest bound gets priority
struct Compare {
    bool operator()(Node a, Node b) {
        return a.bound < b.bound;
    }
};

// Calculate upper bound
double bound(Node u, int n, int W, vector<Item>& a) {
    if(u.weight > W)
        return 0;

    double ans = u.profit;
    int w = u.weight;
    int i = u.level + 1;

    // Take complete items
    while(i < n && w + a[i].weight <= W) {
        w += a[i].weight;
        ans += a[i].profit;
        i++;
    }

    // Take fraction of next item
    if(i < n)
        ans += (W-w) * (double)a[i].profit / a[i].weight;

    return ans;
}

int knapsack(int W, vector<Item>& a) {
    int n = a.size();

    // Sort by profit/weight ratio
    sort(a.begin(), a.end(), [](Item x, Item y) {
        return (double)x.profit/x.weight >
               (double)y.profit/y.weight;
    });

    priority_queue<Node, vector<Node>, Compare> pq;

    Node u = {-1, 0, 0, 0};
    u.bound = bound(u, n, W, a);
    pq.push(u);

    int maxProfit = 0;

    while(!pq.empty()) {
        u = pq.top();
        pq.pop();

        if(u.bound <= maxProfit)
            continue;

        if(u.level == n-1)
            continue;

        Node v;
        v.level = u.level + 1;

        // TAKE item
        v.weight = u.weight + a[v.level].weight;
        v.profit = u.profit + a[v.level].profit;

        if(v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, a);

        if(v.bound > maxProfit)
            pq.push(v);

        // SKIP item
        v.weight = u.weight;
        v.profit = u.profit;

        v.bound = bound(v, n, W, a);

        if(v.bound > maxProfit)
            pq.push(v);
    }

    return maxProfit;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity: ";
    cin >> W;

    vector<Item> a(n);

    cout << "Enter weight and profit:\n";

    for(int i = 0; i < n; i++)
        cin >> a[i].weight >> a[i].profit;

    cout << "Maximum profit = " << knapsack(W, a);

    return 0;
}
