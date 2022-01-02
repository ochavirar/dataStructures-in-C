#ifndef DATATYPES_H_
#define DATATYPES_H_

/**
 * @brief 
 * Declaration of a primitive type to use the BOOL word, as well as the TRUE and FALSE values
 */
typedef enum{FALSE=0, TRUE} BOOL;
/**
 * @brief 
 * Declaration of a void primitive to be used as a primitive type for any kind of data.
 */
typedef void *TYPE;

/**
 * @brief 
 * Singly linked list node structure, which includes a pointer to the next element and a data slot.
 */
struct STRSINGLYLINKEDLISTNODE
{
    TYPE data;
    struct STRSINGLYLINKEDLISTNODE *next;
};

typedef struct STRSINGLYLINKEDLISTNODE *SLLISTNODE; // Primitive type NODE for singly linked list declaration

// Creation of any primitive type using void pointers
TYPE int_create(int);
TYPE float_create(float);
TYPE double_create(double);
TYPE char_create(char);
TYPE str_create(char *);

//Display any primitive type from a void pointer which previously got a value from a TYPE function (declared above)
#define int_val(e) (*((int *) e))
#define float_val(e) (*((float *) e))
#define double_val(e) (*((double *) e))
#define char_val(e) (*((char *) e))
#define str_val(e) ((*e))

#endif //DATATYPES_H_