
#include "Date.h"
using namespace std;

int main() {
    Date d(1,1,2017);
    d.printDate();
    d.setDay(5);
    d.printDate();
    return 0;
}