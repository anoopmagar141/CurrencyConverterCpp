#include <iostream>
#include <unordered_map>
#include <stdexcept>
using namespace std;

class CurrencyConverter {
    private:
        unordered_map<string, double> exchangeRates;
    
       
        }
    
int main() {
    CurrencyConverter converter;
    string fromCurrency, toCurrency;
    double amount;

    cout << "Welcome to Currency Converter!\n";
    cout << "Enter source currency (e.g., USD, EUR, INR): ";
    cin >> fromCurrency;
    cout << "Enter target currency (e.g., USD, EUR, INR): ";
    cin >> toCurrency;
    cout << "Enter amount: ";
    cin >> amount;

    try {
        double convertedAmount = converter.convert(fromCurrency, toCurrency, amount);
        cout << fixed << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << "\n";
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
