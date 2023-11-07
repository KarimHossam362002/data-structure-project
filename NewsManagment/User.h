#include <string>
#include <unordered_map>

class User {
private:
    std::string username;
    std::string password;

public:
    User(const std::string& username, const std::string& password);
    std::string getUsername() const;
    std::string getPassword() const;

    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void displayAccount() const;
    void registerUser(const std::string& username, const std::string& password);
    void saveUsersToFile() const;
    void loadUsersFromFile();
    void processesForUser(const std::string& password);
    void favCategories(const std::string& category);
    void rateNews(int rate);
    void showNewsByCategory();
    void showLatestNews();
    bool loginUser(const std::string& username, const std::string& password);

    void login(const std::string& username, const std::string& password);
};

