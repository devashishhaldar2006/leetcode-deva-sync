class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int count=0;
        int i=0;
        while(q.size() && count!=q.size()){
            if(q.front()==sandwiches[i]){
                count=0;
                i++;
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return count;
            
    }
};