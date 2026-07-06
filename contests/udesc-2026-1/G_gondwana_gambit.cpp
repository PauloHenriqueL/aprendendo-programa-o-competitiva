
#include <bits/stdc++.h>
using namespace std;

long long mdc(long long a, long long b){
  if(b == 0) return a;
  return mdc(b, a % b);
}


int main() {
  long long a;
  cin >> a;
  cout << (100 / mdc(a, 100));


  return 0;
}
