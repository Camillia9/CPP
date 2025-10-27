#include "MutantStack.hpp"

int main() {
{
	std::cout << "~~~ Main subject ~~~" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // [...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
}
{
	std::cout << "\n~~~ TEST + ~~~" << std::endl;
	MutantStack<int>mstack;
	
	std::cout << mstack.empty() << std::endl;
	mstack.push(5);
	mstack.push(10);
	mstack.push(15);
	std::cout << mstack.empty() << std::endl;
	std::cout << "La pile:" << std::endl;
	mstack.afficher();
	std::cout << "\nLe Top: " << mstack.top() << std::endl;
	std::cout << "supression du top\n" << std::endl;
	mstack.pop();
	std::cout << "La pile:" << std::endl;
	mstack.afficher();
	std::cout << "Taille de la pile: " << mstack.size() << std::endl;
	
}
    return 0;
}
