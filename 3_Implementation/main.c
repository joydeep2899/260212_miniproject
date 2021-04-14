#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f'  };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
    
   huffmancodes(arr, freq, size);
    

  // printf("%d",createandbuildminheap(arr,freq,size));
 
    return 0;



}