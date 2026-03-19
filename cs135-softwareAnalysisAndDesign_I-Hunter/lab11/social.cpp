/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-17
Updated:     2026-3-17
Description: Implement the class Profile that can store the info about a user of the network
                Each user profile has:
                    -A username, a non-empty alphanumeric string that uniquely identifies the user
                    -A display name, which can be an arbitrary string
                Provide an interface to:
                    -Return the current display name and username
                    -Change the display name (but the username cannot be changed)

*/

//--Libraries
#include <iostream>
#include <string>

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

int main(){
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)

    return 0;
}