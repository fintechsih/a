
#include <bits/stdc++.h>
using namespace std;

#define INF 999999

struct Node {
    vector<vector<int>> mat;
    vector<int> path;
    int cost, level;
};

struct Compare {
    bool operator()(Node a, Node b) {
        return a.cost > b.cost;
    }
};

// Reduce rows and columns
int reduce(vector<vector<int>>& a) {
    int n = a.size(), total = 0;

    // Row reduction
    for(int i = 0; i < n; i++) {
        int mn = *min_element(a[i].begin(), a[i].end());

        if(mn != INF && mn > 0) {
            total += mn;
            for(int j = 0; j < n; j++)
                if(a[i][j] != INF)
                    a[i][j] -= mn;
        }
    }

    // Column reduction
    for(int j = 0; j < n; j++) {
        int mn = INF;

        for(int i = 0; i < n; i++)
            mn = min(mn, a[i][j]);

        if(mn != INF && mn > 0) {
            total += mn;
            for(int i = 0; i < n; i++)
                if(a[i][j] != INF)
                    a[i][j] -= mn;
        }
    }

    return total;
}

int tsp(vector<vector<int>> cost) {
    int n = cost.size();

    priority_queue<Node, vector<Node>, Compare> pq;

    Node root;
    root.mat = cost;
    root.path = {0};
    root.level = 0;
    root.cost = reduce(root.mat);

    pq.push(root);

    while(!pq.empty()) {
        Node u = pq.top();
        pq.pop();

        int i = u.path.back();

        // All cities visited
        if(u.level == n-1) {
            cout << "Path: ";
            for(int x : u.path)
                cout << x << " ";
            cout << 0 << endl;

            return u.cost;
        }

        // Try visiting every city
        for(int j = 0; j < n; j++) {

            if(u.mat[i][j] == INF)
                continue;

            Node v;
            v.mat = u.mat;
            v.path = u.path;
            v.path.push_back(j);
            v.level = u.level + 1;

            // Block current row and column
            for(int k = 0; k < n; k++) {
                v.mat[i][k] = INF;
                v.mat[k][j] = INF;
            }

            // Avoid returning to start early
            if(v.level < n-1)
                v.mat[j][0] = INF;

            v.cost = u.cost + u.mat[i][j]
                     + reduce(v.mat);

            pq.push(v);
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];

            if(i == j)
                cost[i][j] = INF;
        }
    }

    int ans = tsp(cost);

    cout << "Minimum cost: " << ans << endl;

    return 0;
}
