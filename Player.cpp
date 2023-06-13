#include "Header.h"

void createListPlayer(list_player& L) {
	first(L) = nil;
	last(L) = nil;
}

addressPlayer allocatePlayer(string X, int Y, string Z) {
	addressPlayer P = new elm_player;

	P->name = X;
	P->age = Y;
	P->gender = Z;
	P->next = nil;
	P->first = nil;

	return P;
}

void deallocatePlayer(addressPlayer& P) {
	delete P;
}

void insertPlayer(list_player& L, addressPlayer P) {
	if (first(L) == nil) {
		first(L) = P;
		last(L) = P;
	}
	else {
		last(L)->next = P;
		last(L) = P;
	}
}

void deletePlayer(list_player& L, addressPlayer& P) {
	if (P == nil) {
		cout << "List Kosong" << endl;
		return;
	}

	if (P == first(L)) {
		first(L) = next(P);
		if (P == last(L)) {
			last(L) = nil;
		}
	}
	else {
		addressPlayer Q = first(L);
		while (next(Q) != P) {
			Q = next(Q);
		}
		next(Q) = next(P);
		if (P == last(L)) {
			last(L) = Q;
		}
	}

	deallocatePlayer(P);
}

addressPlayer findElmPlayer(list_player L, string X) {
	addressPlayer P = first(L);

	if (P == NULL) {
		return NULL;
	}
	else {
		while (P != nil) {
			if (P->name == X) {
				return P;
			}
			else {
				P = next(P);
			}
		}
		return NULL;
	}
}

void printInfoPlayer(list_player L) {
	addressPlayer P = first(L);

	if (P == NULL) {
		cout << "List Atlit Kosong" << endl;
		return;
	}
	else {
		do {
			cout << "-Nama : " << P->name << endl;
			cout << "-Umur : " << P->age << endl;
			cout << "-Gender : " << P->gender << endl;
			cout << endl;
			P = next(P);
		} while (P != NULL);
	}
}

void printInfoPlayerRelasi(list_player L, string X) {
	//print out information of elm_player with name X, this includes data inside of elm_player, the name, age, gender, and information stored
	//inside of elm_competition that is connected to elm_player with name X with the relation node (elm_relasi) as the connector between
	//elm_player and elm_competition (elm_player -> elm_relasi -> elm_competition)

	//elm_relasi stores the address of elm_competition, so the information of elm_competition can be accessed by using the address stored
	//inside of elm_relasi
	
	addressPlayer P = findElmPlayer(L, X);

	if (P == nil) {
		cout << "Maaf, Data Atlet Tidak Ditemukan" << endl;
		cout << endl;
	}
	else {
		cout << "Nama : " << P->name << endl;
		cout << "Umur : " << P->age << endl;
		cout << "Gender : " << P->gender << endl;
		cout << endl;

		addressRelasi R = P->first;

		if (R == nil) {
			cout << "Atlet Tidak Mengikuti Kompetisi Apapun" << endl;
		}
		else {
			while (R != nil) {
				addressCompetition C = competition(R); // Access the competition from the relation node
				cout << "Kompetisi : " << C->name << endl;
				cout << "Cabang Olahraga : " << C->sport << endl;
				cout << endl;
				R = next(R);
			}
		}
	}

}

void printSpecificPlayer(list_player L, string X) {
	addressPlayer P = findElmPlayer(L, X);

	if (P == nil) {
		cout << "Maaf, Data Atlet Tidak Ditemukan" << endl;
	}
	else {
		cout << "Name: " << P->name << endl;
		cout << "Age: " << P->age << endl;
		cout << "Gender: " << P->gender << endl;
		cout << endl;
	}
}