#include <stdio.h>
#include <stdlib.h>

typedef struct heapnode{

char c;

int freq;


struct heapnode *left, *right;



} heapnode;

typedef struct Minheap{



int size;

int max_size;

heapnode** array;





} Minheap;


Minheap* createnode(char ch, int frequency ){


heapnode *temp=(heapnode *)malloc(sizeof(heapnode));
temp->c=ch;
temp->freq=frequency;
temp->left=temp->right=NULL;

return temp;


}

Minheap* createminheap(int max_sizeofheap){

Minheap *minheap=(Minheap*)malloc(sizeof(Minheap));

minheap->max_size=max_sizeofheap;
minheap->size=0;
minheap->array=(heapnode**)malloc(max_sizeofheap*sizeof(heapnode*));

return minheap;



}


void heapnode_swap(heapnode **a,heapnode **b){
heapnode* t=*a;
*a=*b;
*b=t;





}

void heapify(Minheap *minheap,int index){

int smallest_idx=index;

int left=2*index+1;
int right=2*index+2;


if(left<minheap->size&& minheap->array[left]->freq<minheap->array[smallest_idx]->freq){

smallest_idx=left;


}
if(right<minheap->size&& minheap->array[right]->freq<minheap->array[smallest_idx]->freq){

smallest_idx=right;



}

if(smallest_idx!=index){


    heapnode_swap(&minheap->array[smallest_idx],&minheap->array[index]);
}








}









void main(){

heapnode a;










































}