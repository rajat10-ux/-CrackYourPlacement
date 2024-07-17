Class Solution{
public:
  long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long int mini=INT_MAX;
    for(int i=0;i+m-1<n;i++){
        mini=min(mini,a[i+m-1]-a[i]);
    }
    return mini;
    }
};
