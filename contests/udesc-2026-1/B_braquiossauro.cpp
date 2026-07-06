#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, a, b;
    cin >> h >> a >> b;
    if(a <= h && h <= b){
        cout << "SIM\n";
    } else {
        cout << "NAO\n";
    }

    return 0;
}
