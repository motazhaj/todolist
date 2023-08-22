#include "date.h"


// Function to parse a date string in the format "day-month-year" into std::tm
tm parseDate(const std::string& dateStr) {

    std::tm date = {0};
    std::istringstream ss(dateStr);
    ss >> date.tm_mday;
    ss.ignore(1); // Ignore the hyphen
    ss >> date.tm_mon;
    ss.ignore(1); // Ignore the hyphen
    ss >> date.tm_year;

    if (date.tm_mday < 1 || date.tm_mday > 31 || date.tm_mon < 1 || date.tm_mon > 12 || date.tm_year < 1900) {
        throw dateException();
    }

    date.tm_mon -= 1; // tm_mon is zero-indexed (0 for January, 1 for February, etc.)
    date.tm_year -= 1900; // tm_year is years since 1900

        return date;
}

