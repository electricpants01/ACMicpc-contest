
/* *****
   
   2020 UCF Local Contest (Final Round) -- elect
   Note: This version is for multiple data sets.
         It assumes there is a data-set-count at
         the beginning of the input.

   ***** */

#include <stdio.h>

/* ************************************************************ */

int main()
{
	int data_set_count, d;
	int num_of_states, s;
	int state_electoral, state_votes1, state_votes2, 
	    total_votes1, total_votes2, total_electorals1, total_electorals2;
	
	scanf("%d", &num_of_states);
	
	total_votes1 = 0;
	total_votes2 = 0;
	total_electorals1 = 0;
	total_electorals2 = 0;
	
	/* process all the states */
	for (s = 1;  s <= num_of_states;  ++s)
	{
		scanf("%d %d %d", &state_electoral, &state_votes1, &state_votes2);
		
		total_votes1 += state_votes1;
		total_votes2 += state_votes2;
		
		if (state_votes1 > state_votes2)
			total_electorals1 += state_electoral;
		else if (state_votes1 < state_votes2)
			total_electorals2 += state_electoral;
		else
			printf("***** Note to Judges: check the judge data ***** \n");
		
	}// end for (s)
		
	/*
	printf("\n");
	printf("data set = %d \n", d);
	printf("total_votes1 = %d,  total_votes2 = %d \n",
	                                        total_votes1, total_votes2);
	printf("total_electorals1 = %d,  total_electorals2 = %d  \n",
	                                 total_electorals1, total_electorals2);
	*/
	
	if ( (total_votes1 > total_votes2) && (total_electorals1 > total_electorals2) )
		printf("1\n");
	else if ( (total_votes1 < total_votes2) && (total_electorals1 < total_electorals2) )
		printf("2\n");
	else
		printf("0\n");
		
	return(0);

}/* end main() */

/* ************************************************************ */

