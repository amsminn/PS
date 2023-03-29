struct DSU{
    vector<int>pa,sz;int n;
    DSU(int _n=0):n(_n){
        pa.resize(n+1);sz=vector<int>(n+1,1);
        iota(pa.begin(),pa.end(),0);
    }
    int find(int a){return pa[a]==a?a:(pa[a]=find(pa[a]));}
    void merge(int a,int b){
        a=find(a);b=find(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        sz[a]+=sz[b];
        pa[b]=a;
    }
};
