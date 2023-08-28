#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "command.h"
#include "execute.h"
#include "parser.h"
#include "parsing.h"
#include "builtin.h"

static void show_prompt(void) {
    char dir[64];
    char user[64];
    char host[64];
    getcwd(dir, 64);
    getlogin_r(user, 64);
    gethostname(host, 64);
    printf("%s@%s:%s$ ", user, host, dir);

    fflush (stdout);
}

int main(int argc, char *argv[]) {
    pipeline pipe;
    Parser input;
    bool quit = false;

    input = parser_new(stdin);
    while (!quit) {
        show_prompt();
        pipe = parse_pipeline(input);

        /* Hay que salir luego de ejecutar? */
        quit = parser_at_eof(input);
        /*
         * COMPLETAR
         *
         */
    }
    parser_destroy(input); input = NULL;
    return EXIT_SUCCESS;
}

