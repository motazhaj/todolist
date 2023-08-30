#include <algorithm>
#include <fstream>
#include <vector>
#include <iomanip>

#include "todoListHeaders.h"
#include "todoList.h"
#include "cParser.h"
#include "enumParser.h"
#include "date.h"


bool addCmp(const std::pair<int, todoItem>& a, const std::pair<int, todoItem>& b) {
    return a.first > b.first;
}

bool dueCmp(const std::pair<int, todoItem>& a, const std::pair<int, todoItem>& b) {
    tm date1 (a.second.getDueDate());
    tm date2 (b.second.getDueDate());

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    return time1 > time2;
}

bool priCmp(const std::pair<int, todoItem>& a, const std::pair<int, todoItem>& b) {
    return a.second.getPriority() < b.second.getPriority();
}

bool proCmp(const std::pair<int, todoItem>& a, const std::pair<int, todoItem>& b) {
    return a.second.getProgress() < b.second.getProgress();
}
//TODO ask for a better Cmp boolean solution


void todoList::addItem(const todoItem& newItem)
{
    items.insert(std::make_pair(itemsCount, newItem));
    itemsCount++;

}

void todoList::editItem(int id, const todoItem& editedItem)
{
    auto it = items.find(id);
    if (it != items.end()) {
        items.erase(id);
        items.insert(std::make_pair(id, editedItem));
    } else {
        throw editException();
    }

}

void todoList::setProgress(int id, const std::string& progress)
{
    enum progress pro;
    if (progress == "not started") { pro = notStarted; }
    else if (progress == "in progress") { pro = inProgress; }
    else if (progress == "done") { pro = done; }
    else {throw progressException();}

    auto it = items.find(id);
    if (it != items.end()) {
        items[id].setProgress(pro);
    } else {
        throw progressExceptionId();
    }

}

void todoList::sortBy(const std::string& method){

    std::vector <std::pair<int,todoItem>> vItems(items.begin(),items.end());

    if (method == "addition"){

        std::sort(vItems.begin(), vItems.end(), addCmp);

        std::unordered_map<int, todoItem> sortedMap;

        for (const auto& pair : vItems) {
            sortedMap.insert(pair);
        }
        items = sortedMap;

    }
    else if (method == "date"){

        std::sort (vItems.begin(), vItems.end(), dueCmp);

        std::unordered_map<int, todoItem> sortedMap;

        for (const auto& pair : vItems) {
            sortedMap.insert(pair);
        }
        items = sortedMap;

    }else if (method == "priority"){

        std::sort (vItems.begin(), vItems.end(), priCmp);

        std::unordered_map<int, todoItem> sortedMap;

        for (const auto& pair : vItems) {
            sortedMap.insert(pair);
        }
        items = sortedMap;


    }else if (method == "progress"){


        std::sort (vItems.begin(), vItems.end(), proCmp);

        std::unordered_map<int, todoItem> sortedMap;

        for (const auto& pair : vItems) {
            sortedMap.insert(pair);
        }
        items = sortedMap;


    }else {
        throw sortingException();
    }

}

void todoList::filterBy(const std::string& method){

    if (method == "priority high"){

        for (auto pair : items) {
            if (pair.second.getPriority() == high) {
                std::cout << pair.first << " : ";
                pair.second.displayItem();
            }
        }
    }
    else if (method == "priority medium"){

        for (auto pair : items) {
            if (pair.second.getPriority() == medium) {
                std::cout << pair.first << " : ";
                pair.second.displayItem();
            }
        }
    }
    else if (method == "priority low"){

        for (auto pair : items) {
            if (pair.second.getPriority() == medium) {
                std::cout << pair.first << " : ";
                pair.second.displayItem();
            }
        }

    }
    else if (method == "not started"){

        for (auto pair : items) {
            if (pair.second.getProgress() == notStarted) {
                std::cout << pair.first << " : ";
                pair.second.displayItem();
            }
        }

    }
    else if (method == "in progress"){

        for (auto pair : items) {
            if (pair.second.getProgress() == inProgress) {
                std::cout << pair.first << " : ";
                pair.second.displayItem();
            }
        }

    }
    else if (method == "done"){

        for (auto pair : items) {
            if (pair.second.getProgress() == done) {
                std::cout << pair.first << " : ";
                pair.second.displayItem();
            }
        }

    }else {
        throw filteringException();
    }
}

void todoList::deleteItem(int id){

    auto it = items.find(id);
    if (it != items.end()) {
        items.erase(id);
    } else {
        throw deleteException();
    }
}

void todoList::display(){
    if(!items.empty()) {
        for (auto pair: items) {
            std::cout <<std::left <<std::setw(2) << pair.first << " : ";
            pair.second.displayItem();
        }
    }
    else {
        throw displayException();
    }
}


todoList todoList::load(){



    std::ifstream myFile(filePath); // read from file

    if (!myFile.is_open()) {
        throw loadException();
    }

    string input;
    todoList list;
    std::vector<string> tokens;

    tm fDue{};
    priority fPri;
    progress fPro;

    if(myFile.is_open()) {
        while (getline(myFile, input)) {
            tokens = cParser::parse(input);
            fDue = parseDate(tokens[3]);
            fPri = enumsParser::parsePriority(tokens[4]);
            fPro = progressParser::parseProgress(tokens[5]);

            todoItem fItem(tokens[1], tokens[2], fDue, fPri, fPro);
            list.addItem(fItem);
        }

        myFile.close();
        list.sortBy("addition");
    }
    else{
        throw loadException();
    }
    return list;
}

void todoList::save(){

    std::ofstream myFile(filePath); // write to txt file

    if (myFile.is_open()) {
        for (const auto& pair: items) {
            myFile << pair.first << " " << pair.second.saveItem() << '\n';
        }
    }
    myFile.close();
}