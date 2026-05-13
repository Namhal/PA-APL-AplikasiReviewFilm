#ifndef FILM_H
#define FILM_H

#include "detailfilm.h"

void menuDaftarFilm()
{
    while (true)
    {
        system("cls");
        cetakJudul("Daftar Film");

        if (totalFilm == 0)
        {
            cout << KUNING << " belum ada film" << RESET << endl;
        }
        else
        {
            // UBAH tampilan daftar film, hapus pencarian nama user pemilik film
            // cukup tampilkan nomor, judul, tahun, dan rata-rata rating
            for (int i = 0; i < totalFilm; i++)
            {
                cout << CYAN << " [" << i + 1 << "] " << RESET
                     << listFilm[i].judul << " (" << listFilm[i].tahun << ")"
                     << KUNING << " - " << rataRating(listFilm[i].id) << "/10" << RESET << endl;
            }
        }

        // HAPUS opsi "tambah film" dari menu ini
        // kurangi jumlah opsi dan sesuaikan penomoran pilihan di bawah
        string opsi[] = {"cari film", "pilih dari list", "kembali"};
        int pil = pilihMenu(opsi, 3, "Daftar Film");

        if (pil == 0)
        {
            system("cls");
            cetakJudul("Cari Film");
            cin.ignore();
            bersihBuffer();
            cout << KUNING << " ketik judul: " << RESET;
            string kataCari;
            getline(cin, kataCari);

            int indexHasil[MAX];
            int totalHasil = 0;

            for (int i = 0; i < totalFilm; i++)
            {
                string judulKecil = listFilm[i].judul;
                string cariKecil = kataCari;
                for (int j = 0; j < judulKecil.size(); j++)
                    judulKecil[j] = tolower(judulKecil[j]);
                for (int j = 0; j < cariKecil.size(); j++)
                    cariKecil[j] = tolower(cariKecil[j]);

                if (judulKecil.find(cariKecil) != string::npos)
                    indexHasil[totalHasil++] = i;
            }

            if (totalHasil == 0)
            {
                // UBAH bagian ini, jika film tidak ditemukan tawarkan opsi untuk mengusulkan
                // film tersebut ke admin, simpan usulan ke listUsulan jika user setuju
                cout << endl
                     << KUNING << " film tidak ditemukan" << RESET << endl;
                tekanEnter();
            }
            else
            {
                system("cls");
                cetakJudul("Hasil Cari");
                for (int i = 0; i < totalHasil; i++)
                    cout << CYAN << " [" << i + 1 << "] " << RESET
                         << listFilm[indexHasil[i]].judul
                         << " (" << listFilm[indexHasil[i]].tahun << ")" << endl;

                cout << endl
                     << KUNING << " pilih nomor (0 batal): " << RESET;
                int pilihanNomor;
                cin >> pilihanNomor;
                bersihBuffer();
                if (pilihanNomor >= 1 && pilihanNomor <= totalHasil)
                    lihatDetailFilm(listFilm[indexHasil[pilihanNomor - 1]].id);
            }
        }
        else if (pil == 1)
        {
            if (totalFilm == 0)
            {
                cout << MERAH << " belum ada film" << RESET << endl;
                tekanEnter();
                continue;
            }
            cout << KUNING << " pilih nomor (0 batal): " << RESET;
            int pilihanNomor;
            cin >> pilihanNomor;
            bersihBuffer();

            if (pilihanNomor >= 1 && pilihanNomor <= totalFilm)
            {
                lihatDetailFilm(listFilm[pilihanNomor - 1].id);
            }
        }
        else
            break;
    }
}

#endif
