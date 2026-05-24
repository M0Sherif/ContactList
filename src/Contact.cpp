#include "Contact.h"
Contact::Contact()
{
    name = "";
    phone_number = "";
    email = "";
    favorite = false;
}
Contact::Contact(string name, string phone_number, string email)
{
    this->name = name;
    this->phone_number = phone_number;
    this->email = email;
    favorite = false;
}
void Contact::display_contact()
{
    cout << "Name: " << name << endl;
    cout << "Phone Number: " << phone_number << endl;
    cout << "Email: " << email << endl;
}
string Contact::get_name()
{
    return name;
}
string Contact::get_phone_number()
{
    return phone_number;
}
string Contact::get_email()
{
    return email;
}
void Contact::set_name(string name)
{
    this->name = name;
}
void Contact::set_phone_number(string phone_number)
{
    this->phone_number = phone_number;
}
void Contact::set_email(string email)
{
    this->email = email;
}
void Contact::update_contact(string name, string phone_number, string email)
{
    this->name = name;
    this->phone_number = phone_number;
    this->email = email;
}
bool Contact::is_favorite()
{
    return favorite;
}

void Contact::set_favorite(bool fav)
{
    favorite = fav;
}
void Contact::toggle_favorite()
{
    favorite = !favorite;
}

