#include <iostream>
using namespace std;
class publication
{
private:
    string title;
    float price;
public:
    void get_data()
    {
        string t;
        float p;
        cout << "Enter Title: ";
        cin >> t;
        cout << "Enter Price(in $): ";
        cin >> p;
        title = t;
        price = p;
    }
    void put_data()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price<<endl;
    }
};
class book :public publication
{
private:
    int page_count;
public:
    void get_data()
    {
        publication::get_data(); //call publication class function to get data
        cout << "No. of Pages: : "; //Acquire book data from user
        cin >> page_count;
    }
    void put_data()
    {
        publication::put_data();  //Show Publication data
        cout << "Pages included: " << page_count << endl; //Show book data
    }
};
class tape :public publication
{
private:
    float time;
public:
    void get_data()
    {
        publication::get_data();
        cout << "Duration(in minute(s)): ";
        cin >> time;
    }
    void put_data()
    {
        publication::put_data();
        cout << "Duration(in minute(s)): " << time << endl;
    }
};
int main()
{
    book b;
    tape t;
    cout<<"Enter data..."<<endl;
    cout<<"\nBOOK"<<endl;
    b.get_data();
    cout<<"\nTAPE"<<endl;
    t.get_data();
    cout<<"\nFetching Data..."<<endl;
    cout<<"\nBOOK"<<endl;
    b.put_data();
    cout<<"\nTAPE"<<endl;
    t.put_data();

    return 0;
}
