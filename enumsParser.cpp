#pragma once

#include "enumsParser.h"


priority enumsParser::parsePriority(const string& token) {

    priority pri = low;
    if (token == "low") {
        pri = low;
    } else if (token == "medium") {
        pri = medium;
    } else if (token == "high") {
        pri = high;
    } else {
        throw priorityParsingException();
    }
    return pri;
}

progress progressParser::parseProgress(const string& token) {

    progress pro = notStarted;
    if (token == "not started") {
        pro = notStarted;
    } else if (token == "in progress") {
        pro = inProgress;
    } else if (token == "done") {
        pro = done;
    } else {
        throw progressParsingException();
    }
    return pro;
}

