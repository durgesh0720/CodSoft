#include "ToDoList.cpp"
#include<conio.h>

std::ostream& bold_on(std::ostream& os)
{
return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
return os << "\e[0m";
}

int main()
{
    ToDoList list;
    int taskNum,choice;
    string taskName;
    char check;

    cout<<bold_on<<"\t\t<-------{ WELCOME TO TO DO LIST }--------->"<<bold_off<<endl<<endl;
    cout<<"\t1.Add Task\n";
    cout<<"\t2.View Task\n";
    cout<<"\t3.Mark Task as Completed\n";
    cout<<"\t4.Remove Task\n";
    cout<<"\t5.Exit\n";
    cin>>choice;

    switch(choice)
    {
        case 1:

            cout<<"\nEnter your Task: ";
            getline(cin,taskName);
            cout<<"\nEnter Task number: ";
            cin>>taskNum;
            list.AddTask()
            cout<<"\tYour Task is Added!";
            getch();
            break;

        case 2:

            cout<<"\nEnter your Task name or number: ";
            check=getch();
            if(check>=48 && 57>=check)
                {
                    cin>>taskNum;
                    list.ViewTask(list.search(taskNum));
                }
            else
                {
                    getline(cin,taskName);
                    list.ViewTask(list.search(taskNum));
                }
                getch();
            break;
        case 3:

            cout<<"\nEnter your Task name or number: ";
            check=getch();
            if(check>=48 && 57>=check)
                {
                    cin>>taskNum;
                    list.ViewTask(list.search(taskNum));
                }
            else
                {
                    getline(cin,taskName);
                    list.ViewTask(list.search(taskNum));
                }
                getch();
            break;

    }
}