#include<bits/stdc++.h>
using namespace std;

class Book{

string author,publisher,title;
int stock, price;

public:
static int success,failure;

 Book(string author="",string title="",string publisher="",int stock=0,int price=0)//we set default arguments 
 {
 
 
  this->title=title;
  this->author=author;
  this->publisher=publisher;
  this->stock=stock;
  this->price=price;
 }
 string getTitle()
 {
  return title;
 }
 
 string getAuthor()
 {
  return author;
 }
 int getPrice()
 {
  return price;
 }
 void details()
 {
  cout<<"Title: "<<title<<endl<<"Author: "<<author<<endl<<"Price: "<<price<<" Publisher: "<<publisher<<endl<<"Stocks available: "<<stock<<endl;
 }
 
 int getStock()
 {
  return stock;
 }
 
 void decrementStock(int val)
 {
  stock=stock-val;
 }
};
int Book::success=0;
int Book::failure=0;

int main()
{
cout<<"Enter Number of Books: "<<endl;
int n=3;

vector<Book> book;
Book b1("nilay gupta","learning java","xyz",200,5);
    Book b2("prj","learning c++","xyz",150,10);
    Book b3("prajwal","learning js","xyz",250,3);
    book.push_back(b1);
    book.push_back(b2);
    book.push_back(b3);
   
   
   
    cout<<"Books pushed"<<endl;
   
    int z=1;
    while(z!=0){


cout<<"Success Transaction: "<<Book::success<<endl;
cout<<"Failed Transaction: "<<Book::failure<<endl;
    cout<<"Enter the title to search"<<endl;
    string title;
    cin>>title;
    int flag=0;
    for(int i=0;i<book.size();i++)
    {
    cout<<book[i].getTitle()<<endl;
    cout<<(book[i].getTitle()).compare(title)<<endl;
    if((book[i].getTitle()).compare(title)==0)
    {
    flag=1;
    cout<<"Book Found!"<<endl;
    book[i].details();
    cout<<"Enter the Number of Copies you want ??"<<endl;
    int request;
    cin>>request;
    if(book[i].getStock()>request)
    {
    cout<<"Requested Stocks available"<<endl;
    cout<<"Total Cost: "<<request*book[i].getPrice()<<endl;
    cout<<"Transaction Completed...";
    book[i].decrementStock(request);
    book[i].success++;
}
else
{
cout<<"Sorry, Requested Number of copies not available!"<<endl;
book[i].failure++;
//not enough copies available
}
   
}
}
