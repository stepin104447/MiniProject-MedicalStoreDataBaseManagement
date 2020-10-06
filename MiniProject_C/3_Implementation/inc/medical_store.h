#ifndef MEDICAL_STORE_H_INCLUDED
#define MEDICAL_STORE_H_INCLUDED

//#include<windows.h>
#include<stdio.h>
//#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//#include<dos.h>
#include<time.h>
//#include<inttypes.h>

int add_medicine(int id,int choice,char* medName,char* supplierName,int supplierId,char* supplierContact,char* mail,char* companyName,float price,int qty,int rackNo,int cabinNo);
int dispose_medicine(int id1);
int search_medicine(char cho,int id1,char* name);
int sell_medicine(int id1,char cho,int unit1,int searchId,int removeId,char* contactNo,char* customerName);
int list_medicine(void);
int edit_medicine(int id1,char* medName,char* supplierName,int supplierId,char* supplierContact,char* companyName,char* mail,int qty,int rackNo,int cabinNo);
int supplier_info(char cho,int id1);

int get_data(int id,int s,char* medName,char* supplierName,int supplierId,char* supplierContact,char* mail,char* companyName,float price,int qty,int rackNo,int cabinNo);
int check_id(int);
void returnfunc(void);

//void goto_xy(int x,int y);
//{
   // coord.X = x;
   // coord.Y = y;
   // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}


#endif // MEDICAL_STORE_H_INCLUDED
