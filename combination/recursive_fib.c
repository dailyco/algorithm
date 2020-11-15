#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib(int n) ;

int main(int argc, char * argv[]) {
    if(argc == 1) {
        printf("\nThis program is computing Fibonacci number.\n") ;
        printf("Usage : ./<executable> <n>\n") ;
        printf("        n is the number which you want to compute Fibonacci number.\n\n") ;
    } else if (argc == 2) {
        int n = atoi(argv[1]) ;

        if (strcmp(argv[1], "0") != 0 && n == 0) { printf("err: No command!\n") ; return 0 ; }

        int fib_num = fib(n) ;
        printf("%d's Fibbonacci number : %d\n", n, fib_num) ;
    } else printf("err: No command!\n") ;
}

int fib(int n) {
    if (n < 2) return n ;
    else return fib(n - 1) + fib(n - 2) ;
}
