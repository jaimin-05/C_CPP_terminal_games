#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <conio.h>
using namespace std;

// template <class general>

// set 31 for O  ---> O ascii value : 79
// set 40 for X  ---> X ascii value : 88

class tic_toc_toi
{
protected:
    int choice;
    int count = 0;
    int plateform[3][3] = {7, 8, 9, 4, 5, 6, 1, 2, 3}; // according to keyboard
    string player1;
    string player2;

public:
    int get_count()
    {
        return count;
    }

    void choice_setter(int choice)
    {
        bool set = false;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (plateform[i][j] == choice && count % 2 != 0)
                {
                    plateform[i][j] = 40;
                    set = true;
                }

                else if (plateform[i][j] == choice && count % 2 == 0)
                {
                    plateform[i][j] = 31;
                    set = true;
                }
            }
        }
        if (set == false) // To stop program to overwrite X or O
            count--;
    }

    void greeter()
    {
        cout << "****WELCOME TO TIC TAC TOI GAME****" << endl;
    }

    void winner_checker()
    {

        for (int i = 0; i < 3; i++)
        {
            int Xrchecker = 0, Xcchecker = 0, Xbdchecker = 0;
            int Orchecker = 0, Occhecker = 0, Obdchecker = 0;

            for (int j = 0; j < 3; j++)
            {
                // To check all rows
                if (plateform[i][j] == 40)
                    Xrchecker++;

                else if (plateform[i][j] == 31)
                    Orchecker++;
                // To check all coloums
                if (plateform[j][i] == 40)
                    Xcchecker++;
                else if (plateform[j][i] == 31)
                    Occhecker++;
                // To check backword diagonal
                if (plateform[j][j] == 40)
                    Xbdchecker++;
                else if (plateform[j][j] == 31)
                    Obdchecker++;
            }
            // To check forward diagonal
            if (Xrchecker == 3 || Xcchecker == 3 || Xbdchecker == 3 || (plateform[0][2] == 40 && plateform[1][1] == 40 && plateform[2][0] == 40))
            {

                cout << player1 << " has won this match" << endl;
                system("pause");
                exit(0);
            }
            else if (Orchecker == 3 || Occhecker == 3 || Obdchecker == 3 || (plateform[0][2] == 31 && plateform[1][1] == 31 && plateform[2][0] == 31))
            {
                cout << player2 << " has won this match" << endl;
                system("pause");
                exit(0);
            }
        }
    }

    void plateform_maker()
    {
        system("cls"); // To clear the terminal
        greeter();
        if (count % 2 == 0)
            cout << player1 << "'s turn..." << endl;
        else
            cout << player2 << "'s turn..." << endl;
        cout << "-------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "|";
            for (int j = 0; j < 3; j++)
            {
                if (plateform[i][j] > 0 && plateform[i][j] < 10) // To just print X or O
                    cout << " "
                         << "|";
                else
                    cout << char(plateform[i][j] + 48) << "|";
            }
            cout << endl
                 << "-------" << endl;
        }
    }
};

class multiplayer : public tic_toc_toi
{
public:
    void set_data()
    {
        cout << "Enter the first player name" << endl;
        getline(cin, player1);

        cout << "Enter the second player name" << endl;
        getline(cin, player2);
    }
    int get_choice()
    {
        choice = getch();
        choice -= 48; // TO convert char to int
        count++;

        if (choice > 9 || choice < 1)
        {
            cout << "INVALID CHOICE" << endl;
            system("pause");
            exit(0);
        }

        return choice;
    }
    void play()
    {
        set_data();
        plateform_maker();
        while (get_count() < 9)
        {
            int choice = get_choice();
            choice_setter(choice);
            plateform_maker();
            winner_checker();
        }
        cout << "MATCH HAS DRAW" << endl
             << endl;
    };
};
class computer : public tic_toc_toi
{
    int turn;

public:
    int computer_choice()
    {
        srand(time(NULL));
        return rand() % 9 + 1;
    }
    void set_data()
    {
        cout << "Enter your turn (1/2)" << endl;
        turn = getche() - 48;
        cout << endl;
        if (turn == 1)
        {
            cout << "Enter the your player name" << endl;
            getline(cin, player1);
            player2 = "computer";
        }
        else if (turn == 2)
        {
            cout << "Enter the your player name" << endl;
            getline(cin, player2);
            player1 = "computer";
        }
        else
        {
            cout << "INVALID CHOICE" << endl;
            system("pause");
            exit(0);
        }
    }
    int get_choice()
    {
        if (turn == 1)
        {
            if (count % 2 == 0)
            {
                choice = getch();
                choice -= 48; // TO convert char to int
            }
            else
                choice = computer_choice();
        }
        else
        {
            if (count % 2 != 0)
            {
                choice = getch();
                choice -= 48; // TO convert char to int
            }
            else
                choice = computer_choice();
        }

        count++;

        if (choice > 9 || choice < 1)
        {
            cout << "INVALID CHOICE" << endl;
            system("pause");
            exit(0);
        }

        return choice;
    }
    void play()
    {
        set_data();
        plateform_maker();
        while (get_count() < 9)
        {
            int choice = get_choice();
            choice_setter(choice);
            plateform_maker();
            winner_checker();
        }
        cout << "MATCH HAS DRAW" << endl
             << endl;
    };
};

int main()
{
    int partner_choice;
    here:
    cout << "With whom do you want to play (computer:1/friend:2)" << endl;
    partner_choice = getche() - 48;
    cout<<endl;

    if (partner_choice == 1)
    {
        computer m1;
        m1.play();
    }
    else if (partner_choice == 2)
    {
        multiplayer m1;
        m1.play();
    }
    else
    {
        cout << "INVALID CHOICE" << endl;
        goto here;

    }

    system("pause"); // to stop terminal of cmd

    return 0;
}
