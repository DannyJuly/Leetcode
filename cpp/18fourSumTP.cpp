class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	vector<vector<int>>str;
	int a = nums.size();
	int b, c, d;
	int temp;
	for (int i = 0; i < a; i++) {
		temp = target - nums[i];
		for (int j = i + 1; j < a; j++) {
			b = nums[j];
			c = j + 1;
			d = a - 1;
			while (c < d) {
				int sum = b + nums[c] + nums[d];
				if (sum == temp) {
					str.push_back({ nums[i],b,nums[c],nums[d] });
					c++;
					d--;
				}
				if (sum < temp) {
					c++;
				}
				if (sum >temp) {
					d--;
				}

			}
		}
	}
	sort(str.begin(), str.end()); ////必须先sort，可查看unique源码
	str.erase(unique(str.begin(), str.end()), str.end());
	return str;
	}
};

作者：du-gu-jian-cheng
链接：https://leetcode-cn.com/problems/4sum/solution/lei-si-qian-ji-ti-xian-gu-ding-yi-ge-shu-zai-gu-di/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。