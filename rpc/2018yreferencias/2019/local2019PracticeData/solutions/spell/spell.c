#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  TRUE   1
#define  FALSE  0

char  dict[100][20];
int   dict_word_cnt; /* number of words in the dictionary */

/* ******************************************************** */

int main(void)
{
   int   k;
   char  inp_word[20];
   int   inp_word_cnt; /* number of words to be spell checked */
   void  spell_chk();

   /* read in the dictionary */
   scanf("%d\n", &dict_word_cnt);
   for ( k = 0;  k < dict_word_cnt;  ++k )
      scanf("%s\n", dict[k]);

   /* read in the words to be spell checked, one at a time, */
   /* and process each word                                 */
   scanf("%d\n", &inp_word_cnt);
   for ( k = 1;  k <= inp_word_cnt;  ++k )
     {
      scanf("%s\n", inp_word);
      printf("%s\n", inp_word);
      spell_chk(inp_word);
      printf("\n");
     }
      
   return(0);

}/* end main */

/* ******************************************************** */

void spell_chk(char inp_word[])
{
   int   k, unknown;
   int   omit_one_chk(), add_one_chk(), mistype_one_chk(),
         transpose_two_chk();

   /* check to see if the input word is in the dictionary */
   for ( k = 0;  k < dict_word_cnt;  ++k )
      if ( strcmp(dict[k],inp_word) == 0 )
        {/* the word is in the dictionary */
         printf("CORRECT\n");
         return;  /* we are done processing this word */
        }

   /* input word is not in the dictionary */
   /* take each dictionary word and check for the four kinds */
   /* of errors                                              */
   unknown = TRUE;
   for ( k = 0;  k < dict_word_cnt;  ++k )
      if ( omit_one_chk(inp_word,dict[k])     ||
           add_one_chk(inp_word,dict[k])      ||
           mistype_one_chk(inp_word,dict[k])  ||
           transpose_two_chk(inp_word,dict[k])   )
         unknown = FALSE;

   if ( unknown )
      /* the input word is not correct and is not misspelled */
      printf("UNKNOWN\n");

}/* end spell_chk */

/* ******************************************************** */

int omit_one_chk(char word1[], char word2[])
   /* Omitting one letter. */
   /* check to see if word1 is obtained by deleting (omitting) */
   /* a letter from word2                                      */
{
   int  omit_test();

   if ( omit_test(word1,word2) )
     {
      printf("ONE LETTER OMITTED FROM %s\n", word2);
      return(TRUE);
     }
   else
      return(FALSE);

}/* end omit_one_chk */

/* ******************************************************** */

int add_one_chk(char word1[], char word2[])
   /* Adding an extra letter. */
   /* check to see if word1 is obtained by adding a letter */
   /* to word2                                             */
{
   int  omit_test();

   /* adding a letter to word2 to get word1 is the same as */
   /* deleting (omitting) a letter from word1 to get word2 */
   if ( omit_test(word2,word1) )
     {
      printf("ONE LETTER ADDED TO %s\n", word2);
      return(TRUE);
     }
   else
      return(FALSE);

}/* end add_one_chk */

/* ******************************************************** */

int omit_test(char word1[], char word2[])
   /* Routine used by omit_one_chk and add_one_check. */
   /* check to see if we can omit a letter from word2 to get word1, */
   /* i.e., word1 is missing a letter                               */
{
   int  missing, index1, index2, len1, len2;

   len1 = strlen(word1);
   len2 = strlen(word2);

   if ( len1 != (len2 - 1) )
      return(FALSE);

   missing = 0;
   index1 = 0;
   index2 = 0;
   while ( index2 < len2 )
     {
      if ( word1[index1] == word2[index2] )
        {
         ++index1;
         ++index2;
        }
      else
        {/* letter missing */
         ++index2;
         ++missing;
        }
     }/* end while */

   if ( missing == 1 )
      /* exactly one letter missing */
      return(TRUE);
   else
      /* zero or more than one letter missing */
      return(FALSE);

}/* end omit_test */

/* ******************************************************** */

int mistype_one_chk(char word1[], char word2[])
   /* Mistyping one letter. */
   /* check to see if word1 is the same as word2 but mistyping */
   /* one letter                                               */
{
   int  mistype, k, len1, len2;

   len1 = strlen(word1);
   len2 = strlen(word2);

   if ( len1 != len2 )
      return(FALSE);

   mistype = 0;
   for ( k = 0;  k < len1;  ++k )
      if ( word1[k] != word2[k] )
         ++mistype;

   if ( mistype == 1 )
     {/* exactly one letter mistyped */
      printf("ONE LETTER DIFFERENT FROM %s\n", word2);
      return(TRUE);
     }
   else
      /* zero or more than one letter mistyped */
      return(FALSE);

}/* end mistype_one_chk */

/* ******************************************************** */

int transpose_two_chk(char word1[], char word2[])
   /* Transposing two adjacent letters. */
   /* check to see if word1 is the same as word2 but transposing */
   /* two adjacent letters                                       */
{
   int  transpose, k, len1, len2;

   len1 = strlen(word1);
   len2 = strlen(word2);

   if ( len1 != len2 )
      return(FALSE);

   transpose = 0;
   k = 0;
   while ( k < len1 )
     {
      if ( word1[k] == word2[k] )
         ++k;
      else if ( (word1[k] == word2[k+1])  && 
                (word1[k+1] == word2[k])     ) 
        {/* two letters transposed */
         k = k + 2;
         ++transpose;
        }
      else
         /* not matching and not transposed */
         return(FALSE);
     }/* end while */

   if ( transpose == 1 )
     {/* exactly two letters transposed */
      printf("TWO LETTERS TRANSPOSED IN %s\n", word2);
      return(TRUE);
     }
   else
      /* zero or more than two letters transposed */
      return(FALSE);

}/* end transpose_two_chk */

/* ******************************************************** */

