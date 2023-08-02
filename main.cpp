#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "todoListHeaders.h"
#include "cParser.h"
#include "enumsParser.h"
#include "todoItem.h"
#include "todoList.h"
#include "date.h"

using std::cout;
using std::endl;
using std::vector;


float version = 0.5;

int main(){

    string input;
    todoList list;
    vector<string> tokens;
    string command;

    cout << divider << "Todo List version: " << version << endl; //Version Number

    //load saved txt file
    cout << "\nLoading..." << endl;
    try {
        list = todoList::load();
        cout << "\nList loaded successfully." << endl;
    }
    catch (loadException&){
        cout << "\nfile not found." << endl;
    }

    //startup text
    cout << divider << "\nEnter a command ('help' for commands, 'quit' to exit) " << endl;

    //main program loop
    while (true){

        cout << "Command: ";
        getline(std::cin, input);
        tokens = cParser::parse(input);
        command = tokens[0];
        cout << endl;

        if (command == "add"){
            if (tokens.size() != 5){
                cout << "Invalid add command, " << helper << endl;
                goto loopEnd;
            }

            try {
                priority pri = enumsParser::parsePriority(tokens[4]);
                tm due = parseDate(tokens[3]);
                todoItem newItem(tokens[1], tokens[2], due, pri);
                list.addItem(newItem);
                list.sortBy("addition");
                std::cout << "\nItem "<< tokens[1]<<" added successfully." << std::endl;
            }
            catch (priorityParsingException& e) {
                cout << "invalid priority input, " << helper << endl;
            }
            catch (dateException&){
                cout << "invalid date input, " << helper << endl;
            }
        }

        else if (command == "edit"){//TODO more abstraction

            if (tokens.size() != 6)
            {
                cout << "Invalid edit command, " << helper << endl;
                goto loopEnd;
            }

            priority pri;
            try {
                pri = enumsParser::parsePriority(tokens[5]);

            }
            catch (priorityParsingException&) {
                cout << "invalid priority input, " << helper << endl;
                goto loopEnd;
            }

            tm due{};

            try{
                due =parseDate(tokens[4]);
            }catch (dateException&){

                cout << "invalid date input, " << helper << endl;
                goto loopEnd;
            }

            int id;

            try {
                id = stoi(tokens[1]);
            }catch (const std::invalid_argument&){
                cout << "Invalid ID, " << helper << endl;
                goto loopEnd;
            }

            todoItem newItem(tokens[2], tokens[3], due, pri);

            try{
                list.editItem(id, newItem);
                list.sortBy("addition");
                cout << "\nItem edited successfully." << std::endl;
            }
            catch (editException&){
                cout << "item not found" << endl;
                goto loopEnd;
            }
        }

        else if (command == "progress"){

            int id;

            try {
                id = stoi(tokens[1]);
            }catch (const std::invalid_argument&){
                cout << "Invalid ID, " << helper << endl;
                goto loopEnd;
            }

            try {
                list.setProgress(id, tokens[2]);
                cout << "progress successfully set to:  " << tokens[2] << endl;
            }catch (progressException&){
                cout << "invalid progress type, " << helper << endl;
                goto loopEnd;
            }catch (progressExceptionId&){
                cout << "item is not in the list" << endl;
                goto loopEnd;
            }
        }

        else if (command == "delete"){

            int id;

            try {
                id = stoi(tokens[1]);
            }catch (const std::invalid_argument&){
                cout << "Invalid ID, " << helper << endl;
                goto loopEnd;
            }

            try{
                list.deleteItem(id);
                cout << "item at id = " << id << " has been deleted successfully." << endl;
            }
            catch (deleteException&){
                cout << "item is not in the list" << endl;
                goto loopEnd;
            }
        }

        else if (command == "show"){

            try{
                list.display();
            }catch (displayException&){
                cout << "list is empty" << endl;
            }
        }

        else if (command == "sort"){
            if(tokens.size() != 2){

                cout << "Invalid sort command, " << helper << endl;
                goto loopEnd;
            }

            try {
                list.sortBy(tokens[1]);

                cout << "list has been sorted by " << tokens[1] << " successfully " << endl;
            }catch (sortingException&){
                cout << "This sorting method is not valid, " << helper << endl;
                goto loopEnd;
            }

        }

        else if (command == "filter"){

            if(tokens.size() != 2){
                cout << "Invalid filter command, " << helper << endl;
                goto loopEnd;
            }

            try {

                list.filterBy(tokens[1]);

            }catch (filteringException&){
                cout << "This filtering method is not valid, " << helper << endl;
                goto loopEnd;
            }

        }

        else if (command == "weather"){//TODO

        }

        else if (command == "help"){

            cout << "Note that commands & priority are case sensitive" << endl;//TODO fix the case sensitivity

            cout << endl;
            cout << "\nCommands:" << endl;

            cout << endl;
            cout << R"(add "Title" "Description" "Due date: dd-mm-yyyy" "Priority, low/medium/high")" << endl;

            cout << endl;
            cout << R"(edit "Item id" "Title" "Description" "Due date: dd-mm-yyyy" "Priority: low/medium/high")" << endl;

            cout << endl;
            cout << "delete \"Item id\"" << endl;

            cout << endl;
            cout << R"(progress "Item id" "not started/in progress/done")" << endl;

            cout << endl;
            cout << "show" << endl;

            cout << endl;
            cout << "sort \"addition/priority/progress\" " << endl;

            cout << endl;
            cout << R"(filter priority "priority high/priority medium/priority low" or progress "not started/in progress/done" )" << endl;

            cout << endl;
            cout << "save"  << endl;

            cout << endl;
            cout << "quit" << endl;
        }

        else if (command == "save"){

            cout << "saving..." << endl;
            list.sortBy("addition");
            list.save();
        }

        else if (command == "quit"){
            cout << "Do you want to save before quitting(y/n)/(any other key to cancel): ";
            char qInput;
            std::cin >> qInput;
            qInput = tolower(qInput);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if(qInput == 'y'){
                cout << "saving..." << endl;
                list.sortBy("addition");
                list.save();
                cout << "quitting..." << endl;
                std::cout << "Press Enter to exit...";
                std::cin.get();
                return 0;
            }
            else if(qInput == 'n'){

                cout << "quitting..." << endl;
                std::cout << "\nPress Enter to exit...";
                std::cin.get();
                return 0;

            }
            else {
                cout << "Quit cancelled." <<endl;
                goto loopEnd;
            }
        }

        else{
            cout << "You have entered an invalid command, " << helper << endl;
        }

        loopEnd: cout << divider;
    }
}
