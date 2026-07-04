#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, cont = 0;
    cin >> m;
    vector<int> vetor(m);
    for(int i = 0; i < m; i++){
        cin >> vetor[i];
    }
    for(int i = 1; i < m-1; i++){
        if(vetor[i-1] < vetor[i] && vetor[i] > vetor[i+1]) cont++;
    }
    cout << cont;
    return 0;
}
