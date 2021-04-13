/**
 * @file huffman.h
 * @author joydeep ghosh (you@domain.com)
 * @brief header file for huffman coding 
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <stdio.h>

#include <stdlib.h>



/**
 * @brief struct to define heapnode
 * 
 */


typedef struct heapnode{

 char c;

 int freq;


 struct heapnode *left, *right;



} heapnode;


/**
 * @brief struct to define minheap
 * 
 */

typedef struct Minheap{

   int size,max_size;


   heapnode** array;

} Minheap;




/**
 * @brief defined enum datatype for error 
 * 
 */
typedef enum error_t {
SUCCESS=0,
FAILED=1



} error_t;



/**
 * @brief function to create a heapnode
 * 
 * @param ch 
 * @param frequency 
 * @return heapnode* 
 */

heapnode* createnode(char ch, int frequency );


/**
 * @brief function to create min heap
 * 
 * @param max_sizeofheap 
 * @return Minheap* 
 */
Minheap* createminheap(int max_sizeofheap);

/**
 * @brief function to swap two heapnodes 
 * 
 * @param a 
 * @param b 
 */

void heapnode_swap(heapnode **a,heapnode **b);



/**
 * @brief function to heapify the heap from the current index
 * 
 * @param minheap 
 * @param index 
 */
 void heapify(Minheap *minheap,int index);

/**
 * @brief extract minimum node from minheap
 * 
 * @param minheap 
 * @return heapnode* 
 */

heapnode* popminnode(Minheap *minheap);


/**
 * @brief function to insert a heapnode into the minheap
 * 
 * @param minheap 
 * @param minheapnode 
 */


void insertminheap(Minheap *minheap,heapnode *minheapnode);

/**
 * @brief function to build minheap
 * 
 * @param minHeap 
 */


void buildMinHeap(Minheap* minHeap);


/**
 * @brief function to print an array of size n 
 * 
 * @param arr 
 * @param n 
 */
void printarray(int arr[],int n);



/**
 * @brief function to check if a particular node is leafnode or not 
 * 
 * @param minheapnode 
 * @return int 
 */

int checkleafnode(heapnode* minheapnode);



/**
 * @brief function to build a minheap from the array
 * 
 * @param c 
 * @param freq 
 * @param size 
 * @return Minheap* 
 */


Minheap* createandbuildminheap(char c[],int freq[] , int size);

/**
 * @brief function to build huffman tree from array
 * 
 * @param c 
 * @param freq 
 * @param size 
 * @return heapnode* 
 */
heapnode* huffmantree(char c[],int freq[],int size );

/**
 * @brief function to print the huffman codes 
 * 
 * @param root 
 * @param ans 
 * @param index 
 */

error_t printhuffmancodes(heapnode* root,int ans[],int index);




/**
 * @brief function to print huffman codes and intialise data structures;
 * 
 * @param c 
 * @param freq 
 * @param size 
 * @return error_t 
 */

error_t huffmancodes(char c[],int freq[], int size);




#endif