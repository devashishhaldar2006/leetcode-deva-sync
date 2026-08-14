class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        vector<char> arr={'I','V','X','L','C','D','M'};
        vector<int> val={1,5,10,50,100,500,1000};
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=val[i];
        }
        int res=0;
        int prev=0;
        for(int i=s.size()-1;i>=0;i--) {
            int curr=m[s[i]];
            if(curr<prev) res-=curr;
            else res+=curr;
            prev=curr;
        };
        return res;
    }
};