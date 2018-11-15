/*
 *  Simple example of a CUnit unit test.
 *
 *  This program (crudely) demonstrates a very simple "black box"
 *  test of the standard library functions fprintf() and fread().
 *  It uses suite initialization and cleanup functions to open
 *  and close a common temporary file used by the test functions.
 *  The test functions then write to and read from the temporary
 *  file in the course of testing the library functions.
 *
 *  The 2 test functions are added to a single CUnit suite, and
 *  then run using the CUnit Basic interface.  The output of the
 *  program (on CUnit version 2.0-2) is:
 *
 *           CUnit : A Unit testing framework for C.
 *           http://cunit.sourceforge.net/
 *
 *       Suite: Suite_1
 *         Test: test of fprintf() ... passed
 *         Test: test of fread() ... passed
 *
 *       --Run Summary: Type      Total     Ran  Passed  Failed
 *                      suites        1       1     n/a       0
 *                      tests         2       2       2       0
 *                      asserts       5       5       5       0
 */

#include <stdio.h>
#include <string.h>
//#include <time.h>
#include "CUnit/Basic.h"

#include "Custom_Main.h"
#include "Custom_Circular_Buffer.h"

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
//	srand(time(0));
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}

/* Simple test of fprintf().
 * Writes test data to the temporary file and checks
 * whether the expected number of bytes were written.
 */
void testFPRINTF(void)
{
   int i1 = 10;

   if (NULL != temp_file) {
      CU_ASSERT(0 == fprintf(temp_file, ""));
      CU_ASSERT(2 == fprintf(temp_file, "Q\n"));
      CU_ASSERT(7 == fprintf(temp_file, "i1 = %d", i1));
   }
}

/* Simple test of fread().
 * Reads the data previously written by testFPRINTF()
 * and checks whether the expected characters are present.
 * Must be run after testFPRINTF().
 */
void testFREAD(void)
{
   unsigned char buffer[20];

   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT(9 == fread(buffer, sizeof(unsigned char), 20, temp_file));
      CU_ASSERT(0 == strncmp(buffer, "Q\ni1 = 10", 9));
   }
}

/* test of buffer init
 */
void test_CBuf_Init(void)
{
   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT_FATAL(0 == CBuffer_Init());
   }
}

void test_CBuf_Overwrite(void)
{
   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'A'));
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'B'));
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'C'));
      CU_ASSERT(Overwriting == CBuffer_Byte_Write(0, 'D'));
   }
}

void test_CBuf_Emptyread(void)
{
	Byte data;
   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('D' == data);
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('B' == data);
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('C' == data);
      CU_ASSERT(Empty == CBuffer_Byte_Read(0, &data));
      CU_ASSERT(Empty == CBuffer_Byte_Read(0, &data));
   }
}

void test_CBuf_Partialfill(void)
{
	Byte data;
   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'X'));
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'Y'));
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('X' == data);
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('Y' == data);
      CU_ASSERT(Empty == CBuffer_Byte_Read(0, &data));
   }
}

void test_CBuf_Continuouscomplex(void)
{
	Byte data;
   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'P'));
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'Q'));
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('P' == data);
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'R'));
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'S'));
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('Q' == data);
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('R' == data);
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'T'));
      CU_ASSERT(Success == CBuffer_Byte_Write(0, 'U'));
      CU_ASSERT(Overwriting == CBuffer_Byte_Write(0, 'V'));
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('V' == data);
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('T' == data);
      CU_ASSERT(Success == CBuffer_Byte_Read(0, &data));
      CU_ASSERT('U' == data);
      CU_ASSERT(Empty == CBuffer_Byte_Read(0, &data));
      CU_ASSERT(Empty == CBuffer_Byte_Read(0, &data));
   }
}

void test_CBuf_Numberofelements(void)
{
	Byte data;
   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT(0 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Write(1, 'E'));
      CU_ASSERT(1 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Write(1, 'F'));
      CU_ASSERT(2 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Write(1, 'G'));
      CU_ASSERT(3 == CBuffer_Elements(1));
	  CU_ASSERT(Success == CBuffer_Byte_Write(1, 'H'));
      CU_ASSERT(4 == CBuffer_Elements(1));
	  CU_ASSERT(Success == CBuffer_Byte_Write(1, 'I'));
      CU_ASSERT(5 == CBuffer_Elements(1));
	  CU_ASSERT(Success == CBuffer_Byte_Write(1, 'J'));
      CU_ASSERT(6 == CBuffer_Elements(1));
	  CU_ASSERT(Success == CBuffer_Byte_Write(1, 'K'));
      CU_ASSERT(7 == CBuffer_Elements(1));
	  CU_ASSERT(Success == CBuffer_Byte_Write(1, 'L'));
      CU_ASSERT(8 == CBuffer_Elements(1));
	  CU_ASSERT(Overwriting == CBuffer_Byte_Write(1, 'M'));
	  CU_ASSERT(8 == CBuffer_Elements(1));
      CU_ASSERT(Overwriting == CBuffer_Byte_Write(1, 'N'));
      CU_ASSERT(8 == CBuffer_Elements(1));
      CU_ASSERT(Overwriting == CBuffer_Byte_Write(1, 'O'));
      CU_ASSERT(8 == CBuffer_Elements(1));
      CU_ASSERT(Overwriting == CBuffer_Byte_Write(1, 'P'));
      CU_ASSERT(8 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('M' == data);
      CU_ASSERT(7 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('N' == data);
      CU_ASSERT(6 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('O' == data);
      CU_ASSERT(5 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('P' == data);
      CU_ASSERT(4 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('I' == data);
      CU_ASSERT(3 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('J' == data);
      CU_ASSERT(2 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('K' == data);
      CU_ASSERT(1 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('L' == data);
      CU_ASSERT(0 == CBuffer_Elements(1));
      CU_ASSERT(Empty == CBuffer_Byte_Read(1, &data));
      CU_ASSERT(Empty == CBuffer_Byte_Read(1, &data));
   }
}

void test_CBuf_Runtimelengthchange(void)
{
	Byte data;
   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT(0 == CBuffer_Resize(1));
      CU_ASSERT(0 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Write(1, 'W'));
      CU_ASSERT(1 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Write(1, 'X'));
      CU_ASSERT(2 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Write(1, 'Y'));
      CU_ASSERT(3 == CBuffer_Elements(1));
	  CU_ASSERT(Success == CBuffer_Byte_Write(1, 'Z'));
      CU_ASSERT(4 == CBuffer_Elements(1));
	  CU_ASSERT(Overwriting == CBuffer_Byte_Write(1, 'E'));
      CU_ASSERT(4 == CBuffer_Elements(1));
	  CU_ASSERT(Overwriting == CBuffer_Byte_Write(1, 'F'));
      CU_ASSERT(4 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('E' == data);
      CU_ASSERT(3 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('F' == data);
      CU_ASSERT(2 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('Y' == data);
      CU_ASSERT(1 == CBuffer_Elements(1));
      CU_ASSERT(Success == CBuffer_Byte_Read(1, &data));
      CU_ASSERT('Z' == data);
      CU_ASSERT(0 == CBuffer_Elements(1));
      CU_ASSERT(Empty == CBuffer_Byte_Read(1, &data));
      CU_ASSERT(Empty == CBuffer_Byte_Read(1, &data));
   }
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int t_main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of fprintf()", testFPRINTF)) ||
       (NULL == CU_add_test(pSuite, "test of fread()", testFREAD)) ||
	   (NULL == CU_add_test(pSuite, "test of CBuffer_Init()", test_CBuf_Init)) ||
	   (NULL == CU_add_test(pSuite, "test of CBuffer_Overwrite", test_CBuf_Overwrite)) ||
       (NULL == CU_add_test(pSuite, "test of CBuffer_Emptyread", test_CBuf_Emptyread)) ||
	   (NULL == CU_add_test(pSuite, "test of CBuffer_Partialfill", test_CBuf_Partialfill)) ||
	   (NULL == CU_add_test(pSuite, "test of CBuffer_Continuouscomplex", test_CBuf_Continuouscomplex)) || 
	   (NULL == CU_add_test(pSuite, "test of CBuffer_Numberofelements", test_CBuf_Numberofelements)) ||
	   (NULL == CU_add_test(pSuite, "test of CBuffer_Runtimelengthchange", test_CBuf_Runtimelengthchange)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
