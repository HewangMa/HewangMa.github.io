#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int dfs(int** grid, int m, int n, int i, int j){
    if(i<0 || j<0 || i>=m || j>=n
         || grid[i][j] == 0)return 0;
    grid[i][j]=0;
    return 1+dfs(grid,m,n,i+1,j)+
        dfs(grid,m,n,i,j+1)+
        dfs(grid,m,n,i,j-1)+
        dfs(grid,m,n,i-1,j);
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int m=gridSize,n=gridColSize[0];
    int ans=0;  
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            int isa = dfs(grid,m,n,i,j);
            printf("!!\n");
            ans=fmax(ans,isa);
        }
    }
    return ans;
}

int main(){
    int a[4][4] = {
        {1,0,1,0},
        {1,0,1,1},
        {0,1,0,0},
        {1,1,0,0}
    };
    int m = 4;
    int n = 4;
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    int ans = maxAreaOfIsland(a, m, &n);
    printf("%d\n", ans);
    return 0;
}