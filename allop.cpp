#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class person
{
private:
    char name[40],dob[15],bld_grp[15];
    int height,weight;
public:
    static int count;
    friend class personal;
    person()
    {
        char * name=new char[40];
        char *dob=new char[80];
        char *bdg=new char[15];
        height=weight=0;
    }

};

class personal
{
private:
    char adres[70],contact[17],policy[10];
public:
    personal()
    {
        strcpy(adres,"");
        strcpy(contact,"");
        strcpy(policy,"");
    }
    void get_data(person *obj);
    void fetch_data(person *obj);
    friend class person;
};
int person::count=0;
void personal::get_data(person *obj)
{
    cout<<"\n Enter Name: ";
    cin>>obj->name;
    cout<<"Enter Date of Birth (DD/MM/YYYY): ";
    cin>>obj->dob;
    cout<<"Enter Blood Group (O, A, B, AB): ";
    cin>>obj->bld_grp;
    cout<<"Enter Height(in cm): ";
    cin>>obj->height;
    cout<<"Enter Weight(in Kg): ";
    cin>>obj->weight;
    cout<<"Enter Contact No.: ";
    cin>>this->contact;
    cout<<"Enter Address: ";
    cin>>this->adres;
    cout<<"Enter Policy No.: ";
    cin>>this->policy;
    obj->count++;
}
void personal::fetch_data(person *obj)
{
    cout<<obj->name<<"\t"<<obj->dob<<"\t"<<obj->bld_grp<<"\t\t"<<obj->height<<"\t"<<obj->weight<<"\t"<<this->contact<<"\t   "<<this->policy<<"\t"<<this->adres<<endl;
}
int main()
{
    personal *p1[30];
    person *p2[30];
    int n=0,choice,i;
    do
    {
        cout<<"\nMenu\n1.Enter Data\n2.Display Data\n3.Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter Information";
                p1[n]=new personal;
                p2[n]=new person;
                p1[n]->get_data(p2[n]);
                n++;
                break;
            case 2:
                cout << "\nGenerating Data..." << endl;
                cout
                        << "Name\tDate of Birth\tBlood Group\tHeight\tWeight\tContact No.\t   Policy No.\tAddress"<< endl;
                for (i = 0; i < n; i++) {
                    p1[i]->fetch_data(p2[i]);
                }
                break;
            case 3:
                cout<<"Exiting...";
                break;
        }
    }while(choice != 3);
    return 0;
}
