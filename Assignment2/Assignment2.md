# CS205 C/ C++ Programming - Lab Assignment X

**Name**: 唐千栋（Qiandong Tang） 

**SID**: 11612730

## Part 1 - Analysis

In this assignment, we need to read a command. If the command are one of start, stop, restart, status, exit, we should simply print "command \<name here\> recognized". Else we need to print "Invalid command". Furthermore, we should  use test the command in a **switch** statement, not an **if ... else if ... else if ...** structure.

Since string can not be used in switch, we can use an array of string containing the commands. For each command in the array, we compare if it is the same as the input. If the same, return the index. If not, print "Invalid command". Then we use switch to check which command it is and print it. 

We can also define a name to recognize the index of array. Like **#define START_CMD    0*** **#define STOP_CMD     1**

## Part 2 - Code

```c++
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

char* trim(char *str) {
    char *end, *sp, *ep;
    sp = str;
    end = str + strlen(str) - 1;
    int len;
    ep = end;

    while(sp <= end && isspace(*sp)) {
        sp++;
    }
    while(ep >= sp && isspace(*ep)) {
        ep--;
    }
    len = (ep < sp) ? 0 : (ep - sp) + 1;
    sp[len] = '\0';
    return sp;
}

int main() {
    const char *command[] = {"start", "stop", "restart", "status", "exit"};
    char str[100];
    while (true) {
        scanf("%s", str);
        int i;
        int len = strlen(str);
        for (i = 0; i < 5; i++) {
            if (strcmp(str, command[i]) == 0) {
                break;
            }
        }
        switch (i) {
            case START_CMD:
                printf("command %s recognized\n", command[i]);
                break;
            case STOP_CMD:
                printf("command %s recognized\n", command[i]);
                break;
            case RESTART_CMD:
                printf("command %s recognized\n", command[i]);
                break;
            case STATUS_CMD:
                printf("command %s recognized\n", command[i]);
                break;
            case EXIT_CMD:
                printf("command %s recognized\n", command[i]);
                return 0;
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }
    return 0;
}

```

## Part 3 - Result & Verification

> The verification is combined with the result queried in the website.

Test case #1:

```
Input:
start
    start
stop
sdhofa
status
exit
Output: 
command start recognized
command start recognized
command stop recognized
Invalid command
command status recognized
command exit recognized
```

![Screen Shot 2019-03-22 at 14.23.04](/Users/macbook/Desktop/Screen Shot 2019-03-22 at 14.23.04.png)

## Part 4 - Difficulties & Solutions

1. How to find two strings are the same?

   We can invoke `strcmp()` to compare two strings, if they are the same, this function return 0

2. How to define a number?

   `#define STATUS_CMD 2`




