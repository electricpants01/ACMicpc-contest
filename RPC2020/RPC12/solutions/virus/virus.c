
/* *****
   
   2020 UCF Local Contest (Final Round) -- virus
   Note: This version is for multiple data sets.
         It assumes there is a data-set-count at
         the beginning of the input.

   ***** */

#include <stdio.h>

/* ************************************************************ */

int main()
{
	int data_set_count, d;
	int num_of_groups, people_per_group, positive_groups;
	int individual_test_kits, group_test_kits;

	scanf("%d %d %d", &num_of_groups, &people_per_group, &positive_groups);
	
	/*
	printf("\n");
	printf("data set = %d \n", d);
	printf("num_of_groups = %d,  people_per_group = %d,  positive_groups = %d \n",
	                             num_of_groups, people_per_group, positive_groups);
	*/
	
	individual_test_kits = num_of_groups * people_per_group;
	group_test_kits = num_of_groups + (positive_groups * people_per_group);
	
	/*
	printf("individual_test_kits = %d,  group_test_kits = %d \n",
	                             individual_test_kits, group_test_kits);
	*/
	
	if (individual_test_kits < group_test_kits)
		printf("1\n");
	else if (individual_test_kits > group_test_kits)
		printf("2\n");
	else
		printf("0\n");
		
	return(0);

}/* end main() */

/* ************************************************************ */

