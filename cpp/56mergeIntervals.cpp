class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        sort(intervals.begin(), intervals.end());
        int len = intervals.size() - 1;
        int i = 0;
        while(i <= len){
            int left = intervals[i][0];
            int right = intervals[i][1];
            while(i < len && intervals[i+1][0] <= right ){
                right = max(right, intervals[i+1][1]);
                i++;
            }
            ans.push_back(vector<int> {left, right});
            i++;

        }
        return ans;
    }
};

先按首位置进行排序;

接下来,如何判断两个区间是否重叠呢?比如 a = [1,4],b = [2,3]

当 a[1] >= b[0] 说明两个区间有重叠.

但是如何把这个区间找出来呢?

左边位置一定是确定，就是 a[0]，而右边位置是 max(a[1], b[1])

所以,我们就能找出整个区间为:[1,4]

