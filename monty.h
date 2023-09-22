#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list nd structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - str and its fttion
 * @str: the str
 * @f: fttion to handle the str
 *
 * Description: str and its fttion
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *str;
        void (*f)(stack_t **stack, unsigned int nub);
} instruction_t;

extern stack_t *hd;
typedef void (*str_ft)(stack_t **, unsigned int);


void fctAdd(stack_t **, unsigned int);
void fctSub(stack_t **, unsigned int);
void fctDiv(stack_t **, unsigned int);
void fctMul(stack_t **, unsigned int);
void fctMod(stack_t **, unsigned int);
void filestr(char *nfilem);
int filePL(char *buf, int nub, int mat);
void fileRD(FILE *);
int fileChar(FILE *);
void fileFind(char *, char *, int, int);
void prChar(stack_t **, unsigned int);
void prString(stack_t **, unsigned int);
void fctRotl(stack_t **, unsigned int);
stack_t *ndCr(int n);
void ndFr(void);
void prStack(stack_t **, unsigned int);
void addStack(stack_t **, unsigned int);
void addQueue(stack_t **, unsigned int);
void fctfile(str_ft, char *, char *, int, int);
void printPstr(stack_t **, unsigned int);
void fctPstr(stack_t **, unsigned int);
void fctNstr(stack_t **, unsigned int);
void fctSwap(stack_t **, unsigned int);
void fctError(int fctErroror_code, ...);
void fctError2(int fctErroror_code, ...);
void fctErrorStr(int fctErroror_code, ...);
void fctRotr(stack_t **, unsigned int);

#endif