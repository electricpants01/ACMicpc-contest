
/* *****
   
   2020 UCF Local Contest (Round 1B) -- birth
   Note: This version is for multiple data sets.
         It assumes there is a data-set-count at
         the beginning of the input.

   ***** */

#include <stdio.h>

#include <string.h>

char unique_dates[60][10];

int unique_count;

void add_to_set(char[]);

/* ************************************************************ */

int main()
{
	int data_set_count, k, inp_dates_count, j;
	char inp_date[10];
	
	scanf("%d\n", &inp_dates_count);
	/* process all the dates in the current data set */
	unique_count = 0;
	for (j = 1;  j <= inp_dates_count;  ++j)
	{
		scanf("%s\n", &inp_date[0]);
		add_to_set(inp_date);
	}
	
	// printf("Data set #%d: \n", k);
	
	printf("%d\n", unique_count);
		
	return(0);

}/* end main() */

/* ************************************************************ */

void add_to_set(char inp_date[])
{
	int k;
	
	/* check to see if the input_date is a duplicate */
	for (k = 0;  k < unique_count;  ++k)
	{
		if ( strcmp(unique_dates[k], inp_date) == 0 )
			/* duplicate date; do not add it to the set */
		    return;
		
	}// end for (k)
		
	// new date; add it to the set
	strcpy(unique_dates[unique_count], inp_date);
	++unique_count;

}/* end add_to_set() */

/* ************************************************************ */

