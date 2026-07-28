class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(s.length()<p.length()) return {};

        vector<int>freqP(26,0);

        for(auto it:p){
            freqP[it-'a']++;
        }

        int l=0;

        vector<int>freqS(26,0);

        vector<int>ans;

        for(int i=0;i<s.length();i++){

            freqS[s[i]-'a']++;

            if((i-l+1)>p.length()){
                freqS[s[l]-'a']--;
                l++;
            }

            if(freqP==freqS){
                ans.push_back(l);
            }
        }

        return ans;
        
    }
};