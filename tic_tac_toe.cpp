#include <iostream>
using namespace std;

int main()
{
    int dimArr, currentPlayer = 1, r, c,
                rowArr[] = {-1, 1, -2, 2, -3, 3, -4, 4, -5, 5, -6, 6, -7, 7, -8, 8},
                colArr[] = {-1, 1, -2, 2, -3, 3, -4, 4, -5, 5, -6, 6, -7, 7, -8, 8};
    bool win = false;
    while (true)
    {
        int ticArr[50][50] = {0};
        cout << "\nEnter the dimension of the Tic Tac Toe : ";
        cin >> dimArr;

        // checking for the dimensions
        bool notvalidDimn = true;
        while (notvalidDimn)
        {
            if (dimArr >= 3 && dimArr <= 9)
            {
                notvalidDimn = false;
                break;
            }
            else
            {
                cout << "\nYou enter not valid dimensions, please enter between 3 & 9 : ";
                cin >> dimArr;
            }
        }

        // running th game
        while (!win)
        {
            cout << "player ";
            if (currentPlayer == 1)
            {
                cout << " x ";
            }
            else
            {
                cout << " o ";
            }
            cout << "turn. enter empty location (r,c) : \n";
            cin >> r >> c;
            int row = r - 1, col = c - 1;

            // check if the location is valid
            while (r <= 0 || r > dimArr || c <= 0 || c > dimArr || ticArr[row][col] == 1 || ticArr[row][col] == 2)
            {
                if (r <= 0 || r > dimArr || c <= 0 || c > dimArr)
                {
                    cout << "enter location in range : ";

                    cin >> r >> c;
                    row = r - 1;
                    col = c - 1;
                }
                else
                {
                    cout << "\nEnter valid location : ";

                    cin >> r >> c;
                    row = r - 1;
                    col = c - 1;
                }
            }
            ticArr[row][col] = currentPlayer;

            // printing the array
            for (int i = 0; i < dimArr; i++)
            {
                for (int j = 0; j < dimArr; j++)
                {
                    if (ticArr[i][j] == 1)
                    {
                        cout << " x ";
                    }
                    else if (ticArr[i][j] == 2)
                    {
                        cout << " o ";
                    }
                    else
                    {
                        cout << " . ";
                    }
                }
                cout << "\n";
            }

            // check win
            int rsum = 0, csum = 0, dsum = 0;
            // 1 check row of the played location
            for (int i = 0; i < dimArr + 1; i++)
            {
                int newrow = row + rowArr[i];
                int newcol = col + colArr[i];
                if (newrow >= 0 && newrow < dimArr)
                {
                    if (ticArr[row][col] == ticArr[newrow][col])
                    {
                        rsum++;
                    }
                }
                if (newcol >= 0 && newcol < dimArr)
                {
                    if (ticArr[row][col] == ticArr[row][newcol])
                    {
                        csum++;
                    }
                }
                if (newrow >= 0 && newrow < dimArr && newcol >= 0 && newcol < dimArr)
                {
                    if (ticArr[row][col] == ticArr[newrow][newcol])
                    {
                        dsum++;
                    }
                }
            }
            if (rsum == dimArr - 1 || csum == dimArr - 1 || dsum == dimArr - 1)
            {
                cout << "player ";
                if (currentPlayer == 1)
                {
                    cout << " x wins.";
                }
                else
                {
                    cout << " o wins.";
                }
                break;
                win = true;
            }

            // changing player role
            if (currentPlayer == 1)
            {
                currentPlayer = 2;
            }
            else
            {
                currentPlayer = 1;
            }
        }
    }
}