#include "todoListHeaders.h"
#include "cParser.h"
#include "enumParser.h"
#include "todoItem.h"
#include "todoList.h"
#include "date.h"

using std::cout;
using std::endl;
using std::vector;

float version = 0.5;

int main() {

    string input;
    todoList list;
    vector<string> tokens;
    string command;

    cout << divider << "Todo List version: " << version << endl; //Version Number

//    load saved txt file
    cout << "\nLoading..." << endl;
    try {
        list = todoList::load();
        cout << "\nList loaded successfully." << endl;
    }
    catch (loadException &) {
        cout << "\nfile not found." << endl;
    }

    //startup text
    cout << divider << "\nEnter a command ('help' for commands, 'quit' to exit) " << endl;

//main program loop
    while (true) {

        cout << "Command: ";
        getline(std::cin, input);
        tokens = cParser::parse(input);
        command = tokens[0];
        cout << endl;

        if (command == "quit") {
            break;
        }
        else if (command == "add") {
            if (tokens.size() != 5) {
                cout << "Invalid add command, " << helper << endl;
                goto loopEnd;
            }

            try {
                priority pri = enumsParser::parsePriority(tokens[4]);
                tm due = parseDate(tokens[3]);
                todoItem newItem(tokens[1], tokens[2], due, pri);
                list.addItem(newItem);
                list.sortBy("addition");
                std::cout << "\nItem " << tokens[1] << " added successfully." << std::endl;
            }
            catch (priorityParsingException &e) {
                cout << "invalid priority input, " << helper << endl;
            }
            catch (dateException &) {
                cout << "invalid date input, " << helper << endl;
            }

        }
        else if (command == "edit") {
            if (tokens.size() != 6) {
                cout << "Invalid edit command, " << helper << endl;
                goto loopEnd;
            }

            priority pri;
            try {
                pri = enumsParser::parsePriority(tokens[5]);

            }
            catch (priorityParsingException &) {
                cout << "invalid priority input, " << helper << endl;
                goto loopEnd;
            }

            tm due{};
            try {
                due = parseDate(tokens[4]);
            } catch (dateException &) {

                cout << "invalid date input, " << helper << endl;
                goto loopEnd;
            }

            int id;

            try {
                id = stoi(tokens[1]);
            } catch (const std::invalid_argument &) {
                cout << "Invalid ID, " << helper << endl;
                goto loopEnd;
            }

            todoItem newItem(tokens[2], tokens[3], due, pri);

            try {
                list.editItem(id, newItem);
                list.sortBy("addition");
                cout << "\nItem edited successfully." << std::endl;
            }
            catch (editException &) {
                cout << "item not found" << endl;
                goto loopEnd;
            }
        }
        else if (command == "progress") {

            int id;

            try {
                id = stoi(tokens[1]);
            } catch (const std::invalid_argument &) {
                cout << "Invalid ID, " << helper << endl;
                goto loopEnd;
            }

            try {
                list.setProgress(id, tokens[2]);
                cout << "progress successfully set to:  " << tokens[2] << endl;
            } catch (progressException &) {
                cout << "invalid progress type, " << helper << endl;
                goto loopEnd;
            } catch (progressExceptionId &) {
                cout << "item is not in the list" << endl;
                goto loopEnd;
            }
        }
        else if (command == "delete") {

        }
        else if (command == "show") {
            try {
                list.display();
            } catch (displayException &) {
                cout << "list is empty" << endl;
            }
        }
        else if (command == "sort") {

        }
        else if (command == "filter") {

        }
        else if (command == "help") {

        }
        else if (command == "save") {
            cout << "Saving..." << endl;
            list.sortBy("addition");
            list.save();
        }
        else {
            cout << "You have entered an invalid command, " << helper << endl;
        }

        loopEnd:
        cout << divider;

    }
    return 0;
}