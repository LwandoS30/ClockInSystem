#include <iostream>
#include <fstream> // for creating and saving to file
#include <sstream> // for
#include <string>
#include <ctime> // for time manipulation
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    //Variable declaration
    string fname = " ";
    string lname = " ";
    string cellNum = " ";
    string serviceP = " ";
    string roomNum = " ";
    string line = " ";

    int minutes = 0;
    int hours = 0;
    int day = 0;
    int month = 0;
    int year = 0;

    int columnWidth = 15;
    string header1 = "Name";
    string header2 = "Surname";
    string header3 = "Cell Number";
    string header4 = "ServiceP";
    string header5 = "Room";
    string header6 = "Time";
    string header7 = "Date";

    //Get the cuurent time
    std::time_t now = std::time(0);

    //Convert to tm struct for local time
    std::tm *tm_ptr = std::localtime(&now);

    //Time manipulation
     minutes = tm_ptr->tm_min;
     hours = tm_ptr->tm_hour;
     day = tm_ptr->tm_mday;
     month = tm_ptr->tm_mon + 1;
     year = tm_ptr->tm_year + 1900;

    ofstream writeFile("student.txt",ios::app);
    ifstream readFile("student.txt");
    string field = "";

    writeFile.clear(); //Clears everything that has been written to the file
    writeFile.seekp(0,ios::beg); //Moves to the beginning of the file

    //Display the headings of the output that will be stored in a text file

    while(true)
        {
            cout << "Please enter first name (or type 'Exit' to stop): ";
            cin >> fname;
             if(fname == "exit"||fname == "Exit"||fname == "EXIT")//to breat from if EXIT, Exit or exit is entered by the user
            {
                break;
            }
            cout << "Please enter last name (or type 'Exit' to stop): ";
            cin >> lname;
             if(lname == "exit"||lname == "Exit"||lname == "EXIT")//to breat from if EXIT, Exit or exit is entered by the user
            {
                break;
            }
            cout << "Please enter your cell number (or type 'Exit' to stop): ";
            cin >> cellNum;
             if(cellNum == "exit"||cellNum == "Exit"||cellNum == "EXIT")//to breat from if EXIT, Exit or exit is entered by the user
            {
                break;
            }
            cout << "Please enter the name of your service provider (or type 'Exit' to stop): ";
            cin >> serviceP;
             if(serviceP == "exit"||serviceP == "Exit"||serviceP == "EXIT")//to breat from if EXIT, Exit or exit is entered by the user
            {
                break;
            }
            cout << "Please enter room number/ class number (or type 'Exit' to stop): ";
            cin >> roomNum;
             if(roomNum == "exit"||roomNum == "Exit"||roomNum == "EXIT")//to breat from if EXIT, Exit or exit is entered by the user
            {
                break;
            }
            writeFile<<line<<fname<<","<<lname<<","<<cellNum<<","<<serviceP<<","<<roomNum<<","
                     <<hours<<":"<<minutes<<","<<day<<"/"<<month<<"/"<<year<<endl; //Entered values ba a user are saved to the file "student.txt"
            cout<<"\n";
        }

        writeFile.close();//Closing the file after entering the required data from Students/ Candidates

        //Moving to the beginning of the file
        readFile.seekg(0,ios::beg);

        //providing an error message if the file fails to open
        if(!readFile){
            cout<<"Error opening file!"<<endl;
        }

            cout<<setw(2)<<header1
                 << std::setw(columnWidth) << header2
                 << std::setw(columnWidth) << header3
                 << std::setw(columnWidth) << header4
                 << std::setw(columnWidth) << header5
                 << std::setw(columnWidth) << header6
                 << std::setw(columnWidth) << header7
                 <<endl;
        //Read file by each line
        while(getline(readFile,line)){
            stringstream ssparse(line); // passing the line by using stringstream

            //after parsing the line, manipulate the it to display in a tabulor form, removing
            // delimeters before displaying it
            while(getline(ssparse, field,',')){ // use stew to give the table format for the data

               //cout
                cout<<field<<setw(15); //the width between columns will be 15
            }

            cout <<endl; //move to the following line
        }


        readFile.close();// close file

    return 0;
}


