#include <iostream>
using namespace std;

int main(){

    double sales, state_tax, county_tax, total_tax, net_total;

    cout << "How much was made in sales?:  ";
    cin  >> sales;

    state_tax = sales * .04;
    county_tax = sales * .02;
    total_tax = state_tax + county_tax;
    net_total = sales - total_tax;

    cout << "Sales:                       $" << sales      << endl;
    cout << "State Tax:                   $" << state_tax  << endl;
    cout << "County Tax:                  $" << county_tax << endl;
    cout << "Total taxed:                 $" << total_tax  << endl;
    cout << "Total:                       $" << net_total  << endl;
    
    return 0;
}

