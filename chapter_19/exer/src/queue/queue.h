#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

void enqueue(int n);
int dequeue(void);
int peek(void);
int peek_end(void);
bool is_empty(void);

#endif
