#include<iostream>
#include<stdlib.h>

using namespace std;

int x[10],n,mat[20][20];

bool place(int k,int i)
{
    for(int j=0;j<k;j++)
    {
        if((x[j]==i) || (abs(x[j]-i)==abs(j-k)))
        {
            return 0;
        }
    }
    return 1;
}
void display(int x[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==x[i])
                cout<<1;
            else
                cout<<0;
        }
        cout<<endl;
    }

}

void Nqueen(int k,int n)
{
    for(int i=0;i<n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==(n-1))
            {
                display(x);
                cout<<endl;
            }
            else
            {
                Nqueen(k+1,n);
            }
        }
    }
}

int main()
{
    cout<<"enter number of queens";
    cin>>n;
    Nqueen(0,n);
    return 0;

}

