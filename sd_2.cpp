#include<iostream>
using namespace std;
#include<conio.h>
#include<stdlib.h>


 typedef struct bst
  {
   int data;
   int lth,rth;
   struct bst *left,*right;
  }node;

class thread
{
  private:

  node *dummy;
  node *New,*root,*temp,*parent;
 public:
 thread();
 void create(); //All The implementation Details are hidden!
 void display();
 void find();

};

thread::thread()
{
 root=NULL;
}


void thread::create()
{
  void insert(node *,node *);
  New=new node;
  New->left=NULL;
  New->right=NULL;
  New->lth=0;
  New->rth=0;
  cout<<"\n Enter The Element ";
  cin>>New->data;
  if(root==NULL)
  {                                      // Tree is not Created
   root=New;
   dummy=new node;
   dummy->data=-999;
   dummy->left=root;
   root->left=dummy;
   root->right=dummy;
  }
  else
  insert(root,New);
}


void thread::display()
{
  void inorder(node *,node *dummy);
  if(root==NULL)
            cout<<"Tree Is Not Created";
  else
            {
               cout<<"\n The Tree is : ";
               inorder(root,dummy);
            }
}


void thread::find()
{
  node *search(node *,node *,int,node **);
  int key;
  cout<<"\n Enter The Element Which You Want To Search";
  cin>>key;
  temp=search(root,dummy,key,&parent);
  if(temp==NULL)
   cout<<"\nElement is Not Present";
  else
    cout<<"elemeny present";
   //cout<<" It's Parent Node is "<<parent->data;
}


void insert(node *root,node *New)
{
  if(New->data<root->data)
   {
             if(root->lth==0)
              {
                        New->left=root->left;
                        New->right=root;
                        root->left=New;
                        root->lth=1;
             }
             else
                        insert(root->left,New);
  }
  if(New->data>root->data)
  {
            if(root->rth==0)
            {
                        New->right=root->right;
                        New->left=root;
                        root->rth=1;
                        root->right=New;
            }
            else
             insert(root->right,New);
  }
}



node *search(node *root,node *dummy,int key,node **parent)
{
  node *temp;
  int flag=0;
  temp=root;
  while((temp!=dummy))
  {
   if(temp->data==key)
   {
            cout<<"\n The "<<temp->data<<" Element is Present";
            flag=1;
            return temp;
  }
   *parent=temp;
   if(temp->data>key)
            temp=temp->left;
   else
            temp=temp->right;
  }
return NULL;
}



void inorder(node *temp,node *dummy)
{
   while(temp!=dummy)
   {
            while(temp->lth==1)
             temp=temp->left;
   cout<<"  "<<temp->data;
   while(temp->rth==0)
   {
   temp=temp->right;
            if(temp==dummy)
             return;
            cout<<"  "<<temp->data;
   }
   temp=temp->right;
  }
 }

 int main()
{
   int choice;
   char ans='N';
   thread th;

   do
   {

            cout<<"\n\t Program For Threaded Binary Tree";
            cout<<"\n1.Create \n2.Display \n3.Search \n4.exit";
            cin>>choice;
            switch(choice)
            {
              case 1:do
                                    {
                                      th.create();
                                       cout<<"\n Do u Want To enter More  Elements?(y/n)";
                                       cin>>ans;
                                    }while(ans=='y');
                                    break;
             case 2:th.display();
                                    break;
             case 3:th.find();
                                    break;
             case 4:exit(0);
                           break;

            }
   cout<<"\n\nWant To See Main Menu?(y/n)";
   cin>>ans;
   }while(ans=='y');
   return 0;
}
