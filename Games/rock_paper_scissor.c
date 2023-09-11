#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random_number_generater()
{

    srand(time(0));

    return rand() % 15+ 1;
}

int main()
{
    char playername[20];
    char compchoice, playerchoice;
    int comppoint = 0, playerpoint = 0;

    printf("***************************************************\n");
    printf("******WELCOME IN THIS ROCK_PAPER_SCISSOR GAME******\n");
    printf("***************************************************\n\n");
    printf("Enter your name\n");
    scanf("%s", playername);
    printf("hello *%s*\n", playername);
    getchar();
    printf("1. Enter 'r' for rock\n2. Enter 'p' for paper\n3. Enter 's' for scissor\n");

    for (int i = 0; i < 3; i++)
    {
        int num = random_number_generater();

        if (num >= 1 && num <= 5)
        // if (num == 1)
        {
            compchoice = 'r';
        }

        else if (num >=6  && num <= 10)
        {
            compchoice = 'p';
        }

        else if (num >= 11 && num <= 15)
        {
            compchoice = 's';
        }

        fflush(stdin);
        printf("\nComputer has decided it's choice\n");
        printf("Now %s it's your turn\n", playername);
        printf("\n%s enter your choice\n", playername);
        printf("==>");
        scanf("%c", &playerchoice);

        if (playerchoice == compchoice)
        {

            printf("\nComputer choice and your choice are same\n");
            printf("Game is draw\n");
        }

        else
        {

            if (playerchoice == 'r' && compchoice == 'p')
            {

                printf("\nComputer chose paper and %s chose rock\n", playername);
                printf("Computer has won this time\n");
                comppoint++;
            }
            else if (playerchoice == 'p' && compchoice == 'r')
            {

                printf("\nComputer chose rock and %s chose paper\n", playername);
                printf("%s has won this time\n", playername);
                playerpoint++;
            }
            else if (playerchoice == 'p' && compchoice == 's')
            {

                printf("\nComputer chose scissor and %s chose paper\n", playername);
                printf("Computer has won this time\n");
                comppoint++;
            }
            else if (playerchoice == 's' && compchoice == 'p')
            {

                printf("\nComputer chose paper and %s chose scissor\n", playername);
                printf("%s has won this time\n", playername);
                playerpoint++;
            }
            else if (playerchoice == 's' && compchoice == 'r')
            {

                printf("\nComputer chose rock and %s chose scissor\n", playername);
                printf("Computer has won this time\n");
                comppoint++;
            }
            else if (playerchoice == 'r' && compchoice == 's')
            {

                printf("\nComputer chose scissor and %s chose rock\n", playername);
                printf("%s has won this time\n", playername);
                playerpoint++;
            }

            else
            {

                printf("\nINVALID CHARACTOR INPUT\n");
            }
            // getchar();
        }
        printf("------------------------------------------------------------\n");
    }
    printf("---------------------------------------------\n");
    printf("%s has got %d points and Computer has got %d\n", playername, playerpoint, comppoint);
    printf("---------------------------------------------\n");

    if (playerpoint < comppoint)
    {
        printf("---------------------\n");
        printf("computer is a winner\n");
        printf("---------------------\n");
    }
    else if (playerpoint > comppoint)
    {
        printf("-----------------------\n");
        printf("%s is a winner\n", playername);
        printf("-----------------------\n");
    }
    else if (playerpoint == comppoint)
    {
        printf("---------------------\n");
        printf("the game has drawn\n");
        printf("---------------------\n");
    }

    system("pause");

    return 0;
}
