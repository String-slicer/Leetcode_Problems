class Solution {
public:
    bool solve(vector<int>& nums,int ind,vector<int>& dp){
        if(ind>=nums.size()-1)return dp[ind]=true;
        if(dp[ind]!=-1)return dp[ind];
        if(nums[ind]==0)return false;
        bool ans=false;
        for(int i=1;i<=nums[ind];i++){
            int newInd=ind+i;
          
            
            ans=solve(nums,newInd,dp);
            if(ans==true)return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int ans=solve(nums,0,dp);

        return ans;
    }
};