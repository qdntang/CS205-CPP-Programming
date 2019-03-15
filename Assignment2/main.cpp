#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define START_CMD 0
#define STOP_CMD 1
#define RESTART_CMD 2
#define STATUS_CMD 3
#define EXIT_CMD 4
using namespace std;

int main() {
    const char *command[] ={"start", "stop", "restart", "status", "exit"};
    char str[100];
    while(true) {
        scanf("%s", str);
        int i;
        for(i = 0; i < 5; i++) {
            if(strcmp(str, command[i]) == 0) {  
                break;
            }
        }
        switch(i) {
            case START_CMD:
                printf("command %s recongnized\n", command[i]);                
                break;
            case STOP_CMD:
                printf("command %s recongnized\n", command[i]);
                break;
            case RESTART_CMD:
                printf("command %s recongnized\n", command[i]);
                break;
            case STATUS_CMD:
                printf("command %s recongnized\n", command[i]);
                break;
            case EXIT_CMD:
                printf("command %s recongnized\n", command[i]);
                return 0;
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }
    return 0;
}

