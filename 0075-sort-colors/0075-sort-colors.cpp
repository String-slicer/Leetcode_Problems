class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0;
        int sec=nums.size()-1;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==0){
               swap(nums[i],nums[one++]);
            }
            else if(nums[i]==2 && i<=sec){
                swap(nums[i],nums[sec--]);
                i--;
            }
        
            i++;
           
        }

    }
};