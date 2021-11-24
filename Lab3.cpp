#include <stdio.h>
#include <getopt.h>
#include <string.h>
//Regina Sliusar IV-93 
int main(int argc, char **argv) {

    const char *shortOptions = "hvl:";

    static struct option longOptions[] = {
    	{"list",    required_argument, 0, 'l'},
    	{"version", no_argument,       0, 'v'},
        {"help ",    no_argument,       0, 'h'}, 
        {0, 0, 0},
    };
    const char *helpOption = "Program options:\n"
    "-l[a,b,c,d...] is list\n"
    "-v or --version is version\n"
    "-h or --help is help\n";
    bool h_bool, v_bool, l_bool = false;
    int index, code;
    while ((code = getopt_long(argc, argv, shortOptions, longOptions, &index)) != -1) {
        switch (code) {
            case 'h': {
                if (!h_bool) {
                    h_bool = true;
                    printf("%s\n", helpOption);
                }
                break;
            }
            case 'l': {
                if (!l_bool) {
                    char *args;
                    printf("List:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    l_bool = true;
                }
                break;
            }
            case 'v': {
                if (!v_bool) {
                    v_bool = true;
                    printf("2021.2.0.3\n");
                }
                break;
            }
            default: {
                printf("Mistake!\n");
                return 0;
            }
        }
    }
    return 0;
}
