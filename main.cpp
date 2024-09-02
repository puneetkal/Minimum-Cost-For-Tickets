class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n]=0;

        for(int k= n-1; k>=0; k--){
            int a=costs[0] + dp[k+1];

            int i;
            for(i=k; i<n && days[i]<days[k]+7; i++);
            int b=costs[1] + dp[i];

            for(i=k; i<n && days[i]<days[k]+30 ; i++);
            int c=costs[2] + dp[i];

            dp[k]=min(a,min(b,c));
        }
        return dp[0];
    }
};