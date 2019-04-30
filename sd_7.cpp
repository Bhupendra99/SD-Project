#include<iostream>
using namespace std;
class hashing
{
    int a[10],tab[10],i,n,h1,h,h2,j;
public:
    hashing()
    {
        for(i=0;i<=9;i++)
        {
         tab[i]=0;
        }
    }
    int accept()
    {
        cout<<"How many no you want to enter";
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        op(a);
    }
    int op(int a[])
    {
         for(i=0;i<n;i++)
         {
             h1=a[i]%10;
             if(tab[h1]==0)
             {
                 tab[h1]=a[i];
             }
             else
             {
                 h2=7-(a[i]%7);
                 for(j=0;j<9;j++)
                 {
                     h=(h1+(j+1)*h2)%10;
                     if(tab[h]==0)
                        {
                        tab[h]=a[i];
                         break;
                        }
                 }
             }

         }
         cout<<"TABLE :"<<endl;
        for(i=0;i<=9;i++)
        {
         //if(tab[i]!=0)
         cout<<tab[i]<<"\t";
        }

    }
};
int main()
{
    hashing hh;
    hh.accept();
}
