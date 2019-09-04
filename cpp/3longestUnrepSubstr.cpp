//double pointer 20ms
int lengthOfLongestSubstring(string s) {
	int max = 0;//记录最大长度
	int start = 0;//记录活动窗口起始点
	int wLength = 0;//滑动窗口的宽度
	int left = 0;//可变记录点
	for (wLength = 0; wLength < s.size(); wLength++)
	{
		for (left = start; left < wLength; left++)
		{//从窗口的起始点开始进行比对，若有相同的字符则将起始点重新设置
			if (s[left] == s[wLength])
			{
				start = left + 1;
				break;
			}
		}
		max = (max > wLength - start + 1) ? max : wLength - start + 1;
	}
	return max;
}

//96ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {    
        set<char> hashset;
        int ans = 0, left = 0, right = 0;
        while(left < s.size() && right < s.size()){
            if(hashset.count(s[right]) == 0 ){
                hashset.insert(s[right++]);
                ans = max(ans,right - left);
            }
            else{
                hashset.erase(hashset.find(s[left++]));
            }
                
            
        }
        return ans;
    }
};