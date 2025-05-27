class Solution {
public:
    void helper(int a,int b,vector<int> &v){
        int i=a;
        int j=b;
        while(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k=k%n;
        helper(0,n-k-1,nums);
        helper(n-k,n-1,nums);
        helper(0,n-1,nums);
        return;
    }
};