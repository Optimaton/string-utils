---
string-utils: >-
  It is a small lightweight C/C++ library that helps in string utilities like
  searching for a substring, finding the position of substring in a string etc
  but with added functionalities like choosing algorithm
---

# Example:  

## In C
**Prototype of `is_substring` function:**

```
is_substring(haystack, needle, searcher_pos, searcher);
Return type: bool
Arg 1: const char* 
Arg 2: const char*
Arg 3: position in haystack to start search from
Arg 4: searcher is a fancy name for set of algorithms. Please find the list below
```
## **List of algorithms provided for searching:**

>     NAIVE,                 
>     RABIN_KARP,                            
>     KNUTH_MORRIS_PRAT,         
>     AHO_CORASICK,               
>     BOYRE_MOORE,           
>     BITAP, 
>     COMMENTZ_WALTER,  
>     TWO_WAY,  
>     BNDM,  
>     BOM, 
>     SET_BOM

# TODO

## In C++
**Prototype of `contains` function:**
```
String str("Some Random String");
bool is_present = str.contains("ome R", searcher_pos, searcher);
Return type: bool
Arg 1: string literal or another string or char array
Arg 2: position in haystack to start search from
Arg 3: searcher - enumeration of algorithms
```
