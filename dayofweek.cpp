#include <iostream>
#include <sstream>

#include "dayofweek.h"

int dayForGC(int day, int year, int month) {
    int a = (14 - month) / 12;
    int m = month + 12 * a - 2;
    int y = year - a;
    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d;
}

bool isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return true;
  }
  return false;
}

int DaysInMonth(int month, int year) {
  if (month == 2 && isLeapYear(year)) {
    return 29;
  }
  return days[month - 1];
}