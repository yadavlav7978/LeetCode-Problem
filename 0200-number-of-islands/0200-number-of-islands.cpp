class Solution {
public:
int r,c;

void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>dir){

    if(i<0 || j<0 || i>=r || j>=c || grid[i][j]=='0') return;


    grid[i][j]='0';

    for(int k=0;k<4;k++){

        int ni=i+dir[k][0];
        int nj=j+dir[k][1];

        dfs(ni,nj,grid,dir);

    }

}


    int numIslands(vector<vector<char>>& grid) {

        int count=0;

        r=grid.size();
        c=grid[0].size();

        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<r;i++){

            for(int j=0;j<c;j++){

                if(grid[i][j]=='1'){

                    dfs(i,j,grid,dir);

                    count++;
                }
            }
        }


return count;

        
    }
};