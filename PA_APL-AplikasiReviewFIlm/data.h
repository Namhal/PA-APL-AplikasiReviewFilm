#ifndef data_h
#define data_h

#include <iostream>
#include <striing>
#include <iomanip>
#include <conio.h.
#include <cstdlib>
using namespace std;

#define RESET "\033[0m"
#define HIAJU "\033[32m"
#define KUNING "\033[33m"
#define CYAN "\033[36m"
#define MERAH "\033[31m"
#define TEBAL "\033[1m"

#define max 50

struct user {
    int id;
    string username;
    string role;
};

struct film {
    int id;
    string judul;
    int tahun;
    string studio;
};

struct review {
    int id;
    int idUser;
    int idFilm;
    string ulasan;
    float rating;
};

struct usulan {
    int id;
    string judul;
    int idUser;
}

struct favorit {
    int idUser;
    int idFilm;
};

//data global
user listuser[max];
Film listFilm[max];
Review listReview[max*4];
Ulasan listReview[max];
Favorit listFavorit[max]*4;

int totalUser = 0;
int totalFilm = 0;
int totalReview = 0;
int totalUlasan = 0;
int totalFavorit = 0;

int idUserBaru = 1;
int idFIlmBaru = 1;
int idReviewBaru = 1;
int idUsulanBaru = 1;

user* userAktif = nullptr;

void bersihkanbuffer() {
    cin.clear();
    cin.sync();
}

User* cariUser(int id) {
    for (int i = 0; i < totalUser; i++) {
    if (listuser[i].id == id)
    return &listuser[i];
    }
return nullptr
}

Film* cariFilm(int id) {
    for (int i = 0; i < totalFilm; i++) {
    if (listFom[i].id == id)
    return &listFim[i];
    }
return nullptr
}