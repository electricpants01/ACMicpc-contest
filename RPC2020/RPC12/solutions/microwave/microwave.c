
/* *****
   
   2020 UCF Local Contest (Final Round) -- microwave
   Note: This version is for multiple data sets.
         It assumes there is a data-set-count at
         the beginning of the input.

   ***** */

#include <stdio.h>

/* ************************************************************ */

int main()
{
	int data_set_count, case_index;
	int donald_minutes, donald_seconds,
	    donald_total_time_in_seconds, 
		microwave_total_time_in_seconds,
		extra_total_time_in_seconds;
	int extra_hours, extra_minutes, extra_seconds;
	char inp_colon;

	scanf("%2d%c%2d", &donald_minutes, &inp_colon, &donald_seconds);
	
	/* Approach taken: Convert everything to seconds; compute the extra time 
	   in seconds; convert the extra time in seconds to hours, minutes, seconds.
	   The idea is that doing all math in one unit is simpler. */
   
    donald_total_time_in_seconds = (60 * donald_minutes) + donald_seconds;
	
	microwave_total_time_in_seconds = (3600 * donald_minutes) + (60 * donald_seconds);
	
	extra_total_time_in_seconds = microwave_total_time_in_seconds - donald_total_time_in_seconds;
	
	extra_hours = extra_total_time_in_seconds / 3600;
	extra_total_time_in_seconds = extra_total_time_in_seconds % 3600;
	extra_minutes = extra_total_time_in_seconds / 60;
	extra_seconds = extra_total_time_in_seconds % 60;
	
	/*
	printf("\n");
	printf("Data set #%d = %02d:%02d\n", case_index, donald_minutes, donald_seconds);
	*/
	
	printf("%02d:%02d:%02d\n", extra_hours, extra_minutes, extra_seconds);
		
	return(0);

}/* end main() */

/* ************************************************************ */

