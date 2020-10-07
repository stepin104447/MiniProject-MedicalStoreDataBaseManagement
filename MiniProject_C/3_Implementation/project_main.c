#include "medical_store.h"
#include<stdio.h>
#include<string.h>
//#include<conio.h>

//COORD coord = {0,0};
//void goto_xy(int x,int y)
//{
  //  coord.X = x;
  //  coord.Y = y;
   // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}


void Password(void);
void main_menu(void);
void close_application();

int s;
char password[]={"admin"};


int main()
{
    Password();
   // getch();
    return(0);
}
void close_application()
{
    system("cls");
   // goto_xy(16,3);
    printf("\tMEDICAL STORE MANAGEMENT SYSTEM");
   // goto_xy(16,6);
    printf("\n Mini Project in C");
   // goto_xy(16,8);
    printf("\n******************************************");
    //goto_xy(16,10);
    printf("\n*******************************************");
    //goto_xy(16,11);
    printf("\n*******************************************");
   // goto_xy(16,13);
    printf("\n********************************************");
    //goto_xy(10,17);
    printf("\nExiting in 3 second...........>");
    //flushall();
   // Sleep(3000);
    exit(0);
}

void Password(void)
{
    system("cls");
    char ch,pass[10];
    char d[]=" Password Protected";
    int i=0;

   // goto_xy(10,4); 
    for(i=0;i<20;i++)
    {
       // Sleep(50);
        printf("#");
    }
    for(i=0;i<20;i++)
    {
       // Sleep(50);
        printf("%c",d[i]);
    }
    for(i=0;i<20;i++)
    {
       // Sleep(50);
        printf("#");
    }
    i=0;
   // goto_xy(15,7);
    scanf("Enter Password :  %s",pass);
   
  /*
  while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i]=ch;
            i++;
        }
    }
    
    pass[i]='\0';
    */
    if(strcmp(pass,password)==0)
    {
        //goto_xy(15,25);
        printf(" password match");
       // goto_xy(15,27);
        printf(" enter any key to continue\n");
       // goto_xy(42,27);
       // getch();
        main_menu();
    }
    else
    {
       // goto_xy(15,25);
        printf("Warning!! incorrect password. Try Again.");
       // goto_xy(56,25);
       // getch();
        Password();
    }
}


void main_menu(void)
{

    system("cls");
    //int i;
   // goto_xy(20,3);
    printf("\n\t\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE  MAIN MENU \xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE");
    //goto_xy(20,5);
    printf("\n\xDB\xDB\xDB\xDB\xB2 1. Add Medicine  ");
    //goto_xy(20,7);
    printf("\n\xDB\xDB\xDB\xDB\xB2 2. Dispose Medicine");
   // goto_xy(20,9);
    printf("\n\xDB\xDB\xDB\xDB\xB2 3. Search Medicine");
    //goto_xy(20,11);
    printf("\n\xDB\xDB\xDB\xDB\xB2 4. Sell Medicine");
    //goto_xy(20,13);
    printf("\n\xDB\xDB\xDB\xDB\xB2 5. List Medicine");
    //goto_xy(20,15);
    printf("\n\xDB\xDB\xDB\xDB\xB2 6. Edit Medicine");
    //goto_xy(20,17);
    printf("\n\xDB\xDB\xDB\xDB\xB2 7. Supplier Information");
    //goto_xy(20,19);
    printf("\n\xDB\xDB\xDB\xDB\xB2 8. Close Application");
    //goto_xy(20,21);
    printf("\n\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\
\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE");
   // goto_xy(20,22);
    //t(); display time
    //goto_xy(20,23);
    printf("\nEnter your choice:");
    scanf("%d",&s);
        switch(s)
        {
            case 1:
            {
                int ret;
                system("cls");
                int choice,id,supplierId,rackNo,cabinNo,qty;
                float price;
                char medName[20],supplierName[20],supplierContact[20],mail[30],companyName[20];


                system("cls");
               // goto_xy(20,5);
                printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT MEDICINE CATEGORY \
\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
               // goto_xy(20,7);
                printf("\n\xDB\xDB\xDB\xDB\xB2 1. Tablets");
               // goto_xy(20,9);
                printf("\n\xDB\xDB\xDB\xDB\xB2 2. Capsules");
                //goto_xy(20,11);
                printf("\n\xDB\xDB\xDB\xDB\xB2 3. Drops");
                //goto_xy(20,13);
                printf("\n\xDB\xDB\xDB\xDB\xB2 4. Inhalers");
               // goto_xy(20,15);
                printf("\n\xDB\xDB\xDB\xDB\xB2 5. Syrup");
                //goto_xy(20,17);
                printf("\n\xDB\xDB\xDB\xDB\xB2 6. others");
               // goto_xy(20,19);
                printf("\n\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
                //goto_xy(20,21);
                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                //goto_xy(20,22);
                printf("\nEnter your choice:");
                scanf("%d",&choice);
                if(choice==7)
                    main_menu();
                system("cls");
                int t;
               // goto_xy(20,3);
                printf("\nEnter information");
               // goto_xy(20,7);
                printf("\nMedicine Id : ");
               // goto_xy(40,7);
                scanf("%d",&id);
                fflush(stdin);
               // goto_xy(20,9);

                printf("\nMedicine Name : ");
               // goto_xy(40,9);
                scanf("%[^\n]%*c", medName);
                fflush(stdin);

                //goto_xy(20,10);
                printf("\nsupplier name : ");
                //goto_xy(40,10);
                scanf("%[^\n]%*c", supplierName);
                fflush(stdin);
                //scanf("%s",a.supplierName);
                //goto_xy(20,11);
                printf("\nsupplier ID : ");
                //goto_xy(40,11);
                scanf("%d",&supplierId);
                fflush(stdin);
                //goto_xy(20,12);
                printf("\nsupplier contact : ");
                //goto_xy(40,12);
                scanf("%s",supplierContact);
                fflush(stdin);
                //goto_xy(20,13);
                printf("\nSupplier Email : ");
                //goto_xy(40,13);
                scanf("%[^\n]%*c",mail);
                fflush(stdin);
                //goto_xy(20,14);
                printf("\nCompany Name : ");
                //goto_xy(40,14);
                scanf("%[^\n]%*c", companyName);
                fflush(stdin);
               // goto_xy(20,15);
                printf("\nprice : ");
               // goto_xy(40,15);
                scanf("%f",&price);
                //goto_xy(20,16);
                printf("\nquantity : ");
                //goto_xy(40,16);
                scanf("%d",&qty);
                //goto_xy(20,17);
                printf("\nrack no : ");
               // goto_xy(40,17);
                scanf("%d",&rackNo);
                //goto_xy(20,18);
                printf("\ncabin no : ");
               // goto_xy(40,18);
                scanf("%d",&cabinNo);
                system("cls");


                ret=add_medicine(id,choice,medName,supplierName,supplierId,supplierContact,mail,companyName,price,qty,rackNo,cabinNo);
                printf("\n return value of add medicine = %d",ret);
                //getch();
                main_menu();
            }
            break;
            case 2:
            {
                int id1,ret;
                system("cls");
               // goto_xy(10,2);
                printf("\n\tDelete Medicine");
               // goto_xy(10,3);
                printf("\n\t******************");
               // goto_xy(10,5);
                printf("\nEnter the Medicine ID to  delete:");
                scanf("%d",&id1);
                ret=dispose_medicine(id1);
                printf("\n return value of dispose medicine = %d",ret);
               // getch();
                main_menu();
            }
            break;
            case 3:
            {
                int ret;
                char cho;
                char name[25];
                int id1=0;
              
                strcpy(name," ");

                system("cls");

                printf("\n\t\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9 SEARCH MEDICINE \
\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9");

               // goto_xy(20,10);
                printf("\n\xDB\xDB\xDB\xDB\xDB 1. Search by ID ");
               // goto_xy(20,12);
                printf("\n\xDB\xDB\xDB\xDB\xDB 2. Search by Name ");
               // goto_xy(20,15);
                printf("\nEnter your choice");
                scanf("%c",&cho);
               // cho=getch();
                if(cho=='1')
                {
                    system("cls");
                    //goto_xy(25,4);
                    printf("\n\t******************** Search By ID ******************");
                    //goto_xy(25,6);
                    printf("\nEnter ID : ");
                   // goto_xy(39,6);
                    scanf("%d",&id1);
                    ret=search_medicine(cho,id1,name);
                    printf("\n return value of search = %d",ret);
                }
                else
                {
                    system("cls");
                    char s[15];
                   // goto_xy(25,4);
                    printf("\n\t************** Search By Name **************");
                   // goto_xy(25,6);
                    printf("\nEnter name : ");
                  //  goto_xy(45,6);
                    fflush(stdin);
                    scanf("%[^\n]%*c", name);
                    ret=search_medicine(cho,id1,name);
                    printf("\nreturn value of search = %d",ret);
                }
               // getch();
                main_menu();

            }
            break;
            case 4:
            {
                int id1=0,unit1=0,searchId=0,removeId=0,ret;
                char customerName[30],contactNo[30];
              
                char cho;
                system("cls");
                //goto_xy(2,2);
                printf("\n\t************************* SELL MEDICINE ************************");
               // goto_xy(10,5);
                printf("\n\xDB\xDB\xDB\xDB\xDB 1. Sell Medicine");
               // goto_xy(10,7);
                printf("\n\xDB\xDB\xDB\xDB\xDB 2. List Sold Medicines");
               // goto_xy(10,9);
                printf("\n\xDB\xDB\xDB\xDB\xDB 3. Search Sold Medicine");
               // goto_xy(10,11);
                printf("\n\xDB\xDB\xDB\xDB\xDB 4. Remove Sold Medicine");
                //goto_xy(10,13);
                printf("\n\xDB\xDB\xDB\xDB\xDB 5. Main Menu");
                //goto_xy(10,15);
                printf("\nEnter your choice : ");
                 scanf("%c",&cho);
                //cho =getch();
                if(cho=='1')
                {
                    system("cls");
                   // goto_xy(22,4);
                    printf("\n\tSELL MEDICINE");
                   // goto_xy(20,5);
                    printf("\n\t******************");
                   // goto_xy(21,7);
                    printf("\nMedicine ID : ");
                    scanf("%d",&id1);
                   //goto_xy(21,8);
                    printf("\nName of Customer : ");
                    fflush(stdin);
                    scanf("%[^\n]%*c", customerName);
                   // goto_xy(21,9);
                    printf("\nContact No : ");
                    scanf("%s",contactNo);
                    //goto_xy(21,10);
                    printf("\nUnits Needed : ");
                    scanf("%d",&unit1);


                    ret=sell_medicine(id1,cho,unit1,searchId,removeId,contactNo,customerName);
                }
                if(cho=='2')
                {
                    ret=sell_medicine(id1,cho,unit1,searchId,removeId,contactNo,customerName);
                }
                if(cho=='3')
                {
                    system("cls");
                    //goto_xy(10,2);
                    printf("\nSearch Sold Medicines");
                   // goto_xy(10,3);
                    printf("\n***********************");
                    //goto_xy(10,6);
                    printf("\nEnter Medicine Id : ");
                    scanf("%d",&searchId);
                    ret=sell_medicine(id1,cho,unit1,searchId,removeId,contactNo,customerName);
                }
                if(cho=='4')
                {
                     system("cls");
                   // goto_xy(10,2);
                    printf("\nRemove Medicine From Sold List");
                   // goto_xy(10,3);
                    printf("\n********************************");
                   // goto_xy(10,5);
                    printf("\nEnter Medicine ID to remove:");
                    scanf("%d",&removeId);
                    ret=sell_medicine(id1,cho,unit1,searchId,removeId,contactNo,customerName);
                }
                if(cho=='5')
                {
                    ret=sell_medicine(id1,cho,unit1,searchId,removeId,contactNo,customerName);
                }
                else
                    ret=sell_medicine(id1,cho,unit1,searchId,removeId,contactNo,customerName);
                printf("\n return value of sell medicine = %d",ret);
                //getch();
                main_menu();
            }
            break;
            case 5:
            {
                int ret;
                ret=list_medicine();
                printf("\n return value  of list medicine function = %d",ret);
                //getch();
                main_menu();
            }

            break;
            case 6:
            {
                 int ret;
                 system("cls");
                 char medName[20],supplierName[20],supplierContact[20],mail[20],companyName[20];
                int id1,rackNo,cabinNo,qty,supplierId;
               // goto_xy(20,4);
                printf("\n\t****************Edit Medicine Details****************");
               // goto_xy(20,6);
                printf("\nEnter the medicine ID : ");
                scanf("%d",&id1);

                //if(check_id(id1)==0)
                //{
                    //goto_xy(20,8);
                   // printf("Medicine Record is available");
                   // goto_xy(32,9);
                    printf("\nEnter New Details");
                   // goto_xy(30,10);
                    printf("\n***********************");
                   // goto_xy(30,12);
                    printf("\nMedicine ID : ");
                   // goto_xy(50,12);
                    printf("%d",id1);
                   // goto_xy(30,13);
                    printf("\nMedicine Name : ");
                   // goto_xy(50,13);
                    fflush(stdin);
                    scanf("%[^\n]%*c", medName);
                  //  goto_xy(30,14);
                    printf("\nSupplier Name : ");
                  //  goto_xy(50,14);
                    fflush(stdin);
                    scanf("%[^\n]%*c", supplierName);
                  //  goto_xy(30,15);
                    printf("\nSupplier ID : ");
                   // goto_xy(50,15);
                    scanf("%d",&supplierId);
                   // goto_xy(30,16);
                    printf("\nSupplier Ph: ");
                   // goto_xy(50,16);
                    scanf("%s",supplierContact);
                   // goto_xy(30,17);
                    fflush(stdin);
                    printf("\nCompany Name : ");
                   // goto_xy(50,17);
                    scanf("%[^\n]%*c", companyName);
                   // goto_xy(30,18);
                    printf("\nMail ID : ");
                   // goto_xy(50,18);
                    scanf("%s",mail);
                   // goto_xy(30,19);
                    printf("\nQuantity : ");
                   // goto_xy(50,19);
                    scanf("%d",&qty);
                   // goto_xy(30,20);
                    printf("\nRack : ");
                   // goto_xy(50,20);
                    scanf("%d",&rackNo);
                   // goto_xy(30,21);
                    printf("\nCabin : ");
                   // goto_xy(50,21);
                    scanf("%d",&cabinNo);
                    ret=edit_medicine(id1,medName,supplierName,supplierId,supplierContact,companyName,mail,qty,rackNo,cabinNo);

                //}
                //else
                //{
                   // ret=0;
                   // printf("\n record not available");

               // }

                printf("\n return value of edit medicine = %d",ret);
                //getch();
                main_menu();
            }
            break;
            case 7:
            {
                system("cls");
                char cho;
                int id1=0;
                int ret;

               // goto_xy(10,2);
                printf("\n\tSupplier Details");
               // goto_xy(9,3);
                printf("\n\t*******************");
              //  goto_xy(10,5);
                printf("\n\xDB\xDB\xDB\xDB 1. Supplier List");
               // goto_xy(10,7);
                printf("\n\xDB\xDB\xDB\xDB 2. Search Supplier");
              //  goto_xy(10,9);
                printf("\n\xDB\xDB\xDB\xDB 3. Main Menu");
              //  goto_xy(10,11);
                printf("\nEnter Your Choice ");
                //cho=getch();
                scanf("%c",&cho);

                if(cho=='1')
                {
                    ret=supplier_info(cho,id1);
                }
                if(cho=='2')
                {
                    system("cls");
                   // goto_xy(25,4);
                    printf("\n\t******************** Search Supplier ******************");
                   // goto_xy(25,6);
                    printf("\nEnter ID : ");
                  //  goto_xy(39,6);
                    scanf("%d",&id1);
                    ret=supplier_info(cho,id1);
                }
                else
                {
                    ret=supplier_info(cho,id1);
                }
                printf("\n return value of supplier info = %d",ret);
                //getch();
                main_menu();
            }
            break;
            case 8:
            close_application();
            default:
            {
               // goto_xy(10,25);
                printf("\nWrong Entry!!Please re-entered correct option");
                //getch();
                main_menu();
            }
        }
}


