class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a[10]={};
        for(int i = 0; i<9; ++i)
        {
            memset(a,0,sizeof(a));
            for(int j = 0;j<9;++j)
            {
                if(board[i][j] != '.')
                {
                    a[board[i][j] - '0'] ++;
                }
            }
            bool flag = true;
            for(int j = 1;j<=9;++j)
            {
                if(a[j]>1) {
                    flag = false;
                    break;
                }
            }
            if(!flag)
            {
                return false;
            }
        }
        for(int i = 0; i<9; ++i)
        {
            memset(a,0,sizeof(a));
            for(int j = 0;j<9;++j)
            {
                if(board[j][i] != '.')
                {
                    a[board[j][i] - '0'] ++;
                }
            }
            bool flag = true;
            for(int j = 1;j<=9;++j)
            {
                if(a[j]>1) {
                    flag = false;
                    break;
                }
            }
            if(!flag)
            {
                return false;
            }
        }
        for(int i = 0; i<3;++i)
        {
            for(int j = 0;j<3;++j)
            {
                memset(a,0,sizeof(a));
                for(int k = 3*i;k<3*i + 3;++k)
                {
                    for(int l = 3*j;l<3*j+3;++l)
                    {
                        if(board[k][l]!='.')
                            a[board[k][l] - '0'] ++;
                    }
                }
                bool flag = true;
                for(int k = 1; k<=9;++k)
                {
                    if(a[k]>1)
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                {
                    return false;
                }
            }
        }
        return true;
    }
};