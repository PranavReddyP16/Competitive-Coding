#include<bits/stdc++.h>
using namespace std;
class Solution{public:
int numIslands(vector<vector<char>>&grid){
    int n=grid.size(),m=grid[0].size(),cnt=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(grid[i][j]=='1'){
        cnt++;queue<pair<int,int>>q;q.push({i,j});grid[i][j]='0';
        while(!q.empty()){auto[x,y]=q.front();q.pop();
            int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
            for(int d=0;d<4;d++){int nx=x+dx[d],ny=y+dy[d];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]=='1'){grid[nx][ny]='0';q.push({nx,ny});}
            }
        }
    }
    return cnt;
}};
int main(){return 0;}
// cleanup
