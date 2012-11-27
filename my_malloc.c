/***********************
 *
 * My_malloc.c
 *
 * Calesse Damien
 * Hancquart Louis
 * Groupe 3
 *
 * 27/11/2012
 *
 **********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
	
#include "my_malloc.h"

#define SUPER	"Supercalifragilisticexpialidocious"





static char *adresse_memoire_sbrk = NULL;
static int test_sbrk_call=TRUE;


void display() {
	/*affichage des infos du bloc */
	printf("bloc: \n\tadresse: %p \n\ttaille : %d \n\tadresse du suivant: %p 	\n",bloc.adresse,bloc.taille,bloc.suivant);
}

void *my_malloc (unsigned size) {
	void *ptr;


	/****************1er appel de malloc********************/

	if(test_sbrk_call==TRUE){
		adresse_memoire_sbrk = sbrk(10000);
		ptr= adresse_memoire_sbrk;
		printf("bloc memoire en %p \n",ptr);
		test_sbrk_call=FALSE;
		
		/*Allocation dun bloc*/

		bloc.adresse=ptr;
		bloc.taille=size+sizeof(bloc);
		bloc.suivant=bloc.adresse;
		
		display();
		return ptr;
	} else {
	
		/******************2e appel de malloc********************/

		/* Recherche d'emplacement mémoire */
		if(bloc.taille > size){
		
			bloc.adresse -= size;
			bloc.taille -= size;
			bloc.suivant = bloc.adresse;
			
		} else if(bloc.taille == size) {
			return bloc.adresse;
		} else {
			
			
			test_sbrk_call = TRUE;
			return my_malloc(size);
		}
		display();
		return bloc.adresse;
	}
	

}

int main(void){ 
	void *str;
	/* Un appel direct à malloc */
	str = my_malloc(strlen(SUPER)+10);
	str = my_malloc(strlen(SUPER));
	str = my_malloc(strlen(SUPER));
	/* On libere la memoire allouee sur str est strcp*/
	my_free(str);

	exit(EXIT_SUCCESS);
}


/*Improvements 

  faire un modulo sizeof (segment) pour que la mémoire soie allouée au segment près.
  Out of bound accesses are not ckecked.
  gérer si il y a plusieurs allocations à sbrk
*/
