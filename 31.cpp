class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return ;
        int i = n-1;
        while(i-1 >=0 && nums[i-1] >= nums[i])
        {
            i--;
        }
        if(i == 0)
        {
            reverse(nums.begin(),nums.end());
        }
        else{
            int j = i;
            while(j<n && nums[j] > nums[i-1]) j++;
            int tmp = nums[j-1];
            nums[j-1] = nums[i-1];
            nums[i-1] = tmp;
            reverse(nums.begin() + i,nums.end());
        }
    }
};