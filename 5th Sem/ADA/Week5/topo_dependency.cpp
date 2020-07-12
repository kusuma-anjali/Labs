#include<iostream>
using namespace std;

int main()
{
    int n,flag[20],adj[30][30]={0},indeg[20],tasks[50],count = 0;
    cout<<"enter the number of tasks "<<endl;
    cin>>n;
    cout<<"enter the tasks"<<endl;
    for(int i=0;i<(2*n);i++)
    {
        cin>>tasks[i];
    }

    for(int i=0;i<(2*n);i+=2)
    {
        adj[tasks[i+1]][tasks[i]]=1;
    }

    for(int i=0;i<n;i++)
    {
      flag[i]=0;
      indeg[i]=0;
    }

    for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
         {
            if(adj[i][j]==1)
            {
                indeg[j]++;
            }
         }
    }

    while(count<n)
    {
        for(int k=0;k<n;k++)
        {
            if(indeg[k]==0 && flag[k]==0)
            {
                cout<<k<<endl;
                flag[k]=1;
                count++;
            }
            for(int i=0;i<n;i++)
            {
                if(adj[k][i]==1)
                {
                    indeg[i]--;
                }
            }
        }
    }
    return 0;

}
