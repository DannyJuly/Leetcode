class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int area = 0, ans = 0;
        while(i < j){
            area = min(height[i], height[j]) * (j-i);
            ans = max(area,ans);
            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};