#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to initialize the exchange rates
unordered_map<string, double> initializeExchangeRates() {
    unordered_map<string, double> Rates;
    Rates["INR"] = 82.50; 
    Rates["GBP"] = 0.80;
    Rates["SAR"] = 3.75;
    Rates["AED"] = 3.67;
    Rates["CAD"] = 1.35;
    Rates["AUD"] = 1.50;
    Rates["NZD"] = 1.65;
    Rates["EUR"] = 0.92;
    Rates["RUB"] = 75.00;
    return Rates;
}

// Function to convert USD to target Currency
double convertCurrency(double amount, const string& targetCurrency, const unordered_map<string, double>& Rates) {
    auto it = Rates.find(targetCurrency);
    if (it != Rates.end()) {
        return amount * it->second;
    } else {
        cout << "Currency not found" << endl;
        return 0.0;
    }
}

int main() {
    unordered_map<string, double> Rates = initializeExchangeRates();
    double amount;
    string targetCurrency;

    cout << endl;
    cout << "Enter Amount in USD: ";
    cin >> amount;

    cout << "Enter target currency (e.g., CAD, INR, AUD..): ";
    cin >> targetCurrency;

    double convertedAmount = convertCurrency(amount, targetCurrency, Rates);

    if (convertedAmount != 0.0) {
        cout << "Converted Amount: " << convertedAmount << " " << targetCurrency << endl;
    }
    return 0;
}
