#include<iostream>
#define N 9
#define SQN 3

using namespace std;

bool findlocation(int grid[N][N],int &row,int &col)
{
    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
        {
            if(grid[row][col]==0)
                return true;
        }
    }
    return false;
}


bool usedInRow(int grid[N][N], int row, int num)
{
    for(int col=0;col<N;col++)
    {
        if(grid[row][col]==num)
            return true;
    }
    return false;
}

bool usedInCol(int grid[N][N], int col, int num)
{
    for(int row=0;row<N;row++)
    {
        if(grid[row][col]==num)
            return true;
    }
    return false;
}

bool usedInBox(int grid[N][N],int row,int col,int num)
{
    for(int r=0;r<SQN;r++)
    {
        for(int c=0;c<SQN;c++)
        {
            if(grid[r+row][c+col]==num)
                return true;
        }
    }
    return false;
}

bool isSafe(int grid[N][N],int row,int col,int num)
{
    return !usedInRow(grid,row,num) && !usedInCol(grid,col,num) && !usedInBox(grid,row-(row%SQN),col-(col%SQN),num);
}

bool solveSudoku(int grid[N][N])
{
    int row,col;
    if(!findlocation(grid,row,col))
        return true;
    for(int num=1;num<=9;num++)
    {
        if(isSafe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(solveSudoku(grid))
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int grid[9][9];
    cout<<"enter the 9*9 elements"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>grid[i][j];
        }
    }
    bool ans = solveSudoku(grid);
    if(ans)
    {
        cout<<"the complete suduko is as follows"<<endl;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution exists";
    }

    return 0;
}
