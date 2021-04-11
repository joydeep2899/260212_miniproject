#include <stdio.h>
#include <stdlib.h>

typedef struct heapnode{

 char c;

 int freq;


 struct heapnode *left, *right;



} heapnode;



typedef struct Minheap{

   int size,max_size;


   heapnode** array;

} Minheap;





heapnode* createnode(char ch, int frequency ){


    heapnode *temp=(heapnode *)malloc(sizeof(heapnode));
    temp->c=ch;
    temp->freq=frequency;
    temp->left=temp->right=NULL;

return temp;


}

Minheap* createminheap(int max_sizeofheap){

   Minheap *minheap=(Minheap*)malloc(sizeof(Minheap));
   
    minheap->size=0; 
    minheap->max_size=max_sizeofheap;
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
 if(right<minheap->size && minheap->array[right]->freq<minheap->array[smallest_idx]->freq){

  smallest_idx=right;



 }



 if(smallest_idx!=index){

    heapnode_swap(&minheap->array[smallest_idx],&minheap->array[index]);

    heapify(minheap,smallest_idx);
 }



}


//extract minimum node from minheap
heapnode* popminnode(Minheap *minheap){

  heapnode *temp=minheap->array[0];


  minheap->array[0]=minheap->array[minheap->size-1];
  --minheap->size;

  heapify(minheap,0);


  return temp;
}


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


void buildMinHeap(Minheap* minHeap)
 {
 
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(minHeap, i);



}

void printarray(int arr[],int n)
{
 int i=0;

 for(i=0; i<n;i++ ){

     printf("%d",arr[i]);
     
 }
 printf("\n");


}


int checkleafnode(heapnode* minheapnode){

 return !(minheapnode->left) && !(minheapnode->right);

}




Minheap* createandbuildminheap(char c[],int freq[] , int size) 
{

 int i=0;

 Minheap *minheap= createminheap(size);

 for(i=0;i<size;i++){
 minheap->array[i]=createnode(c[i],freq[i]);


}


minheap->size=size;

buildMinHeap(minheap);

return minheap;




}










heapnode* huffmantree(char c[],int freq[],int size ){

  Minheap* minheap=createandbuildminheap(c,freq,size);

  heapnode *top, *left, *right ;

  while(!(minheap->size==1)){
 
    left=popminnode(minheap);
    right=popminnode(minheap);

    top=createnode('$',left->freq+right->freq);
    top->left=left;
    top->right=right;

    insertminheap(minheap,top);




}

return popminnode(minheap);

}


void printhuffmancodes(heapnode* root,int ans[],int index){

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


}




void huffmancodes(char c[],int freq[], int size){


    heapnode* root=huffmantree(c,freq,size);

    int ans[100],index=0;

    printhuffmancodes(root,ans,index);

 
    
}







int main(){

char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f'  };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
    
   huffmancodes(arr, freq, size);
    

  // printf("%d",createandbuildminheap(arr,freq,size));
 
    return 0;



}