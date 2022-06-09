
class FenwickTree{
    public:
    /* everything is 1 based indexing */
    vector<ll> BIT;

    FenwickTree(int size){
        BIT = vector<ll>(size+3, 0);
    }

    void update(int idx, ll val, int n){
        while(idx <= n){
            BIT[idx] += val;
            idx += (idx & - idx);
        }
    }

    ll prefix_query(int idx){
        ll res = 0;
        
        while(idx > 0){
            res += BIT[idx];
            idx -= (idx & -idx);
        }

        return res;
    }

    ll range_query(int l, int r){
        return prefix_query(r) - prefix_query(l-1);
    }
};
