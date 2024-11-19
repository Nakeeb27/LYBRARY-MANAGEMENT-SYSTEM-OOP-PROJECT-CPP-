///STUDENT DATABASE MANAGEMENT SYSTEM
///Developed BY << TEAM  HYPOCRITE>>
///NAKEEB(2109016)
///Date: 07-04-2024

#include<iostream>
#include<stdbool.h>
#include<windows.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
using namespace std;

///global boolean attribute
float credit[10];
bool is= true;
bool isrun= true;

///Declared function
void exit(); ///To Exit the program
void userguid();///Details for user guidense
void authority(); ///To maintain authority work
string space(int,int);
void changepass();///Friend Function of autho class

class details
{
public:
    string batch;
    string serial;
    string serial1;
    string roll;
    string name;
    string email;
    string phone;
    string fname;
    string mname;
    void getdet() ///to get Information from user
    {
        cout<<"\t\t\tEnter Student information: "<<endl;
        cin.ignore();
        cout<<"\t\t\tName(30): ";
        getline(cin,name);
        cout<<"\t\t\tBatch(2K **): ";
        getline(cin,batch);
        cout<<"\t\t\tSerial(***): ";
        getline(cin,serial);
        cout<<"\t\t\tEmail(30): ";
        getline(cin,email);
        cout<<"\t\t\tPhone(11): ";
        getline(cin,phone);
        cout<<"\t\t\tFather Name(30): ";
        getline(cin,fname);
        cout<< "\t\t\tMother Name(30): ";
        getline(cin,mname);
        if(serial.size()==1)
        {
            string zero1="00";
            serial1=zero1+serial;
        }
        else if(serial.size()==2)
        {
            string zero="0";
            serial1=zero+serial;
        }
        else
        {
            serial1=serial;
        }
        roll = batch+ serial1;
    }
    void savedet() /// To save this in FILE
    {
        ofstream file;
        file.open("Stu Data.txt",ios::out|ios::app);
        file<<roll<<" | "<<name<<space(name.length(),30)<<" | "<<phone<<" | "<<email<<space(email.length(),30)<<" | "
        <<fname<<space(fname.length(),30)<<" | "<<mname<<space(mname.length(),30)<<" | "<<endl;
        file.close();
    }
};

class result
{
public:
    string c_name;///course name
    int c_number; ///number of course
    float t_credit;
    float mark[10];
    float gpa;
    float sum;
    void course_detail()
    {
        system("cls");
        cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
        cout<<"\t\t\tEnter The number of courses: ";
        cin>>c_number;
        ofstream file;
        file.open("Result.txt", ios::out|ios::app);
        file<<"Roll  | ";
        for (int i=0; i<c_number;i++)
        {
            cin.ignore();
            cout<<"\t\t\t["<<i<<"] course name: ";
            cin>>c_name;
            cin.ignore();
            cout<<"\t\t\t["<<i<<"] course credit: ";
            cin>>credit[i];
            file<<c_name<<" | ";
        }
        file<<"GPA  |"<<endl<<endl;
        file.close();
    }

};

class stud: public details,virtual public result
{
public:
    int exist(string roll)
    {
        int coun=0;
        string line;
        ifstream file;
        file.open("Stu Data.txt");
        char temp[6];
        while(getline( file , line ))
        {
            line.copy(temp,5,0);
            cout<<temp<<endl;
            if (roll==temp)
            {
                coun++;
            }
        }
        file.close();
        return coun;
    }
};

class autho: public stud, virtual public result
{
private:
    string password;
public:
    void addstudent()
    {
        system("cls");
        cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
        cout<<"\t\t\tHow many student do you want to add: ";
        int ammount;
        cin>>ammount;
        for(int i=0;i<ammount;i++)
        {
            system("cls");
            system("color 17");
            cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
            getdet();
            cout<< "\t\t\tTo save press s: ";
            string optn;
            getline(cin,optn);
            if(optn[0]=='s'||optn[0]=='S')
            {
                if(exist(roll)==0)
                {
                    savedet();
                    cout<<"\t\t\tData is saved successfully."<<endl;
                }
                else
                {
                    cout<<"\t\t\tThis Serial in this Batch already exist:"<<endl;
                }
            }
        }
        getch();
    }

    void showall()
    {
        system("cls");
        system("color 17");
        cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
        string data;
        ifstream file;
        file.open("Stu Data.txt");
        while(getline(file,data))
        {
            cout<<data<<endl;
        }
        file.close();
        getch();

    }

    void course_result()
    {
        system("cls");
        cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
        ofstream file;
        file.open("Result.txt", ios::out|ios::app);
        cout<<"\t\t\tEnter roll: ";
        cin>>roll;
        sum=0;
        t_credit=0;
        int l=exist(roll);
        if (l>0)
            {
                file<<roll<<" | ";
                cout<<"\t\t\tEnter GPA for"<<endl;
                for(int i=0 ; i<c_number ; i++)
                {
                    cout<<"\t\t\tcourse "<<i+1<<" : ";
                    cin>>mark[i];
                    file<<mark[i]<<" | ";
                    sum= sum + (mark[i]*credit[i]);
                    t_credit=t_credit+credit[i];
                }
                gpa=sum/t_credit;
                file<<showpoint<<setprecision(3)<<gpa<<" | "<<endl;
            }
            else
            {
                cout<<"\t\t\tThis roll doesn't EXIST."<<endl;
                cout<<"\t\t\tPlease Enter the existed roll."<<endl;
                Sleep(500);
                course_result();
            }
            cout<<"\t\t\tPress  y to add more: ";
            string choice;
            cin.ignore();
            getline(cin,choice);
            if(choice[0]=='y'||choice[0]=='Y')
            {
               course_result();
            }
            file.close();
        }

    void addresult()
    {
        course_detail();
        course_result();
        getch();
    }

    void sroll()
    {
        system("cls");
        cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
        cout<<"\t\t\tEnter student roll: ";
        string Roll;
        cin.ignore();
        getline(cin,Roll);
        int count=0;
        string line;
        string line1;
        ifstream file;
        file.open("Stu Data.txt");
        char temp[60];
        while(getline(file,line))
        {
            line.copy(temp,5,0);
            if (Roll==temp)
            {
                cout<<"\t\t\t\tInformation:"<<endl<<endl;
                line.copy(temp,30,7);
                cout<<"\t\t\tName       : "<<temp<<endl;
                line.copy(temp,2,0);
                cout<<"\t\t\tBatch      : 2k"<<temp<<endl;
                line.copy(temp,11,41);
                cout<<"\t\t\tPhone      : "<<temp<<endl;
                line.copy(temp,30,55);
                cout<<"\t\t\tEmail      : "<<temp<<endl;
                line.copy(temp,30,88);
                cout<<"\t\t\tFather Name: "<<temp<<endl;
                line.copy(temp,30,121);
                cout<< "\t\t\tMother Name: "<<temp<<endl;
                ifstream res;
                res.open("Result.txt");
                cout<<endl<<"\t\t\t\tResult : "<<endl<<endl;
                int i=0;
                while(getline(res,line1))
                {
                    line1.copy(temp,5,0);
                    if(i==0)
                    {
                        cout<<"\t\t"<<line1<<endl;
                        i++;
                    }
                    if (Roll==temp)
                    {
                        cout<<"\t\t"<<line1<<endl;
                    }
                }
                res.close();
                count++;
            }
        }
        file.close();
        if(count==0)
        {
            cout<<"\t\t\tThis Roll doesn't EXIST.";
        }
        getch();
    }

    void delete_rec()
    {
        system("cls");
        cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
        string Roll;
        int count=0;
        char temp[60];
        string line;
        string record;
        string newline="\n";
        ofstream trash;
        ifstream file;

        cout<<"\t\t\tEnter student roll: ";
        cin.ignore();
        getline(cin,Roll);
        file.open("Stu Data.txt");
        trash.open("Trash.txt",ios::out|ios::app);
        while(getline(file,line))
        {
            line.copy(temp,5,0);
            if (Roll==temp)
            {
                count++;
                trash<<line;
                continue;
            }
            record=record+newline+line;
        }
        file.close();
        trash.close();

        trash.open("Stu Data.txt");
        trash<<record;
        trash.close();

        if(count==0)
        {
            cout<<"\t\t\tThis Roll doesn't EXIST.";
        }
        else
        {
            cout<<"\t\t\tDeleted Successfully";
        }
        record="\0";
        getch();
    }

    void edit_student()
    {
        system("cls");
        cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
        string Roll;
        int count=0;
        char temp[60];
        string line;
        string record;
        string newline="\n";
        string S=" | ";
        ofstream trash;
        ifstream file;

        cout<<"\t\t\tEnter student roll: ";
        cin.ignore();
        getline(cin,Roll);
        file.open("Stu Data.txt");
        while(getline(file,line))
        {
            line.copy(temp,5,0);
            if (Roll==temp)
            {
                getdet();
                roll=Roll;
                line=roll+S+name+space(name.length(),30)+S+phone+S+email+space(email.length(),30)
                    +S+fname+space(fname.length(),30)+S+mname+space(mname.length(),30)+S;
                    count++;

            }
            record=record+newline+line;
        }
        file.close();
        trash.open("Stu Data.txt");
        trash<<record;
        trash.close();

        if(count==0)
        {
            cout<<"\t\t\tThis Roll doesn't EXIST.";
        }
        record="\0";
        getch();
    }
    friend void changepass();
};

void changepass()
{
    system("cls");
    ofstream file;
    file.open("Authpass.txt");
    autho iam;
    cout<<"\t\t\tEnter your New Password: ";
    getline(cin,iam.password);
    system("cls");
    string temp;
    cout<<"\t\t\tAgain Enter your New Password: ";
    getline(cin,temp);
    if(iam.password==temp)
    {
        file<<iam.password;
        file.close();
        cout<<"\t\t\tPassword is changed successfully."<<endl;
        getch();
    }
    else
    {
        cout<<"\t\t\tYour password didn't match.\n\t\t\tPlease Try again.";
        changepass();
    }
}

void userguid()
{
    system("cls");
    cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
    cout<<"\t\t\tName should be in between 30 letters."<<endl;
    cout<<"\t\t\tEmail should be in between 30 letters."<<endl;
    cout<<"\t\t\tRoll should be in between 5 letters.\n\t\t\tFirst Two letters is Batch.\n\t\t\tNext 3 letters is serial\n";
    cout<<"\t\t\tPhone Number Must be in 11 digit."<<endl;
    getch();
}

string space(int m, int n)
{
    int s=abs(m-n);
    string word;
    for(int i=0;i<s;i++)
    {
        word= word+' ';
    }
    return word;
}

void exit()
{
    system("color 47");
    cout<<"\t\t\tAre You Sure Want to Exit? (Y,N): ";
    char choice;
    cin>>choice;
    if(choice == 'Y' || choice == 'y')
    {
        system("cls");
        char welcoming[500] = "\t\t\t   Application is developed by TEAM HYPOCRITE.\n\t\t\t\t   =======Thank You======\n\
        \t\t\t   =====See You Soon=====\n";
        int i=0;
        for(i=0;i<strlen(welcoming);i++)
        {
            system("color 47");
            cout<<welcoming[i];
            Sleep(40);
        }
        is=false;
        isrun=false;
    }
}

void authority() ///Only authority can access such a function or objects
{
    system("cls");
    system("color 17");
    string pass1;
    cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
    cout<<"\t\t\tEnter your Password: ";
    getline(cin,pass1);

    ifstream file;
    file.open("Authpass.txt");
    string pass;
    getline(file,pass);
    file.close();

    if(pass==pass1)
    {
        while(isrun==true)
        {
            system("cls");
            system("color 17");
            cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
            cout<<"\t\t\t\tAUTHORITY MENU"<<endl;
            cout<<"\t\t\t==========================="<<endl;
            cout<<"\t\t\t[1]Add student."<<endl;
            cout<<"\t\t\t[2]Edit student details."<<endl;
            cout<<"\t\t\t[3]Show all student."<<endl;
            cout<<"\t\t\t[4]Add students result."<<endl;
            cout<<"\t\t\t[5]Search student By Roll."<<endl;
            cout<<"\t\t\t[6]Delete student record."<<endl;
            cout<<"\t\t\t[7]Change Password."<<endl;
            cout<<"\t\t\t[8]Back to main menu"<<endl;
            cout<<"\t\t\t[9]User Guidline."<<endl;
            cout<<"\t\t\t[0]EXIT"<<endl<<endl;
            autho iam;
            int n;
            cout<<"\t\t\tEnter the choice: ";
            cin>>n;
            switch(n)
            {
            case 1:
                iam.addstudent();
                break;
            case 2:
                iam.edit_student();
                break;
            case 3:
                iam.showall();
                break;
            case 4:
                iam.addresult();
                break;
            case 5:
                iam.sroll();
                break;
            case 6:
                iam.delete_rec();
                break;
            case 7:
                changepass();
                break;
            case 8:
                isrun=false;
                is =true;
                break;
            case 9:
                userguid();
                break;
            case 0:
                exit();
                break;
            default:
                cout<<"\t\t\tPlease try again .  .  ."<<endl;
                Sleep(500);
                break;
            }
        }
    }

    else
      {
        cout<<"\t\t\tYour Password is wrong"<<endl;
        Sleep(500);
      }
}

int main()
{
    cout<<endl<<endl<<endl<<"\t\t\t";
    char AppStarting[100] = "Application is Starting....";
    for(int i=0;i<strlen(AppStarting);i++)
    {
        cout<<AppStarting[i];
        Sleep(50);
    }

    while(is==true)
    {
        system("cls");
        system("color 17");
        cout<<endl<<"\t\t------STUDENT DATABASE MANAGEMENT SYSTEM------"<<endl<<endl;
        cout<<"\t\t\t\tMAIN MENU"<<endl;
        cout<<"\t\t\t====================="<<endl;
        cout<<"\t\t\t[1]Authority LogIn"<<endl;
       /// cout<<"\t\t\t[2]Students LogIn"<<endl;
        cout<<"\t\t\t[0]EXIT"<<endl<<endl;
        string n;
        cout<<"\t\t\tEnter the choice: ";
        getline(cin,n);
        switch(n[0])
        {
        case '1':
            authority();
            isrun=true;
            break;
        case '0':
            exit();
            getch();
            break;
        default:
           cout<<"\t\t\tPlease try again .  .  ."<<endl;
           Sleep(500);
            break;
        }
    }
}
