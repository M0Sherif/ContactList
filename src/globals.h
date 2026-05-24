#pragma once
#include <QApplication>
#include <QCoreApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QCheckBox>
#include "ContactManager.h"
#include "FileManager.h"

#define widget QWidget
#define label QLabel
#define button QPushButton
#define field QLineEdit
#define hbox QHBoxLayout
#define vbox QVBoxLayout
#define check_box QCheckBox

extern field*       Search_bar;
extern vbox*        first_page;
extern widget*      list_container;
extern vbox*        list_layout;
extern widget*      window;
extern widget*      add_contact_window;
extern widget*      inside_contact;
extern field*       name_field;
extern field*       Email_field;
extern field*       Phone_field;
extern vbox*        second_page;
extern field*       inside_name;
extern field*       inside_email;
extern field*       inside_number;
extern label*       inside_name_label;
extern label*       inside_email_label;
extern label*       inside_number_label;
extern label*       favorite_label;
extern label*       contacts_count_label;
extern label*       inside_avatar_label;
extern check_box*   favorite_checkbox;
extern ContactManager manager;
extern FileManager    contacts_file;
extern Contact*     current_contact;
extern QScrollArea* scroll;