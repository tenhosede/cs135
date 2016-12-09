/*
Bruce Powell Lec 1003, Lab 1009, Assignment 6

program keeps track of employees and changes

outputs employee information to terminal

*/


#include<string>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<iostream>
using namespace std;

struct employeeRecord 
{
  string firstName;
  string lastName;
  int idNum;
  char jobSts;
  double payHourly;
  double hoursWorked;
};

string properCase(string wordToFormat);
void getRecord(employeeRecord records[],int& numEmployees);
void getChanges(employeeRecord records[],int numEmployees);
void calcPay(employeeRecord records[],int numEmployees);
void changeRecord(employeeRecord toChange,int numEmployees,char changeCode);
void printRecords(employeeRecord records[],int numEmployees);
void printTimeReport(employeeRecord records[],int numEmployees);
void sortRecords(employeeRecord records[],int numEmployees);
string properCase(string input);
int findRecord(employeeRecord records[],int numEmployees,int idNumber);

//form values
const int nameWidth = 30;
const int idWidth = 5;
const int statusWidth = 7;
const int rateWidth = 8;



int main()
{
  employeeRecord employees[25]; // list of records
  int employeeCount = 0; // number of people employed
  
  getRecord(employees, employeeCount);

  getChanges(employees, employeeCount);
  
  calcPay(employees, employeeCount);
}


void getRecord(employeeRecord records[], int& numEmployees)
{
  //gets records from records file (user inputs filename)
  //sorts records based on last name and prints them in a form with record information

  ifstream inf;
  string inputfile;


  cout << "Enter the name of the employee records file:" << endl;
  cin >> inputfile;
  cout << endl;

  inf.open(inputfile.c_str());
  
  inf >> records[numEmployees].firstName;
  while (inf)
    {
      records[numEmployees].firstName = properCase(records[numEmployees].firstName);
      inf >> records[numEmployees].lastName;
      records[numEmployees].lastName = properCase(records[numEmployees].lastName);
      inf >> records[numEmployees].idNum;
      inf >> records[numEmployees].jobSts;
      inf >> records[numEmployees].payHourly;
      numEmployees++;
      if (numEmployees == 25)
	break;
      if (numEmployees < 25)
       inf >> records[numEmployees].firstName;
    }

  inf.close();

  sortRecords(records, numEmployees);

  printRecords(records, numEmployees);
}

void sortRecords(employeeRecord records[],int numEmployees)
//sorts using a bubblesort algorithm
{
  employeeRecord temp;
  bool sortdone = false;
  bool sorted = false;

  while (!sortdone)
    {
      for(int i = 0; i < (numEmployees - 1); i++)
	{
	  if (records[i].lastName > records[i+1].lastName)
	    {	  
	      temp = records[i];
	      records[i] = records[i+1];
	      records[i+1] = temp;
	      sorted = true;
	    }
	}
      if (sorted)
	sortdone = false;
      else 
	sortdone = true;
      
      sorted = false;
    }

}

void printRecords(employeeRecord records[],int numEmployees)
{
  //prints records in a set form
  cout << left << setw(nameWidth) << "Name" << right << setw(idWidth) << "ID#" << setw(statusWidth) << "Status";
  cout << setw(rateWidth) << "Rate" << endl << fixed << setprecision(2);

  for (int i = 0; i < numEmployees; i++)
    {
      cout << left << setw(nameWidth) << records[i].lastName + ", " + records[i].firstName;
      cout << right << setw(idWidth) << records[i].idNum;
      cout << "   " << records[i].jobSts << "     $";
      cout << setw(rateWidth) << records[i].payHourly << endl;
    }
  cout << endl;

}

string properCase(string input)
{
  //formats a string to proper case
  string wordtoformat = input;

  for (int i = 0; i < input.length();i++)
    {
      if (i == 0)
	wordtoformat[i] = toupper(static_cast<char>(input[i]));
      else
	wordtoformat[i] = tolower(static_cast<char>(input[i]));
    }
  return wordtoformat;
} 

int findRecord(employeeRecord records[], int numEmployees,int idNumber)
{
  //Returns the index number of the record with the indicated idNumber, otherwise 
  //returns -1 if no record matches.
  for (int i = 0; i < numEmployees; i++)
    if (records[i].idNum == idNumber)
      return i;
  return -1;
}

void getChanges(employeeRecord records[], int numEmployees)
{
  //prompts for a filename. Opens file and checks for sentinal values of 'S' or 'P' to change
  //either status or hourly pay in the record file. Executes changes to records
  //and prints to cout to list the cahnges and show the record files 
  ifstream inf;
  string filename;
  int idToChange = 0;
  int recordIndex = 0;
  char changeType;
  char stsChange;
  double payChange = 0.0;

  cout << "Enter the name of the record change file: " << endl;
  cin >> filename;
  cout << endl << "Changes:" << endl;

  inf.open(filename.c_str());

  inf >> idToChange;

  while (inf)
    {
      recordIndex = findRecord(records, numEmployees, idToChange);
      
      if (recordIndex == -1)
	{
	  cout << "ID# " << idToChange << " is invalid" << endl;
	  inf.ignore(80,'\n');
	}
      else
	{
	  inf >> changeType;
	  if (changeType == 'S')
	    {
	      inf >> stsChange;
	      records[recordIndex].jobSts = stsChange;
	      cout << "ID# " << records[recordIndex].idNum << " status changed to " << stsChange << endl;
	    }
	  else if (changeType == 'P')
	    {
	      inf >> payChange;
	      records[recordIndex].payHourly = payChange;
	      cout << "ID# " << records[recordIndex].idNum << " hourly pay rate changed to " << payChange << endl;
	    }
	  else
	    {
	      cout << "Command for ID# " << idToChange << " is invalid" << endl;
	      inf.ignore(80,'\n');
	    }
	}
      inf >> idToChange;
    }
      inf.close();
      cout << endl;
      printRecords(records, numEmployees);

}

void calcPay(employeeRecord records[],int numEmployees)
{
  //opens a file with ID numbers and hours worked, calculates pay owed to employees based on 40 hour work week (1.5x pay for hours over 40)
  ifstream inf;
  string hoursfile;
  int idNum = 0;
  double hoursWorked = 0.0;
  int recordIndex = 0;  
  double payDue = 0.0;
  double totalHoursWorked = 0.0;
  double totalPayDue = 0.0;

  cout << "Enter the name of the time file: " << endl;
  cin >> hoursfile;
  cout << endl;

  inf.open(hoursfile.c_str());

  inf >> idNum;

  while (inf)
    {
      recordIndex = findRecord(records,numEmployees,idNum);
      if (recordIndex == -1)
	inf.ignore(80,'\n');
      else
	{
	  inf >> hoursWorked;
	  records[recordIndex].hoursWorked = records[recordIndex].hoursWorked + hoursWorked;
	}    
      inf >> idNum;
    }
  inf.close();

  cout << left << setw(nameWidth) << "NAME" << setw(12) << "PAY RATE" << setw(9) << "HOURS" << setw(12) << "  TOTAL" << endl;

  for (int i = 0; i < numEmployees;i++)
    {
      cout << setw(nameWidth) << left << records[i].lastName + ", " + records[i].firstName;
      cout << right << "$" << setw(6) << records[i].payHourly << setw(11) << records[i].hoursWorked << "  $" <<  setw(10);
	if (records[i].hoursWorked > 40)
	    payDue = 40 * records[i].payHourly + (records[i].hoursWorked - 40) * (records[i].payHourly * 1.5);
	else
	  payDue = (records[i].hoursWorked * records[i].payHourly);
      cout << payDue << endl;
      totalHoursWorked = totalHoursWorked + records[i].hoursWorked;
      totalPayDue = totalPayDue + payDue;
    }
  cout << left << setw(nameWidth + 9) << "TOTAL" << right << setw(9) << totalHoursWorked << "  $" << right;
  cout << setw(10) << totalPayDue << endl;
}
