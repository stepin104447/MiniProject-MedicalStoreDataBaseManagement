/** 
* @file medical_store.h
* MedicalStore management application with seven major functions
*
*/

#ifndef MEDICAL_STORE_H_INCLUDED
#define MEDICAL_STORE_H_INCLUDED

//#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//#include<dos.h>
//#include<time.h>
#include<inttypes.h>

/**
*  adds the medicine details id,choice,medName,supplierName,supplierId,supplierContact,mail,companyName,price,qty,rackNo,cabinNo and returns the status
* @param[in] id 
* @param[in] choice
* @param[in] medName
* @param[in] supplierName
* @param[in] supplierId
* @param[in] supplierContact
* @param[in] mail
* @param[in] companyName
* @param[in] price
* @param[in] qty
* @param[in] rackNo
* @param[in] cabinNo
* @return status of function success - 1, failure - 0
*/
int add_medicine(int id,int choice,char* medName,char* supplierName,int supplierId,char* supplierContact,char* mail,char* companyName,float price,int qty,int rackNo,int cabinNo);

/**
*  deletes the medicine with ID id1 the operand1, operand2 and returns the status
* @param[in] id1
* @return status of fuction 1-successfully deleted ,0-failed
*/
int dispose_medicine(int id1);

/**
* search for a medicine with ID id1 and medicine name and returns the status
* @param[in] cho 
* @param[in] id1
* @param[in] name
* @return satus of function 1-medicine found 0-failed
*/
int search_medicine(char cho,int id1,char* name);

/**
* sell a medicine with ID id1 if its available, search for a sold medicine with ID searchId, remove a sold medicine with ID removeId and returns the satus
* @param[in] id1
* @param[in] cho 
* @param[in] unit1
* @param[in] searchId
* @param[in] removeId
* @param[in] contactNo
* @param[in] customerName
* @return status of function 1 - success, 0-failed
*/
int sell_medicine(int id1,char cho,int unit1,int searchId,int removeId,char* contactNo,char* customerName);

/**
* list of medicine available in store 
* @return status of function 1 - success, 0 - failure
*/
int list_medicine(void);

/**
* edits the information of an existing medicine with ID id1
* @param[in] id1
* @param[in] medName
* @param[in] supplierName
* @param[in] supplierId
* @param[in] supplierContact
* @param[in] companyName
* @param[in] mail
* @param[in] qty
* @param[in] rackNo
* @param[in] cabinNo
* @return status of function 1-successfully edited, 0 - failed
*/
int edit_medicine(int id1,char* medName,char* supplierName,int supplierId,char* supplierContact,char* companyName,char* mail,int qty,int rackNo,int cabinNo);

/**
* shows the details of all suppliers, search for a supplier with ID id1
* @param[in] cho
* @param[in] id1 
* @return status of function 1 - success, 0 - failed
*/
int supplier_info(char cho,int id1);

/**
* function to get data from user. sub function of add_medicine
* @param[in] id
* @param[in] s
* @param[in] medName
* @param[in] supplierName
* @param[in] supplierId
* @param[in] supplierContact
* @param[in] mail
* @param[in] companyName
* @param[in] price
* @param[in] qty
* @param[in] rackNo
* @param[in] cabinNo
* @return status of function 1-successfully obtained data, 0 -failed
*/
int get_data(int id,int s,char* medName,char* supplierName,int supplierId,char* supplierContact,char* mail,char* companyName,float price,int qty,int rackNo,int cabinNo);

/**
* checks if medicine with ID t already exist
* @param[in] t 
* @return status of function 1 - id doesnt exist, 0 - id exist
*/
int check_id(int t);
//void returnfunc(void);

//void goto_xy(int x,int y);
//{
   // coord.X = x;
   // coord.Y = y;
   // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}


#endif // MEDICAL_STORE_H_INCLUDED
