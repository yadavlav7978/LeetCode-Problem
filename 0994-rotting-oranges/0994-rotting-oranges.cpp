class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<vector<int>>q;

        int r=grid.size();
        int c=grid[0].size();

        int fresh=0;

        for(int i=0;i<r;i++){

            for(int j=0;j<c;j++){

                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        int time=0;

        if(q.size()>0){
            time=-1;
        }

        while(!q.empty()){

            int sz=q.size();

            for(int k=0;k<sz;k++){

                auto tp=q.front();
                q.pop();

                int i=tp[0];
                int j=tp[1];

                for(auto d:dir){

                    int ni=i+d[0];
                    int nj=j+d[1];

                    if(ni>=0 && nj>=0 && ni<r && nj<c && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                        fresh--;
                    }


                }


            }

            time++;
        }

        if(fresh>0) return -1;

        return time;

        
    }
};