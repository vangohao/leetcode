class Solution {
public:
    template <class ITERATOR>
    ITERATOR upper_bound(ITERATOR begin, ITERATOR end, int target)
    {
        int l = end - begin;
        if(l == 0) return begin;
        if(l == 1) return begin;
        if(l == 2){
            if(*(begin+1) == target) return begin+1;
            else if(*(begin) == target) return begin;
            else if(*begin < target) return begin+1;
            else return begin;
        }
        ITERATOR mid = begin + l/2;// very important mind the difference
        if(target < *mid)
        {
            return upper_bound(begin,mid + 1, target);
        }
        else
        {
            return upper_bound(mid,end,target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        if(target > *nums.rbegin()) return nums.size();
        auto x = upper_bound(nums.begin(),nums.end(),target);
        return x - nums.begin();
    }
};