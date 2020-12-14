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

ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

// returns how many numbers are divisible by Sn from 1 to range
ll divisibilityOfSet(ll range, ll set[], int elements){

    // subsets = (2^elements) - 1
    ll subSets = (1<<elements);
    ll ans = 0;

    // loop from 1 to subsets
    for(int i = 1; i < subSets; i++){
        ll devide = 1;
        ll bitSets = __builtin_popcount(i);

        // searching setbit positions
        for(int j = 0; j < elements; j++){
            if(i & (1<<j))
                devide = LCM(devide, set[j]);
        }

        // if number of elements is odd then add to ans
        if(bitSets & 1)
            ans = ans + (range/devide);

        // if number of elements is even then subtract from ans
        else
            ans = ans - (range/devide);
    }
    
    return ans;
}

// driver function
int main(){
  // start
  
}
