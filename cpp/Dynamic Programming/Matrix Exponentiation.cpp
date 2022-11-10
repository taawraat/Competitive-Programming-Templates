class MatrixExpo{
public:
    int MAX_N;
    vector<vector<int>> ans; // give the ans datatype manually

    template<typename T>
    vector<vector<T>> matMul(vector<vector<T>>& a, vector<vector<T>>& b){
        vector<vector<T>> res(MAX_N, vector<T>(MAX_N));
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

    template<typename T>
    void matPow(vector<vector<T>>& base, long long power){
        while(power){
            if(power&1) ans = matMul(ans, base);
            base = matMul(base, base);
            power >>= 1;
        }
    }

    template<typename T>
    MatrixExpo(vector<vector<T>> base,long long power, int size){
        MAX_N = size;
        ans = vector<vector<T>>(MAX_N, vector<T>(MAX_N));

        for(int i = 0; i < MAX_N; i++){
            for(int j = 0; j < MAX_N; j++){
                ans[i][j] = (i == j);
            }
        }

        matPow(base, power);
    }
};
