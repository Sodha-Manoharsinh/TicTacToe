#include<iostream>
using namespace std;

int winner(char combination[9], char turn)
{
    if((combination[0] == turn && combination[1] == turn && combination[2] == turn) ||
            (combination[3] == turn && combination[4] == turn && combination[5] == turn) ||
            (combination[6] == turn && combination[7] == turn && combination[8] == turn) ||
            (combination[0] == turn && combination[3] == turn && combination[6] == turn) ||
            (combination[1] == turn && combination[4] == turn && combination[7] == turn) ||
            (combination[2] == turn && combination[5] == turn && combination[8] == turn) ||
            (combination[0] == turn && combination[4] == turn && combination[8] == turn) ||
            (combination[2] == turn && combination[4] == turn && combination[6] == turn))
    {
        return 1;
    }

    return 0;
}


void fill_space(int location,int &space_left, char &turn,char combination[9])
{
    if(combination[location]!='X' && combination[location]!='O')
    {
        combination[location]=turn;
        turn=turn=='X'?'O':'X';
        space_left--;
    }
}

void display(char combination[9])
{
    for(int i = 0; i<9; i++)
    {
        if(i==0||i==3||i==6)
        {
            cout<<"  "<<combination[i]<<"  |  "<<combination[i+1]<<"  |  "<<combination[i+2]<<"  "<<endl;
        }
    }
    cout<<endl<<endl;
}

int main()
{
    char combination[9]= {'1','2','3','4','5','6','7','8','9'}, turn = 'X';
    int space_left = 9, position;

    while(space_left!=0)
    {

        display(combination);

        if(winner(combination,turn))
        {
            cout<<"WINNER IS "<<turn<<endl;
            break;
        }
        else
        {

            cout<<"Enter position for "<<turn<<endl;
            cin>>position;


            if (position > 0 && position <= 9 && combination[position-1] != 'X' && combination[position-1] != 'O')
            {
                fill_space(position-1, space_left, turn, combination);
            }
            else
            {
                cout << "Invalid position. Please choose an empty cell." << endl;
                continue;
            }
        }
    }
    if(space_left==0)
    {
        cout<<"DRAW"<<endl;
    }
    return 0;
}
