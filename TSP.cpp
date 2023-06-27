#include<bits/stdc++.h>

using namespace std;

#define maxn 30

int f[maxn],a[maxn][maxn],d[maxn],vertexCount,edgeCount;
long long min1,k[600000][20][20];
void process()
{
    long long ans=0;
    for(int i=1;i<vertexCount;i++) ans=ans+a[f[i]][f[i+1]];
    min1=min(min1,ans+a[f[vertexCount]][f[1]]);
}

void permutation(int x)
{
    if(x==vertexCount+1)
    {
        process();
        return ;
    }
    for(int i=1;i<=vertexCount;i++)
    {
        if(d[i]==true) continue;

        f[x]=i;d[i]=true;
        permutation(x+1);d[i]=false;
    }
}

void solutionOne()
{
    min1=1000000000000000;
    permutation(1);
    cout<<min1<<endl;
}

long long qhd(int x,int st,int fn)
{
    if(k[x][st][fn]!=-1) return k[x][st][fn];

    k[x][st][fn]=1000000000000000;

    if(x==(int)(1<<vertexCount)-1)
        return k[x][st][fn]=a[fn][st];

    for(int i=0;i<vertexCount;i++)
    {
        int u=(x>>i)&1;
        if(u==0) k[x][st][fn]=min(k[x][st][fn],qhd(x+(int)(1<<i),st,i+1)+a[fn][i+1]);
    }

    return k[x][st][fn];
}

void solutionTwo()
{
    memset(k,-1,sizeof(k));
    cout<<qhd(1,1,1)<<endl;
}

int main()
{
    freopen("TSP.INP","r",stdin);
    freopen("TSP.OUT","w",stdout);

    cin>>vertexCount>>edgeCount;

    for(int i=1;i<=vertexCount;i++)
        for(int j=1;j<=vertexCount;j++) a[i][j]=1000000000;

    for(int i=1;i<=edgeCount;i++)
    {
        int nodeX,nodeY,value;cin>>nodeX>>nodeY>>value;
        edge[nodeX][nodeY]=value;edge[nodeY][nodeX] = value;
    }

    solutionOne();
    solutionTwo();

}
