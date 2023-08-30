#include <fstream>
#include <iomanip>
#include <utility>

#include "todoItem.h"


// Constructor
todoItem::todoItem() :dueDate(parseDate("1-1-2000")), itemPriority(low), itemProgress(notStarted) {}

todoItem::todoItem(string  tit, string  des, tm due, priority pri) : title(std::move(tit)), description(std::move(des)), dueDate(due), itemPriority(pri), itemProgress(notStarted) {}

todoItem::todoItem(string  tit, string  des, tm due, priority pri, progress pro) : title(std::move(tit)), description(std::move(des)), dueDate(due), itemPriority(pri), itemProgress(pro) {}

//setters&getters

void todoItem::setProgress(progress pro){
    itemProgress = pro;
}

progress todoItem::getProgress() const {
    return (itemProgress);
}

priority todoItem::getPriority() const {
    return(itemPriority);
}

tm todoItem::getDueDate() const {
    return (dueDate);
}

//methods

void todoItem::displayItem(){
    string pri;
    if (itemPriority == 0) { pri = "Low"; }
    if (itemPriority == 1) { pri = "Medium"; }
    if (itemPriority == 2) { pri = "High"; }

    string pro;
    if (itemProgress == 0) { pro = "Not Started"; }
    if (itemProgress == 1) { pro = "In Progress"; }
    if (itemProgress == 2) { pro = "Done"; }


    char dBuffer[80]; // Buffer to store the formatted date
    std::strftime(dBuffer, sizeof(dBuffer), "%d-%m-%Y", &dueDate);


    std::cout  << std::left << std::setw(25) << title << ": "  << std::setw(35) <<  description
               <<  " By: " << dBuffer << " | Is: " << std::setw(8) << pri << " | Is: " << pro << std::endl;
}

string todoItem::saveItem() const {
    string pri;
    if (itemPriority == 0) { pri = "low"; }
    if (itemPriority == 1) { pri = "medium"; }
    if (itemPriority == 2) { pri = "high"; }

    string pro;
    if (itemProgress == 0) { pro = "not started"; }
    if (itemProgress == 1) { pro = "in progress"; }
    if (itemProgress == 2) { pro = "done"; }

    char dBuffer[80]; // Buffer to store the formatted date
    std::strftime(dBuffer, sizeof(dBuffer), "%d-%m-%Y", &dueDate);


    string item = "\"" + title + "\" \"" + description +  "\" \"" + dBuffer
                  + "\" \"" + pri + "\" \"" + pro + "\"";
    return item;
}
