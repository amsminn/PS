struct DSU{
    vector<int>pa;int n;
    DSU(int _n):n(_n){pa.resize(n+1);iota(pa.begin(),pa.end(),0);}
    int find(int a){return pa[a]==a?a:(pa[a]=find(pa[a]));}
    void merge(int a,int b){pa[find(b)]=find(a);}
};
