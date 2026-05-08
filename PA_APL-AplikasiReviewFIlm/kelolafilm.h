#ifndef KELOLAFILM_H
#define KELOLAFILM_H

#include "detailfilm.h"

void menuKelolaFilm()
{
    while (true)
    {
        string opsiUtama[] = {"tambah film", "pilih film", "kembali"};
        int pil = pilihMenu(opsiUtama, 3, "Kelola Film");

        if (pil == 0)
        {
            system("cls");
            cetakJudul("Tambah Film");

            if (totalFilm >= MAX)
            {
                cout << MERAH << " kapasitas film penuh" << RESET << endl;
                tekanEnter();
                continue;
            }

            string judulBaru, studioBaru, inputTahun;
            int tahunBaru = 0;

            cout << KUNING << " judul : " << RESET;
            judulBaru = bacaInputBaris();
            if (judulBaru.empty())
            {
                cout << MERAH << " judul tidak boleh kosong" << RESET << endl;
                tekanEnter();
                continue;
            }

            cout << KUNING << " tahun : " << RESET;
            inputTahun = bacaInputBaris();
            if (inputTahun.empty())
            {
                cout << MERAH << " tahun tidak boleh kosong" << RESET << endl;
                tekanEnter();
                continue;
            }

            if (!hanyaAngka(inputTahun))
            {
                cout << MERAH << " tahun harus angka" << RESET << endl;
                tekanEnter();
                continue;
            }
            tahunBaru = stoi(inputTahun);

            cout << KUNING << " studio: " << RESET;
            studioBaru = bacaInputBaris();
            if (studioBaru.empty())
            {
                cout << MERAH << " studio tidak boleh kosong" << RESET << endl;
                tekanEnter();
                continue;
            }

            listFilm[totalFilm].id = idFilmBaru++;
            listFilm[totalFilm].judul = judulBaru;
            listFilm[totalFilm].tahun = tahunBaru;
            listFilm[totalFilm].studio = studioBaru;
            totalFilm++;

            cout << endl
                 << HIJAU << TEBAL << " film berhasil ditambahkan!" << RESET << endl;
            tekanEnter();
        }
        else if (pil == 1)
        {
            if (totalFilm == 0)
            {
                system("cls");
                cetakJudul("Kelola Film");
                cout << MERAH << " belum ada film" << RESET << endl;
                tekanEnter();
                continue;
            }

            string daftarFilm[MAX + 1];
            for (int i = 0; i < totalFilm; i++)
            {
                int jumlahReview = 0;
                for (int j = 0; j < totalReview; j++)
                {
                    if (listReview[j].idFilm == listFilm[i].id)
                    {
                        jumlahReview++;
                    }
                }

                daftarFilm[i] = listFilm[i].judul + " (" + to_string(listFilm[i].tahun) + ") - " + listFilm[i].studio + " | review: " + to_string(jumlahReview);
            }
            daftarFilm[totalFilm] = "kembali";

            int pilihanDaftar = pilihMenu(daftarFilm, totalFilm + 1, "Pilih Film");
            if (pilihanDaftar == totalFilm)
            {
                continue;
            }

            int indexPilih = pilihanDaftar;

            while (true)
            {
                system("cls");
                cetakJudul("Film Dipilih");
                cout << KUNING << " judul : " << RESET << listFilm[indexPilih].judul << endl;
                cout << KUNING << " tahun : " << RESET << listFilm[indexPilih].tahun << endl;
                cout << KUNING << " studio: " << RESET << listFilm[indexPilih].studio << endl;
                string opsiFilm[] = {"edit film", "hapus film", "lihat review", "kembali"};
                int pilihanFilm = pilihMenu(opsiFilm, 4, "Film Dipilih");

                if (pilihanFilm == 0)
                {
                    system("cls");
                    cetakJudul("Edit Film");
                    cout << KUNING << " kosongkan input untuk mempertahankan nilai lama" << RESET << endl
                         << endl;

                    cout << KUNING << " judul  [" << listFilm[indexPilih].judul << "]: " << RESET;
                    updateTeksJikaDiisi(listFilm[indexPilih].judul);

                    cout << KUNING << " tahun  [" << listFilm[indexPilih].tahun << "]: " << RESET;
                    if (!updateAngkaJikaDiisi(listFilm[indexPilih].tahun))
                    {
                        cout << MERAH << " tahun harus angka" << RESET << endl;
                        tekanEnter();
                        continue;
                    }

                    cout << KUNING << " studio [" << listFilm[indexPilih].studio << "]: " << RESET;
                    updateTeksJikaDiisi(listFilm[indexPilih].studio);

                    cout << endl
                         << HIJAU << TEBAL << " film berhasil diupdate!" << RESET << endl;
                    tekanEnter();
                }
                else if (pilihanFilm == 1)
                {
                    string opsiHapus[] = {"ya hapus", "batal"};
                    if (pilihMenu(opsiHapus, 2, "Hapus Film?") == 0)
                    {
                        int idFilm = listFilm[indexPilih].id;
                        hapusFilm(idFilm);
                        system("cls");
                        cout << endl
                             << HIJAU << TEBAL << " film berhasil dihapus" << RESET << endl;
                        tekanEnter();
                        break;
                    }
                }
                else if (pilihanFilm == 2)
                {
                    lihatDetailFilm(listFilm[indexPilih].id, true);
                    if (indexPilih >= totalFilm)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
}

#endif
