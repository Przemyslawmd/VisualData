
#include <cstdlib>
#include <iostream>

#include "drawer.h"


int main(void)
{
    Drawer drawer;
    
    try {
        drawer.run();
    }
    catch (const std::exception& exc) {
        std::cout << exc.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}