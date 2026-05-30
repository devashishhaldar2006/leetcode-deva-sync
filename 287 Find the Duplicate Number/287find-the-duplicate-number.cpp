class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            int cnt = 0;
            for (int x : nums) {
                if (x <= mid) cnt++;
            }

            if (cnt > mid)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};