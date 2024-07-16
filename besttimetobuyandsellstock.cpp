class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]-mini);
        }
        return maxi;
    }
};
