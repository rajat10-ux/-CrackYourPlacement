
class Solution {
public:
void mergesort(vector<int>&arr,int low,int mid,int high){
	int left=low,right=mid+1,i;
	vector<int>ans;
	while(left<=mid && right<=high){
		if(arr[left]<=arr[right]){
         ans.push_back(arr[left]);
		 left++;
		}
		else{
			ans.push_back(arr[right]);
			right++;
		}
	}
	while(left<=mid){
		    ans.push_back(arr[left]);
		 left++;
	}
	while(right<=high){
		ans.push_back(arr[right]);
			right++;
	}
	for(i=low;i<=high;i++){
		arr[i]=ans[i-low];
	}
}
int countpairs(vector<int>&arr,int low,int mid,int high){
	int count=0;
	int right=mid+1;
	for(int i=low;i<=mid;i++){
      while(right<=high && arr[i]>2*(long long)arr[right])right++;
		  count+=(right-(mid+1));
	}
	return count;
}
int  merge(vector<int>&arr,int low,int high){
	int count=0;
	if(low>=high) return count;
	int mid=(low+high)/2;
	count+=merge(arr,low,mid);
	count+=merge(arr,mid+1,high);
	count+=countpairs(arr,low,mid,high);
	mergesort(arr,low,mid,high);
	return count;
}
    int reversePairs(vector<int>&arr) {
        int n=arr.size();
        return merge(arr,0,n-1);
    }
};
