#include<iostream>
using namespace std;

class kruskal
{
private:
    int cost[10][10],parent[10],mincost[10];
    int edges,nodes;
public:
    kruskal()
    {
        edges=nodes=0;
        for(int i=1;i<10;i++)
        {
            parent[i]=mincost[i]=0;
                for(int j=1;j<10;j++)
                {
                    cost[i][j]=999;
                }
        }

    }
    void accept();
    void display();
    int algorithm_find(int);
    void algorithm_kruskal();
    int uni(int ,int);

};

void kruskal:: accept()
{
    int v1,v2,weight;
    cout<<"\n ENTER NO OF EDGES\n";
    cin>>edges;
    cout<<"\n ENTER NO OF VERTEX \n";
    cin>>nodes;
    for(int i=1;i<=edges;i++)
    {
        cout<<"\nENTER FIRST VERTEX:\n";
        cin>>v1;
        cout<<"\n ENTER SECOND VERTEX\n";
        cin>>v2;
        cout<<"\nENTER COST OF VERTEX\t"<<v1<<"\t"<<v2<<"\n";
        cin>>weight;
        cost[v1][v2]=cost[v2][v1]=weight;
    }
}
void kruskal:: display()
{
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {   cout.width(4);
            cout<<cost[i][j]<<" ";
        }cout<<"\n";
    }
}
void kruskal::algorithm_kruskal()
{
    int ne=1,a,b,v,u,minno;
    cout<<"\n edges of minimum cost spanning tree are\n";

    while(ne<nodes)
    {
        minno=999;

        for(int i=1;i<=nodes;i++)
        {
            for(int j=1;j<=nodes;j++)
            {
                if(cost[i][j]<minno)
                {
                    minno=cost[i][j];
                    a=u=i;
                    b=v=j;

                }
            }

        }
        u=algorithm_find(u);
        v=algorithm_find(v);

        if(uni(u,v))
        {
            mincost[ne]=minno;
            cout<<"\n\t"<<ne++<<" EDGE "<<a<<" "<<b<<" "<<minno;

        }
        cost[a][b]=cost[b][a]=999;
    }
int sum=0;
    for(int i=1;i<nodes;i++)
    {
        sum=sum+mincost[i];
    }
    cout<<sum;
}

int  kruskal:: algorithm_find(int p)
{
    while(parent[p])
    {
        p=parent[p];
    }
    return p;
}

int kruskal::uni(int r,int s)
{
    if(r!=s)
    {
        parent[s]=r;
        return 1;
    }
    return 0;
}

int main()
{
     kruskal obj;
    obj.accept();
    obj.display();
    obj.algorithm_kruskal();
    return 0;
}
