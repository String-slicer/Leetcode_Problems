class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        vector<int>sum(arr.size(),0);
        sum[0]=arr[0];
        for(int i=1;i<arr.size();i++ ){
            sum[i]=arr[i]+sum[i-1];
        }

      
        vector<int>prevEven(arr.size(),0);
        vector<int>prevOdd(arr.size(),0);

        if(sum[0]%2==0){
            prevEven[0]=1;
        }
        for(int i=1;i<arr.size();i++){
            if(sum[i]%2==0){
                prevEven[i]=prevEven[i-1]+1;
            }
            else{
                prevEven[i]=prevEven[i-1];

            }
        }
        if(sum[0]%2==1){
            prevOdd[0]=1;
        }
        for(int i=1;i<arr.size();i++){
            if(sum[i]%2==1){
                prevOdd[i]=prevOdd[i-1]+1;
            }
            else{
                prevOdd[i]=prevOdd[i-1];

            }
        }

        int count=0;
        if(sum[0]%2==1)count++;
        for(int i=1;i<arr.size();i++){
            if(sum[i]%2==1){
                
                count++;
                count=(count+prevEven[i])%mod;
            }
            else{
                count=(count+prevOdd[i])%mod;

            }
        }
        return count;


    }
};