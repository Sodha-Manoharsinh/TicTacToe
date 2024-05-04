#include<iostream>
#include<cstdlib> //for srand() and rand()
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

char random_turn()
{
    srand(time(NULL)); // srand function ensures that we get rand number every time

    //int n = rand(); //Gives us any random number for example 6895742
    //cout<<n<<endl;
    //cout<<n%2<<endl; //by doing n%2 we could get reminder of 1 or 0

    if(rand()%2)
    {
        return 'X';
    }
    return 'O';
}

int main()
{
    char combination[9]= {'1','2','3','4','5','6','7','8','9'}, turn;
    int space_left = 9, position;

    turn=random_turn();

    while(space_left!=0)
    {
        display(combination);

        //!winner(combination,turn)&&get_position(position,turn);

        if(winner(combination,turn))
        {
            cout<<"WINNER IS "<<turn<<endl;
            break;
        }
        else
        {
            turn=turn=='X'?'O':'X';
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
    if(space_left==0 && !winner(combination,turn))
    {
        cout<<"DRAW"<<endl;
    }else if(space_left==0 && winner(combination,turn)) // for special case winning for example position sequence=(1,2,3,5,4,6,8,9,7)
    {
        cout<<"WINNER IS "<<turn<<endl;
    }
    return 0;
}
