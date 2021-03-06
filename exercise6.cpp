/*Bruce Powell @ UNLV Lec Sec# 1003, Lab Sec# 1009
Exercise 6: Bank Accounts
Accepts an account number, type, and number of checks
if applicable. Then calculates and outputs any interest earned
or fees incurred.
*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double interestChecking = .015;
const double interestSavings = .03;
const double minBalance = 5000.0;
const double serviceFee = 10.0;
const double checkFee = .25;
const int labelWidth = 30;
const int valueWidth = 10;

int main()
{

  char accountType = ' ';
  int accountNumber = 0;
  double finalBalance = 0.0;
  double monthEndBalance = 0.0;
  double numberChecks = 0.0;
  double checkFeeTotal = 0.0;
  double interestPercentEarned = 0.0;
  double interestValueEarned = 0.0;

  cout << endl << "Bruce Powell   Lec Sec# 1003, Lab Sec# 1009, Exercise #6" << endl;
  cout << "Enter your account number:";
  cin >> accountNumber;
  cout << endl << "Enter month end balance:";
  cin >> monthEndBalance;
  cout << endl << "Enter account type, S = savings C = checking:";
  cin >> accountType;
  cout << endl;

  if (accountType == 'S') 
    {
      finalBalance = monthEndBalance + (monthEndBalance * interestSavings);
      interestPercentEarned = interestSavings * 100.0;
      interestValueEarned = (monthEndBalance * interestSavings);
    }
  else if (accountType == 'C')
    {
      if (monthEndBalance >= minBalance)
	{
	  finalBalance = monthEndBalance + (monthEndBalance * interestChecking);
	  interestPercentEarned = interestChecking * 100.0;
	  interestValueEarned = (monthEndBalance * interestChecking);
	}
      else
	{
	  cout << "Enter number of checks written:";
	  cin >> numberChecks;
	  cout << endl;
	  checkFeeTotal = numberChecks * checkFee;
	  finalBalance = monthEndBalance - checkFeeTotal - serviceFee;
	}
    }
  else
    {
      cout << "That is not a valid account type" << endl;
      return 0;
    }
  cout << fixed << setprecision(2);
  cout << setw(labelWidth) << left << "Account #:" << right << setw(valueWidth) << accountNumber << endl;
  cout << left << setw(labelWidth) << "Account Type:" << right << setw(valueWidth);
  if (accountType == 'S')
      {
	cout << "Savings" << endl;
      }
  else if (accountType == 'C')
      {
	cout << "Checking" << endl;
      }
	  
  cout << left << setw(labelWidth) << "Interest rate:" << right << setw(valueWidth -1);
  cout << interestPercentEarned << "%" << endl;
  cout << left << setw(labelWidth) << "Month end balance:" << right << "$" << setw(valueWidth -1);
  cout << monthEndBalance << endl;
  if (interestValueEarned > 0.0)
    {
      cout << left << setw(labelWidth) << "Interest earned:"  << right << "$" << setw(valueWidth -1);
      cout << interestValueEarned << endl;
    }
  else
    {
      cout << left << setw(labelWidth) << "Service fee:" << right << "$" << setw(valueWidth -1);
      cout << serviceFee << endl;
      cout << left << setw(labelWidth) << "Check fee:" << right << "$" << setw(valueWidth -1);
      cout << checkFeeTotal << endl;
    }
  cout << left << setw(labelWidth) << "Final balance:" << right << "$" << setw(valueWidth -1);
  if (finalBalance <= 99999.99)
    cout << finalBalance << endl;
  else
    cout << 99999.99 << endl;
}
