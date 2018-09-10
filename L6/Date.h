//
// Created by Sam Feig on 9/10/18.
//

#ifndef CLASS_DATE_H
#define CLASS_DATE_H

class Date {
public:
    Date(int, int, int);

    void printDate();

    void setMonth(int);

    void setDay(int);

private:
    int month;
    int day;
    int year;
};

#endif CLASS_DATE_H
