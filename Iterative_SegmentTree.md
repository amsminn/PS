# Iterative Segment Tree

## Concept
- 0 based index
- Contructor 
    - int _n : 구간의 크기
    - T _ID : 항등원 
    - function<T(T&,T&)> _op : 세그먼트 트리에서 사용할 연산
- void upd(int i, T x) : i번째 원소를 x로 수정, $O(logN)$
- T qry(int l, int r) : op(a[l], op(a[l + 1], op(... a[r])))을 반환, $O(logN)$
- 교환 법칙은 성립하지 않아도 됨

## Implement
```cpp
template<typename T>
struct seg{
    // 0 based index
    int n;T ID;vector<T>tree;
    function<T(T&,T&)>op;
    seg() {}
    seg(int _n,T _ID,function<T(T&,T&)>_op)
        :n(_n),ID(_ID),op(_op),tree(2*_n,ID){}
    void upd(int i,T x){
        tree[i+=n]=x;
        for(i>>=1;i>0;i>>=1)tree[i]=op(tree[i<<1],tree[i<<1|1]);
    }
    T qry(int l,int r){
        T retL=ID,retR=ID;
        for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
            if(l&1)retL=op(tree[l++], retL);
            if(~r&1)retR=op(retR,tree[r--]);
        }
        return op(retL,retR);
    }
};
```
