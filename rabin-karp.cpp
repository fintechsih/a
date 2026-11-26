
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pat;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pat;

    int n = text.size();
    int m = pat.size();

    if(m > n) {
        cout << "Pattern not found";
        return 0;
    }

    int B = 256, MOD = 1000000007;

    int h = 1;

    // Calculate h
    for(int i = 0; i < m-1; i++)
        h = (h * B) % MOD;

    int pHash = 0, tHash = 0;

    // Calculate pattern and text hash
    for(int i = 0; i < m; i++) {
        pHash = (pHash * B + pat[i]) % MOD;
        tHash = (tHash * B + text[i]) % MOD;
    }

    int found = 0;

    // Check each window
    for(int i = 0; i <= n-m; i++) {

        if(pHash == tHash && text.substr(i, m) == pat) {
            cout << "Pattern found at index " << i << endl;
            found = 1;
        }

        // Calculate next window hash
        if(i < n-m) {
            tHash = (tHash - text[i]*h % MOD + MOD) % MOD;
            tHash = (tHash * B + text[i+m]) % MOD;
        }
    }

    if(!found)
        cout << "Pattern not found";

    return 0;
}
