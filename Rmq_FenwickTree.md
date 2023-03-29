# Rmq Fenwick Tree

## Concept
- Constructor
    - int _n : 구간의 크기
    - T _ID : 항등원
    - function<T(const T&, const T&)> _f : 구간에 사용할 연산
- void init() : $O(N)$에 펜윅 트리를 초기화
- void upd(int i, T x) : i번째 원소를 x로 수정, $O(logN)$
- T qry(int l, int r) : - T qry(int l, int r) : f(a[l], f(a[l + 1], f(... a[r])))을 반환, $O(logN)$
- 역원이 존재하지 않는 연산에도 사용 가능

## Implement
```cpp
template<typename T>
struct fenwick {
    int n; T ID; vector<T> v, FT1, FT2;
    function<T(const T&, const T&)> f;
    fenwick() {}
    fenwick(int _n, T _ID, function<T(const T&, const T&)> _f) : n(_n), ID(_ID), f(_f) {
        // FT1[j] = (j - (j & -j), j]
        // FT2[j] = [j, j + (j & -j))
        FT1 = vector<T>(n + 1, ID);
        FT2 = vector<T>(n + 1, ID);
        v = vector<T>(n + 1, ID);
    }
    void init() {
        for(int i=1; i<=n; i++) if(i + (i & -i) <= n)
            FT1[i + (i & -i)] = f(FT1[i], FT1[i + (i & -i)]);
        for(int i=n; i>0; i--)
            FT2[i - (i & -i)] = f(FT2[i], FT2[i - (i & -i)]);
    }
    void upd(int i, T x) {
        T t = v[i] = x;
        for(int j=i,l=i-1,r=i+1; j<=n; j+=j&-j) {
            while(l > 0 and l - (l & -l) >= j - (j & -j)) t = f(FT1[l], t), l -= l & -l;
            while(r + (r & -r) <= j) t = f(t, FT2[r]), r += r & -r;
            FT1[j] = i ^ j ? f(t, v[j]) : t;
        }
        t = x;
        for(int j=i,l=i-1,r=i+1; j>0; j-=j&-j) {
            while(l - (l & -l) >= j) t = f(FT1[l], t), l -= l & -l;
            while(r + (r & -r) <= j + (j & -j)) t = f(t, FT2[r]), r += r & -r;
            FT2[j] = i ^ j ? f(v[j], t) : t;
        }
    }
    T qry(int l, int r) {
        T ret1 = ID, ret2 = ID; int i;
        for(i=l; i+(i&-i)<=r; i+=i&-i) ret2 = f(ret2, FT2[i]);
        for(i=r; i-(i&-i)>=l; i-=i&-i) ret1 = f(FT1[i], ret1);
        return f(f(ret1, v[i]), ret2);
    }
};
```