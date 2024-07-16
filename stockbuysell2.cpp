class Solution {
public:
int helper(int ind,int buy,vector<int>&arr,vector<vector<int>>&dp){
    if(ind==arr.size()) return 0;
    int ans=0;
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    if(buy){
        // if buy allowed
        int op1=-arr[ind]+helper(ind+1,0,arr,dp);
        // if by not allowed
        int op2=0+helper(ind+1,1,arr,dp);
        ans=max(op1,op2);
    }
    else{
        // sell karo to agian buy allowed
        int op1=arr[ind]+helper(ind+1,1,arr,dp);
        // if by not allowed
        int op2=helper(ind+1,0,arr,dp);
        ans=max(op1,op2);
    }
    dp[ind][buy]=ans;
    return dp[ind][buy];
}
int secondhelper(vector<int>&arr){
    int n=arr.size();
     vector<vector<int>>dp(n+1,vector<int>(2,0));
     int ans=0;
     for(int i=n-1;i>=0;i--){
        for(int j=0;j<=1;j++){
               if(j){
        // if buy allowed
        int op1=-arr[i]+dp[i+1][0];
        // if by not allowed
        int op2=0+dp[i+1][1];
        ans=max(op1,op2);
    }
    else{
        // sell karo to agian buy allowed
        int op1=arr[i]+dp[i+1][1];
        // if by not allowed
        int op2=dp[i+1][0];
        ans=max(op1,op2);
    }
    dp[i][j]=ans;
        }
     }
     return dp[0][1];
}
int thirdhelper(vector<int>&arr){
    int n=arr.size();
    //  vector<vector<int>>dp(n+1,vector<int>(2,0));
    vector<int>curr(2,0);
    vector<int>next(2,0);
     int ans=0;
     for(int i=n-1;i>=0;i--){
        for(int j=0;j<=1;j++){
               if(j){
        // if buy allowed
        int op1=-arr[i]+next[0];
        // if by not allowed
        int op2=0+next[1];
        ans=max(op1,op2);
    }
    else{
        // sell karo to agian buy allowed
        int op1=arr[i]+next[1];
        // if by not allowed
        int op2=next[0];
        ans=max(op1,op2);
    }
    curr[j]=ans;
        }
        next=curr;
     }
     return  next[1];
}
    int maxProfit(vector<int>& prices) {
    //    int ind=0,buy=1;
        // int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // int ans=helper(ind,buy,prices,dp);
        // return ans;
        return thirdhelper(prices);
    }
};
