//
// Created by dreamscached on 21.9.22.
//

#ifdef __linux__

#include <cstdlib>
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
        // TODO: Would better use an array and an execvp rather than this way of duplication.
        // This needs duplicated xdg-open string because of argv convention of having argv[0] a program name.
        if (execlp("xdg-open", "xdg-open", url.c_str()) == -1) {
            perror("execlp");
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