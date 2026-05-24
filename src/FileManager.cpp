#include "FileManager.h"

void FileManager::save_to_file(ContactManager& manager)
{
    ofstream file("contacts.txt");

    vector<Contact> all = manager.get_all_contacts();

    for(auto& c : all)
    {
        file << c.get_name() << ","
             << c.get_phone_number() << ","
             << c.get_email() << ","
             << (c.is_favorite() ? "1" : "0") << endl;
    }

    file.close();
}

void FileManager::load_from_file(ContactManager& manager)
{
    ifstream file("contacts.txt");

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string name;
        string phone;
        string email;
        string favorite_str;

        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, favorite_str, ',');

        manager.add_contact(name, phone, email);
        
        if(!favorite_str.empty())
        {
            bool is_fav = (favorite_str == "1");
            Contact* contact = manager.get_contact(name);
            if(contact != nullptr)
            {
                contact->set_favorite(is_fav);
            }
        }
    }

    file.close();
}