
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INVALID_PLAYER   -1
#define FIRST_CARD       0
#define FIRST_PLAYER     0
#define MAX_LEN_STR      20

int main()
{
    int i, j;
    int numSq, numPl, numCd;
    int curPl, curCd;
    int winner;
    char ** board;
    char ** cards;
    int *   type;
    int *   plPos;
    
    // Read in the number of squares and the number of players
    scanf("%d", &numSq);
    scanf("%d", &numPl);
    numSq--;

    // Allocate the board
    board = (char **) calloc(numSq, sizeof(char *));
    for (i = 0; i < numSq; i++)
    {
        board[i] = (char *) calloc(MAX_LEN_STR + 1, sizeof(char));
    }

    // Allocate the player
    plPos = (int *) calloc(numPl, sizeof(int));
    for (i = 0; i < numPl; i++)
    {
        plPos[i] = -1;
    }

    // Read in the board
    for (i = 0; i < numSq; i++)
    {
        scanf("%s", board[i]);
    }

    // Read in the number of cards
    scanf("%d", &numCd);

    // Allocate room for the cards
    cards = (char **) calloc(numCd, sizeof(char *));
    type = (int *) calloc(numCd, sizeof(int));

    // Read the cards
    for (i = 0; i < numCd; i++)
    {
        cards[i] = (char *) calloc(MAX_LEN_STR + 1, sizeof(char));
        scanf("%d", &type[i]);
        scanf("%s", cards[i]);
    }

    // Initialize some values
    winner = INVALID_PLAYER;
    curPl = FIRST_PLAYER;
    curCd = FIRST_CARD;

    // Loop until the winner is valid
    while (INVALID_PLAYER == winner)
    {
        // Check which type of card we have
        if (type[curCd] == 1)
        {
            // Move at least one square
            plPos[curPl]++;

            // Move to the correct position
            while (plPos[curPl] < numSq && 
                0 != 
		strcmp(board[plPos[curPl]], cards[curCd]))
            {
                plPos[curPl]++;
            }
        }
        else if (type[curCd] == 2)
        {
            // Move at least one square
            plPos[curPl]++;

            // Move to the correct position
            while (plPos[curPl] < numSq && 
                0 != 
		strcmp(board[plPos[curPl]], cards[curCd]))
            {
                plPos[curPl]++;
            }
            
            // Move at least one square
            plPos[curPl]++;

            // Move to the correct position
            while (plPos[curPl] < numSq && 
                0 != 
		strcmp(board[plPos[curPl]], cards[curCd]))
            {
                plPos[curPl]++;
            }
        }
        else
        {
            // Loop until we find the correst special square
            for (i = 0; i < numSq; i++)
            {
                if (0 == strcmp(cards[curCd], board[i]))
                {
                    plPos[curPl] = i;
                }
            }
        }
        
        // Check for a winner
        if (plPos[curPl] >= numSq)
        {
            winner = curPl;
        }

        // Update the player and card
        curPl++;
        if (curPl == numPl)
        {
            curPl = FIRST_PLAYER;
        }
        curCd++;
        if (curCd == numCd)
        {
            curCd = FIRST_CARD;
        }
    }

    // Print the winner
    printf("%d\n", winner + 1);

    // Free the memory
    for (i = 0; i < numSq; i++)
    {
        free(board[i]);
    }
    free(board);

    // Free the cards
    for (i = 0; i < numCd; i++)
    {
        free(cards[i]);
    }
    free(cards);
    free(type);

    // Free the player position
    free(plPos);

    // Return zero before exitting
    return 0;
}
