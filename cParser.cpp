#include "cParser.h"


cParser::cParser() = default;

std::vector<std::string> cParser::parse(const std::string& input){

    std::vector<std::string> result;
    std::stringstream inputStream(input);
    std::string currentToken;

    char delimiter;



    while (inputStream.peek() != EOF){

        if (inputStream.peek() != ' ')//checks, if true ignore
        {
            if (inputStream.peek() == '\"')
            {
                delimiter = '\"';//for sentences
                inputStream.ignore(1);//ignore opening quotation mark
            }
            else
            {
                delimiter = ' ';//for single words
            }

            getline(inputStream, currentToken, delimiter);
            result.push_back(currentToken);
        }
        else {
            inputStream.ignore(1);
        }
    }
    return result;
}


