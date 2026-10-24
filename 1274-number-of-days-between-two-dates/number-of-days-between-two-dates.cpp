class Solution {
public:
    bool isLeap(int year) {
        return (year%400==0) || (year%4==0 && year%100!=0);
    }
    int toDays(string date){
        vector<int> days={31,28,31,30,31,30,31,31,30,31,30,31};
        int day=stoi(date.substr(8,2));
        int month=stoi(date.substr(5,2));
        int year=stoi(date.substr(0,4));

        if(isLeap(year)){
            days[1]+=1;
        }

        int total=day;
        for(int i=0;i<month-1;i++){
            total+=days[i];
        }
        for(int y=1;y<year;y++) {
            total+=isLeap(y)?366:365;
        }
        return total;
    }
    int daysBetweenDates(string date1, string date2) {
        int a=toDays(date1);
        int b=toDays(date2);
        return abs(a-b);
    }
};