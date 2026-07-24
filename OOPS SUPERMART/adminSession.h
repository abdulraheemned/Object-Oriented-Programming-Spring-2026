#pragma once
#include <string>
using namespace std;

// DESIGN PATTERN: Singleton 
//   Ensure that only ONE admin session can exist at any time and provide a
//   single global access point to that session's state.


/* STRUCTURE:
 Private constructor: prevents external code from creating instances
 Static instance pointer: the single object lives here
 Static getInstance(): the one and only access point
 Private copy constructor + assignment operator: prevents copying*/
/* USAGE:
  AdminSession& s = AdminSession::getInstance();
  s.login("admin", 1234);
  if (s.isLoggedIn()) { ... }
  s.logout();*/

class AdminSession {
private:
    bool   loggedIn;
    string adminID;

    AdminSession() : loggedIn(false), adminID("") {}
    AdminSession(const AdminSession&)            = delete;
    AdminSession& operator=(const AdminSession&) = delete;

public:
    static AdminSession& getInstance() {
        static AdminSession instance;
		 return instance;
    }
    bool login(const string& id, int password) {
        if (loggedIn) {
            return false;   // already logged in Singleton enforcement
        }
        if (password == 1234) {
            loggedIn = true;
            adminID  = id;
            return true;
        }
        return false;
    }
     void logout() {
        loggedIn = false;
        adminID  = "";
    }

    bool   isLoggedIn() const { return loggedIn; }
    string getAdminID() const { return adminID;  }
};
