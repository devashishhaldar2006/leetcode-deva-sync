class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev=countAndSay(n-1);
        string ztr="";
        int freq=1;
        char ch=prev[0];
        for(int i=1;i<prev.length();i++){
            char dh=prev[i];
            if(ch==dh){
                freq++;
            }
            else{
                ztr+=(to_string(freq)+ch);
                freq=1;
                ch=dh;
            }
        }
        ztr+=(to_string(freq)+ch);
        return ztr;

    }
};