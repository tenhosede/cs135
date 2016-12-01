/*
Bruce Powell, Lecture Section 1003, Lab Section 1009, Assignment 5

Accepts and input file that contains a string, number of readings, and temperature readings

calculates Max, Average, median, and std deviation for both high and low temperatures.

Prints data per month
*/

#include<string>
#include<iomanip>
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;


const dayspermonth = 31;
struct tempData
{
  string monthName;
  int numReadings;
  int hiTempValues[dayspermonth];
  int loTempValues[dayspermonth];
};

void getValues(tempData inputValues);
int maximum(int values[], int numvalues);
int minumum(int values[], int numvalues);
double average(int values[], int numvalues);
double median(int vaues[], int numvalues);
double stdDeviation(int values[], int numvalues);
void printValues(tempData inputValues);
string properCase(string input);



int main()
{
  tempData tempvalues;


  getValues(tempvalues);

  return 0;
}

void getValues(tempData inputValues)
{
  //gets data from file, calculates average, median, deviation of high and low, as well as max and min
  // displays values in a printed form
}

int maximum(int values[], int numvalues)
{
  //find the maximum integer value in an array, returns it
}

int minimum(int values[], int numvalues)
{
  // finds the minimum integer value in an array, returns it
}

double average(int values[], int numvalues)
{
  //calculates the average of values in an array, returns a double
}

double median(int values[], int numvalues)
{
  //calcuates the median of an values in an array, returns a double
}

double stdDeviation(int values[], int numvalues)
{
  //calculates the standard deviation of a set of integer values in an array, returns a double
}

void printValues(tempData inputValues)
{
  //prints values in a structured format
}

string properCase(string input)
{
  //formats a string to proper case
}
