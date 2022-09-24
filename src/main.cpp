//
// Created by dreamscached on 21.9.22.
//

#include <iostream>
#include "urlopen.hpp"
#include "const.hpp"

int main(int argc, char **argv) {
    if (!urlopen(RRCXX_RICK_URL)) {
        std::cerr << "error: could not open video url." << std::endl;
        return 1;
    }

    return 0;
}