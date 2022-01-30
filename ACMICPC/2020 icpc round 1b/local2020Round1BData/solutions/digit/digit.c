
/* *****
   
   2020 UCF Local Contest (Round 1B) -- digit
   Note: This version is for multiple data sets.
         It assumes there is a data-set-count at
         the beginning of the input.

   ***** */

#include <stdio.h>

int count_digits_in_num(int, int);

/* ************************************************************ */

int main()
{
	int data_set_count, k, num;
	int low, high, digit, total_count;
	
	scanf("%d %d %d", &low, &high, &digit);
	total_count = 0;
	/* check for (count) the digit in the given range */
	for (num = low;  num <= high;  ++num)
	{
		total_count = total_count + count_digits_in_num(num, digit);
	}
	
	// printf("low = %d  high = %d  digit =  %d \n", low, high, digit);
	
	printf("%d\n", total_count);
		
	return(0);

}/* end main() */

/* ************************************************************ */

int count_digits_in_num(int num, int digit)
{
	int count, k, next_digit;
	
	count = 0;
	/* four digits in the number; check each digit */
	for (k = 1;  k <= 4;  ++k)
	{
		next_digit = num % 10;
		if (next_digit == digit)
			++count;
		
		num = num / 10;
		
	}// end for (k)
		
	return(count);

}/* end count_digits_in_num() */

/* ************************************************************ */

