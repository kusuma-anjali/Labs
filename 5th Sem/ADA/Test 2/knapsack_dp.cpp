#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int w[10],v[10],n,c,mat[10][10];
    cout<<"enter the no of bags"<<endl;
    cin>>n;
    cout<<"enter the weight matrix"<<endl;
    for(int i=0;i<n;i++)
        cin>>w[i];
    cout<<"enter the values matrix"<<endl;
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"enter the capacity"<<endl;
    cin>>c;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
        {
            if(i==0||j==0)
                mat[i][j]=0;
            else if(j-w[i-1]>=0)
                mat[i][j]=std::max(mat[i-1][j],(v[i-1]+mat[i-1][j-w[i-1]]));
            else
                mat[i][j]=mat[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<"the value is "<<mat[n][c];
    return 0;

}
