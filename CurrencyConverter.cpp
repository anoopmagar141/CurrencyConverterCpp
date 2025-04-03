#include <iostream>
#include <unordered_map>
#include <stdexcept>
using namespace std;

class CurrencyConverter {
private:
    unordered_map<string, double> exchangeRates;

    void loadExchangeRates() {
        exchangeRates = {
            {"USD", 1.0}, {"EUR", 0.91}, {"GBP", 0.78}, {"INR", 83.27},
            {"JPY", 151.85}, {"CNY", 7.22}, {"AUD", 1.52}, {"CAD", 1.35},
            {"NPR", 132.50}, {"CHF", 0.89}, {"SGD", 1.34}, {"HKD", 7.84},
            {"SEK", 10.48}, {"NZD", 1.67}, {"KRW", 1320.75}, {"BRL", 4.98},
            {"ZAR", 18.52}, {"RUB", 92.34}, {"MXN", 17.20}, {"IDR", 15950.0},
            {"TRY", 32.55}, {"SAR", 3.75}, {"AED", 3.67}, {"THB", 36.50},
            {"MYR", 4.69}, {"PKR", 278.90}, {"EGP", 30.87}, {"BDT", 109.50},
            {"VND", 24650.0}, {"PLN", 3.98}, {"CZK", 23.12}, {"HUF", 351.47},
            {"DKK", 6.84}, {"ILS", 3.72}, {"ARS", 880.50}, {"CLP", 926.15},
            {"COP", 3912.75}, {"PEN", 3.78}, {"NGN", 1380.45}, {"KWD", 0.31},
            {"BHD", 0.38}, {"OMR", 0.39}, {"QAR", 3.64}, {"LKR", 303.50},
            {"MAD", 10.25}, {"DZD", 136.70}, {"UAH", 38.75}, {"BGN", 1.79},
            {"RON", 4.92}, {"KES", 134.25}, {"TZS", 2550.0}, {"UGX", 3850.0},
            {"GHS", 14.25}, {"ETB", 56.75}, {"XAF", 600.50}, {"XOF", 600.50},
            {"MUR", 45.50}, {"BWP", 14.75}, {"ZMW", 24.95}, {"NAD", 18.52},
            {"SYP", 2500.0}, {"IQD", 1310.0}, {"AFN", 74.75}, {"MNT", 3450.0},
            {"KZT", 458.75}, {"UZS", 12550.0}, {"KHR", 4100.0}, {"MMK", 3200.0},
            {"LAK", 19500.0}, {"YER", 250.00}, {"SLL", 23000.0}, {"BND", 1.34},
            {"FJD", 2.22}, {"PGK", 3.57}, {"TOP", 2.35}, {"WST", 2.75},
            {"VUV", 118.75}, {"XCD", 2.70}, {"TTD", 6.80}, {"JMD", 153.50},
            {"BSD", 1.00}
        };
    }

    public:
    CurrencyConverter() {
        loadExchangeRates();
    }

    double convert(const string& fromCurrency, const string& toCurrency, double amount) {
        if (exchangeRates.find(fromCurrency) == exchangeRates.end() ||
            exchangeRates.find(toCurrency) == exchangeRates.end()) {
            throw invalid_argument("Invalid currency code!");
        }
        double baseAmount = amount / exchangeRates[fromCurrency];
        return baseAmount * exchangeRates[toCurrency];
    }
};

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
