class SegmentTree{
    struct node{
        ll sum, lazy;

        node(){ // Initial node values
            sum = 0;
            lazy = 0;
        }
        node(ll _sum, ll _lazy){
            sum = _sum;
            lazy = _lazy;
        }
    };

public:
    int n;
    vector<node> st;
    vector<int> A; // original array copy. change type accordingly

    void merge(int idx){
        int left = (idx << 1) + 1;
        int right = (idx << 1) + 2;

        st[idx].sum = st[left].sum + st[right].sum;
    }

    void build(int idx, int low, int high){
        if(low > high) return;
        if(low == high){
            st[idx] = node(A[low], 0); // leaf node
            return;
        }

        int mid = (low + high) >> 1;
        st[idx] = node();
        build(2*idx+1, low, mid);
        build(2*idx+2, mid+1, high);
        merge(idx);
    }

    void lazy_update(int idx, int low, int high, int x){ // modify accordingly
        st[idx].lazy += x;
        st[idx].sum += (high - low + 1) * x;
    }

    void lazy_propagate(int idx, int low, int high){
        int mid = (low + high) >> 1;

        lazy_update(2 * idx + 1, low, mid, st[idx].lazy);
        lazy_update(2 * idx + 2, mid+1, high, st[idx].lazy);
        st[idx].lazy = 0; // clear the lazy variable
    }

    void update(int idx, int low, int high, int l, int r, int &x){        
        int mid = (low + high) >> 1;

        if(l <= low and high <= r){ // completely lie under the segment
            lazy_update(idx, low, high, x);
            return;
        }
        else if(high < l || low > r) return; // out of range
        else{
            lazy_propagate(idx, low, high);
            update(2 * idx + 1, low, mid, l, r, x);
            update(2 * idx + 2, mid+1, high, l, r, x);
            merge(idx);
        }
    }

    void update(int l, int r, int x){ // range update, add x from l to r (1 based indexing)
        update(0, 0, n-1, l-1, r-1, x); // converted to 0 based indexiing
    }

    int query(int idx, int low, int high, int l, int r){
        int mid = (low + high) >> 1;

        if(l <= low and high <= r){ // completely lie under the segment
            return st[idx].sum;
        }
        else if(high < l || low > r) return 0; // out of range
        else{
            lazy_propagate(idx, low, high);
            
            int L = query(2 * idx + 1, low, mid, l, r);   // left node value
            int R = query(2 * idx + 2, mid+1, high, l, r); // right node value
            merge(idx);

            return L + R; // return accordingly
        }
    }

    int query(int l, int r){ // 1 index based
        return query(0, 0, n-1, l-1, r-1); // converted to 0 based
    }

    template<typename T>
    SegmentTree(int sz, vector<T> v){
        A = v;
        n = sz;
        st = vector<node>((n << 2) + 10);
        build(0, 0, n-1);
    }
};
