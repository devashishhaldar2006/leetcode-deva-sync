class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string word;
        string ans="";
        while(ss>>word){
            if(word.size()<=2){
                for(int i=0;i<word.size();i++){
                    word[i]=tolower(word[i]);
                }
            }
            else{
                word[0]=toupper(word[0]);
                for(int i=1;i<word.size();i++){
                    word[i]=tolower(word[i]);
                }
            }
            if(ans.size()) ans+=" ";
            ans+=word; 
        }
        return ans;
    }
};