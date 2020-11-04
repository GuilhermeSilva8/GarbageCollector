#include "libCL.h"

struct object *malloc2(){  // aloca a struct
	struct object *aux = (struct object *) malloc(sizeof(struct object));
	aux->cont = 1;
	return aux;
}

void atrib(int x, struct object *p){  // coloca o valor na �rea de endere�o passada
	p->value = x;
}

void statusdeclaracao(struct object *aux, FILE *fp){

    fprintf(fp, "Foi declarado o ponteiro no endereco %d\n\n", aux);

}

void status(struct object *aux, FILE *fp){  // mostra o estado da mem�ria

        fprintf(fp, "O ponteiro agora aponta para o endereco %d do heap\n", aux);
        fprintf(fp, "O ponteiro tem valor %d\n", aux->value);
        fprintf(fp, "O endereco %d agora tem %d apontamento(s)\n\n", aux, aux->cont);

}

struct object *atrib2(struct object **p, struct object **q, FILE *fp){   // realiza a atribui��o de ponteiros
	struct object *temp;  //vari�vel tempor�ria para armazenar o endere�o que mudou seu apontamento
	if(q != NULL){
        temp = (*p);
        (*p) = (*q);
        (*q)->cont++;
        temp->cont--;

        if (temp->cont==0){
            fprintf(fp, "A area %d agora tem 0 apontamentos e foi liberada\n", temp);
            free(temp);
        }
        return (*q);
	}else{
       temp = (*p);
       (*p) = NULL;
       temp->cont--;
       if (temp->cont==0){
            fprintf(fp, "A area %d agora tem 0 apontamentos e foi liberada\n", temp);
            free(temp);
        }
	   return NULL;
	}
}
