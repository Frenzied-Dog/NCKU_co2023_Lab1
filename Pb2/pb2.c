#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* forward declaration */
int cmd_q(char*);
int cmd_help(char*);

typedef struct {
    char* name;
    char* description;
    int (*handler)(char*);  // function pointer
} cmd_t;

cmd_t cmd_table[] = {
    {"q", "exit the interactive interface", &cmd_q},
    {"help", "print useful information about supported commands", &cmd_help},
};

#define ARRLEN(s) (sizeof(s) / sizeof(*s))
#define NUM_CMD ARRLEN(cmd_table)

int cmd_q (char* args) { return -1; }

int cmd_help(char* args) {
    if (args == NULL) {
        for (int i = 0; i < NUM_CMD; i++) {
            printf("%s: %s\n", cmd_table[i].name, cmd_table[i].description);
        }
        return 0;
    }

    int i;
    for (i = 0; i < NUM_CMD; i++) {
        if (strcmp(args, cmd_table[i].name) == 0) {
            printf("%s\n", cmd_table[i].description);
            break;
        }
    }
    if (i == NUM_CMD) {
        printf("%s\n", "help: Unknown command!");
    }
    return 0;
}

char* rl_gets(void) {
    static char* line = NULL;  // note this is static variable in a function

    if (line) {
        free(line);
        line = NULL;
    }

    line = readline("(CO2023) ");
    if (line && *line) {
        add_history(line);
    }

    return line;
}

int main(void) {
    for (char* read_line; (read_line = rl_gets()) != NULL;) {
        char* read_line_end = read_line + strlen(read_line) + 1;

        char* cmd = strtok(read_line, " ");
        if (cmd == NULL) {
            /* empty input -> continue and read new line */
            continue;
        }

        char* args = read_line + strlen(cmd) + 1;
        if (args >= read_line_end) {
            args = NULL;
        }

        int i;
        for (i = 0; i < NUM_CMD; i++) {
            if (strcmp(cmd, cmd_table[i].name) == 0) {
                if (cmd_table[i].handler(args) < 0) {
                    return 0;
                }
                break;
            }
        }
        if (i == NUM_CMD) {
            printf("%s\n", "Unsupported command!");
        }
    }
}
