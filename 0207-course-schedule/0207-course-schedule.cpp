class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //1->0
        int n=prerequisites.size();

        vector<vector<int>>graph(numCourses);

        vector<int>indegree(numCourses,0);

        for(int i=0;i<n;i++){

            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            //b ->a

            graph[b].push_back(a);

            indegree[a]++;

        }

        queue<int>q;

        for(int node=0;node<numCourses;node++){

            if(indegree[node]==0){
                q.push(node);
            }

        }

        int count=0;

        while(q.size()>0){

            auto tp=q.front();
            q.pop();
            count++;

            for(auto adj:graph[tp]){

                 indegree[adj]--;

                 if(indegree[adj]==0){
                    q.push(adj);
                 }
            }
        }

        return count==numCourses;
        
    }
};