class Solution {
public:
    string countAndSay(int n) {
        string nums;
        string temp;
        nums.append(1, '1');
        for (int j = 1; j < n; j++)
        {
            int target = nums[0] ;
            int count = 1+'0';
            for (int i = 1; i < nums.length(); )
            {
                if (target != nums.at(i))
                {
                    temp.append(1, (char)(count ));
                    temp.append(1, (char)(target));
                    count = 1+'0';
                    target = nums.at(i++) ;
                }
                else {count++;i++;}
            }
            temp.append(1, (char)(count ));
            temp.append(1, (char)(target));
            nums = temp;
            temp.clear();
        };
        return nums;
    }
};

