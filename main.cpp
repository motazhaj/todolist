#include "todoListHeaders.h"
#include "cParser.h"


int main() {

    string input;
//    todoList list;
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

        cout << divider;

    }
    return 0;
}