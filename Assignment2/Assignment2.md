# CS205 C/ C++ Programming - Lab Assignment X

**Name**: 唐千栋（Qiandong Tang） 

**SID**: 11612730

## Part 1 - Analysis

> 

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

int main() {
    const char *command[] = {"start", "stop", "restart", "status", "exit"};
    char str[100];
    while (true) {
        scanf("%s", str);
        int i;
        int len = strlen(str);
        for (int j = 0; j < len; j++) {
            str[j] = tolower(str[j]);
        }
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
Input: Shenzhen
	   22.55 114.1
	   Beijing
	   39.9139 116.3917
Output: 
```



![make and run](/Users/macbook/Downloads/screenshot.png)

## Part 4 - Difficulties & Solutions

1. 