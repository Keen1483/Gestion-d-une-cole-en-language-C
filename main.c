#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constante.h"
#include "basic_function.h"
#include "extension.h"

TabClass *SC;
void InfoEleve(TabClass *SC, ListName *nom);
void classementClasse(char code[]);
void AgeEleve();
void NouveauxEleve();
void MiseAJourClasse(char code[]);



int main()
{
    char r, code[NB_CAR_CODE];
    int choix = 0; double moy;
    FILE* fichier1 = fopen("classe1.txt", "a+");
    FILE* fichier2 = fopen("classe2.txt", "a+");
    FILE* fichier3 = fopen("classe3.txt", "a+");
    FILE* fichier4 = fopen("classe4.txt", "a+");
    FILE* fichier5 = fopen("classe5.txt", "a+");
    printf("\n\tLes codes des classes sont:\n\t000A 000B 000C 000D  000E\n");
    printf("\n\tPour toute question, OUI = o et NON = n\n");
    SC = initialiser_SC();
    ListName *nom = nouveau_nom();
    printf("\n\tQue voulez vous faire ?\n\tFaites un choix\n");
    while(choix < 1 || choix > 6){
        printf("\n\t1. Ajouter un eleve\n\t2. Verifier le classement des classes\n\t3. La liste des nouveaux eleves\n");
        printf("\t4. Les eleves ayant eus 25 ans en 2017\n\t5. Faire la mise a jour d'une classe\n\t6. Verifier les informations d'un eleve\n");
        printf("\tVotre choix ? ");
        scanf("%d", &choix);
    }
    switch(choix){
    case 1:
        printf("\n\tEntrez le code de la classe: ");
        scanf("%s", code);
        if(strcmp(code, SC->classe[0]->code) == 0){
            SC->classe[0]->listeElev = ajouter_eleve(SC->classe[0]->listeElev);fprintf(fichier1, "\n");
            moy = (SC->classe[0]->listeElev->head->note->noteExcel + SC->classe[0]->listeElev->head->note->noteJava + SC->classe[0]->listeElev->head->note->noteMatlab)/3.00;
            mettre_nom_dans_fichier(SC->classe[0]->listeElev->head->nomElev, fichier1);
            fprintf(fichier1, "Note Excel: %lf\n", SC->classe[0]->listeElev->head->note->noteExcel);
            fprintf(fichier1, "Note Java: %lf\n", SC->classe[0]->listeElev->head->note->noteJava);
            fprintf(fichier1, "Note Matlab: %lf\n", SC->classe[0]->listeElev->head->note->noteMatlab);
            fprintf(fichier1, "Moyenne: %lf", moy);
        }
        if(strcmp(code, SC->classe[1]->code) == 0){
            SC->classe[1]->listeElev = ajouter_eleve(SC->classe[1]->listeElev);fprintf(fichier2, "\n");
            moy = (SC->classe[1]->listeElev->head->note->noteExcel + SC->classe[1]->listeElev->head->note->noteJava + SC->classe[1]->listeElev->head->note->noteMatlab)/3.00;
            mettre_nom_dans_fichier(SC->classe[1]->listeElev->head->nomElev, fichier2);
            fprintf(fichier2, "Note Excel: %lf\n", SC->classe[1]->listeElev->head->note->noteExcel);
            fprintf(fichier2, "Note Java: %lf\n", SC->classe[1]->listeElev->head->note->noteJava);
            fprintf(fichier2, "Note Matlab: %lf\n", SC->classe[1]->listeElev->head->note->noteMatlab);
            fprintf(fichier2, "Moyenne: %lf", moy);
        }
        if(strcmp(code, SC->classe[2]->code) == 0){
            SC->classe[2]->listeElev = ajouter_eleve(SC->classe[2]->listeElev);fprintf(fichier3, "\n");
            moy = (SC->classe[2]->listeElev->head->note->noteExcel + SC->classe[2]->listeElev->head->note->noteJava + SC->classe[2]->listeElev->head->note->noteMatlab)/3.00;
            mettre_nom_dans_fichier(SC->classe[2]->listeElev->head->nomElev, fichier3);
            fprintf(fichier3, "Note Excel: %lf\n", SC->classe[2]->listeElev->head->note->noteExcel);
            fprintf(fichier3, "Note Java: %lf\n", SC->classe[2]->listeElev->head->note->noteJava);
            fprintf(fichier3, "Note Matlab: %lf\n", SC->classe[2]->listeElev->head->note->noteMatlab);
            fprintf(fichier3, "Moyenne: %lf", moy);
        }
        if(strcmp(code, SC->classe[3]->code) == 0){
            SC->classe[3]->listeElev = ajouter_eleve(SC->classe[3]->listeElev);fprintf(fichier4, "\n");
            moy = (SC->classe[3]->listeElev->head->note->noteExcel + SC->classe[3]->listeElev->head->note->noteJava + SC->classe[3]->listeElev->head->note->noteMatlab)/3.00;
            mettre_nom_dans_fichier(SC->classe[3]->listeElev->head->nomElev, fichier4);
            fprintf(fichier4, "Note Excel: %lf\n", SC->classe[3]->listeElev->head->note->noteExcel);
            fprintf(fichier4, "Note Java: %lf\n", SC->classe[3]->listeElev->head->note->noteJava);
            fprintf(fichier4, "Note Matlab: %lf\n", SC->classe[3]->listeElev->head->note->noteMatlab);
            fprintf(fichier4, "Moyenne: %lf", moy);
        }
        if(strcmp(code, SC->classe[4]->code) == 0){
            SC->classe[4]->listeElev = ajouter_eleve(SC->classe[4]->listeElev);fprintf(fichier5, "\n");
            moy = (SC->classe[4]->listeElev->head->note->noteExcel + SC->classe[4]->listeElev->head->note->noteJava + SC->classe[4]->listeElev->head->note->noteMatlab)/3.00;
            mettre_nom_dans_fichier(SC->classe[4]->listeElev->head->nomElev, fichier5);
            fprintf(fichier5, "Note Excel: %lf\n", SC->classe[4]->listeElev->head->note->noteExcel);
            fprintf(fichier5, "Note Java: %lf\n", SC->classe[4]->listeElev->head->note->noteJava);
            fprintf(fichier5, "Note Matlab: %lf\n", SC->classe[4]->listeElev->head->note->noteMatlab);
            fprintf(fichier5, "Moyenne: %lf", moy);
        }
        break;
    case 2:
        printf("\n\tEntrez code de la classe? ");
        scanf("%s", code);
        classementClasse(code);
        break;
    case 3:
        NouveauxEleve();
        break;
    case 4:
        AgeEleve();
        break;
    case 5:
        printf("\n\tEntrez le code de la classe ? ");
        scanf("%s", code);
        MiseAJourClasse(code);
        break;
    default:
        printf("\n\tEntrez de l'eleve: ");
        scanf("%c", &r);
        nom = ecrire_un_nom(nom);
        InfoEleve(SC, nom);
        break;
    }
    return 0;
}

void InfoEleve(TabClass *SC, ListName *nom)
{
    int i;
    FILE* fichierElev = fopen("eleve.txt", "r");
    FILE* fichierInfoElev = fopen("InfoEleveIndice.txt", "a+");
    Name *temp = nom->head;
    char chaine[nom->tailleNom + 1], tmpChaine[nom->tailleNom + 1];
    for(i = 0; i <= nom->tailleNom - 1; i++){
        chaine[i] = temp->lettre;
        temp = temp->next;
    }
    chaine[nom->tailleNom] = '\0';
    while(strcmp(fgets(tmpChaine, nom->tailleNom + 1, fichierElev), chaine) != 0 && fgets(tmpChaine, nom->tailleNom + 1, fichierElev) != NULL);
    {
        printf("Nom: %s", tmpChaine);
    }
    if(strcmp(fgets(tmpChaine, nom->tailleNom + 1, fichierElev), chaine) == 0){
        fprintf(fichierInfoElev, "Nom: %s", chaine);

    }
    fclose(fichierElev);
    fclose(fichierInfoElev);
}

void AgeEleve()
{
    char chaine[15];
    FILE* fichierAgeEleve = fopen("AgeEleve.txt", "r");
    while(fgets(chaine, 15, fichierAgeEleve) != NULL){
        printf("%s\n", chaine);
    }
    fclose(fichierAgeEleve);
}

void NouveauxEleve()
{
    int k;
    FILE* fichierNouveauxEleve = fopen("NouveauxEleve.txt", "r");
    do{k = fgetc(fichierNouveauxEleve); printf("%c", k);}while(k != EOF);
}

void classementClasse(char code[])
{
    int i, k;
    FILE* fichier1 = fopen("classe1.txt", "a+");
    FILE* fichier2 = fopen("classe2.txt", "a+");
    FILE* fichier3 = fopen("classe3.txt", "a+");
    FILE* fichier4 = fopen("classe4.txt", "a+");
    FILE* fichier5 = fopen("classe5.txt", "a+");
    SC = initialiser_SC();
    for(i = 1; i <= NB_CLASSE; i++){
        if(strcmp(SC->classe[i-1]->code, code) == 0){
            if(i == 1){
                do{k = fgetc(fichier1); printf("%c", k);}while(k != EOF);
            }
            if(i == 2){
                do{k = fgetc(fichier2); printf("%c", k);}while(k != EOF);
            }
            if(i == 3){
                do{k = fgetc(fichier3); printf("%c", k);}while(k != EOF);
            }
            if(i == 4){
                do{k = fgetc(fichier4); printf("%c", k);}while(k != EOF);
            }
            if(i == 5){
                do{k = fgetc(fichier5); printf("%c", k);}while(k != EOF);
            }
        }
    }
    fclose(fichier1); fclose(fichier2); fclose(fichier3); fclose(fichier4); fclose(fichier5);
}

void MiseAJourClasse(char code[])
{
    char chaine[15]; int k = 0;
    FILE* fichier1 = fopen("classe1.txt", "a+");
    FILE* fichier2 = fopen("classe2.txt", "a+");
    FILE* fichier3 = fopen("classe3.txt", "a+");
    FILE* fichier4 = fopen("classe4.txt", "a+");
    FILE* fichier5 = fopen("classe5.txt", "a+");
    FILE* fichieraffectation = fopen("affectation.txt", "w+");
    if(strcmp(code, SC->classe[0]->code) == 0){
        while(fgets(chaine, 15, fichier1) != NULL){k++;}
        k = k/10 + 1;
        fprintf(fichieraffectation, "Code de la classe: %s\nContenance: %d\n", code, k);
    }
    if(strcmp(code, SC->classe[1]->code) == 0){
        while(fgets(chaine, 15, fichier2) != NULL){k++;}
        k = k/10 + 1;
        fprintf(fichieraffectation, "Code de la classe: %s\nContenance: %d\n", code, k);
    }
    if(strcmp(code, SC->classe[2]->code) == 0){
        while(fgets(chaine, 15, fichier3) != NULL){k++;}
        k = k/10 + 1;
        fprintf(fichieraffectation, "Code de la classe: %s\nContenance: %d\n", code, k);
    }
    if(strcmp(code, SC->classe[3]->code) == 0){
        while(fgets(chaine, 15, fichier4) != NULL){k++;}
        k = k/10 + 1;
        fprintf(fichieraffectation, "Code de la classe: %s\nContenance: %d\n", code, k);
    }
    if(strcmp(code, SC->classe[4]->code) == 0){
        while(fgets(chaine, 15, fichier5) != NULL){k++;}
        k = k/10 + 1;
        fprintf(fichieraffectation, "Code de la classe: %s\nContenance: %d\n", code, k);
    }
    fclose(fichier1); fclose(fichier2); fclose(fichier3); fclose(fichier4); fclose(fichier5);
}


