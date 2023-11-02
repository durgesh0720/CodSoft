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
    while (1)
    {
        cout << "\t1.Add Task\n";
        cout << "\t2.View Task\n";
        cout << "\t3.Mark Task as Completed\n";
        cout << "\t4.Remove Task\n";
        cout << "\t5.Exit\n";
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
            getch();
            system("cls");
            break;

        case 2:

            cout << "\nEnter your Task name or number: ";
            check = getch();
            if (check >= 48 && 57 >= check)
            {
                cin >> taskNum;
                list.ViewTask(list.search(taskNum));
            }
            else
            {
                getline(cin, taskName);
                list.ViewTask(list.search(taskNum));
            }
            getch();
            system("cls");
            break;
        case 3:

            cout << "\nEnter your Task name or number: ";
            check = getch();
            if (check >= 48 && 57 >= check)
            {
                cin >> taskNum;
                list.MarkToCompleted(list.search(taskNum));
            }
            else
            {
                getline(cin, taskName);
                list.MarkToCompleted(list.search(taskNum));
            }
            getch();
            system("cls");
            break;

        case 4:

            cout << "\nEnter your task number or task name: ";
            check = getch();
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
            system("cls");
            break;
        case 5:
            cout << bold_on << "\t\t<-------{ GooD LucK }--------->" << bold_off << endl << endl;
            getch();
            exit(0);
        default:
            cout << "\nPlease choose a valid option!\n";
        }
    }
    return 0;
}
