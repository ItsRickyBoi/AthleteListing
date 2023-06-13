#include <iostream>
#include <string>

#define first(G) G.first
#define last(G) G.last
#define prev(G) G.prev
#define next(P) P->next
#define info(P) P->info
#define competition(P) P->competition
#define nil NULL

using namespace std;

typedef struct elm_player* addressPlayer;
typedef struct elm_competition* addressCompetition;
typedef struct elm_relasi* addressRelasi;

struct elm_relasi {
    addressCompetition competition;
    addressRelasi next;
};


addressRelasi alokasi_relasi(addressCompetition C);
void insertRelasi(addressRelasi& R, addressCompetition C);

struct elm_player {
    string name;
    int age;
    string gender;
    addressPlayer next;
    addressRelasi first;
};

struct list_player {
    addressPlayer first;
    addressPlayer last;
};

void createListPlayer(list_player& L);
addressPlayer allocatePlayer(string X, int Y, string Z);
void insertPlayer(list_player& L, addressPlayer P);
void deallocatePlayer(addressPlayer& P);
void deletePlayer(list_player& L, addressPlayer& P);
addressPlayer findElmPlayer(list_player L, string X);
void printInfoPlayer(list_player L);
void printInfoPlayerRelasi(list_player L, string X);
void printSpecificPlayer(list_player L, string X);


struct elm_competition {
    string name;
    string sport;
    addressCompetition next;
    addressCompetition prev;
};

struct list_competition {
    addressCompetition first;
    addressCompetition last;
};

void createListCompetition(list_competition& L);
addressCompetition allocateCompetition(string X, string Y);
void deallocateCompetition(addressCompetition& P);
void insertCompetition(list_competition& L, addressCompetition P);
void deleteCompetition(list_competition& L, addressCompetition& P);
addressCompetition findElmCompetition(list_competition L, string X);
void printInfoCompetition(list_competition L);
void printSpecificCompetition(list_competition L, string X);


void deleteRelasiPlayer(addressRelasi& R, addressCompetition C);
addressRelasi deallocateRelasi(addressRelasi& R);