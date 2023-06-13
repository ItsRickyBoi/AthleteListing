#include "Header.h"

int main() {

    string nama_atlit, nama_sport, nama_compe;
    int pilihan1, pilihan2, pilihan3;
    int umur_atlit;
    string jenis_kelamin_atlit;

    addressPlayer P_atlit;
    addressCompetition P_compe;
    addressRelasi P_relasi;

	list_player L_atlit;
    list_competition L_compe;

	createListPlayer(L_atlit);
    createListCompetition(L_compe);

    menu:
    system("cls");
    cout << "=========================================================" << endl;
    cout << "|           TUGAS BESAR STRUKTUR DATA - TOPIK 4         |" << endl;
    cout << "|         Ricky Ariesta Fakhruddin - 1301194117         |" << endl;
    cout << "=========================================================" << endl;
    cout << "| Pilihan * : 1. Masukkan Nama Atlit                    |" << endl;
    cout << "|             2. Masukkan Data Kompetisi                |" << endl;
    cout << "|             3. Masukkan Relasi Atlit dan Kompetisi    |" << endl;
    cout << "|             4. Cari Dan Hapus Data                    |" << endl;
    cout << "|             5. Cari Dan Tampilkan Data                |" << endl;
    cout << "|             0. Keluar                                 |" << endl;
    cout << "=========================================================" << endl;
		cout << "Masukkan Pilihan : ";
        cin >> pilihan1;
        cout << endl;

        switch (pilihan1) {
            case 0:
                cout << "Terima Kasih Telah Menggunakan Program Ini!" << endl;
				return 0;
				break;

            case 1:
                cout << "Masukkan Nama Atlit : ";
                cin.ignore();
                getline(cin, nama_atlit);
                cout << "Masukkan Umur Atlit : ";
                cin >> umur_atlit;
                cout << "Masukkan Jenis Kelamin Atlit (L/P/Other) : ";
                cin >> jenis_kelamin_atlit;
                cout << endl;
                allocatePlayer(nama_atlit, umur_atlit, jenis_kelamin_atlit);
                insertPlayer(L_atlit, allocatePlayer(nama_atlit, umur_atlit, jenis_kelamin_atlit));
                P_atlit = findElmPlayer(L_atlit, nama_atlit);
                if (P_atlit != nil) {
                    cout << "Data Atlit Baru Berhasil Ditambahkan!" << endl;
                    cout << endl;
                }
                else {
                    cout << "Data Atlit Tidak Berhasil Ditambahkan!" << endl;
                    cout << endl;
                }
                cout << "Tekan Enter Untuk Kembali Ke Menu";
                cin.ignore();
                cin.get();
                goto menu;
                break;

            case 2:
                cout << "Masukkan Nama Kompetisi : ";
                cin.ignore();
                getline(cin, nama_compe);
                cout << "Masukkan Nama Cabang Olahraga : ";
                getline(cin, nama_sport);
                cout << endl;
                allocateCompetition(nama_compe, nama_sport);
                insertCompetition(L_compe, allocateCompetition(nama_compe, nama_sport));
                P_compe = findElmCompetition(L_compe, nama_compe);
                if (P_compe != nil) {
					cout << "Data Kompetisi Baru Berhasil Ditambahkan!" << endl;
					cout << endl;
				}
                else {
					cout << "Data Kompetisi Tidak Berhasil Ditambahkan!" << endl;
					cout << endl;
				}
                cout << "Tekan Enter Untuk Kembali Ke Menu";
                cin.get();
                goto menu;
                break;

            case 3:
                cout << "Masukkan Nama Atlit : ";
                cin.ignore();
                getline(cin, nama_atlit);
                cout << "Masukkan Nama Kompetisi : ";
                getline(cin, nama_compe);
                cout << endl;
                P_atlit = findElmPlayer(L_atlit, nama_atlit);
                P_compe = findElmCompetition(L_compe, nama_compe);
                if (P_atlit != nil && P_compe != nil) {
                    P_relasi = alokasi_relasi(P_compe);
                    insertRelasi(P_atlit->first, P_compe);
                    cout << "Data Relasi Berhasil Ditambahkan!" << endl;
                    cout << endl;
                }
                else {
                    cout << "Data Atlit atau Kompetisi Tidak Ditemukan!" << endl;
                    cout << endl;
                }
                cout << "Tekan Enter Untuk Kembali Ke Menu";
                cin.get();
                goto menu;
                break;

            case 4:
            menu1:
                system("cls");
                cout << "=========================================================" << endl;
                cout << "|           TUGAS BESAR STRUKTUR DATA - TOPIK 4         |" << endl;
                cout << "|         Ricky Ariesta Fakhruddin - 1301194117         |" << endl;
                cout << "=========================================================" << endl;
                cout << "| Pilihan * : 1. Cari dan Hapus Data Atlit              |" << endl;
                cout << "|             2. Cari dan Hapus Data Kompetisi          |" << endl;
                cout << "|             3. Cari dan Hapus Relasi Tertentu         |" << endl;
                cout << "|             0. Keluar                                 |" << endl;
                cout << "=========================================================" << endl;
                cout << "Masukkan Pilihan : ";
                cin >> pilihan2;
                cout << endl;
                switch (pilihan2) {
                    case 0:
                        goto menu;
                        break;

                    case 1:
                        cout << "Masukkan Nama Atlit Yang Ingin Dihapus : ";
                        cin.ignore();
                        getline(cin, nama_atlit);
                        P_atlit = findElmPlayer(L_atlit, nama_atlit);
                        if (P_atlit != nil) {
                            deletePlayer(L_atlit, P_atlit);
                            cout << "Data Atlit Berhasil Dihapus!" << endl;
                            cout << endl;
                        }
                        else {
                            cout << "Data Atlit Tidak Ditemukan!" << endl;
                            cout << endl;
                        }
                        cout << "Tekan Enter Untuk Kembali" << endl;
                        cin.get();
                        goto menu1;
                        break;

                    case 2:
                        cout << "Pastikan Relasi Atlit Pada Kompetisi Telah Dihapus Terlebih Dahulu!" << endl;
                        cout << "Masukkan Nama Kompetisi Yang Ingin Dihapus: ";
                        cin.ignore();
                        getline(cin, nama_compe);
                        P_compe = findElmCompetition(L_compe, nama_compe);
                        if (P_compe != nil) {
							deleteCompetition(L_compe, P_compe);
							cout << "Data Kompetisi Berhasil Dihapus!" << endl;
							cout << endl;
						}
                        else {
							cout << "Data Kompetisi Tidak Ditemukan!" << endl;
							cout << endl;
						}
						cout << "Tekan Enter Untuk Kembali " << endl;
						cin.get();
						goto menu1;
						break;

                    case 3:
                        cout << "Masukkan Nama Atlit Yang Ingin Dicari : ";
                        cin.ignore();
                        getline(cin, nama_atlit);
                        cout << "Masukkan Nama Kompetisi Yang Ingin Dicari : ";
                        getline(cin, nama_compe);
                        cout << endl;
                        P_atlit = findElmPlayer(L_atlit, nama_atlit);
                        P_compe = findElmCompetition(L_compe, nama_compe);
                        if (P_atlit != nil && P_compe != nil) {
                            deleteRelasiPlayer(P_atlit->first, P_compe);
                            cout << "Data Relasi Berhasil Dihapus!" << endl;
                            cout << endl;
                        }
                        else {
                            cout << "Data Atlit atau Kompetisi Tidak Ditemukan!" << endl;
                            cout << endl;
                        }
                        cout << "Tekan Enter Untuk Kembali " << endl;
                        cin.get();
                        goto menu1;
                        break;

                    }

            case 5:
            menu2:
                system("cls");
                cout << "=========================================================" << endl;
                cout << "|           TUGAS BESAR STRUKTUR DATA - TOPIK 4         |" << endl;
                cout << "|         Ricky Ariesta Fakhruddin - 1301194117         |" << endl;
                cout << "=========================================================" << endl;
                cout << "| Pilihan * : 1. Cari dan Tampilkan Data Atlit          |" << endl;
                cout << "|             2. Cari dan Tampilkan Data Kompetisi      |" << endl;
                cout << "|             3. Cari dan Tampilkan Relasi Atlit        |" << endl;
                cout << "|             4. Tampilkan Semua Daftar Atlit           |" << endl;
                cout << "|             5. Tampilkan Semua Daftar Kompetisi       |" << endl;
                cout << "|             0. Keluar                                 |" << endl;
                cout << "=========================================================" << endl;
                cout << "Masukkan Pilihan : ";
                cin >> pilihan3;
                cout << endl;

                switch (pilihan3) {
                    case 0:
                        goto menu;
                        break;

                    case 1:
                        cout << "Masukkan Nama Atlit Yang Ingin Dicari: ";
                        cin.ignore();
                        getline(cin, nama_atlit);
                        P_atlit = findElmPlayer(L_atlit, nama_atlit);
                        if (P_atlit != nil) {
                            printSpecificPlayer(L_atlit, nama_atlit);
                        }
                        else {
                            cout << "Data Atlit Tidak Ditemukan!" << endl;
                            cout << endl;
                        }
                        cout << "Tekan Enter Untuk Kembali Ke Menu";
                        cin.get();
                        goto menu2;
                        break;
                        
                    case 2:
                        cout << "Masukkan Kompetisi Yang Ingin Dicari : ";
                        cin.ignore();
                        getline(cin, nama_compe);
                        cout << endl;
                        P_compe = findElmCompetition(L_compe, nama_compe);
                        if (P_compe != nil) {
                            printSpecificCompetition(L_compe, nama_compe);
                            cout << endl;
                        }
                        else {
                            cout << "Data Kompetisi Tidak ada!" << endl;
                        }
                        cout << "Tekan Enter Untuk Kembali Ke Menu";
                        cin.get();
                        goto menu2;
                        break;

                    case 3:
                        cout << "Masukkan Nama Atlit Yang Ingin Dicari Relasinya : ";
                        cin.ignore();
                        getline(cin, nama_atlit);
                        P_atlit = findElmPlayer(L_atlit, nama_atlit);
                        if (P_atlit != nil) {
                            printInfoPlayerRelasi(L_atlit, nama_atlit);
                            cout << endl;
                        }
                        else
                        {
                            cout << "Data Atlit Tidak Ada!" << endl;
                            cout << endl;
                        }
                        cout << "Tekan Enter Untuk Kembali Ke Menu";
                        cin.get();
                        goto menu2;
                        break;

                    case 4:
                        printInfoPlayer(L_atlit);
                        cout << "Tekan Enter Untuk Kembali" << endl;
                        cin.ignore();
                        cin.get();
                        goto menu2;
                        break;
                    
                    case 5:
                        printInfoCompetition(L_compe);
                        cout << "Tekan Enter Untuk Kembali Ke Menu";
                        cin.ignore();
                        cin.get();
                        goto menu2;
                        break;
                }


                
        }

	return 0;
}

/**
* 
* 
cout << "Masukkan Nama Atlit Yang Ingin Dicari Relasinya : ";
                cin.ignore();
                getline(cin, nama_atlit);
                P_atlit = findElmPlayer(L_atlit, nama_atlit);
                if (P_atlit != nil) {
                    printInfoPlayerRelasi(L_atlit, nama_atlit);
                    cout << endl;
                }
                else
                {
                    cout << "Data Atlit Tidak Ada!" << endl;
                    cout << endl;
                }
                cout << "Tekan Enter Untuk Kembali Ke Menu";
                cin.get();
                goto menu;
                break;

cout << "Masukkan Nama Atlit Yang Ingin Dicari : ";
                cin.ignore();
                getline(cin, nama_atlit);
                cout << "Masukkan Nama Kompetisi Yang Ingin Dicari : ";
                getline(cin, nama_compe);
                cout << endl;
                P_atlit = findElmPlayer(L_atlit, nama_atlit);
                P_compe = findElmCompetition(L_compe, nama_compe);
                if (P_atlit != nil && P_compe != nil) {
                    deleteRelasiPlayer(P_atlit->first, P_compe);
                    cout << "Data Relasi Berhasil Dihapus!" << endl;
                    cout << endl;
                }
                else {
                    cout << "Data Atlit atau Kompetisi Tidak Ditemukan!" << endl;
                    cout << endl;
                }
                cout << "Tekan Enter Untuk Kembali Ke Menu";
                cin.get();
                goto menu;
                break;
 
 cout << "Masukkan Kompetisi Yang Ingin Dicari : ";
                cin.ignore();
                getline(cin, nama_compe);
                cout << endl;
                P_compe = findElmCompetition(L_compe, nama_compe);
                if (P_compe != nil) {
                    printSpecificCompetition(L_compe, nama_compe);
                    cout << endl;
                }
                else {
                    cout << "Data Kompetisi Tidak ada!" << endl;
                }
                cout << "Tekan Enter Untuk Kembali Ke Menu";
                cin.get();
                goto menu;
                break;

 printInfoCompetition(L_compe);
                cout << "Tekan Enter Untuk Kembali Ke Menu";
                cin.ignore();
                cin.get();
                goto menu;
                break;

* cout << "Masukkan Nama Atlit Yang Ingin Dicari: ";
                cin.ignore();
                getline(cin, nama_atlit);
                P_atlit = findElmPlayer(L_atlit, nama_atlit);
                if (P_atlit != nil) {
                    printSpecificPlayer(L_atlit, nama_atlit);
				}
                else {
					cout << "Data Atlit Tidak Ditemukan!" << endl;
					cout << endl;
				}
                cout << "Tekan Enter Untuk Kembali Ke Menu";
                cin.ignore();
                cin.get();
                goto menu;
                break;

case 2:
                    cout << "Masukkan Nama Atlit Yang Ingin Dihapus : ";
                    cin.ignore();
                    getline(cin, nama_atlit);
                    P_atlit = findElmPlayer(L_atlit, nama_atlit);
                    if (P_atlit != nil) {
                        deletePlayer(L_atlit, P_atlit);
                        cout << "Data Atlit Berhasil Dihapus!" << endl;
                        cout << endl;
                    }
                    else {
                        cout << "Data Atlit Tidak Ditemukan!" << endl;
                        cout << endl;
                    }
                    cout << "Tekan Enter Untuk Kembali" << endl;
                    cin.ignore();
                    cin.get();
                    goto menu;
                    break;

                case 3:
                    printInfoPlayer(L_atlit);
                    cout << "Tekan Enter Untuk Kembali" << endl;
                    cin.ignore();
                    cin.get();
                    goto menu;
                    break;

**/