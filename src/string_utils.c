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

  uint8_t mismatch = true;
  int32_t pos = NPOS;
  for (uint32_t i = searcher_pos; i < haystack_size; i++) {
    pos = i;
    for (uint32_t j = 0; j < needle_size; j++) {
      if (haystack[i] != needle[j]) {
        break;
      }
      if (j == needle_size - 1) { 
        mismatch = false; 
      }
      i++;
    }
    if (mismatch == false) {
      searcher_result.is_present = !mismatch;
      searcher_result.pos = pos;
      break;
    }
  }

  return searcher_result;
}

static uint32_t base = 17;
static uint32_t mod_val = 101;

void
set_rolling_hash_base(uint32_t cbase)
{
  base = cbase;
}

void
set_rolling_hash_mod(uint32_t cmod_val)
{
  mod_val = cmod_val;
}

/* rolling hash */
RollingHash hash(const char* str, uint32_t str_size)
{
  /* hash(str) = 
      ((str[0] * (base^(str_size - 1))) + (str[1] * (base^(str_size-2))) + ... 
        + (str[str_size - 1] * (base ^ 0))) mod m */
  RollingHash hash = {0, 0};

  uint32_t idx = 0;
  while (str_size != 0) {
    hash.dividend += str[idx] * pow(base, --str_size); // Optimization required, 
        //  the whole thing has to wait one cycle for -- to complete
    idx++;
  }
  
  hash.remainder = hash.dividend % mod_val;
  return hash;
}


RollingHash subsequent_hash(RollingHash previous_hash, uint32_t str_size, 
                            const char* old_str, const char* new_str)
{
  /* subsequent_hash = (base * (previous_hash - ((base ^ (pattern_size - 1)) * 
      old_pattern[0]))) + new_pattern[pattern_size - 1] mod m */
  RollingHash new_hash = {0, 0};
  new_hash.dividend = (base * (previous_hash.dividend - (pow(base, str_size - 1) * 
     old_str[0]))) + new_str[str_size - 1];

  new_hash.remainder = new_hash.dividend % mod_val;

  return new_hash;
}


SearcherResult 
rabin_karp_searcher(const char* haystack, uint32_t haystack_size, 
                    const char* needle, uint32_t needle_size, 
                    uint32_t searcher_pos) 
{
  SearcherResult searcher_result = {false, NPOS};
  
  if (strlen(haystack + searcher_pos) < needle_size) {
    return searcher_result;
  }
  
  RollingHash needle_hash = hash(needle, needle_size);
  RollingHash haystack_hash = hash(haystack + searcher_pos, needle_size);

  uint8_t mismatch = true;
  int32_t pos = NPOS;
  for (uint32_t i = searcher_pos; i < haystack_size; i++) {
    pos = i;
    if (needle_hash.remainder != haystack_hash.remainder) {
     haystack_hash = subsequent_hash(haystack_hash, needle_size, 
                                     haystack + i, haystack + i + 1);
    } else {
      mismatch = false;
      break;
    } 
  }

  if (mismatch == false) {
    int j = 0;
    for (uint32_t i = pos; i < needle_size; i++) {
      if (haystack[i] != needle[j]) {
        mismatch = true;
        break;
      }
      j++;
    }
  }

  if (mismatch == false) {
    searcher_result.is_present = !mismatch;
    searcher_result.pos = pos;
  }

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
  uint32_t needle_size = get_size(needle);

  // user has to specify searcher_pos
  if (haystack_size + searcher_pos < needle_size) {
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

