#include<iostream>
using namespace std;

int n,i,j,adj[100][100],arr[100];

void dfs(int v)
{
    cout<<v;
    arr[v]=1;
    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1 && arr[i]==0)
            dfs(i);
    }

}
int main()
{

    cout<<"Enter number of vertices in the graph: ";
    cin>>n;

    cout<<"Enter the adjacency matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>adj[i][j];
    }
    for(i=0;i<n;i++)
        arr[i]=0;

    for(i=0;i<n;i++)
        if(arr[i]==0)
            dfs(i);

    return 0;
}
