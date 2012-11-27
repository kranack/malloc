/**
 *
 * My_malloc.c
 *
 * Calesse Damien
 * Hancquart Louis
 * Groupe 3
 *
 * 13/11/2012
 *
 **/
#define FALSE	0
#define TRUE	1


extern void *my_malloc (unsigned size);
extern void my_free (void *ptr);

/*definition d'une structure bloc de memoire */ 
typedef struct Bloc {
    char *adresse;
    int taille;
    char *suivant;
  } Bloc;
Bloc bloc;



