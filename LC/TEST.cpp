#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (a != 0) {
        int temp = b % a;
        b = a;
        a = temp;
    }
    return b;
}

int main() {
    cout << "Hello World!666\n";
    int a, b;
    cin >> a >> b;
    cout<<gcd(a,b);
}

