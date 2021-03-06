#ifndef Exception_H
#define Exception_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#define NODE_ADD_EXIST  1
typedef struct Exception Exception;
typedef Exception* ExceptionPtr;
struct Exception {
  char *msg;
  int  errorCode;
  void *data;
};
Exception *createException(char *msg, int errorCode);
void freeException(Exception *e);
void dumpException(Exception *e);

void throwException(int errorCode, char *message, ...);


#endif // Exception_H
