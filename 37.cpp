class Solution {
public:
    int row[9][10]={};
    int col[9][10]={};
    int block[3][3][10]={};
    pair<int,int> next(pair<int,int> x)
    {
        if(x.second == 8 && x.first < 8)
        {
            return make_pair(x.first + 1,0);
        }
        else if(x.second< 8 && x.first <= 8)
        {
            return make_pair(x.first, x.second + 1);
        }
        else return make_pair(9,9);
    }
    int dfs(int x, int y ,vector<vector<char>>& board)
    {
        pair<int,int> x1 = next(make_pair(x,y));
        while(x1!=make_pair(9,9) && board[x1.first][x1.second] != '.')
        {
            x1 = next(x1);
        }
        for(int i = 1; i<=9; ++i)
        {
            if(row[x][i] == 0 && col[y][i]==0 && block[x/3][y/3][i] == 0)
            {
                board[x][y] = '0'+i;
                row[x][i] = 1;
                col[y][i] = 1;
                block[x/3][y/3][i] = 1;
                if(x1 == make_pair(9,9)) return 1;
                int tmp = dfs(x1.first,x1.second,board);
                if(tmp == 1)
                {
                    return 1;
                }
                else
                {
                    board[x][y] = '.';
                    row[x][i] = 0;
                    col[y][i] = 0;
                    block[x/3][y/3][i] = 0;
                }
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9;i++)
        for(int j = 0; j<9;j++)
        {
            if(board[i][j]!='.')
                {
                    row[i][board[i][j] - '0'] = 1;
                    col[j][board[i][j] - '0'] = 1;
                    block[i/3][j/3][board[i][j] - '0'] = 1;
                }
        }
        pair<int,int> x1 = make_pair(0,0);
        while(x1!=make_pair(9,9) && board[x1.first][x1.second] != '.')
        {
            x1 = next(x1);
        }
        if(x1==make_pair(9,9))
            return;
        else dfs(x1.first,x1.second,board);
    }
};