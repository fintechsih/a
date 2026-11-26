
#include <bits/stdc++.h>
using namespace std;

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int a=A[0][0], b=A[0][1];
    int c=A[1][0], d=A[1][1];

    int e=B[0][0], f=B[0][1];
    int g=B[1][0], h=B[1][1];

    // 7 multiplications
    int m1 = (a+d)*(e+h);
    int m2 = (c+d)*e;
    int m3 = a*(f-h);
    int m4 = d*(g-e);
    int m5 = (a+b)*h;
    int m6 = (c-a)*(e+f);
    int m7 = (b-d)*(g+h);

    // Calculate result
    C[0][0] = m1+m4-m5+m7;
    C[0][1] = m3+m5;
    C[1][0] = m2+m4;
    C[1][1] = m1-m2+m3+m6;
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter matrix A:\n";
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            cin >> A[i][j];

    cout << "Enter matrix B:\n";
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            cin >> B[i][j];

    strassen(A, B, C);

    cout << "Result:\n";
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
