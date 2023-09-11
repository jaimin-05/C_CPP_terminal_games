#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#define area 25
#define row area
#define coloum 2 * area
using namespace std;

class snake_game
{
    bool jump = true;

public:
    int plateform[row + 2][coloum + 2], sr, sc;
    int pos[4];

    void snake_position_setter()
    {
        for (int i = 0; i < 2; i++)
        {
            srand(time(NULL));
            pos[i] = rand() % (row * (i + 1)) + 1;
        }
        if (jump)
        {
            sr = pos[0];
            sc = pos[1];
            jump = false;
        }
    }
    void snake_position_saver()
    {
        pos[0] = sr;
        pos[1] = sc;
    }

    void food_position_setter()
    {
        snake_position_setter();
        for (int i = 2; i < 4; i++)
        {
            srand(time(NULL));
            pos[i] = rand() % (row * (i - 1)) + 1;
        }
    }
    void position_checker()
    {
        while (pos[0] == pos[2] && pos[1] == pos[3])
        {
            food_position_setter();
        }
        snake_position_saver();
    }

    void snake_mover(char side)
    {
        switch (side)
        {
        case 'W':
        case 'w':
            sr--;
            // if (sr == 0)
            //     sr = row;
            break;

        case 'S':
        case 's':
            sr++;
            // if (sr == row + 1)
            //     sr = 1;
            break;

        case 'D':
        case 'd':
            sc++;
            // if (sc == coloum + 1)
            //     sc = 1;
            break;

        case 'A':
        case 'a':
            sc--;
            // if (sc == 0)
            //     sc = coloum;
            break;

        default:
            break;
        }
        position_checker();
    }

    void plateform_maker()
    {
        for (int i = 0; i < row + 2; i++)
        {
            for (int j = 0; j < coloum + 2; j++)
            {
                if (i == 0 || i == row + 1 || j == 0 || j == coloum + 1)
                {
                    plateform[i][j] = 42; // '*' = 42
                    cout << char(plateform[i][j]);
                }

                else
                {
                    plateform[i][j] = 32;           // ' ' = 32
                    plateform[pos[2]][pos[3]] = 43; //'+' = 43
                    plateform[pos[0]][pos[1]] = 48; //'0' = 48
                    cout << char(plateform[i][j]);
                }
            }
            cout << endl;
        }
    }

    void food_generator()
    {
        if (pos[0] == pos[2] && pos[1] == pos[3])
        {
            position_checker();
        }
    }

    
};

int main()
{
    snake_game g1;
    char side = 'o';
    g1.food_position_setter();
    g1.position_checker();

    for (int i = 0; true; i++)
    {
        if (i != 0 && _kbhit())
            side = _getch();
        system("cls");
        g1.snake_mover(side);
        if(g1.sr == 0 || g1.sr == row + 1 || g1.sc == coloum + 1 || g1.sc == 0 )
         break;
        g1.position_checker();
        g1.plateform_maker();
        _sleep(20);
        // g1.food_generator();
    }
    cout<<"GAME OVER"<<endl;
    system("pause");

    return 0;
}
