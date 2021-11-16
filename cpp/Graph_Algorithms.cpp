// DSU + Minimum Spanning Tree (Kruskal)
class MST{
public:
    vector<int> par, _size;

    MST(int size){
        par = vector<int>(size+10);
        _size = vector<int>(size+10);

        for(ll i = 1; i <= size; i++){
            par[i] = i;
            _size[i] = 1;
        }
    }

    int findP(int node){
        if(par[node] == node)
            return node;
        
        return par[node] = findP(par[node]);
    }

    void Union(int u, int v){
        u = findP(u);
        v = findP(v);

        if(u == v) return;

        if(_size[u] > _size[v]){
            par[v] = u;
            _size[u] += _size[v];
        }
        else{
            par[u] = v;
            _size[v] += _size[u];
        }
    }

    ll Kruskal(vector<pair<ll, pair<ll, ll>>>& data){
        ll minCost = 0;
        ll u,v,cost;

        for(auto &it: data){
            cost = it.first;
            u = it.second.first;
            v = it.second.second;

            if(findP(u) != findP(v)){
                minCost += cost;
                Union(u,v);
            }
        }

        return minCost;
    }
};
