#pragma once

static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayForGC(int day, int year, int month);

bool isLeapYear(int year);

int DaysInMonth(int month, int year);