/**
 * @file huffman.c
 * @author joydeep ghosh (you@domain.com)
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

void insertminheap(Minheap *minheap,heapnode *minheapnode)
{
 minheap->size++;
 int j=minheap->size-1;


 while(j && minheapnode->freq < minheap->array[(j-1)/2]->freq )
   {

    minheap->array[j]=minheap->array[(j-1)/2];
    j=(j-1)/2;


   }

 minheap->array[j]=minheapnode;



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
int status=0;
  if(root->left)
   { status=0;
    ans[index]=0;
    printhuffmancodes(root->left,ans,index+1);



    }

 if(root->right)
  { status=0;
   ans[index]=1;
   printhuffmancodes(root->right,ans,index+1);

  } 

 if(checkleafnode(root))
  {
    printf("%c: ",root->c);

    printarray(ans,index);
   status=1;


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






