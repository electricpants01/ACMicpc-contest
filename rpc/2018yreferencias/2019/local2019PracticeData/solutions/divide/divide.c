
#include <stdlib.h>
#include <stdio.h>

typedef long long int LLI;

#define MAX_REQ      10
#define IMPOSSIBLE   -1

LLI comp(LLI st, LLI en, LLI tks);

int main()
{
    LLI      tracks;
    int      plays;
    int      oldMemoSize;
    LLI      oldMemoValue[MAX_REQ];
    LLI      oldMemoIndex[MAX_REQ];
    int      newMemoSize;
    LLI      newMemoValue[MAX_REQ];
    LLI      newMemoIndex[MAX_REQ];
    int      i;
    size_t   j;
    size_t   k;
    LLI      temp_res;
    LLI      ans;
    
    // Read in the number of tracks and the songs to play
    scanf("%lld", &tracks);
    scanf("%d", &plays);
    
    // Initialize the memo table
    oldMemoSize = 1;
    oldMemoValue[0] = 0;
    oldMemoIndex[0] = 0;
    
    // Read in the number of songs to play
    for (i = 0; i < plays; i++)
    {
        // Reset the answer
        ans = IMPOSSIBLE;
        
        // Read in the number of songs
        scanf("%d", &newMemoSize);
        
        // Handle each possible song
        for (j = 0; j < newMemoSize; j++)
        {
            // Read in the song track
            scanf("%lld", &newMemoIndex[j]);
            
            // Set the value for the partial memo table to an impossible value
            newMemoValue[j] = IMPOSSIBLE;
            
            // Look for each previous song to find a shortest total number of
            // presses
            for (k = 0; k < oldMemoSize; k++)
            {
                temp_res = 
                    comp(oldMemoIndex[k], newMemoIndex[j], tracks) + 
                    oldMemoValue[k];
                if (newMemoValue[j] == IMPOSSIBLE || 
                    temp_res < newMemoValue[j])
                {
                    newMemoValue[j] = temp_res;
                }
            }
            
            // Store an answer if it is acceptable
            if (ans == IMPOSSIBLE || ans > newMemoValue[j])
            {
                ans = newMemoValue[j];
            }
        }
        
        // Move the dp table over
        for (j = 0; j < newMemoSize; j++)
        {
            oldMemoIndex[j] = newMemoIndex[j];
            oldMemoValue[j] = newMemoValue[j];
        }
        oldMemoSize = newMemoSize;
    }
    
    // Print the answer
    printf("%lld\n", ans);
    
    // Return
    return 0;
}


LLI comp(LLI st, LLI en, LLI tks)
{
    // Get the song start and end
    st = (st+1)%tks;
    en = en%tks;
    
    // Compute the normal difference 
    LLI r = st-en;
    if (r < 0)
    {
        r = -r;
    }
    
    // Compute the difference by wrapping around
    LLI ar = tks - r;
    
    // Return the smaller value
    if (r < ar)
    {
        return r;
    }
    return ar;
}