#include <iostream>
#include <windows.h> //for Sleep(ms)
#include <conio.h>
#include <string>
#include <fstream>
#include "News.h"
#include "Admin.h"
#include <vector>

using namespace std;

Admin adminObj;
vector <News>news3;
News obj3;
//Node::Node(string username, string password)
//{
//    next = 0;
//    this->username = username;
//    this->password = password;
//}

void Admin::processes_for_Admin()
{
    while (true)
    {
        system("cls"); //clear console
        cout << "1- Add Category\n2- Add News\n3- Remove News\n4- Update News\n5-Display average rate by Title \n6- Go Back\n";
        string choice;

        getline(cin, choice);
        system("cls");
        if (choice == "1")
        {
            system("CLS");
            adminObj.Add_Category();
        }
        else if (choice == "2")
        {
            adminObj.Add_News();
        }
        else if (choice == "3")
        {
            adminObj.Remove_News();
        }
        else if (choice == "4")
        {
            adminObj.Update_News();
        }
        else if (choice == "5")
        {
            adminObj.AvgRateTitle();
        }
        else if (choice == "6")
        {
            obj3.mainPage();
        }
        else
        {
            cout << "Enter Valid input!";
            Sleep(1500);
            system("CLS");
        }
    }
}

// admin login
void Admin::Login_Admin()
{
    system("CLS");
    bool check;
    while (true)
    {
        check = Admin_Name();
        if (check)
        {
            check = password();
            if (check)
            {
                system("CLS");
                cout << "Login Success :)";
                Sleep(1500);
                system("CLS");
                processes_for_Admin();
                return;
            }
            else
            {
                cout << "Wrong Password :(";
                Sleep(2000);
                system("CLS");
            }
        }
        else
        {
            cout << "Wrong Username :(";
            Sleep(2000);
            system("CLS");
        }
        while (true)
        {
            cout << "Do you want to return? (y/n)\n";
            string ch;
            getline(cin, ch);
            if (ch == "y" || ch == "Y")
                return;
            else if (ch == "N" || ch == "n")
                adminObj.Login_Admin();
            else
            {
                cout << "Enter Valid Input!";
                Sleep(2000);
                system("CLS");
            }
        }
    }
}

void Admin::Add_News() // finished
{
    fstream myFile;
    myFile.open("News.txt", ios::out);
    if (myFile.is_open())
    {
        myFile << "ID: " << obj3.id << "\n"
            << "Title: " << obj3.title << "\n"
            << "Category: " << obj3.category << "\n"
            << "Description: " << obj3.description << "\n"
            << "Date: " << obj3.date << "\n"
            << "Rate(1-5): " << obj3.rate << endl;
        myFile.close();
    }
}

void Admin::Remove_News() // finsished
{
    system("cls");
    // Open the original file in read mode.
    ifstream myFile("News.txt");

    // Create a new file in write mode.
    ofstream outputFile("NewsRemoved.txt");

    // Read each line from the original file.
    string line;
    int index;
    cout << "Choose the id you ant to remove :" << endl;
    cin >> index;
    while (getline(myFile, line)) {
        for (int i = 0; i < news3.size();i++)
        {
            if (index == obj3.id)
            {
                outputFile << line << endl;
            }
        }
        /*if (line.find(newsObj.id) == string::npos) {
            outputFile << line << endl;
        }*/
    }

    // Close both files.
    myFile.close();
    outputFile.close();
}

void Admin::Add_Category() //finished
{
    fstream myFile;
    myFile.open("News.txt", ios::out);
    if (myFile.is_open())
    {
        myFile << "Category: " << obj3.category << "\n";
        myFile.close();
    }
}

void Admin::AvgRateTitle()
{
    ifstream myfile("News.txt");
    if (myfile.is_open()) {
        int count = 0;
        int totalRate = 0;
        string line;
        while (getline(myfile, line)) {
            cout << "Enter the title to display average rate: ";
            string title;
            cin.ignore();
            getline(cin, title);
            for (const auto& n :news3 ) { //iteration to store News class in n and compare
                if (n.title == title) {
                    count++;
                    totalRate += n.rate;
                }
            }
            if (count > 0) {
                double averageRate = static_cast<double>(totalRate) / count; //casting
                cout << "Average rate for " << title << "= " << averageRate << endl;
            }
            else {
                cout << "Wrong Title...!!!" << endl;
            }
        }
        myfile.close();
    }
}

void Admin::Update_News()
{
   
    fstream myFile("News.txt", ios::in | ios::out);
    string line;
    int index;
    cout << "Enter the id of News you want to update: ";
    cin >> index;
    if (index == obj3.id)
    {
        int nid;
        string ntitle;
        string ncategory;
        string ndescription;
        string ndate;
        int nrate;
        vector<string> lineData;
        cout << "Enter the news details you want to update" << endl;
        cout << "ID: ";
        cin >> nid;
        cout << "Title: ";
        cin >> ntitle;
        cout << "Category: ";
        cin >> ncategory;
        cout << "Description: ";
        cin >> ndescription;
        cout << "Date: ";
        cin >> ndate;
        cout << "Rate: ";
        cin >> nrate;
        lineData.push_back(to_string(nid));
        lineData.push_back(ntitle);
        lineData.push_back(ncategory);
        lineData.push_back(ndescription);
        lineData.push_back(ndate);
        lineData.push_back(to_string(nrate));

        fstream myFile("News.txt");
        vector<string> lines; //Reading lines of the file exist to compare
        while (getline(myFile, line)) {
            lines.push_back(line);
        }
        myFile.close();

        int index = -1; // searching for the line I want to update
        for (int i = 0; i < lines.size(); i++) {
            if (lines[i] == lineData[0] + " " + lineData[1] + " " + lineData[2] + " " + lineData[3] + " " + lineData[4] + " " + lineData[5]) {
                index = i;
                break;
            }
        }
        // Update the line if found.
        if (index != -1) {
            lines[index] = lineData[0] + " " + lineData[1] + " " + lineData[2] + " " + lineData[3] + " " + lineData[4] + " " + lineData[5];
        }
        myFile.open("News.txt", ios::out);
        for (int i = 0; i < lines.size(); i++)
        {
            myFile << lines[i] << endl;
        }
        myFile.close();
    }
}

bool Admin::Admin_Name()
{
    system("CLS");
    string username = "admin"; // Initializing username
    string check_user = "";
    int trials = 0;
    cout << "Enter a username (you have only 3 tries): ";
    while (trials < 3) // Loop until the user enters the correct username or exceeds the maximum number of trials
    {
        getline(cin, check_user); // Read input with spaces
        if (check_user == username)
            return true;
        trials++;
        cout << "Wrong username!\n";
        Sleep(1000);
        system("CLS");

        if (trials == 1)
        {
            system("CLS");
            cout << "Wait 1 second";
            Sleep(1000);
            system("CLS");
            cout << "Enter a username (you have only 2 tries left): ";
        }
        else if (trials == 2)
        {
            system("CLS");
            cout << "Wait 2 seconds";
            Sleep(1000);
            system("CLS");
            cout << "Wait 1 second";
            Sleep(1000);
            system("CLS");
            cout << "Enter a username (Be careful! It is the last try): ";
        }
    }
    return false;
}
bool Admin::password() {

    string password = "admin123"; // Initializing username
    string check_password = "";

    cout << "Enter your password " << endl;
    cin >> check_password;
    while (check_password != password) {
        cout << "Try again..!!" << endl;
    }
    return true;

};


