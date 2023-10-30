#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>

using namespace std;
struct lists;
struct node
{
    string title;
    lists* listLinker;
    node *next;
};
struct lists
{
    string note;
    lists* nextList;
};

class ToDoList
{
    private:
        node* start;
    protected:
        void Notes(node*);
        node* search(string);
    public:
        ToDoList();
        void add_list(string);
        void viewList(string);
        void viewAllLists();
        void deleteList(node* t);
        ~ToDoList();
};
ToDoList :: ~ToDoList()
{
    while(start)
        deleteList(search(start->title));
}
node* ToDoList :: search(string Title)
{
    if(start)
    {
        node* t=start;
        if(t->title==Title)
            return t;
        while(t->next)
        {
            if(t->next->title==Title)
                return t->next;
            else
                t=t->next;
        }
    }
    return NULL;
}
void ToDoList :: deleteList(node* t)
{
    node* r;
    r=t->next;
    if(t->next)
        t=t->next->next;
    else
        t=NULL;
    delete r;
}
void ToDoList :: viewAllLists()             // view all lists
{
    node* t;
    t=start;
    while(t)
    {
        viewList(t->title);
        t=t->next;
    }
}
void ToDoList :: viewList(string Title)
{
    node* t;
    lists* l;
    int i=0;
    if(start)
    {
        t=start;
        while(t)                            // find node 
        {
            if(t->title==Title)
                break;
            else
                t=t->next;
        }
        l=t->listLinker;
        while(l)                            // print all lists
        {
            i++;
            cout<<i<<" : "<<l->note<<endl;
           l = l->nextList;
        }
    }
}
void ToDoList :: Notes(node* t)
{   
    string Note;
    char check;
    lists* n = new lists;
    n->nextList=NULL;

    cout<<"Write lists: ";
    getline(cin,Note);
    n->note=Note;

    cout<<"\nAgain! Add list press 'y': ";
    check=getch();

    if(check=='y')
    {   
        if(t->listLinker==NULL)
            t->listLinker=n;
        else
            n->nextList=n;
        Notes(t);
    }
    else
        return;
}
void ToDoList :: add_list(string Title)
{
    node* n= new node;
    n->title=Title;
    n->listLinker=NULL;
    Notes(n);
    n->next=start;
    start=n;
}
ToDoList :: ToDoList()
{
    start=NULL;
}

int main()
{
    ToDoList l;
    l.add_list("C++");
    l.viewList("C++");
    return 0;
}