#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    srand(time(0));
    int Gen_Num;
    Gen_Num = rand()%100+1;
    int guess,count=0;
    cout<<"\n\n\t\t--------------------{ WELCOME TO NUMBER GUESSING GAME }--------------------\n\n";
    while(1)
    {
        cout<<"\nEnter your guess number: ";
        cin>>guess;
        count++;
        if(guess == Gen_Num)
        {
            cout<<"\n\t\tCongratulation! your number is matched in "<<count<<" tries.\n";
            break;
        }
        else if(guess > Gen_Num)
            cout<<"To high! Try again."<<endl;
        else
            cout<<"To low! Try again."<<endl;
    }
    return 0;
}