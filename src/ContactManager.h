#pragma once
#include<map>
#include<algorithm>
#include<vector>
#include"Contact.h"
struct CaseInsensitiveCompare {
    bool operator()(const string& a, const string& b) const {
        string lowerA = a, lowerB = b;
        transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        return lowerA < lowerB;
    }
};
class ContactManager
{
private:
    map<string, Contact, CaseInsensitiveCompare> contacts;
public:
    void add_contact(string name, string phone_number, string email);
    vector <Contact*> search_contact(string name);
    void delete_contact(string name);
    void update_by_name(string current_name ,string name);
    vector<Contact> get_all_contacts();
    Contact* get_contact(string name);
};