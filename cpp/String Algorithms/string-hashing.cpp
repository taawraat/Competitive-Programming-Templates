class Hash{
    using ll = long long;
public:
    vector<ll> power;
    vector<ll> inv;
    vector<ll> hash;
    
    int n;
    ll mod; string s; int base;

    int chartoint(char ch){ return (ch - 'a') + 1; }; // control this function if needed

    ll bigMod(ll a, ll b){ int ans = 1; a = a % mod; while(b){ if(b & 1) ans = (ans * a) % mod; a = (a*a) % mod; b /= 2; } return ans; }
    
    ll MOD(ll num){ return ((num%mod + mod)%mod); }

    ll modAdd(ll a, ll b){ return MOD(MOD(a) + MOD(b)); }

    ll modSub(ll a, ll b){ return MOD(MOD(a) - MOD(b)); }

    ll modMul(ll a, ll b){ return MOD(MOD(a) * MOD(b)); }
    
    ll modDiv(ll a, ll b){ return modMul(a, bigMod(b,mod-2)); }

    void precal_powers(){
        power = vector<ll>(n+5);
        inv = vector<ll>(n+5);
        power[0] = inv[0] = 1;

        for(int i = 1; i <= n; i++){
            power[i] = modMul(power[i-1], base);
        }
        ll pw_inv = bigMod(base, mod-2);
        for(int i = 1; i <= n; i++){
            inv[i] = modMul(inv[i-1], pw_inv);
        }
    }

    void build_hash(){
        int sz = s.size();
        hash = vector<ll>(sz+5);

        for(int i = 1; i <= sz; i++){
            hash[i] = modAdd(hash[i-1], modMul(power[i-1], chartoint(s[i-1])));
        }
    }

    ll getHash(int l, int r){ // query is 1 based
        return modMul(modSub(hash[r], hash[l-1]), inv[l-1]);
    }

    Hash(string &s, int base = 31, int mod = 1e9+9){
        this->s = s;
        this->base = base;
        this->mod = mod;
        n = s.size()+5;

        precal_powers();
        build_hash();
    }
};
