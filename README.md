# News Management System

## Overview

The News Management System is a C++ program designed to manage and display news articles, allowing users to register, login, view, rate, and filter news based on categories. Admin users have additional functionalities like posting, removing, updating news, adding new categories, and viewing average ratings for specific news titles.

### Features

1. **User Authentication:**
   - Validate user login credentials.
   - Differentiate between admin and regular users based on login.

2. **Admin Functionalities:**
   - **Login:** Authenticate admin credentials.
   - **Post/Remove News:** Add or delete news articles.
   - **Update Existing News:** Modify existing news details.
   - **Add New Category:** Introduce new categories like Sport or Health and assign news articles to them.
   - **Display Average Rate:** Calculate and display the average rating for a specific news title.

3. **User Functionalities:**
   - **Register/Login:** Register with a username and password, then log in securely.
   - **Display Latest News:** View the most recent news articles.
   - **Filter by Category:** Show news articles based on user-selected categories.
   - **Rate News:** Provide ratings (1 to 5 stars) for news articles.

4. **News Display and Rating:**
   - **Hide Low-Rated News:** Articles with ratings below 2 are hidden from users.
   - **Descending Order by Rating:** Display news articles in descending order based on their ratings.

## Implementation Details

### Data Structure

The program utilizes appropriate data structures such as arrays, linked lists, or dynamic arrays to manage news articles efficiently. Each news article is represented by:
- Title
- Description
- Date
- Rating (1 to 5)
- Category

### Usage

1. **Compilation:**
   Compile the program using a C++ compiler (e.g., g++).

2. **Execution:**
   Run the compiled executable to start the News Management System.

3. **Functionality Demonstration:**
   Follow the prompts to login/register, view latest news, filter by category, rate news articles, and access admin functionalities as needed.

### Example Commands

```bash
# Compile the program (example command, adjust as per your setup)
g++ main.cpp -o news_management_system

# Run the program
./news_management_system

