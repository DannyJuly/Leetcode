//BF
class Solution {
public:
    int climbStairs(int n) {
        return climb_Stairs(0,n);
    }
    
    int climb_Stairs(int i, int n){
        if(i > n)
            return 0;
        if(i == n)
            return 1;
        return climb_Stairs(i+1,n)+climb_Stairs(i+2,n);
    }
};

//memory recursion O(n)  4ms
class Solution {
public:
    int climbStairs(int n) {
        int* memo = new int[n+1];
        return climb_Stairs(0,n,memo);
    }
    
    int climb_Stairs(int i, int n, int memo[]){
        if(i > n)
            return 0;
        if(i == n)
            return 1;
        if(memo[i] > 0)
            return memo[i];
        memo[i] = climb_Stairs(i+1,n,memo)+climb_Stairs(i+2,n,memo);
        return memo[i];
    }
};

//DP 4ms  Fibonacci number
class Solution {
public:
    int climbStairs(int n) {
        
        if(n <= 2)
            return n;
        int* dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i-2] + dp[i-1];
        return dp[n];
    }
};