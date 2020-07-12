#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n1,n2,mat[10][10],index=0,k,l;
    char s1[10],s2[10],res[10];
    cout<<"Enter the 2 strings length"<<endl;
    cin>>n1>>n2;
    for(int i=0;i<n1;i++)
        cin>>s1[i];
    for(int i=0;i<n2;i++)
        cin>>s2[i];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0||j==0)
                mat[i][j]=0;
        }
    }
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
                mat[i][j]=std::max(mat[i-1][j],mat[i][j-1]);
        }
    }
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<mat[n1][n2]<<endl;
    index = mat[n1][n2];
    res[index]='\0';
    cout<<index<<endl;
    k = n1;
    l = n2;
    while(k>0&&l>0)
    {

            if(s1[k-1]==s2[l-1])
            {
                res[index-1]=s1[k-1];
                k--;
                l--;
                index--;
            }
            else if(mat[k-1][l]>=mat[k][l-1])
                k--;
            else
                l--;

    }

        cout<<res<<endl;

    return 0;
}
