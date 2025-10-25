class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int weekStart = 1; 
        int dayMoney = weekStart;
        for (int i = 1; i <= n; i++) {
            total += dayMoney;
            dayMoney++;
            if (i % 7 == 0) {
                weekStart++;
                dayMoney = weekStart;
            }
        }

        return total;

    }
};