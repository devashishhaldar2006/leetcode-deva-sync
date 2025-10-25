class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n=operations.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            string ch = operations[i];

            if (ch == "+") {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.push(val1);
                st.push(val1 + val2);
            }
            else if (ch == "D") {
                int x = st.top();
                st.push(2 * x);
            }
            else if (ch == "C") {
                st.pop();
            }
            else {
                st.push(stoi(ch));
            }
        }

        int score = 0;
        while (!st.empty()) {
            score += st.top();
            st.pop();
        }
        return score;
    }
};
