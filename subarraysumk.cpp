class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int,int>mp;
       mp[0]=1;
       int count=0;
       int sum=0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int rem=sum-k;
        if(mp.find(rem)!=mp.end()){
            count+=mp[rem];
        }
        mp[sum]+=1;
       }
       return count;   
    }
};
