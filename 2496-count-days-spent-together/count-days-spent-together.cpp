class Solution {
public:
    int toDays(string date) {
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));
        vector<int> days={31,28,31,30,31,30,31,31,30,31,30,31};
        int total=day;
        for(int i=0;i<month-1;i++) {
            total+=days[i];
        }
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int daysAliceArrive=toDays(arriveAlice);
        int daysAliceLeave=toDays(leaveAlice);

        int daysBobArrive=toDays(arriveBob);
        int daysBobLeave=toDays(leaveBob);

        cout<<daysAliceArrive<<endl;
        cout<<daysAliceLeave<<endl;

        cout<<daysBobArrive<<endl;
        cout<<daysBobLeave<<endl;

        int mx=max(daysAliceArrive,daysBobArrive);
        int mn=min(daysAliceLeave,daysBobLeave);


        if(mn<mx) return 0;
        return mn-mx+1;
    }
};