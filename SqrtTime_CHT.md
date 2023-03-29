# Sqrt Time CHT

# Concept
- 직선 N개 쿼리 Q개에 대해 $O((N + Q)N^{1/2})$에 CHT를 풀 수 있음
- 쿼리나 직선의 기울기에 대해 단조성이 필요하지 않음
- ll cross(const Line &p, const Line &q) : 직선 p, q의 교점의 x좌표를 올림한 값을 반환
- bool chk(const Line &a, const Line &b, const Line &c) : 직선 c를 삽입할 때 b가 후보에서 삭제되는지를 T/F로 반환
- void insert(ll a, ll b) : 직선 $y = ax + b$를 삽입
- ll qry(ll x) : 삽입된 직선 중 x에서 y값의 최대를 반환

## Implement
```cpp
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
```