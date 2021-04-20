#ifndef DEF_BASICFUNCTION
#define DEF_BASICFUNCTION

/*nom */
typedef struct Name Name;
struct Name
{
    char lettre;
    struct Name *next;
};

typedef struct ListName ListName;
struct ListName
{
    size_t tailleNom;
    Name *head;
};

typedef struct Subject Subject;
struct Subject
{
    char ue[NB_CAR_UE];
};

/* note */
typedef struct Note Note;
struct Note
{
    double noteExcel;
    double noteJava;
    double noteMatlab;
};

typedef struct Lnote Lnote;
struct Lnote
{
    Note *note;
    struct Lnote *next;
};

typedef struct ListeNote ListeNote;
struct ListeNote
{
    size_t nbNote;
    Lnote *head;
    Lnote *tail;
};


/*eleve */
typedef struct Student Student;
struct Student
{
    ListName *nomElev;
    int age;
    Note *note;
    double moyenne;
    int rang;
    struct Student *next;
    struct Student *prev;
};

typedef struct DlistStudent DlistStudent;
struct DlistStudent
{
    size_t nbElev;
    Student *head;
    Student *tail;
};


/* classe */
typedef struct Class Class;
struct Class
{
    char code[NB_CAR_CODE];
    ListName *nomEseig;
    DlistStudent *listeElev;
    int contenance;
};

typedef struct TabClass TabClass;
struct TabClass
{
    Class *classe[NB_CLASSE];
};

/* prototypes */
ListName* nouveau_nom();
ListName* ajouter_lettre(ListName *nom, char lettre);
ListName* ecrire_un_nom(ListName *nom);
void affiche_nom(ListName *nom);
int compare_nom(ListName *nom1, ListName *nom2);

Note* nouvelle_note();
ListeNote* allouer_liste_note();
ListeNote* ajouter_note(ListeNote *liste, Note *note);
int rang_eleve(ListeNote *liste, Note *note);

DlistStudent* nouvel_liste_elev();
DlistStudent* add_elev_prepend(DlistStudent *listElev, ListName *nom, int age, Note *note, int rang);
DlistStudent* add_elev_append(DlistStudent *listElev, ListName *nom, int age, Note *note, int rang);
ListName* ordonner_liste_noms(DlistStudent *listElev, Student *elev);
DlistStudent* insert_elev(DlistStudent *listElev, ListName *nom, int age, Note *note, int rang);

Class *initialiser_classe();
TabClass *initialiser_SC();

#endif // DEF_BASICFUNCTION

