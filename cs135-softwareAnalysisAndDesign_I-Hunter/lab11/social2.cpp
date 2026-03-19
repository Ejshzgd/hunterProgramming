/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-17
Updated:     2026-3-17
Description: Improved version of social.cpp
             The class has the following private variables:
                -An array of registered user profiles
                -An integer numUsers, which stores the number of registered users
                -The size of the profiles array is defined as MAX_USERS=20
            The public interface:
                -A default constructor that creates an empty network. For now, setting numUsers = 0
                -addUser(usrn, dspn)
                    -The new username usrn must be a non-empty alphanumeric string
                    -There is no other users in the network with the same username
                    -The array profiles is not full

*/

//--Libraries
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

//--Namespaces
using namespace std;

//---Classes ---
class Profile {
private:
    string username;
    string displayname;
public:
    Profile(string usrn, string dspn);

    Profile();

    string getUsername();

    string getFullName();

    void setDisplayName(string dspn);
};


class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn);
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
};


//--Defining Profile
Profile::Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
}

Profile::Profile(){
    username = "";
    displayname = "";
}

string Profile::getUsername(){
    return username;
}

string Profile::getFullName(){
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string dspn){
    displayname = dspn;
}

//--Defining Network
Network::Network(){
    numUsers = 0;
}

int Network::findID(string usrn){
    for(int i = 0; i < numUsers; i++)
    {
        if(profiles[i].getUsername() == usrn)
        {
            return i;
        }
    }
    return -1;
}

bool Network::addUser(string usrn, string dspn){
    if (numUsers >= MAX_USERS) {
        return false;
    }

    if (!all_of(usrn.begin(), usrn.end(),
                [](unsigned char c){ return isalnum(c); })) {
        return false;
    }

    for (int i = 0; i < numUsers; i++) {
        if (profiles[i].getUsername() == usrn) {
            return false;
        }
    }

    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;

    return true;
}


int main() {
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i), 
                    "Mario" + to_string(i)) << endl;   // true (1)

    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)

    return 0;
}