#include <stdio.h>
#include <stdlib.h>
#include "constante.h"
#include "basic_function.h"
#include "extension.h"

/* nom */
ListName* nouveau_nom()
{
    ListName *nom = malloc(sizeof *nom);
    if(nom != NULL)
    {
        nom->tailleNom = 0;
        nom->head = NULL;
    }
    return nom;
}

ListName* ajouter_lettre(ListName *nom, char lettre)
{
    if(nom != NULL && nom->tailleNom < NB_CAR_NOM)
    {
        Name *nouvel_lettre = malloc(sizeof *nouvel_lettre);
        nouvel_lettre->lettre = lettre;
        nouvel_lettre->next = NULL;
        if(nom->head == NULL)
        {
            nom->head = nouvel_lettre;
        }
        else
        {
            Name *temp = nom->head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nouvel_lettre;
        }
        nom->tailleNom++;
    }
    return nom;
}

ListName* ecrire_un_nom(ListName *nom)
{
    int a = 0;
    while(a != '\n' && a != EOF)
    {
        a = getchar();
        nom = ajouter_lettre(nom, a);
    }
    return nom;
}

void affiche_nom(ListName *nom)
{
    if(nom != NULL)
    {
        Name *temp = nom->head;
        while(temp != NULL)
        {
            printf("%c", temp->lettre);
            temp = temp->next;
        }
    }
}

int compare_nom(ListName *nom1, ListName *nom2)
{
    if(nom1->tailleNom < nom2->tailleNom)
    {
        Name *temp1 = nom1->head;
        Name *temp2 = nom2->head;
        while(temp1->lettre == temp2->lettre && temp1 != NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1->lettre < temp2->lettre) return 1;
        if(temp1->lettre > temp2->lettre) return -1;
        else return 1;
    }

    if(nom1->tailleNom > nom2->tailleNom)
    {
        Name *temp1 = nom1->head;
        Name *temp2 = nom2->head;
        while(temp1->lettre == temp2->lettre && temp2 != NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1->lettre < temp2->lettre) return 1;
        if(temp1->lettre > temp2->lettre) return -1;
        else return -1;
    }

    else
    {
        Name *temp1 = nom1->head;
        Name *temp2 = nom2->head;
        while(temp1->lettre == temp2->lettre && temp1->next != NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1->lettre < temp2->lettre) return 1;
        if(temp1->lettre > temp2->lettre) return -1;
        else return 0;
    }
}


/* note */
Note* nouvelle_note()
{
    Note *nouvelleNote = malloc(sizeof *nouvelleNote);
    if(nouvelleNote != NULL)
    {
        nouvelleNote->noteExcel = -1.00;
        nouvelleNote->noteJava = -1.00;
        nouvelleNote->noteMatlab = -1.00;
    }
    return nouvelleNote;
}

ListeNote* allouer_liste_note()
{
    ListeNote *liste = malloc(sizeof *liste);
    if(liste != NULL)
    {
        liste->nbNote = 0;
        liste->head = NULL;
        liste->tail = NULL;
    }
    return liste;
}

ListeNote* ajouter_note(ListeNote *liste, Note *note)
{
    Lnote *noeud = malloc(sizeof *noeud);
    noeud->note = note;
    noeud->next = NULL;
    if(liste->head == NULL)
    {
        liste->head = noeud;
        liste->tail = noeud;
    }
    else
    {
        liste->tail->next = noeud;
        liste->tail = noeud;
    }
    liste->nbNote++;
    return liste;
}

int rang_eleve(ListeNote *liste, Note *note)
{
    int i, rang = liste->nbNote;
    double moy = (note->noteExcel + note->noteJava + note->noteMatlab)/3.00;
    Lnote *temp = liste->head;
    for(i = 1; i <= liste->nbNote; i++)
    {
        if((temp->note->noteExcel + temp->note->noteJava + temp->note->noteMatlab)/3.00 < moy)
        {
            rang--;
        }
        temp = temp->next;
    }
    return rang;
}

/* eleve */
DlistStudent* nouvel_liste_elev()
{
    DlistStudent *listElev = malloc(sizeof *listElev);
    if(listElev != NULL)
    {
        listElev->nbElev = 0;
        listElev->head = NULL;
        listElev->tail = NULL;
    }
    return listElev;
}

DlistStudent* add_elev_prepend(DlistStudent *listElev, ListName *nom, int age, Note *note, int rang)
{
    if(listElev != NULL && listElev->nbElev < NB_MAX_ELEVE)
    {
        Student *nouveauElev = malloc(sizeof *nouveauElev);
        if(nouveauElev != NULL)
        {
            nouveauElev->nomElev = nom;
            nouveauElev->age = age;
            nouveauElev->note = note;
            nouveauElev->moyenne = (note->noteExcel + note->noteJava + note->noteMatlab)/3.00;
            nouveauElev->rang = rang;
            nouveauElev->prev = NULL;
            if(listElev->head == NULL)
            {
                nouveauElev->next = NULL;
                listElev->head = nouveauElev;
                listElev->tail = nouveauElev;
            }
            else
            {
                listElev->head->prev = nouveauElev;
                nouveauElev->next = listElev->head;
                listElev->head = nouveauElev;
            }
            listElev->nbElev++;
        }
    }
    return listElev;
}

DlistStudent* add_elev_append(DlistStudent *listElev, ListName *nom, int age, Note *note, int rang)
{
    if(listElev != NULL && listElev->nbElev < NB_MAX_ELEVE)
    {
        Student *nouveauElev = malloc(sizeof *nouveauElev);
        if(nouveauElev != NULL)
        {
            nouveauElev->nomElev = nom;
            nouveauElev->age = age;
            nouveauElev->note = note;
            nouveauElev->moyenne = (note->noteExcel + note->noteJava + note->noteMatlab)/3.00;
            nouveauElev->rang = rang;
            nouveauElev->next = NULL;
            if(listElev->tail == NULL)
            {
                nouveauElev->prev = NULL;
                listElev->head = nouveauElev;
                listElev->tail = nouveauElev;
            }
            else
            {
                listElev->tail->next = nouveauElev;
                nouveauElev->prev = listElev->tail;
                listElev->tail = nouveauElev;
            }
            listElev->nbElev++;
        }
    }
    return listElev;
}

ListName* ordonner_liste_noms(DlistStudent *listElev, Student *elev)
{
    if(listElev->head == NULL) return NULL;
    else{
        Student *temp = listElev->head;
        while(compare_nom(elev->nomElev, temp->nomElev) != 1 && temp->next != NULL)
        {
            temp = temp->next;
        }
        if(temp->next == NULL)
            return listElev->tail->nomElev;
        else
            return temp->nomElev;
        }
}

DlistStudent* insert_elev(DlistStudent *listElev, ListName *nom, int age, Note *note, int rang)
{
    if(listElev->nbElev < NB_MAX_ELEVE)
    {
        DlistStudent *temp = listElev;
        Student *ptemp = listElev->head;
        Student *nouveauElev = malloc(sizeof *nouveauElev);
        ListName *comp = nouveau_nom();
        if(nouveauElev != NULL)
        {
            nouveauElev->nomElev = nom;
            nouveauElev->age = age;
            nouveauElev->note = note;
            nouveauElev->moyenne = (note->noteExcel + note->noteJava + note->noteMatlab)/3.00;
            nouveauElev->rang = rang;
            comp = ordonner_liste_noms(temp, nouveauElev);
            if(listElev->head == NULL)
            {
                listElev = add_elev_append(listElev, nom, age, note, rang);
            }
            else
            {
                if(comp == listElev->tail->nomElev)
            {
                if(compare_nom(nouveauElev->nomElev, listElev->tail->nomElev) == -1)
                {
                    listElev = add_elev_append(listElev, nom, age, note, rang);
                }
            }
            if((comp == listElev->head->nomElev))
            {
                if(compare_nom(nouveauElev->nomElev, listElev->head->nomElev) == 1)
                {
                    listElev = add_elev_prepend(listElev, nom, age, note, rang);
                }
            }
            else
            {
                while(ptemp->nomElev != comp)
                {
                    ptemp = ptemp->next;
                }
                ptemp->next->prev = nouveauElev;
                ptemp->prev->next = nouveauElev;
                nouveauElev->prev = ptemp->prev;
                nouveauElev->next = ptemp;
                listElev->nbElev++;
            }
            }
        }
    }
    return listElev;
}


Class *initialiser_classe()
{
    int j;
    Class *classe = malloc(sizeof *classe);
    for(j = 0; j <= NB_CAR_CODE - 2; j++)
    {
        classe->code[j] = '0';
    }
    classe->code[NB_CAR_CODE - 1] = '\0';
    classe->nomEseig = nouveau_nom();
    classe->listeElev = nouvel_liste_elev();
    classe->contenance = classe->listeElev->nbElev;
    return classe;
}

TabClass *initialiser_SC()
{
    int i;
    TabClass *tClasse = malloc(sizeof *tClasse);
    for(i = 0; i <= NB_CLASSE - 1; i++){
        tClasse->classe[i] = initialiser_classe();
        tClasse->classe[i]->code[NB_CAR_CODE - 2] = i + 65;
    }
    return tClasse;
}

