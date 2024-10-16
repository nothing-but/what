#include <stdlib.h>
#include <stdio.h>
#include "sorted_array.h"

//Initial capacity for the array
#define INITIAL_CAPACITY 2


static unsigned long  get_index_to_insert(const SortedArray *sorted_array, const void* element);
static void insert_element(SortedArray *sorted_array, const void* element,unsigned long index);

//It represents the internal structure of this implementation of sorted arrays
//- array is an array of pointers to the actual elements (i.e. it physically 
//stores the pointers to the elements, not the elements themselves)
//- el_num is the number of elements currently stored in the sorted array
//- array_capacity is the current capacity of the sorted array
struct _SortedArray{
  void const** array;
  unsigned long el_num;
  unsigned long array_capacity;
  int (*precedes)(const void*,const void*);
};

SortedArray *sorted_array_create(int (*precedes)(const void*,const void*)){
  if(precedes == NULL){
    fprintf(stderr,"sorted_array_create: precedes parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  SortedArray *sorted_array = (SortedArray *)malloc(sizeof(SortedArray));
  if(sorted_array == NULL){
    fprintf(stderr, "sorted_array_create: unable to allocate memory for the sorted array");
    exit(EXIT_FAILURE);
  }
  sorted_array->array = (const void**)malloc(INITIAL_CAPACITY*sizeof(void*));
  if(sorted_array->array == NULL){
    fprintf(stderr, "sorted_array_create: unable to allocate memory for the internal array");
    exit(EXIT_FAILURE);
  }
  sorted_array->el_num = 0;
  sorted_array->array_capacity =INITIAL_CAPACITY;
  sorted_array->precedes = precedes;
  
  return(sorted_array);
}


int sorted_array_is_empty(const SortedArray *sorted_array){
  if(sorted_array == NULL){
    fprintf(stderr,"sorted_array_is_empty: sorted_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(sorted_array->el_num == 0)
    return(1);
  return(0);
}


unsigned long sorted_array_size(const SortedArray *sorted_array){
  if(sorted_array == NULL){
    fprintf(stderr,"sorted_array_size: sorted_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return(sorted_array->el_num);
}


void sorted_array_add(SortedArray *sorted_array, const void* element){
  if(sorted_array == NULL){
    fprintf(stderr,"sorted_array_add: sorted_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(element == NULL){
    fprintf(stderr,"sorted_array_add: element parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  
  if(sorted_array->el_num >= sorted_array->array_capacity){
    sorted_array->array = (const void**)realloc(sorted_array->array,2*(sorted_array->array_capacity)*sizeof(void*));
    if(sorted_array->array == NULL){
      fprintf(stderr,"sorted_array_add: unable to reallocate memory to host the new element");
      exit(EXIT_FAILURE);
    }
    sorted_array->array_capacity = 2*sorted_array->array_capacity;
  }
  
  unsigned long index = get_index_to_insert(sorted_array, element);
  
  insert_element(sorted_array,element,index);
  
  (sorted_array->el_num)++;
  
}


const void* sorted_array_get(const SortedArray *sorted_array, unsigned long i){
  if(sorted_array == NULL){
    fprintf(stderr,"sorted_array_get: sorted_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(i>=sorted_array->el_num){
    fprintf(stderr,"sorted_array_get: Index %lu is out of the array bounds",i);
    exit(EXIT_FAILURE);
  }
  return(sorted_array->array)[i];
}


void sorted_array_free_memory(SortedArray *sorted_array){
  if(sorted_array == NULL){
    fprintf(stderr,"sorted_array_free_memory: sorted_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  free(sorted_array->array);
  free(sorted_array);
}



//returns the position where the new element must be inserted
//[Commento didattico (da NON considerarsi come parte dei commenti al codice): siccome
//al momento dell'invocazione di questa funzione l'array è sempre ordinato, sarebbe
//possibile implementare questa stessa funzione con una ricerca binaria. Qui, per semplicità, si 
//propone una ricerca sequenziale. Si noti comunque che l'implementazione di 
//questa funzione con una ricerca binaria non modificherebbe la complessità computazionale
//asintotica dell'operazione di inserimento]
static unsigned long get_index_to_insert(const SortedArray *sorted_array, const void* element){
  unsigned long i = 0;
  int cont = 1;
  while(i<sorted_array->el_num && cont){
    if(sorted_array->precedes(element,(sorted_array->array)[i])){
      cont = 0;
    } else i++;
  }
  return(i);
}


//inserts the specified element in the specified ordered array at the specified
//index position
static void insert_element(SortedArray *sorted_array, const void* element,unsigned long index){
  for(unsigned long i = sorted_array->el_num;i>index;i--){
    (sorted_array->array)[i] = (sorted_array->array)[i-1];
  }
  (sorted_array->array)[index] = element;
}
