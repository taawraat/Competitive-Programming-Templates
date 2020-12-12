#include <bits/stdc++.h>

using    ll = long long;
using    namespace std;

// returns nCr
ll nCr(int n, int r) {
    if(r > n - r) r = n - r;
    ll ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

// returns nPr
ll nPr(int n, int r){
    ll ans = 1;

    for(int i = (n-r)+1; i <= n; i++)
        ans *= i;

    return ans;
}

// driver function
int main(){
  // start
  
}
