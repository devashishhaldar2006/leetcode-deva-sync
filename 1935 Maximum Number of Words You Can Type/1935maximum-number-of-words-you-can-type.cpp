class Solution {
public:
    int canBeTypedWords(string str, string broken) {
        vector<bool> flag(26,0);
        for(char ch:broken){
            flag[ch-'a']=1; 
        }
        int ans=0;
        stringstream ss(str);
        string word;
        while(ss>>word){
            bool type=1;
            for(char ch:word){
                if(flag[ch-'a']){
                    type=false;
                    break;
                }

            }
            if(type) ans++;
        }
        return ans;

    }
};