# Random Number

## Concept
- 메르센 트위스터 사용
- T rnd.nxt(T l, T r) : [l, r]에서 난수 반환

## Implement
```cpp
template<typename T> struct RANDOM {
    random_device rg;
    mt19937 rd;
    RANDOM() { rd.seed(rg()); }
    T nxt(T l = 0, T r = 32767) { return uniform_int_distribution<T>(l, r)(rd); }
};

RANDOM<int> rnd;
```