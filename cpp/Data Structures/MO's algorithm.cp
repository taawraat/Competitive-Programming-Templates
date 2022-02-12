int n;
int ans;
int BLOCK = 555; // ~sqrt(n)
int arr[311111];

struct query{
    int L,R,id;
};

bool cmp(query x, query y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		return x.L/BLOCK < y.L/BLOCK;
	}
	return x.R < y.R;
}

void add(int i){
    // if one element is added what happens?
}

void remove(int i){
    // if one element is removed what happens?
}

void MO(vector<query>& Query, vector<ll>& Ans){
    sort(Query.begin(), Query.end(), cmp);

    int L,R;
    int currentL = 0, currentR = 0;

    for(auto &it: Query){
        L = it.L;
        R = it.R;

        while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
        
        Ans[it.id] = ans;
    }
}