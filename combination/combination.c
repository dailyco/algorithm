#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_help() ;
long long recursive_algorithm(int n, int k) ;
long long dynamic_programming_algorithm(int n, int k) ;

int main(int argc, char * argv[]) {

    if(argc == 1) print_help() ;
    else if (argc == 4) {
        char * option = argv[1] ;
        int n = atoi(argv[2]) ;
        int k = atoi(argv[3]) ;

        if (n >= 0 && k <= n) {
            clock_t start, finish ;
            double duration = 0.0 ;

            printf("Computing %dC%d...\n", n, k) ;

            if (strcmp(option, "-r") == 0 || strcmp(option, "-b") == 0) {
                start = clock() ;
                long long result = recursive_algorithm(n, k) ;
                finish = clock() ;
                duration = (double)(finish - start)/CLOCKS_PER_SEC ;
                printf("Recursive Algorithm: %lli | time : %f sec\n", result, duration) ;
            }

            if (strcmp(option, "-d") == 0 || strcmp(option, "-b") == 0) {
                start = clock() ;
                long long result = dynamic_programming_algorithm(n, k) ;
                finish = clock() ;
                duration = (double)(finish - start)/CLOCKS_PER_SEC ;
                printf("Dynamic Programming: %lli | time : %f sec\n", result, duration) ;
            }
        } else printf("err: n is smaller than k!\n") ;
    } else printf("err: No command!\n") ;

    return 0;
}

long long recursive_algorithm(int n, int k) {
    if (k == n || k == 0) return 1 ;
    else return recursive_algorithm(n-1, k-1) + recursive_algorithm(n-1, k) ;
}

long long dynamic_programming_algorithm(int n, int k) {
    long long ** combination ;
    long long answer ;

    combination = (long long **)malloc(sizeof(long long *) * (n+1)) ;
    for(int i = 0; i < n + 1; i++)
        combination[i] = (long long *)malloc(sizeof(long long) * (i + 1)) ;

    for (int i = 0; i < n + 1; i++) {
        for(int j = 0; j <= i && j != k + 1; j++) {
            if(i == j || j == 0) combination[i][j] = 1 ;
            else combination[i][j] = combination[i-1][j-1] + combination[i-1][j] ;
        }
    }
    answer = combination[n][k] ;

    for (int i = 0; i < n + 1; i++) free(combination[i]) ;
    free(combination);

    return answer ;
}

void print_help() {
        printf("This program is computing Combination.\n") ;
        printf("Usage: ./<excutable> <option> <n> <k>\n") ;
        printf("option:\n") ;
        printf("        -r  Recursive Algorithm\n") ;
        printf("        -d  Dynamic Programming Algorithm\n") ;
        printf("        -b  Both and comparing\n") ;
}
