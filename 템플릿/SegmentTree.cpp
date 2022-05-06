template<typename T>
struct seg{
    // 0 based index
    int n;T ID;vector<T>tree;
    function<T(T&,T&)>op;
    seg(){}
    seg(int _n,T _ID,function<T(T&,T&)>_op)
        :n(_n),ID(_ID),op(_op),tree(2*_n,_ID){}
    void upd(int i,T x){
        tree[i+=n]=x;
        for(i>>=1;i>0;i>>=1)tree[i]=op(tree[i<<1],tree[i<<1|1]);
    }
    T qry(int l,int r){
        T retl=ID,retr=ID;
        for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
            if(l&1)retl=op(retl, tree[l++]);
            if(~r&1)retr=op(tree[r--], retr);
        }
        return op(retl,retr);
    }
};
