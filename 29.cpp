class Solution{
    public:
    int divide(int dividend, int divisor)
    {
        int result  =0;
        int l = 30;
        int s = 1;
        if(divisor == 0) return 0;
        if(divisor == INT_MIN && dividend ==INT_MIN) return 1;
        else if(divisor == INT_MIN) return 0;
        if(divisor < 0) {divisor = -divisor;s = -1;}
        while(!(divisor & (1<<l))) l--;
        int start = 30;
        if(dividend == INT_MIN) start = 31;
        bool label = false;
        for(int i = start-l;i>=0;i--)
        {
            if(dividend >= 0)
            {
                if(dividend - (divisor << i) >= 0)
                {
                    result += 1<<i;
                    dividend -= (divisor << i);
                    if(result == INT_MAX && s==1) break;
                    if(result == INT_MIN && s==-1) {label  = true;break;}
                }
            }
            else if(dividend <0)
            {
                if(dividend + (divisor << i) <= 0)
                {
                    result -= 1<<i;
                    dividend += divisor << i;
                    if(result == INT_MIN && s==1){label  = true;break;}
                    if(result == -INT_MAX && s== -1) break;
                }
            }
        }
        if(result == INT_MIN && label==false) return INT_MAX;
        if(s==1)
            return result;
        else return -result;
    }
};