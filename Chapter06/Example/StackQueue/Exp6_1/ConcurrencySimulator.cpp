#include <ctype.h>
#include <stdio.h>

typedef enum {
    FMT_ASSIGN = 0, /* = */
    FMT_PRINT, /* print */
    FMT_LOCK, /* lock */
    FMT_UNLOCK, /* unlock */
    FMT_END, /* end */
    FMT_BUTT
} FMT_CODE;

int time[FMT_BUTT];
int quota;

#define PROGRAM_NUM 10000
#define PROGRAM_LEN 10

char program[PROGRAM_NUM][PROGRAM_LEN];
int lines[PROGRAM_NUM];

int value[26];

#define MAX_QUEUE_SIZE 1000

int waitQueue[MAX_QUEUE_SIZE];
int waitFront = 0, waitTail = 0;

int stopQueue[MAX_QUEUE_SIZE];
int stopFront = 0, stopTail = 0;

bool isLocked = false;

void runProgram(int progId)
{
    int tmpQuota = quota;

    while (tmpQuota > 0) {
        char *currProg = program[lines[progId]];
        switch (currProg[2]) {
            case '=': 
                value[currProg[0] - 'a'] = isdigit(currProg[5]) ? (currProg[4] - '0') * 10 + (currProg[5] - '0') : currProg[4] - '0';
                tmpQuota -= time[FMT_ASSIGN];
                break;
            
            case 'i':
                printf("program %d, line %d: %c = %d\n", progId + 1, lines[progId], currProg[6], value[currProg[6] - 'a']);
                tmpQuota -= time[FMT_PRINT];
                break;

            case 'c':
                tmpQuota -= time[FMT_LOCK];
                if (isLocked == true) {
                    stopQueue[stopTail++] = progId;
                    return;
                } else {
                    isLocked = true;
                }
                break;

            case 'l':
                isLocked = false;
                tmpQuota -= time[FMT_UNLOCK];
                if (stopFront != stopTail) {
                    int p = stopQueue[stopFront++];
                    waitQueue[--waitFront] = p;
                }
                break;

            case 'd':
                return;
        }

        lines[progId]++;
    }
    
    waitQueue[waitTail++] = progId;
}

int main(int argc, char **argv)
{
    int caseNum;
    scanf("%d", &caseNum);

    int line = 0;
    while (caseNum--) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < 5; i++) {
            scanf("%d", &time[i]);
        }

        scanf("%d", &quota);

        for (int i = 0; i < n; i++) {
            gets(program[line++]);
            lines[i] = line - 1;
            while (program[line - 1][2] != 'd') {
                gets(program[line++]);
            }

            waitQueue[waitTail++] = i;
        }

        while (waitFront != waitTail) {
            int front = waitQueue[waitFront++];
            runProgram(front);
        }

        if (caseNum) {
            printf("\n");
        }
    }

    return 0;
}
