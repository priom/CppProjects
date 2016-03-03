#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int bin2dec(string bin);
string dec2bin(int dec);
string dec2oct(int dec);
string bin2oct(string bin);
int oct2dec(int oct);
string oct2bin(int oct);

int main() {
  cout << "Welcome to Binary to Decimal Converter!!\n\n";
  cout << "Type 1 to convert binary to decimal\nType 2 to convert decimal to binary\nType 3 to convert decimal to octal\nType 4 to convert binary to octal\nType 5 to convert octal to decimal\nType 6 to convert octal to binary: ";

// Declare variables
  string b;
  int c, d, o;
  cin >> c;

  if (c == 1) {
    cout << "Enter a binary number: ";
    cin >> b;
    cout << b << " (base 2) = " << bin2dec (b) << " (base 10)\n";
  }
  else if (c == 2) {
    cout << "Enter a decimal number: ";
    cin >> d;
    cout << d << " (base 10) = " << dec2bin(d) << " (base 2)\n";
  }
  else if (c == 3) {
    cout << "Enter a decimal number: ";
    cin >> d;
    cout << d << " (base 10) = " << dec2oct(d) << " (base 8)\n";
  }
  else if (c == 4) {
    cout << "Enter a binary number: ";
    cin >> b;
    cout << b << " (base 2) = " << bin2oct(b) << " (base 8)\n";
  }
  else if (c == 5) {
    cout << "Enter a octal number: ";
    cin >> o;
    cout << o << " (base 8) = " << oct2dec(o) << " (base 10)\n";
  }
  else if (c == 6) {
    cout << "Enter a octal number: ";
    cin >> o;
    cout << o << " (base 8) = " << oct2bin(o) << " (base 2)\n";
  }
}

//  binary to decimal function
int bin2dec(string bin) {
  int r = 0;

  if (bin.size() > 31) {
    cout << "Invalid input: " + bin + " : length greater than 31 characters.\n";
  }
  else {
    for (int i = 0; i < bin.size(); i++) {
      if (bin.at(i) == '1') {
        r = (r * 2) + 1;
      }
      else if (bin.at(i) == '0') {
        r = (r * 2);
      }
      else {
        r = -1;
      }
    }
    return r;
  }
  return 0;
}

// decimal to binary function
string dec2bin(int dec) {
  string res = "";
  if (dec == 0) {
    res = "0";
  }
  else {
    while (dec > 0) {
      int rem = dec % 2;
      res = to_string(rem) + res;
      dec = dec / 2;
    }
  }
  return res;
}

// decimal to octal function
string dec2oct(int dec) {
  string val;

  while (dec > 0) {
    int div = dec % 8;
    val = to_string(div) + val;
    dec /= 8;
  }
  return val;
}

// binary to octal function
string bin2oct(string bin) {
  int b2d = bin2dec(bin);
  string d2o = dec2oct(b2d);
  return d2o;
}

// octal to decimal function
int oct2dec(int oct) {
  int result=0, i=0, rem;

  while (oct != 0) {
    rem = oct % 10;
    oct /= 10;
    result += rem * pow(8,i);
    ++i;
  }

  return result;
}

// octal to binary function
string oct2bin(int oct) {
  int o2d = oct2dec(oct);
  string d2b = dec2bin(o2d);
  return d2b;
}


