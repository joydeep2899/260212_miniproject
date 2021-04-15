#include "unity.h"
#include "huffman.h"
#include "unity_internals.h"

#define PROJECT_NAME    "huffman"
void setUp (void) {} /* Is run before every test, put unit init calls here. */
void tearDown (void) {} /* Is run before every test, put unit init calls here. */


 char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f','x'  }; /* character array */
  int freq[] = { 2, 6, 11, 19, 26, 45 ,65}; /* integer frequency of characters array */
  int size = sizeof(arr) / sizeof(arr[0]); /* size of both arrays  */
    










/* Prototypes for all the test functions */
void test_huffman_code(void);
void test_create_node(void);
void test_create_minheap(void);
void test_insert_minheap(void);
void test_check_leafnode(void);




/* Start of the application test */
int main()
{

  

   
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_huffman_code);
  RUN_TEST(test_create_node);
  RUN_TEST(test_create_minheap);
  RUN_TEST(test_insert_minheap);
  RUN_TEST(test_check_leafnode);

  /* Close the Unity Test Framework */
  return UNITY_END();



}



/**
 * @brief function to test function huffman codes to check if huffman tree is built correctly
 * 
 */
void test_huffman_code(void) {
  TEST_ASSERT_EQUAL(0, huffmancodes(arr, freq,size));
  
  
}


/**
 * @brief function to test function create node which creates node by taking in character and its frequency
 * 
 */
void test_create_node(void){

  TEST_ASSERT_NOT_NULL(createnode('a',33));


}


/**
 * @brief function to test function createminheap which creates a minheap by taking in maximum size of minheap
 * 
 */
void test_create_minheap(void){

   TEST_ASSERT_NOT_NULL(createminheap(100));


}


/**
 * @brief function to test function insert minheap which inserts a heapnode into minheap by taking pointers to minheap and heapnode
 * 
 */
void test_insert_minheap(void){
   Minheap *minheap=createminheap(100);
   heapnode *minheapnode=createnode('e',25);


   TEST_ASSERT_EQUAL(0,insertminheap(minheap,minheapnode));

}


/**
 * @brief function to test function check leafnode  to see if a particular heapnode is a leafnode
 * 
 */
void test_check_leafnode(void){

  heapnode *minheapnode=createnode('e',25);


  TEST_ASSERT_EQUAL(1,checkleafnode(minheapnode));



}