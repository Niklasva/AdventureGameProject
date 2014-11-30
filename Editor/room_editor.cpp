#include "room_editor.h"

void Room_Editor::clear()
{
    items_.clear();
    persons_.clear();
    name_ = ""; description_ = "";
    north_ = 0; south_ = 0; west_ = 0; east_ = 0;
}
