
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

    int last[256];

    // Initialize all positions to -1
    for(int i = 0; i < 256; i++)
        last[i] = -1;

    // Store last occurrence
    for(int i = 0; i < m; i++)
        last[(unsigned char)pat[i]] = i;

    int s = 0, found = 0;

    while(s <= n-m) {
        int j = m-1;

        // Compare from right to left
        while(j >= 0 && pat[j] == text[s+j])
            j--;

        if(j < 0) {
            cout << "Pattern found at index " << s << endl;
            found = 1;
            s++;
        }
        else {
            s += max(1, j-last[(unsigned char)text[s+j]]);
        }
    }

    if(!found)
        cout << "Pattern not found";

    return 0;
}
