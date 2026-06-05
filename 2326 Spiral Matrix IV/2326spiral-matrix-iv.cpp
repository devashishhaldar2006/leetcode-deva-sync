
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int> (n,-1));
        int minr=0,maxr=m-1,minc=0,maxc=n-1;
        while(minr<=maxr && minc<=maxc && head){
            for(int i=minr;i<=maxc;i++){
                if(!head) return ans;
               ans[minr][i]=head->val;
               head=head->next;
            }
            minr++;
            if(minr>maxr || minc>maxc) break;
            for(int j=minr;j<=maxr;j++){
                if(!head) return ans;
                ans[j][maxc]=head->val;
                head=head->next;
            }
            maxc--;
            if(minr>maxr || minc>maxc) break;
            for(int k=maxc;k>=minc;k--){
                if(!head) return ans;
                ans[maxr][k]=head->val;
                head=head->next;
            }
            maxr--;
            if(minr>maxr || minc>maxc) break;
            for(int l=maxr;l>=minr;l--){
                if(!head) return ans;
                ans[l][minc]=head->val;
                head=head->next;
            }
            minc++;
        }
        return ans;
    }
};