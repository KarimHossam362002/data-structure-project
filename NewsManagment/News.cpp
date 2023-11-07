#include <iostream>
#include <fstream>
#include "News.h"
#include <vector>
#include <string>
#include "Admin.h"
#include "User.h"
using namespace std;

Admin obj1;
User obj2;
News::News()
{
}
void News::viewNews()
{
    ifstream myFile("News.txt");
    string line;
    while (getline(myFile, line)) {
        cout << line << endl;
    }
    myFile.close();
}
// Displaying Descendling for user
void News::displayNewsDesc() {
    // Filter news with rate greater than 2
    vector<News> filteredNews;
    for (News& n : news) {
        if (n.rate > 2) {
            filteredNews.push_back(n);
        }
    }

    // Sort news in descending order of rate
    for (int i = 0; i < filteredNews.size() - 1; i++) {
        for (int j = i + 1; j < filteredNews.size(); j++) {
            if (filteredNews[j].rate > filteredNews[i].rate) {
                News temp = filteredNews[i];
                filteredNews[i] = filteredNews[j];
                filteredNews[j] = temp;
            }
        }
    }

    // Display the filtered and sorted news
    for (News& n : filteredNews) {
        cout << "Title: " << n.title << endl;
        cout << "Category: " << n.category << endl;
        cout << "Description: " << n.description << endl;
        cout << "Date: " << n.date << endl;
        cout << "Rate: " << n.rate << endl << endl;
    }
}
void News::mainPage() {

    string userName, pass;
    int choice;
    cout << "Welcome to News Managment System" << endl;
    cout << "Pick a choice to proceed...!" << endl;
    cout << "1-Login as Admin" << endl;
    cout << "2-Register" << endl;
    cout << "3-Login" << endl;
    cout << "4-Exit" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        obj1.Login_Admin();
    case 2:
        cout << "Please enter your username :" << endl;

        cin >> userName;
        cout << "Please enter your password :" << endl;

        cin >> pass;
        obj2.registerUser(userName, pass);
    case 3:
        obj2.login(userName, pass);
    case 4:
        break;
    }
}
News::~News()
{
}
//void News::favCategories()
//{
//}

//void News::rateNews()
//{
//}
