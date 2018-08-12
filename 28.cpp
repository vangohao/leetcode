class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1,l2;
        l1 = haystack.size();
        l2 = needle.size();
        int * next = new int[l2];
        next[0] = -1;
        int j = 0;
        int k = -1;
        while(j<l2-1)
        {
            if(k<0 || needle[j] == needle[k])
            {
                ++j;++k;
                next[j] = k;
            }
            else
            {
                k = next[k];
            }
        }
        int i = 0;
        j = 0;
        while( i<l1 && j<l2)
        {
            if(j==-1 || haystack[i] == needle[j])
            {
                ++i;++j;
            }
            else
            {
                j = next[j];
            }
        }
        if(j == l2)
        {
            return i-j;
        }
        else return -1;
    }
};