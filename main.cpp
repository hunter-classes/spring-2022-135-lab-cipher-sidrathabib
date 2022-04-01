#include <iostream>
#include "funcs.h"

int main() {
  std::cout << "-----------------Welcome to Lab_Cypher-----------------\n";
  std::cout << "Wanna try solving this? (\"F Qnlmy-Djfw Fufwy\") == \"A Light-Year Apart\"";
  solve("F Qnlmy-Djfw Fufwy") == "A Light-Year Apart" ?
    std::cout << "Congrats!\n" : std::cout << "Oops!\n";
  return 0;
}