class Solution {
public:
    string decimal_to_binary(int n){
        if(n==0) return "0";
    	string result="";
    	while(n>0){
    		if(n%2==0){
    			result="0"+result;
    		}
    		else{
    			result="1"+result;
    		}
    		n=n>>1;
    	}
    	return result;
    }
    int minimumFlips(int n) {
        string s=decimal_to_binary(n);
        string r=s;
        reverse(r.begin(),r.end());
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=r[i]) count++;
        }
        return count;
    }
};