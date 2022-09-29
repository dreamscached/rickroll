//
// Created by dreamscached on 21.9.22.
//

#include <iostream>
#include <CLI/CLI.hpp>
#include "urlopen.hpp"
#include "const.hpp"

int main(int argc, char **argv) {
    CLI::App app{"open a rickroll link in default browser"};
    CLI11_PARSE(app, argc, argv)

    if (!urlopen(RRCXX_RICK_URL)) {
        std::cerr << "error: could not open video url." << std::endl;
        return 1;
    }

    return 0;
}