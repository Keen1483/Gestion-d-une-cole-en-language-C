
#ifndef DEF_EXTENSION
#define DEF_EXTENSION

Note* modifier_note(Note *note);
void afficher_note(Note *note);
void afficher_les_nom(DlistStudent *liste);
void mettre_nom_dans_fichier(ListName *nom, FILE* fichier);
DlistStudent* ajouter_eleve(DlistStudent *listElev);
Class* modifier_classe(Class *classe);
DlistStudent* supprimer_eleve(DlistStudent *listElev, ListName *nom);
void ecrire_mode_binaire(DlistStudent* listElev, FILE* fic);

typedef struct compte
{
    char *unNom;
    double uneNote[3];
    double moyenne;
}compte;

#endif // DEF_EXTENSION
