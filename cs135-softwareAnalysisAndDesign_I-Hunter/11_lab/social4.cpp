/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-18
Updated:     2026-3-18
Description: Improved version of social3.cpp
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
                - bool writePost(string usrn, string msg);
                    -Adds a new post to the posts array
                    -If the username is found in the network and the posts array is not full, return true and false otherwise
                -bool printTimeline(string usrn);
                    -Print out all posts by the user and by the people they follow, presented in reverse-chronological order
                    -Return true if user is found in the posts array and false otherwise

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


struct Post{
  string username;
  string message;
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

    static const int MAX_POSTS = 100;
    int numPosts;                    // number of posts
    Post posts[MAX_POSTS];           // array of all posts
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);

    bool follow(string usrn1, string usrn2);
    void printDot();

    // Add a new post
    bool writePost(string usrn, string msg);
    // Print user's "timeline"
    bool printTimeline(string usrn);
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
    numPosts = 0;

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

bool Network::writePost(string usrn, string msg){
    if(numPosts >= MAX_POSTS) {
        return false;
    }


    for(int i = 0; i < numUsers; i++)
    {
        if(profiles[i].getUsername() == usrn)
        {
            Post p = {usrn,msg};
            posts[numPosts] = p;
            numPosts++;

            return true;
        }
    }

    return false;
}


int containsString(string arr[], int size, string element)
{
    int index = -1;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            index = i;
            return index;
        }
    }

    return index;
}


bool Network::printTimeline(string usrn){
    bool userFound = false;

    string connections[MAX_USERS];
    int numConnections = 0;

    for(int r = 0; r < numUsers; r++)
    {
        if(profiles[r].getUsername() == usrn)
        {
            userFound = true;
        }
    }

    if(!userFound)
    {
        return false;
    }

    for(int c = 0; c < numUsers; c++)
    {
        if(following[findID(usrn)][c])
        {
            connections[numConnections] = profiles[c].getUsername();
            numConnections++;
        }
    }


    for(int i = numPosts; i >= 0; i--)
    {
        string user = posts[i].username;
        if((user == usrn) || (containsString(connections,numConnections,user) != -1))
        {
            cout << profiles[findID(user)].getFullName() << ": " << posts[i].message << '\n';
        }
    }
    return true;

}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
    
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;

    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;

    return 0;
}