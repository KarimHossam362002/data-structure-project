#include <iostream>
#include <windows.h> //for Sleep(ms)
#include<conio.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include "News.h"
#include<fstream>
#include"User.h"
#include "News.h"
#include <utility>
using namespace std;


News obj4;
User userObj;
vector <News> news2;
unordered_map <string, User> users;

string User::displayAccount(string password)
{
    ifstream infile("User.txt");
    
    while (getline(infile, username)) {
        getline(infile, password);
        users[username] = User(username, password);
       
    }
    infile.close();
    return username;
}

void User::registerUser(string username, string password) {
    // Check if the username already exists.
    if (users.count(username)) {
        cout << "The username already exists." << endl;
        return;
    }

    users[username] = User(username, password);

    cout << "The user has been registered successfully." << endl;
    /*userObj.loginUser(username, password);*/
}

bool User::loginUser(string username, string password) {
    if (!users.count(username)) {
        return false;
    }

    
    User user = users[username];

    
    return user.getPassword() == password;
}
void User::login(string username, string password) {
    int choice=0;
    char accept=0;
    string accept2 = 0;
    string cate;
    if (!users.count(username)) {
        cout << "Invalid username or password" << endl;
    }
    else {
        cout << "\n";
        userObj.loadUsersFromFile();
        cout << "\n";
        userObj.showNewsByCate();
        cout << "Do you want to rate some news y / n?" << endl;
        if (accept =='y'|| accept =='Y')
        {
            cin >> choice;
            userObj.rateNews(choice);
        }
        else if (accept == 'n' || accept == 'N') {
            system("cls");
            userObj.showNewsByCate();

        }
        else {
            cout << "Invalid Response,  Loading...." << endl;
            Sleep(1000);
            system("cls");
            cout << "We would like to make a survey about which category you prefer" << endl;
            cin >> cate;
            userObj.favCategories(cate);
            Sleep(5000);
            system("CLS");
            cout << "I think you missed some Latest News..." << endl;
            userObj.showLatestNews();
            Sleep(3000);
            cout << "Do you want to show all news? y/n" << endl;
            cin >> accept2;
            if (accept2 =="y" || accept2 == "Y")
            {
                obj4.displayNewsDesc();
            }
            else if (accept2 == "n" || accept2 == "N") {
                obj4.mainPage();
            }
            else {
                cout << "Invalid choice" << endl;
            }
            return;
        }
    }
   
}


void User::saveUsersToFile() {
    ofstream outfile("User.txt");

    // iterate in hash tables
    for (auto user : users) {
        outfile << user.first << endl;
        outfile << user.second.getPassword() << endl;
    }

    
    outfile.close();
}

void User::loadUsersFromFile() {
    
    ifstream infile("User.txt");
   
    while (getline(infile, username)) {
        getline(infile, password);
        users[username] = User(username, password);
    }
    infile.close();
}



string User::getUsername()
{
    return string();
}

void User::processes_for_user(string password)
{
    vector <News>news;
    while (true)
    {

        system("cls");
        cout << "1-My Account\n2-My News\n3-Exit\n";
        string choice;

        getline(cin, choice);
        if (choice == "1")
        {
            system("CLS");
            userObj.displayAccount(password);

        }
        else if (choice == "2")
        {
            obj4.displayNewsDesc();
            system("CLS");
        }
        else if (choice == "3")
        {
            return;
        }
        else
        {
            cout << "Enter Valid input !"; Sleep(1500); system("CLS");
        }

    }
}

void User::favCategories(string category)
{
    fstream myFile;
    string favCate;
    cout << "Enter your favourite category to show its details" << endl;
    cin >> favCate;
    for (int i = 0; i < news2.size(); i++)
    {
        
        myFile.open("News.txt", ios::in);
        if (myFile.is_open())
        {
            if (favCate == obj4.category)
            {
                cout << "ID: " << obj4.id << endl;
                cout << "Title: " << obj4.title << endl;
                cout << "Category: " << obj4.category << endl;
                cout << "Description: " << obj4.description << endl;
                cout << "Date: " << obj4.date << endl;
                cout << "Rate: " << obj4.rate << endl;
            }
           
           
        }
    }
    myFile.close();
}

void User::rateNews(int rate)
{
    cout << "Please rate news from 1 to 5" << endl;
    if (rate >= 1 && rate <= 5) {
        obj4.rate = rate;
    }
    else {
        cout << "Invalid rate. Please enter a number from 1 to 5." << endl;
    }
}


void User::showNewsByCate() {
    string cate;
    cout << "Enter your Favourite category" << endl;
    cin >> cate;
    if (cate == obj4.category)
    {
        cout << "ID: " << obj4.id << endl;
        cout << "Title: " << obj4.title << endl;
        cout << "Category: " << obj4.category << endl;
        cout << "Description: " << obj4.description << endl;
        cout << "Date: " << obj4.date << endl;
        cout << "Rate: " << obj4.rate << endl;
    }
}
void User::showLatestNews()
{
    cout << "Enter the number of the latest News you want to recieve" << endl;
    int choice;
    cin >> choice;
    ifstream myfile("News.txt");
    if (myfile.is_open()) {
        
        string line;
        while (getline(myfile,line)) {
            for (int i = choice; i < news2.size(); i--)
            {
                if (i < 0) {
                    cout << "Wrong choice pick something from 1 to" << news2[choice].id << endl;
                }
                else {
                    for (int i = choice; i < news2.size(); i++)
                    {
                        cout << "ID: " << news2[choice].id << endl;
                        cout << "Title: " << news2[choice].title << endl;
                        cout << "Category: " << news2[choice].category << endl;
                        cout << "Description: " << news2[choice].description << endl;
                        cout << "Date: " << news2[choice].date << endl;
                        cout << "Rate: " << news2[choice].rate << endl;
                        break;
                    }
                    
                }
            }
        }

        myfile.close();
    }
    else {
        // File does not exist.
        std::cout << "File does not exist." << std::endl;
    }
   
}
;



