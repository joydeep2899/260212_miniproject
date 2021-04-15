#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief main function 
 * 
 * 
 * @return int 
 */
int main(){

   char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f','x'  };/* character array */
   int freq[] = { 2, 6, 11, 19, 26, 45 ,65 }; /* integer frequency of characters array */
 
   int size = sizeof(arr) / sizeof(arr[0]); /* size of both arrays  */
    


    
   huffmancodes(arr, freq, size);
    

    return 0;



}