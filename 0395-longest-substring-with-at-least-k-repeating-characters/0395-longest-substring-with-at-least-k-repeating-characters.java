class Solution {

    public int helper(String s,int u,int k){

        int n=s.length();

        int unique=0;
        int uniqueAtleastK=0;

        int v[]=new int[26];
        int left=0;

        int len=0;

        for(int i=0;i<n;i++){

            char ch=s.charAt(i);

            v[ch-'a']++;

            if(v[ch-'a']==1){
                unique++;
            }
            if(v[ch-'a']==k){
                uniqueAtleastK++;
            }

            while(unique>u){

                if(v[s.charAt(left)-'a']==k){
                    uniqueAtleastK--;
                }

                v[s.charAt(left)-'a']--;

                if(v[s.charAt(left)-'a']==0){
                    unique--;
                }
                left++;
            }

            if(unique==u && uniqueAtleastK==u){
                len=Math.max(len,i-left+1);
            }

        }

        return len;

    }

    public int longestSubstring(String s, int k) {

        // U (1->26)
        // find  length of the longest substring of s such the substring should only contain U unique character +
        // frequency of each character in this substring is greater than or equal to k

        int ans=0;

        for(int u=1;u<=26;u++){

            int res=helper(s,u,k);

            ans=Math.max(ans,res);

        }

        return ans;
        
    }
}