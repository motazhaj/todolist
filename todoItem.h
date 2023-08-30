#pragma once


#include <iostream>
#include <string>

#include "todoListHeaders.h"
#include "date.h"


class todoItem
{
private:
    string title;
    string description;
    tm dueDate{};
    priority itemPriority;
    progress itemProgress;

public:
    // Constructors
    todoItem();

    todoItem(string  tit, string  des, tm due, priority pri); // default progress set to not started

    todoItem(string  tit, string  des, tm due, priority pri, progress pro); // for loading progress from file

    //setters&getters
    void setProgress(progress pro);

    progress getProgress() const;

    priority getPriority() const;

    tm getDueDate() const;


    //methods
    void displayItem();

    string saveItem() const;

};
