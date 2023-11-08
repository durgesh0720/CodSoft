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
        cout<<"\t2.Student\n\n";
        cout<<"Choose option:";
        cin>>n;
        system("cls");
        if(n==1)
        {
            cout<<"\tWELCOME TO LIBRARY!\n";
            cout<<"\tChoose your option!\n";
            cout<<"\t1.Add book"<<endl;
            cout<<"\t2.Delete book"<<endl;
            cout<<"\t3.Check all books"<<endl;
            cout<<"\t4.Exit\n\n"<<endl;
            cout<<"Choose option:";
            cin>>op;
            cin.ignore();
            switch (op)
            {
            case 1:
                cout<<"Enter your book title:";
                getline(cin,Title);
                cout<<"Enter your book author:";
                getline(cin,Author);
                cin.ignore();
                cout<<"Enter your book isbn:";
                cin>>Isbn;
                Admin.AddBook(Title,Author,Isbn);
                break;
            case 2:
                cout<<"Enter book isbn:";
                cin>>Isbn;
                Admin.RemoveBook(Isbn);
                break;
            case 3:
                cout<<"All books->\n";
                Admin.CheckAllBooks();
                break;
            case 4:
                cout<<"Thank you!\tPress any key!"<<endl;
                getch();
                exit(0);
            default:
                cout<<"You choose wrong option!"<<endl;
                break;
            }
        }
        else
        {
            cout<<"\t-------{ WELCOME TO LIBRARY }------\n\n";
            cout<<"\t1.Book borrowers"<<endl;
            cout<<"\t2.Book return"<<endl;
            cout<<"\t3.Search book by Title"<<endl;
            cout<<"\t4.Search book by Author"<<endl;
            cout<<"\t5.Search bokk by Isbn"<<endl;
            cout<<"\t6.Check all transactions"<<endl;
            cout<<"\t7.Terms and conditions"<<endl;
            cout<<"\t8.Exit\n"<<endl;
            cout<<"Choose option:";
            cin>>op;
            cin.ignore();
            switch (op)
            {
            case 1:
                cout<<"Enter your name: ";
                getline(cin,Name);
                cout<<"Enter your Id No: ";
                cin>>Id;
                cin.ignore();
                cout<<"Enter your book Title: ";
                getline(cin,Title);
                User.Book_Checkout(Name,Id,Admin.search_title(Title));
                break;
            case 2:
                cout<<"Choose a book"<<endl;
                User.Return_Book(Admin);
                break;
            case 3:
                cin.ignore();
                cout<<"Enter book Title: ";
                getline(cin,Title);
                User.Search_Book_Title(Admin.search_title(Title));
                getch();
                break;
            case 4:
                cout<<"Enter book Author: ";
                getline(cin,Author);
                cin.ignore();
                User.Search_Book_Author(Admin.search_author(Author));
                getch();
                break;
            case 5:
                cout<<"Enter book ISBN No:";
                cin>>Isbn;
                User.Search_Book_ISBN(Admin.search_isbn(Isbn));
                getch();
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