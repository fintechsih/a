#include <bits/stdc++.h>
using namespace std;

int main() {
    string captcha = "";
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    srand(time(0));

    for (int i = 0; i < 6; i++) {
        captcha += chars[rand() % chars.length()];
    }

    cout << "Generated CAPTCHA: " << captcha << endl;

    string user;
    cout << "Enter CAPTCHA: ";
    cin >> user;

    if (user == captcha)
        cout << "Verification Successful!";
    else
        cout << "Invalid CAPTCHA!";

    return 0;
}
