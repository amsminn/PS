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
        for(char c=*p++;c&16;x=10*x+(c&15),c=*p++);
        return e?-x:x;
    }
    inline void put(T x) {
        if(x<0) *d++='-', x=-x;
        char t[16],*q=t;
        do *q++=x%10|48; while(x/=10);
        do *d++=*--q; while(q!=t);
        *d++=10;
    }
};
