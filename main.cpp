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

    //load saved txt file
    cout << "\nLoading..." << endl;
    try {
//        list = todoList::load();
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

        }
        else if (command == "progress") {

        }
        else if (command == "delete") {

        }
        else if (command == "show") {

        }
        else if (command == "sort") {

        }
        else if (command == "filter") {

        }
        else if (command == "help") {

        }
        else if (command == "save") {

        }
        else {
            cout << "You have entered an invalid command, " << helper << endl;
        }

        loopEnd:
        cout << divider;

    }
    return 0;
}