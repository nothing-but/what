#ifndef ORDERED_ARRAY_H_laokjsdnbudjllvfidkfmqm
#define ORDERED_ARRAY_H_laokjsdnbudjllvfidkfmqm

/**An array of any number of elements of any kind, sorted in non descending order
  * according to a specific precedence relation.
  */
typedef struct _SortedArray SortedArray;

/**It creates an empty sorted array and returns the created sorted array.
 * It accepts as input a pointer to a function implementing the 
 * precedence relation between the array elements. 
 * Such a function must accept as input two pointers to elements and
 * return 0 iff the first element does not precede the second one and
 * a number different from zero otherwise.
 * The input parameter cannot be NULL.
*/
SortedArray *sorted_array_create(int (*precedes)(const void*,const void*));

/**It accepts as input a pointer to a sorted array and it returns 1 iff
 * the sorted array is empty (0 otherwise).
 * The input parameter cannot be NULL.
 */
int sorted_array_is_empty(const SortedArray *);

/**It accepts as input a pointer to a sorted array and it
 * returns the number of elements currently stored into the array.
 * The input parameter cannot be NULL.
 */
unsigned long sorted_array_size(const SortedArray *);

/**It accepts as input a pointer to a sorted array and a pointer to an element. It adds
 * the element to the sorted array in the right position. 
 * The input parameters cannot be NULL.
 * No copy of the element to be added is created. Thus, any change to an inserted
 * element while it belongs to the sorted array may destroy the actual array order.
 */
void sorted_array_add(SortedArray *, const void*);

/**It accepts as input a pointer to a sorted array and an integer "i" and
 *it returns the pointer to the i-th element of the sorted array
 * The first parameter cannot be NULL; the second parameter must be a valid position 
 * within the sorted array.
 */
const void* sorted_array_get(const SortedArray *, unsigned long);

/**It accepts as input a pointer to a sorted array and 
 * it frees the memory allocated to store the sorted array. 
 * It does not free the memory allocated to store the array elements,
 * since managing that memory is responsibility of the function(s) using the
 * library (moreover such memory may also not have been dymamically allocated).
 * The input parameter cannot be NULL.
 */
void sorted_array_free_memory(SortedArray *);

/**
* ...function for deleting elements non implemented in this toy example...
 */

#endif /* ORDERED_ARRAY_H_laokjsdnbudjllvfidkfmqm */

