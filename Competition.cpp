#include "Header.h"

void createListCompetition(list_competition& L) {
	first(L) = nil;
	last(L) = nil;
}

addressCompetition allocateCompetition(string X, string Y) {
	addressCompetition P = new elm_competition;

	P->name = X;
	P->sport = Y;
	P->next = nil;

	return P;
}

void deallocateCompetition(addressCompetition& P) {
	delete P;
}

void insertCompetition(list_competition& L, addressCompetition P) {
	if (first(L) == nil) {
		first(L) = P;
		last(L) = P;
	}
	else {
		last(L)->next = P;
		P->prev = last(L);
		last(L) = P;
	}
}

void deleteCompetition(list_competition& L, addressCompetition& P) {
	if (first(L) == nil) {
		cout << "List Kosong" << endl;
		return;
	}

	if (P == first(L)) {
		first(L) = next(P);
		if (first(L) != nil) {
			first(L)->prev = nil;
		}
		deallocateCompetition(P);
	}
	else if (P == last(L)) {
		last(L) = P->prev;
		if (last(L) != nil) {
			next(last(L)) = nil;
		}
		deallocateCompetition(P);
	}
	else {
		addressCompetition Q = first(L);
		while (next(Q) != P) {
			Q = next(Q);
		}
		next(Q) = next(P);
		next(P)->prev = Q;
		deallocateCompetition(P);
	}
}

addressCompetition findElmCompetition(list_competition L, string X) {
	addressCompetition P = first(L);

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

void printInfoCompetition(list_competition L) {
	addressCompetition P = first(L);
	if (P == nil) {
		cout << "List Kompetisi Kosong" << endl;
		cout << endl;
	}
	else {
		do {
			cout << "Nama Kompetisi: " << P->name << endl;
			cout << "Cabang Olahraga: " << P->sport << endl;
			cout << endl;
			P = next(P);
		} while (P != nil);
	}
}

void printSpecificCompetition(list_competition L, string X) {
	addressCompetition P = findElmCompetition(L, X);

	if (P == nil) {
		cout << "Maaf, Data Kompetisi Tidak Ditemukan" << endl;
	}
	else {
		cout << "Nama Kompetisi : " << P->name << endl;
		cout << "Cabang Olahraga : " << P->sport << endl;
		cout << endl;
	}
}