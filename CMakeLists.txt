cmake_minimum_required(VERSION 3.16)
project("Contact List")

set(CMAKE_CXX_STANDARD 17)

# Output the .exe to the project root folder (one level above build/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Fix for windres failing on paths with spaces
set(CMAKE_RC_COMPILE_OBJECT "<CMAKE_RC_COMPILER> -O coff -i <SOURCE> -o <OBJECT>")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

set(SOURCES
    src/Main.cpp
    src/Contact.cpp
    src/ContactManager.cpp
    src/FileManager.cpp
    src/functions.cpp
    src/globals.cpp
    app.rc
)

set(HEADERS
    src/Contact.h
    src/ContactManager.h
    src/FileManager.h
    src/functions.h
    src/globals.h
)

qt_add_resources(SOURCES resources/resources.qrc)
qt_add_executable(ContactList WIN32 ${SOURCES} ${HEADERS})

target_link_libraries(ContactList PRIVATE Qt6::Widgets)