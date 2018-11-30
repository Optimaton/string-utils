---
string-utils: >-
  It is a small lightweight C/C++ library written in C that helps in string 
  utilities like searching for a substring, finding the position of substring 
  in a string etc but with support for specifying the algorithm of your choice
---

# Example:  

**Prototype of `is_substring` function:**

```c
is_substring(haystack, needle, searcher_pos, searcher);
Return type: bool
Arg 1: const char* 
Arg 2: const char*
Arg 3: position in haystack to start search from
Arg 4: searcher is a fancy name for set of algorithms. Please find the list below
```

## **List of algorithms provided for searching:**
> - [x] `NAIVE`              
> - [x] `RABIN_KARP`                            
> - [ ] `KNUTH_MORRIS_PRAT`       
> - [ ] `AHO_CORASICK`           
> - [ ] `BOYRE_MOORE`           
> - [ ] `BITAP`
> - [ ] `COMMENTZ_WALTER`
> - [ ] `TWO_WAY`  
> - [ ] `BNDM`  
> - [ ] `BOM`
> - [ ] `SET_BOM`

