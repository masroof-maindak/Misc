#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

// Function to convert a hex string to an integer
int hexToDecimal(const std::string& hex) {
    int decimal;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> decimal;
    return decimal;
}

// Function to calculate the average hexcode
std::string calculateAverageHex(const std::vector<std::string>& hexcodes) {
    int totalRed = 0, totalGreen = 0, totalBlue = 0;
    for (const std::string& hex : hexcodes) {
        // Extract red, green, and blue components
        int red = hexToDecimal(hex.substr(0, 2));
        int green = hexToDecimal(hex.substr(2, 2));
        int blue = hexToDecimal(hex.substr(4, 2));

        totalRed += red;
        totalGreen += green;
        totalBlue += blue;
    }

    // Calculate the average
    int avgRed = totalRed / hexcodes.size();
    int avgGreen = totalGreen / hexcodes.size();
    int avgBlue = totalBlue / hexcodes.size();

    // Convert average components back to hex and construct the result
    std::stringstream result;
    result << std::setfill('0') << std::setw(2) << std::hex << avgRed;
    result << std::setfill('0') << std::setw(2) << std::hex << avgGreen;
    result << std::setfill('0') << std::setw(2) << std::hex << avgBlue;
    return result.str();
}

int main() {
    int numColors;
    std::vector<std::string> hexcodes;

    std::cout << "Enter the number of color hexcodes: ";
    std::cin >> numColors;

    if (numColors <= 0) {
        std::cout << "Invalid number of color hexcodes. Exiting the program.\n";
        return 1;
    }

    std::cout << "Enter " << numColors << " color hexcodes (e.g., FFFFFF):" << std::endl;

    // Read the hexcodes from the user
    for (int i = 0; i < numColors; ++i) {
        std::string hexcode;
        std::cin >> hexcode;

        // Convert the entered hexcode to uppercase if needed
        if (hexcode.length() == 6) {
            for (char& c : hexcode) {
                c = toupper(c);
            }
        }

        hexcodes.push_back(hexcode);
    }

    // Calculate the average hexcode
    std::string averageHex = calculateAverageHex(hexcodes);

    std::cout << "Average hexcode: " << averageHex << std::endl;

    return 0;
}
