#include "Library-Management.cpp"
#include<cstdlib>
using namespace std;
int main()
{
    admin Admin;
    user  User;
    string Title,Author,Name;
    long Id,Isbn;
    int n,op;
    cout<<endl<<endl;
    cout<<"\t*******************************************************************\n";
    cout<<"\t******************|-----WELCOME TO LIBRARY SYSTEM---|**************\n";
    cout<<"\t*******************************************************************\n";
    while(1)
    {
        cout<<"\t\tChoose your option!->\n";
        cout<<"\t1.Librarian\n";
        cout<<"\t2.Student\n";
        cin>>n;
        system("clear");
        if(n==1)
        {
            cout<<"\tWELCOME TO LIBRARY!\n";
            cout<<"\tChoose your option!\n";
            cout<<"\t1.Add book"<<endl;
            cout<<"\t2.Delete book"<<endl;
            cout<<"\t3.Check all books"<<endl;
            cout<<"\t4.Exit"<<endl;
            cin>>op;
            cin.ignore();
            switch (op)
            {
            case 1:
                cout<<"\tEnter your book title:"<<endl;
                getline(cin,Title);
                cout<<"\tEnter your book author:"<<endl;
                getline(cin,Author);
                cout<<"\tEnter your book isbn:"<<endl;
                cin>>Isbn;
                Admin.AddBook(Title,Author,Isbn);
                break;
            case 2:
                cout<<"\tEnter book isbn:"<<endl;
                cin>>Isbn;
                Admin.RemoveBook(Isbn);
                break;
            case 3:
                cout<<"\tAll books->\n";
                Admin.CheckAllBooks();
                break;
            case 4:
                cout<<"\tThank you!\tPress any key!"<<endl;
                getch();
                exit(0);
            default:
                cout<<"\tYou choose wrong option!"<<endl;
                break;
            }
        }
        else
        {
            cout<<"\tWELCOME TO LIBRARY!\n";
            cout<<"\t1.Book borrowers"<<endl;
            cout<<"\t2.Book return"<<endl;
            cout<<"\t3.Search book by Title"<<endl;
            cout<<"\t4.Search book by Author"<<endl;
            cout<<"\t5.Search bokk by Isbn"<<endl;
            cout<<"\t6.Check all transactions"<<endl;
            cout<<"\t7.Terms and conditions"<<endl;
            cout<<"\t8.Exit"<<endl;
            cin>>op;
            cin.ignore();
            switch (op)
            {
            case 1:
                cout<<"\tEnter your name: "<<endl;
                getline(cin,Name);
                cout<<"\tEnter your Id No: "<<endl;
                cin>>Id;
                cout<<"\tEnter your book Title: "<<endl;
                cin.ignore();
                getline(cin,Title);
                User.Book_Checkout(Name,Id,Admin.search_title(Title));
                break;
            case 2:
                cout<<"\tChoose a book"<<endl;
                User.Return_Book(Admin);
                break;
            case 3:
                cout<<"\tEnter book Title: "<<endl;
                getline(cin,Title);
                cin.ignore();
                User.Search_Book_Title(Admin.search_title(Title));
                getch();
                break;
            case 4:
                cout<<"\tEnter book Author: "<<endl;
                getline(cin,Author);
                cin.ignore();
                User.Search_Book_Author(Admin.search_author(Author));
                break;
            case 5:
                cout<<"\tEnter book ISBN No:"<<endl;
                cin>>Isbn;
                User.Search_Book_ISBN(Admin.search_isbn(Isbn));
                break;
            case 6:
                cout<<"\tDetails of your transactions!"<<endl;
                User.All_Transactions(Admin);
                break;
            case 7:
                User.Terms_and_Condition();
                getch();
                break;
            case 8:
                cout<<"\tThank you!"<<"Press any key "<<endl;
                getch();
                exit(0);
            default:
                cout<<"\t!Enter wrong option!"<<endl;
                break;
            }
        }
    }
    cout<<"\t*******************************************************************\n";
    cout<<"\t*******************************************************************\n";
}