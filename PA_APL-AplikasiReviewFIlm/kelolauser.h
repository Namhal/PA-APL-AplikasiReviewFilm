#ifndef KELOLAUSER_H
#define KELOLAUSER_H

#include "tampilan.h"
#include "data.h"

int jumlahReviewMilikUser(int idUser) {
    int jumlah = 0;
    for (int i = 0; i < totalReview; i++) {
        if (listReview[i].idUser == idUser) {
            jumlah++;
        }
    }
    return jumlah;
}

int buatDaftarReviewMilikUser(int idUser, int daftarIndexReview[]) {
    int jumlah = 0;
    for (int i = 0; i < totalReview; i++) {
        if (listReview[i].idUser == idUser) {
            daftarIndexReview[jumlah] = i;
            jumlah++;
        }
    }
    return jumlah;
}

void menuKelolaUser() {
    while (true) {
        system("cls");
        cetakJudul("Kelola User");

        int daftarIndexUser[MAX];
        int jumlahUserNonAdmin = 0;

        for (int i = 0; i < totalUser; i++) {
            if (listUser[i].role != "admin") {
                daftarIndexUser[jumlahUserNonAdmin] = i;
                jumlahUserNonAdmin++;
            }
        }

        if (jumlahUserNonAdmin == 0) {
            cout << KUNING << " belum ada user selain admin" << RESET << endl;
        } else {
            for (int i = 0; i < jumlahUserNonAdmin; i++) {
                int idxUser = daftarIndexUser[i];
                cout << CYAN << " [" << i + 1 << "] " << RESET
                    << listUser[idxUser].username
                    << KUNING << " - " << jumlahReviewMilikUser(listUser[idxUser].id) << " review"
                    << RESET << endl;
            }
        }

        string opsiAwal[2];
        opsiAwal[0] = "pilih user";
        opsiAwal[1] = "kembali";

        int pilAwal = pilihMenu(opsiAwal, 2, "Kelola User");

        if (pilAwal == 0) {
            if (jumlahUserNonAdmin == 0) {
                system("cls");
                cetakJudul("Kelola User");
                cout << MERAH << " belum ada user selain admin" << RESET << endl;
                tekanEnter();
                continue;
            }

            system("cls");
            cetakJudul("Pilih User");
            cout << KUNING << " masukkan nomor user: " << RESET;

            int nomorUser;
            cin >> nomorUser;
            bersihBuffer();

            if (cin.fail() || nomorUser < 1 || nomorUser > jumlahUserNonAdmin) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << MERAH << " nomor user tidak valid" << RESET << endl;
                tekanEnter();
                continue;
            }

            int idxUser = daftarIndexUser[nomorUser - 1];

            while (true) {
                system("cls");
                cetakJudul("Detail User");

                cout << KUNING << " username : " << RESET << listUser[idxUser].username << endl;
                cout << KUNING << " jumlah review : " << RESET << jumlahReviewMilikUser(listUser[idxUser].id) << endl;
                cout << endl << CYAN;
                cetakGaris('-', 42);
                cout << KUNING << TEBAL << " daftar review" << RESET << endl;
                cetakGaris('-', 42);
                cout << RESET;

                int daftarIndexReview[MAX * 4];
                int jumlahReviewUser = buatDaftarReviewMilikUser(listUser[idxUser].id, daftarIndexReview);

                if (jumlahReviewUser == 0) {
                    cout << KUNING << " belum ada review" << RESET << endl;
                } else {
                    for (int i = 0; i < jumlahReviewUser; i++) {
                        int idxReview = daftarIndexReview[i];
                        Film* filmDipilih = cariFilm(listReview[idxReview].idFilm);
                        string namaFilm = "?";
                        if (filmDipilih != nullptr) {
                            namaFilm = filmDipilih->judul;
                        }

                        cout << CYAN << " [" << i + 1 << "] " << RESET
                            << namaFilm << KUNING << " - " << listReview[idxReview].rating << "/10"
                            << RESET << endl;
                        cout << " " << listReview[idxReview].ulasan << endl << endl;
                    }
                }

                string opsiUser[3];
                opsiUser[0] = "hapus user";
                opsiUser[1] = "hapus review";
                opsiUser[2] = "kembali";

                int pilUser = pilihMenu(opsiUser, 3, listUser[idxUser].username);

                if (pilUser == 0) {
                    string opsiKonfirmasi[2];
                    opsiKonfirmasi[0] = "ya hapus";
                    opsiKonfirmasi[1] = "batal";

                    int konfirmasi = pilihMenu(opsiKonfirmasi, 2, "Hapus User?");
                    if (konfirmasi == 0) {
                        int idYangDihapus = listUser[idxUser].id;
                        hapusUser(idYangDihapus);
                        system("cls");
                        cout << endl << HIJAU << TEBAL << " user berhasil dihapus" << RESET << endl;
                        tekanEnter();
                        break;
                    }
                } else if (pilUser == 1) {
                    if (jumlahReviewUser == 0) {
                        system("cls");
                        cetakJudul("Hapus Review");
                        cout << KUNING << " user ini belum punya review" << RESET << endl;
                        tekanEnter();
                        continue;
                    }

                    system("cls");
                    cetakJudul("Hapus Review");
                    cout << KUNING << " pilih nomor review yang dihapus: " << RESET;

                    int nomorReview;
                    cin >> nomorReview;
                    bersihBuffer();

                    if (cin.fail() || nomorReview < 1 || nomorReview > jumlahReviewUser) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << MERAH << " nomor review tidak valid" << RESET << endl;
                        tekanEnter();
                        continue;
                    }

                    hapusReviewDi(daftarIndexReview[nomorReview - 1]);

                    system("cls");
                    cout << endl << HIJAU << TEBAL << " review berhasil dihapus" << RESET << endl;
                    tekanEnter();
                } else {
                    break;
                }
            }
        } else {
            return;
        }
    }
}

#endif