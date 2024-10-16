#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "sorted_array.h"

/*
 * Test suite for ordered array data structure and algorithms
 */

//precedence relation used in tests
static int precedes_int(const void* i1_p,const void* i2_p){
  int* int1_p = (int*)i1_p;
  int* int2_p = (int*)i2_p;
  if((*int1_p) < (*int2_p))
    return(1);
  return(0);
}



//Data elements that are initialized before each test
static int i1,i2,i3;
static SortedArray *sorted_array_int;

void setUp(void){
  i1 = -12;
  i2 = 0;
  i3 = 4;
  sorted_array_int = sorted_array_create(precedes_int);
}



void tearDown(void){
  sorted_array_free_memory(sorted_array_int);
}


static void test_sorted_array_is_empty_zero_el(void){
  TEST_ASSERT_TRUE(sorted_array_is_empty(sorted_array_int));
}



static void test_sorted_array_is_empty_one_el(void){
 sorted_array_add(sorted_array_int,&i1);
 TEST_ASSERT_FALSE(sorted_array_is_empty(sorted_array_int));
}
  
  
static void test_sorted_array_size_zero_el(void){
  TEST_ASSERT_EQUAL_INT(0,sorted_array_size(sorted_array_int));
}

  
static void test_sorted_array_size_one_el(void){
  sorted_array_add(sorted_array_int,&i1);
  TEST_ASSERT_EQUAL_INT(1,sorted_array_size(sorted_array_int));
}

  
static void test_sorted_array_size_two_el(void){
  sorted_array_add(sorted_array_int,&i1);
  sorted_array_add(sorted_array_int,&i2);
  TEST_ASSERT_EQUAL_INT(2,sorted_array_size(sorted_array_int));
}

  
static void test_sorted_array_add_get_one_el(void){
  sorted_array_add(sorted_array_int,&i1);
  TEST_ASSERT_EQUAL_INT(-12,*(int*)sorted_array_get(sorted_array_int,0));
}

  
static void test_sorted_array_add_get_three_el_added_in_order(void){
  int exp_arr[] = {-12,0,4};
  sorted_array_add(sorted_array_int,&i1);
  sorted_array_add(sorted_array_int,&i2);
  sorted_array_add(sorted_array_int,&i3);
  int act_arr[3]; 
  for(unsigned long i=0;i<3;i++)
    act_arr[i] = *(int*)sorted_array_get(sorted_array_int,i);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr,act_arr,3);
}

static void test_sorted_array_add_get_three_el_added_reverse_order(void){
  int exp_arr[] = {-12,0,4};
  sorted_array_add(sorted_array_int,&i3);
  sorted_array_add(sorted_array_int,&i2);
  sorted_array_add(sorted_array_int,&i1);
  int act_arr[3]; 
  for(unsigned long i=0;i<3;i++)
    act_arr[i] = *(int*)sorted_array_get(sorted_array_int,i);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr,act_arr,3);
}

static void test_sorted_array_add_get_three_el_added_no_order(void){
  int exp_arr[] = {-12,0,4};
  sorted_array_add(sorted_array_int,&i2);
  sorted_array_add(sorted_array_int,&i3);
  sorted_array_add(sorted_array_int,&i1);
  int act_arr[3]; 
  for(unsigned long i=0;i<3;i++)
    act_arr[i] = *(int*)sorted_array_get(sorted_array_int,i);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr,act_arr,3);
}

static void test_sorted_array_add_get_three_el_two_equal(void){
  int exp_arr[] = {0,0,4};
  sorted_array_add(sorted_array_int,&i2);
  sorted_array_add(sorted_array_int,&i3);
  sorted_array_add(sorted_array_int,&i2);
  int act_arr[3]; 
  for(unsigned long i=0;i<3;i++)
    act_arr[i] = *(int*)sorted_array_get(sorted_array_int,i);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr,act_arr,3);
}

static void test_sorted_array_add_get_three_el_all_equal(void){
  int exp_arr[] = {0,0,0};
  sorted_array_add(sorted_array_int,&i2);
  sorted_array_add(sorted_array_int,&i2);
  sorted_array_add(sorted_array_int,&i2);
  int act_arr[3]; 
  for(unsigned long i=0;i<3;i++)
    act_arr[i] = *(int*)sorted_array_get(sorted_array_int,i);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr,act_arr,3);
}

int main(void) {

  //test session
  UNITY_BEGIN();
  
  RUN_TEST(test_sorted_array_is_empty_zero_el);
  RUN_TEST(test_sorted_array_is_empty_one_el);
  RUN_TEST(test_sorted_array_size_zero_el);
  RUN_TEST(test_sorted_array_size_one_el);
  RUN_TEST(test_sorted_array_size_two_el);
  RUN_TEST(test_sorted_array_add_get_one_el);
  RUN_TEST(test_sorted_array_add_get_three_el_added_in_order);
  RUN_TEST(test_sorted_array_add_get_three_el_added_reverse_order);
  RUN_TEST(test_sorted_array_add_get_three_el_added_no_order);
  RUN_TEST(test_sorted_array_add_get_three_el_two_equal);
  RUN_TEST(test_sorted_array_add_get_three_el_all_equal);
  
  return UNITY_END();
}