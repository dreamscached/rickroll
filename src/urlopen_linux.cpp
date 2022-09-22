//
// Created by dreamscached on 21.9.22.
//

#ifdef __linux__

#include <cstdlib>
#include "urlopen.hpp"

bool urlopen(const std::string &url) {
    // FIXME: this isn't reliable, need to cli encode this so this prevents globbing
    return system(("xdg-open " + url).c_str()) != 0;
}

#endif