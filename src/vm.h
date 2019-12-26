#ifndef _AU3_VM_H
#define _AU3_VM_H
#pragma once

#include "chunk.h"
#include "table.h"
#include "compiler.h"

typedef struct {
    au3Function *function;
    uint8_t *ip;
    au3Value *slots;
} au3CallFrame;

#define AU3_MAX_FRAMES  64
#define AU3_MAX_STACK   (AU3_MAX_FRAMES * AU3_MAX_LOCALS)

typedef struct {

    au3CallFrame frames[AU3_MAX_FRAMES];
    int frameCount;

    au3Value *top;
    au3Value stack[AU3_MAX_STACK];

    au3Table strings;
    au3Table globals;
    au3Object *objects;

} au3VM;

typedef enum {
    AU3_OK = 0,
    AU3_COMPILE_ERROR,
    AU3_RUNTIME_ERROR
} au3Status;

au3VM *au3_create();
void au3_close(au3VM *vm);
au3Status au3_interpret(au3VM *vm, const char *source);

#endif
