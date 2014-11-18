#include "item_editor.h"

QString Item_Editor::print_item()
{
    QString output;
    output.append("\n\tItem:\n\t{\n");
    output.append("\t\tName: " + name_ + "\n");
    output.append("\t\tDescription: " + description_ + "\n");
    output.append("\t\tHeight: " + QString::number(length_) + "\n");
    output.append("\t\tWidth: " + QString::number(width_) + "\n");
    output.append("\t\tWeight: " + QString::number(weight_) + "\n");
    output.append("\t\tValue: " + QString::number(value_) + "\n");
    output.append("\t\tThrowable: " + QString::number(throwable_) + "\n");
    output.append("\t\tSellable: " + QString::number(sellable_) + "\n");
    output.append("\t\tPickable: " + QString::number(pickable_) + "\n");
    output.append("\t}\n");
    return output;
}
