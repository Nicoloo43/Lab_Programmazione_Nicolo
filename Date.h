//
// Created by Nicolò on 30/09/2023.
//

#ifndef EL_LAB_PROG_DATE_H
#define EL_LAB_PROG_DATE_H
#include <iostream>

class Date {
private: int day;
    int month;
    int year;

public:
    // Constructor
    Date(int d, int m, int y): day(d),
                               month(m),
                               year(y) {}

    // Member function to set the date
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    // Member function to get the day
    int getDay() const {
        return day;
    }

    // Member function to get the month
    int getMonth() const {
        return month;
    }

    // Member function to get the year
    int getYear() const {
        return year;
    }

    // Member function to validate if the date is valid
    bool isValidDate() const {
        // Check if the month is valid
        if (month < 1 || month > 12)
            return false;

        // Check if the day is valid
        if (day < 1 || day > 31)
            return false;

        // Check for specific month-day combinations that are invalid
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;

        if (month == 2) {
            // Check for leap year
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                if (day > 29)
                    return false;
            } else {
                if (day > 28)
                    return false;
            }
        }

        // Date is valid
        return true;
    }
};
#endif //EL_LAB_PROG_DATE_H
