/*
	Ben Richardson 
	C++ Fall 2022
	Due 10/14/22
	Lab 4 Temperature Output
	Lab description : Design and write a C++ program that inputs a series of hourly
	temperature from a file, and outputs a bar chart (using stars) of the temperatures.
	The temperature should be printed to the left of the corresponding bar, and there
	should be a heading that gives the scale of the chart. The range of temperatures should
	be from  -30 to 120. Because it is hard to display 150 characters on the screen,you should
	have each star represent a range of 3 degrees. That way, the bars will be at most 50 characters wide.
	Use meaningful variable names, proper indentation, and appropriate comments. Thoroughly test
	the program using your own data sets. Make sure to vet the values from the input file.
*/

#include <iostream> 
#include <fstream> //FILE I/O
#include <string> // C++ STRING METHOD .append() IS USED TO STORE STARS IN A STRING
#include <iomanip> //FORMATING THE GRAPH

using namespace std; 

void PrintGraph(ifstream& inFile, string starOutput, int& temp);


int main()
{
	string intemp = "inTemperature";
	ifstream inFile; // READ FILE 
	inFile.open(intemp); // OPENS FILE
	if (!inFile) // IF FILE IS NOT READ A MESSAGE WILL POP UP
	{
		cout << "Can't read file."; 
	}
	string starOutput;
	int temp;
	
	// PRINT GRAPH READS IN DATA FROM THE FILE, DETERMINES HOW MANY STARS ARE NEEDED, AND THEN PRINTS THE GRAPH TO THE SCREEN 
	PrintGraph(inFile, starOutput, temp); 

}

void PrintGraph(ifstream& inFile, string starOutput, int& temp)
{
	// GRAPH HEADING
	cout << "\n\nTemperatures for 24 hours: \n";
	cout << endl << setw(6) << "-30" << setw(10) << "0" << setw(11) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;

	inFile >> temp; 	

	while (inFile)
	{  
		temp = round(temp); // ROUND IS USED TO ROUND ANY FLOATING POINT VALUES TO A WHOLE NUMBER

		string starOutput; 
		starOutput = "";

		if (temp < -30 || temp > 120) // IF NUMBER IS TOO LOW OR HIGH AN EROROR WILL BE OUTPUTED 
		{
			cout << temp << " is not in the range.";
		}
		else // TEMPERATURE IN RANGE
		{
			cout << temp << ":";
		}

		// THIS FOR LOOP IS USED TO CALCULATE THE CORRECT NUMBER OF STARS PER DEGREE
		for (int i = 1; i <= round((abs(temp) / 3.0)); ++i) // abs() IS USED TO CALCULATE NEGATIVE VALUES
		{
			starOutput.append("*"); //APPENDS A STAR TO A STRING CALLED STAROUTPUT EVERY TIME THE LOOP ITERATES 
		}

		// THIS IS HOW THE GRAPH PRINTS THE CORRESPONDING AMOUNT OF STARS WITH ITS TEMPERATURE VALUE
		if (temp == -30) {
			cout << " " << starOutput + "|";
		}
		else if (temp > -30 && temp <= -10) {
			cout << setw(12) << starOutput + "|";
		}
		else if (temp >= -10 && temp < 0) {
			cout << setw(13) << starOutput + "|";
		}
		else if (temp >= 0 && temp < 10) {
			cout << setw(14) << "|" << starOutput;
		}
		else if (temp >= 10 && temp < 100) {
			cout << setw(13) << "|" << starOutput;
		}
		else if (temp >= 100 && temp <= 120) {
			cout << setw(12) << "|" << starOutput;
		}

		cout << endl;
		inFile >> temp;
	}
	inFile.close();
}
