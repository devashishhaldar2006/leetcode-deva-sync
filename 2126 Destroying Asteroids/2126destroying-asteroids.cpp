class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long m=mass;
        for(long long i=0;i<n;i++){
            if(m>=(long long)asteroids[i]){
                m+=(long long)asteroids[i];
            }
            else return false;
        }
        return true;
    }
};