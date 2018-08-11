class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        int l = nums.size();
        for(;i<l;++i)
        {
            if(nums[i]!=val)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};