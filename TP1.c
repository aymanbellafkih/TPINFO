# include <stdio.h>
# include <stdlib.h>

typedef struct Noeud {
int D;
struct Noeud *Next;
} Noeud;

Noeud* cree(int valeur)
{
Noeud *P;
P=(Noeud*) malloc (sizeof(Noeud));
P-> D=valeur;
P-> Next=NULL;
return P;

}

void affiche(Noeud *head)
{
    Noeud *current=head;
    while(current!=NULL)
    {
        printf("La valeur: %d\n",current->D);
    current=current->Next;
    }

}

Noeud* ajouterD(Noeud *head, int valeur)
{
Noeud *P;
P=(Noeud*) malloc (sizeof(Noeud));
P-> D=valeur;
P-> Next=NULL;
P->Next=head;
head=P;
return head;
}

Noeud* ajouterF(Noeud *head, int valeur) {
   Noeud *P, *current;
   P = (Noeud*) malloc(sizeof(Noeud));
   if (P == NULL) {
       return NULL;
   }
   P->D = valeur;
   P->Next = NULL;

   if (head == NULL) {
       head = P;
   } else {
       current = head;
       while (current->Next != NULL) {
           current = current->Next;
       }
       current->Next = P;
   }

   return head;
}

int taille(Noeud *head)
{
   int cpt=0;
   Noeud *current;
   current=head;
   while (current->Next!=NULL)
   {
       cpt++;
        current = current->Next;
   }
return cpt;
}

Noeud* ajouterF(Noeud *head, int valeur) {
   Noeud *P, *current;
   P = (Noeud*) malloc(sizeof(Noeud));
   if (P == NULL) {
       return NULL;
   }
   P->D = valeur;
   P->Next = NULL;

   if (head == NULL) {
       head = P;
   } else {
       current = head;
       while (current->Next != NULL) {
           current = current->Next;
       }
       current->Next = P;
   }

   return head;
}

int taille(Noeud *head)
{
   int cpt=0;
   Noeud *current;
   current=head;
   while (current->Next!=NULL)
   {
       cpt++;
        current = current->Next;
   }
return cpt;
}


Noeud* insertion( Noeud *debut , int pos , int valeur ){
 Noeud *BRAIN, *SEMIBRAIN;
 int LENGHT , I = 1;
  LENGHT = TAILLE(debut) ; 
  if( pos < 1 || pos > LENGHT + 1 ){
    printf("position invalide") ;
  }
  else{
    if( !debut || pos == 1 ){
      debut = ajouterD(debut,valeur) ;
    }
    else{
      SEMIBRAIN = debut ;
      while( I < pos - 1 ){
        I++ ;
        SEMIBRAIN = SEMIBRAIN->suivant ;
      }
      if( SEMIBRAIN->suivant ){
        BRAIN = cree(valeur) ;
        if( !BRAIN ){
          exit(EXIT_FAILURE) ;
        }
        else{
          BRAIN->suivant = SEMIBRAIN->suivant ;
          SEMIBRAIN->suivant = BRAIN ;
        }
      }
      else{
        debut = ajouterF(debut,valeur) ;
      }
    }
  }
  return debut ;
}
void rechercher( Noeud *debut , int valeur ){
 Noeud *BRAIN;
  if( !debut ){
    printf("la liste est vide") ;
  } 
  else{
    BRAIN = debut ;
    while( BRAIN && BRAIN->valeur != valeur ){
      BRAIN = BRAIN->suivant ;                               
    } 
    if( BRAIN ){
      printf("la valeur existe dans le tableau ") ;
    }
    else{
      printf("la valeur n'existe pas dans le tableau") ;
    }
  }
}
Noeud* suppressionD( Noeud *debut ){
 Noeud *BRAIN;
  if( !debut ){
    printf("rien a supprimmer") ;
  } 
  else{
    BRAIN = debut ;
    debut = debut->suivant ;
    free(BRAIN) ;
  }
 return debut ; 
}
Noeud* suppressionF( Noeud *debut ){
 Noeud *BRAIN, *SEMIBRAIN;
 if( !debut ){
   printf("la liste est vide") ;
 } 
 else{
  if( !(debut->suivant) ){
    free(debut) ;
    debut = NULL ; 
  }
  else{
   SEMIBRAIN = debut ;
   while( SEMIBRAIN->suivant->suivant ){
    SEMIBRAIN = SEMIBRAIN->suivant ;
   }
   free(SEMIBRAIN->suivant) ;
   SEMIBRAIN->suivant = NULL ;
  }
 }
 return debut ; 
}
Noeud *suppressionP( Noeud *debut , int pos ){
 Noeud *BRAIN, *SEMIBRAIN;
 int LENGHT, I; 
  LENGHT = TAILLE(debut) ;
  if( pos < 1 || pos > LENGHT ){
    printf("position invalide") ;
  }
  else{
    if( pos == 1 ){
      debut = suppressionD(debut) ;
    }
    else{
      BRAIN = debut ;
      I = 1 ;
      while( I < pos - 1 ){
        BRAIN = BRAIN->suivant ;
      }
      SEMIBRAIN = BRAIN->suivant ;
      BRAIN->suivant = BRAIN->suivant->suivant ;
      free(SEMIBRAIN) ;
    }
  }
 return debut ; 
}
void modifierD( Noeud *debut , int valeur ){
 debut->valeur = valeur ;
}
void modifierF( Noeud *debut , int valeur ){
 Noeud *BRAIN;
  if( !debut ){
    printf("la liste est vide") ;
  }
  else{
    BRAIN = debut ;
    while( BRAIN->suivant ){
      BRAIN = BRAIN->suivant ;
    }
    BRAIN->valeur = valeur ;
  }
}
void modifierP( Noeud *debut , int pos , int valeur ){
 Noeud *BRAIN;
 int LENGHT, I = 1 ;
  LENGHT = TAILLE(debut) ;
  if( pos < 1 || pos > LENGHT ){
    printf("position invalide") ;
  }
  else{
    BRAIN = debut ;
    while( I < pos ){
      BRAIN = BRAIN->suivant ;
      I++ ;
    }
    BRAIN->valeur = valeur ;