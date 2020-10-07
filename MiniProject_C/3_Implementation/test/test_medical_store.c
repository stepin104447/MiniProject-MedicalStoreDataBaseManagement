#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <medical_store.h>
#define PROJECT_NAME    "MedicalStore"

/* Prototypes for all the test functions */
void test_add_medicine(void);
void test_dispose_medicine(void);
void test_search_medicine(void);
void test_sell_medicine(void);
void test_list_medicine(void);
void test_edit_medicine(void);
void test_supplier_info(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */
  
  
  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "add_medicine", test_add_medicine);
  CU_add_test(suite, "dispose_medicine", test_dispose_medicine);
  CU_add_test(suite, "search_medicine", test_search_medicine);
  CU_add_test(suite, "sell_medicine", test_sell_medicine);
  CU_add_test(suite, "list_medicine", test_list_medicine);
  CU_add_test(suite, "edit_medicne", test_edit_medicine);
  CU_add_test(suite, "supplier_info", test_supplier_info);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  
  /* run the unit test framework*/
  CU_basic_run_tests();
  
  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */ 
void test_add_medicine(void) {
  CU_ASSERT(1 == add_medicine(101,1,"medicine 101","supplier 101",1001,"12341001","supplier1001@gmail.com","company 101",100.00,20,2,3));
  CU_ASSERT(1 == add_medicine(102,1,"medicine 102","supplier 102",1002,"12341002","supplier1002@gmail.com","company 102",150.00,30,4,1));
  CU_ASSERT(1 == add_medicine(103,2,"medicine 103","supplier 103",1003,"12341003","supplier1003@gmail.com","company 103",200.00,40,2,4));
   CU_ASSERT(1 == add_medicine(104,3,"medicine 104","supplier 104",1004,"12341004","supplier1004@gmail.com","company 104",120.00,44,3,2));
   CU_ASSERT(1 == add_medicine(105,4,"medicine 105","supplier 105",1005,"12341005","supplier1005@gmail.com","company 105",140.00,25,5,4));
  
  /* Dummy fail*/
}

void test_dispose_medicine(void) {
  CU_ASSERT(1 == dispose_medicine(101));
  
  /* Dummy fail*/
  
}

void test_search_medicine(void) {
  CU_ASSERT(1 == search_medicine('1',102,"medicine 102"));  //search with id
  CU_ASSERT(1 == search_medicine('2',102,"medicine 102"));  //search with name
  
  /* Dummy fail*/
  
}

void test_sell_medicine(void) {
  CU_ASSERT(1 == sell_medicine(102,'1',5,102,102,"12341021","customer 1021")); //sell medicine
  CU_ASSERT(1 == sell_medicine(102,'3',5,102,102,"12341021","customer 1021"));  // list sold medicine
  CU_ASSERT(1 == sell_medicine(102,'2',5,102,102,"12341021","customer 1021")); // search sold medicine
  CU_ASSERT(1 == sell_medicine(102,'4',5,102,102,"12341021","customer 1021")); // remove sold medicine
  
  /* Dummy fail*/
 
}
                              
void test_list_medicine(void) {
  CU_ASSERT(1 == list_medicine());
  
  /* Dummy fail*/
 
}
                              
void test_edit_medicine(void) {
  CU_ASSERT(1 == edit_medicine(102,"medicine 102","supplier 102",1002,"12341002","company 102","supplier1001@gmail.com",50,1,5));
  
  
  /* Dummy fail*/
 
}
                               
void test_supplier_info(void) {
  CU_ASSERT(1 == supplier_info('1',1001)); //list of suppliers
 //CU_ASSERT(1 == supplier_info('2',1001));  // search supplier
  
  /* Dummy fail*/
 
}


                               
