class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;       
        int row = matrix.size(), cols = matrix[0].size();
        int i = 0, j = cols - 1;
        while(i < matrix.size() && j < matrix[0].size()){
            if(target > matrix[i][j])
                i++;
            else if(target < matrix[i][j])
                j--;
            else
                return true;
        }
        return false;
    }
};

//8ms
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;       
        int row = matrix.size(), cols = matrix[0].size();
        int i =0;
        while(i < min(row,cols)){
            if(target > matrix[i][i])
                i++;
            else if(target == matrix[i][i])
                return true;
            else
                break;
        }
        i--;
        cout<<i;
       for(int j = 0;j <= i; j++)
            matrix[j].erase(matrix[j].begin(),matrix[j].begin() + i+1);
         int m,n;
        for(m = 0; m < matrix.size();m++)
            for(n = 0; n < matrix[m].size(); n++){
                if(target == matrix[m][n])

                    return true;
            }
        return false;
    }
};