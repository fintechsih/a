
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pat;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pat;

    int n = text.length();
    int m = pat.length();

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pat[j])
                break;
        }

        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }

    return 0;
}
