#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void display(string m[3][3])
{
    cout<<endl;
    for (int i = 0 ; i <3;i++)
    {
        for (int j = 0 ; j <3;j++)
        {
            cout<<"      "<<m[i][j]<<"     ";
        }
        cout<<endl<<endl<<endl;
    }
}
bool isValidInput(int f  , int s)
{
    if ((f and s >2)|| (f and s <0) )
        return false;
    else
        return true;
}
bool isVisited(int f , int s,string m[3][3])
{
    if (m[f][s]=="x"||m[f][s]=="o"||m[f][s]=="X"||m[f][s]=="O")
        return true;
    else
        return false;
}
void update(int f , int s,string m[3][3] ,string sy)
{
    m[f][s]=sy;
}
bool isWinner(string m[3][3] ,string sy)
{
    for (int i = 0 ; i < 3 ; i ++)
    {
        if (m[i][0]==sy and m[i][1]==sy and m[i][2]==sy)
            return true;
        else if (m[0][i]==sy and m[1][i]==sy and m[2][i]==sy)
            return true;
    }
    if (m[0][0] == sy && m[1][1] == sy && m[2][2] == sy) {
        return true;
    }

    else if (m[0][2] == sy && m[1][1] == sy && m[2][0] == sy) {
        return true;
    } else
        return false;
}
bool isDraw(string m[3][3])
{
    for (int i = 0 ; i <3;i++)
    {
        for (int j = 0 ; j <3;j++)
        {
            if (m[i][j]!= "X" && m[i][j]!="x" && m[i][j]!="O"&&m[i][j]!="o" )
            {
                return false;
            }
        }
    }
    return true;
}
void play()
{
    string grid [3][3]={{"0.0","0.1","0.2"},{"1.0","1.1","1.2"},{"2.0","2.1","2.2"}};

    string p1,p2;
    cout<<"welcome to our XO game"<<endl;
    while (true)
    {
        cout<<"player one please choose your symbol you can choose X or O"<<endl;
        cin>>p1;
        if (p1=="X"||p1 =="x")
        {
            cout <<"now player 2 will play with O symbol"<<endl;
            p1="X";
            p2="O";
            break;
        }
        else if (p1=="O"||p1=="o")
        {
            cout <<"now player 2 will play with X symbol"<<endl;
            p1="O";
            p2="X";
            break;
        } else{
            cout<<"Unknown symbol you can choose X or O only"<<endl;
        }
    }
    cout <<"now here is the current state of our game :"<<endl;
    display (grid);
    while (true)
    {
        cout <<"player 1 choose do your move  choose numbers of the cell like shown above "<<endl;
        int first_cell,second_cell ;
        while (cin>>first_cell,cin>>second_cell)
        {
            if (isValidInput(first_cell,second_cell))
            {
                if (isVisited(first_cell,second_cell,grid))
                {
                    cout<<"this cell is already visited choose another cell"<<endl;
                } else
                {
                    update(first_cell,second_cell,grid,p1);
                    display(grid);
                    break;
                }
            }
            else
                cout<<"you can't choose cells less than 0 or bigger than 2 ,please try again"<<endl;
        }
        if (isDraw(grid))
        {
            cout<<"Game ended with draw"<<endl;
            break;
        }
        else if (isWinner(grid,p1))
        {
            cout <<"player 1 the winner"<<endl;
            break;
        }

        cout <<"player 2 choose do your move  choose numbers of the cell like shown above "<<endl;
        int firsst_cell,ssecond_cell ;
        while (cin>>firsst_cell,cin>>ssecond_cell)
        {
            if (isValidInput(firsst_cell,ssecond_cell))
            {
                if (isVisited(firsst_cell,ssecond_cell,grid))
                {
                    cout<<"this cell is already visited choose another cell"<<endl;
                } else
                {
                    update(firsst_cell,ssecond_cell,grid,p2);
                    display(grid);
                    break;
                }
            }
            else
                cout<<"you can't choose cells less than 0 or bigger than 2 ,please try again"<<endl;
        }
        if (isDraw(grid))
        {
            cout<<"Game ended with draw"<<endl;
            break;
        }
        else if (isWinner(grid,p2))
        {
            cout <<"player 2 is the winner"<<endl;
            break;
        }
    }
    cout<<"Thanks for playing our game \n";
}
int main() {
    play();
    int  again ;
    cout <<"Do you want to play another game?\n";
    cout <<"for yes press 1\nfor no press 0\n";
    while (cin>>again)
    {
        if (again>=1)
        {
            play();
        }
        else
            break;
    }
}
