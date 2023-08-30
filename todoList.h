#pragma once

#include <unordered_map>
#include "todoItem.h"
#include "todoListHeaders.h"


class todoList
{
private:

    int itemsCount = 1;

    std::unordered_map <int, todoItem> items;

public:

    void addItem(const todoItem& newItem);

    void editItem(int id, const todoItem& editedItem);

    void setProgress(int id, const std::string& progress);

    void deleteItem(int id);

    void sortBy(const std::string& method);

    void filterBy(const std::string& method);

    void display();

    static todoList load();

    void save();
};