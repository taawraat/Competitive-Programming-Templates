class SparseTable{
public:
    /* all are 1 based indexing */
    vector<int> Log;
    vector<vector<long long>> sp_table;

    void precalLog(int n){
        for(ll i = 2; i <= n; i++){
            Log[i] = Log[i/2]+1;
        }
    }

    void build(int n, vector<ll>& v){
        for(ll i = 1; i <= n; i++){
            sp_table[0][i] = v[i];
        }

        for(ll k = 1; k <= 25; k++){
            for(ll i = 1; i + (1 << k) - 1 <= n; i++){
                sp_table[k][i] = max(sp_table[k-1][i], sp_table[k-1][i + (1 << (k-1))]);
            }
        }
    }

    SparseTable(int n, vector<ll>& v){
        Log = vector<int>(n+5);
        sp_table = vector<vector<long long>>(25, vector<long long>(n+5));
        precalLog(n);
        build(n, v);
    }

    ll query(int left, int right){
        int len = (right - left)+1;

        int k = Log[len];

        return max(sp_table[k][left], sp_table[k][right - (1 << k) + 1]);
    }
};
