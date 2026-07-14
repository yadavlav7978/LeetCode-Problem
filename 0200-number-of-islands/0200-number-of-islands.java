class Solution {
    int r,c;
    int[][] dir={{0,1},{1,0},{-1,0},{0,-1}};

    public void visited(int i,int j, char[][] grid){

        grid[i][j]='0';


        for(int[] it: dir){

            int ni=i+it[0];
            int nj=j+it[1];

            if(ni<0 || nj<0 || ni>=r || nj>=c || grid[ni][nj]=='0') continue;

                visited(ni,nj,grid);
            

        }

    }

    public int numIslands(char[][] grid) {
        
        r=grid.length;
        c=grid[0].length;

        int count=0;

        for(int i=0;i<r;i++){

            for(int j=0;j<c;j++){

                if(grid[i][j]=='1'){

                    visited(i,j,grid);
                    count++;

                }


            }
        }

        return count;
    }
}