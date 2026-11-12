class Solution {
public:
    int solve(int currStep,int n,vector<int>&cost,int prevCostInd,unordered_map<int,int>&mp){
        if(currStep>=n){
            return 0;
        }
        if(mp.find(currStep)!=mp.end())return mp[currStep];
        int ans1=INT_MAX;
        int ans2=INT_MAX;
        int ans3=INT_MAX;
        int prevCost=0;
        if(prevCostInd!=-1){
            prevCost=cost[prevCostInd-1];
        }
        // cost of going +1
        if(currStep<n)
         ans1=solve(currStep+1,n,cost,currStep+1,mp)+cost[currStep]+pow(currStep+1-currStep,2);
        if(currStep+1<n)
        ans2=solve(currStep+2,n,cost,currStep+2,mp)+cost[currStep+1]+pow(currStep+2-currStep,2);
        if(currStep+2<n)
         ans3=solve(currStep+3,n,cost,currStep+3,mp)+cost[currStep+2]+pow(currStep+3-currStep,2);

        return mp[currStep]=min(ans1,min(ans2,ans3));
    }
    int climbStairs(int n, vector<int>& costs) {
        int prevCostInd= -1;
        unordered_map<int,int>mp;
        int ans = solve(0,n,costs,prevCostInd,mp);
        return ans;
    }
};