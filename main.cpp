#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>

class ColorInfo {
    public:
        std::string colorName;
        std::string hexCode;
        int redVal;
        int blueVal;
        int greenVal;
        float grayVal;
};

int hexTranslate(std::string twoDigitCode) {
    char sixteensPlace = twoDigitCode[0];
    char onesPlace = twoDigitCode[1];
    int decimalVal = 0;

    switch(sixteensPlace) {
        case '0':
            decimalVal += (0*16);
            break;
        case '1':
            decimalVal += (1*16);
            break;
        case '2':
            decimalVal += (2*16);
            break;
        case '3':
            decimalVal += (3*16);
            break;
        case '4':
            decimalVal += (4*16);
            break;
        case '5':
            decimalVal += (5*16);
            break;
        case '6':
            decimalVal += (6*16);
            break;
        case '7':
            decimalVal += (7*16);
            break;
        case '8':
            decimalVal += (8*16);
            break;
        case '9':
            decimalVal += (9*16);
            break;
        case 'a':
        case 'A':
            decimalVal += (10*16);
            break;
        case 'b':
        case 'B':
            decimalVal += (11*16);
            break;
        case 'c':
        case 'C':
            decimalVal += (12*16);
            break;
        case 'd':
        case 'D':
            decimalVal += (13*16);
            break;
        case 'e':
        case 'E':
            decimalVal += (14*16);
            break;
        case 'f':
        case 'F':
            decimalVal += (15*16);
            break;
        default:
            decimalVal += (0*16);
            break;
    }

    switch(onesPlace) {
        case '0':
            decimalVal += 0;
            break;
        case '1':
            decimalVal += 1;
            break;
        case '2':
            decimalVal += 2;
            break;
        case '3':
            decimalVal += 3;
            break;
        case '4':
            decimalVal += 4;
            break;
        case '5':
            decimalVal += 5;
            break;
        case '6':
            decimalVal += 6;
            break;
        case '7':
            decimalVal += 7;
            break;
        case '8':
            decimalVal += 8;
            break;
        case '9':
            decimalVal += 9;
            break;
        case 'a':
        case 'A':
            decimalVal += 10;
            break;
        case 'b':
        case 'B':
            decimalVal += 11;
            break;
        case 'c':
        case 'C':
            decimalVal += 12;
            break;
        case 'd':
        case 'D':
            decimalVal += 13;
            break;
        case 'e':
        case 'E':
            decimalVal += 14;
            break;
        case 'f':
        case 'F':
            decimalVal += 15;
            break;
        default:
            decimalVal += 0;
            break;
    }

    return decimalVal;
}
// Converts a two digit hexadecimal code to a decimal value


int main() {
    
    std::string tempConvert;
    ColorInfo colorOne;
    ColorInfo colorTwo;
    float avgDiff;

    std::cout << "Enter the first color's name (no spaces): ";
    std::cin >> colorOne.colorName;
    std::cout << "Enter the first color's hex code (i.e. 'c4728b'): ";
    std::cin >> colorOne.hexCode;
    std::cout << "So, your first color is " << colorOne.colorName << " and it's hex code is " << colorOne.hexCode << "\n";
    colorOne.redVal = hexTranslate(colorOne.hexCode);
    colorOne.blueVal = hexTranslate(colorOne.hexCode.substr(2,2));
    colorOne.greenVal = hexTranslate(colorOne.hexCode.substr(4,2));
    colorOne.grayVal = (colorOne.redVal) * 0.299 + (colorOne.greenVal) * 0.587 + (colorOne.blueVal) * 0.114;

    std::cout << "Enter the second color's name (no spaces): ";
    std::cin >> colorTwo.colorName;
    std::cout << "Enter the second color's hex code (i.e. 'c4728b'): ";
    std::cin >> colorTwo.hexCode;
    std::cout << "So, your second color is " << colorTwo.colorName << " and it's hex code is " << colorTwo.hexCode << "\n";
    colorTwo.redVal = hexTranslate(colorTwo.hexCode);
    colorTwo.blueVal = hexTranslate(colorTwo.hexCode.substr(2,2));
    colorTwo.greenVal = hexTranslate(colorTwo.hexCode.substr(4,2));
    colorTwo.grayVal = (colorTwo.redVal) * 0.299 + (colorTwo.greenVal) * 0.587 + (colorTwo.blueVal) * 0.114;

    avgDiff = abs(colorOne.grayVal - colorTwo.grayVal);

    if (avgDiff > 30) {
        std::cout << "Your colors are very different. There is no issue.";
    } else if (avgDiff > 10) {
        std::cout << "Your colors are somewhat different. There will likely be no issue.";
    } else {
        std::cout << "Your colors are too similar. Please change the values to make the difference more stark.";
    }

    return 0;
}
