#include "philosophers.h"

int main(int argc, char *argv[]) {
    if ((argc != 6 && argc != 5)) {
        perror("Invalid number of arguments");
        exit(1);
    }
    parse_input(argv);
    return 0;
}