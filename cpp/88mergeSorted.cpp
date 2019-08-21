class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n -1;
        --m;
        --n;
        while(m >= 0 && n>= 0)
           nums1[tail--] = (nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
        while(n >= 0){
            nums1[tail--] = nums2[n--];
        }
    }


	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	for(int i = m; i < m + n; ++i)
		nums1[i] = nums2[i - m];
		sort(nums1.begin(), nums1.begin() + m + n ); //直接快速排序，nlogn
	}
};

