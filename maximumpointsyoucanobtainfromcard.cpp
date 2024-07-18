class Solution {
public:
    int maxScore(vector<int>&arr, int k) {
    int n=arr.size();
        int leftsum=0;
        for(int i=0;i<k;i++){
            leftsum+=arr[i];
        }
        int maxsum=leftsum;
        // k-i-1 is caled drop sum 
        //from front place and add element from back side
        for(int i=0;i<k;i++){
            maxsum=maxsum-arr[k-i-1]+arr[n-i-1];
            leftsum=max(leftsum,maxsum);
        }
        return leftsum;
    }
};
