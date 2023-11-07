#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class News
{


public:

	vector <News> news;
	int id;
	string title;
	string category;
	string description;
	string date;
	int rate;
	//News* next;


public:
	 News();
	void viewNews();
	void displayNewsDesc(); 
	static void mainPage();
	~News();

};

