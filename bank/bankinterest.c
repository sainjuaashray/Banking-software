#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
#include<string.h>

//----------------------------------------------------------------------------------------
//INTEREST CODE
//---------------------------------------------------------------------------------------
int interestcal()
{
    int day,day1,day2,month,month2,month1,month11,year,year1,year2,balance1,balance2,balance3;
    int interest1,interest2;
    int time=1,rate=10;
    char account1[15],account2[15],account3[15];
     FILE *interests,*interests1,*date,*balance;

     date=fopen("D:\\bank\\date.info","r");
     fscanf(date,"%d %d %d",&year,&month,&day);
     fclose(date);

         interests=fopen("D:\\bank\\interest.info","r");
         interests1=fopen("D:\\bank\\interest1.info","a+");
         while(fscanf(interests,"%s %d %d %d %d %d",&account2,&interest2,&year1,&month1,&day1,&month11)!=EOF)
         {
             balance=fopen("D:\\bank\\balance.info","a+");

            while(fscanf(balance,"%s %d",&account1,&balance1)!=EOF)
            {
                if(strcmp(account1,account2)==0)
                {
                     interest1=balance1*time*rate/100;
                }

            }
                    if(day1!=day)

                    {
                    interest2=interest2+interest1;
                    }

                 if(month!=month11)
                 {
                     addInt(account2,interest2,day,month,year);
                     interest2=0;
                    month11=month;
                 }

                 fprintf(interests1,"%s %d %d %d %d %d\n",account2,interest2,year,month,day,month11);
             }


          fclose(interests1);

         fclose(interests);

       interests=fopen("D:\\bank\\interest.info","w");

       fclose(interests);

     interests1=fopen("D:\\bank\\interest1.info","r");
      interests=fopen("D:\\bank\\interest.info","a+");

     while(fscanf(interests1,"%s %d %d %d %d %d",&account3,&balance3,&year2,&month2,&day2,&month11)!=EOF)
        {


            fprintf(interests,"%s %d %d %d %d %d\n",account3,balance3,year2,month2,day2,month11);


        }
        fclose(interests);
        fclose(interests1);

       interests1=fopen("D:\\bank\\interest1.info","w");
       fclose(interests1);



}
//--------------------------------------------------------------
void addInt(char account[15],int interest,int day,int month,int year)
{
    int amount=0,amount1=0;
    char accountno[15];
    FILE *balance,*balance1,*interestList;

    balance1=fopen("D:\\bank\\balance1.info","w");
    fclose(balance1);

    balance1=fopen("D:\\bank\\balance1.info","a+");
    balance=fopen("D:\\bank\\balance.info","r");

    while(fscanf(balance,"%s %d",&accountno,&amount1)!=EOF)
    {
        if(strcmp(accountno,account)==0)
        {
            amount1=amount1+(int)interest;
        }
        fprintf(balance1,"%s %d\n",accountno,amount1);
    }

    fclose(balance);
    fclose(balance1);

     balance=fopen("D:\\bank\\balance.info","w");
    fclose(balance);

    balance=fopen("D:\\bank\\balance.info","a+");
    balance1=fopen("D:\\bank\\balance1.info","r");

    while(fscanf(balance1,"%s %d",&accountno,&amount)!=EOF)
    {
        fprintf(balance,"%s %d\n",accountno,amount);
    }

    fclose(balance1);
    fclose(balance);

    interestList=fopen("D:\\bank\\interestList.info","a+");
    fprintf(interestList,"%s %d %d %d %d\n",account,interest,year,month,day);
    fclose(interestList);


}

//---------------------------------------------------------------------------------------------

int date()
{
    //DATE CALCULATION
   struct SYSTEMTIME{
    WORD  wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
      WORD wHour;
    WORD wMinute;
    WORD wSecond;
};
SYSTEMTIME str;

    int year,month,day;
    FILE *dat,*dat1;
      GetSystemTime(&str);
      printf("%d\t%d\t%d",str.wYear,str.wMonth,str.wDay);
      dat=fopen("D:\\bank\\date.info","r");
      fscanf(dat,"%d %d %d",&year,&month,&day);
      fclose(dat);
      if(year==str.wYear && month==str.wMonth && day==str.wDay)
      {

      }
      else
        {
            dat1=fopen("D:\\bank\\date1.info","w");
            fprintf(dat1,"%d %d %d\n",str.wYear,str.wMonth,str.wDay);
            fclose(dat1);
            dat1=fopen("D:\\bank\\date1.info","a+");
            dat=fopen("D:\\bank\\date.info","r");
            while(fscanf(dat,"%d %d %d",&year,&month,&day)!=EOF)
            {
                fprintf(dat1,"%d %d %d\n",year,month,day);
            }
            fclose(dat);
            fclose(dat1);
        }


            dat=fopen("D:\\bank\\date.info","w");
            fclose(dat);
            dat=fopen("D:\\bank\\date.info","a+");
            dat1=fopen("D:\\bank\\date1.info","r");
            while(fscanf(dat1,"%d %d %d",&year,&month,&day)!=EOF)
            {
                fprintf(dat,"%d %d %d\n",year,month,day);
            }
            fclose(dat1);
            fclose(dat);

}

//----------------------------------------------------------------
void home()
{
    system("cls");
    rectangle(1,1,100,25);
    gotoxy(35,10);
    printf("NEW CONTACT");
     gotoxy(35,12);
    printf("ADMIN");
     gotoxy(35,14);
    printf("LOG IN");

    char ch="a";
    int choice=1;
    do
    {
        switch(ch)
        {
        case 'w':
            if(choice<1)
                choice=1;
            else
                choice--;
            break;

        case 's':
             if(choice>3)
                choice=3;
            else
                choice++;
            break;


        }
        switch(choice)
        {
            case 1:
                gotoxy(33,10);printf("#");
                gotoxy(33,12);printf("  ");
                gotoxy(33,14);printf("  ");
                break;
            case 2:
                gotoxy(33,10);printf("  ");
                gotoxy(33,12);printf("#");
                gotoxy(33,14);printf("  ");
                break;
            case 3:
                gotoxy(33,10);printf("  ");
                gotoxy(33,12);printf("  ");
                gotoxy(33,14);printf("#");
        }
        gotoxy(0,0);
        ch=getch();
    }while(ch!=13);

    //ACTIVITY INTEND
    switch(choice)
    {
    case 1:
        newContact();
        break;
    case 2:
        admin();
        break;
    case 3:
        login();
        break;
    }


}


void logInlayout()
{
    int i;
    rectangle(1,1,100,30);
    rectangle(34,13,70,16);
    rectangle(34,9,70,12);

    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);
    gotoxy(20,11);
    printf("ACCOUNT NO :  ");

    gotoxy(20,15);
    printf("PASSWORD   :  ");
}

void newContact()
{
     char name[15];
    char address[15];
    char rollno[15];
    int save;
    int numder;
    int i;
    //location of data information
    system("cls");
    rectangle(1,1,100,25);
    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);
    gotoxy(40,6);
    printf("NEW ACCOUNT");

     gotoxy(10,10);
    printf("NAME           :");
     gotoxy(10,12);
    printf("ADDRESS        :");
     gotoxy(10,14);
    printf("CONTACT        :");
    gotoxy(10,16);
    printf("IOE ROLLNO     :");

    //get data from client

     gotoxy(28,10);
    scanf(" %s",&name);
    gotoxy(28,12);
    scanf(" %s",&address);
    gotoxy(28,14);
    scanf(" %d",&numder);
     gotoxy(28,16);
    scanf(" %s",&rollno);
    printf("\n\n");
    getchar();

    //CHECKING WITH EXISTED CONTACTS
      struct newAcc{
    char sName[15];
    char sAddress[15];
    int sContact;
    char sRollno[15];
    char sPassword[15];
    int  sBalance;
    char sAccount[15];

    };
    char ch;

        struct newAcc Acc;
    FILE *fp;
    fp=fopen("D:\\bank\\newdata.info","r");
     while(fscanf(fp,"%s %s %d %s %s",&Acc.sName,&Acc.sAddress,&Acc.sContact,&Acc.sRollno,&Acc.sPassword)!=EOF)
     {
         if(strcmp(Acc.sRollno,rollno)==0)
         {
             gotoxy(35,22);
             printf("!!!ACCOUNT ALREADY EXISTED!!!");
             gotoxy(37,23);printf("%s \t %s",Acc.sName,Acc.sAddress);
            do{
             ch=getch();
             switch(ch)
             {
             case 13:
                newContact();
                break;
             case 27:
                home();
                break;
             }
            }while(1);

         }
     }

    //asking to save
     save=MessageBox(NULL,"CREATE CONTACT","NEW CONTACT",MB_YESNOCANCEL);
   if(save==6)
   {
    accountCon(name,address,numder,rollno);

   }
   else if(save==7)
   {
       newContact();

   }
   else
    home();
}


   void accountCon(char name[15],char address[15],int number,char rollno[15])
   {
       char password[15];
       char rePassword[15];
       char cc;
       int i;
       system("cls");

       rectangle(1,1,100,25);
    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);
    gotoxy(40,6);
       printf("ACCOUNT CREATED SUCCESSFULLY");

       gotoxy(15,8);
       printf("NAME     :  %s",name);
        gotoxy(15,10);
       printf("Address  :  %s",address);
       gotoxy(15,13);
       printf("Your Account number  :  %s",rollno);
       l3:
       gotoxy(15,15);
       printf("PASSWORD     :  ");
       gotoxy(15,17);
       printf("RE-PASSWORD  :");
       gotoxy(30,15);
       scanf(" %s",&password);

       p1:
       gotoxy(30,17);
       scanf(" %s",&rePassword);
       if(strcmp(password,rePassword)!=0)
       {
           gotoxy(20,23);
           printf("!!!please enter same password!!!");
           cc=getch();
           if(cc==26){home();}
           else
            accountCon(name,address,number,rollno);
       }
       else
       {
           MessageBox(NULL,"SUCCESSFUL","DONE",MB_OK);
        savedata(name,address,number,rollno,password);

       }


   }

void savedata(char name[15],char address[15],int contact,char rollno[15],char password[15])
{

    struct SYSTEMTIME{
    WORD  wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
      WORD wHour;
    WORD wMinute;
    WORD wSecond;
};
SYSTEMTIME str;
GetSystemTime(&str);

    struct newAcc{
    char sName[15];
    char sAddress[15];
    int sContact;
    char sRollno[15];
    };

        struct newAcc Acc,s;

FILE *fp;
fp=fopen("d:\\bank\\newdata.info","a+");
 if(fp==NULL)
      {
          printf("cannot be created");

      }
 fprintf(fp,"\n%s %s %d %s %s",name,address,contact,rollno,password);
 //fputs(name,fp);
 printf("saved");
 //fflush(stdin);
  fclose(fp);

  fp=fopen("D:\\bank\\balance.info","a+");
  int amt=0;
  fprintf(fp,"%s %d\n",rollno,amt);
  fclose(fp);

  fp=fopen("d:\\bank\\interest.info","a+");
  int interest=0;
  fprintf(fp,"%s %d %d %d %d %d\n",rollno,interest,str.wYear,str.wMonth,str.wDay,str.wMonth);
  fclose(fp);
  userInterface(name,address,contact,rollno);
  main();

}

//ADMINISTRATION PAGE

void admin()
{

    //login process
    char accountno[15];
    char password[15];
    char ch;
    system("cls");
    l2:
    logInlayout();
    gotoxy(40,6);
    printf("ADMINSTRATIVE LOGIN");
    gotoxy(36,11);
    scanf(" %s",&accountno);

     gotoxy(36,15);
    scanf(" %s",&password);

        if(strcmp(accountno,"ANNaR")==0 && strcmp(password,"rhombus")==0)
        {
             adminInterface();
        }
        else
        {
            gotoxy(45,23);printf("wrong ID");
             gotoxy(40,24);printf("press any key to try again");
             gotoxy(43,25);printf("ESC-to return");
            ch=getch();
            switch(ch)
            {
            case 27:
                home();
                break;
            default:
                admin();


            }

        }
}

//ADMIN INTERFACE PAGE
void adminInterface()
{
    int i;

    system("cls");
    rectangle(1,1,100,25);
    gotoxy(40,6);
    printf("ADMINSTRATIVE BLOCK");
    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);
     gotoxy(40,10);
    printf("DEPOSITE TRANSACTION");
     gotoxy(40,12);
    printf("WITHDRAW TRANSACTION");
    gotoxy(40,14);
    printf("DISPLAY INFORMATION");
     gotoxy(40,16);
    printf("SETTINGS");

    int choice=1;
    char ch="a";
    do
    {
        switch(ch)
        {
        case 'w':
            if(choice<1)
                choice=1;
            else
                choice--;
            break;

        case 's':
             if(choice>4)
                choice=4;
            else
                choice++;
            break;
        case 27:
            main();


        }
        switch(choice)
        {
            case 1:
                gotoxy(38,10);printf("#");
                gotoxy(38,12);printf("  ");
                gotoxy(38,14);printf("  ");
                gotoxy(38,16);printf("  ");
                break;
            case 2:
                gotoxy(38,10);printf("  ");
                gotoxy(38,12);printf("#");
                gotoxy(38,14);printf("  ");
                gotoxy(38,16);printf("  ");
                break;
            case 3:
                gotoxy(38,10);printf("  ");
                gotoxy(38,12);printf("  ");
                gotoxy(38,14);printf("#");
                gotoxy(38,16);printf("  ");
                break;
            case 4:
                gotoxy(38,10);printf("  ");
                gotoxy(38,12);printf("  ");
                gotoxy(38,14);printf("  ");
                gotoxy(38,16);printf("#");
        }
        gotoxy(0,0);
        ch=getch();
    }while(ch!=13);
        switch(choice)
        {
        case 1:
            depositeActivity();
            break;
        case 2:
            withdrawActivity();
            break;
        case 3:
            Display();
            break;
        case 4:
            system("cls");
            gotoxy(50,15);printf("UNDER CONSYRUCTION");
            getch();
            adminInterface();
            break;

        }


}

//DEPOSITE AMOUNT PROCESS
void depositeActivity()
{
    int i,j=0,k;
    int amount;
    char ch;
    char acn[15],name[15],address[15];
    int contact;
    char ACNO[15];
    char password[15];
    system("cls");
     rectangle(1,1,105,28);
        gotoxy(2,7);for(i=0;i<102;i++) printf("%c",196);
        gotoxy(40,6);printf("DEPOSITE BALANCE");
        gotoxy(18,9);printf("ACCOUNT NUMBER ");
        rectangle(35,8,70,10);
        gotoxy(37,9);
        scanf("%s",&acn);

        //Checking in file
        FILE *qq;
        qq=fopen("d:\\bank\\newdata.info","r");
        while(fscanf(qq,"%s %s %d %s %s",&name,&address,&contact,&ACNO,&password)!=EOF)
        {
            if(strcmp(acn,ACNO)==0)
            {
                gotoxy(30,13);printf("NAME     : %s",name);
                gotoxy(30,15);printf("ROLL NO  : %s",ACNO);
                j=1;

            }
        }

        switch(j)
        {
        case 0:
            gotoxy(30,20);
            printf("WRONG ACCOUNT NUMBER.....");
            ch=getch();
            switch(ch)
            {
            case 13:
                depositeActivity();
                break;
            case 27:
                adminInterface();
                break;
            }

            break;

        case 1:
            do{
             gotoxy(18,19);printf("DEPOSITED AMOUNT ");
             rectangle(36,18,70,20);
             gotoxy(40,19);
             scanf(" %d",&amount);
             k=MessageBox(NULL,"ARE YOU SURE??","DEPOSITE BALANCE",MB_YESNOCANCEL);
            }while(k==7);
             switch(k)
             {
             case 2:
                adminInterface();
                break;
             case 6:
                depositeBalance(acn,amount);
                break;
             case 7:
                depositeActivity();
                break;
             }
             break;




        }



}

//BALANCE DEPOSITION LIST
void depositionList()
{
    //VARIABLE CREATION
    int i;
    system("cls");
    struct depolist{

        char sName[15];
        char sAddress[15];
        int sContact;
        char sRollno[15];
        char sPassword[15];
        int  sBalance;
        char sAccount[15];
        int day,month,year;
    };

        struct depolist Acc;


         int k=1;
            char ch="s";
            int choice=1;
            int cy=10,ly=10,y;
            int start=1;
            int end=15;
            int l=0;
            int import=0;

    //DISPLAY ALL LAYOUT
    rectangle(1,1,100,25);
    gotoxy(40,6);
    printf("DEPOSITE LIST");
    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);

    //FILE DECLARATION

        FILE *qqq;
        FILE *balan;



    //title list

    gotoxy(5,8);printf("ACCOUNT NO.");
    gotoxy(30,8);printf("NAME");
     gotoxy(50,8);printf("BALANCE");
    gotoxy(70,8);printf("DATE");

    gotoxy(2,9);for(i=1;i<98;i++)printf("-");




//SCROLL CODE
do{
       cy=10;
        ly=10;
         y=10;
         int j;

         import=0;

//CLEARING ALL LIST DISPLAY SCREEN
         for(i=1;i<=15;i++)
         {
             gotoxy(5,y);
             printf("                           ");

             gotoxy(30,y);
             printf("                  ");

             gotoxy(50,y);
             printf("                           ");

             gotoxy(70,y);
             printf("                           ");

                 y=y+1;

         }
         y=10;

         //INITIAL SELECTION LOCATION
         gotoxy(2,10);
         printf("#");

         //DATA DISPLAY

   qqq=fopen("d:\\bank\\deposited.info","r");

    //importing from file
   while(fscanf(qqq,"%s %d %d %d %d",&Acc.sAccount,&Acc.sBalance,&Acc.year,&Acc.month,&Acc.day)!=EOF)
   {
       import=import+1;
    if(import>=start && import<start+end){

     gotoxy(5,y);printf("%s",Acc.sAccount);

     gotoxy(50,y);printf("%d",Acc.sBalance);
     gotoxy(70,y);printf("%d-%d-%d",Acc.year,Acc.month,Acc.day);


                  balan=fopen("d:\\bank\\newdata.info","r");
            while(fscanf(balan,"%s %s %d %s %s",&Acc.sName,&Acc.sAddress,&Acc.sContact,&Acc.sRollno,&Acc.sPassword)!=EOF)
            {
                if(strcmp(Acc.sRollno,Acc.sAccount)==0)
                {
                    gotoxy(30,y);
                    printf("%s",Acc.sName);
                     y++;
                }

            }
            fclose(balan);


    }
   }
     fclose(qqq);

     //SELECTION PROCESS

     do{
            k=1;
            ch=getch();

     switch(ch)
     {
     case 27:
        Display();
        break;
     case 's':
        ly=ly+1;
        choice++;
        for(cy=10;cy<25;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

         case 'w':
        ly=ly-1;
        choice--;
        for(cy=10;cy<25;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

     }

     //SCROLL CONDITION
     if(choice==start+end)
     {
         k=0;
         start=start+15;

     }
     if(choice<start)
     {
         k=0;
         start=start-15;
         choice=choice-14;
         if(start<1)
         {start=1;
         choice=1;
         }
     }

     }while(k==1);

}while(1);


}

//WITHDRAW AMOUNT PROCESS
void withdrawActivity()
{
    int i,j=0,k;
    int amount;
    char ch;
    char acn[15],name[15],address[15];
    int contact;
    char ACNO[15];
    char password[15];
    system("cls");
     rectangle(1,1,105,28);
        gotoxy(2,7);for(i=0;i<102;i++) printf("%c",196);
        gotoxy(40,6);printf("WITHDRAW BALANCE");
        gotoxy(18,9);printf("ACCOUNT NUMBER ");
        rectangle(35,8,70,10);
        gotoxy(37,9);
        scanf("%s",&acn);

        //Checking in file
        FILE *qq;
        qq=fopen("d:\\bank\\newdata.info","r");
        while(fscanf(qq,"%s %s %d %s %s",&name,&address,&contact,&ACNO,&password)!=EOF)
        {
            if(strcmp(acn,ACNO)==0)
            {
                gotoxy(30,13);printf("NAME     : %s",name);
                gotoxy(30,15);printf("ROLL NO  : %s",ACNO);

                goto p1;

            }
        }

        switch(j)
        {
        case 0:
            gotoxy(30,20);
            printf("WRONG ACCOUNT NUMBER.....");
            ch=getch();
            switch(ch)
            {
            case 13:
                withdrawActivity();
                break;
            case 27:
                adminInterface();
                break;
            }

            break;

        case 1:
            do{
                    p1:
             gotoxy(18,19);printf("WITHDRAW AMOUNT ");
             rectangle(36,18,70,20);
             gotoxy(40,19);
             scanf(" %d",&amount);
             k=MessageBox(NULL,"ARE YOU SURE??","WITHDRAW BALANCE",MB_YESNOCANCEL);
            }while(k==7);
             switch(k)
             {
             case 2:
                adminInterface();
                break;
             case 6:
                withDraw(acn,amount);
                break;
             }
             break;




        }



}

//BALANCE WITHDRAW LIST
void withdrawList()
{
      //VARIABLE CREATION
    int i;
    system("cls");
    struct withdraw{

        char sName[15];
    char sAddress[15];
    int sContact;
    char sRollno[15];
    char sPassword[15];
    int  sBalance;
    char sAccount[15];
     int day,month,year;
    };

        struct withdraw Acc;


         int k=1;
            char ch="s";
            int choice=1;
            int cy=10,ly=10,y;
            int start=1;
            int end=15;
            int l=0;
            int import=0;


    //DISPLAY ALL LAYOUT
    rectangle(1,1,100,25);
    gotoxy(37,6);
    printf("BALANCE WITHDRAW LIST");
    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);

    //FILE DECLARATION

        FILE *qqq;
        FILE *balan;



    //title list

    gotoxy(5,8);printf("ACCOUNT NO.");

    gotoxy(30,8);printf("NAME");

     gotoxy(50,8);printf("WITHDRAW AMOUNT");

     gotoxy(77,8);printf("DATE");
    gotoxy(2,9);
    for(i=1;i<98;i++)printf("-");




//SCROLL CODE
do{
       cy=10;
        ly=10;
         y=10;
         int j;

         import=0;

//CLEARING ALL LIST DISPLAY SCREEN
         for(i=1;i<=15;i++)
         {
             gotoxy(5,y);
             printf("                           ");

             gotoxy(30,y);
             printf("                  ");

             gotoxy(50,y);
             printf("                           ");

              gotoxy(70,y);
             printf("                           ");


                 y=y+1;

         }
         y=10;

         //INITIAL SELECTION LOCATION
         gotoxy(2,10);
         printf("#");

         //DATA DISPLAY

   qqq=fopen("d:\\bank\\withdraw.info","r");

    //importing from file
   while(fscanf(qqq,"%s %d %d %d %d",&Acc.sAccount,&Acc.sBalance,&Acc.year,&Acc.month,&Acc.day)!=EOF)
   {
       import=import+1;
    if(import>=start && import<start+end){

     gotoxy(5,y);printf("%s",Acc.sAccount);

     gotoxy(50,y);printf("%d",Acc.sBalance);

    gotoxy(77,y);printf("%d-%d-%d",Acc.year,Acc.month,Acc.day);

       balan=fopen("d:\\bank\\newdata.info","r");
            while(fscanf(balan,"%s %s %d %s %s",&Acc.sName,&Acc.sAddress,&Acc.sContact,&Acc.sRollno,&Acc.sPassword)!=EOF)
            {
                if(strcmp(Acc.sRollno,Acc.sAccount)==0)
                {
                    gotoxy(30,y);
                    printf("%s",Acc.sName);
                     y++;
                }

            }
            fclose(balan);


    }
   }
     fclose(qqq);

     //SELECTION PROCESS

     do{
            k=1;
            ch=getch();

     switch(ch)
     {
     case 27:
        Display();
        break;
     case 's':
        ly=ly+1;
        choice++;
        for(cy=10;cy<25;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

         case 'w':
        ly=ly-1;
        choice--;
        for(cy=10;cy<25;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

     }

     //SCROLL CONDITION
     if(choice==start+end)
     {
         k=0;
         start=start+15;

     }
     if(choice<start)
     {
         k=0;
         start=start-15;
         choice=choice-14;
         if(start<1)
         {start=1;
         choice=1;
         }
     }

     }while(k==1);

}while(1);

}

//INFORMATION CENTER
void Display()
{
        int i;

    system("cls");
    rectangle(1,1,100,25);
    gotoxy(40,6);
    printf("INFORMATION CENTER");
    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);

    //OPTION MENU
     gotoxy(40,10);
    printf("CLIENT LIST");
     gotoxy(40,12);
    printf("DEPOSITION LIST");
    gotoxy(40,14);
    printf("WITHDRAW LIST");
     gotoxy(40,16);
    printf("TRANSFER LIST");

    int choice=1;
    char ch="a";
    do
    {
        switch(ch)
        {
        case 'w':
            if(choice<1)
                choice=1;
            else
                choice--;
            break;

        case 's':
             if(choice>4)
                choice=4;
            else
                choice++;
            break;
        case 27:
            adminInterface();


        }
        switch(choice)
        {
            case 1:
                gotoxy(38,10);printf("#");
                gotoxy(38,12);printf("  ");
                gotoxy(38,14);printf("  ");
                gotoxy(38,16);printf("  ");
                break;
            case 2:
                gotoxy(38,10);printf("  ");
                gotoxy(38,12);printf("#");
                gotoxy(38,14);printf("  ");
                gotoxy(38,16);printf("  ");
                break;
            case 3:
                gotoxy(38,10);printf("  ");
                gotoxy(38,12);printf("  ");
                gotoxy(38,14);printf("#");
                gotoxy(38,16);printf("  ");
                break;
            case 4:
                gotoxy(38,10);printf("  ");
                gotoxy(38,12);printf("  ");
                gotoxy(38,14);printf("  ");
                gotoxy(38,16);printf("#");
        }
        gotoxy(0,0);
        ch=getch();
    }while(ch!=13);
        switch(choice)
        {
        case 1:
            DisplayALL();
            break;
        case 2:
            depositionList();
            break;
        case 3:
            withdrawList();
            break;
        case 4:
            transferList();
            break;
        }


}

//DISPLAY ALL USERS
void DisplayALL()
{




    //VARIABLE CREATION
    int i;
    system("cls");
    struct newAcc{

        char sName[15];
        char sAddress[15];
        int sContact;
        char sRollno[15];
        char sPassword[15];
        int  sBalance;
        char sAccount[15];
    };

        struct newAcc Acc;


         int k=1;
            char ch="s";
            int choice=1;
            int cy=10,ly=10,y;
            int start=1;
            int end=15;
            int l=0;
            int import=0;

    //DISPLAY ALL LAYOUT
    rectangle(1,1,100,25);
    gotoxy(40,6);
    printf("ClIENT LIST");
    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);

    //FILE DECLARATION

        FILE *qqq;
        FILE *balan;



    //title list
    gotoxy(5,8);
    printf("FULL NAME");

    gotoxy(35,8);
    printf("ADDRESS");

    gotoxy(55,8);
    printf("CONTACT");

    gotoxy(70,8);
    printf("ROLL NO.");

    gotoxy(85,8);
    printf("BALANCE");
    gotoxy(2,9);
    for(i=1;i<98;i++)printf("-");




//SCROLL CODE
do{
       cy=10;
        ly=10;
         y=10;
         int j;

         import=0;

//CLEARING ALL LIST DISPLAY SCREEN
         for(i=1;i<=15;i++)
         {
             gotoxy(4,y);
             printf("                           ");

             gotoxy(35,y);
             printf("                  ");

             gotoxy(50,y);
             printf("                           ");

             gotoxy(70,y);
             printf("                    ");

              gotoxy(85,y);
                 printf("           ");

                y=y+1;

         }
         y=10;

         //INITIAL SELECTION LOCATION
         gotoxy(2,10);
         printf("#");

         //DATA DISPLAY

   qqq=fopen("d:\\bank\\newdata.info","r");

    //importing from file
   while(fscanf(qqq,"%s %s %d %s %s",&Acc.sName,&Acc.sAddress,&Acc.sContact,&Acc.sRollno,&Acc.sPassword)!=EOF)
   {
       import=import+1;

    // printf("\n %s \t %s \t %d \t %s ",Acc.sName,Acc.sAddress,Acc.sContact,Acc.sRollno);
    if(import>=start && import<start+end){


     gotoxy(4,y);
     printf("%s",Acc.sName);

     gotoxy(35,y);
     printf("%s",Acc.sAddress);

     gotoxy(55,y);
     printf("%d",Acc.sContact);

     gotoxy(70,y);
     printf("%s",Acc.sRollno);


     balan=fopen("D:\\bank\\balance.info","a+");
     while(fscanf(balan,"%s %d",&Acc.sAccount,&Acc.sBalance)!=EOF)
     {
         if(strcmp(Acc.sRollno,Acc.sAccount)==0)
            {
                 gotoxy(85,y);
                 printf("%d",Acc.sBalance);

                 y=y+1;
            }
     }
     fclose(balan);
    }
   }
     fclose(qqq);

     //SELECTION PROCESS

     do{
            k=1;
            ch=getch();

     switch(ch)
     {
     case 27:
        Display();
        break;
     case 13:
           j=0;
         qqq=fopen("d:\\bank\\newdata.info","r");
        //importing from file
        while(fscanf(qqq,"%s %s %d %s %s",&Acc.sName,&Acc.sAddress,&Acc.sContact,&Acc.sRollno,&Acc.sPassword)!=EOF)
        {
            j++;
            if(j==choice)
              {
                 j=clientInfo(Acc.sName,Acc.sAddress,Acc.sContact,Acc.sRollno);
              }

        }

        break;
     case 's':
        ly=ly+1;
        choice++;
        for(cy=10;cy<25;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

         case 'w':
        ly=ly-1;
        choice--;
        for(cy=10;cy<25;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

     }

     //SCROLL CONDITION
     if(choice==start+end)
     {
         k=0;
         start=start+15;

     }
     if(choice<start)
     {
         k=0;
         start=start-15;
         choice=choice-14;
         if(start<1)
         {start=1;
         choice=1;
         }
     }

     }while(k==1);

}while(1);


}


//LOGIN PAGE

void login()
{

    char accountno[15];
    char password[15];
    int x=0;
    char xh;

    system("cls");
    logInlayout();
    gotoxy(40,6);
    printf("USER LOGIN");

    do{
    gotoxy(36,11);printf("                ");
    gotoxy(36,15);printf("               ");
    gotoxy(36,11);
    scanf(" %s",&accountno);

     gotoxy(36,15);
    scanf(" %s",&password);

    //checking data of user

     struct newAcc{
    char sName[15];
    char sAddress[15];
    int sContact;
    char sRollno[15];
    char sPassword[15];
    };

        struct newAcc Acc;


        FILE *qqq;

    qqq=fopen("d:\\bank\\newdata.info","r");
    //importing from file
    int y=3;
   while(fscanf(qqq,"%s %s %d %s %s",&Acc.sName,&Acc.sAddress,&Acc.sContact,&Acc.sRollno,&Acc.sPassword)!=EOF)
   {

    if(strcasecmp(accountno,Acc.sRollno)==0 && strcmp(password,Acc.sPassword)==0)
    {
        printf("matched");
        x=1;
        userInterface(Acc.sName,Acc.sAddress,Acc.sContact,Acc.sRollno);
    }
   }
   //gotoxy(35,18);
   //printf("not matched");
     fclose(qqq);
     gotoxy(40,23);
     printf("!!!INVALID ACCOUNT!!!");
     gotoxy(40,25);
     printf("PRESS 'enter' -TRY AGAIN");
     gotoxy(40,27);printf("PRESS 'ESC' -TO RETURN");
     gotoxy(40,29);xh=getch();

     switch(xh)
     {
     case 27:
        home();
        break;
     default:
        x=0;
        break;
     }
    }while(x==0);

}

 //USER INTERFACE
    void userInterface(char name[15],char address[15],int contact,char accountno[15])
    {
        int i;
        int k=1;
        int m=1;
         int option=1;
            char ch='a';
            int choice=1;
            int cy=14,ly=14,y;
            int start=1;
            int end=14;
            int l=0;
            int import=0;
     system("cls");
        //OUTLINE DISPLAY
        rectangle(1,1,105,28);
        gotoxy(2,7);for(i=0;i<102;i++) printf("%c",196);
        gotoxy(42,6);printf("USER INFORMATION");

         int balan,balance1=0;
         int inter,inter1;
           int day,month,year,month11;
           int wDay,wMonth,wYear;
           char n[15];

         FILE *bal;
         bal=fopen("D:\\bank\\balance.info","r");
         while(fscanf(bal,"%s %d",&n,&balan)!=EOF)
         {
             if(strcmp(n,accountno)==0)
               {
                balance1=balan;
                break;
               }

         }
         fclose(bal);

          bal=fopen("D:\\bank\\interest.info","r");
         while(fscanf(bal,"%s %d %d %d %d %d",&n,&inter1,&year,&month,&day,&month11)!=EOF)
         {
             if(strcmp(n,accountno)==0)
                {inter=inter1;
                break;
                }

         }
         fclose(bal);

        //CLIENT DETAILS
        gotoxy(7,8);
        printf("NAME      :  %s",name);
        gotoxy(7,9);
        printf("ADDRESS   :  %s",address);
        gotoxy(45,8);
        printf("CONTACT    :  %d",contact);
        gotoxy(45,9);
        printf("ACCOUNT NO :  %s",accountno);
        gotoxy(80,8);
        printf("BALANCE  : %d",balance1);
        gotoxy(80,9);
        printf("INTEREST : %d",inter);
        gotoxy(2,10);for(i=0;i<102;i++)printf("-");
        gotoxy(5,11);printf("TRANSACTIONS");
         gotoxy(2,12);for(i=0;i<102;i++)printf("-");
         gotoxy(85,11);printf("TRANSFER BALANCE");
         gotoxy(80,10);for(i=1;i<25;i++)printf("%c",196);
         gotoxy(80,12);for(i=1;i<25;i++)printf("%c",196);
         gotoxy(80,11);printf("%c",179);
          y=14;

         int deposites,withdraws,transfers;
         char acn[15],transTo[15];
         FILE *deposite,*withdraw,*transfer,*date,*interest;

         do{

        cy=13;
        ly=13;
         y=13;
         int j;

         import=0;

//CLEARING ALL LIST DISPLAY SCREEN
         for(i=1;i<=15;i++)
         {
             gotoxy(5,y);
             printf("                           ");

             gotoxy(30,y);
             printf("                  ");

             gotoxy(50,y);
             printf("                           ");

              gotoxy(70,y);
             printf("                           ");


                 y=y+1;

         }
         y=13;

         //INITIAL SELECTION LOCATION
         gotoxy(2,13);
         printf("#");

         //DATA DISPLAY

date=fopen("D:\\bank\\date.info","r");
while(fscanf(date,"%d %d %d",&wYear,&wMonth,&wDay)!=EOF)
    {

   deposite=fopen("D:\\bank\\deposited.info","r");

    //importing from file
   while(fscanf(deposite,"%s %d %d %d %d",&acn,&deposites,&year,&month,&day)!=EOF)
   {
       if(wDay==day && wMonth==month && wYear==year)
        {
       if(strcmp(acn,accountno)==0){
              import=import+1;
             if(import>=start && import<=start+end){
                gotoxy(5,y);printf("deposited");
                 gotoxy(25,y);printf("%d",deposites);
                 gotoxy(55,y);printf("----");
                 gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                 y++;
             }
       }
       }
   } fclose(deposite);

    interest=fopen("D:\\bank\\interestList.info","r");

    //importing from file
   while(fscanf(interest,"%s %d %d %d %d",&acn,&deposites,&year,&month,&day)!=EOF)
   {
       if(wDay==day && wMonth==month && wYear==year)
        {
       if(strcmp(acn,accountno)==0){
              import=import+1;
             if(import>=start && import<=start+end){
                gotoxy(5,y);printf("interest");
                 gotoxy(25,y);printf("%d",deposites);
                 gotoxy(55,y);printf("----");
                 gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                 y++;
             }
       }
       }
   } fclose(interest);

    withdraw=fopen("D:\\bank\\withdraws.info","r");
         while(fscanf(withdraw,"%s %d %d %d %d",&acn,&withdraws,&year,&month,&day)!=EOF)
         {
              if(wDay==day && wMonth==month && wYear==year){
             if(strcmp(acn,accountno)==0)
             {
                 import=import+1;
                if(import>=start && import<start+end){
                     gotoxy(5,y);printf("WITHDRAWN");
                    gotoxy(25,y);printf("%d",withdraws);
                    gotoxy(55,y);printf("---");
                    gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                    y++;

                }
             }
              }
         }

          fclose(withdraw);

         transfer=fopen("D:\\bank\\trans.info","r");
         while(fscanf(transfer,"%s  %s %d %d %d %d",&acn,&transTo,&transfers,&year,&month,&day)!=EOF)
         {
              if(wDay==day && wMonth==month && wYear==year){
             if(strcmp(acn,accountno)==0)
             {
                 import=import+1;
                 if(import>=start && import<start+end){

                    gotoxy(5,y);printf("TRANSFERD");
                 gotoxy(25,y);printf("%d",transfers);
                 gotoxy(55,y);printf("%s",transTo);
                 gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                 y++;
                 }
             }

               if(strcmp(transTo,accountno)==0)
             {
                 import=import+1;
                 if(import>=start && import<start+end){

                    gotoxy(5,y);printf("RECEIVED");
                 gotoxy(25,y);printf("%d",transfers);
                 gotoxy(55,y);printf("%s",acn);
                 gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                 y++;
                 }
             }
              }
         }
          fclose(transfer);

    }

//SELECTION PROCESS

     do{
            k=1;

            option=1;

            while(m==1)
            {
                gotoxy(2,13);printf("  ");

                switch(ch)
                {
                case 'd':
                    gotoxy(83,11);printf("#");
                    gotoxy(2,11);printf("   ");
                    option=2;
                    break;
                case 'a':
                    gotoxy(2,11);printf("#");
                    gotoxy(83,11);printf("  ");
                    option=1;
                    break;
                case 27:
                    home();
                    break;
                case 13:
                    switch(option)
                    {
                    case 1:
                         gotoxy(2,13);printf("#");
                        gotoxy(2,11);printf(" ");
                        gotoxy(83,11);printf(" ");
                        m=0;
                        break;
                    case 2:
                       balanceTransfer(name,address,contact,accountno,balance1);
                       break;

                    }
                    break;
                }
                 gotoxy(0,0);ch=getch();


            }

             ch=getch();

     switch(ch)
     {
     case 27:
        m=1;
         for(cy=13;cy<27;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf(" ");}

        }
        ch='a';
        break;
     case 's':
        ly=ly+1;
        choice++;
        for(cy=13;cy<27;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

         case 'w':
        ly=ly-1;
        choice--;
        for(cy=13;cy<27;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

     }

     //SCROLL CONDITION
     if(choice==start+end)
     {
         k=0;
         start=start+14;

     }
     if(choice<start)
     {
         k=0;
         start=start-14;
         choice=choice-14;
         if(start<1)
         {start=1;
         choice=1;
         }
     }

     }while(k==1);


    }while(1);
    }

    //BALANCE TRANSECTION

    void balanceTransfer(char name[15],char address[15],int contact,char accNo[15],int balance)
    {
         system("cls");
         int i;
        //OUTLINE DISPLAY
        rectangle(1,1,105,28);
        gotoxy(2,7);for(i=0;i<102;i++) printf("%c",196);
        gotoxy(40,6);printf("BALANCE TRANSFER");
        gotoxy(2,10);for(i=0;i<102;i++) printf("%c",196);

        //CLIENT DETAILS
        gotoxy(7,8);
        printf("NAME       :  %s",name);
        gotoxy(7,9);
        printf("ADDRESS    :  %s",address);
        gotoxy(45,8);
        printf("CONTACT    :  %d",contact);
        gotoxy(45,9);
        printf("ACCOUNT NO :  %s",accNo);
        gotoxy(80,9);
        printf("BALANCE    : %d",balance);



        //TO WHOM
        char receiverAcc[15];
        gotoxy(6,12);
        printf("TRANSFER BALANCE TO:");

        gotoxy(7,14);
        printf("ACCOUNT NO   :  ");

        scanf(" %s",&receiverAcc);

        //checking contact in database

    struct newAcc{
    char sName[15];
    char sAddress[15];
    int sContact;
    char sRollno[15];
    char sPassword[15];
    };

        struct newAcc Acc;

        FILE *qqq;

    qqq=fopen("d:\\bank\\newdata.info","r");
    //importing from file
    int y=3;
    int trn=0;
   while(fscanf(qqq,"%s %s %d %s %s",&Acc.sName,&Acc.sAddress,&Acc.sContact,&Acc.sRollno,&Acc.sPassword)!=EOF)
   {

    if(strcasecmp(receiverAcc,Acc.sRollno)==0)
    {
         //CLIENT DETAILS
        gotoxy(7,16);
        printf("NAME         :  %s",Acc.sName);
        gotoxy(7,17);
        printf("ADDRESS      :  %s",Acc.sAddress);
        gotoxy(7,18);
        printf("CONTACT      :  %d",Acc.sContact);
        trn=1;
        break;
    }
   }
   fclose(qqq);
    int tamt;
    char t;
    char yn;
   switch(trn)
   {
       case 0:
           gotoxy(50,26);
            printf("No data found");
            getch();
              balanceTransfer(name, address, contact, accNo,balance);
              break;

        case 1:

                do{
              gotoxy(60,14);
              printf("TRANSFER AMOUNT  : ");
              scanf(" %d",&tamt);
              if(balance<tamt)
                {
                    gotoxy(35,24);
                printf("!!!your balance is low to transfer!!!");
                t=getch();
                 gotoxy(70,14);printf("                   ");
                if(t==27)
                    userInterface(name,address,contact,accNo);

                }
                else
                {

                  break;
                 }

                }while(1);
              //yn=getch();
               t=MessageBox(NULL,"ARE YOU SURE?","TRANSFER CONFIRMATION",MB_YESNOCANCEL);
               switch(t)
               {
                   case 6:
                   gotoxy(30,25);
                   y=transfer(accNo,receiverAcc,tamt);
                   printf("successfully transferred Rs %d TO %s",tamt,Acc.sName);
                   gotoxy(40,26);
                   printf("press any key....");
                   getch();
                    userInterface(name, address, contact, accNo);
                    break;

               case 7:
                   balanceTransfer(name, address, contact, accNo,balance);
                   break;
               case 2:
                    userInterface(name, address, contact, accNo);
               break;
   }

    }
    }

    //CLIENT INFO
    int clientInfo(char name[15],char address[15],int contact,char accountnos[15])
    {
         int i;

         int k=1;
            char ch="s";
            int choice=1;
            int cy=14,ly=14,y;
            int start=1;
            int end=14;
            int l=0;
            int import=0;
     system("cls");
        //OUTLINE DISPLAY
        rectangle(1,1,105,28);
        gotoxy(2,7);for(i=0;i<102;i++) printf("%c",196);
        gotoxy(42,6);printf("CLIENT DETAIL");

         int balAn,balanc;
         int inter,inter1;
          int day,month,year;
         int month11;
         char n[15];
         FILE *bal;
         bal=fopen("D:\\bank\\balance.info","r");
         while(fscanf(bal,"%s %d",&n,&balAn)!=EOF)
         {
             if(strcmp(n,accountnos)==0)
                {balanc=balAn;
                break;
                }

         }
         fclose(bal);

          bal=fopen("D:\\bank\\interest.info","r");
         while(fscanf(bal,"%s %d %d %d %d %d",&n,&inter1,&year,&month,&day,&month11)!=EOF)
         {
             if(strcmp(n,accountnos)==0)
                {inter=inter1;
                break;
                }

         }
         fclose(bal);

        //CLIENT DETAILS
        gotoxy(7,8);
        printf("NAME      :  %s",name);
        gotoxy(7,9);
        printf("ADDRESS   :  %s",address);
        gotoxy(45,8);
        printf("CONTACT    :  %d",contact);
        gotoxy(45,9);
        printf("ACCOUNT NO :  %s",accountnos);
        gotoxy(80,8);
        printf("BALANCE  : %d",balanc);
        gotoxy(80,9);
        printf("INTEREST : %d",inter);
        gotoxy(2,10);for(i=0;i<102;i++)printf("-");
        gotoxy(5,11);printf("TRANSACTIONS");
        gotoxy(25,11);printf("AMOUNT");
        gotoxy(55,11);printf("TRANSFET TO");
        gotoxy(85,11);printf("DATE");

         gotoxy(2,12);for(i=0;i<102;i++)printf("-");
         y=14;

         int wDay,wMonth,wYear;
         int deposites,withdraws,transfers;
         char acn[15],transTo[15];
         FILE *deposite,*withdraw,*transfer,*date,*interest;

  do{

        cy=13;
        ly=13;
         y=13;
         int j;

         import=0;

//CLEARING ALL LIST DISPLAY SCREEN
         for(i=1;i<=15;i++)
         {
             gotoxy(5,y);
             printf("                           ");

             gotoxy(30,y);
             printf("                  ");

             gotoxy(50,y);
             printf("                           ");

              gotoxy(70,y);
             printf("                           ");


                 y=y+1;

         }
         y=13;

         //INITIAL SELECTION LOCATION
         gotoxy(2,13);
         printf("#");

         //DATA DISPLAY
         date=fopen("D:\\bank\\date.info","r");
while(fscanf(date,"%d %d %d",&wYear,&wMonth,&wDay)!=EOF)
{

   deposite=fopen("D:\\bank\\deposited.info","r");

    //importing from file
   while(fscanf(deposite,"%s %d %d %d %d",&acn,&deposites,&year,&month,&day)!=EOF)
   {
       if(wDay==day && wMonth==month && wYear==year)
       {
       if(strcmp(acn,accountnos)==0){
              import=import+1;
             if(import>=start && import<start+end){
                gotoxy(5,y);printf("deposited");
                 gotoxy(25,y);printf("%d",deposites);
                 gotoxy(55,y);printf("----");
                 gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                 y++;
             }
       }
       }
   } fclose(deposite);

    interest=fopen("D:\\bank\\interestList.info","r");

    //importing from file
   while(fscanf(interest,"%s %d %d %d %d",&acn,&deposites,&year,&month,&day)!=EOF)
   {
       if(wDay==day && wMonth==month && wYear==year)
       {
       if(strcmp(acn,accountnos)==0){
              import=import+1;
             if(import>=start && import<start+end){
                gotoxy(5,y);printf("interest");
                 gotoxy(25,y);printf("%d",deposites);
                 gotoxy(55,y);printf("----");
                 gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                 y++;
             }
       }
       }
   } fclose(interest);

    withdraw=fopen("D:\\bank\\withdraw.info","r");
         while(fscanf(withdraw,"%s %d %d %d %d",&acn,&withdraws,&year,&month,&day)!=EOF)
         {
             if(wDay==day && wMonth==month && wYear==year){
             if(strcmp(acn,accountnos)==0)
             {
                 import=import+1;
                if(import>=start && import<start+end){
                     gotoxy(5,y);printf("WITHDRAWN");
                    gotoxy(25,y);printf("%d",withdraws);
                    gotoxy(55,y);printf("---");
                    gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                    y++;

                }
             }
             }
         }

          fclose(withdraw);

          transfer=fopen("D:\\bank\\trans.info","r");
         while(fscanf(transfer,"%s  %s %d %d %d %d",&acn,&transTo,&transfers,&year,&month,&day)!=EOF)
         {
             if(wDay==day && wMonth==month && wYear==year){
             if(strcmp(acn,accountnos)==0)
             {
                 import=import+1;
                 if(import>=start && import<start+end){

                    gotoxy(5,y);printf("TRANSFERD");
                 gotoxy(25,y);printf("%d",transfers);
                 gotoxy(55,y);printf("%s",transTo);
                 gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                 y++;
                 }
             }

              if(strcmp(transTo,accountnos)==0)
             {
                 import=import+1;
                 if(import>=start && import<start+end){

                    gotoxy(5,y);printf("RECEIVED");
                 gotoxy(25,y);printf("%d",transfers);
                 gotoxy(55,y);printf("%s",acn);
                 gotoxy(85,y);printf("%d-%d-%d",year,month,day);
                 y++;
                 }
             }
             }
         }
          fclose(withdraw);

}

//SELECTION PROCESS

     do{
            k=1;
            ch=getch();

     switch(ch)
     {
     case 27:
        DisplayALL();
        break;
     case 's':
        ly=ly+1;
        choice++;
        for(cy=13;cy<27;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

         case 'w':
        ly=ly-1;
        choice--;
        for(cy=13;cy<27;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

     }

     //SCROLL CONDITION
     if(choice==start+end)
     {
         k=0;
         start=start+14;

     }
     if(choice<start)
     {
         k=0;
         start=start-14;
         choice=choice-14;
         if(start<1)
         {start=1;
         choice=1;
         }
     }

     }while(k==1);


    }while(1);
    }




    //DEPOSITR BALANCE

    int depositeBalance(char accountno[15],int  amount)
    {
        char Account[15];
        char account[15];
        int  bal;
        int day,month,year;
        int amounts;

        //DATE CALCULATION
    struct SYSTEMTIME{
    WORD  wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
      WORD wHour;
    WORD wMinute;
    WORD wSecond;
};
SYSTEMTIME str;
         GetSystemTime(&str);
         day=str.wDay;
         month=str.wMonth;
         year=str.wYear;
         //-----------

        FILE *balance,*bal1;
         FILE *depos,*depos1;
        //DEPOSITING BALANCE
         bal1=fopen("D:\\bank\\balance1.info","w");
        fclose(bal1);

        balance=fopen("D:\\bank\\balance.info","r");

        bal1=fopen("D:\\bank\\balance1.info","a+");

        while(fscanf(balance,"%s %d",&Account,&bal)!=EOF)
        {
            if(strcmp(accountno,Account)==0)
                fprintf(bal1,"%s %d\n",Account,bal+amount);
            else
                fprintf(bal1,"%s %d\n",Account,bal);
        }
        fclose(balance);
        fclose(bal1);

        //UPDATING DATA IN FILE
        balance=fopen("D:\\bank\\balance.info","w");
        fclose(balance);

         balance=fopen("D:\\bank\\balance.info","a+");

        bal1=fopen("D:\\bank\\balance1.info","r");

        while(fscanf(bal1,"%s %d",&Account,&bal)!=EOF)
        {
                fprintf(balance,"%s %d\n",Account,bal);
        }
        fclose(balance);
        fclose(bal1);



        depos1=fopen("D:\\bank\\deposited1.info","w");
            fprintf(depos1,"%s %d %d %d %d\n",accountno,amount,year,month,day);
        fclose(depos1);

        depos1=fopen("D:\\bank\\deposited1.info","a+");
        depos=fopen("D:\\bank\\deposited.info","a+");
        while(fscanf(depos,"%s %d %d %d %d ",&account,&amounts,&year,&month,&day)!=EOF)
        {
             fprintf(depos1,"%s %d %d %d %d\n",account,amounts,year,month,day);

        }
        fclose(depos);

        fclose(depos1);

        //RETRIVING DATA

          depos=fopen("D:\\bank\\deposited.info","w");
          fclose(depos);

          depos=fopen("D:\\bank\\deposited.info","a+");

        depos1=fopen("D:\\bank\\deposited1.info","r");
        while(fscanf(depos1,"%s %d %d %d %d ",&account,&amounts,&year,&month,&day)!=EOF)
        {
             fprintf(depos,"%s %d %d %d %d\n",account,amounts,year,month,day);

        }
        fclose(depos1);

        fclose(depos);


        depositionList();

  }
  //------------------------------------------------------------------------------------------------

  //BALANCE WITHDRAW

   int  withDraw(char accountno[15],int amount)
    {
        char Account[15];
        char account[15];
        int  bal;
        int day,month,year,amount1;

        struct SYSTEMTIME{
    WORD  wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
      WORD wHour;
    WORD wMinute;
    WORD wSecond;
};
SYSTEMTIME str;
         GetSystemTime(&str);
         day=str.wDay;
         month=str.wMonth;
         year=str.wYear;
         //-----------

        FILE *balance,*bal1;
         FILE *withd,*withd1;
        //WITHDRAWING BALANCE
        balance=fopen("D:\\bank\\balance.info","r");
        bal1=fopen("D:\\bank\\balance1.info","w");
        fclose(bal1);
        bal1=fopen("D:\\bank\\balance1.info","a+");


        while(fscanf(balance,"%s %d",&Account,&bal)!=EOF)
        {

            if(strcmp(accountno,Account)==0)
            {
                if(bal>amount)
                    {
                    fprintf(bal1,"%s %d\n",Account,bal-amount);
                    }

                      else
                        {
                        gotoxy(30,25);printf("YOUR BALANCE IS LOW (%d)",bal);
                      getch();
                        withdrawActivity();
                        }
            }

            else
                fprintf(bal1,"%s %d\n",Account,bal);
        }
        fclose(balance);
        fclose(bal1);

        //UPDATING DATA IN FILE
        balance=fopen("D:\\bank\\balance.info","w");
        fclose(balance);
        balance=fopen("D:\\bank\\balance.info","a+");
        bal1=fopen("D:\\bank\\balance1.info","r");

        while(fscanf(bal1,"%s %d",&Account,&bal)!=EOF)
        {
                fprintf(balance,"%s %d\n",Account,bal);
        }
        fclose(balance);
        fclose(bal1);



        withd1=fopen("D:\\bank\\withdraw1.info","w+");
        fprintf(withd1,"%s %d %d %d %d\n",accountno,amount,year,month,day);
        fclose(withd1);

        withd1=fopen("D:\\bank\\withdraw1.info","a+");

        withd=fopen("d:\\bank\\withdraw.info","r");
        while(fscanf(withd,"%s %d %d %d %d",&account,&amount1,&year,&month,&day)!=EOF)
        {
             fprintf(withd1,"%s %d %d %d %d\n",account,amount1,year,month,day);
        }
        fclose(withd);
        fclose(withd1);

        //retriving data

         withd=fopen("D:\\bank\\withdraw.info","w");
         fclose(withd);

        withd=fopen("D:\\bank\\withdraw.info","a+");

        withd1=fopen("d:\\bank\\withdraw1.info","r");
        while(fscanf(withd1,"%s %d %d %d %d",&account,&amount1,&year,&month,&day)!=EOF)
        {
             fprintf(withd,"%s %d %d %d %d\n",account,amount1,year,month,day);
        }
        fclose(withd1);
        fclose(withd);

        //CLEARING DATA FROM WITHDRAWDATA1
        // withd1=fopen("D:\\bank\\withdraw1.info","w");
        // fclose(withd1);


        gotoxy(35,23);printf("!!!successfully withdrawed Rs%d   !!!",amount);
        getch();
        withdrawList();
  }

  //BALANCE TRANSFER ACTIVITY


   int  transfer(char accountno[15],char transferTo[15],int amount)
    {
        char Account[15];
        char account[15];
        char transfer[15];
        int amounts;
        int  bal;
        int year,month,day;

        //DATE CALCULATION
    struct SYSTEMTIME{
    WORD  wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
      WORD wHour;
    WORD wMinute;
    WORD wSecond;
};
SYSTEMTIME str;

 GetSystemTime(&str);
         day=str.wDay;
         month=str.wMonth;
         year=str.wYear;

        FILE *balance,*bal1;
         FILE *trans,*trans1;
        //WITHDRAWING BALANCE
        balance=fopen("D:\\bank\\balance.info","r");
        bal1=fopen("D:\\bank\\balance1.info","w");
        fclose(bal1);
        bal1=fopen("D:\\bank\\balance1.info","a+");


        while(fscanf(balance,"%s %d",&Account,&bal)!=EOF)
        {
            if(strcmp(accountno,Account)==0)
                fprintf(bal1,"%s %d\n",Account,bal-amount);
            else if(strcmp(Account,transferTo)==0)
                fprintf(bal1,"%s %d\n",Account,bal+amount);
            else
                fprintf(bal1,"%s %d\n",Account,bal);
        }
        fclose(balance);
        fclose(bal1);

        //UPDATING DATA IN FILE
        balance=fopen("D:\\bank\\balance.info","w");
        fclose(balance);
        balance=fopen("D:\\bank\\balance.info","a+");
        bal1=fopen("D:\\bank\\balance1.info","r");

        while(fscanf(bal1,"%s %d",&Account,&bal)!=EOF)
        {
                fprintf(balance,"%s %d\n",Account,bal);
        }
        fclose(balance);
        fclose(bal1);




        trans1=fopen("D:\\bank\\trans1.info","w+");
        fprintf(trans1,"%s %s %d %d %d %d\n",accountno,transferTo,amount,year,month,day);
        fclose(trans1);

        trans1=fopen("D:\\bank\\trans1.info","a+");

        trans=fopen("D:\\bank\\trans.info","r");
        while(fscanf(trans,"%s %s %d %d %d %d\n",&account,&transfer,&amounts,&year,&month,&day)!=EOF)
        {
            fprintf(trans1,"%s  %s   %d   %d  %d  %d\n",account,transfer,amounts,year,month,day);
        }
        fclose(trans);
        fclose(trans1);

        //RETRIVING DATA TO TRANS.INFO


        trans=fopen("D:\\bank\\trans.info","w");
        fclose(trans);

        trans=fopen("D:\\bank\\trans.info","a+");

        trans1=fopen("D:\\bank\\trans1.info","r");
       while(fscanf(trans1,"%s  %s   %d   %d  %d  %d\n",&account,&transfer,&amounts,&year,&month,&day)!=EOF)
       {
            fprintf(trans,"%s  %s   %d   %d  %d  %d\n",account,transfer,amounts,year,month,day);
       }
       fclose(trans1);
       fclose(trans);

       return 0;

  }

  //TRANSFER LIST
  int transferList()
  {
          //VARIABLE CREATION
    int i;
    system("cls");
    struct transfer{
        char transferTo[15];
        int  sBalance;
        char sAccount[15];
        int year,month,day;
    };

        struct transfer Acc;


         int k=1;
            char ch="s";
            int choice=1;
            int cy=10,ly=10,y;
            int start=1;
            int end=15;
            int l=0;
            int import=0;

    //DISPLAY ALL LAYOUT
    rectangle(1,1,100,25);
    gotoxy(40,6);
    printf("TRANSFER LIST");
    gotoxy(2,7);for(i=0;i<97;i++) printf("%c",196);

    //FILE DECLARATION

        FILE *qqq;
        FILE *balan;



    //title list

    gotoxy(5,8);printf("ACCOUNT NO.");

    gotoxy(30,8);printf("BALANCE");

     gotoxy(50,8);printf("TRANSFER TO");

     gotoxy(70,8);printf("DATE");
    gotoxy(2,9);
    for(i=1;i<98;i++)printf("-");




//SCROLL CODE
do{
       cy=10;
        ly=10;
         y=10;
         int j;

         import=0;

//CLEARING ALL LIST DISPLAY SCREEN
         for(i=1;i<=15;i++)
         {
             gotoxy(5,y);
             printf("                           ");

             gotoxy(30,y);
             printf("                  ");

             gotoxy(50,y);
             printf("                           ");

              gotoxy(70,y);
             printf("                           ");


                 y=y+1;

         }
         y=10;

         //INITIAL SELECTION LOCATION
         gotoxy(2,10);
         printf("#");

         //DATA DISPLAY

   qqq=fopen("d:\\bank\\Trans.info","r");

    //importing from file
   while(fscanf(qqq,"%s %s %d %d %d %d",&Acc.sAccount,&Acc.transferTo,&Acc.sBalance,&Acc.year,&Acc.month,&Acc.day)!=EOF)
   {
       import=import+1;
    if(import>=start && import<start+end){

     gotoxy(5,y);printf("%s",Acc.sAccount);

     gotoxy(30,y);printf("%d",Acc.sBalance);

    gotoxy(50,y);printf("%s",Acc.transferTo);

     gotoxy(70,y);printf("%d-%d-%d",Acc.year,Acc.month,Acc.day);

        y=y+1;


    }
   }
     fclose(qqq);

     //SELECTION PROCESS

     do{
            k=1;
            ch=getch();

     switch(ch)
     {
     case 27:
        Display();
        break;
     case 's':
        ly=ly+1;
        choice++;
        for(cy=10;cy<25;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

         case 'w':
        ly=ly-1;
        choice--;
        for(cy=10;cy<25;cy++)
        {
            if(cy==ly)
            {gotoxy(2,ly);
                printf("#");}
            else
        {
            gotoxy(2,cy);
            printf(" ");
        }
        }
        break;

     }

     //SCROLL CONDITION
     if(choice==start+end)
     {
         k=0;
         start=start+15;

     }
     if(choice<start)
     {
         k=0;
         start=start-15;
         choice=choice-14;
         if(start<1)
         {start=1;
         choice=1;
         }
     }

     }while(k==1);

}while(1);

  }


//------------------------------------------------------------------------------------------------------
    //RECTANGLE FORMATION

void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
    gotoxy(40,3);
    printf("THE BANKING SYSTEM");
    gotoxy(2,5);for(i=0;i<(l-x-2);i++) printf("%c",196);

}
int gotoxy(int x,int y)
{
    COORD coord;

    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
int main()
{
   // logInlayout();
     //DisplayALL();
        date();
        interestcal();
        home();
       // depositeActivity();

}
