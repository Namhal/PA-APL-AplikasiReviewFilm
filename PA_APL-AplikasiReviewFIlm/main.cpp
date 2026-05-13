#include "koleksi.h"
#include "kelolafilm.h"
#include "kelolauser.h"

void menuAdmin()
{
    while (true)
    {
        string opsi[] = {"kelola film", "kelola user", "logout"};
        int pil = pilihMenu(opsi, 3, "Admin, " + userAktif->username + "!");

        if (pil == 0)
        {
            menuKelolaFilm();
        }
        else if (pil == 1)
        {
            menuKelolaUser();
        }
        else
        {
            system("cls");
            cout << endl
                 << HIJAU << TEBAL << " sampai jumpa, " << userAktif->username << "!" << RESET << endl;
            userAktif = nullptr;
            tekanEnter();
            break;
        }
    }
}

int main()
{
    listUser[totalUser].id = idUserBaru++;
    listUser[totalUser].username = "admin";
    listUser[totalUser].password = "admin123";
    listUser[totalUser].role = "admin";
    totalUser++;

    listUser[totalUser].id = idUserBaru++;
    listUser[totalUser].username = "user";
    listUser[totalUser].password = "user123";
    listUser[totalUser].role = "user";
    totalUser++;

    while (true)
    {
        string opsi[] = {"login", "keluar"};
        int pil = pilihMenu(opsi, 2, "Review Film & Serial");

        if (pil == 0)
        {
            userAktif = prosesLogin();
            if (userAktif != nullptr)
            {
                if (userAktif->role == "admin")
                {
                    menuAdmin();
                }
                else
                {
                    menuUser();
                }
            }
        }
        else
        {
            system("cls");
            cout << endl
                 << CYAN;
            cetakGaris('=', 42);
            cout << " " << KUNING << "makasih sudah pake aplikasinya!" << RESET << endl;
            cout << CYAN;
            cetakGaris('=', 42);
            cout << RESET << endl
                 << endl;
            break;
        }
    }
    return 0;
}
