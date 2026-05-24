#include "ContactManager.h"
void ContactManager::add_contact(string name, string phone_number, string email)
{
    Contact c(name, phone_number, email);
    contacts[name] = c;
}

vector <Contact*> ContactManager::search_contact(string name)
{
    string prefix = name;
    vector<Contact*> results;
    transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
    auto it = contacts.lower_bound(prefix);
    while (it != contacts.end())
    {
        string keyprefix = it->first.substr(0, prefix.length());
        transform(keyprefix.begin(), keyprefix.end(), keyprefix.begin(), ::tolower);
        if (keyprefix != prefix)
            break;
        results.push_back(&it->second);
        ++it;
    }
    return results;
}
void ContactManager::update_by_name(string current_name, string name)
{
    auto it = contacts.find(current_name);
    if (it != contacts.end())
    {
        Contact c(name, it->second.get_phone_number(), it->second.get_email());
        bool f = it->second.is_favorite();
        c.set_favorite(f);
        contacts.erase(it);
        contacts[name] = c;
    }
}
void ContactManager::delete_contact(string name)
{
    if (contacts.find(name) != contacts.end())
    {
        contacts.erase(name);
    }
}
vector<Contact> ContactManager::get_all_contacts()
{
    vector<Contact> all_contacts;
    for (const auto& pair : contacts)
    {
        all_contacts.push_back(pair.second);
    }
    return all_contacts;
}
Contact* ContactManager::get_contact(string name)
{
    auto it = contacts.find(name);
    if (it != contacts.end())
    {
        return &(it->second);
    }
    throw runtime_error("Contact not found");
}


