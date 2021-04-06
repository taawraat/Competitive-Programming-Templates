#include   <bits/stdc++.h>
#define    pf printf
#define    sc scanf
#define    nline cout << '\n'
#define    dbg(x) \
           cout << "debug " << #x << ": " << x << '\n';
#define    inp(t) cin >> (t)
#define    out(t) cout << (t)
#define    lastof(s) s.size() - 1
#define    all(x) x.begin(), x.end()
#define    FOR(n, x) for (ll i = n; i < x; i++)
#define    FOR2(N, X) for (int j = N; j < X; j++)
#define    pb push_back
#define    mp make_pair
#define    EPS 0.0001

typedef    unsigned long long ull;
typedef    long long ll;
using      namespace std;

void OJ(){
// file I/O
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool descFun(ll i, ll j) { return (i > j); }

ll LCM(ll x, ll y) { return x * (y / __gcd(x, y)); }

ll sum(ll n) { return (n * (n + 1)) / 2; } 

ll logAB(ll a, ll b) { return log(a) / log(b); }

ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }

ll chartoint(char ch) { return ch - '0'; }

bool coPrime(ll a, ll b){ return __gcd(a,b) == 1; }

void solve(){
    

}

void TC(){
    int x;
    inp(x);
    int i = 0;
    while (x--){
        out("Case ") << ++i << ": ";
        solve();
        nline;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // OJ();

    // Start
    TC();
    // solve();
    
}
