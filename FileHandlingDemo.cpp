#include<iostream>
#include<fstream>
using namespace std;
class _data
{
public:
    ofstream f_out;
    char name[20], b_date[10], contact_no[13];
    int age;
    void get_data()
    {
        cout<<"\nName: ";
        cin>>name;
        cout<<"Age: ";
        cin>>age;
        cout<<"Contact No.: ";
        cin>>contact_no;
        cout<<"Birthday: ";
        cin>>b_date;
    }
    void fetch_data()
    {
        f_out.open("Details.txt");
        f_out<<"Name: "<<name;
        f_out<<"\nAge: "<<age;
        f_out<<"\nContact No.: "<<contact_no;
        f_out<<"\nBirthday: "<<b_date;
        f_out.close();
        ifstream fin;
        cout<<"\n\n-----------Reading----------\n\n";
        fin.open("Details.txt");
        string str;
        while (getline(fin, str))
        {
            cout << str << "\n";
        }
        fin.close();
    }
};
int main()
{
    _data d;
    d.get_data();
    d.fetch_data();
    return 0;
}
