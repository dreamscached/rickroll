//
// Created by dreamscached on 21.9.22.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

#include <windows.h>
#include <shellapi.h>
#include "urlopen.hpp"

bool urlopen(const std::string &url) {
    return (INT_PTR) ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL) > 32;
}

#endif