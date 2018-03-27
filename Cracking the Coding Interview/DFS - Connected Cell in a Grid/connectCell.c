#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int countCell(int **grid, int i, int j, int n, int m){
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;

    grid[i][j] = 0;
    int count = 1; //grid[i][j] == 1
    count += countCell(grid, i-1, j-1, n, m);
    count += countCell(grid, i, j-1, n, m);
    count += countCell(grid, i+1, j-1, n, m);
    count += countCell(grid, i-1, j, n, m);
    count += countCell(grid, i+1, j, n, m);
    count += countCell(grid, i-1, j+1, n, m);
    count += countCell(grid, i, j+1, n, m);
    count += countCell(grid, i+1, j+1, n, m);
    return count;
}

int main(){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int grid[n][m];
    for(int grid_i = 0; grid_i < n; grid_i++){
       for(int grid_j = 0; grid_j < m; grid_j++){

          scanf("%d",&grid[grid_i][grid_j]);
       }
    }

    int max = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int tmp = countCell(grid, i, j, n, m);
            max = (tmp > max) ? tmp : max;
        }
    printf("%d\n", max);
    return 0;
}
