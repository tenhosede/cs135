/*
Bruce Powell, Lecture Section 1003, Lab Section 1009, Exercise #10

User enters an input file name and an output file name. 

Program gets input words from the input file and prints them to the output file 

with lower case consonants and capital vowels.
*/

#include<fstream>
#include<string>
#include<iomanip>
#include<iostream>

using namespace std;



const int columnwidth = 12;

void getFileNames(string&, string&);
void printWords(string, string);
string ex10Format(string);


int main()
{
  string inputfile;
  string outputfile;


  cout << endl << endl;
  getFileNames(inputfile,outputfile);
  printWords(inputfile, outputfile);

}

void getFileNames(string& infile, string& outfile)
{
  cout << "Please enter the input file name: ";
  cin >> infile;
  cout << endl << endl << "Please enter the output file name: ";
  cin >> outfile;
  cout << endl << endl;
}

void printWords(string inputfilename, string outputfilename)
{
  ifstream inf;
  ofstream outf;
  string inword;

  inf.open(inputfilename.c_str());
  outf.open(outputfilename.c_str());


  outf << "====================================================================" << endl;
  outf << "Bruce Powell, Lecture Section 1003, Lab Section 1009, Exercise #10" << endl;
  outf << "====================================================================" << endl << endl;
  outf << "Input file name: " << inputfilename << endl << endl;

  if (!inf)
    {
      cout << inputfilename << " was not succesfully opened." << endl;
    }
  else
    {
      outf << "Reformatted words in file:" << endl;
      int count = 1;
      inf >> inword;

      while (inf)
	{
	  outf << setw(columnwidth) << ex10Format(inword);
	  count ++;
	  if (count == 6)
	    {
	      outf << endl;
	      count = 1;
	    }
	  inf >> inword;
	}
    }
  inf.close();
  outf.close();


}

string ex10Format(string inputword)
{
  string outputword = "";
  for (int i = 0; i < inputword.length(); i++)
    {
      if (inputword[i] == 'a' || inputword[i] == 'A' || inputword[i] == 'e' || inputword[i] == 'E' || inputword[i] == 'i' || inputword[i] == 'I' || inputword[i] == 'o' || inputword[i] == 'O' || inputword[i] == 'u' || inputword[i] == 'U') 
	outputword = outputword += toupper(static_cast<char>(inputword[i]));
      else
	outputword = outputword += tolower(static_cast<char>(inputword[i]));
    }
  return outputword;
}
