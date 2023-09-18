# FastIO

## Concept
- std::cin, std::cout, std::scanf, std::printf 등의 입출력과 혼용하면 안됨
- void set() : main에서 가장 먼저 실행해야함
- T get() : 정수 하나를 입력받고 반환
- void put(T x) : 정수 x를 출력
- 실수는 사용 불가능
- x 하나당 자릿수가 20이 넘는다면 put 함수의 char t[20]의 크기를 수정해야함

## Implement
```cpp
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
template<typename T>
struct FASTIO {
    char *p,O[2000000],*d;
    void set() {
        struct stat st;fstat(0,&st);d=O;
        p=(char*)mmap(0,st.st_size,1,1,0,0);
    }
    ~FASTIO() {
        write(1,O,d-O);
    }
    inline T get() {
        T x=0;bool e;p+=e=*p=='-';
        for(;*p==10 or *p==32;p++);
        for(char c=*p++;c&16;x=10*x+(c&15),c=*p++);
        return e?-x:x;
    }
    inline void put(T x) {
        if(d-O+100>2000000) write(1,O,d-O), d=O;
        if(x<0) *d++='-', x=-x;
        char t[16],*q=t;
        do *q++=x%10|48; while(x/=10);
        do *d++=*--q; while(q!=t);
        *d++=10;
    }
};
```
