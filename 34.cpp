class Solution {
public:
    template <class ITERATOR>
    ITERATOR fake_lower_bound(ITERATOR begin, ITERATOR end, int target)
    {
        int l = end - begin;
        if(l == 0) return begin;
        if(l == 1) return begin;
        ITERATOR mid = begin + (l-1)/2;//very important 
        if(target <= *mid)
        {
            return fake_lower_bound(begin,mid+1, target);
        }
        else
        {
            return fake_lower_bound(mid+1,end,target);    
        }
    }
    template <class ITERATOR>
    ITERATOR upper_bound(ITERATOR begin, ITERATOR end, int target)
    {
        int l = end - begin;
        if(l == 0) return begin;
        if(l == 1) return begin;
        ITERATOR mid = begin + l/2;// very important mind the difference
        if(target < *mid)
        {
            return upper_bound(begin,mid, target);
        }
        else
        {
            return upper_bound(mid,end,target);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        auto low = fake_lower_bound(nums.begin(),nums.end(),target);
        auto hi = upper_bound(nums.begin(),nums.end(),target);
        if(*low == target && *hi == target)
        {
            return {low-nums.begin(),hi-nums.begin()};
        }
        else 
        {
            return {-1,-1};
        }
    }
};