#include "zoo.h"
int main() {
    HomeZoo myZoo;

    myZoo.addRandom();
    myZoo.showAll();

    myZoo.add();
    myZoo.showAll();

    std::cout << "Editing\n";
    myZoo.edit(0);
    myZoo.showAll();

    std::cout << "Removing\n";
    myZoo.remove(0);
    myZoo.showAll();

    std::cout << "Removing all\n";
    myZoo.removeAll();
    myZoo.showAll();

    return 0;
}
