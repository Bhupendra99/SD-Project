#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
void show();
void admin();
void exi();
void main_loges();
void winner();
void voting();
void stop();
void not_again();
void voter_insert();
typedef struct voter_information
{
	char id[10];
	char name[20];
	char birth_date[20];
	char father_name[20];
	char mother_name[20];
	struct voter_information *next;
}node;

node *head;
int count1=0,count2=0,count3=0,count4=0,count5=0;
void show()
{
	system("cls");
	//cout<<"\n\n\n";
	cout<<"\t\t\t Who Got How Many Votes??\n";
	Sleep(500);
	cout<<"\n\nRam Got %d votes:",count1;
	Sleep(500);
		cout<<"\n\nSham Got %d votes:",count2;
	Sleep(500);
		cout<<"\n\nRamu Got %d votes:",count3;
	Sleep(500);
		cout<<"\n\nShamu Got %d votes:",count4;
	Sleep(500);
		cout<<"\n\nGhansham Got %d votes:",count5;
	Sleep(500);

	int r;
	cout<<"\t\t\tEnter 1 For Main Loges Or \n\n\t\t\t 0 for Exit";
	cin>>r;
	if(r==1)
	{
		main_loges();
	}
	else
	{
		exi();
	}

}
void admin()
{
	int b;
	cout<<"\n\n\n\n";
	cout<<"\t\t\tEnter Password To Unlock Admin Panel ";
	cin>>b;
	if(b==1111)
	{
		show();
	}
	else
	{
		cout<<"Wrong Password\n";
	}
}





void exi()
{
	system("cls");
	cout<<"\n\n\n";

	cout<<"----------You Have Given Your Vote Successfully----------!! ";
	Sleep(500);

	cout<<"-------------------Thank You---------------------!!";
	Sleep(500);

}

void main_loges()
{

	system("cls");

	cout<<"\n\n\n";
	cout<<"\t\t\t1.                 For vote entry              -------------------------\n ";
	Sleep(300);

	cout<<"\t\t\t2.                 For Admin panel             -------------------------\n ";
	Sleep(300);

	cout<<"\t\t\t3.                 For Winner              -------------------------\n ";
	Sleep(300);

	cout<<"\t\t\t4.                 For Exit            -------------------------\n ";
	Sleep(300);

	cout<<"\t ...................... Press 1 To Enter Your Vote............\n";
	Sleep(500);

	int t;

	cin>>t;

	if(t==1)
	{
		voter_insert();
	}
	if(t==2)
	{
		admin();
	}
	if(t==3)
	{
		winner();
	}
	if(t==4)
	{
		exi();
	}

}

int main()
{
	system("cls");

	cout<<"\n";
	cout<<"\t --------------------Welcome To Online Voting System---------------------\n\n";
	cout<<"\t -----------------***********************************---------------------\n\n";

	cout<<"\t\t -----------------Press ( 1 )for Login into Vote main loges---------------------\n\n";

	int b;
	cin>>b;
	if(b==1)
	{
		main_loges();
	}

return 0;
}


void winner()
{
	system("cls");
	cout<<"\n\n\n\n";
	if(count2 < count1 && count3<count1 && count4<count1 && count5<count1)
	{
		cout<<"Present Winner is Ram And He Got %d votes:   ",count1;
	}

	if(count1 < count2 && count3<count2 && count4<count2 && count5<count2)
	{
		cout<<"Present Winner is Sham And He Got %d votes:   ",count2;
	}

	if(count1 < count3 && count2<count3 && count4<count3 && count5<count3)
	{
		cout<<"Present Winner is Ramu And He Got %d votes:   ",count3;
	}

	if(count1 < count4 && count2<count4 && count3<count4 && count5<count4)
	{
		cout<<"Present Winner is Shamu And He Got %d votes:  ",count4;
	}

	if(count1 < count5 && count2<count5 && count3<count5 && count4<count5)
	{
		cout<<"Present Winner is Ghamsham And He Got %d votes:  ",count5;
	}

	int t;
	cout<<" Enter One 1 For MainLoges Or \t\t Zero (0) For Exit\n";
	cin>>t;
	if(t==1)
	{
		main_loges();
	}

	if(t!=1)
	{
		exi();
	}
}



void voting()
{
	system("cls");
	cout<<"\n\n\n";
	cout<<"**********************List Of Candidates**********************\n\n\n";
	Sleep(300);
	cout<<"\t\t\tName--------------------Symbol\n\n";
	Sleep(300);
	cout<<"\t\t\t1.Ram---------------------Horse\n\n";
	Sleep(300);
	cout<<"\t\t\t2.Sham---------------------Elephant\n\n";
	Sleep(300);
	cout<<"\t\t\t3.Ramu---------------------Table\n\n";
	Sleep(300);
	cout<<"\t\t\t4.Shamu---------------------Donkey\n\n";
	Sleep(300);
	cout<<"\t\t\t5.Ghansham---------------------Bottle\n\n";


	int b,j;
	cout<<"\t\tEnter Your Choice";

	for(j=1;j<=1;j++)
	{
		cin>>b;
		if(b==1)
		{
			count1++;
		}
		if(b==2)
		{
			count2++;
		}
		if(b==3)
		{
			count3++;
		}
		if(b==4)
		{
			count4++;
		}
		if(b==5)
		{
			count5++;
		}
		if(b!=1 && b!=2 && b!=3 && b!=4 && b!=5)
		{
			cout<<"\t\tYour Vote IS Invalid";
			main_loges();
		}
	}
	int r;
	system("cls");

	cout<<"\n\n\n\n\n";
	cout<<"If You Want To See Present Winner Enter 1 Or\t\t\t 0 For Main Logs:  ";
	cin>>r;
	if(r==1)
	{
		winner();
	}
	if(r!=1)
	{
		main_loges();
	}

}
int cunt=0,count=0,r=3;
void stop()
{

	system("cls");

	cout<<"\n\n\n";
	cout<<"----------Sorry you can not give your vote now because your limit is exhausted!! \n\n";
	Sleep(500);

	cout<<"-----------Please try again after a few moment--------!!\n";
	Sleep(500);

	cout<<"------------------thank you--------------!!\n\n";
	Sleep(500);
}

void not_again()
{	int r;

		system("cls");
	cout<<"\n\n\n";

	cout<<"\t\t -----------------You Have Given your Vote Successfully--------!!\n\n";
	Sleep(300);

	cout<<"\t\t\t ---------------You can not give your Vote more than One time!!\n\n";
	Sleep(300);

	cout<<"\t\t\t ------If you want to See present Winner Enter one (1) or \t\t\t Two (2) for main loges!!\n\n";
	Sleep(300);


	cout<<"\t -------zero (0) for exit \n\n!! ";
	cin>>r;
	if(r==1)
	{
		winner();
	}

	if(r==2)
	{
		main_loges();
	}

	if(r==3)
	{
		exi();
	}
}

void voter_insert()
{
	node *temp;

	char name[20],birth_date[15],f_name[25],m_name[25],id[10];

	system("cls");

	cout<<"\n\n\n";
	cout<<"\t  ENTER YOUR NAME , NATIONAL ID , MOTHER NAME , FATHER NAME , BIRTHDATE \n\n";
	cout<<"\n****IF ABOVE INFORMATION MATCHES THE RECORD THEN ONLY YOU ARE ELLIGIBLE TO VOTE*****\n\n";
	Sleep(300);

	cout<<"\t\t\t If You Enter  wrong Info (3) times the program will be stopped automatically";
	Sleep(300);

	cout<<"Enter your nation id number\n:   ";
	gets(id);
    gets(id);

	cout<<"Enter your name\n";
	gets(name);

	cout<<"Enter your birth-date\n";
	gets(birth_date);

	cout<<"Enter your Father's name\n";
	gets(f_name);

	cout<<"Enter your Mother's name\n";
	gets(m_name);


	temp= new node ;

	strcpy(temp->id,id);


	strcpy(temp->birth_date,birth_date);

	strcpy(temp->father_name,f_name);

 	strcpy(temp->mother_name,m_name);

	strcpy(temp->name,name);

	temp->next=NULL;

	head=temp;

	while(temp!=NULL)
	{

	if((strcmp(temp->id,"100")==0 && strcmp(temp->name,"honey")==0 && strcmp(temp->birth_date,"28-06-1999")==0 && strcmp(temp->mother_name,"lata")==0 && strcmp(temp->father_name,"om")==0) ||

		(strcmp(temp->id,"101")==0 && strcmp(temp->name,"tanuj")==0 && strcmp(temp->birth_date,"29-06-1999")==0 && strcmp(temp->mother_name,"madhu")==0 && strcmp(temp->father_name,"jay")==0)||

		(strcmp(temp->id,"102")==0 && strcmp(temp->name,"rubal")==0 && strcmp(temp->birth_date,"30-06-1999")==0 && strcmp(temp->mother_name,"bindu")==0 && strcmp(temp->father_name,"kara")==0) )
	{

		cunt++;
		if(cunt>2)
		{
			not_again();
			break;

		}
		voting();

	}
	else
	{
		r--;
		count++;
		if(count==3)
		{
			stop();
			break;
		}
		cout<<"\n\n\n";

		cout<<"\n you have entered Wrong details\n";
		Sleep(300);

		cout<< " Please re enter\n\n ";
		Sleep(300);

		system("pause");
		main_loges();

	}

	temp=temp->next;

	}

}


