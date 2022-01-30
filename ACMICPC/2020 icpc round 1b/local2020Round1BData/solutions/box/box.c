
/* *****
   
   2020 UCF Local Contest (Round 1B) -- box
   Note: This version is for multiple data sets.
         It assumes there is a data-set-count at
         the beginning of the input.

   ***** */

#include <stdio.h>

int heights[101]; /* heights[0] is not used to simplify the code */

void place_block(int, int, int);

int find_tallest(int, int);

/* ************************************************************ */

int main()
{
	int data_set_count, k, base_length, block_count, j;
	int block_horizontal, block_vertical, block_left_column;
	
	scanf("%d %d", &base_length, &block_count);
	
	for (j = 1;  j <= base_length;  ++j)
		heights[j] = 0;
	
	/* read and place all the blocks */
	for (j = 1;  j <= block_count;  ++j)
	{
		scanf("%d %d %d", &block_horizontal, &block_vertical, &block_left_column);
		place_block(block_horizontal, block_vertical, block_left_column);
	}
	
	/*
	printf("data set = %d,  base_length = %d,  block_count = %d \n",
	                                               k, base_length, block_count);
	*/
	
	/* print the height for the tallest column */
	printf("%d\n", find_tallest(1, base_length) );
		
	return(0);

}/* end main() */

/* ************************************************************ */

void place_block(int block_horizontal, int block_vertical, int block_left_column)
{
	int block_right_column, tallest_column_height, new_height, k;
	
	/* find the rightmost column where this block is dropping */
	block_right_column = block_left_column + block_horizontal - 1;
	
	/* find the height of the tallest column where this block is dropping */
	tallest_column_height = find_tallest( block_left_column, block_right_column);
	
	/* all the columns in the given range need to be updated to a new height */
	new_height = tallest_column_height + block_vertical;
	for (k = block_left_column;  k <= block_right_column;  ++k)
		heights[k] = new_height;
		
}/* end place_block() */

/* ************************************************************ */

int find_tallest(int start_column, int end_column)
    /* returns the height of the tallest coulmn in the given range */
{
	int k, max;
	
	max = -1;
	for (k = start_column;  k <= end_column;  ++k)
		if (max < heights[k])
			max = heights[k];

	return(max);
	
}/* end find_tallest() */

/* ************************************************************ */

