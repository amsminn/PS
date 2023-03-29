struct Lichao {
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
        ll s = -1e12, e = 1e12;
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
        ll s = -1e12, e = 1e12;
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
