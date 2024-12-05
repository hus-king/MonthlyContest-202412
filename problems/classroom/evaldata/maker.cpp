#include "testlib.h"
#include <iostream>

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T, n, m;
    for(int i = 1; i <= 20; ++i) {
        startTest(i);
        if(i <= 2) {   
            T = rnd.wnext(1, 10, 3);
            printf("%d\n",T);
            for(int j = 1; j <= T; ++j) {
                n = 1; m = rnd.wnext(1, 1000, 5);
                printf("%d %d\n", n, m);
            }
        }
        else if(i <= 4) {
            T = rnd.wnext(10, 3);
            printf("%d\n",T);
            for(int j = 1; j <= T; ++j) {
                n = 2; m = rnd.wnext(1, 1000, 5);
                printf("%d %d\n", n, m);
            }
        }
        else if(i <= 8) {
            T = 1;
            printf("%d\n",T);
            for(int j = 1; j <= T; ++j) {
                n = rnd.wnext(3, 9, 0); m = rnd.wnext(3, 9, 0);
                while(n * m > 36) {
                	n = rnd.wnext(3, 9, 0); m = rnd.wnext(3, 9, 0);
                }
                printf("%d %d\n", n, m);
            }
        }
        else if(i <= 14) {
            T = rnd.wnext(1, 10, 3);
            printf("%d\n",T);
            for(int j = 1; j <= T; ++j) {
                n = rnd.wnext(1, 1000, 5); m = rnd.wnext(1, 1000, 5);
                while((n & 1) && (m & 1)) {
                    n = rnd.wnext(1, 1000, 5); m = rnd.wnext(1, 1000, 5);
                }
                printf("%d %d\n", n, m);
            }
        }
        else {
            T = rnd.wnext(1, 10, 4);
            printf("%d\n",T);
            for(int j = 1; j <= T; ++j) {
                n = rnd.wnext(1, 1000, 5); m = rnd.wnext(1, 1000, 5);
                printf("%d %d\n", n, m);
            }
        }
    }

}
