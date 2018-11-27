#ifndef __STRING_UTILS__
#define __STRING_UTILS__
#define NPOS -1

/* Enumeration for choosing an algorithm of choice */
enum Searcher_t {
  NAIVE,
  RABIN_KARP,
  KNUTH_MORRIS_PRAT,
  AHO_CORASICK,
  BOYRE_MOORE,
  BITAP,
  COMMENTZ_WALTER,
  TWO_WAY,
  BNDM,
  BOM,
  SET_BOM
};

typedef enum Searcher_t Searcher;

/* Although there is an overhead of an extra element 
 * at any given point but the advantage of use in 
 * apis is more than that */
struct SearcherResult_t {
  bool is_present;
  int32_t pos;
};

typedef struct SearcherResult_t SearcherResult;

struct RollingHash_t {
  uint32_t dividend;  /* We are storing it to get back previous before mod */
  uint32_t remainder; /* remainder is our real hash */
};

typedef struct RollingHash_t RollingHash;

/* helper function to get the size of the string */
uint32_t get_size(const char* str);
RollingHash hash(const char* str, uint32_t str_size);
RollingHash subsequent_hash(RollingHash previous_hash, uint32_t str_size,
                            const char* old_str, const char* new_str);

/* naive search - O(nm) */
SearcherResult 
naive_searcher(const char* haystack, uint32_t haystack_size, 
               const char* needle, uint32_t needle_size, 
               uint32_t searcher_pos);

/* rabin karp - hash based search - O(n+m) */
SearcherResult 
rabin_karp_searcher(const char* haystack, uint32_t haystack_size, 
                    const char* needle, uint32_t needle_size, 
                    uint32_t searcher_pos);

/* kmp - uses past match data - O(n) */
SearcherResult 
knuth_morris_prat_searcher(const char* haystack, uint32_t haystack_size, 
                           const char* needle, uint32_t needle_size, 
                           uint32_t searcher_pos);

/* aho corasick - dictionary matching - O(m+n+z), z = match count */
SearcherResult 
aho_corasick_searcher(const char* haystack, uint32_t haystack_size, 
                      const char* needle, uint32_t needle_size, 
                      uint32_t searcher_pos);

/* boyre moore - bad character - O(n+m)*/
SearcherResult 
boyre_moore_searcher(const char* haystack, uint32_t haystack_size, 
                     const char* needle, uint32_t needle_size, 
                     uint32_t searcher_pos);

/**/
SearcherResult 
bitap_searcher(const char* haystack, uint32_t haystack_size, 
               const char* needle, uint32_t needle_size, 
               uint32_t searcher_pos);

/**/
SearcherResult 
commentz_walter_searcher(const char* haystack, uint32_t haystack_size, 
                         const char* needle, uint32_t needle_size, 
                         uint32_t searcher_pos);

/**/
SearcherResult 
two_way_searcher(const char* haystack, uint32_t haystack_size, 
                 const char* needle, uint32_t needle_size, 
                 uint32_t searcher_pos);

/**/
SearcherResult 
bndm_searcher(const char* haystack, uint32_t haystack_size, const char* needle,
              uint32_t needle_size, uint32_t searcher_pos);

/**/
SearcherResult 
bom_searcher(const char* haystack, uint32_t haystack_size, const char* needle, 
             uint32_t needle_size, uint32_t searcher_pos);

/**/
SearcherResult 
set_bom_searcher(const char* haystack, uint32_t haystack_size, 
                 const char* needle, uint32_t needle_size, 
                 uint32_t searcher_pos);


/* Driver function to pick and run algorithms */
SearcherResult search(const char* haystack, const char* needle,
                      uint32_t searcher_pos, const Searcher searcher);

/**
 * decl: is_substring(haystack, needle, searcher);
 */
bool is_substring(const char* haystack, const char* needle,
                  uint32_t searcher_pos, const Searcher searcher);

/**
 * decl: find_pos(haystack, needle, searcher_pos, searcher);
 */
int32_t find_pos(const char* needle, const char* haystack, 
                  uint32_t searcher_pos, const Searcher searcher);

#endif // __STRING_UTILS__
