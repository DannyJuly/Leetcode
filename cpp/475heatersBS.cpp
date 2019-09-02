class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int pos = 0;
        int len = heaters.size();
        int max = 0;
        for(int i = 0; i < houses.size(); i++)
        {
            //找到下边界
            while(pos < len)
            {
               if(heaters[pos] < houses[i])
                   pos++;
                else
                    break;
            }
            
            int k1 = INT_MAX, k2 = INT_MAX;
            //计算下边界
            if(pos < len)
            {
                k1 = heaters[pos] - houses[i];
            }
            
            //计算上边界
            if(pos > 0)
            {
                k2 = houses[i] - heaters[pos -1];
            }
            
            //本次获取较小的
            int key = k1 > k2 ? k2 : k1;

            //与已经获取的相比  取较大的
			if(key > max)
				max = key;
            
        }
        
        return max;
    }
};

