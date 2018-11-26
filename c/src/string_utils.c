#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <string_utils.h>

SearcherResult
naive_searcher(const char* haystack, uint32_t haystack_size, 
               const char* needle, uint32_t needle_size, uint32_t searcher_pos)
{ 
  SearcherResult searcher_result = {false, NPOS};

  uint8_t mismatch = false;
  int32_t pos = NPOS;
  for (uint32_t i = searcher_pos; i < haystack_size; i++) {
    pos = i;
    for (uint32_t j = 0; j < needle_size; j++) {
      if (haystack[i] != needle[j]) {
        mismatch = true;
        break;
      }
      i++;
    }
    if (mismatch == false) {
      searcher_result.is_present = true;
      searcher_result.pos = pos;
    } else {
      mismatch = false;
    }
  }

  return searcher_result;
}

/* rolling hash */
uint32_t hash(const char* str, uint32_t str_size)
{
  /* hash(str) = 
      ((str[0] * (base^(str_size - 1))) + (str[1] * (base^(str_size-2))) + ... 
        + (str[str_size - 1] * (base ^ 0))) mod m */

  uint32_t base = 10; // TODO: let user decide the base
  uint32_t mod_value = 101; // TODO: let user decide the mod_value
  
  uint32_t idx = 0;
  uint32_t hash = 0;
  while (str_size != 0) {
    hash += str[idx] * pow(base, --str_size); // Optimization required, 
        //  the whole thing has to wait one cycle for -- to complete
    idx++;
  }
  
   return (hash % mod_value);
}


uint32_t subsequent_hash(uint32_t previous_hash, uint32_t str_size, 
                         const char* old_str, const char* new_str)
{
  /* subsequent_hash = (base * (previous_hash - ((base ^ (pattern_size - 1)) * 
      old_pattern[0]))) + new_pattern[pattern_size - 1] mod m */
  uint32_t base = 10; // user must be able to provide this
  uint32_t mod_value = 101; // user must be able to set a mod value
  return  (base * (previous_hash - ((base ^ (str_size - 1)) * 
      old_str[0]))) + new_str[str_size - 1] % mod_value;
}

/**
 * TODO: create context sensitive function to let users to 
 * specify base and mod values in rolling hash
 */
SearcherResult 
rabin_karp_searcher(const char* haystack, uint32_t haystack_size, 
                    const char* needle, uint32_t needle_size, 
                    uint32_t searcher_pos) 
{
  SearcherResult searcher_result = {false, NPOS};
  
  return searcher_result;
}

SearcherResult
knuth_morris_prat_searcher(const char* haystack, uint32_t haystack_size, 
                           const char* needle, uint32_t needle_size, 
                           uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult 
aho_corasick_searcher(const char* haystack, uint32_t haystack_size, 
                      const char* needle, uint32_t needle_size, 
                      uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
boyre_moore_searcher(const char* haystack, uint32_t haystack_size, 
                     const char* needle, uint32_t needle_size, 
                     uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
bitap_searcher(const char* haystack, uint32_t haystack_size, 
               const char* needle, uint32_t needle_size, uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
commentz_walter_searcher(const char* haystack, uint32_t haystack_size, 
                         const char* needle, uint32_t needle_size, 
                         uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
two_way_searcher(const char* haystack, uint32_t haystack_size, 
                 const char* needle, uint32_t needle_size, 
                 uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
bndm_searcher(const char* haystack, uint32_t haystack_size, 
              const char* needle, uint32_t needle_size, uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
bom_searcher(const char* haystack, uint32_t haystack_size, const char* needle,
             uint32_t needle_size, uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
set_bom_searcher(const char* haystack, uint32_t haystack_size, 
                 const char* needle, uint32_t needle_size, 
                 uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

uint32_t 
get_size(const char* str)
{
  uint32_t str_size = 0;
  if (str != NULL) {
    for (uint32_t i = 0; str[i] != '\0'; i++) {
      str_size++;
    }
  }
  return str_size;
}

SearcherResult 
search(const char* haystack, const char* needle, uint32_t searcher_pos, 
       const Searcher searcher)
{
  SearcherResult searcher_result = {false, NPOS}; /* default intialize to not found */
  if (haystack == NULL || needle == NULL) {
    return searcher_result;
  }

  uint32_t haystack_size = get_size(haystack);
  if (searcher_pos > 0) {
    haystack_size = haystack_size - searcher_pos + 1;
  }
  uint32_t needle_size = get_size(needle);

  if (haystack_size < needle_size) {
    return searcher_result;
  }
  
  switch(searcher) {
    case NAIVE: 
      searcher_result = naive_searcher(haystack, haystack_size, needle, 
                                       needle_size, searcher_pos);
      break;
    case RABIN_KARP: 
      searcher_result = rabin_karp_searcher(haystack, haystack_size, needle, 
                                            needle_size, searcher_pos);
      break;
    case KNUTH_MORRIS_PRAT: 
      searcher_result = knuth_morris_prat_searcher(haystack, haystack_size, needle, 
                                                  needle_size, searcher_pos);
      break;
    case AHO_CORASICK: 
      searcher_result = aho_corasick_searcher(haystack, haystack_size, needle, 
                                              needle_size, searcher_pos);
      break;
    case BOYRE_MOORE: 
      searcher_result = boyre_moore_searcher(haystack, haystack_size, needle, 
                                             needle_size, searcher_pos);
      break;
    case BITAP:
      searcher_result = bitap_searcher(haystack, haystack_size, needle, 
                                       needle_size, searcher_pos);
      break;
    case COMMENTZ_WALTER:
      searcher_result = commentz_walter_searcher(haystack, haystack_size, 
                                                 needle, needle_size, 
                                                 searcher_pos);
      break;
    case TWO_WAY:
      searcher_result = two_way_searcher(haystack, haystack_size, needle, 
                                         needle_size, searcher_pos);
      break;
    case BNDM:
      searcher_result = bndm_searcher(haystack, haystack_size, needle, 
                                      needle_size, searcher_pos);
      break;
    case BOM:
      searcher_result = bom_searcher(haystack, haystack_size, needle, 
                                     needle_size, searcher_pos);
      break;
    case SET_BOM: 
      searcher_result = set_bom_searcher(haystack, haystack_size, needle, 
                                         needle_size, searcher_pos);
      break;
  } 

  return searcher_result;
}

bool 
is_substring(const char* haystack, const char* needle, uint32_t searcher_pos,
             Searcher searcher)
{
  SearcherResult searcher_result = search(haystack, needle, searcher_pos,
                                          searcher);
  return searcher_result.is_present;
}

int32_t
find_pos(const char* haystack, const char* needle, uint32_t searcher_pos,
         Searcher searcher)
{
  SearcherResult searcher_result = search(haystack, needle, searcher_pos,
                                          searcher);
  return searcher_result.pos;
}

