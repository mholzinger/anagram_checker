#include <stdio.h>
#include <string.h>

#define True 0
#define False 1

int is_anagram(char* a, char* b);
int charscan(char needle, char* haystack);

/*----------------------------------------------------------------------------*/
int main(){
  char* string1 = "race";
  char* string2 = "care";

  (void)printf("Are strings <%s>, <%s>, anagrams? : %s\n", string1, string2,
    is_anagram(string1, string2) ? "False" : "True");

  return 0;
}

/*----------------------------------------------------------------------------*/
int is_anagram(char* a, char* b){
  int idx;

  // Test if our string lengths match, if they don't match then we don't
  // have an anagram
  if ((int)strlen(a) != (int)(strlen(b))){ return False; }

  idx = 0;
  while (idx < strlen(a))
  {
    if (charscan(a[idx], a) != charscan(a[idx], b)){ return False; }
    idx++;
  }
  return True;
}

/*----------------------------------------------------------------------------*/
int charscan(char needle, char* haystack){
  int idx = 0;
  int counter = 0;

  while (idx < strlen(haystack))
  {
    if (needle == haystack[idx]){ counter += 1; }
    idx++;
  };
/*
  (void)printf("character <%c> appears <%d> times in string <%s>\n",
    needle, counter, haystack);
*/
  return counter;
};
