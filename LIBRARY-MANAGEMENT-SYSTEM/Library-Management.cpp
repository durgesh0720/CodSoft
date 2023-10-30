#include<stdio.h>
#include<iostream>
#include<string>
#include <conio.h>
#include "Fine_Calculate.cpp"
using namespace std;

struct transaction
{
    long isbn;
    transaction* next;
    long id;
    string name;
};
struct book_info    
{
    string title;
    string author;
    long isbn;
    bool status;
    book_info* next;
};

class admin
{
    private:
        book_info* start;
    public:
        admin();
        void AddBook(string,string,long);
        void RemoveBook(long);
        book_info* search_title(string);
        book_info* search_author(string);
        book_info* search_isbn(long);
        void CheckAllBooks();
         ~admin();
};
void admin :: CheckAllBooks()
{
    book_info* t;
    int i=0;
    if(start)
    {
        t=start;
        while(t)
        {
            i++;
            cout<<"\t Book details-->\n";
            cout<<"\t Book no:"<<i<<endl<<endl;
            cout<<"\t Book title: "<<t->title<<endl;
            cout<<"\t Book author: "<<t->author<<endl;
            cout<<"\t Book ISBN: "<<t->isbn<<endl;
            if(t->status)
                cout<<"\t Status: Available"<<endl;
            else
                cout<<"\t Status: Not available\n";
            t=t->next;
        }
    }
    else
        cout<<"Library is empty!";
}
book_info* admin :: search_isbn(long ISBN)
{
    book_info* t;
    if(start!=NULL)
    {
        t=start;
        while(t)
        {
            if(t->isbn==ISBN)
                return t;
            t=t->next;
        }
        cout<<"\tBook not found!\n";
    }
    return NULL;
}
book_info* admin :: search_author(string AUTHOR)
{
    book_info* t;
    if(start!=NULL)
    {
        t=start;
        while(t)
        {
            if(t->author==AUTHOR)
                return t;
            t=t->next;
        }
        cout<<"\tBook not found!\n";
    }
    return NULL;
}
book_info* admin:: search_title(string TITLE)
{
    book_info* t;
    if(start!=NULL)
    {
        t=start;
        while(t)
        {
            if(t->title==TITLE)
            {
                return t;
            }
            t=t->next;
        }
        cout<<"\tBook not found!\n";
    }
    return NULL;
}
void admin :: RemoveBook(long ISBN)
{
    book_info* t,*r;
    if(start!=NULL)
    {
        t=start;
        if(t->isbn==ISBN)
            {
                start=start->next;
                r=t;
            }
        else
            while(t->next)
            {
                if(t->next->isbn==ISBN)
                    r=t->next;
                t=t->next;
            }
        delete r;
    }
}
void admin :: AddBook(string TITLE,string AUTHOR,long ISBN)
{
    book_info* n= new book_info;
    n->title=TITLE;
    n->author=AUTHOR;
    n->isbn=ISBN;
    n->status=true;
    n->next=start;
    start=n;
    cout<<"Book Added!\n";
}
admin :: admin()
{
    start=NULL;
}
admin:: ~admin()
{
    while(start)
        RemoveBook(start->isbn);
}
 class user
{
    private:
        transaction* head;
        void deleteTransaction(long);
    public:
        void Book_Checkout(string,long,book_info* ); //Enter name,Id,book_info node
        void Search_Book_Title(book_info*);
        void Search_Book_Author(book_info*);
        void Search_Book_ISBN(book_info*);
        void All_Transactions(admin&);
        void Return_Book(admin&); 
        void Terms_and_Condition();
        user();
        ~user();
};
void user :: Terms_and_Condition()
{

    cout<<"1. You books issue only for 1 week"<<endl;
    cout<<"2. 1 week After you submit book then you pay fine"<<endl;
    cout<<"3. fine is every day 20 ruppies"<<endl;
    cout<<"4. If you submit book before submission date then you will not pay"<<endl;
    cout<<"<************************Thank You*********************>\n\n";
    cout<<"Press any key to continue----!"<<endl;
}
void user :: deleteTransaction(long isbn)
{
    transaction* t,*r;
    int i=0;
    if(head!=NULL)
    {
        t=head;
        if(t->isbn==isbn)
        {
            i++;
            head=head->next;
            r=head;
        }
        else
        {
            while(t->next)
            {
                if(t->next->isbn==isbn)
                {
                    i++;
                    r=t->next;
                    break;
                }
                t=t->next;
            }
        }
        delete r;
    }   
}
void user :: Return_Book(admin& a)
{
    long ISBN;
    book_info* t;
    if(head!=NULL)
    {
        All_Transactions(a);
        cout<<"\nEnter your book isbn: ";
        cin>>ISBN;
        input_Date();
        t=a.search_isbn(ISBN);
        t->status=true;
        deleteTransaction(ISBN);
        cout<<"\nBook returned!\n";
    }
}
void user :: All_Transactions(admin& a)
{
    transaction* t;
    int i=0;
    int k=0;
    if(head!=NULL)
    {   
        t=head;
        while(t)
        {
            i++;
            cout<<"\tTransaction No:"<<i<<endl;
            cout<<"\tBook ISBN:"<<t->isbn<<endl;
            Search_Book_ISBN(a.search_isbn(t->isbn));
            cout<<"\tStudent Name: "<<t->name<<endl;
            cout<<"\tStudent Id: "<<t->id<<endl<<endl;
            t=t->next;
        }
    }
}
void user :: Search_Book_ISBN(book_info* t)
{
    if(t!=NULL)
    {
        cout<<"\tBook details-->\n\n";
        cout<<"\tBook title: "<<t->title<<endl;
        cout<<"\tBook author: "<<t->author<<endl;
        cout<<"\tBook ISBN:"<<t->isbn<<endl;
        if(t->status)
            cout<<"\tStatus: Available"<<endl;
        else
            cout<<"\tStatus: Not available\n\n";
    }
}
void user :: Search_Book_Author(book_info* t)
{
    if(t!=NULL)
    {
        cout<<"\tBook details-->\n";
        cout<<"\tBook Title: "<<t->title<<endl;
        cout<<"\tBook Author: "<<t->author<<endl;
        cout<<"\tBook ISBN: "<<t->isbn<<endl;
        if(t->status)
            cout<<"\tStatus: Available"<<endl;
        else
            cout<<"\tStatus: Not available\n";
    }
}
void user :: Search_Book_Title(book_info* t)
{
    if(t!=NULL)
    {
        cout<<"\tBook details-->\n";
        cout<<"\tBook Title: "<<t->title<<endl;
        cout<<"\tBook Author: "<<t->author<<endl;
        cout<<"\tBOok ISBN: "<<t->isbn<<endl;
        if(t->status)
            cout<<"\tStatus: Available"<<endl;
        else
            cout<<"\tStatus: Not available\n";
    }
}
void user :: Book_Checkout(string Name,long Id,book_info* t)
{
    if(t!=NULL && t->status!=false)
    {
        t->status=false;
        transaction* n=new transaction;
        n->id=Id;
        n->isbn=t->isbn;
        n->name=Name;
        n->next=head;
        head=n;
        cout<<"Book is issue\n";
        getch();
    }
    else
        cout<<"Book not found! or not available\n";
}
user::user()
{
    head=NULL;
}
user :: ~user()
{
    while(head)
        deleteTransaction(head->isbn);
}
