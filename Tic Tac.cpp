#include <iostream>
#include <Windows.h>
using namespace std;

char Broad[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int CurrentPlayer;
char CurrentMarker;
void DrawBroad()
{
    system("cls");
    cout << "-----------\n";
    cout << " " << Broad[0][0] << " | " << Broad[0][1] << " | " << Broad[0][2] << " |\n";
    cout << "---|---|---\n";
    cout << " " << Broad[1][0] << " | " << Broad[1][1] << " | " << Broad[1][2] << " |\n";
    cout << "---|---|---\n";
    cout << " " << Broad[2][0] << " | " << Broad[2][1] << " | " << Broad[2][2] << " |\n";
    cout << "----------\n";


}
bool PlacePlayer(int slot) {

    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (Broad[row][col] != 'X' && Broad[row][col] != 'O')
    {
        Broad[row][col] = CurrentMarker;
        return true;

    }
    else
        return false;

}
int Winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (Broad[i][0] == Broad[i][1] && Broad[i][1] == Broad[i][2])
        {

            return Broad[i][0] == 'X' ? 1 : 2;
        }


    }


    for (int i = 0; i < 3; i++)
    {
        if (Broad[0][i] == Broad[1][i] && Broad[1][i] == Broad[2][i])
        {

            return Broad[0][i] == 'X' ? 1 : 2;
        }


    }
    if (Broad[0][0] == Broad[1][1] && Broad[1][1] == Broad[2][2])
    {
        return Broad[0][0] == 'X' ? 1 : 2;

    }
    if (Broad[0][2] == Broad[1][1] && Broad[1][1] == Broad[2][0])
    {
        return Broad[0][2] == 'X' ? 1 : 2;

    }



    return 0;

}
void SwaapPlayer()
{
    CurrentMarker = (CurrentMarker =='X') ? 'O' : 'X';
    CurrentPlayer = (CurrentPlayer == 1) ? 2 : 1;

    
}

void Game() {
    cout << "Player 1 choose your marker (X or O)";
    char markerP1;
    cin >> markerP1;
    CurrentMarker = markerP1;
    CurrentPlayer = 1;
    DrawBroad();
    int playerwon = 0;
    for (int i = 0; i < 9; i++)
    {
        cout << "It is player" << CurrentPlayer << "'s turn.Enter your slot: ";
        int slot;
        cin >> slot;
        if (slot < 1 ||slot>9)
        {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;

        }
        if (!PlacePlayer(slot))
        {


            cout << "Slot occupied! Try again.\n";
            i--;
            continue;
        }
        DrawBroad();

        playerwon = Winner();
        if (playerwon == 1 || playerwon == 2) {

            cout << "Player " << playerwon << " Wins!\n";
            return ;
        }
        SwaapPlayer();
        
    }
    cout << "It's a tie.\n";
}







int main() {
    
    Game();

    return 0;
}
