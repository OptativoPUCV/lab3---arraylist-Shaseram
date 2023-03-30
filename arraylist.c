#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *list = NULL;
  list = (ArrayList *) malloc(sizeof(ArrayList));
  if (list == NULL) exit(EXIT_FAILURE);
  list->data = (void **) calloc(2, sizeof(void*));
  list->capacity = 2;
  list->size = 0;
  
  return list;
}

void append(ArrayList * l, void * data){
  if (l->size == l->capacity)
  {
    l->capacity *= 2;
    l->data = (void **) realloc(l->data,l->capacity * sizeof(void*));
  }
  l->data[l->size] = data;
  l->size++;
}

void push(ArrayList * l, void * data, int i){
  if (i > l->size) return;

  if (l->size == l->capacity)
  {
    l->capacity *= 2;
    l->data = (void **) realloc(l->data,l->capacity * sizeof(void*));
  }
  
  for (int u = l->size-1 ; u >= i ; u--)
    {
      l->data[u+1] = l->data[u];
    }

  l->data[i] = data;
  l->size++;
  
  return;
}

void* get(ArrayList * l, int i){
  if (i >= l->size) return NULL;

  if (i < 0) return l->data[i+l->size];

    return l->data[i];
}

void* pop(ArrayList * l, int i){
  void * auxilio = NULL;
  int j = i;
  if (i < 0)
  {
    auxilio = l->data[i+l->size];
    j = i+l->size;
  }
  
  for (int a = j ; a < l->size-1 ; a++)
    {
      l->data[a] = l->data[a+1];
    }
  l->size--;
  
    return auxilio;
}



int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
