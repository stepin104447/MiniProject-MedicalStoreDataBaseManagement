#include "medical_store.h"
#include<string.h>
char findMedicine;

FILE *fp,*fs,*ft;

//COORD coord = {0,0};
//void goto_xy(int x,int y)
//{
  //  coord.X = x;
   // coord.Y = y;
   // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

COORD coord = {0,0};

void goto_xy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct date
{
    int mm,dd,yy;
};

char categories[][15]={"Tablets","Capsules","Drops","Inhalers","Syrup","Other"};

struct medicine
{
    int id;
    char medName[20];
    char supplierName[20];
    char customerName[20];
    char companyName[20];
    char mail[50];
    int supplierId;
    char supplierContact[20];
    float price;
    int qty;
    int unitSold;
    int rackNo;
    int cabinNo;
    char contactNo[20];
    char *cat; // medicine categories
    struct date soldDate;
};

struct medicine a;

int check_id(int t)
{
    rewind(fp);
    while (fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;
    return 1;
}


int get_data(int id,int s,char* medName,char* supplierName,int supplierId,char* supplierContact,char* mail,char* companyName,float price,int qty,int rackNo,int cabinNo)
{
    int t;
    goto_xy(20,3);
    printf("Entered information");
    goto_xy(20,5);
    printf("category : ");
    goto_xy(40,5);
    printf("%s",categories[s-1]);
    goto_xy(20,7);
    printf("Medicine Id : ");
    goto_xy(40,7);
    //scanf("%d",&t);
    t=id;
    printf("%d",t);

    fflush(stdin);

    if(check_id(t)==0)
    {
       system("cls");
        goto_xy(25,11);
        printf("medicine ID already exist!!. Press any key to try again");
        //getch();
        //add_medicine(id,s,medName,supplierName,supplierId,supplierContact,mail,companyName,price,qty,rackNo,cabinNo);

        return 0;
    }

    a.id = t;
    goto_xy(20,9);
    printf("Medicine Name : ");
    goto_xy(40,9);
    printf("%s",medName);
    //scanf("%[^\n]%*c", a.medName);
    strcpy(a.medName,medName);
    fflush(stdin);
    goto_xy(20,10);
    printf("supplier name : ");
    goto_xy(40,10);
    printf("%s",supplierName);
    //scanf("%[^\n]%*c", a.supplierName);
    strcpy(a.supplierName,supplierName);
    fflush(stdin);
    goto_xy(20,11);
    printf("supplier ID : ");
    goto_xy(40,11);
    printf("%d",supplierId);
    //scanf("%d",&a.supplierId);
    a.supplierId=supplierId;
    fflush(stdin);
    goto_xy(20,12);
    printf("supplier contact : ");
    goto_xy(40,12);
    printf("%s",supplierContact);
    //scanf("%s",a.supplierContact);
    strcpy(a.supplierContact,supplierContact);
    fflush(stdin);
    goto_xy(20,13);
    printf("Supplier Email : ");
    goto_xy(40,13);
    printf("%s",mail);
    //scanf("%[^\n]%*c",a.mail);
    strcpy(a.mail,mail);
    fflush(stdin);
    goto_xy(20,14);
    printf("Company Name : ");
    goto_xy(40,14);
    printf("%s",companyName);
    //scanf("%[^\n]%*c", a.companyName);
    strcpy(a.companyName,companyName);
    fflush(stdin);
    goto_xy(20,15);
    printf("price : ");
    goto_xy(40,15);
    printf("%0.2f",price);
    //scanf("%f",&a.price);
    a.price=price;
    goto_xy(20,16);
    printf("quantity : ");
    goto_xy(40,16);
    printf("%d",qty);
    //scanf("%d",&a.qty);
    a.qty=qty;
    goto_xy(20,17);
    printf("rack no : ");
    goto_xy(40,17);
    printf("%d",rackNo);
    //scanf("%d",&a.rackNo);
    a.rackNo=rackNo;
    goto_xy(20,18);
    printf("cabin no : ");
    goto_xy(40,18);
    printf("%d",cabinNo);
    //scanf("%d",&a.cabinNo);
    a.cabinNo=cabinNo;
    return 1;

}





int add_medicine(int id,int choice,char* medName,char* supplierName,int supplierId,char* supplierContact,char* mail,char* companyName,float price,int qty,int rackNo,int cabinNo)
{
    int s;
    s=choice;
    switch(s)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        {
            system("cls");
            fp=fopen("medicine1.dat","ab+");
            if(get_data(id,s,medName,supplierName,supplierId,supplierContact,mail,companyName,price,qty,rackNo,cabinNo)==1)
            {
                a.cat=categories[s-1];
                fseek(fp,0,SEEK_END);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                goto_xy(20,20);
                printf("record saved successfully");
                goto_xy(20,22);
                printf("do you want to add more medicine Y/N :");
                goto_xy(58,23);
                /*
                if(getch()=='n')
                    main_menu();
                else
                {
                    system("cls");
                    add_medicine(id,choice,medName,supplierName,supplierId,supplierContact,mail,companyName,price,qty,rackNo,cabinNo);
                }
                */

                return(1);
            }
            return(0);

        }
        break;
        case 7: return(1);
        break;
        default:
        {
            printf("\n invalid entry. Try again");
            return(1);
            getch();
            add_medicine(id,choice,medName,supplierName,supplierId,supplierContact,mail,companyName,price,qty,rackNo,cabinNo);
        }

    }
}




int dispose_medicine(int id1)
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')
    {
        system("cls");
        goto_xy(10,2);
        printf("Delete Medicine");
        goto_xy(10,3);
        printf("******************");
        goto_xy(10,5);
        printf("Medicine ID to  delete: ");
        //scanf("%d",&d);
        d=id1;
        printf("%d",d);
        fp=fopen("medicine1.dat","rb+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {

                goto_xy(10,7);
                printf("The Medidcine record is available");
                goto_xy(10,8);
                printf("Medicine Name :  %s",a.medName);
                goto_xy(10,9);
                printf("Rack No :        %d",a.rackNo);
                goto_xy(10,10);
                printf("Cabin No :       %d",a.cabinNo);
                findMedicine='t';
            }
        }
    if(findMedicine!='t')
    {
        goto_xy(10,12);
        printf("No record is found ... Press Any key");
        return(0);
        //if(getch())
        //main_menu();
    }
    if(findMedicine=='t' )
    {
        goto_xy(10,12);
        printf("Do you want to delete it?(Y/N):");
        //if(getch()=='y')
        //{
            ft=fopen("test.dat","wb+");  //temporary file for delete
            rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id!=d)
            {
                fseek(ft,0,SEEK_CUR);
                fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(ft);
        fclose(fp);
        remove("medicine1.dat");
        rename("test.dat","medicine1.dat"); //copy all item from temporary file to fp except that
        fp=fopen("medicine1.dat","rb+");    //we want to delete
        if(findMedicine=='t')
        {
            goto_xy(10,14);
            printf("The record is sucessfully deleted");
            return(1);
            goto_xy(10,16);
            printf("Delete another record?(Y/N)");
            //another=getch();
        }
    //}
    //else
    //{
      //  main_menu();
       // fflush(stdin);
        //another=getch();
    }

    }
}



int search_medicine(char cho,int id1,char *name)
{
    char choice;
    system("cls");
    int id;
    printf("\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9 SEARCH MEDICINE \
\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9\xF9");

    //goto_xy(20,10);
   // printf("\xDB\xDB\xDB\xDB\xDB 1. Search by ID ");
    //goto_xy(20,12);
    //printf("\xDB\xDB\xDB\xDB\xDB 2. Search by Name ");
    //goto_xy(20,15);
    //printf("Enter your choice");
    //choice=getch();
    choice=cho;

    fp=fopen("medicine1.dat","rb+");
    rewind(fp);

    switch(choice)
    {
        case '1':
        {
            int id_flag=0;
            system("cls");
            goto_xy(25,4);
            printf("******************** Search By ID ******************");
            goto_xy(25,6);
            printf("Entered ID : ");
            goto_xy(39,6);
            //scanf("%d",&id);
            id=id1;
            printf("%d",id);
            goto_xy(25,8);
            printf("searching");
            goto_xy(35,8);
            for(int i=0;i<6;i++)
            {
                Sleep(160);
                printf(". ");
            }

            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(a.id==id)
                {
                    goto_xy(25,9);
                    printf("The medicine is available");
                    goto_xy(36,11);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\
\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

                    goto_xy(35,13);
                    printf("Medicine ID : ");
                    goto_xy(58,13);
                    printf("%d",a.id);
                    goto_xy(35,14);
                    printf("Medicine Name : ");
                    goto_xy(58,14);
                    printf("%s",a.medName);
                    goto_xy(35,15);
                    printf("Supplier Name : ");
                    goto_xy(58,15);
                    printf("%s",a.supplierName);
                    goto_xy(35,16);
                    printf("Supplier ID : ");
                    goto_xy(58,16);
                    printf("%d",a.supplierId);
                    goto_xy(35,17);
                    printf("Supplier Ph.No : ");
                    goto_xy(58,17);
                    printf("%s",a.supplierContact );
                    goto_xy(35,18);
                    printf("Quantity : ");
                    goto_xy(58,18);
                    printf("%d",a.qty);
                    goto_xy(35,19);
                    printf("Price : ");
                    goto_xy(58,19);
                    printf("%0.2f",a.price);
                    goto_xy(35,20);
                    printf("Rack : ");
                    goto_xy(58,20);
                    printf("%d",a.rackNo);
                    goto_xy(35,21);
                    printf("Cabin : ");
                    goto_xy(58,21);
                    printf("%d",a.cabinNo);
                    goto_xy(36 ,23);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\
\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    id_flag = 1;
                    return 1;
                }
            }

            if(id_flag!=1)
            {
                goto_xy(25,9);
                printf("Medicine Record is not available");
                return 0;
            }

            goto_xy(30,25);
            printf("Do you want to search another record Y/N");
           /*
            if(getch()=='y')
            {
                search_medicine();
            }
            else
                main_menu();
            */


        }
        break;

        case '2':
        {
            system("cls");
            char s[15];
            goto_xy(25,4);
            printf("************** Search By Name **************");
            goto_xy(25,6);
            printf("Entered name : ");
            goto_xy(45,6);
            fflush(stdin);
            //scanf("%[^\n]%*c", s);
            strcpy(s,name);
            printf("%s",s);
            int name_flag=0;

            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(strcmp(a.medName,s)==0)
                {
                    goto_xy(25,8);
                    printf("Medicine is available");
                    goto_xy(35,10);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\
\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

                    goto_xy(35,12);
                    printf("Medicine ID : ");
                    goto_xy(58,12);
                    printf("%d",a.id);
                    goto_xy(35,13);
                    printf("Medicine Name : ");
                    goto_xy(58,13);
                    printf("%s",a.medName);
                    goto_xy(35,14);
                    printf("Supplier Name : ");
                    goto_xy(58,14);
                    printf("%s",a.supplierName);
                    goto_xy(35,15);
                    printf("Supplier ID : ");
                    goto_xy(58,15);
                    printf("%d",a.supplierId);
                    goto_xy(35,16);
                    printf("Supplier Ph.No : ");
                    goto_xy(58,16);
                    printf("%s",a.supplierContact );
                    goto_xy(35,17);
                    printf("Quantity : ");
                    goto_xy(58,17);
                    printf("%d",a.qty);
                    goto_xy(35,18);
                    printf("Price : ");
                    goto_xy(58,18);
                    printf("%0.2f",a.price);
                    goto_xy(35,19);
                    printf("Rack : ");
                    goto_xy(58,19);
                    printf("%d",a.rackNo);
                    goto_xy(35,20);
                    printf("Cabin : ");
                    goto_xy(58,20);
                    printf("%d",a.cabinNo);
                    goto_xy(35,22);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\
\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    name_flag=1;
                    return 1;

                }
            }

            if(name_flag!=1)
            {
                goto_xy(25,9);
                printf("Medicine Record is not available");
                return(0);
            }

            goto_xy(30,24);
            printf("Do you want to search another record Y/N");
            /*
            if(getch()=='y')
            {
                search_medicine();
            }
            else
                main_menu();
            */
            break;
        }

        default :
        {
            goto_xy(20,17);
            printf("invalid Entry ");
            return(1);
            //getch();
           // search_medicine();
        }
    }
    fclose(fp);

}

int sell_medicine(int id1,char cho,int unit1,int searchId,int removeId,char* contactNo,char* customerName)
{
    int id;
    int return_flag;
    char ch;
    system("cls");
    /*
    goto_xy(2,2);
    printf("************************* SELL MEDICINE ************************");
    goto_xy(10,5);
    printf("\xDB\xDB\xDB\xDB\xDB 1. Sell Medicine");
    goto_xy(10,7);
    printf("\xDB\xDB\xDB\xDB\xDB 2. List Sold Medicines");
    goto_xy(10,9);
    printf("\xDB\xDB\xDB\xDB\xDB 3. Search Sold Medicine");
    goto_xy(10,11);
    printf("\xDB\xDB\xDB\xDB\xDB 4. Remove Sold Medicine");
    goto_xy(10,13);
    printf("\xDB\xDB\xDB\xDB\xDB 5. Main Menu");
    goto_xy(10,15);
    printf("Enter your choice : ");
    */
    ch =cho;

    switch(ch)
    {
        case '1' :
        {
            system("cls");
            int c = 0;
            int unit;
            float total;
            char another='y';

            while(another=='y')
            {

                system("cls");
                goto_xy(22,4);
                printf("SELL MEDICINE");
                goto_xy(20,5);
                printf("******************");
                goto_xy(21,7);
                printf("Medicine ID to sell : ");
                //scanf("%d",&id);
                id=id1;
                printf("%d",id);

                fp=fopen("medicine1.dat","rb+");
                fs=fopen("sell.dat","ab+");

                if(check_id(id)==0)
                {
                    goto_xy(21,9);
                    printf("Medicine Record is Available");
                    goto_xy(21,11);
                    printf("Medicine Name : ");
                    goto_xy(41,11);
                    printf("%s",a.medName);
                    goto_xy(21,12);
                    printf("Units Available : ");
                    goto_xy(41,12);
                    printf("%d",a.qty);
                    goto_xy(21,13);
                    printf("cost : ");
                    goto_xy(41,13);
                    printf("%0.2f",a.price);
                    goto_xy(21,15);
                    printf("Name of Customer : ");
                    goto_xy(41,15);
                    printf("%s",customerName);
                    fflush(stdin);
                    //scanf("%[^\n]%*c", a.customerName);
                    strcpy(a.customerName,customerName);
                    goto_xy(21,16);
                    printf("Contact No : ");
                    goto_xy(41,16);
                    printf("%s",contactNo);
                    //scanf("%s",a.contactNo);
                    strcpy(a.contactNo,contactNo);
                    goto_xy(21,17);
                    printf("Units Needed : ");
                    goto_xy(41,17);
                    printf("%d",unit1);
                    //scanf("%d",&unit);
                    unit=unit1;
                    if(unit>a.qty)
                    {
                        goto_xy(21,19);
                        printf("Not Enough Units!!. Press Any Key to go Back : ");
                        return_flag=0;
                        return(0);
                        getch();
                        //sell_medicine();
                    }
                    a.unitSold = unit;

                    total=unit*a.price;
                    goto_xy(21,19);
                    printf(" Total Price  =   RS %0.2f",total);
                    fclose(fp);

                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);

                    a.soldDate.dd=tm.tm_mday;
                    a.soldDate.mm=tm.tm_mon + 1;
                    a.soldDate.yy=tm.tm_year + 1900;

                    goto_xy(21,20);
                    printf("The Medicine of ID %d is sold",a.id);
                    return_flag=1;


                    fseek(fs,sizeof(a),SEEK_END);
                    fwrite(&a,sizeof(a),1,fs);
                    fclose(fs);
                    c=1;

                }
                if(c==0)
                {
                    goto_xy(21,9);
                    printf("No Medicine Record Found");
                    return_flag=0;
                }
                goto_xy(21,24);
                printf("Do you want to sell more medicine(Y/N):");
                fflush(stdin);
                another='n';
                fclose(fp);

                fp=fopen("medicine1.dat","rb+");

                 while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(check_id(id)==0)
                    {
                        a.qty=a.qty-unit;

                        fseek(fp,ftell(fp)-sizeof(a),0);
                        fwrite(&a,sizeof(a),1,fp);
                        fclose(fp);
                    }

                }
                return(return_flag);
            }

        }
        break;

        case '2' :
        {
            system("cls");
            int j=6;
            goto_xy(47,1);
            printf("SOLD MEDICINE");
            goto_xy(2,2);
            printf("********************************************************************************************************");
            goto_xy(2,4);
            printf("Customer Name        Contact No         Med ID      Med Name           Price     Unit Sold      Date ");

            fs=fopen("sell.dat","rb");
            while (fread(&a,sizeof(a),1,fs)==1)
            {
                goto_xy(2,j);
                printf("%s",a.customerName);
                goto_xy(23,j);
                printf("%s",a.contactNo);
                goto_xy(43,j);
                printf("%d",a.id);
                goto_xy(54,j);
                printf("%s",a.medName);
                goto_xy(73,j);
                printf("%0.2f",a.price);
                goto_xy(86,j);
                printf("%d",a.unitSold);
                goto_xy(98,j);
                printf("%d-%d-%d",a.soldDate.dd,a.soldDate.mm,a.soldDate.yy);

                j++;
            }
            fclose(fs);
            goto_xy(1,j+5);
            printf("Press Enter to go back : ");
            if(j>6)
                return_flag=1;
            else
                return_flag= 0;
            //while(getch()!=13);
            //sell_medicine();
            return(return_flag);
        }
        break;

        case '3' :
        {
            system("cls");

            int id,c=0;



            char another='y';
            while(another=='y')
            {
                system("cls");
                goto_xy(10,2);
                printf("Search Sold Medicines");
                goto_xy(10,3);
                printf("***********************");
                goto_xy(10,6);
                printf("Medicine Id to search : ");
                //scanf("%d",&id);
                id=searchId;
                printf("%d",id);
                fs=fopen("sell.dat","rb");
                while(fread(&a,sizeof(a),1,fs)==1)
                {
                    if(a.id==id)
                    {
                        system("cls");
                        Sleep(1000);
                        goto_xy(10,6);
                        printf("Medicine Record Exist");
                        goto_xy(10,8);
                        printf("Medicine ID : ");
                        goto_xy(30,8);
                        printf("%d",a.id);
                        goto_xy(10,9);
                        printf("Medicine Name : ");
                        goto_xy(30,9);
                        printf("%s",a.medName);
                        goto_xy(10,11);
                        printf("Customer Name : ");
                        goto_xy(30,11);
                        printf("%s",a.customerName);
                        goto_xy(10,12);
                        printf("contact no : ");
                        goto_xy(30,12);
                        printf("%s",a.contactNo);
                        goto_xy(10,13);
                        printf("Price : ");
                        goto_xy(30,13);
                        printf("%0.2f",a.price);
                        goto_xy(10,14);
                        printf("Units Sold : ");
                        goto_xy(30,14);
                        printf("%d",a.unitSold);
                        goto_xy(10,16);
                        printf("Press any ENTER key to view the next result ");
                        //while(getch()!=13);
                       // Sleep(2500);
                       // for(int i=0;i<8;i++)
                       // {

                           // printf(". ");
                        //}
                        //issuerecord();
                        c=1;
                    }

                }
                fflush(stdin);
                fclose(fs);
                if(c==0)
                {
                    goto_xy(10,8);
                    printf("No Record Found");
                    return_flag=0;
                }
                return_flag=1;
                goto_xy(10,20);
                printf("Try Another Search?(Y/N)");
                //another=getch();
                return(return_flag);
            }
        }

        break;

        case '4':
        {
            system("cls");
            int id;
            FILE *fg;  //declaration of temporary file for delete
            char another='y';
            while(another=='y')
            {
                system("cls");
                goto_xy(10,2);
                printf("Remove Medicine From Sold List");
                goto_xy(10,3);
                printf("********************************");
                goto_xy(10,5);
                printf("Medicine ID to remove:");
                //scanf("%d",&id);
                id=removeId;
                printf("%d",id);
                fs=fopen("sell.dat","rb+");
                while(fread(&a,sizeof(a),1,fs)==1)
                {
                    if(a.id==id)
                    {
                        system("cls");
                        goto_xy(10,5);
                        printf("Record Exist");
                        goto_xy(10,7);
                        printf("Medicine Name : ");
                        goto_xy(30,7);
                        printf("%s",a.medName);
                        goto_xy(10,8);
                        printf("Customer Name : ");
                        goto_xy(30,8);
                        printf("%s",a.customerName);
                        goto_xy(10,9);
                        printf("Contact : ");
                        goto_xy(30,9);
                        printf("%s",a.contactNo);
                        findMedicine='t';
                        goto_xy(10,11);
                        printf("press any key to view the next result ");
                       // getch();

                    }

                }
                    if(findMedicine=='t')
                    {
                        goto_xy(10,13);
                        //printf("Do You Want to Remove it?(Y/N)");
                        //if(getch()=='y')
                        //{
                            fg=fopen("record.dat","wb+");
                            rewind(fs);
                            while(fread(&a,sizeof(a),1,fs)==1)
                            {
                                if(a.id!=id)
                                {
                                    fseek(fs,0,SEEK_CUR);
                                    fwrite(&a,sizeof(a),1,fg);
                                }
                            }
                            fclose(fs);
                            fclose(fg);
                            remove("sell.dat");
                            rename("record.dat","sell.dat");
                            goto_xy(10,15);
                            printf("The Medicine Record is removed from list");
                            return_flag=1;

                        //}

                    }
                    if(findMedicine!='t')
                    {
                        goto_xy(10,15);
                        printf("No Record Found");
                        return_flag=0;
                    }

                goto_xy(10,17);
                printf("Delete any more?(Y/N)");
                //another=getch();
                return(return_flag);
            }

        }
         break;

        case '5':
        {
            return 1;
            //main_menu();
        }

        default :
        {
            printf("invalid entry !! Try again ");
            return(1);
            getch();
            //sell_medicine();
        }
    }
    goto_xy(10,30);
    printf("Press ENTER to go Back : ");
    //while(getch()!=13);
   // sell_medicine();
}

int list_medicine(void)
{
    system("cls");
    goto_xy(1,1);
    printf("***************************************** MEDICINE LIST *****************************************");
    goto_xy(2,3);
    printf("CATEGORY     ID    MED NAME             SUPPLIER ID         QTY       PRICE        RACK    CABIN");

    int i=5;
    fp=fopen("medicine1.dat","rb+");
    while (fread(&a,sizeof(a),1,fp)==1)
    {
        goto_xy(3,i);
        printf("%s",a.cat);
        goto_xy(15,i);
        printf("%d",a.id);
        goto_xy(21,i);
        printf("%s",a.medName);
        goto_xy(43,i);
        printf("%d",a.supplierId);
        goto_xy(62,i);
        printf("%d",a.qty);
        goto_xy(72,i);
        printf("%0.2f",a.price);
        goto_xy(86,i);
        printf("%d",a.rackNo);
        goto_xy(94,i);
        printf("%d",a.cabinNo);

        i++;
    }

    goto_xy(35,25);
    fclose(fp);
    if(i>5)
        return 1;
    else
        return 0;

    //returnfunc();
}

int edit_medicine(int id1,char* medName,char* supplierName,int supplierId,char* supplierContact,char* companyName,char* mail,int qty,int rackNo,int cabinNo)
{
    system("cls");
    int id;
    goto_xy(20,4);
    printf("****************Edit Medicine Details****************");
    goto_xy(20,6);
    printf("Enter the medicine ID : ");
    //scanf("%d",&id);
    id=id1;
    fp=fopen("medicine1.dat","rb+");

    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(check_id(id)==0)
        {
            goto_xy(20,8);
            printf("Medicine Record is available");
            goto_xy(32,9);
            printf("Enter New Details");
            goto_xy(30,10);
            printf("***********************");
            goto_xy(30,12);
            printf("Medicine ID : ");
            goto_xy(50,12);
            printf("%d",a.id);
            goto_xy(30,13);
            printf("Medicine Name : ");
            goto_xy(50,13);
            fflush(stdin);
            //scanf("%[^\n]%*c", a.medName);
            strcpy(a.medName,medName);
            goto_xy(30,14);
            printf("Supplier Name : ");
            goto_xy(50,14);
            fflush(stdin);
            //scanf("%[^\n]%*c", a.supplierName);
            strcpy(a.supplierName,supplierName);
            goto_xy(30,15);
            printf("Supplier ID : ");
            goto_xy(50,15);
            //scanf("%d",&a.supplierId);
            a.supplierId=supplierId;
            goto_xy(30,16);
            printf("Supplier Ph: ");
            goto_xy(50,16);
            //scanf("%s",a.supplierContact);
            strcpy(a.supplierContact,supplierContact);
            goto_xy(30,17);
            fflush(stdin);
            printf("Company Name : ");
            goto_xy(50,17);
            //scanf("%[^\n]%*c", a.companyName);
            strcpy(a.companyName,companyName);
            goto_xy(30,18);
            printf("Mail ID : ");
            goto_xy(50,18);
            //scanf("%s",a.mail);
            strcpy(a.mail,mail);
            goto_xy(30,19);
            printf("Quantity : ");
            goto_xy(50,19);
            //scanf("%d",&a.qty);
            a.qty=qty;
            goto_xy(30,20);
            printf("Rack : ");
            goto_xy(50,20);
            //scanf("%d",&a.rackNo);
            a.rackNo=rackNo;
            goto_xy(30,21);
            printf("Cabin : ");
            goto_xy(50,21);
            //scanf("%d",&a.cabinNo);
            a.cabinNo=cabinNo;

            fseek(fp,ftell(fp)-sizeof(a),0);
            fwrite(&a,sizeof(a),1,fp);
            fclose(fp);
            goto_xy(30,23);
            printf("Record Edited Successfully");
            return(1);
        }
        else
        {
            goto_xy(20,8);
            printf("Medicine Record Not Available !");
            return(0);
            getch();
        }
    }
    goto_xy(30,25);
    printf("Do you want to edit another record Y/N : ");
    /*
    if(getch()=='y')
        edit_medicine();
    else
    {
        goto_xy(30,26);
        returnfunc();
    }
    */
}
int supplier_info(char cho,int id1)
{
     system("cls");
     char ch;
    /*
    goto_xy(10,2);
    printf("Supplier Details");
    goto_xy(9,3);
    printf("*******************");
    goto_xy(10,5);
    printf("\xDB\xDB\xDB\xDB 1. Supplier List");
    goto_xy(10,7);
    printf("\xDB\xDB\xDB\xDB 2. Search Supplier");
    goto_xy(10,9);
    printf("\xDB\xDB\xDB\xDB 3. Main Menu");
    goto_xy(10,11);
    printf("Enter Your Choice ");
    */
    ch=cho;

    switch(ch)
    {
        case '1':
        {
            system("cls");
            int j=7;
            goto_xy(38,2);
            printf("Supplier List");
            goto_xy(2,3);
            printf("*****************************************************************************************************************");
            goto_xy(2,5);
            printf("Supplier ID     Supplier Name            Contact No          Company Name              Email");
            fp=fopen("medicine1.dat","rb");
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                goto_xy(4,j);
                printf("%d",a.supplierId);
                goto_xy(18,j);
                printf("%s",a.supplierName);
                goto_xy(43,j);
                printf("%s",a.supplierContact);
                goto_xy(63,j);
                printf("%s",a.companyName);
                goto_xy(89,j);
                printf("%s",a.mail);

                j++;
            }
            if(j>7)
                return(1);
            else
                return(0);
            fclose(fp);
            goto_xy(2,j+5);
            printf("Press any key to Go Back : ");
            //getch();
            //supplier_info();
        }
        break;

        case '2':
        {
            int id;
            fp=fopen("medicine1.dat","rb+");
            rewind(fp);
            char another='y';
            while(another=='y')
            {
                system("cls");
                int id_flag=0;
                system("cls");
                goto_xy(25,4);
                printf("******************** Search Supplier ******************");
                goto_xy(25,6);
                printf("Supplier ID to search : ");
                goto_xy(39,6);
                //scanf("%d",&id);
                id=id1;
                printf("%d",id);
                goto_xy(25,8);
                printf("searching");
                goto_xy(35,8);
                for(int i=0;i<6;i++)
                {
                    Sleep(160);
                    printf(". ");
                }

                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.supplierId==id)
                    {
                        goto_xy(25,9);
                        printf("ID is Valid");
                        goto_xy(36,11);
                        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\
\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

                        goto_xy(35,13);
                        printf("Supplier ID : ");
                        goto_xy(58,13);
                        printf("%d",a.supplierId);
                        goto_xy(35,14);
                        printf("Supplier Name : ");
                        goto_xy(58,14);
                        printf("%s",a.supplierName);
                        goto_xy(35,15);
                        printf("Supplier Ph.No : ");
                        goto_xy(58,15);
                        printf("%s",a.supplierContact );
                        goto_xy(35,16);
                        printf("Company : ");
                        goto_xy(58,16);
                        printf("%s",a.companyName);
                        goto_xy(35,17);
                        printf("E-mail : ");
                        goto_xy(58,17);
                        printf("%s",a.mail);
                        goto_xy(36,19);
                        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\
\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                        id_flag = 1;
                        return(1);
                    }
                }

                if(id_flag!=1)
                {
                    goto_xy(25,9);
                    printf("Invalid Id");
                    return(0);
                }

                goto_xy(30,22);
                printf("Do you want to search another record Y/N");
               // another = getch();
            }

            goto_xy(30,24);
            printf("Press ENTER to go Back");
            //while(getch()!=13);
            //supplier_info();

        }
        break;

        case '3':
        {
           return(1);
           // main_menu();
        }
        break;

        default:
         {
             printf("Invalid Entry ! Try again ");
             return(1);
            // getch();
             //supplier_info();
         }
    }
}

