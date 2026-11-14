class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                int sum=0;

                int size=j-i+1;
                if(size>=l && size<=r){
                    for(int k=i;k<=j;k++){
                        sum+=nums[k];
                    }
                if(sum>0)
                minSum=min(minSum,sum);
                }

            }
               
        
        }
        if(minSum==INT_MAX)return -1;
        return minSum;
    }
};