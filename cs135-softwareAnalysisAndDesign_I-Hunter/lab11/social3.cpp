/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-18
Updated:     2026-3-18
Description: Improved version of social2.cpp
             The class has the following private variables:
                -An array of registered user profiles
                -An integer numUsers, which stores the number of registered users
                -The size of the profiles array is defined as MAX_USERS=20
                - bool following[MAX_USERS][MAX_USERS]; Defines a friendship matrix
            The public interface:
                -A default constructor that creates an empty network. For now, setting numUsers = 0
                -bool addUser(usrn, dspn);
                    -The new username usrn must be a non-empty alphanumeric string
                    -There is no other users in the network with the same username
                    -The array profiles is not full
                    -Return true if added successfully, false otherwise
                -bool follow(string usrn1, string usrn2);
                    -Make 'usrn1' follow 'usrn2' (if both usernames are in the network)
                    -Return true if success (if both usernames exist), otherwise return false
                -void printDot();
                    -Print Dot file (graphical representation of the network)

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
    bool following[MAX_USERS][MAX_USERS];  // friendship matrix:

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn);
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);

    bool follow(string usrn1, string usrn2);
    void printDot();
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

    for(int r = 0; r < MAX_USERS; r++)
    {
        for(int c = 0; c < MAX_USERS; c++)
        {
            following[r][c] = false;
        }
    }
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

bool Network::follow(string usrn1, string usrn2){
    bool flag1 = false, flag2 = false;

    for(Profile p : profiles)
    {
        if(p.getUsername() == usrn1)
        {
            flag1 = true;
        }

        if(p.getUsername() == usrn2)
        {
            flag2 = true;
        }

        if(flag1 == flag2)
        {
            break;
        }
    }

    following[findID(usrn1)][findID(usrn2)] = true;

    return true;
}

void Network::printDot(){
    cout << "\ndigraph {\n";

    for(int i = 0; i < numUsers; i++)
    {
        cout << "  \"@" << profiles[i].getUsername() << "\"" << "\n";
    }

    cout << '\n';
    for(int r = 0; r < numUsers; r++)
    {
        for(int c = 0; c < numUsers; c++)
        {
            if(following[r][c])
            {
                cout << "  \"@" << profiles[r].getUsername() << "\" -> \"@" << profiles[c].getUsername() << "\"" << '\n';
            } 
        }
    }

    cout << '}';
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}