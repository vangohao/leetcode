class Solution {
public:
    template <class ITERATOR>
    ITERATOR bs(ITERATOR begin, ITERATOR end,ITERATOR endofvector, int target)
    {
        int l = end - begin;
        if(l == 0)
            return endofvector;
        if(l == 1)
        {
            return target == * begin ? begin : endofvector;
        }
        if(*begin == target) return begin;
        ITERATOR mid = begin + l/2;
        if(*mid == target) return mid;
        if(*begin >= *mid)
        {
            if(*begin >= target && *mid <= target)
            {
                return bs(mid,end,endofvector,target);
            }
            else
            {
                return bs(begin,mid,endofvector,target);
            }
        }
        else
        {
            if(*begin <= target && target <= *mid)
            {
                return bs(begin,mid,endofvector,target);
            }
            else
            {
                return bs(mid,end,endofvector,target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        auto x = bs(nums.begin(),nums.end(),nums.end(),target);
        return x==nums.end()? -1 : x-nums.begin();
    }
};