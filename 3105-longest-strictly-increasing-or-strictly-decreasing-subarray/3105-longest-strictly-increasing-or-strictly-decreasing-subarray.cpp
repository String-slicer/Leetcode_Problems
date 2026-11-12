class Solution {
public:
    int getMaxInc(vector<int>&nums){
        int maxi=1;
        int currMax=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currMax++;
            }
            else{
                currMax=1;
            }
            maxi=max(maxi,currMax);
        }
        return maxi;

    }
    int getMaxDec(vector<int>&nums){
        int maxi=1;
        int currMax=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                currMax++;
            }
            else{
                currMax=1;
            }
            maxi=max(maxi,currMax);
        }
        return maxi;

    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int incMax=getMaxInc(nums);
        int decMax=getMaxDec(nums);
        return max(incMax,decMax);
    }
};