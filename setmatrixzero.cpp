class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int colm=1;
       int n=matrix.size();
       int m=matrix[0].size();
       for(int i=0;i<n;i++){
        if(matrix[i][0]==0) colm=0;
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
         }
       }
      for(int i=n-1;i>=0;i--){
           for(int j=m-1;j>=1;j--){
                if( matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(colm==0)matrix[i][0]=0;
        }
    }
};
