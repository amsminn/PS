# Iterative Lichao Tree

## Concept
- upd(Line v) : $y = ax + b$ 꼴의 직선을 후보에 추가, $O(logN)$
- qry(ll x) : 후보 중 $y = ax + b$가 최대일 때 y를 반환, $O(logN)$
- template parameter
    - [QS, QR] : x의 범위
    - inf : |y|의 최댓값

## Implement
```cpp
template<ll Qs = -1e12, ll Qe = 1e12, ll inf = 2e18> struct Lichao {
    struct Line {
        ll a, b;
        ll get(ll x) { return a * x + b; }
    };
    struct Node {
        int l, r;
        Line v;
    };
    vector<Node> tree;
    const ll inf = 2e18;
    void init() { tree.pb({-1, -1, 0, -inf}); }
    ll mid(ll s, ll e) { return (s + e) / 2 - (s + e < 0 and (s + e) % 2); }
    void upd(Line v) {
        int node = 0;
        ll s = Qs, e = Qe;
        while(s <= e) {
            ll m = mid(s, e);
            Line lo = v, hi = tree[node].v;
            if(lo.get(s) > hi.get(s)) swap(lo, hi);
            if(lo.get(e) <= hi.get(e)) {
                tree[node].v = hi;
                break;
            }
            if(lo.get(m) < hi.get(m)) {
                tree[node].v = hi;
                if(tree[node].r == -1) {
                    tree[node].r = tree.size();
                    tree.pb({-1, -1, {0, -inf}});
                }
                s = m + 1;
                v = lo;
                node = tree[node].r;
            } else {
                tree[node].v = lo;
                if(tree[node].l == -1) {
                    tree[node].l = tree.size();
                    tree.pb({-1, -1, {0, -inf}});
                }
                e = m;
                v = hi;
                node = tree[node].l;
            }
        }
    }
    ll qry(ll x) {
        int node = 0;
        ll ret = -inf;
        ll s = Qs, e = Qe;
        while(s <= e) {
            if(node == -1) break;
            ll m = mid(s, e);
            ret = max(ret, tree[node].v.get(x));
            if(x <= m) {
                e = m;
                node = tree[node].l;
            } else {
                s = m + 1;
                node = tree[node].r;
            }
        }
        return ret;
    }
};
```