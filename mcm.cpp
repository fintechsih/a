
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[100];

    cout << "Enter dimensions:\n";
    for(int i = 0; i <= n; i++)
        cin >> p[i];

    int dp[100][100] = {0};

    // Chain length
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i <= n-len+1; i++) {
            int j = i+len-1;
            dp[i][j] = INT_MAX;

            // Try every split
            for(int k = i; k < j; k++) {

                int cost = dp[i][k] +
                           dp[k+1][j] +
                           p[i-1]*p[k]*p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum multiplications = " << dp[1][n];

    return 0;
}
