#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
#include<cstdlib>
#include<cstring>


using namespace std;

class PhoneBook
{
    long long int number;
    char name[20];
public:

     void addContact();
     long long int searchContact(char searchName[20]);
     void displayContact();


};

void PhoneBook::displayContact()
{
    cout<<setiosflags(ios::left)<<setw(10)<<name<<setw(10)<<setiosflags(ios::left)<<setw(10)<<number<<endl;
}


void PhoneBook::addContact()
{
    cout<<"Enter Name: "; cin>>name;
    cout<<"Enter Number: "; cin>>number;
}

long long int PhoneBook::searchContact(char searchName[20])
{
    // Name
    if(!strcmp(name, searchName))
       {
        return number;
       }
    else
    {
     return 0;

    }
}

void adding()
{
    system("CLS");

    long long int val;
    char * searchName;
    fstream contact;
    int choice;
    char ch;
    char exit;
    PhoneBook p;
    contact.open("phoneyes.txt", ios::in | ios::out | ios::binary | ios::app);


cout<<"\nAdd Contact\n\n";

     do{
    p.addContact();
    contact.write(reinterpret_cast<char *>(&p), sizeof(p));

    cout<<"\n Add more: "; cin>>ch;
    ch=(char)tolower(ch);
} while(ch!='n');




}

void display()
{
    system("CLS");

       long long int val;
    char* searchName;
    fstream contact;
    int choice;
    char ch;
    char exit;
    PhoneBook p;
    contact.open("phoneyes.txt", ios::in | ios::out | ios::binary | ios::ate);

    contact.clear();
    contact.seekg(0);
cout<<setiosflags(ios::left)<<setw(10)<<"Name"<<setw(10)<<setiosflags(ios::left)<<setw(10)<<"Number"<<endl<<endl;

    while(true)
    {
        contact.read(reinterpret_cast<char *> (&p), sizeof(p));
        if(contact.eof())
            break;
        p.displayContact();
    }


}

void searching()
{
    long long int val=0;
    char searchName[20];
    fstream contact;
    int choice;
    char ch;
    char exit;
     PhoneBook p;
    contact.open("phoneyes.txt", ios::in | ios::out | ios::binary | ios::ate);



    cout<<"\nEnter the name: "; cin>>searchName;
    cout<<"\n\nSearching\n\n";
    contact.clear();
    contact.seekg(0);

while(true)
{
    contact.read(reinterpret_cast<char *>(&p), sizeof(p));
    if (contact.eof())
        break;
    val=p.searchContact(searchName);
    if(val!=0)
    {
    cout<<searchName<<" "<<val<<endl;

    }
}

}

void totalObjets()
{
     long long int val;
    char* searchName;
    fstream contact;
    int choice;
    char ch;
    char exit;
    PhoneBook p;
    contact.open("phoneyes.txt", ios::in | ios::out | ios::binary | ios::ate);

    contact.seekg(0, ios::end);

int mem=contact.tellg();
cout<<"Total Memory: "<<mem;

cout<<"\nTotal Objects: "<<mem/sizeof(PhoneBook);

}


void selection()
{
    long long int val;
    char* searchName;
    fstream contact;
    int choice;
    char ch;
    char exit;
     PhoneBook p;
    contact.open("phoneyes.txt", ios::in | ios::out | ios::binary | ios::ate);


int object, location;

cout<<"\n\nSelect a Contact to be changed. Select object number. 1 for first; 2 for second...likewise\n\n";cin>>object;

location=(object-1)*sizeof(PhoneBook);
contact.seekg(location);

p.addContact();

contact.write(reinterpret_cast<char *>(&p), sizeof(p));
}

int main()
{
    char ch;
    int choice;



do{
    system("CLS");


    cout<<"1 Add Contact\n"
        <<"2 Display Contact\n"
        <<"3 Search Contact\n"
        <<"4 Modify Contact\n"
        <<"5 Quit\n\n"
        <<"Chose One: "; cin>>choice;


        switch(choice)
        {
            case 1:
            adding();
            cin.get(ch);
            cin.ignore();

            break;
            case 2:
            display();
            cin.get(ch);
            cin.ignore();
            break;

            case 3:
            display();
            searching();
            cin.get(ch);
            cin.ignore();
            break;

            case 4:
            display();
            cout<<"\n\n";
            totalObjets();
            selection();
            cin.get();
            cin.ignore();
              display();
              cin.get();
            cin.ignore();
            break;

            case 5:
            cout<<"\n\nQuiting\n\n";
            cin.get(ch);
            cin.ignore();
            exit(0);

            default:
            cout<<"\n\nWrong Input\n\n";
            break;

        }

}while(true);
}
