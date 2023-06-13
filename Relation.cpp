#include "Header.h"

addressRelasi alokasi_relasi(addressCompetition C) {
	//allocate address of Competition and Player, the child will save the address of Competition parent
	addressRelasi P = new elm_relasi;

	competition(P) = C;
	next(P) = nil;

	return P;
}

void insertRelasi(addressRelasi& R, addressCompetition C) {
	//insert Competition to the list of Competition in Player
	addressRelasi P = alokasi_relasi(C);

	if (R == nil) {
		R = P;
	}
	else {
		next(P) = R;
		R = P;
	}
}

void deleteRelasiPlayer(addressRelasi& R, addressCompetition C) {
    if (R == nil) {
        return; // Relation list is empty, nothing to delete
    }

    addressRelasi P = R;
    addressRelasi prev = nil;

    while (P != nil) {
        if (competition(P) == C) {
            if (prev == nil) {
                R = next(P);
            }
            else {
                next(prev) = next(P);
            }

            delete P;

            return;
        }

        prev = P;
        P = next(P);
    }
}