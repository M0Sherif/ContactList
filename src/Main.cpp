#include "globals.h"
#include "functions.h"

int main(int argc, char *argv[])
{
    contacts_file.load_from_file(manager);
    QApplication app(argc, argv);

    app.setStyleSheet(
        "QWidget { background-color: #1c1c1e; color: #ffffff; }"
        "QScrollArea { border: none; }"
        "QScrollBar:vertical { width: 4px; background: transparent; margin: 0; }"
        "QScrollBar::handle:vertical { background: #3a3a3c; border-radius: 2px; min-height: 24px; }"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0; }"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: transparent; }");

    window = new widget();
    add_contact_window = new widget();
    inside_contact = new widget();

    app.setWindowIcon(QIcon(":/icon.ico"));
    window->setWindowIcon(QIcon(":/icon.ico"));
    add_contact_window->setWindowIcon(QIcon(":/icon.ico"));
    inside_contact->setWindowIcon(QIcon(":/icon.ico"));

    window->resize(420, 660);
    window->setMinimumSize(360, 500);
    window->setWindowTitle("Contacts");
    add_contact_window->resize(420, 400);
    add_contact_window->setWindowTitle("New Contact");
    inside_contact->resize(420, 620);
    inside_contact->setWindowTitle("Contact");


    first_page = new vbox();
    first_page->setContentsMargins(0, 0, 0, 0);
    first_page->setSpacing(0);

    widget *header_widget = new widget();
    header_widget->setFixedHeight(64);
    header_widget->setStyleSheet("background-color: #1c1c1e; border-bottom: 1px solid #2c2c2e;");
    hbox *header_h = new hbox(header_widget);
    header_h->setContentsMargins(20, 0, 20, 0);

    label *title_lbl = new label("Contacts");
    title_lbl->setStyleSheet("font-size: 22px; font-weight: 700; color: #ffffff;");

    contacts_count_label = new label();
    contacts_count_label->setStyleSheet("font-size: 13px; color: #636366;");

    header_h->addWidget(title_lbl);
    header_h->addStretch();
    header_h->addWidget(contacts_count_label);

    widget *search_row = new widget();
    search_row->setStyleSheet("background-color: #1c1c1e;");
    hbox *search_h = new hbox(search_row);
    search_h->setContentsMargins(16, 10, 16, 10);

    Search_bar = new field();
    Search_bar->setPlaceholderText("   🔍   Search contacts...");
    Search_bar->setFixedHeight(42);
    Search_bar->setStyleSheet(
        "QLineEdit {"
        "    background-color: #2c2c2e;"
        "    border: 1px solid #3a3a3c;"
        "    border-radius: 21px;"
        "    padding: 0 20px;"
        "    color: #ffffff;"
        "    font-size: 14px;"
        "}"
        "QLineEdit:focus { border-color: #0a84ff; }");
    search_h->addWidget(Search_bar);

    scroll = new QScrollArea();
    scroll->setWidgetResizable(true);

    list_container = new widget();
    list_layout = new vbox(list_container);
    list_layout->setAlignment(Qt::AlignTop);
    list_layout->setSpacing(8);
    list_layout->setContentsMargins(12, 12, 12, 12);
    scroll->setWidget(list_container);

    widget *bottom_strip = new widget();
    bottom_strip->setFixedHeight(72);
    bottom_strip->setStyleSheet("background-color: #1c1c1e; border-top: 1px solid #2c2c2e;");
    hbox *bottom_h = new hbox(bottom_strip);
    bottom_h->setContentsMargins(20, 0, 20, 0);
    bottom_h->setAlignment(Qt::AlignVCenter);

    favorite_checkbox = new check_box("Show Favorites");
    favorite_checkbox->setStyleSheet(
        "QCheckBox { color: #8e8e93; font-size: 13px; spacing: 8px; }"
        "QCheckBox::indicator { width: 20px; height: 20px; border: 2px solid #48484a; border-radius: 5px; background: #2c2c2e; }"
        "QCheckBox::indicator:checked { background-color: #0a84ff; border-color: #0a84ff; }");

    button *Add = new button();
    Add->setText("  ＋  Add Contact");
    Add->setFixedHeight(46);
    Add->setCursor(Qt::PointingHandCursor);
    Add->setStyleSheet(
        "QPushButton {"
        "    background-color: #0a84ff;"
        "    color: #ffffff;"
        "    font-size: 14px;"
        "    font-weight: 600;"
        "    border-radius: 23px;"
        "    border: none;"
        "    padding: 0 24px;"
        "    min-width: 150px;"
        "}"
        "QPushButton:hover { background-color: #1a94ff; }"
        "QPushButton:pressed { background-color: #0070dd; }");

    bottom_h->addWidget(favorite_checkbox);
    bottom_h->addStretch();
    bottom_h->addWidget(Add);

    first_page->addWidget(header_widget);
    first_page->addWidget(search_row);
    first_page->addWidget(scroll, 1);
    first_page->addWidget(bottom_strip);
    window->setLayout(first_page);


    second_page = new vbox();
    second_page->setContentsMargins(28, 32, 28, 28);
    second_page->setSpacing(14);

    label *form_title = new label("Create New Contact");
    form_title->setAlignment(Qt::AlignCenter);
    form_title->setStyleSheet("font-size: 20px; font-weight: 700; color: #ffffff; margin-bottom: 4px;");

    QString field_style =
        "QLineEdit {"
        "    background-color: #2c2c2e;"
        "    border: 1px solid #3a3a3c;"
        "    border-radius: 12px;"
        "    padding: 0 16px;"
        "    color: #ffffff;"
        "    font-size: 15px;"
        "}"
        "QLineEdit:focus { border-color: #0a84ff; }";

    name_field = new field();
    name_field->setPlaceholderText("Full Name");
    name_field->setFixedHeight(50);
    name_field->setStyleSheet(field_style);

    Email_field = new field();
    Email_field->setPlaceholderText("Primary Email");
    Email_field->setFixedHeight(50);
    Email_field->setStyleSheet(field_style);

    Phone_field = new field();
    Phone_field->setPlaceholderText("Mobile Phone");
    Phone_field->setFixedHeight(50);
    Phone_field->setStyleSheet(field_style);

    button *add_contact_button = new button();
    add_contact_button->setText("Create Contact");
    add_contact_button->setFixedHeight(50);
    add_contact_button->setCursor(Qt::PointingHandCursor);
    add_contact_button->setStyleSheet(
        "QPushButton {"
        "    background-color: #0a84ff;"
        "    color: #ffffff;"
        "    font-size: 15px;"
        "    font-weight: 600;"
        "    border-radius: 14px;"
        "    border: none;"
        "}"
        "QPushButton:hover { background-color: #1a94ff; }"
        "QPushButton:pressed { background-color: #0070dd; }");

    button *cancel_btn = new button();
    cancel_btn->setText("Cancel");
    cancel_btn->setFixedHeight(50);
    cancel_btn->setCursor(Qt::PointingHandCursor);
    cancel_btn->setStyleSheet(
        "QPushButton {"
        "    background-color: #2c2c2e;"
        "    color: #8e8e93;"
        "    font-size: 15px;"
        "    font-weight: 500;"
        "    border-radius: 14px;"
        "    border: 1px solid #3a3a3c;"
        "}"
        "QPushButton:hover { background-color: #3a3a3c; }"
        "QPushButton:pressed { background-color: #48484a; }");

    hbox *form_btns = new hbox();
    form_btns->setSpacing(12);
    form_btns->addWidget(cancel_btn, 1);
    form_btns->addWidget(add_contact_button, 2);

    second_page->addWidget(form_title);
    second_page->addWidget(name_field);
    second_page->addWidget(Email_field);
    second_page->addWidget(Phone_field);
    second_page->addStretch();
    second_page->addLayout(form_btns);
    add_contact_window->setLayout(second_page);


    inside_name = new field();
    inside_email = new field();
    inside_number = new field();

    inside_name_label = new label();
    inside_email_label = new label();
    inside_number_label = new label();
    favorite_label = new label();
    inside_avatar_label = new label();

    inside_avatar_label->setFixedSize(88, 88);
    inside_avatar_label->setAlignment(Qt::AlignCenter);

    inside_name_label->setAlignment(Qt::AlignCenter);
    inside_name_label->setStyleSheet("font-size: 22px; font-weight: 700; color: #ffffff; background: transparent;");

    favorite_label->setAlignment(Qt::AlignCenter);
    favorite_label->setStyleSheet("font-size: 13px; color: #ffd60a; min-height: 20px; background: transparent;");

    widget *profile_top = new widget();
    profile_top->setFixedHeight(190);
    profile_top->setStyleSheet("background-color: #2c2c2e;");
    vbox *profile_v = new vbox(profile_top);
    profile_v->setAlignment(Qt::AlignCenter);
    profile_v->setSpacing(8);
    profile_v->setContentsMargins(20, 24, 20, 20);

    hbox *av_h = new hbox();
    av_h->setAlignment(Qt::AlignCenter);
    av_h->addWidget(inside_avatar_label);

    profile_v->addLayout(av_h);
    profile_v->addWidget(inside_name_label);
    profile_v->addWidget(favorite_label);

    QString save_style =
        "QPushButton {"
        "    background-color: #0a84ff; color: #ffffff;"
        "    font-size: 12px; font-weight: 600;"
        "    border-radius: 8px; border: none;"
        "    min-width: 70px;"
        "}"
        "QPushButton:hover { background-color: #1a94ff; }"
        "QPushButton:pressed { background-color: #0070dd; }";

    QString card_field_style =
        "QLineEdit {"
        "    background-color: #3a3a3c;"
        "    border: 1px solid #48484a;"
        "    border-radius: 8px;"
        "    padding: 0 10px;"
        "    color: #ffffff;"
        "    font-size: 13px;"
        "}"
        "QLineEdit:focus { border-color: #0a84ff; }";

    inside_name->setFixedHeight(36);
    inside_email->setFixedHeight(36);
    inside_number->setFixedHeight(36);
    inside_name->setStyleSheet(card_field_style);
    inside_email->setStyleSheet(card_field_style);
    inside_number->setStyleSheet(card_field_style);

    button *name_edit = new button();
    button *email_edit = new button();
    button *number_edit = new button();

    name_edit->setText("Save");
    email_edit->setText("Save");
    number_edit->setText("Save");
    name_edit->setFixedHeight(36);
    email_edit->setFixedHeight(36);
    number_edit->setFixedHeight(36);
    name_edit->setCursor(Qt::PointingHandCursor);
    email_edit->setCursor(Qt::PointingHandCursor);
    number_edit->setCursor(Qt::PointingHandCursor);
    name_edit->setStyleSheet(save_style);
    email_edit->setStyleSheet(save_style);
    number_edit->setStyleSheet(save_style);

    QString card_style = "background-color: #2c2c2e; border-radius: 12px;";
    QString type_lbl_style = "font-size: 11px; color: #636366; font-weight: 600; background: transparent;";

    inside_email_label->setStyleSheet("font-size: 15px; color: #ffffff; background: transparent;");
    widget *email_card = new widget();
    email_card->setAttribute(Qt::WA_StyledBackground, true);
    email_card->setStyleSheet(card_style);
    vbox *email_v = new vbox(email_card);
    email_v->setContentsMargins(16, 14, 16, 14);
    email_v->setSpacing(6);
    label *email_type = new label("EMAIL");
    email_type->setStyleSheet(type_lbl_style);
    hbox *email_row = new hbox();
    email_row->setSpacing(8);
    email_row->addWidget(inside_email, 1);
    email_row->addWidget(email_edit);
    email_v->addWidget(email_type);
    email_v->addWidget(inside_email_label);
    email_v->addLayout(email_row);

    inside_number_label->setStyleSheet("font-size: 15px; color: #ffffff; background: transparent;");
    widget *phone_card = new widget();
    phone_card->setAttribute(Qt::WA_StyledBackground, true);
    phone_card->setStyleSheet(card_style);
    vbox *phone_v = new vbox(phone_card);
    phone_v->setContentsMargins(16, 14, 16, 14);
    phone_v->setSpacing(6);
    label *phone_type = new label("PHONE");
    phone_type->setStyleSheet(type_lbl_style);
    hbox *phone_row = new hbox();
    phone_row->setSpacing(8);
    phone_row->addWidget(inside_number, 1);
    phone_row->addWidget(number_edit);
    phone_v->addWidget(phone_type);
    phone_v->addWidget(inside_number_label);
    phone_v->addLayout(phone_row);

    widget *name_card = new widget();
    name_card->setAttribute(Qt::WA_StyledBackground, true);
    name_card->setStyleSheet(card_style);
    vbox *name_v = new vbox(name_card);
    name_v->setContentsMargins(16, 14, 16, 14);
    name_v->setSpacing(6);
    label *name_type = new label("CHANGE NAME");
    name_type->setStyleSheet(type_lbl_style);
    hbox *name_row = new hbox();
    name_row->setSpacing(8);
    name_row->addWidget(inside_name, 1);
    name_row->addWidget(name_edit);
    name_v->addWidget(name_type);
    name_v->addLayout(name_row);

    widget *cards_widget = new widget();
    vbox *cards_v = new vbox(cards_widget);
    cards_v->setContentsMargins(16, 16, 16, 16);
    cards_v->setSpacing(10);
    cards_v->addWidget(email_card);
    cards_v->addWidget(phone_card);
    cards_v->addWidget(name_card);
    cards_v->addStretch();

    QScrollArea *info_scroll = new QScrollArea();
    info_scroll->setWidgetResizable(true);
    info_scroll->setStyleSheet("border: none; background: #1c1c1e;");
    info_scroll->setWidget(cards_widget);

    button *delete_button = new button();
    button *add_to_favourites = new button();
    button *return_button2 = new button();

    delete_button->setText("Delete");
    add_to_favourites->setText("⭐  Favorite");
    return_button2->setText("Return");
    delete_button->setFixedHeight(48);
    add_to_favourites->setFixedHeight(48);
    return_button2->setFixedHeight(48);
    delete_button->setCursor(Qt::PointingHandCursor);
    add_to_favourites->setCursor(Qt::PointingHandCursor);
    return_button2->setCursor(Qt::PointingHandCursor);

    return_button2->setStyleSheet(
        "QPushButton { background-color: #2c2c2e; color: #8e8e93; font-size: 14px; font-weight: 500;"
        "border-radius: 12px; border: 1px solid #3a3a3c; }"
        "QPushButton:hover { background-color: #3a3a3c; }"
        "QPushButton:pressed { background-color: #48484a; }");
    delete_button->setStyleSheet(
        "QPushButton { background-color: #ff453a; color: #ffffff; font-size: 14px; font-weight: 600;"
        "border-radius: 12px; border: none; }"
        "QPushButton:hover { background-color: #ff6b62; }"
        "QPushButton:pressed { background-color: #d93b31; }");
    add_to_favourites->setStyleSheet(
        "QPushButton { background-color: #2c2c2e; color: #ffd60a; font-size: 13px; font-weight: 600;"
        "border-radius: 12px; border: 1px solid #3a3a3c; }"
        "QPushButton:hover { background-color: #3a3a3c; }"
        "QPushButton:pressed { background-color: #48484a; }");

    widget *action_bar = new widget();
    action_bar->setFixedHeight(72);
    action_bar->setStyleSheet("background-color: #1c1c1e; border-top: 1px solid #2c2c2e;");
    hbox *action_h = new hbox(action_bar);
    action_h->setContentsMargins(16, 12, 16, 12);
    action_h->setSpacing(10);
    action_h->addWidget(return_button2, 1);
    action_h->addWidget(delete_button, 1);
    action_h->addWidget(add_to_favourites, 1);

    vbox *contact_layout = new vbox();
    contact_layout->setContentsMargins(0, 0, 0, 0);
    contact_layout->setSpacing(0);
    contact_layout->addWidget(profile_top);
    contact_layout->addWidget(info_scroll, 1);
    contact_layout->addWidget(action_bar);
    inside_contact->setLayout(contact_layout);


    QObject::connect(favorite_checkbox, &check_box::toggled, &update_list);
    QObject::connect(Search_bar, &field::textChanged, &update_list);
    QObject::connect(Add, &button::clicked, &switch_to_add);
    QObject::connect(add_contact_button, &button::clicked, &add_contact);
    QObject::connect(cancel_btn, &button::clicked, &return_to_page);
    QObject::connect(name_edit, &button::clicked, &edit_name);
    QObject::connect(email_edit, &button::clicked, &edit_email);
    QObject::connect(number_edit, &button::clicked, &edit_number);
    QObject::connect(delete_button, &button::clicked, &delete_contact);
    QObject::connect(add_to_favourites, &button::clicked, &add_contact_to_favourites);
    QObject::connect(return_button2, &button::clicked, &return_to_page);

    update_list();
    window->show();
    return app.exec();
}