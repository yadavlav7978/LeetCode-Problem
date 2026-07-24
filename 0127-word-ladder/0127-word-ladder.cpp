class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        set<string>st;

        for(auto it:wordList){
            st.insert(it);
        }

    

        queue<string>q;

        q.push(beginWord);

        int count=1;

        while(q.size()>0){

            int sz=q.size();

            for(int k=0;k<sz;k++){

            auto cur=q.front();
            q.pop(); 
            // st.erase(cur); 

            if(cur==endWord) return count;

            for(int i=0;i<cur.length();i++){

                char orginal=cur[i];

                for(char ch='a';ch<='z';ch++){

                    if(ch==cur[i]) continue;

                    cur[i]=ch;

                    if(st.find(cur)!=st.end()){
                        q.push(cur);
                        st.erase(cur); 
                    }
                    
                }

                 cur[i]=orginal;
            }
            }

            count++;


        }

        return 0;
        
    }
};