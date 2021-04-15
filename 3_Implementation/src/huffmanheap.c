
/**
 * @file huffmanheap.c
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
 * @brief extract minimum node from minheap
 * 
 * @param minheap 
 * @return heapnode* 
 */


heapnode* popminnode(Minheap *minheap){

  heapnode *temp=minheap->array[0];


  minheap->array[0]=minheap->array[minheap->size-1];
  --minheap->size;

  heapify(minheap,0);


  return temp;
}


/**
 * @brief function to insert a heapnode into the minheap
 * 
 * @param minheap 
 * @param minheapnode 
 */

error_t insertminheap(Minheap *minheap,heapnode *minheapnode)
{
 minheap->size++;
 int j=minheap->size-1;


 while(j && minheapnode->freq < minheap->array[(j-1)/2]->freq )
   {

    minheap->array[j]=minheap->array[(j-1)/2];
    j=(j-1)/2;


   }

 minheap->array[j]=minheapnode;

 if(minheap->size>0){

   return SUCCESS;
 }
 else return FAILED;

}

/**
 * @brief function to build minheap
 * 
 * @param minHeap 
 */


void buildMinHeap(Minheap* minHeap)
 {
 
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(minHeap, i);



}

/**
 * @brief function to print an array of size n 
 * 
 * @param arr 
 * @param n 
 */

void printarray(int arr[],int n)
{
 int i=0;

 for(i=0; i<n;i++ ){

     printf("%d",arr[i]);
     
 }
 printf("\n");


}





/**
 * @brief function to check if a particular node is leafnode or not 
 * 
 * @param minheapnode 
 * @return int 
 */
int checkleafnode(heapnode* minheapnode){

 return !(minheapnode->left) && !(minheapnode->right);

}


/**
 * @brief function to build a minheap from the array
 * 
 * @param c 
 * @param freq 
 * @param size 
 * @return Minheap* 
 */

Minheap* createandbuildminheap(char c[],int freq[] , int size) 
{

 int i=0;

 Minheap *minheap= createminheap(size);

 for(i=0;i<size;i++)
 {
   minheap->array[i]=createnode(c[i],freq[i]);


  }


  minheap->size=size;

  buildMinHeap(minheap);

  return minheap;




}