class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;
        for(int i=0;i<list1.size();i++) m1[list1[i]]=i;
        for(int i=0;i<list2.size();i++) m2[list2[i]]=i;
        vector<string> ans;
        int mn=INT_MAX;
        for(auto itr:m1){
            string curr=itr.first;
            int i=itr.second;
            if(m2.find(curr)!=m2.end()){
                int sum = i + m2[curr];
                if(sum<mn){
                    mn=sum;
                    ans.clear();
                    ans.push_back(curr);
                }
                else if(mn==sum) ans.push_back(curr);
            }
        }
        return ans;

    }
};