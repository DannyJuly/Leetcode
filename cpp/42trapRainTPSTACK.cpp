
//O(n) TC O(n) memory
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left(size), right(size);
        //left[0] = height[0];
        for(int i = 1; i < size; i++)
            left[i] = max(height[i-1],left[i-1]);
        for(int i = size - 2; i > 0; i--)
            right[i] = max(height[i+1],right[i+1]);
        for(int i = 1; i < size-1; i++){
            int m = min(left[i],right[i]);
            if(m > height[i])
                ans += m - height[i];
        }
        return ans;
    }
};

//O(N),O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int ans = 0;
        int size = height.size();
        int max_left = 0;
        int max_right = 0;
        int left = 1;
        int right = size - 2;// 加右指针进去
        for(int i = 1; i < size - 1; i++){
            //从左到右更
            if(height[left - 1] < height[right + 1]){
                max_left = max(max_left, height[left-1]);
                int minh = max_left;
                if(minh > height[left])
                    ans+=minh - height[left];
                left++;
            }
             //从右到左更
            else{
                max_right = max(max_right, height[right+1]);
                int minh = max_right;
                if(minh > height[right])
                    ans += minh - height[right];
                right--;
            }
        }
        

    
        return ans;
    }
};

//stack 4ms
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}

//https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/