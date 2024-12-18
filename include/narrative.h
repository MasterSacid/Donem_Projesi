#pragma once
#include "console.h"

typedef struct dialog{
    message message;
    int duration;
    char clear;
}dialog,*pDialog;

void printSequence(dialog sequence[]);
void printSequenceOnDialog(dialog sequence[]);
int dialogChoice(wchar_t string[], wchar_t opts[][300], int optCount);
