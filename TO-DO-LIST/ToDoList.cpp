#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct Task 
{
    string taskName;
    bool status;
    int num;
    Task* next;
};

class ToDoList 
{
private:
    Task* start;

public:
    ToDoList();
    ~ToDoList();
    void LoadTasks();
    void SaveTasks();
    Task* search(string);
    Task* search(int);
    void AddTask(string, int);
    void ViewTask(Task*);
    void MarkToCompleted(Task*);
    void RemoveTask(Task*);
    void viewAllTask();
};

ToDoList::ToDoList() 
{
    start = NULL;
    LoadTasks();
}

ToDoList::~ToDoList() 
{
    SaveTasks();
    while (start)
        RemoveTask(start);
}

void ToDoList::LoadTasks() 
{
    ifstream inputFile("tasks.txt");
    if (inputFile) 
    {
        string taskName;
        int taskNum;
        Task* lastTask = NULL;

        while (inputFile >> taskName >> taskNum) 
        {
            Task* newTask = new Task;
            newTask->taskName = taskName;
            newTask->num = taskNum;
            newTask->next = NULL;

            char statusChar;
            if (inputFile >> statusChar) 
                newTask->status = (statusChar == '1'); 

            else 
                newTask->status = false;

            if (lastTask) 
                lastTask->next = newTask;

            else 
                start = newTask;

            lastTask = newTask;
            inputFile.ignore();
        }
        inputFile.close();
    }
}

void ToDoList::SaveTasks() 
{
    ofstream outputFile("tasks.txt");
    if (outputFile) 
    {
        Task* t = start;
        while (t) 
        {
            outputFile << t->taskName << " " << t->num << " " << (t->status ? "1" : "0") << endl;
            t = t->next;
        }
        outputFile.close();
    }
}

void ToDoList::viewAllTask() 
{
    Task* t = start;
    while (t) 
    {
        ViewTask(t);
        t = t->next;
    }
}

void ToDoList::RemoveTask(Task* t) 
{
    Task* r;
    if (t) 
    {
        if (t == start) 
        {
            start = t->next;
            r = t;
        } 
        else 
        {
            r = start;
            while (r->next != t) 
                r = r->next;

            r->next = t->next;
        }
        delete t;
        SaveTasks();
    }
}

void ToDoList::MarkToCompleted(Task* t) 
{
    if (t) 
    {
        if (t->status) 
            cout << "\nThis task is already completed!"; 

        else 
        {
            cout << "\nTask marked for complete\n";
            t->status = true;
            SaveTasks();
        }
    } 
    else
        cout << "\nList is Empty or Task not found!\n";
}

void ToDoList::ViewTask(Task* t) 
{
    if (t) 
    {
        cout << "\nTask number: " << t->num;
        cout << "\n Your Task is: " << t->taskName;

        if (t->status) 
            cout << "\nYour task is completed!\n";

        else 
            cout << "\nYour task is pending!\n";
    } 
    else 
        cout << "\nList is Empty or Task not found!\n";
}

Task* ToDoList::search(string tsk) 
{
    Task* t = start;
    while (t) 
    {
        if (t->taskName == tsk) 
            return t;
        t = t->next;
    }
    return NULL;
}

Task* ToDoList::search(int n) 
{
    Task* t = start;
    while (t) 
    {
        if (t->num == n) 
            return t;

        t = t->next;
    }
    return NULL;
}

void ToDoList::AddTask(string tsk, int number) 
{
    Task* t;
    Task* n = new Task;
    n->status = false;
    n->num = number;
    n->taskName = tsk;
    n->next = NULL;
    if (start == NULL) 
        start = n;
    else 
    {
        t = start;
        while (t->next) 
            t = t->next;

        t->next = n;
    }
    SaveTasks();
}

int main() 
{
    ToDoList list;
    int taskNum, choice;
    string taskName;
    char check;
    cout << "\t<-------{ WELCOME TO TO DO LIST }--------->" << endl << endl;

    while (1) 
    {
        cout << "\t1. Add Task\n";
        cout << "\t2. View Task\n";
        cout << "\t3. View All Task\n";
        cout << "\t4. Mark Task as Completed\n";
        cout << "\t5. Remove Task\n";
        cout << "\t6. Exit\n";
        cin >> choice;

        system("cls");
        cin.ignore();

        switch (choice) 
        {
            case 1:
                cout << "\nEnter your Task: ";
                getline(cin, taskName);
                cout << "\nEnter Task number: ";
                cin >> taskNum;
                list.AddTask(taskName, taskNum);
                cout << "\tYour Task is Added!\n";
                _getch();
                system("cls");
                break;

            case 2:
                cout << "\nEnter your Task name or number: ";
                check = _getch();
                if (check >= 48 && 57 >= check) 
                {
                    cin >> taskNum;
                    list.ViewTask(list.search(taskNum));
                } 
                else 
                {
                    getline(cin, taskName);
                    list.ViewTask(list.search(taskName));
                }
                _getch();
                system("cls");
                break;

            case 3:
                cout << "\n>----Task list--->\n";
                list.viewAllTask();
                _getch();
                system("cls");
                break;

            case 4:
                cout << "\nEnter your Task name or number: ";
                check = _getch();
                if (check >= 48 && 57 >= check) 
                {
                    cin >> taskNum;
                    list.MarkToCompleted(list.search(taskNum));
                } 
                else 
                {
                    getline(cin, taskName);
                    list.MarkToCompleted(list.search(taskName));
                }
                _getch();
                system("cls");
                break;

            case 5:
                cout << "\nEnter your task number or task name: ";
                check = _getch();
                if (check >= 48 && 57 >= check) 
                {
                    cin >> taskNum;
                    list.RemoveTask(list.search(taskNum));
                } 
                else 
                {
                    getline(cin, taskName);
                    list.RemoveTask(list.search(taskName));
                }
                cout << "\nTask Removed\n";
                system("cls");
                break;

            case 6:
                cout << "\t<-------{ GooD LucK }--------->" << endl << endl;
                _getch();
                exit(0);

            default:
                cout << "\nPlease choose a valid option!\n";
        }
    }
    return 0;
}
