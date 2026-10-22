#pragma once

#include <iostream>
#include <sstream>

static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ulianDay(int day, int month, int year);

int dayForGC(int day, int year, int month);

int JDToNormal(int JD, int& daySoon, int& monthSoon);

bool isLeapYear(int year);

int getDayOfWeek(int day, int month, int year);

int DaysInMonth(int month, int year);