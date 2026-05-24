#include "globals.h"
#include "functions.h"
#include <QPushButton>
#include <QPainter>
#include <QPainterPath>

static QPixmap make_avatar(const QString& name, int size = 46)
{
    QPixmap px(size, size);
    px.fill(Qt::transparent);

    QString initials;
    QStringList parts = name.trimmed().split(' ', Qt::SkipEmptyParts);
    if (parts.size() >= 2)
        initials = QString(parts[0][0]).toUpper() + QString(parts[1][0]).toUpper();
    else if (!parts.isEmpty())
        initials = QString(parts[0][0]).toUpper();

    static const QColor colors[] = {
        QColor("#5e5ce6"), QColor("#0a84ff"), QColor("#30d158"),
        QColor("#ff9f0a"), QColor("#bf5af2"), QColor("#ff453a"),
        QColor("#64d2ff"), QColor("#ff6b6b")
    };
    int idx = 0;
    for (QChar c : name) idx += c.unicode();
    QColor bg = colors[abs(idx) % 8];

    QPainter p(&px);
    p.setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addEllipse(0, 0, size, size);
    p.setClipPath(path);
    p.fillRect(0, 0, size, size, bg);
    p.setPen(Qt::white);
    QFont f;
    f.setPixelSize(size * 11 / 32);
    f.setBold(true);
    p.setFont(f);
    p.drawText(QRect(0, 0, size, size), Qt::AlignCenter, initials);

    return px;
}

void update_list()
{
    delete list_container;
    list_container = new widget();

    list_layout = new vbox(list_container);
    list_layout->setAlignment(Qt::AlignTop);
    list_layout->setSpacing(8);
    list_layout->setContentsMargins(12, 12, 12, 12);
    scroll->setWidget(list_container);

    QString text = Search_bar->text();
    vector<Contact*> results = manager.search_contact(text.toStdString());

    int displayed = 0;
    for (size_t i = 0; i < results.size(); i++)
        if ((favorite_checkbox->isChecked() && results[i]->is_favorite()) || !favorite_checkbox->isChecked())
            displayed++;

    if (contacts_count_label)
        contacts_count_label->setText(QString::number(displayed) + " Contacts");

    for (size_t i = 0; i < results.size(); i++)
    {
        if ((favorite_checkbox->isChecked() && results[i]->is_favorite()) || !favorite_checkbox->isChecked())
        {
            button* card = new button(list_container);
            card->setMinimumHeight(78);
            card->setCursor(Qt::PointingHandCursor);
            card->setStyleSheet(
                "QPushButton {"
                "    background-color: #2c2c2e;"
                "    border: 1px solid #3a3a3c;"
                "    border-radius: 14px;"
                "    text-align: left;"
                "    padding: 0px;"
                "}"
                "QPushButton:hover {"
                "    background-color: #363638;"
                "    border-color: #48484a;"
                "}"
                "QPushButton:pressed { background-color: #48484a; }"
            );

            hbox* row = new hbox(card);
            row->setContentsMargins(14, 14, 14, 14);
            row->setSpacing(12);

            label* av = new label();
            av->setPixmap(make_avatar(QString::fromStdString(results[i]->get_name())));
            av->setFixedSize(46, 46);
            av->setStyleSheet("background: transparent; border: none;");

            vbox* txt = new vbox();
            txt->setSpacing(2);

            label* name_lbl  = new label(QString::fromStdString(results[i]->get_name()));
            label* email_lbl = new label(QString::fromStdString(results[i]->get_email()));
            label* phone_lbl = new label(QString::fromStdString(results[i]->get_phone_number()));

            name_lbl->setStyleSheet("font-size: 15px; font-weight: 600; color: #ffffff; background: transparent; border: none;");
            email_lbl->setStyleSheet("font-size: 12px; color: #8e8e93; background: transparent; border: none;");
            phone_lbl->setStyleSheet("font-size: 12px; color: #8e8e93; background: transparent; border: none;");

            txt->addWidget(name_lbl);
            txt->addWidget(email_lbl);
            txt->addWidget(phone_lbl);

            label* star = new label(results[i]->is_favorite() ? "⭐" : "");
            star->setStyleSheet("background: transparent; border: none; font-size: 14px;");

            row->addWidget(av);
            row->addLayout(txt, 1);
            row->addWidget(star);

            list_layout->addWidget(card);

            Contact* captured = results[i];
            QObject::connect(card, &button::clicked, [captured]() {
                handle_card_click(captured);
            });
        }
    }
}

void add_contact()
{
    QString name  = name_field->text();
    QString email = Email_field->text();
    QString phone = Phone_field->text();
    manager.add_contact(name.toStdString(), phone.toStdString(), email.toStdString());
    contacts_file.save_to_file(manager);
    name_field->clear();
    Email_field->clear();
    Phone_field->clear();
    return_to_page();
}

void switch_to_add()
{
    window->hide();
    add_contact_window->show();
}

void return_to_page()
{
    add_contact_window->hide();
    inside_contact->hide();
    update_list();
    window->show();
}

void handle_card_click(Contact* contact)
{
    window->hide();

    current_contact = contact;
    inside_name->setText("");
    inside_email->setText("");
    inside_number->setText("");
    inside_name->setPlaceholderText(QString::fromStdString(current_contact->get_name()));
    inside_email->setPlaceholderText(QString::fromStdString(current_contact->get_email()));
    inside_number->setPlaceholderText(QString::fromStdString(current_contact->get_phone_number()));
    inside_name_label->setText(QString::fromStdString(current_contact->get_name()));
    inside_email_label->setText(QString::fromStdString(current_contact->get_email()));
    inside_number_label->setText(QString::fromStdString(current_contact->get_phone_number()));
    favorite_label->setText(current_contact->is_favorite() ? "⭐  Favorite" : "");

    if (inside_avatar_label)
        inside_avatar_label->setPixmap(make_avatar(QString::fromStdString(current_contact->get_name()), 84));

    inside_contact->show();
    contacts_file.save_to_file(manager);
}

void add_contact_to_favourites()
{
    (*current_contact).toggle_favorite();
    favorite_label->setText(current_contact->is_favorite() ? "⭐  Favorite" : "");
    contacts_file.save_to_file(manager);
}

void edit_name()
{
    manager.update_by_name(current_contact->get_name(), inside_name->text().toStdString());
    current_contact = manager.get_contact(inside_name->text().toStdString());
    current_contact->set_name(inside_name->text().toStdString());
    contacts_file.save_to_file(manager);
    handle_card_click(current_contact);
}

void edit_email()
{
    current_contact->set_email(inside_email->text().toStdString());
    contacts_file.save_to_file(manager);
    handle_card_click(current_contact);
}

void edit_number()
{
    current_contact->set_phone_number(inside_number->text().toStdString());
    contacts_file.save_to_file(manager);
    handle_card_click(current_contact);
}

void delete_contact()
{
    manager.delete_contact(current_contact->get_name());
    contacts_file.save_to_file(manager);
    return_to_page();
}