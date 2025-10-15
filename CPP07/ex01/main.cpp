#include "iter.hpp"

template <typename T>
void print(T const & x) {
    std::cout << "[" << x << "]";
}

void increment(int& x) {
    x++;
}

void topper(char& x) {
    x = std::toupper(x);
}

void addExclamation(std::string& str) {
    str += "!";
}

int main() {
{
    std::cout << "~~~ Test INT ~~~\n";
    int numbers[] = {1, 2, 3, 4, 5};
    
	// Tableau normal
    std::cout << "Affichage:" << std::endl;
    iter(numbers, 5, print<int>);
    std::cout << std::endl;
    
    std::cout << "\nIncrément:" << std::endl;
    iter(numbers, 5, increment);
    iter(numbers, 5, print<int>);
    std::cout << std::endl;
    
    // Tableau const
    const int constNumbers[] = {10, 20, 30};
    std::cout << "\nTableau const:" << std::endl;
    iter(constNumbers, 3, print<int>);
    std::cout << std::endl;
}
{
    std::cout << "\n~~~ Test CHAR ~~~\n";
    char letters[] = {'a', 'b', 'c', 'd', 'e'};
    
	// Tableau normal
    std::cout << "Affichage:" << std::endl;
    iter(letters, 5, print<char>);
    std::cout << std::endl;
    
    std::cout << "\nToupper:" << std::endl;
    iter(letters, 5, topper);
    iter(letters, 5, print<char>);
    std::cout << std::endl;
    
    // Tableau const
    const char constLetters[] = {'K', 'o', 'X'};
    std::cout << "\nTableau const:" << std::endl;
    iter(constLetters, 3, print<char>);
    std::cout << std::endl;
}
{
    std::cout << "\n~~~ Test STRING ~~~\n";
    std::string string[] = {"coucou", "hey", "Bouboule"};
    
	// Tableau normal
    std::cout << "Affichage:" << std::endl;
    iter(string, 3, print<std::string>);
    std::cout << std::endl;
    
    std::cout << "\nExcalamtions:" << std::endl;
    iter(string, 3, addExclamation);
    iter(string, 3, print<std::string>);
    std::cout << std::endl;
    
    // Tableau const
    const std::string constString[] = {"Vroum", "La", "Voiture"};
    std::cout << "\nTableau const:" << std::endl;
    iter(constString, 3, print<std::string>);
    std::cout << std::endl;
}
    return 0;
}