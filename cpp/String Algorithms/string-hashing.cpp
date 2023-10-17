class Hash{
    // Possible TLE verdict for using so many long long data types
    // beaware of overflowing
    using ll = long long;
public:
    vector<int> power;
    vector<int> inv;
    vector<int> hash;
    
    int n;
    int mod; string s; int base;

    int chartoint(char ch){ return (ch - 'a') + 1; }; // control this function if needed, small letter characters

    int bigMod(ll a, int b){ int ans = 1; a = a % mod; while(b){ if(b & 1) ans = (ans * a) % mod; a = (a*a) % mod; b /= 2; } return ans; }
    
    int MOD(int num){ return ((num + mod)%mod); }

    int modAdd(int a, int b){ return (a+b) % mod; }

    int modSub(int a, int b){ return MOD(a - b); }

    int modMul(ll a, int b){ return (a * b) % mod; }
    
    int modDiv(int a, int b){ return modMul(a, inv[b]); }

    void precal_powers(){
        power = vector<int>(n+5);
        inv = vector<int>(n+5);
        power[0] = inv[0] = 1;

        for(int i = 1; i <= n; i++){
            power[i] = modMul(power[i-1], base);
        }
        int pw_inv = bigMod(base, mod-2);
        for(int i = 1; i <= n; i++){
            inv[i] = modMul(inv[i-1], pw_inv);
        }
    }

    void build_hash(){
        int sz = s.size();
        hash = vector<int>(sz+5);

        for(int i = 1; i <= sz; i++){
            hash[i] = modAdd(hash[i-1], modMul(power[i-1], chartoint(s[i-1]))); // this will reverse hash the string
                                                                                // EX: 1234 will be 4321 if base is 10
                                                                                // for non-reversed, formula is (presum * base) + character
        }
    }

    ll getHash(int l, int r){ // query is 1 based
        if(l > r) return -1;
        return modMul(modSub(hash[r], hash[l-1]), inv[l-1]);
    }

    Hash(string &s, int base = 29, int mod = 1e9+7){
        this->s = s;
        this->base = base;
        this->mod = mod;
        n = s.size()+5;

        precal_powers();
        build_hash();
    }
};
