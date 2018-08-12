class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        int i = 0,j= 0;
        for(;i<l;++i)
        {
            if(i!=0 && nums[i] == nums[i-1])
            {
                
            }
            else
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }   
};