#pragma once

#include <fstream>
#include <sstream>
#include "ContactManager.h"

using namespace std;

class FileManager
{
public:
    static void save_to_file(ContactManager& manager);

    static void load_from_file(ContactManager& manager);
};