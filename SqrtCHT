struct CHT {
    static const size_t sq = 400;
    static const ll inf = (ll)1e18;
    struct Line {
        ll a, b, x;
        Line(ll _a = 0, ll _b = 0) : a(_a), b(_b), x(-inf) {}
        ll get(ll x) const { return a * x + b; };
    };
    vector<Line> Main;
    vector<pair<ll, ll>> Sub;
    // p.a < q.a or (p.a == p.b and p.b <= q.b)
    ll cross(const Line &p, const Line &q) const {
        if(p.a == q.a) return -inf;
        else return (p.b - q.b + q.a - p.a - 1) / (q.a - p.a);
    }
    bool chk(const Line &a, const Line &b, const Line &c) const {
        return cross(a, c) <= cross(a, b);
    }
    void insert(ll a, ll b) {
        Sub.emplace_back(a, b);
        if(Sub.size() < sq) return;
        sort(Sub.begin(), Sub.end());
        vector<pair<ll, ll>> tmp(Main.size());
        for(int i = 0; i < Main.size(); i++) tmp[i] = {Main[i].a, Main[i].b};
        vector<pair<ll, ll>> ret(sq + Main.size());
        merge(tmp.begin(), tmp.end(), Sub.begin(), Sub.end(), ret.begin());
        Main.clear(); Main.shrink_to_fit();
        Sub.clear(); Sub.shrink_to_fit();
        for(auto &i : ret) {
            Line t = Line(i.first, i.second);
            while(Main.size() > 1 and chk(*++Main.rbegin(), *Main.rbegin(), t)) {
                Main.pop_back();
            }
            ll x = -inf;
            if(!Main.empty()) t.x = cross(Main.back(), t);
            Main.push_back(t);
        }
    }
    ll qry(ll x) const {
        ll mx = -inf;
        for(auto &[a, b] : Sub) mx = max(mx, a * x + b);
        ll lo = -1, hi = Main.size();
        while(lo + 1 < hi) {
            ll m = (lo + hi) / 2;
            if(Main[m].x <= x) lo = m;
            else hi = m;
        }
        if(Main.size()) mx = max(mx, Main[lo].get(x));
        return mx;
    }
};
