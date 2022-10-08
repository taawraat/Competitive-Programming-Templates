#include   <bits/stdc++.h>

#define    nline        cout << '\n'
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    rall(x)      x.rbegin(), x.rend()
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-5
#define    pdd          pair<double,double>

typedef    unsigned     long long ull;
typedef    long long    ll;
using      namespace    std;

void OJ(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w+", stdout);
    #endif
}
    
#ifndef ONLINE_JUDGE

auto debug(){ return cout << endl,0; }
template<typename Arg,typename... Args>
auto debug(Arg elem,Args... elems){
    cout << "debugging: " << elem << ' ';
    // cout << endl;
    return debug(elems...);
}

template<typename T>
void printVec(T& v){
    cout << "container : [ ";
    for(auto &it: v) cout << it << ' ';
    cout << "]\n";
}
    
#endif
    
const ll mod = 1000000000 + 7;
// const ll maxN = 150000+10;
    
ll bigMod(ll a, ll b, ll m){
    ll ans = 1;
    a = a % m;
    
    while(b){
        if(b & 1)
            ans = (ans * a) % m;
        
        a = (a*a) % m;
        b /= 2;
    }
    return ans;
}
    
ll MOD(ll num){ return ((num%mod + mod)%mod); }

ll MOD(ll num, ll mod){ return ((num%mod + mod)%mod); }

ll modAdd(ll a, ll b){ return MOD(MOD(a) + MOD(b)); }

ll modSub(ll a, ll b){ return MOD(MOD(a) - MOD(b)); }

ll modMul(ll a, ll b){ return MOD(MOD(a) * MOD(b)); }
    
ll modDiv(ll a, ll b){ return modMul(a, bigMod(b,mod-2, mod)); }
    
ll Lcm(ll x, ll y) { return x * y / __gcd(x, y); }
    
ll Sum(ll n) { return (n * (n + 1)) / 2; }

ll totalDigits(ll n){ return floor(log10(n)) + 1; };

ll logAB(ll a, ll b) { return log(a) / log(b); }
    
ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }
    
ll ceilNegAB(ll a, ll b) { return (a - b + 1) / b; }
    
ll chartoint(char ch) { return ch - '0'; }

bool isPowerOfTwo(ll n) { return n > 0 && !(n&(n-1)); }

bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }
    
bool isEqual(double a, double b) { return abs(a-b) < EPS; }
    
bool isGreater(double a, double b) { return a >= b + EPS; }
    
bool isGreaterEqual(double a, double b) { return a > b - EPS; }

class MatrixExpo{
public:
    int MAX_N;
    vector<vector<int>> ans;

    vector<vector<int>> matMul(vector<vector<int>>& a, vector<vector<int>>& b){
        vector<vector<int>> res(MAX_N, vector<int>(MAX_N));
        int i, j, k;

        for(i = 0; i < MAX_N; i++){
            for(j = 0; j < MAX_N; j++){
                res[i][j] = 0;
                for(k = 0; k < MAX_N; k++){
                    res[i][j] = res[i][j] + (a[i][k] * b[k][j]); // apply modulo arithmetic if needed
                }
            }
        }

        return res;
    }

    void matPow(vector<vector<int>>& base, long long power){
        while(power){
            if(power&1) ans = matMul(ans, base);
            base = matMul(base, base);
            power >>= 1;
        }
    }

    MatrixExpo(vector<vector<int>> base,long long power, int size){
        MAX_N = size;
        ans = vector<vector<int>>(MAX_N, vector<int>(MAX_N));

        for(int i = 0; i < MAX_N; i++){
            for(int j = 0; j < MAX_N; j++){
                ans[i][j] = (i == j);
            }
        }

        matPow(base, power);
    }
};

vector<vector<int>> makeBase(vector<int>& v){
    int sz = v.size();
    vector<vector<int>> rest(sz, vector<int>(sz));

    for(ll i = 0; i < sz; i++){
        rest[0][i] = v[i];
    }
    for(ll i = 1; i < sz; i++){
        for(ll j = 0; j < sz; j++){
            rest[i][j] = (i == (j+1));
        }
    }

    /*
        Example for fibonacci f(n) = f(n-1) + f(n-2)
                1 1
                1 0
        first row = coefficients
        from second row
                10000
                01000
                00100
                00010
                .....
                .....
                .....
    */ 

    return rest;
}

void solve(){
    ll n; cin >> n;

    if(n == 0){
        cout << 0;
        return;
    }
    if(n == 1){
        cout << 1;
        return;
    }

    vector<int> v = {1, 1};
    vector<vector<int>> base = makeBase(v);

    MatrixExpo mat(base, n, 2);

    cout << mat.ans[0][1];
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    
    while(t--){
        // cout << "Case " << ++Case << ": ";
        solve();
        nline;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    OJ();
    
    // Start
    TC();
}
