class Solution {
public:
int n;
vector<int>dp;

int decode(string s,int i){

    if(i>=n) return 1;

    if(s[i]=='0') return 0;

    if(i==n-1) return 1;


    if(dp[i]!=-1) return dp[i];

    int case1=decode(s,i+1);
    int case2=0;

    if(stoi(s.substr(i,2))<27){
        case2=decode(s,i+2);
    }



    return dp[i]=case1+case2;

}
    int numDecodings(string s) {

        n=s.length();

        dp.resize(n,-1);

        return decode(s,0);
        
    }
};