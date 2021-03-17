#include <iostream>
#include <stdio.h>

using namespace std;

struct data{
    int day, month, year;
};

int main(){

    struct data today;

    scanf("%d/%d/%d", &today.day, &today.month, &today.year);

    cout << "Today date: " << today.day << '/' << today.month << '/' << today.year << '\n';

    return 0;
}