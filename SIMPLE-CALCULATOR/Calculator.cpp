#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
void Operation()
{
    char op;
    int num1,num2;
    cout<<"\t\t--------------------{ WELCOME TO SIMPLE CALCULATOR }--------------------"<<endl<<endl;
    while(1)
    {
    cout<<"\t\nOperations list-->\n";
    cout<<"\t\n1. ADDITION sign '+' ";
    cout<<"\t\n2. SUBSTRACTION sign '-' ";
    cout<<"\t\n3. MULTIPLICATION sign 'x' ";
    cout<<"\t\n4. DIVISION sign '/' ";
    cout<<"\t\n5. End Program Sign '0' \n";
    
    cout<<"\n\nChoose anyone operation of press sign key: ";
    op = getch();
    if((42<=op && 47>=op && op!=44 && op!=46) || (op==48))
    {
    	if(42<=op && 47>=op && op!=44 && op!=46)
    	{
        cout<<"\nEnter first operand: ";
        cin>>num1;
        cout<<"\nEnter secend operand: ";
        cin>>num2;
    	}
    	system("cls");
        switch (op)
        {
        case '+':
            cout<<"\t\n"<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
            getch();
            break;
        case '-':
            cout<<"\t\n"<<num1<<" - "<<num2<<" = "<<num1-num2<<endl;
            getch();
            break;
        case '*':
            cout<<"\t\n"<<num1<<" x "<<num2<<" = "<<num1*num2<<endl;
            getch();
            break;
        case '/':
            cout<<"\t\n"<<num1<<" / "<<num2<<" = "<<num1/num2<<endl;
            getch();
            break;
        case '0':
            cout<<"\t\t\n\n------------{ PROGRAM END }-------------\n\n";
            exit(0);
        default:
            break;
        }
    }
    else
    {   
    	system("cls");
        cout<<"\n\t\n--!!!!-You press wrong key,please select the right key-!!!!--\n\n";
        cout<<"\n\tPress any key to continue program......\n";
        getch();
        system("cls");
        Operation();
    }
	}	
}
int main()
{
    Operation();
    return 0;
}
