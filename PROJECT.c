//Project Name: Bank Management System
//Coders: Sheryar khan & Taha Rizwan
//Purpose of code: The given program is a simple command-line Bank Management System, Its purpose is to allow users to perform various banking operations, such as depositing money, withdrawing money, transferring money to other accounts, and checking account details and transaction history

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char name[20];
char user[50], pw[50], adminu[] = "FAST", adminpw[] = "taha";
int dip_amt, amt = 10000, acc_no, ac, count = 0;
int trans_amt;
int with_amt;

// Function declarations
void deposit_money();
void withdraw_money();
void transfer_money();
void checkDetail();
void LastDetail();
void transaction_details();
void menu();
void divider();

int main(){
printf("\tBANK MANAGEMENT SYSTEM\n");
    divider();
    printf("\n\t**LOGIN TO YOUR ACCOUNT**\n");
    divider();
    printf("\nEnter username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0'; // Remove the newline character

  
    printf("\nEnter password: ");
    fgets(pw, sizeof(pw), stdin);
    pw[strcspn(pw, "\n")] = '\0'; // Remove the newline character
    
if (strcmp(user, adminu) == 0 && strcmp(pw, adminpw) == 0){
    FILE *ptr = fopen("Account.txt","w");
    system("clear");
int ch;
	printf("\t***Welcome***\n");
    printf("\nEnter your name : \n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // remove newline if present
    fprintf(ptr, "\nName : %s\n", name);
    printf("Enter your account no. : ");
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no. : %d\n", acc_no);

    fclose(ptr);
while (1) {
        menu();
        printf("\nEnter your choice :\n");
        scanf("%d", &ch);
       switch (ch) {
            case 1:
                system("clear");
                deposit_money();
                break;
            case 2:
                system("clear");
                withdraw_money();
                break;
            case 3:
                system("clear");
                transfer_money();
                break;
            case 4:
                system("clear");
                checkDetail();
                break;
            case 5:
                transaction_details();
                break;
           case 0:
                system("clear");
                LastDetail();
                exit(0);
           default:
                printf("*****Invalid choice*****");}

}}
else{
printf("\n\t\aInvalid login\n");
printf("\nPress Enter to Exit....\n");
    while (getchar() != '\n'); // Clear input buffer
}


return 0;
}

void menu(){
system("clear");
    divider();
    printf("\n\tHOME\n");
    divider();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account details\n");
    printf("5.Transaction details\n");
    printf("0.Exit\n");
divider();
}

void divider() {
int i;
for(i=0;i<50;i++){
        printf("-");}
}

void deposit_money(){
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****DEPOSITING MONEY*****\n");
    divider();
    printf("\nEnter the amount you want to deposit\n");
    scanf("%d", &dip_amt);
    amt += dip_amt;
    printf("****Money Deposited****\n");
    printf("Now balance : %d\n", amt);
    fprintf(ptr, "\nRs%d had been deposited to your account \n", dip_amt);
    count++;
    fclose(ptr);
    printf("Press Enter to continue....\n");
    while (getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for Enter key
}

void withdraw_money() {
    FILE *ptr=fopen("Account.txt", "a");
    printf("*****WITHDRAWING MONEY*****\n");
    divider();
    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &with_amt);

if(amt<with_amt) {
      printf("****Insufficient balance****\n");
    }
else{
      amt = amt - with_amt;
      printf("*****Money withdrawn*****\n");
      printf("Current balance : %d\n", amt);
      fprintf(ptr, "\nRs%d had been withdrawn from your account \n", with_amt);
           count++;
}
    fclose(ptr);
    printf("Press Enter to continue....\n");
while (getchar() != '\n'); // Clear input buffer
getchar(); // Wait for Enter key
}

void transfer_money(){
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****TRANSFERRING MONEY*****\n");
    divider();
    printf("\nEnter the account no. in which you want to transfer the money : ");
    scanf("%d", &ac);
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amt);

if(amt <trans_amt){
        printf("****You have not sufficient balance****\n");
} 
else{
        amt = amt - trans_amt;
        printf("****Money Transferred****\n");
        printf("Current balance : %d\n", amt);
        fprintf(ptr, "\nRs%d had been transferred from your account to %d\n", trans_amt, ac);
        count++;
    }
    fclose(ptr);
    printf("Press Enter to continue....\n");
while (getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for Enter key
}

void checkDetail() {
    printf("ACCOUNT DETAILS\n");
    divider();
    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amt);
    printf("\n%d transactions have been made from your account \n", count);
    printf("Press Enter to continue....\n");
    while (getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for Enter key
}

void transaction_details() {
    system("clear");
    FILE *ptr;
    ptr = fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF) {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n*******NO RECENT TRANSACTION*******\n");
}
else {
      printf("TRANSACTION DETAILS\n");
      divider();
      printf("\n%d transactions have been made from your account \n", count);
     while (c != EOF) {
          printf("%c", c);
          c = fgetc(ptr);
        }
    }
    printf("Press Enter to continue....\n");
while (getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for Enter key
}

void LastDetail(){
    printf("ACCOUNT DETAILS\n");
    divider();
    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amt);

    printf("\n\nPress Enter to exit.....\n");
while(getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for Enter key
}

