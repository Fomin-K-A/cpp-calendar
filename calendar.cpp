#include <iostream>

#include "calendar.h"
#include "dayofweek.h"

const char* Months[] = {"January",   "February", "March",    "April",
                        "May",       "June",     "July",     "August",
                        "September", "October",  "November", "December"};

void PrintNumber(int n) {
  if (n < 10) {
    std::cout << ' ';
  }
  std::cout << n;
}

void printMonth(int month, int year) {
  int start_day = dayForGC(1, year, month);

  std::cout << year << '\n';
  std::cout << Months[month-1] << '\n';
  std::cout << "Su Mo Tu We Th Fr Sa" << '\n';

  for (int i = 0; i < start_day; i++) {
    std::cout << "   ";
  }

  int column = start_day;
  int days_in_month = DaysInMonth(month, year);
  for (int i = 1; i <= days_in_month; i++) {
    PrintNumber(i);
    ++column;

    if (column == 7) {
      column = 0;
      if (i != days_in_month) {
        std::cout << '\n';
      }
    } else if (i != days_in_month) {
      std::cout << ' ';
    }
  }

}

void printYear(int year) {
  std::cout << year << '\n';

  for (int i = 1; i <= 12; i += 3) {
    for (int j = i; j < i + 3; j++) {
      const char* name = Months[j - 1];

      int len = 0;
      while (name[len] != '\0') {
        len++;
      }

      std::cout << name;

      if (j != i + 2) {
        for (int k = len; k < 22; k++) {
          std::cout << ' ';
        }
      }
    }

    std::cout << '\n';

    for (int j = 0; j < 3; j++) {
      std::cout << "Su Mo Tu We Th Fr Sa";

      if (j != 2) {
        std::cout << "  ";
      }
    }

    std::cout << '\n';

    int days_in_month[3];

    int start_day[3];

    int max_week = 0;

    for (int j = 0; j < 3; j++) {
      int month = i + j;

      days_in_month[j] = DaysInMonth(month, year);
      start_day[j] = dayForGC(1, year, month);

      int weeks = (start_day[j] + days_in_month[j] + 6) / 7;

      if (weeks > max_week) {
        max_week = weeks;
      }
    }

    for (int week = 0; week < max_week; week++) {
      for (int j = 0; j < 3; j++) {
        for (int day = 0; day < 7; day++) {
          int number = week * 7 + day - start_day[j] + 1;

          if (number < 1 || number > days_in_month[j]) {
            std::cout << "  ";
          } else {
            PrintNumber(number);
          }

          if (day != 6) {
            std::cout << ' ';
          }
        }

        if (j != 2) {
          std::cout << "  ";
        }
      }

      std::cout << '\n';
    }

    if (i != 10) {
      std::cout << "\n";
    }
  }
}
