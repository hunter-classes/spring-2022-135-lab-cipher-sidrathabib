#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include "funcs.h"

std::string solve(std::string encryptString) {
  std::string rotation = "";
  std::string output = "";
  
  std::vector<double> currentFreq(26); 
  double closest = 0.0;

  const double engVer[26] = {.084966, .020720, .045388, .033844, .111607,
  .018121, .024705, .030034, .075448, .001964, .011016, .054893, .030129,
  .066544, .071635, .031671, .001962, .075809, .057351, .069509, .036308,
  .010074, .012899, .002902, .017779, .002722};

  for(int i = 0; i < 26; i++) {
    rotation = decCaesar(encryptString, i);
    currentFreq = freq(rotation);
    double dist = 0;

    for (int j = 0; j < 26; j++) {
      dist += pow((currentFreq[j] - engVer[j]), 2);
    }

    if (closest == 0.0) {
      closest = dist;
      output = rotation;
    }

    if (dist < closest) {
      closest = dist;
      output = rotation;
    }
  }

  return output;
}

char decChar(char c, int rotary) {
  char output = c;
  if (!isalpha(c)) {
    return output;
  }
  if (isalpha(c)) {
    if (isupper(c)) { 
      if ((c - rotary) < 65) { 
        output = 'A' + (c - rotary - 65 + 26); 
      } 
      else {
        output = c - rotary;
      }
    } 
    else if (islower(c)) {
      if ((c - rotary) < 97) { 
        output = 'a' + (c - rotary - 97 + 26); 
      } 
      else {
        output = c - rotary;
      }
    }
  }
  return output;
}

std::vector<double> freq(std::string textCyph) {
  std::vector<double> freq (26, 0.0);
  int len = textCyph.length();

  for(int i = 0; i < len; i++) {
    if (isalpha(textCyph[i])) { 
      int index = 0;

      if (isupper(textCyph[i])) {
        index = int(textCyph[i]) - 65; 
      } 
      else {
        index = int(textCyph[i]) - 97; 
      }

      freq[index] += 1;
    }
  }

  for(int i = 0; i < 26; i++) {
    freq[i] /= len;
  }

  return freq;
}

std::string decCaesar(std::string textCyph, int rotary) {
  int cipher_len = textCyph.length();
  for (int i = 0; i < cipher_len; i++) {
    textCyph[i] = decChar(textCyph[i], rotary);
  }
  return textCyph;
}