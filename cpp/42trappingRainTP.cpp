public int trap(int[] height) {
    int sum = 0;
    int max_left = 0;
    int max_right = 0;
    int left = 1;
    int right = height.length - 2; // 加右指针进去
    for (int i = 1; i < height.length - 1; i++) {
        //从左到右更
        if (height[left - 1] < height[right + 1]) {
            max_left = Math.max(max_left, height[left - 1]);
            int min = max_left;
            if (min > height[left]) {
                sum = sum + (min - height[left]);
            }
            left++;
        //从右到左更
        } else {
            max_right = Math.max(max_right, height[right + 1]);
            int min = max_right;
            if (min > height[right]) {
                sum = sum + (min - height[right]);
            }
            right--;
        }
    }
    return sum;
}

//stack 4ms
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while(current < height.size()){
            while(!st.empty() && height[current] > height[st.top()]){
                int top = st.top();
                st.pop();
                if(st.empty())
                 break;
                int distance = current -st.top() - 1;  
                int bound_height = min(height[current],height[st.top()]) - height[top];
                ans += distance * bound_height;
                
            }
            st.push(current++);
            
            
        }
        return ans;
    }
};

//https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/