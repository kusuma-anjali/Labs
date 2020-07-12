#include<iostream>

using namespace std;

int c,w[20],v[20],n,mat[20][20];

void knapsack(int w[],int v[],int c)
{
    for(int i=0;i<=n;i++)
    {
        mat[i][0]=0;
    }
    for(int j=0;j<=c;j++)
    {
        mat[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if((j-w[i-1])>=0)
            {
                mat[i][j] = mat[i-1][j]>(v[i-1]+mat[i-1][j-w[i-1]]) ? mat[i-1][j] : (v[i-1]+mat[i-1][j-w[i-1]]);
            }
            else
            {
                mat[i][j] = mat[i-1][j];
            }
        }
    }
    cout<<mat[n][c]<<endl;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    cout<<"enter the capacity of the bag"<<endl;
    cin>>c;
    cout<<"enter the number of coins"<<endl;
    cin>>n;
    cout<<"enter the weights of coins"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    cout<<"enter the values of coins"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    knapsack(w,v,c);

    return 0;
}
