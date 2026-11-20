class Solution {
public:
    typedef pair<int,char> pr;
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        for(auto ch:s){
            m[ch]++;
        }
        priority_queue<pr> pq;
        for(auto itr:m){
            pq.push({itr.second,itr.first});
        }
        string ans="";
        while(pq.size()){
            char ch=pq.top().second;
            int freq=pq.top().first;
            pq.pop();
            ans.append(freq,ch);
        }
        return ans;
    }
};