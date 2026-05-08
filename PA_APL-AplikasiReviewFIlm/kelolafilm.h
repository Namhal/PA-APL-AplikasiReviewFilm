
#ifndef KELOLAFILM_H
#define KELOLAFILM_H

#include "tampilan.h"
#include "detailfilm.h"
#include "data.h"

bool hanyaAngka(const string& teks) {
    if (teks.empty()) return false;
    for (int i = 0; i < teks.size(); i++) {
        if (!isdigit(teks[i])) return false;
    }
    return true;
}

int jumlahReviewFilm(int idFilm) {
    int jumlah = 0;
    for (int i = 0; i < totalReview; i++) {
        if (listReview[i].idFilm == idFilm) {
            jumlah++;
        }
    }
    return jumlah;
}

void menuKelolaFilm() {
    while (true) {
        system("cls");
        cetakJudul("Kelola Film");

        if (totalFilm == 0) {
            cout << KUNING << " belum ada film" << RESET << endl;
        } else {
            for (int i = 0; i < totalFilm; i++) {
                cout << CYAN << " [" << i + 1 << "] " << RESET
                    << listFilm[i].judul << " (" << listFilm[i].tahun << ")"
                    << KUNING << " - " << listFilm[i].studio
                    << " - " << jumlahReviewFilm(listFilm[i].id) << " review"
                    << RESET << endl;
            }
        }

        string opsi[] = {"tambah film", "pilih film", "kembali"};
        int pil = pilihMenu(opsi, 3, "Kelola Film");

        if (pil == 0) {
            system("cls");
            cetakJudul("Tambah Film");

            if (totalFilm >= MAX) {
                cout << MERAH << " kapasitas film penuh" << RESET << endl;
                tekanEnter();
                continue;
            }

            string judulBaru, studioBaru, tahunInput;

            cout << KUNING << " judul : " << RESET;
            getline(cin, judulBaru);
            if (judulBaru.empty()) {
                cout << MERAH << " judul tidak boleh kosong" << RESET << endl;
                tekanEnter();
                continue;
            }

            cout << KUNING << " tahun : " << RESET;
            getline(cin, tahunInput);
            if (!hanyaAngka(tahunInput)) {
                cout << MERAH << " tahun harus angka" << RESET << endl;
                tekanEnter();
                continue;
            }

            cout << KUNING << " studio: " << RESET;
            getline(cin, studioBaru);
            if (studioBaru.empty()) {
                cout << MERAH << " studio tidak boleh kosong" << RESET << endl;
                tekanEnter();
                continue;
            }

            listFilm[totalFilm].id = idFilmBaru++;
            listFilm[totalFilm].judul = judulBaru;
            listFilm[totalFilm].tahun = stoi(tahunInput);
            listFilm[totalFilm].studio = studioBaru;
            totalFilm++;

            cout << endl << HIJAU << TEBAL << " film ditambahkan!" << RESET << endl;
            tekanEnter();
        }
        else if (pil == 1) {
            if (totalFilm == 0) {
                cout << MERAH << " belum ada film" << RESET << endl;
                tekanEnter();
                continue;
            }

            cout << KUNING << " pilih nomor film: " << RESET;
            int nomorFilm;
            cin >> nomorFilm;
            bersihBuffer();

            if (cin.fail() || nomorFilm < 1 || nomorFilm > totalFilm) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << MERAH << " nomor tidak valid" << RESET << endl;
                tekanEnter();
                continue;
            }

            int indexPilih = nomorFilm - 1;

            while (true) {
                system("cls");
                cetakJudul("Pilih Film");

                cout << KUNING << " judul : " << RESET << listFilm[indexPilih].judul << endl;
                cout << KUNING << " tahun : " << RESET << listFilm[indexPilih].tahun << endl;
                cout << KUNING << " studio: " << RESET << listFilm[indexPilih].studio << endl;
                cout << KUNING << " review: " << RESET << jumlahReviewFilm(listFilm[indexPilih].id) << endl;

                string opsiFilm[] = {"edit film", "hapus film", "lihat review", "kembali"};
                int pilFilm = pilihMenu(opsiFilm, 4, listFilm[indexPilih].judul);

                if (pilFilm == 0) {
                    system("cls");
                    cetakJudul("Edit Film");
                    cout << KUNING << " (kosong = tidak diubah)" << RESET << endl << endl;

                    string inputBaru;

                    cout << KUNING << " judul [" << listFilm[indexPilih].judul << "]: " << RESET;
                    getline(cin, inputBaru);
                    if (!inputBaru.empty()) {
                        listFilm[indexPilih].judul = inputBaru;
                    }

                    cout << KUNING << " tahun [" << listFilm[indexPilih].tahun << "]: " << RESET;
                    getline(cin, inputBaru);
                    if (!inputBaru.empty()) {
                        if (!hanyaAngka(inputBaru)) {
                            cout << MERAH << " tahun harus angka" << RESET << endl;
                            tekanEnter();
                            continue;
                        }
                        listFilm[indexPilih].tahun = stoi(inputBaru);
                    }

                    cout << KUNING << " studio [" << listFilm[indexPilih].studio << "]: " << RESET;
                    getline(cin, inputBaru);
                    if (!inputBaru.empty()) {
                    listFilm[indexPilih].studio = inputBaru;
                    }

                    cout << endl << HIJAU << TEBAL << " film diupdate!" << RESET << endl;
                    tekanEnter();
                }
                else if (pilFilm == 1) {
                    string opsiHapus[] = {"ya hapus", "batal"};
                    int konfirmasi = pilihMenu(opsiHapus, 2, "Hapus Film?");
                    if (konfirmasi == 0) {
                        int idFilmHapus = listFilm[indexPilih].id;
                        hapusFilm(idFilmHapus);
                        cout << endl << HIJAU << TEBAL << " film dihapus" << RESET << endl;
                        tekanEnter();
                        break;
                    }
                }
                else if (pilFilm == 2) {
                    lihatDetailFilm(listFilm[indexPilih].id, true);
                }
                else {
                    break;
                }
            }
        }
        else {
            return;
        }
    }
}

#endif
