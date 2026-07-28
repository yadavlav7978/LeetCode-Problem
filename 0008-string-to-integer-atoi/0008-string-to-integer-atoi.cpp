class Solution {
public:
    int myAtoi(string s) {

        int intMin=-2147483648;
        int intMax=2147483647;

        int ispos=1;

        int i=0;
        //Step1 : Igonore the white spacse first
        while(i<s.length() and s[i]==' ') i++;

        //step 2 : checked the signed of integer
        if(s[i]=='-'){
            ispos=-1;
            i++;
        }else if(s[i]=='+'){
            ispos=1;
            i++;
        }

     //step 3: extarct the valid integer
     long val=0;

        while(i<s.length() and s[i]>='0' and s[i]<='9'){

            val=(val*10)+s[i]-'0';

            if((val*ispos)<intMin) return intMin;
            if((val*ispos)>intMax) return intMax;
            
            i++;
        }


        return val*ispos;
        
    }
};