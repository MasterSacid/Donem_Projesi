#ifndef NARRATIVE
#define NARRATIVE
#include "console.h"

typedef struct dialog{
    message message;
    int duration;
    char clear;
}dialog,*pDialog;

void printSequence(HANDLE stdOut, dialog sequence[]);

int dialogChoice(HANDLE stdOut, HANDLE stdIn, wchar_t string[], wchar_t opts[][300], int optCount);

#endif