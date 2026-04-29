#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CAPACITY 10  

typedef struct {
    char buf[CAPACITY];
    int head;   
    int tail;   
    int count;  
    int capacity; 
} CircBuf;


void cb_init(CircBuf *c) {
    c->head = 0;
    c->tail = 0;
    c->count = 0;
    c->capacity = CAPACITY;
}


int cb_is_empty(CircBuf *c) {
    return c->count == 0;
}


int cb_is_full(CircBuf *c) {
    return c->count == c->capacity;
}


int cb_write(CircBuf *c, char ch) {
    if (cb_is_full(c)) return -1; 
    c->buf[c->tail] = ch;
    c->tail = (c->tail + 1) % c->capacity;
    c->count++;
    return 0;
}


int cb_read(CircBuf *c, char *pch) {
    if (cb_is_empty(c)) return -1; 
    *pch = c->buf[c->head];
    c->head = (c->head + 1) % c->capacity;
    c->count--;
    return 0;
}

int main(void) {
    CircBuf cb;
    cb_init(&cb); 

    char name[200];
    printf("malek alhamoud");
    
    
    if (!fgets(name, sizeof(name), stdin)) {
        return 1;  
    }
    
  
    name[strcspn(name, "\n")] = '0'; 
    
    printf("Hi %s\n", name);

     
    for (int i = 0; i < strlen(name); i++) {
        if (cb_write(&cb, name[i]) == -1) {
            printf("Overflow:\n");
            break;
        }
    }

    
    char ch;
    while (cb_read(&cb, &ch) != -1) {
        printf("complet read : %c\n", ch);
    }

    return 0;
}
