#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constante.h"
#include "basic_function.h"
#include "extension.h"

Note* modifier_note(Note *note)
{
    printf("Note Excel ? ");
    scanf("%lf", &(note->noteExcel));
    printf("Note Java ? ");
    scanf("%lf", &(note->noteJava));
    printf("Note Matlab ? ");
    scanf("%lf", &(note->noteMatlab));
    return note;

}

void afficher_note(Note *note)
{
    printf("note Excel: %lf\n note Java: %lf\n note Matlab: %lf\n", note->noteExcel, note->noteJava, note->noteMatlab);
}

void afficher_les_nom(DlistStudent *liste)
{
    Student *temp = liste->head;
    while(temp != NULL)
    {
        affiche_nom(temp->nomElev);
        temp = temp->next;
    }
}

void mettre_nom_dans_fichier(ListName *nom, FILE* fichier)
{
    int i; Name *temp = nom->head;
    char chaine[nom->tailleNom + 1];
    for(i = 0; i <= nom->tailleNom - 1; i++){
        chaine[i] = temp->lettre;
        temp = temp->next;
    }
    chaine[nom->tailleNom] = '\0';
    fprintf(fichier, "Nom: %s", chaine);
}

void ecrire_mode_binaire(DlistStudent* listElev, FILE* fic)
{
    fic = fopen("binaire.txt", "wb");
    compte* unCompte = malloc(sizeof(compte));
    char chaine[listElev->head->nomElev->tailleNom + 1];
    int i = 0; Name *temp = listElev->head->nomElev->head;
    for(i = 0; i <= listElev->head->nomElev->tailleNom - 1; i++){
        chaine[i] = temp->lettre;
        temp = temp->next;
    }
    chaine[listElev->head->nomElev->tailleNom] = '\0';
    unCompte->unNom = chaine;
    unCompte->uneNote[0] = listElev->head->note->noteExcel;
    unCompte->uneNote[1] = listElev->head->note->noteJava;
    unCompte->uneNote[2] = listElev->head->note->noteMatlab;
    unCompte->moyenne = (unCompte->uneNote[0]  + unCompte->uneNote[1] + unCompte->uneNote[2])/3.00;
    fwrite(&unCompte, sizeof(compte), 1, fic);
    fclose(fic);
}

DlistStudent* ajouter_eleve(DlistStudent *listElev)
{
    FILE* fichierbin = fopen("binaire.txt", "wb");
    FILE* fichierElev = fopen("eleve.txt", "a+");
    FILE* fichierClass = fopen("note.txt", "a+");
    FILE* fichierAgeEleve = fopen("AgeEleve.txt", "a+");
    FILE* fichierNouveauxEleve = fopen("NouveauxEleve.txt", "a+");
    ListeNote *lisNote = allouer_liste_note();
    char c, code[5] = {'0','0','0','0','\0'};
    int i = 0, j, age = 0, err = 0, ok = 0, yes = 0, rang = -1, rd = 0; double moy = -1.00;
    ListName *nom;
    Note *note = nouvelle_note();
    while(!yes)
    {
        nom = nouveau_nom();
        printf("\tEntrez le nom de l'eleve\n");
        scanf("%c", &c);
    nom = ecrire_un_nom(nom);
    printf("\tEntrez l'age de l'eleve\n");
    scanf("%d", &age);
    if(age == 26)
    {
        fprintf(fichierAgeEleve, "\n");
        mettre_nom_dans_fichier(nom, fichierAgeEleve);
    }
    while(!ok)
    {
        printf("\tVoulez vous modifier ses notes ?\n");
        printf("\tOUI = o et NON = n\n");
        err = 0;
        while(err != '\n' && err != EOF)
        {
            err = getchar();
        }
        scanf("%c", &c);
        if(c == 'o' || c == 'n') ok = 1;
        else printf("Recommencez ");
    }
    if(c == 'n') {
            srand(time(NULL));
            rd = (rand() % 5) + 65;
            code[3] = rd;
            fprintf(fichierNouveauxEleve, "\n");
        mettre_nom_dans_fichier(nom, fichierNouveauxEleve);
        fprintf(fichierNouveauxEleve, "Age: %d\nCode de la classe d'affectation: %s", age, code);
    }
    if(c == 'o')
    {
        printf("\tEntrez les notes de l'eleve\n");
        printf("\tNote Excel ? ");
        scanf("%lf", &(note->noteExcel));
        printf("\tNote Java ? ");
        scanf("%lf", &(note->noteJava));
        printf("\tNote Matlab ? ");
        scanf("%lf", &(note->noteMatlab));
        moy = (note->noteExcel + note->noteJava + note->noteMatlab)/3.00;
    }
    lisNote = ajouter_note(lisNote, note);
    listElev = insert_elev(listElev, nom, age, note, rang);
    fprintf(fichierElev, "\n");
    mettre_nom_dans_fichier(nom, fichierElev);
    fprintf(fichierElev, "Moyenne: %lf", moy);
    printf("Ajouter un nouveau eleve\nOUI = o et NON = n ? ");
    err = 0;
    while(err != '\n' && err != EOF){
        err = getchar();
    }
    scanf("%c", &c);
    if(c == 'n') yes = 1;
    else{}
    ok = 0;

        i++;
    }

    Student *tmpElev = listElev->head;
    for(j = 1; j <= i; j++)
    {
        moy = (tmpElev->note->noteExcel + tmpElev->note->noteJava + tmpElev->note->noteMatlab) / 3.00;
        rang = rang_eleve(lisNote, tmpElev->note);
        fprintf(fichierClass, "\n");
        mettre_nom_dans_fichier(tmpElev->nomElev, fichierClass);
        fprintf(fichierClass, "Note Excel: %lf\nNote Java: %lf\nNote Matlab: %lf\n", tmpElev->note->noteExcel, tmpElev->note->noteJava, tmpElev->note->noteMatlab);
        fprintf(fichierClass, "Moyenne: %lf\nRang: %d", moy, rang);
        tmpElev = tmpElev->next;
    }
    ecrire_mode_binaire(listElev, fichierbin);
    fclose(fichierElev);
    fclose(fichierClass);
    fclose(fichierAgeEleve);
    fclose(fichierNouveauxEleve);
    fclose(fichierbin);
    return listElev;
}

Class* modifier_classe(Class *classe)
{
    FILE* fichierClass = fopen("classe.txt", "w+");
    ListName *nomEnseig = nouveau_nom();
    fprintf(fichierClass, "Code de la classe: %s\nNom de l'enseignant: ", classe->code);
    printf("Entrez le nom de l'enseignant\n");
    nomEnseig = ecrire_un_nom(nomEnseig);
    mettre_nom_dans_fichier(nomEnseig, fichierClass);
    classe->listeElev = ajouter_eleve(classe->listeElev);
    fclose(fichierClass);
    return classe;
}


DlistStudent* supprimer_eleve(DlistStudent *listElev, ListName *nom)
{
    if(listElev->head != NULL)
    {
        Student *temp = listElev->head;
        if(listElev->head->nomElev == nom)
        {
            listElev->head = listElev->head->next;
            listElev->head->prev = NULL;
        }
        if(listElev->tail->nomElev == nom)
        {
            listElev->tail =listElev->tail->prev;
            listElev->tail->next = NULL;
        }
        else
        {
            while(temp->nomElev != nom && temp->next != NULL)
            {
                temp = temp->next;
            }
            if(temp->nomElev == nom)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
        }
        free(temp);
        listElev->nbElev--;
    }
    return listElev;
}


