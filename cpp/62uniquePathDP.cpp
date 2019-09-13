//4ms  DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(n, vector<int>(m,1));
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];    
            }
        }
        return dp[n-1][m-1];
    }
};

//recursion exceed time limit
class Solution{
	public:
		int uniquePaths(int m, int n){
			if(m <= 0 || n <= 0)
				return 0;
			else if(m == 1  || n == 1)//只能一直向右走或者一直向下走，所以路径数为 1
				return 1;
			else if(m == 2 && n == 2)
				return 2;
			else if((m == 3 && n == 2) || (m == 2 && n == 3))
				return 3;
			int paths = 0;
			paths = uniquePaths(m-1,n)+uniquePaths(m,n-1);		
			return paths;
		}
};


