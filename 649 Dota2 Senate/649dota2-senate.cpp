class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> q;
        queue<int> d;
        queue<int> r;
        for(int i=0;i<n;i++){
            q.push(i);
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        while(q.size()>1){
            if(senate[q.front()]=='R'){
                if(!d.size()) return "Radiant";
                senate[d.front()]='X';
                d.pop();
                q.push(q.front());
                q.pop();
                r.push(r.front());
                r.pop();
            }
            else if(senate[q.front()]=='X')
                q.pop();
            else{
                if(!r.size()) return "Dire";
                senate[r.front()]='X';
                r.pop();
                q.push(q.front());
                q.pop();
                d.push(d.front());
                d.pop();
            }
        }
        if(senate[q.front()]=='R') return "Radiant";
        else return "Dire";
;    }
};