#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
const int number = 10000;

int sayac1 = 0, sayac2 = 0;


struct ArrayList {
    int* bas;
    void olustur();
    void ekle(int, int);
    void guncelle(int, int);
    void sil(int);
    void yazdir();
    void bosalt();
    int sayac;
};

struct Node {
    int deger;
    Node* sonraki;
};

struct LinkedList {
    Node* bas;
    void olustur();
    void ekle(int, int);
    void guncelle(int, int);
    void sil(int);
    void yazdir();
    void bosalt();
    int sayac;
};

int main() {
    LinkedList* l = new LinkedList();
    l->olustur();
    ArrayList* a = new ArrayList();
    a->olustur();
    int result;
    int special, _value, _siraNumarasi;

    do {
        cout << "+++++++++++++++++++" << endl << "Programima hosgeldiniz lutfen seciminizi yapiniz" << endl << "+++++++++++++++++++" << endl << "1)Programa giris" << endl << "2)Cikis" << endl;
        cin >> result;
        if (result == 1) {

            cout << "deger giriniz" << endl;
            cin >> _value;

            cout << "sira numarasi giriniz" << endl;
            cin >> _siraNumarasi;
            for (int i = 0;i < number;i++) {
                a->ekle(i, i);
            }
            for (int i = 0;i < number;i++) {
                l->ekle(i, i);
            }
            auto begin1 = chrono::high_resolution_clock::now();
            l->ekle(_value, _siraNumarasi);
            auto end1 = std::chrono::high_resolution_clock::now();
            auto elapsed1 = std::chrono::duration_cast<chrono::nanoseconds>(end1 - begin1);

            auto begin2 = chrono::high_resolution_clock::now();
            l->ekle(_value, _siraNumarasi);
            auto end2 = std::chrono::high_resolution_clock::now();
            auto elapsed2 = std::chrono::duration_cast<chrono::nanoseconds>(end2 - begin2);
            

            cout << number<< " elemanli bir listede:  ";
            cout << "LinkedList ile Ekleme Suresi=> " << elapsed1.count() << " nano - saniye" << endl;
            cout << "ArrayList ile Ekleme Suresi=> " << elapsed2.count() << " nano - saniye" << endl;
            break;
        }
        else if (result == 2) {
            exit(1);
        }
        else {
            cout << "+++++++++++++++++++" << endl << "Error or mistake number" << endl;
            continue;
        }
    } while (100);

    return 0;

}

//olusturma

void LinkedList::olustur() {
    bas = NULL;
    sayac = 0;
}


//ekleme

void LinkedList::ekle(int _deger, int _siraNumarasi) {
    Node* n = new Node();
    n->deger = _deger;
    Node* tara;
    tara = bas;

    if (bas == NULL) {
        bas = n;
        return;
    }

    while (tara) {
        sayac++;
        tara = tara->sonraki;
    }
    tara = bas;
    for (int i = 0;i < _siraNumarasi - 1;i++) {
        tara = tara->sonraki;
    }
    n->sonraki = tara->sonraki;
    tara->sonraki = n;
}
//guncelle
void LinkedList::guncelle(int _deger, int siraNumarasi) {

    Node* u_node = new Node();
    u_node->deger = _deger;


    Node* tara;
    tara = bas;
    for (int i = 0;i < siraNumarasi;i++) {
        tara = tara->sonraki;

    }
    if (tara != NULL) {
        u_node->sonraki = tara->sonraki;
        *u_node = *tara;
    }
    else {
        cout << "Girilen kullanici girisi hatali" << endl;
    }
}

//yazdir
void LinkedList::yazdir() {
    Node* tara;
    tara = bas;
    if (!tara) {
        cout << "listenin ici bos" << endl;
        return;
    }
    while (tara) {
        cout << tara->deger <<endl;
        tara = tara->sonraki;
    }
    cout << endl;
}


//bosalt
void LinkedList::bosalt() {
    Node* p;
    while (bas) {
        p = bas;
        bas = bas->sonraki;
        delete p;
    }
    sayac = 0;
}

//sil
void LinkedList::sil(int _siraNumarasi) {
    Node* tara, * arka;

    arka = tara = bas;
    if (_siraNumarasi <= 0) {
        cout << "Hatali kayit sira numarasi."<<endl;
        return;
    }
    if (_siraNumarasi == 1) {
        bas = bas->sonraki;
        delete tara;
        sayac--;
        return;
    }
    while (tara != NULL) {
        arka = tara;
        tara = tara->sonraki;

    }
    if (sayac < _siraNumarasi) {
        cout << "Silenecek kayit yok" << endl;
    }
    else {
        arka->sonraki = tara->sonraki;
        delete tara;
        sayac--;
    }

}

void ArrayList::olustur() {
    bas = NULL;
    sayac = 0;
}
int arr[number];
void ArrayList::ekle(int a, int b) {


    if (sayac == 0) {
        bas = new int[1];
        bas[b] = a;
    }
    else {
        int* gecici = bas;
        bas = new int[sayac + 1];
        for (int i = 0; i < b; i++)
            bas[i] = gecici[i];
        bas[b] = a;
        for (int i = b + 1; i < sayac + 1; i++)
            bas[i] = gecici[i];
    }

    sayac++;
}
void ArrayList::guncelle(int sirano, int yenieleman) {
    for (int i = 0;i < sirano;i++) {
        arr[sirano - 1] = yenieleman;
        //*(bas + sirano - 1) = yenieleman;
    }
}

void ArrayList::sil(int sirano) {

    int* tara = bas;
    for (int i = sirano;i < number;i++) {
        *(tara + i - 1) = *(tara + i);
        sayac1++;
    }
}

void ArrayList::bosalt() {
    int* tara = bas;
    for (int i = sayac;i > 0;i--) {
        *(tara + i - 1) = *(tara + i);
        //sayac2=30;
    }

}
void ArrayList::yazdir() {
    for (int i = 0;i < sayac;i++) {
        cout << *(bas + i) << " ";
    }

    cout << endl;
}