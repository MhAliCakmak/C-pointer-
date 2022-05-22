#include <iostream>
#include <Windows.h>
using namespace std;
#ifndef KUYRUK_H
#define KUYRUK_H

typedef int KuyrukVeriTipi;

struct Dugum
{
	KuyrukVeriTipi veri;
	Dugum* sonraki;
};

struct Kuyruk
{
	Dugum* bas; //kuyruğunbaşındaki elemanın adresini tutar
	Dugum* son; //kuyruğun sonundaki elemanın adresini tutar
	void olustur(); // başlangıç için gereken tanımları içerir
	void kapat(); //program bitimindebellek iadesi yapar
	void ekle(int); // kuyruğa yeni veri ekler
	int cikar(); //kuyruktan sıradaki elemanı çıkarır
	bool bosMu(); //kuyruk boş mu kontrol eder
	int size();
};

struct Yigin {
	Kuyruk k1, k2; //yığın için kullanılacak kuyruk değişkenleri
	Dugum* bas;
	void olustur(); //başlangıç için gereken tanımları içerir
	void kapat(); //program bitiminde bellek iadesi yapar
	void ekle(int); //kuyruğa yeni veri ekler
	int cikar(); //kuyruktan sıradaki elemanı çıkarır
	bool bosMu(); //kuyruk boş mu kontrol eder
	int tepe(); //yığının tepesindeki elemanı okur
	void yazdir(); //yığın elemanlarını sırayla ekrana yazar
};
int now_number = 0;


#endif // !1

void yiginCikar(Yigin* p);
void siraliEkle(Yigin* p, int b);
int main()
{
	Yigin* y = new Yigin();
	
	int choose,number;
	

	
	do {
		
		cout << "'''''''''''''''Kuyruk ve yigin programina hosgeldiniz'''''''''''''''"<<endl;
		cout<<endl << "               1)Sayi ekleme (yigini olusturduysaniz '0' ya tiklayin)" << endl << "               2)Sayi cikarma" << endl << "               3)Cikis \t";
		cin >> choose;
		if (choose == 1) {
			cout << "Sayi Giriniz : \t";
			cin >> number;
			y->ekle(number);

			
		}
		else if (choose == 2) {
			system("cls");
			cout << "orijinal yiginimiz" << endl<<endl;
			y->yazdir();
			cout << "---yiginCikar fonksiyonu cagrisi--- " << endl<<endl;
			yiginCikar(y);
			
			cout << "sirali yiginimiz" << endl;
			y->yazdir();
		}
		else if (choose == 3) {
			cout << "Cikis yapiliyor";
			break;
		}
		else if (choose == 0) {
			cout << "aktif yiginimiz" << endl<<endl;
			y->yazdir();
			
		}
		else {
			cout << "Eksik veya hatali tusladiniz.";
			continue;
		}
		
	} while (true);
	

	return 0;
}






//""""""""""""""""Kuyruk""""""""""""""""""""""""

void Kuyruk::olustur()
{
	bas = NULL;
	son = NULL;
}
void Kuyruk::kapat()
{
	Dugum* p;

	while (bas) {
		p = bas;
		bas = bas->sonraki;
		delete p;
		now_number = 0;
	}
}
void siraliEkle(Yigin* s, int x) {
	if (s->bosMu() or x > s->tepe())
	{
		s->ekle(x);
		return;
	}
	else
	{
		int temp = s->cikar();
		siraliEkle(s, x);
		s->ekle(temp);
	}

}

void Kuyruk::ekle(int eklenenveri)
{
	Dugum* yenidugum = new Dugum;
	yenidugum->veri = eklenenveri;
	yenidugum->sonraki = NULL;
	if (bas == NULL)
	{
		bas = yenidugum;
		son = bas;
	}
	else {
		son->sonraki = yenidugum;
		son = yenidugum;
	}
}
int Kuyruk::cikar()
{
	Dugum* ustdugum;
	KuyrukVeriTipi gecici;
	ustdugum = bas;
	bas = bas->sonraki;
	gecici = ustdugum->veri;
	delete ustdugum;
	return gecici;
	now_number--;
}

int Kuyruk::size()
{
	return now_number;
}
bool Kuyruk::bosMu()
{
	return bas == NULL;
}


// """"""""""""""""YIGIN""""""""""""""""""""

void Yigin::olustur()
{
	bas = NULL;
}
void Yigin::ekle(int x)
{
	k2.ekle(x);

	while (!k1.bosMu())
	{
		k2.ekle(k1.bas->veri);
		k1.cikar();
	}
	Kuyruk q = k1;
	k1 = k2;
	k2 = q;
}
void Yigin::kapat()
{
	Dugum* p;
	while (bas)
	{
		p = bas;
		bas = bas->sonraki;
		delete p;
	}
}

int Yigin::cikar()
{
	if (k1.bosMu())
		return 0;
	else
		k1.cikar();
}

void Yigin::yazdir()
{
	Dugum* tara;
	tara = k1.bas;
	if (!tara)
	{
		cout << "Liste Bos!" << endl;
		return;
	}
	while (tara) {
		cout << tara->veri << " ";
		tara = tara->sonraki;
	}
	cout << endl;
}
bool Yigin::bosMu()
{
	return k1.bas == NULL;
}

int Yigin::tepe()
{
	if (k1.bosMu())
		return 0;
	return k1.bas->veri;
}



void yiginCikar(Yigin* p) {
	if (!p->bosMu())
	{

		int x = p->cikar();

		yiginCikar(p);
		siraliEkle(p, x);
	}
}