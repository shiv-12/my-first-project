#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
typedef struct coutmer
{
    int acno;
    int blc;
}coutmer;

int main()
{
    FILE *fp;                                 //for insert more data change a[5] to a[6...or]
    int acc,ch,i;
    coutmer a[5];
    fp=fopen("D:\\atm_record.txt","r");
    fread(&a,sizeof(a),1,fp);
    gotoxy(40,1);
    textcolor(YELLOW);
    printf("*** HELLO USER ***");
label:
    textcolor(YELLOW);
    delay(1000);

    printf("\n\nEnter your account number -  ");
    scanf("%d",&acc);
    printf("\nunder processing please wait...");
    delay(2000);

    for(i=0;i<5;i++)
    {
         if(acc==a[i].acno)
         {
             textcolor(GREEN);

             printf("\n\nYour total account balance is - %d",a[i].blc);
             textcolor(YELLOW);
             printf("\nChoose any one operation which you want to perform - \nPress 1 for deposite money\nPress 2 for withdrown money\nPress 3 for exit       => ");
             scanf("%d",&ch);
             switch(ch)
             {
                 case 1:
                     {
                         textcolor(YELLOW);
                         printf("\nEnter your ammount(deposite) - ");
                         scanf("%d",&ch);
                         a[i].blc=ch+a[i].blc;
                         fp=fopen("D:\\atm_record.txt","w");
                         fwrite(&a,sizeof(a),1,fp);
                          textcolor(GREEN);
                         printf("\nOperation successfully done");
                         break;
                     }
                 case 2:
                    {
                         printf("\nEnter your ammount(withdrown) - ");
                         scanf("%d",&ch);
                         a[i].blc=a[i].blc-ch;
                         fp=fopen("D:\\atm_record.txt","w");
                         fwrite(&a,sizeof(a),1,fp);
                          textcolor(GREEN);
                         printf("\nOperation successfully done");
                         break;
                    }
                 case 3:
                    {
                        exit(0);
                        break;
                    }
             }

             break;
         }
    }
    if(i==5)
    {
        textcolor(RED);

        printf("\n\ninvalid account number.. try again!\n\n");
        goto label;
    }
    fclose(fp);
    return 0;
}

