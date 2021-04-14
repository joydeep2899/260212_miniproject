/**
 * @file huffman.c
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
 * @brief function to create a heapnode
 * 
 * @param ch 
 * @param frequency 
 * @return heapnode* 
 */
heapnode* createnode(char ch, int frequency ){


    heapnode *temp=(heapnode *)malloc(sizeof(heapnode));
    temp->c=ch;
    temp->freq=frequency;
    temp->left=temp->right=NULL;

return temp;


}
/**
 * @brief function to create min heap
 * 
 * @param max_sizeofheap 
 * @return Minheap* 
 */
Minheap* createminheap(int max_sizeofheap){

   Minheap *minheap=(Minheap*)malloc(sizeof(Minheap));
   
    minheap->size=0; 
    minheap->max_size=max_sizeofheap;
    minheap->array=(heapnode**)malloc(max_sizeofheap*sizeof(heapnode*));

return minheap;



}


/**
 * @brief function to swap two heapnodes 
 * 
 * @param a 
 * @param b 
 */


void heapnode_swap(heapnode **a,heapnode **b){
   heapnode* t=*a;
   *a=*b;
   *b=t;

}



/**
 * @brief function to heapify the heap from the current index
 * 
 * @param minheap 
 * @param index 
 */


void heapify(Minheap *minheap,int index)
{

    int smallest_idx=index;

    int left=2*index+1;
    int right=2*index+2;


   if(left<minheap->size&& minheap->array[left]->freq<minheap->array[smallest_idx]->freq)
    {

        smallest_idx=left;


    }
   if(right<minheap->size && minheap->array[right]->freq<minheap->array[smallest_idx]->freq)
     {

         smallest_idx=right;



     } 



   if(smallest_idx!=index)
   {

     heapnode_swap(&minheap->array[smallest_idx],&minheap->array[index]);

     heapify(minheap,smallest_idx);
    }



}















