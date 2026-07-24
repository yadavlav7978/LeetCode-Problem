class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>>graph(n);

        for(auto it:paths){

            int a=it[0]-1;
            int b=it[1]-1;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int>color(n,-1);

        for(int i=0;i<n;i++){

            vector<bool>usedFlower(4,false);

            for(auto neigh:graph[i]){
                int clr=color[neigh];
                if(clr==-1) continue;
                usedFlower[clr]=true;
            }

            for(int type=0;type<4;type++){

                if(usedFlower[type]==false){
                    color[i]=type;
                    break;
                }
            }

        }

        for(int i=0;i<n;i++){
            color[i]++;
        }

        return color;

        
        
    }
};