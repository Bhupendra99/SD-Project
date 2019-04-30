#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class student
{
private:
    int roll_no;
    char name[20];
    char division;
public:
    student()
    {
        roll_no=0;
        strcpy(name,"honey");
        division='a';
    }
    void getstudent_data()
    {
        cout<<"\nenter your roll no name and division\n";
        cin>>roll_no;
        cin.ignore();
        cin.getline(name,19);
        cin>>division;
    }
    void showdata()
    {
        cout<<"\n"<<roll_no<<" "<<name<<" "<<division;
    }
    int storedata();
    void view_all();
    void search_student(char *);
    void delete_record(char*);
    void update(char*);
};

void student::update(char *t)
{
    fstream file;
    long position;
    file.open("student1.dat",ios::in|ios::binary|ios::ate|ios::out);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
        {
            if(!strcmp(t,name))
            {
                getstudent_data();
                position=file.tellp();
                file.seekp(position-sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
                file.read((char*)this,sizeof(this));

        }
        file.close();
}
void student::delete_record(char *t)
{
    ifstream fin;
    ofstream fout;
   fin.open("student1.dat",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"\n file dosent exits\n";
    }else{//getch();
         fout.open("temp.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));

       while(!fin.eof())
       {
           if(strcmp(t,name))
           {
                fout.write((char*)this,sizeof(*this));
           }
                fin.read((char*)this,sizeof(*this));
       }
       fin.close();
       fout.close();
       //getch();
       remove("student1.dat");
      // getch();
       rename("temp.dat","student1.dat");
    }
}
void student::search_student(char *t)
{
    ifstream fin;
    int flag=0;
    fin.open("student1.dat",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"\n file does not exits\n";
    }
    else{

        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(t,name)){
            showdata();
            flag=1;
            }
            fin.read((char*)this,sizeof(*this));
        }
        if(flag==0)
        {
            cout<<"\n Record not found\n";
        }
        fin.close();
    }
}
void student::view_all()
{

    ifstream fin;
    fin.open("student1.dat",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"\n file not found\n";
    }else{
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
        showdata();
            fin.read((char*)this,sizeof(*this));
    }
    }
    fin.close();
}
int student::storedata()
{
    if(roll_no==0&& division=='a')
    {
        cout<<"can not enter into file";
        return (0);
    }else{
        ofstream fout;
        fout.open("student1.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return (1);
    }
}
int menu()
{       int choice;
        cout<<"\n student record\n";
        cout<<"\n 1.insert student record\n";
        cout<<"\n 2.view student records\n";
        cout<<"\n 3.search student record\n";
        cout<<"\n 4.Delete insert student record\n";
        cout<<"\n 5.update student record\n";
        cout<<"\n 6.exit\n";
        cout<<"\n\nEnter your choice\n";
        cin>>choice;
        return choice;
}
int main()
{
    student s1;
    char name[20];
    while(1)
    {
        switch(menu())
        {
            case 1: s1.getstudent_data();
                    s1.storedata();
                    cout<<"\n record entered succesfully\n";
                    break;
            case 2: s1.view_all();
                        break;

            case 3: cout<<"\n enter name to be searched\n";
                    cin.ignore();
                    cin.getline(name,19);
                    s1.search_student(name);
                    break;
            case 4:cout<<"\n enter name to be deleted\n";
                        cin.ignore();
                    cin.getline(name,19);
                    s1.delete_record(name);
                        break;
           case 5: cout<<"\n enter name to be updated\n";
                        cin.ignore();
                    cin.getline(name,19);
                    s1.update(name);
                        break;

           case 6: cout<<"\n thank you for using this app!\n";
                    exit(0);
            default:cout<<"\n invalid choice \n";

        }
    }
    return 0;
}
