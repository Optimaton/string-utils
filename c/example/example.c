#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string_utils.h>

int main()
{
  /* NAIVE */
  printf("String: Software Development, Substring: Develop, Searcher Pos: 0, Searcher: Naive\n");
  printf("IS PRESENT: %d\n", is_substring("Software Development", "Develop", 0, NAIVE));
  printf("POSITION: %d\n", find_pos("Software Development", "Develop", 0, NAIVE));
 
  printf("String: Software Development, Substring: Leverage the handle, Searcher Pos: 13, Searcher: Naive\n");
  printf("IS_PRESENT: %d\n", is_substring("Software Development", "Leverage the handle", 0, NAIVE));
  printf("POSITION: %d\n", find_pos("Software Development", "Leverage the handle", 0, NAIVE));
 
  /* RABIN KARP */
  printf("String: Software Development, Substring: Develop, Searcher Pos: 7, Searcher: Rabin Karp\n");
  printf("IS PRESENT: %d\n", is_substring("Software Development", "Develop", 7, RABIN_KARP));
  printf("POSITION: %d\n", find_pos("Software Development", "Develop", 7, RABIN_KARP));

  printf("String: Software Development, Substring: Leverage the handle, Searcher Pos: 13, Searcher: Rabin Karp\n");
  printf("IS_PRESENT: %d\n", is_substring("Software Development", "Leverage the handle", 0, RABIN_KARP));
  printf("POSITION: %d\n", find_pos("Software Development", "Leverage the handle", 0, RABIN_KARP));
 
  return 0;
}

