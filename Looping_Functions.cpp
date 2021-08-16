// Derek Meng

// Looping_Functions.cpp

#include <iostream>
#include <sstream>

using namespace std;

bool play_game(int n) {
  cout << "Welcome to my number guessing game\n\n";

  string input_string;
  int input_int;

  for(int i = 1; i < 7; i++) {
    cout << "Enter your guess: \n"; 

    getline(cin, input_string);
    istringstream iss(input_string);
    iss >> input_int;

    cout << "You entered: " << input_int << endl;

    if(input_int == n) {
      cout << "You found it in " << i << " guess(es)." << endl;
      return true;
    }
  } 
  
  cout << "\nI'm sorry. You didn't find my number." << endl;
  cout << "It was " << n << endl;
  return false;
}

double etox(double x, size_t n) {
  if(n == 0)
	 return 0;

  double sum = 1, exp = 1, factorial = 1;

  for(size_t i = 1; i < n; i++) {
    exp *= x;
    factorial *= i; 

    sum += exp / factorial;
  }

  return sum;
}

size_t count_chars(string s, char c) {
  size_t counter = 0;

  for(size_t i = 0; i < s.length(); i++) {
    if(s[i] == c) 
      counter++;
  }

  return counter;
}

size_t gcd(size_t a, size_t b) {
  while(true) {
    if(a == 0) 
      return b;
    else if(b == 0) 
      return a;

    size_t placeholder = a;
    a = b;
    b = placeholder % b;
  }
}

string get_ap_terms(int a, int d, size_t n) {
  stringstream stream;
  int m = n;

  for(int i = 0; i < m; i++) {
    stream << a + (i * d); 

    if(i < m - 1)
      stream << ',';
  } 

  return stream.str();
}

string get_gp_terms(double a, double r, size_t n) {
  stringstream stream;
  int m = n;

  for(int i = 0; i < m; i ++) {
    double exp = 1;
    
    for(int j = 1; j <= i; j++) 
      exp *= r;
    
    stream << (a * exp); 

    if(i < m - 1)
      stream << ',';
  }

  return stream.str();
}

double get_nth_fibonacci_number(size_t n) {
  if(n < 3)
   return 1;

  double sum = 1; 
  double prev = 1;

  for(size_t i = 2; i < n; i++) {
    double placeholder = sum;
    sum += prev;
    prev = placeholder;
  }

  return sum;
}