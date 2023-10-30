#include "ToDoList.cpp"
int main()
{
    ToDoList list;
    list.AddTask("Today i read a book",5);
    list.ViewTask(list.search("Today i read a book"));
    list.MarkToCompleted(list.search("Today i read a book"));
    list.ViewTask(list.search("Today i read a book"));
    return 0;
}