#include<bits/stdc++.h>
#include<stdio.h>
#define pii pair<int,int>
#define CLR(a) memset(a,0,sizeof(a))
#define max_size 220
using namespace std;
int fx[]= {-1,-1,+0,+0,+1,+1};
int fy[]= {-1,+0,-1,+1,+0,+1};
int flag[max_size][max_size];
char grid[max_size][max_size];
int n;
void floodfill(int i,int j) //check Black
{
    if(i<0 || j<0 || i>=n || j>=n) return ;
    if(grid[i][j]=='b' && flag[i][j]==0) {
        flag[i][j]=1;
        for(int m=0;m<6;m++) floodfill(i + fx[m], j + fy[m]);
    }
}
int main()
{
    int Case=0;
    while(scanf(" %d",&n)!=EOF) {
        if(n==0) break;
        CLR(grid); CLR(flag);
        for(int k=0; k<n; k++) scanf(" %s",grid[k]);
        for(int j=0;j<n;j++) if(grid[0][j]=='b') floodfill(0,j);

        bool test = 0;
        for (int k = 0; k < n; k++) if (flag[n-1][k]) test = 1;
        if (test == 0) printf ("%d W\n", ++Case);
        else printf ("%d B\n", ++Case);
    }
    return 0;
}
