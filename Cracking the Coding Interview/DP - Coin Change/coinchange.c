#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long makeChange(int coin[], int coin_num, int money) {
        long *DP = (long *)malloc(sizeof(long)*(money+1)); // O(N) space.
        DP[0] = (long)1; 	// n == 0 case.
        for(int i = 0; i < coin_num; i++) {
            for(int j = coin[i]; j < (money+1); j++) {
            // The only tricky step.
                DP[j] += DP[j - coin[i]];
            }
        }
        return DP[money];
    }

int main(){
    int n;
    int m;
    scanf("%d %d",&n,&m);
    int *coins = malloc(sizeof(int) * m);
    for(int coins_i = 0; coins_i < m; coins_i++){
       scanf("%d",&coins[coins_i]);
    }
    printf("%ld\n", makeChange(coins, m, n));
    return 0;
}
