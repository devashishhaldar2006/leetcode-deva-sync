class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int> m;
        if(n1>=n2){
            for(int i=0;i<n2;i++){
                m[nums2[i]]++;
            }
            for(int i=0;i<n1;i++){
                if (m.find(nums1[i])!=m.end() && m[nums1[i]]) {
                    ans.push_back(nums1[i]);
                    m[nums1[i]]--;
                }
            }
        }
        else{
            for(int i=0;i<n1;i++){
                m[nums1[i]]++;
            }
            for(int i=0;i<n2;i++){
                if (m.find(nums2[i])!=m.end() && m[nums2[i]]) {
                    ans.push_back(nums2[i]);
                    m[nums2[i]]--;
                }
            }
        }
        return ans;
    }
};