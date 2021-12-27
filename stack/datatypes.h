#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef void *TYPE; // void pointer defined as TYPE
typedef enum{FALSE, TRUE} BOOL;

struct STRSTACKNODE
{
    TYPE data;
    struct STRSTACKNODE *prev;
};

typedef struct STRSTACKNODE *NODE;

#define int_val(e) (*((int *)e))
#define float_valr(e) (*((float *)e))
#define double_val(e) (*((double *)e))
#define char_val(e) (*((char *)e))
#define str_val(e) ((*e))


TYPE int_create(int);
TYPE float_create(float);
TYPE double_create(double);
TYPE char_create(char);
TYPE string_create(char *);

#endif //DATATYPES_H_