class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        // r , c, k, step

        // 0, 0 ,k, 0
        // if next cell->0- > nr, nc, k, step+1
        // next cell -> 1 (k>0) -> nr,nc,k-1,step+1

        int m=grid.size();
        int n=grid[0].size();

        queue<vector<int>>q;
        q.push({0,0,k,0});

        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        vector<vector<int>>best(m,vector<int>(n,-1));

        best[0][0]=k;
        // i,j , remK=5 , remK=2

        // if(remK>best[i][j])

        while(!q.empty()){

            auto it=q.front();
            q.pop();

            int i=it[0];
            int j=it[1];
            int remK=it[2];
            int step=it[3];

            if(i==m-1 && j==n-1) return step;

            for(auto adj:dir){

                int ni=i+adj[0];
                int nj=j+adj[1];

                if(ni<0 || nj<0 || ni>=m || nj>=n) continue;

                int newRem=remK-grid[ni][nj];

                if(newRem<0 || newRem<=best[ni][nj]) continue;

                best[ni][nj]=newRem;

                q.push({ni,nj,newRem,step+1});

  
                }

            }

    


        return -1;
        
    }
};