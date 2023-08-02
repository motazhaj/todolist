#pragma once

#include "todoListHeaders.h"
#include <string>


class priorityParsingException : exception {};

class enumsParser {
public:
    priority static parsePriority(const string &token);
};


class progressParsingException : exception {};

class progressParser {
public:
    progress static parseProgress(const string &token);
};

