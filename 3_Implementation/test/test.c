#include "unity.h"
#include "huffman.h"
#include "unity_internals.h"

#define PROJECT_NAME    "huffman"
void setUp (void) {} /* Is run before every test, put unit init calls here. */
void tearDown (void) {} /* Is run before every test, put unit init calls here. */


 char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f'  };
  int freq[] = { 5, 9, 12, 13, 16, 45 };
  int size = sizeof(arr) / sizeof(arr[0]);
    










/* Prototypes for all the test functions */
void test_huffman_code(void);

/* Write all the test functions */ 


/* Required by the unity test framework */


/* Start of the application test */
int main()
{

  

   
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_huffman_code);
  

  /* Close the Unity Test Framework */
  return UNITY_END();



}

void test_huffman_code(void) {
  TEST_ASSERT_EQUAL(0, huffmancodes(arr, freq,size));
  
  /* Dummy fail*/
 // TEST_ASSERT_EQUAL(1, huffmancodes(arr, freq,size));
}
