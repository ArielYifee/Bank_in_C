#include <stdio.h>
#include "myBank.h"

int main() {
	char c;
	int end = 0;
	double d;
	int n;
	int flag1;
	int flag2;
	printf("please choose your action \n to open new account press O \n to get your balance press B \n to deposit press D \n to withrawal press W \n to close your account press C \n interest press I \n print all accounts press P \n to close all accounts press E \n");
	while(end != 1){
		printf("what is your choose?\n");
		scanf(" %c", &c);
		cleaner();
		d = 0;
		n = 0;
		flag1 = 0;
		flag2 = 0;
		switch(c){
			case 'O':
				printf("please enter first deposit amount:");
				flag1 = scanf("%lf", &d);
				cleaner();
				if(flag1 == 1){
					if(d>0){
						New_Account(d);
						break;
					}
					else{
						printf("amount must be positive. \n");
					}
				}
				else{
					printf("invaild amount. \n");
				}
				break;
			case 'B':
				printf("please enter your account number:");
				flag1 = scanf("%d", &n);
				cleaner();
				if(flag1 == 1){
					Balance(n);
					break;
				}
				else{
					printf("invaild account number.\n");
				}
			case 'D':
				printf("please enter your account number:");
				flag1 = scanf("%d", &n);
				cleaner();
				if (flag1 == 1){
					printf("what is your deposit?:");
					flag2 = scanf("%lf", &d);
					cleaner();
					if(flag2 == 0){
						Deposit(n,d);
						break;
					}
					else{
						printf("invaild deposit.\n");
					}
				}
				else{
					printf("invaild account number.\n");
				}
				break;
			case 'W':
				printf("please enter your account number:");
				flag1 = scanf("%d", &n);
				cleaner();
				if(flag1 == 1){
					printf("how much you want to withrawal?:");
					flag2 = scanf("%lf", &d);
					cleaner();
					if(flag2 ==1 ){
						Withrawal(n,d);
						break;
					}
				}
				else{
					printf("invaild account number.\n");
				}
				break;
			case 'C':
				printf("please enter the account number:");
				flag1 = scanf("%d", &n);
				cleaner();
				if(flag1 == 1){
					Close_Account(n);
					break;
				}
				else{
					printf("invaild account number.\n");
				}
				break;
			case 'I':
				printf("what is the interest?:");
				flag1 = scanf("%lf", &d);
				if(flag1 == 1){
					Interest(d);
					cleaner();
					break;
				}
				else{
					printf("invaild interest.\n");
				}
				break;
			case 'P':
				Print_Accounts();
				break;
			case 'E':
				Close_Accounts();
				printf("\n bye bye \n");
				end = 1;
				break;
	
			default:
				printf("incorrect char!\n");
		}
	}
	return 0;
}
