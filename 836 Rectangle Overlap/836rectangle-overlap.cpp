class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[2] <= rec2[0] ||   // A is left of B
            rec1[0] >= rec2[2] ||   // A is right of B
            rec1[3] <= rec2[1] ||   // A is below B
            rec1[1] >= rec2[3]) {   // A is above B

            return false;
        }

        return true;
    }
};