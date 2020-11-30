#include <stdio.h>
#include <math.h>
#include "myBank.h"

int counter = 0;
arr Accounts;

int New_Account(double x){
	int a = -1;
	if(counter < 50){
		for(int j = 0; j < 50 ; j++){
			if(Accounts[0][j] == 0){
				Accounts[0][j] = j+901;
				Accounts[1][j] = x;
				a = j+901;
				counter ++;
				break;
			}
		}
	}
	if(a == -1){
	printf("there is no space for another account \n");
	return 0;
	}
	else{
	printf("the new account is %d \n",a);
	return 0;
	}
return 0;
}

double Balance (int x){
	if(Accounts[0][x-901] != (x)){
		printf("the account doesnt exist \n");
		return 0;
	}
	double b = Accounts[1][x-901];
	printf("the current balance is %0.2lf \n",b);
	return 0;
}

double Deposit (int x, double y){
	if(Accounts[0][x-901] != x){
		printf("the account doesnt exist \n");
		return 0;
	}
	Accounts[1][x-901] += y;
	double b = Accounts[1][x-901];
	printf("the new balance is %0.2lf \n",b);
	return 0;
}

double Withrawal (int x, double y){
	if(Accounts[0][x-901] != x){
		printf("the account doesnt exist \n");
		return 0;
	}
	int c = Accounts[1][x-901] - y;
	if(c >0){
		Accounts[1][x-901] -= y;
		double b = Accounts[1][x-901];
		printf("the new balance is %0.2lf \n",b);
		return 0;
	}
	printf("you dont have enough money in your account \n");
	return 0;
}

int Close_Account (int x){
	if(Accounts[0][x-901] != x){
		printf("the account doesnt exist \n");
		return 0;
	}
	Accounts[0][x-901] = 0;
	Accounts[1][x-901] = 0;
	counter --;
	printf("this account is closed \n");
	return 0;
}

int Interest (double x){
	if(x == 0){
		return 0;
	}
	for(int j = 0; j < 50 ; j++){
		Accounts[1][j] *= (1+ (x/100));
	}
	return 0;
}
int Print_Accounts (){
	for(int j = 0; j < 50 ;j++){
		if(Accounts[0][j] == (j+901)){
			printf(" account number: %d \n balance: %0.2lf \n \n", j+901, Accounts[1][j]);
		}
	}
	return 0;
}
int Close_Accounts (){
	for(int i = 0; i < 2 ; i++){
		for(int j = 0; j < 50 ; j++){
		Accounts[i][j] = 0;
		}
	}
	counter = 0;
	printf("all the accounts are empty \n");
	return 0;
}
int cleaner(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
	return 0;
}
