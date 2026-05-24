#include "globals.h"

field*        Search_bar         = nullptr;
vbox*         first_page         = nullptr;
widget*       list_container     = nullptr;
vbox*         list_layout        = nullptr;
widget*       window             = nullptr;
widget*       add_contact_window = nullptr;
widget*       inside_contact     = nullptr;
field*        name_field         = nullptr;
field*        Email_field        = nullptr;
field*        Phone_field        = nullptr;
vbox*         second_page        = nullptr;
field*        inside_name        = nullptr;
field*        inside_email       = nullptr;
field*        inside_number      = nullptr;
label*        inside_name_label  = nullptr;
label*        inside_email_label = nullptr;
label*        inside_number_label= nullptr;
label*        favorite_label     = nullptr;
label*        contacts_count_label = nullptr;
label*        inside_avatar_label  = nullptr;
check_box*    favorite_checkbox  = nullptr;
Contact*      current_contact    = nullptr;
QScrollArea*  scroll             = nullptr;
ContactManager manager;
FileManager    contacts_file;