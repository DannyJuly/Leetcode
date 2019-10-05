//binary search O(log(m+n))
class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        if (m > n) { 
            return findMedianSortedArrays(B,A); // 保证 m <= n
        }
        int iMin = 0, iMax = m;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = (m + n + 1) / 2 - i;
            if (j != 0 && i != m && B[j-1] > A[i]){ // i 需要增大
                iMin = i + 1; 
            }
            else if (i != 0 && j != n && A[i-1] > B[j]) { // i 需要减小
                iMax = i - 1; 
            }
            else { // 达到要求，并且将边界条件列出来单独考虑
                int maxLeft = 0;
                if (i == 0) { maxLeft = B[j-1]; }
                else if (j == 0) { maxLeft = A[i-1]; }
                else { maxLeft = Math.max(A[i-1], B[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; } // 奇数的话不需要考虑右半部分

                int minRight = 0;
                if (i == m) { minRight = B[j]; }
                else if (j == n) { minRight = A[i]; }
                else { minRight = Math.min(B[j], A[i]); }

                return (maxLeft + minRight) / 2.0; //如果是偶数的话返回结果
            }
        }
        return 0.0;
    }
}



//double pointer  O(m+n)
class Solution {
public:
	//method 1. using std
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),nums2.begin(),nums2.end());
        sort(nums1.begin(), nums1.end());
        cout<<nums1.size();
        int res = nums1.size() % 2;
        int m = nums1.size() / 2;
        if(res == 1)
            return nums1[m];
        else
            return double(nums1[m-1]+nums1[m]) /2;
        
    }
    //method 2.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> ans(len1+len2, 0);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
            
        while(i < len1 || j < len2){
            if(nums1[i] <= nums2[j] && i < len1){
                ans[i+j] = nums1[i];
                i++;    
            }
            else if(nums1[i] > nums2[j] && j < len2){
                ans[i+j] = nums2[j];
                j++;    
            }    
        }
        int res = ans.size() % 2;
        int m = ans.size() / 2;
        if(res == 1)
            return ans[m];
        else
            return double(ans[m-1]+ans[m]) /2;
        
    }
};