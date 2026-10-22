
#include "calendar.h"

#include <iostream>

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
  std::cout << year << '\n';
  std::cout << Months[month - 1] << '\n';
  std::cout << "Su Mo Tu We Th Fr Sa\n";

  int first = dayForGC(1, year, month);
  int count = DaysInMonth(month, year);

  for (int i = 0; i < first; ++i) {
    std::cout << "   ";
  }

  for (int day = 1; day <= count; ++day) {
    PrintNumber(day);

    int weekday = (first + day - 1) % 7;

    if (weekday == 6) {
      std::cout << '\n';
    } else if (day != count) {
      std::cout << ' ';
    }
  }

  if ((first + count) % 7 != 0) {
    std::cout << '\n';
  }
}

void printYear(int year) {
  std::cout << year << '\n';

  for (int group = 0; group < 12; group += 3) {
    if (group != 0) {
      std::cout << '\n';
    }

    for (int m = 0; m < 3; ++m) {
      const char* name = Months[group + m];

      int len = 0;
      while (name[len] != '\0') {
        ++len;
      }

      std::cout << name;

      if (m != 2) {
        for (int k = len; k < 22; ++k) {
          std::cout << ' ';
        }
      }
    }

    std::cout << '\n';

    for (int m = 0; m < 3; ++m) {
      if (m != 0) {
        std::cout << "  ";
      }

      std::cout << "Su Mo Tu We Th Fr Sa";
    }

    std::cout << '\n';

    int first[3];
    int count[3];
    int weeks = 0;

    for (int m = 0; m < 3; ++m) {
      first[m] = dayForGC(1, year, group + m + 1);
      count[m] = DaysInMonth(group + m + 1, year);

      int n = (first[m] + count[m] + 6) / 7;

      if (n > weeks) {
        weeks = n;
      }
    }

    for (int w = 0; w < weeks; ++w) {
      char line[65];

      for (int k = 0; k < 64; ++k) {
        line[k] = ' ';
      }

      line[64] = '\0';

      for (int m = 0; m < 3; ++m) {
        for (int d = 0; d < 7; ++d) {
          int number = w * 7 + d - first[m] + 1;

          if (number < 1 || number > count[m]) {
            continue;
          }

          int pos = m * 22 + d * 3;

          if (number >= 10) {
            line[pos] = char('0' + number / 10);
          }

          line[pos + 1] = char('0' + number % 10);
        }
      }

      int len = 64;

      while (len > 0 && line[len - 1] == ' ') {
        --len;
      }

      line[len] = '\0';

      std::cout << line << '\n';
    }
  }
}
