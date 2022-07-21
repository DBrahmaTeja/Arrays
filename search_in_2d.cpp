/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*int lo=0,n=matrix.size(),m=matrix[0].size(),hi=m*n-1;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            int k=matrix[(mid)/m][mid%m];
            if(k==target)
                return true;
            else if(k>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return false;*/
        //----------OR------------
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;
        while(i<n&&j>=0)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(target>matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }