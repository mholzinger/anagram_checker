#include <stdio.h>
#include <string.h>

#define True 0
#define False 1

int is_anagram(char* a, char* b);
int charscan(char needle, char* haystack);

/*----------------------------------------------------------------------------*/
int main() {

    char* string1 = "race";
    char* string2 = "care";
    int ret;

    ret = is_anagram(string1, string2);

    printf("Are strings <%s>, <%s>, anagrams? : %s\n",
     string1, string2, ret ? "False" : "True");

    return 0;
}

/*----------------------------------------------------------------------------*/
int is_anagram(char* a, char* b)
{
   int len1;
   int idx;
   char* chr;

   //  (void)printf("F: is_anagram\n");
   if ((int)strlen(a) != (int)(strlen(b)))
   {
       return False;
   }

   len1 = strlen(a);
   idx = 0;
   while (idx < len1)
   {
      //(void)printf("Scanning <%c>\n", a[idx]);
      if (charscan(a[idx], a) != charscan(a[idx], b))
        return False;

      idx++;
   }
   return True;
}

/*----------------------------------------------------------------------------*/
int charscan(char needle, char* haystack)
{

  int idx = 0;
  int counter = 0;

//  (void)printf("F: Charscan\n");

  while (idx < strlen(haystack))
  {
    if (needle == haystack[idx])
    {
      counter += 1;

    }
    idx++;
  };
//  (void)printf("character <%c> appears <%d> times in string <%s>\n",
//    needle, counter, haystack);
  return counter;
}
