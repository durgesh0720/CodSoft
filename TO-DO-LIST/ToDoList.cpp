#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

struct task
{
    string taskName;
    bool status;
    task* next;
    int num;
};

class ToDoList
{
    private:
        task* start;
    public:
        task* search(string);
        task* search(int);
        ToDoList();
        void AddTask(string,int);
        void ViewTask(task*);
        void MarkToCompleted(task*);
        void RemoveTask(task*);
        ~ToDoList();
};
ToDoList :: ~ToDoList()                     // deallocate memory of object and dynamic created space
{
    while(start)
        RemoveTask(start);
}
void ToDoList :: RemoveTask(task* t)                // remove a particular task
{
    task* r;
    if(t)
    {
        if(t==start)
        {
            start=t->next;
            r=t;
        }
        else
        {
            r=t->next;
            t->next=r->next;
        }
        delete r;
    }
}   
void ToDoList :: MarkToCompleted(task* t)               //  mark to complete
{
    if(t)
    {
        if(t->status)
            cout<<"\nThis task is already completed!";
        else
        {
            cout<<"\nTask mark to completed";
            t->status=true;
        }
    }
    else
        cout<<"\nList is Empty or Task not found!";
}
void ToDoList :: ViewTask(task* t)                      // View a particuller task
{
    if(t)
    {
        cout<<"\nTask number: "<<t->num;
        cout<<"\n Your Task is: "<<t->taskName;
        if(t->status)
            cout<<"\nYour task is completed!";
        else
            cout<<"\nYour task pending!";
    }
    else
        cout<<"\nList is Empty or Task not found!";
}
task* ToDoList :: search(string tsk)            // searching task by passing task name and return task node address
{
    task* t;
    if(start)
    {
        t=start;
        if(t->taskName==tsk)
            return t;
        else
        {
            while(t->next)
            {
                if(t->next->taskName==tsk)
                    return t;
                t=t->next;
            }
        }
    }
    return NULL;
}
task* ToDoList :: search(int n)
{
    task* t;
    if(start)
    {
        t=start;
        if(t->num==n)
            return t;
        else
        {
            while(t->next)
            {
                if(t->next->num==n)
                    return t;
                t=t->next;
            }
        }
    }
    return NULL;
}
void ToDoList :: AddTask(string tsk,int number)        // add a new task at start of list
{
    task* n = new task;
    n->status=false;
    n->num=number;
    n->taskName=tsk;
    n->next=start;
    start=n;
}
ToDoList :: ToDoList()          // constructor
{
    start=NULL;
}