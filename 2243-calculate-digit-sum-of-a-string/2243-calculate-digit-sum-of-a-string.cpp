class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k)return s;
        string num;
        int tempNum=0;
        for(int i=0;i<s.length();i+=k){
            
            for(int j=i;j<i+k && j<s.size();j++){
                tempNum+=s[j]-'0';
            }
            num+=to_string(tempNum);
            tempNum=0;

        }


       

        string Snum=num;
       cout<<num<<endl;
        while(Snum.size()>k){
            string num;
            int tempNum=0;
            for(int i=0;i<Snum.length();i+=k){
                
                for(int j=i;j<i+k && j<Snum.size();j++){
                    tempNum+=Snum[j]-'0';
                }
                 num+=to_string(tempNum);
                tempNum=0;

            }
            Snum=num;
            
            
           
            if(Snum.length()<=k)break;
        }
        return Snum;
    }
};