#include<iostream>
#include<queue>

using namespace std;

int visited[20],n,adj[50][50];

void BFS(int v)
{
    queue<int> q;
    q.push(v);
    cout<<v;
    while(!q.empty())
    {
        q.pop();
    }
    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1 && visited[i]==0)
        {
            q.push(i);
            visited[i]=1;
            cout<<i;
        }
    }
}

int main()
{
    cout<<"enter the number of verties in the graph: "<<endl;
    cin>>n;
    cout<<"Enter the adjacency matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            BFS(i);
    }

    return 0;
}
