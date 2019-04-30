
#include<iostream>
#include<conio.h>
using namespace std;

class flight{

public:
        int A[3][3];

     void create()
    {   cout<<"\n ENTER TOTAL FLIGHTS FOR THE DAY 1.pune 2.mumbai 3.banglore \n";

        for(int k=1;k<=3;k++)
        {
            for(int j=1;j<=3;j++)
            {
                    cin>>A[k][j];
            }cout<<"\n";
        }
    }
    void display()
    {
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                    cout<<A[i][j]<<" ";
            }cout<<"\n";
        }
    }

    void input()
    {
        string source,destination;
        int i,j;
            cout<<"\nENTER THE SOURCE \n";
            cin>>source;
            cout<<"\nENTER THE DESTINATION\n";
            cin>>destination;

            if(source=="pune")
            {
                i=1;
            }
            else if(source=="mumbai")
            {
                i=2;
            }
            else if(source=="banglore")
            {
                i=3;
            }

             if(destination=="pune")
            {
                j=1;
            }
            else if(destination=="mumbai")
            {
                j=2;
            }
            else if(destination=="banglore")
            {
                j=3;
            }
            cout<<"\t"<<"-------------------------------------------------------------\n";
            cout<<" ";


            cout<<"\t"<<"SOURCE"<<"\t \t \t "<<"to"<<"\t \t \t"<<"DESTINATION"<<"\n";
            cout<<"\t"<<source<<"\t \t \t "<<"to"<<"\t \t \t"<<destination;

            search_value(i,j);

            cout<<"bye";
    }

   void search_value(int i,int j)
   {


   if(A[i][j]==1)
   {
       cout<<"\n \n --HELLO ATTENTION PLEASE!!\n \n AIR INDIA 123 DIRECT FLIGHT IS THERE!!\n";
       getch();
   }else{
   cout<<"\n SORRY FOR THE INCONVINIECE!\n\n CURRENTLY WE DO NOT HAVE ANY DIRECT FLIGHT FOR THIS ROUTE\n";
   getch();
   }
   }
};
int main()
{   flight f1;
        f1.create();
        f1.display();
        f1.input();

    return 0;
}
