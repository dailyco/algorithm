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
    int * fib_table = (int *)malloc(sizeof(int) * (n + 1)) ;

    fib_table[0] = 0 ;
    fib_table[1] = 1 ;

    for (int i = 2; i < n + 1; i++)
        fib_table[i] = fib_table[i - 1] + fib_table[i - 2] ;

    return fib_table[n] ;
}
