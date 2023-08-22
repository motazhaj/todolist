#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class cParser
{
public:
    cParser();
    std::vector<std::string> static parse(const std::string& input);
};