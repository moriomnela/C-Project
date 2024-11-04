#include<stdio.h>
#include<time.h>
char name[20];
int dip_amount;
int amount=10000;
int acc_no;

void menu();
void deposit_money();
void withdraw_money();
void transfer_money();
void account_details();
void transaction_details();
void last_details();

int main(){
  int choice;
  printf("Enter your name:");
  gets(name);

  printf("Enter your account no: ");
  scanf("%d",&acc_no);

  menu();
  printf("Enter your choice: ");
  scanf("%d",&choice);

  switch(choice){
    case 1:
       deposit_money();
       break;
    case 2:
        withdraw_money();
        break;
    case 3:
        transfer_money();
        break;
    case 4:
        account_details();
        break;
    case 5:
        transaction_details();
        break;
    case 6:
        last_details();
        exit(0);
    default:
        printf("Invalid to choice");
        break;
  }
  return 0;
}
void menu(){
   printf("MAIN MENU\n");
   printf("1.Deposit Money\n");
   printf("2.Withdraw Money\n");
   printf("3.Transfer Money\n");
   printf("4.Account details\n");
   printf("5.Transaction details\n");
   printf("6.Exit\n");
}
void deposit_money(){
    time_t tm;
    time(&tm);

   FILE *fptr=fopen("Account.txt","a");
   if(fptr == NULL){
    printf("Error opening file.\n");
    return;
   }
   printf("Deposit Money \n");
   printf("enter the amount \n");
   scanf("%d", &dip_amount);

   amount += dip_amount;
   printf("Money Deposit\n");
   printf("Current balance : %d",amount);
   fprintf(fptr,"Rs%d had been deposited to your account \n",dip_amount);
   fprintf(fptr,"Date of transaction %s", ctime(&tm));
}










