class Solution {

    int[] parent;
    int[] size;

    public int findParent(int u){

        if(parent[u]==u) return u;

        return parent[u]=findParent(parent[u]);
    }

    public void unionBySize(int u,int v){

        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return;

        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    public int removeStones(int[][] stones) {

        int n=stones.length;

        int r=0;
        int c=0;

        for(int i=0;i<n;i++){
            r=Math.max(r,stones[i][0]);
            c=Math.max(c,stones[i][1]);
        }

        parent=new int[r+c+2];
        size=new int[r+c+2];

        for(int i=0;i<r+c+2;i++){
            parent[i]=i;
            size[i]=1;
        }


        for(int i=0;i<stones.length;i++){

            int a=stones[i][0];
            int b=stones[i][1];

            int u=a;
            int v=b+r+1;

            unionBySize(u,v);
        }

        Set<Integer>st=new HashSet<>();

        for(int i=0;i<n;i++){
            int pr=findParent(stones[i][0]);
            st.add(pr);
        }

        System.out.println(st.size());

        return n-st.size();

       
        
    }
}