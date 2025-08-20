#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

std::string getCurrentDate() {
    // Get the current time
    std::time_t current_time = std::time(nullptr);

    // Convert time_t to a struct tm in local time
    std::tm* time_info = std::localtime(&current_time);

    // Format the date in "YYYY/MM/DD" format
    std::string formatted_date = std::to_string(1900 + time_info->tm_year) + '/'
                               + std::to_string(1 + time_info->tm_mon) + '/'
                               + std::to_string(time_info->tm_mday);

    return formatted_date;
}

class Transaction {
    string date;
    string type; // "sales" or "purchase"
    double totalAmount;
    public:

    Transaction(std::string t=" ",int total=0){
        date=getCurrentDate();
        type=t;
        totalAmount=total;

    }
    void writeToFile() {
        ofstream outFile("Transaction_Details.txt", ios::app); // Open file in append mode

        if (!outFile.is_open()) {
            cerr << "Error: Unable to open file Transaction_Details.txt for writing." << endl;
            return;
        }

        // Write transaction data to file
        outFile << this->date << "  "
                << this->type << "  "
                << this->totalAmount << endl;

        outFile.close();
    }
};


