#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    double num1,num2;
    cout<<"Welcome to our calculator "<<endl;
    cout<<"Enter the first number to do operators on "<<endl;
    cin>>num1;
    cout<<"Enter the second number to do operators on "<<endl;
    cin>>num2;
    int op;
    cout<<"Choose the operator to do"<<endl;
    cout<<"Press 1 to do addition operator"<<endl;
    cout<<"Press 2 to do subtraction operator"<<endl;
    cout<<"Press 3 to do multiplication operator"<<endl;
    cout<<"Press 4 to do division operator"<<endl;
    cout<<"Press 5 to Exit"<<endl;
    while (cin>>op)
    {
        if (op>5||op<1)
        {
            cout<<"Unknown input please choose again"<<endl;
            cout<<"Choose the operator to do"<<endl;
            cout<<"Press 1 to do addition operator"<<endl;
            cout<<"Press 2 to do subtraction operator"<<endl;
            cout<<"Press 3 to do multiplication operator"<<endl;
            cout<<"Press 4 to do division operator"<<endl;
            cout<<"Press 5 to Exit"<<endl;
        } else
        if (op==1)
        {
            cout <<"the result of the addition is : "<<num1+num2<<endl;
            cout<<"Choose the operator to do"<<endl;
        }
        else if (op==2)
        {
            cout <<"the result of the subtraction is : "<<num1-num2<<endl;
            cout<<"Choose the operator to do"<<endl;
        }
        else if (op==3)
        {
            cout <<"the result of the multiplication is : "<<num1*num2<<endl;
            cout<<"Choose the operator to do"<<endl;
        }
        else if (op==4)
        {
            cout <<"the result of the division is : "<<num1/num2<<endl;
            cout<<"Choose the operator to do"<<endl;
        } else
            return 0;
    }



}
