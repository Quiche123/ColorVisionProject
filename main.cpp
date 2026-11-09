#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>

class Color {
    public:
        std::string colorName;
        std::string hexCode;
        int redVal;
        int greenVal;
        int blueVal;
        float grayVal;
};

bool validHex(std::string testHex) {
  if (testHex.length() != 7 || testHex.at(0) != '#') {
    return false;
  }
  for (int i = 1; i < 7; i++) {
    if ( (testHex.at(i) < '0' || testHex.at(i) > '9') &&
    (testHex.at(i) < 'A' || testHex.at(i) > 'F') &&
    (testHex.at(i) < 'a' || testHex.at(i) > 'f') ) {
      return false;
    }
  }
  return true;
}

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

void getColorVal(Color& newColor) {
  newColor.redVal = hexTranslate(newColor.hexCode.substr(1,2));
  newColor.greenVal = hexTranslate(newColor.hexCode.substr(3,2));
  newColor.blueVal = hexTranslate(newColor.hexCode.substr(5,2));
  newColor.grayVal = (newColor.redVal) * 0.299 + (newColor.greenVal) * 0.587 + (newColor.blueVal) * 0.114;
  return;
}


int main() {
    
  std::string tempConvert;
  Color colorOne;
  Color colorTwo;
  float avgDiff;
  bool validEntry = false;
  std::vector<Color> colorList;

  do {
    std::cout << "Enter the first color's name (no spaces): ";
    std::cin >> colorOne.colorName;
    validEntry = true;
    for (Color x : colorList) {
      if(x.colorName == colorOne.colorName) {
        validEntry = false;
      }
    }
    if (!validEntry) {
      std::cout << "This name is already in use. Please enter a new name.\n";
    }
  } while(!validEntry);
  validEntry = false;

  do {
    std::cout << "Enter the first color's hex code (i.e. '#c4728b'): ";
    std::cin >> colorOne.hexCode;
    validEntry = validHex(colorOne.hexCode);
    if (!validEntry) {
      std::cout << "Your entry is invalid. Please enter the hex code according to the format given.\n";
    }
  } while(!validEntry);
  validEntry = false;

  std::cout << "So, your first color is " << colorOne.colorName << " and it's hex code is " << colorOne.hexCode << "\n";
  getColorVal(colorOne);

  colorList.push_back(colorOne);
  std::ofstream FileWrite;
  FileWrite.open("colordata.txt", std::ios::app);
  FileWrite << colorOne.colorName << " " << colorOne.hexCode << " " <<
  colorOne.redVal << " " << colorOne.greenVal << " " <<
  colorOne.blueVal << " " << colorOne.grayVal << "\n";
  FileWrite.close();

  do {
    std::cout << "Enter the second color's name (no spaces): ";
    std::cin >> colorTwo.colorName;
    validEntry = true;
    for (Color x : colorList) {
      if(x.colorName == colorOne.colorName) {
        validEntry = false;
      }
    }
    if (!validEntry) {
      std::cout << "This name is already in use. Please enter a new name.\n";
    }
  } while(!validEntry);
  validEntry = false;

  do {
    std::cout << "Enter the second color's hex code (i.e. '#c4728b'): ";
    std::cin >> colorTwo.hexCode;
    validEntry = validHex(colorTwo.hexCode);
    if (!validEntry) {
      std::cout << "Your entry is invalid. Please enter the hex code according to the format given.\n";
    }
  } while(!validEntry);
  
  std::cout << "So, your second color is " << colorTwo.colorName << " and it's hex code is " << colorTwo.hexCode << "\n";
  getColorVal(colorTwo);

  colorList.push_back(colorTwo);
  FileWrite.open("colordata.txt", std::ios::app);
  FileWrite << colorTwo.colorName << " " << colorTwo.hexCode << " " <<
  colorTwo.redVal << " " << colorTwo.greenVal << " " <<
  colorTwo.blueVal << " " << colorTwo.grayVal << "\n";
  FileWrite.close();

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
