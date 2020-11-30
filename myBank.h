#ifndef Bank
#define Bank
#define L 50
#define K 2

typedef double arr[K][L];

int New_Account(double x);
double Balance (int x);
double Deposit (int x, double y);
double Withrawal (int x, double y);
int Close_Account (int x);
int Interest (double x);
int Print_Accounts ();
int Close_Accounts ();
int action (char c);
int cleaner ();

#endif
