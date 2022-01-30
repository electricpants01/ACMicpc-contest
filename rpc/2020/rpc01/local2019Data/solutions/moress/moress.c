
#include <stdio.h>
#include <stdlib.h>

#define TRUE (1==1)
#define FALSE (!TRUE)
#define BLANK -1
#define MAX_BOARD 7
#define NEITHER 0
#define GREATER_THAN 1
#define LESS_THAN 2
#define MAX_ROW_LEN 13


int ud[7][7];
int lr[7][7];
int board[7][7];
int n;

int rec(int, int);
int valid ();

int main()
{
    int i, j;
    char buf[MAX_ROW_LEN + 1];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", buf);

        // Handle the digits
        for (j = 0; j < n; j++)
        {
            if (buf[j<<1] == '-')
            {
                board[i][j] = BLANK;
            }
            else
            {
                board[i][j] = buf[j<<1] - '0';
            }
        }
        
        // Handle between each number
        for (j = 0; j < n - 1; j++)
        {
            if (buf[(j<<1)|1] == '>')
            {
                lr[i][j] = GREATER_THAN;
            }
            else if (buf[(j<<1)|1] == '<')
            {
                lr[i][j] = LESS_THAN;
            }
        }

        // Handle the between row
        if (i < n - 1)
        {
            scanf("%s", buf);
            for (j = 0; j < n; j++)
            {
                if (buf[j<<1] == 'v')
                {
                    ud[i][j] = GREATER_THAN;
                }
                else if (buf[j<<1] == '^')
                {
                    ud[i][j] = LESS_THAN;
                }
                else
                {
                    ud[i][j] = NEITHER;
                }
            }
        }
    }

    // Solve the board
    rec(0,0);

    // Print the board
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int valid (int rr, int cc)
{
    int i, j, k;
    
    // Check duplicate in row
    for (k = 0; k < n; k++)
    {
        if (k != cc && board[rr][cc] == board[rr][k])
        {
            return FALSE;
        }
    }

    // Check duplicate in col
    for (k = 0; k < n; k++)
    {
        if (k != rr && board[rr][cc] == board[k][cc])
        {
            return FALSE;
        }
    }
    
    // Check the left right values
    if (cc > 0 && board[rr][cc - 1] != BLANK)
    {
        if (board[rr][cc - 1] > board[rr][cc] && 
            LESS_THAN == lr[rr][cc - 1])
        {
            return FALSE;
        }
        if (board[rr][cc - 1] < board[rr][cc] && 
            GREATER_THAN == lr[rr][cc - 1])
        {
            return FALSE;
        }
    }
    if (cc < n - 1 && board[rr][cc + 1] != BLANK)
    {
        if (board[rr][cc] > board[rr][cc + 1] && 
            LESS_THAN == lr[rr][cc])
        {
            return FALSE;
        }
        if (board[rr][cc] < board[rr][cc + 1] && 
            GREATER_THAN == lr[rr][cc])
        {
            return FALSE;
        }
    }

    // Check the up down values
    if (rr > 0 && board[rr - 1][cc] != BLANK)
    {
        if (board[rr - 1][cc] > board[rr][cc] && 
            LESS_THAN == ud[rr - 1][cc])
        {
            return FALSE;
        }
        if (board[rr - 1][cc] < board[rr][cc] && 
            GREATER_THAN == ud[rr - 1][cc])
        {
            return FALSE;
        }
    }
    if (rr < n - 1 && board[rr + 1][cc] != BLANK)
    {
        if (board[rr][cc] > board[rr + 1][cc] && 
            LESS_THAN == ud[rr][cc])
        {
            return FALSE;
        }
        if (board[rr][cc] < board[rr + 1][cc] && 
            GREATER_THAN == ud[rr][cc])
        {
            return FALSE;
        }
    }

    return TRUE;
}

int rec(int r, int c)
{
    int i;


    // Check if the board was filled in
    if (r == n)
    {
        return TRUE;
    }

    // Check if we are at the end of the row
    if (c == n)
    {
        return rec(r + 1, 0);
    }

    // Check if the spot is already filled in
    if (board[r][c] != BLANK)
    {
        return rec(r, c + 1);
    }

    // Try to fill the spot with any valid value
    for (i = 1; i <= n; i++)
    {
        board[r][c] = i;

        if (valid(r, c))
        {
            if (rec(r, c + 1))
            {
                return TRUE;
            }
        }
        board[r][c] = BLANK;
    }

    // No solution found return false
    return FALSE;
}

