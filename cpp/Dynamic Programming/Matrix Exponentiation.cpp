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
