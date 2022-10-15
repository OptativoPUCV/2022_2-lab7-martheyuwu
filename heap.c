#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    if (pq->size==0)
      return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
    heapElem *aux=(nodo*)malloc(sizeof(nodo));
    pq->heapArray[pq->size].data=data;
    pq->heapArray[pq->size].priority=priority;
    pq->size++;
    while (1){
      if (pq->heapArray[pq->size-3/2].priority<pq->heapArray[pq->size-2].priority){
        aux=pq->heapArray[pq->size-3/2];
        pq->heapArray[pq->size-3/2]=pq->heapArray[pq->size-2];
        pq->heapArray[pq->size-2]=aux;
      }
      else
        break;
    }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *crear=(Heap*)malloc(sizeof(Heap));
  crear->heapArray=(heapElem*)calloc(3,sizeof(heapElem));
  crear->size=0;
  crear->capac=3; 
  return crear;
}
