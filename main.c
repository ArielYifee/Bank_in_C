#include <stdio.h>
#include "myBank.h"

int main() {
	char c;
	int end = 0;
	double d;
	int n;
	int flag1;
	int flag2;
	while(end != 1){
		printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
		scanf(" %c", &c);
		cleaner();
		d = 0;
		n = 0;
		flag1 = 0;
		flag2 = 0;
		switch(c){
			case 'O':
				printf("Please enter amount for deposit: ");
				flag1 = scanf("%lf", &d);
				cleaner();
				if(flag1 == 1){
					if(d>0){
					New_Account(d);
					break;
					}
					else{
						printf("Invalid Amount\n");
					}
					}
				else{
					printf("Failed to read the amount\n");
				}
				break;
				
			case 'B':
				printf("Please enter account number: ");
				flag1 = scanf("%d", &n);
				cleaner();
				if(flag1 == 1){
					Balance(n);
					break;
				}
				else{
					printf("Failed to read the account number\n");
				}
				break;
			case 'D':
				printf("Please enter account number: ");
				flag1 = scanf("%d", &n);
				cleaner();
				if (flag1 == 1){
					printf("what is your deposit?:");
					flag2 = scanf("%lf", &d);
					cleaner();
					if(flag2 == 0){
						if(d>0){
							Deposit(n,d);
							break;
							}
						else{ 
							printf("Cannot deposit a negative amount\n");
						}
						}
					else {
						printf("Failed to read the amount\n");
						}
						}
				else{
					printf("Failed to read the account number\n");
				}
				break;
			case 'W':
				printf("Please enter account number: ");
				flag1 = scanf("%d", &n);
				cleaner();
				if(flag1 == 1){
					printf("Please enter the amount to withdraw: ");
					flag2 = scanf("%lf", &d);
					cleaner();
					if(flag2 ==1 ){
						Withrawal(n,d);
						break;
					}
				}
				else{
					printf("Failed to read the account number\n");
				}
				break;
			case 'C':
				printf("Please enter account number: ");
				flag1 = scanf("%d", &n);
				cleaner();
				if(flag1 == 1){
					Close_Account(n);
					break;
				}
				else{
					printf("Failed to read the account number\n");
				}
				break;
			case 'I':
				printf("Please enter interest rate: ");
				flag1 = scanf("%lf", &d);
				cleaner();
				if(flag1 == 1){
					if(d<0){
						printf("Invalid interest rate\n");
					}
					else{
						Interest(d);
					break;
					}
				}
				else{
					printf("Failed to read the interest rate\n");
				}
				break;
			case 'P':
				Print_Accounts();
				break;
			case 'E':
				Close_Accounts();
				end = 1;
				break;
			default:
				printf("Invalid transaction type\n");
		}
	}
	return 0;
}
