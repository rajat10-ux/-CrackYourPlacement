class Solution {
public:
int helper(vector<int>&nums,int mid){
    int count=1;
    int load=0;
    for(int i=0;i<nums.size();i++){
        if(load+nums[i]<=mid){
            load+=nums[i];
        }
        else{
            count++;
            load=nums[i];
        }
    }
    return count;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
            while(low<=high){
            int mid=(low+high)/2;
            int res=helper(nums,mid);
            if(res<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
