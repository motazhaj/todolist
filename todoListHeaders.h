#pragma once
#include <string>

using std::string;
using std::exception;

const std::string filePath = R"(todo_list.txt)";

const string divider = "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
const string helper = "please use \"help\" command to guide you!";


enum progress{
    notStarted = 0, inProgress = 1, done = 2
};
enum priority{
    low = 0, medium = 1, high = 2
};

//exceptions
class editException : exception {};
class sortingException : exception {};
class filteringException : exception {};
class progressException : exception {};
class loadException : exception {};
class deleteException : exception {};
class progressExceptionId : exception {};
class displayException : exception {};
class dateException : std::exception {};

