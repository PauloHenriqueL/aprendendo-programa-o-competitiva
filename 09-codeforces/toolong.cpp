#include <bits/stdc++.h>
using namespace std;







int main(){
    int n; cin >> n;
    string palavra;
    map<string, int> resultado;
    for(int i = 0; i < n; i++){
        cin >> palavra;
        resultado[palavra];
    }
    for(auto& par : resultado){
        if(par.first.size() > 10){
            par.second = par.first.size() -2;
        
        }

    }
}
