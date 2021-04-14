/**
 * @file huffmantree.c
 * @author joydeep ghosh 
 * @brief project to implement huffman coding 
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
/**
 * @brief function to build huffman tree from array
 * 
 * @param c 
 * @param freq 
 * @param size 
 * @return heapnode* 
 */
heapnode* huffmantree(char c[],int freq[],int size ){

  Minheap* minheap=createandbuildminheap(c,freq,size);

  heapnode *top, *left, *right ;

  while(!(minheap->size==1))
  {
 
    left=popminnode(minheap);
    right=popminnode(minheap);

    top=createnode('$',left->freq+right->freq);
    top->left=left;
    top->right=right;

    insertminheap(minheap,top);




  }
  free(top);

return popminnode(minheap);

}
/**
 * @brief function to print the huffman codes 
 * 
 * @param root 
 * @param ans 
 * @param index 
 */

error_t printhuffmancodes(heapnode* root,int ans[],int index){

  if(root->left)
   { 
    ans[index]=0;
    printhuffmancodes(root->left,ans,index+1);



    }

 if(root->right)
  { 
   ans[index]=1;
   printhuffmancodes(root->right,ans,index+1);

  } 

 if(checkleafnode(root))
  {
    printf("%c: ",root->c);

    printarray(ans,index);
   


  }
  if(ans[0]!=0) 
   return SUCCESS;
  else return FAILED; 


}




/**
 * @brief function to print huffman codes and intialise data structures;
 * 
 * @param c 
 * @param freq 
 * @param size 
 * @return error_t 
 */

error_t huffmancodes(char c[],int freq[], int size){


    heapnode* root=huffmantree(c,freq,size);

    int ans[100],index=0;

   return printhuffmancodes(root,ans,index);
 
    
}