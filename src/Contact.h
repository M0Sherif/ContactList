#pragma once
#include<iostream>
#include<string>
using namespace std;
class Contact
{
private:
    string name;
    string phone_number;
    string email;
    bool favorite;
public:
    Contact();
    Contact(string name, string phone_number, string email);
    void display_contact();
    string get_name();
    string get_phone_number();
    string get_email();
    void set_name(string name);
    void set_phone_number(string phone_number);
    void set_email(string email);
    void update_contact(string name, string phone_number, string email);
    bool is_favorite();
    void set_favorite(bool fav);
    void toggle_favorite();
};