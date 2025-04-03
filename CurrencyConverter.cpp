#include <iostream>
#include <unordered_map>
#include <stdexcept>
using namespace std;
int main() {
   
    string fromCurrency, toCurrency;
    double amount;

    cout << "Welcome to Currency Converter!\n";
    cout << "Enter source currency (e.g., USD, EUR, INR): ";
    cin >> fromCurrency;
    cout << "Enter target currency (e.g., USD, EUR, INR): ";
    cin >> toCurrency;
    cout << "Enter amount: ";
    cin >> amount;

    return 0;
}
