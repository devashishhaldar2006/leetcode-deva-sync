class Solution {
public:
    bool simulate(vector<int> nums, int start, int dir) {
        int n = nums.size();
        int curr = start;
        
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += dir;
            } else {
                nums[curr]--;
                dir = -dir;
                curr += dir;
            }
        }
        
        for (int x : nums) {
            if (x != 0) return false;
        }
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulate(nums, i, 1)) count++;
                if (simulate(nums, i, -1)) count++;
            }
        }
        return count;
    }
};
