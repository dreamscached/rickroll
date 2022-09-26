//
// Created by dreamscached on 21.9.22.
//

#ifdef __linux__

#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "urlopen.hpp"

bool urlopen(const std::string &url) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return false;
    }

    if (pid == 0) {
        const std::vector<std::string> args{"xdg-open", url};
        std::vector<const char*> argv;

        for (const std::string &s : args) {
            argv.push_back(s.data());
        }
        argv.push_back(nullptr);
        argv.shrink_to_fit();

        if (execvp(argv[0], const_cast<char* const*>(argv.data())) == -1) {
            perror("execvp");
            exit(1);
        }

        exit(0);
    } else {
        int status;
        do {
            pid_t w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
            if (w == -1) {
                perror("waitpid");
                return false;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        return true;
    }
}

#endif