# strutil
It is a small lightweight C/C++ library written in C that helps in string utilities like searching for a substring, finding the position of substring in a string etc but with support for specifying the algorithm of your choice.

## The why ?
Just for fun. 

## Usage
It is pretty simple to use.
If you wish to use it as a library, I mean a static lib(.o file):
1. go to root dir of this project, 
2. run `gcc -std=c99 -I include/ example/* src/* -o string_utils.o -lm`
3. run `ar -rc libstringutils.a string_utils.o`
4. Now just add it to your Makefile, CMakeLists or if you are using just for one time, call it from command line with gcc like this: `gcc -std=c99 -I <path-to-your-include> <your-source-dirs> -L <path-to-libstringutils.a>`-lm

If you wish to use it as is:
1. Just copy the src to your src,
2. Copy the header file to the include dir and you are good to go, it is just a single file as of now.
3.  You are good to go.

## API Usage
***Note:*** There are only two functions as of now, will extend once all the algorithms for the given two functions are implemented.
### 1. Find if the string contains the substring:
```c
is_substring(haystack, needle, searcher_pos, searcher);
Return type: bool
Arg 1: const char* 
Arg 2: const char*
Arg 3: position in haystack to start search from
Arg 4: searcher is a fancy name for set of algorithms. Please find the list below
```
### 2. Find the position of th substring in the main string:
```c
find_pos(haystack, needle, searcher_pos, searcher);
Return type: bool
Arg 1: const char* 
Arg 2: const char*
Arg 3: position in haystack to start search from
Arg 4: searcher is a fancy name for set of algorithms. Please find the list below
```


## **List of algorithms provided for searching:**
> ***Searchers***
> - [x] `NAIVE`              
> - [x] `RABIN_KARP`                            
> - [x] `KNUTH_MORRIS_PRAT`       
> - [ ] `AHO_CORASICK`           
> - [ ] `BOYRE_MOORE`           
> - [ ] `BITAP`
> - [ ] `COMMENTZ_WALTER`
> - [ ] `TWO_WAY`  
> - [ ] `BNDM`  
> - [ ] `BOM`
> - [ ] `SET_BOM`



