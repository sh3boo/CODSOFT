#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int main() {
    int ra  = rand()%100;
    int num ;
    cout<<"Guess the number :";
    while (cin>>num)
    {
        if (num>ra)
            cout<<"Too High Try again";
        else if (num<ra)
            cout<<"Too Low Try again";
        else {
            cout << "Prefect,That is our number";
            break;
        }
        cout<<endl<<"Guess the number :";
    }

    return 0;
}
