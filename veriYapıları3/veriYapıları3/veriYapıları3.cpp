#include <iostream>
#include <stack>
#include <queue>
#include <chrono>


using namespace std;
#define UZUNLUK 68	//dizilerde yer alan eleman sayısı

int dizi1[] = { 1064,1065,1066,1067,1068,1069,1070,1071,1072,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,2001,2002,2003,2004,2013,2014,2015,3001,3002,3003,3004,3005,3006,3007,3008,3009,3010,3011,3012,3013,3014,3015,3016,3017,3018,3019,3020,3021,3022,3023,3024,3025,3026,3027,3028,3029,3030,3031,3032,3033,3034,3035,3036,3037,3038,3039,3040,3041 };	//agac1 için kullanılacak veriler
int dizi2[] = { 3041,3040,3039,3038,3037,3036,3035,3034,3033,3032,3031,3030,3029,3028,3027,3026,3025,3024,3023,3022,3021,3020,3019,3018,3017,3016,3015,3014,3013,3012,3011,3010,3009,3008,3007,3006,3005,3004,3003,3002,3001,2015,2014,2013,2004,2003,2002,2001,1083,1082,1081,1080,1079,1078,1077,1076,1075,1074,1073,1072,1071,1070,1069,1068,1067,1066,1065,1064 };	//agac2 için kullanılacak veriler
int dizi3[] = { 3039,1074,3010,1082,3016,3005,3008,3014,3015,3023,3025,2002,3021,3035,1077,1065,1069,1073,3011,2004,3020,3001,3030,1076,1081,3031,3040,1071,3013,3029,3036,3027,3033,1070,3038,1068,1080,3037,2014,3003,3007,1072,1066,1083,2015,2003,3018,3024,3034,3009,3012,3019,3028,1078,3017,2001,1079,3041,1067,2013,3026,1064,3004,3022,3006,1075,3032,3002 };	//agac3 için kullanılacak veriler

struct Dugum {		//Agacta yer alan her bir dugumun veri yapisi
	int veri; 		//Dugumde tutulan veri
	Dugum* sag;	//Dugumun sag cocuguna isaretci
	Dugum* sol;  	//Dugumun sol cocuguna isaretci
};

struct IkiliSiralamaAgaci {	//Ikili siralama agaci veri yapisi
	Dugum* kok;			//Agac kokune isaretci
	void agacKur(int*);	//Dizi isaretcisi alir ve dizinin elemanlarini ikili siralama agacina uygun sekilde yerlestirir
	void agacKapat();		//Agacin dugumleri icin alinan bellek gozlerini program sonlanmadan hemen once iade eder
};


bool DFS(Dugum*, int);	//Ilk derinlik arama fonksiyonu bir agac koku ve aranacak deger parametrelerini alir
bool BFS(Dugum*, int);//Ilk genislik arama fonksiyonu bir agac koku ve aranacak deger parametrelerini alir

int pastTimeDFS;
int pastTimeBFS;
int chooseagac, choosearama;
int main()
{
	
	IkiliSiralamaAgaci* agac1 = new IkiliSiralamaAgaci();
	IkiliSiralamaAgaci* agac2 = new IkiliSiralamaAgaci();
	IkiliSiralamaAgaci* agac3 = new IkiliSiralamaAgaci();
	
	
	for (int i = 0; i < UZUNLUK; i++)
	{
		agac1->agacKur(dizi1 + i);
		agac2->agacKur(dizi2 + i);
		agac3->agacKur(dizi3 + i);
	}
	do {
		cout << "Merhaba Programa Hosgeldiniz " << endl;
		
		cout << "Arama yapacaginiz agaci seciniz (1,2,3):" << endl;
		
		cin >> chooseagac;
		
		cout << endl;
		if (chooseagac == 1)
	{
		int value;
		cout << "Agac 1 icin arama yontemini seciniz (DFS:1,BFS:2):" << endl;
		cin >> choosearama;
		cout << endl;
		
		bool gelendeger;
		if (choosearama == 1)
		{
			cout << "Agac 1 uzerinde DFS ile arayacaginiz degeri giriniz:" << endl;
			
			cin >> value;
			cout << endl;
			gelendeger = DFS(agac1->kok, value);

			if (gelendeger == true)
			{
				cout << "SONUC => VERI BULUNDU" << endl;
				cout << "GECEN SURE => " << pastTimeDFS << " nano-saniye" << endl;
			}
			else
			{
				cout << "Aranan deger bulunamadi" << endl;;
			}
		}
		if (choosearama == 2)
		{
			cout << "Agac 1 uzerinde BFS ile arayacaginiz degeri giriniz:" << endl;
			
			cin >> value;
			cout << endl;
			gelendeger = BFS(agac1->kok, value);

			if (gelendeger == true)
			{
				cout << "SONUC => VERI BULUNDU" << endl;
				cout << "GECEN SURE => " << pastTimeBFS << " nano-saniye" << endl;

			}
			else
			{
				cout << "Aranan deger bulunamadi" << endl;;
			}
		}
	}
	if (chooseagac == 2)
	{
		cout << "Agac 2 icin arama yontemini seciniz (DFS:1,BFS:2):" << endl;
		
		cin >> choosearama;
		cout << endl;
		int deger;
		bool gelendeger;
		if (choosearama== 1)
		{
			cout << "Agac 2 uzerinde DFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			cout << endl;
			
			gelendeger = DFS(agac2->kok, deger);

			if (gelendeger == true)
			{
				cout << "SONUC => VERI BULUNDU" << endl;
				cout << "GECEN SURE => " << pastTimeDFS << " nano-saniye" << endl;
			}
			else
			{
				cout << "Aranan deger bulunamadi" << endl;;
			}
		}
		if (choosearama == 2)
		{
			cout << "Agac 2 uzerinde BFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			cout << endl;
			gelendeger = BFS(agac2->kok, deger);

			if (gelendeger == true)
			{
				cout << "SONUC => VERI BULUNDU" << endl;
				cout << "GECEN SURE => " << pastTimeBFS << " nano-saniye" << endl;

			}
			else
			{
				cout << "Aranan deger bulunamadi" << endl;;
			}
		}
	}
	if (chooseagac == 3)
	{
		cout << "Agac 3 icin arama yontemini seciniz (DFS:1,BFS:2):" << endl;
		cin >> choosearama;
		cout << endl;
		int deger;
		bool gelendeger;
		if (choosearama == 1)
		{
			cout << "Agac 3 uzerinde DFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			cout << endl;
			gelendeger = DFS(agac3->kok, deger);

			if (gelendeger == true)
			{
				cout << "SONUC => VERI BULUNDU" << endl;
				cout << "GECEN SURE => " << pastTimeDFS << " nano-saniye" << endl;
			}
			else
			{
				cout << "Aranan deger bulunamadi" << endl;
			}
		}
		if (choosearama == 2)
		{
			cout << "Agac 3 uzerinde BFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			cout << endl;

			gelendeger = BFS(agac3->kok, deger);

			if (gelendeger == true)
			{
				cout << "SONUC => VERI BULUNDU" << endl;
				cout << "GECEN SURE => " << pastTimeBFS << " nano-saniye" << endl;

			}
			else
			{
				cout << "Aranan deger bulunamadi" << endl;
			}
		}
	}
	} while (true);

	
	
	
	
}

bool DFS(Dugum* node, int veri)
{
	auto begin1 = chrono::high_resolution_clock::now();

	stack <Dugum*> yigin;
	yigin.push(node);
	while (!yigin.empty())
	{
		node = yigin.top();
		yigin.pop();
		if (veri == node->veri)
		{
			
			
			auto end1 =
				chrono::high_resolution_clock::now();
			auto elapsed1 = chrono::duration_cast<chrono::nanoseconds>(end1 - begin1);
			pastTimeDFS = elapsed1.count();
			return true;
		}
		else {
			if (node->sag)
			{
				yigin.push(node->sag);
			}
			if (node->sol)
			{
				yigin.push(node->sol);
			}
		}
	}
	auto end1 = chrono::high_resolution_clock::now();
	auto elapsed1 = chrono::duration_cast<chrono::nanoseconds>(end1 - begin1);
	pastTimeDFS = elapsed1.count();
	return false;
}



void IkiliSiralamaAgaci::agacKur(int* adres)
{
	Dugum* tara, * yeni;
	tara = kok;
	int karsilas;
	bool eklendi = false;
	yeni = new Dugum;
	yeni->veri = *adres;
	yeni->sag = NULL;
	yeni->sol = NULL;
	if (kok == NULL)
	{
		kok = yeni;
	}
	else
	{
		while ((tara != NULL) && (!eklendi))
		{
			if (tara->veri > yeni->veri)
			{
				if (tara->sol != NULL)
				{
					tara = tara->sol;
				}
				else {
					tara->sol = yeni;
					eklendi = true;
				}
			}

			if (tara->veri < yeni->veri)
			{
				if (tara->sag != NULL)
				{
					tara = tara->sag;
				}
				else
				{
					tara->sag = yeni;
					eklendi = true;
				}
			}
		}
	
	}

}




bool BFS(Dugum* dugumKok, int aranacakVeri)
{
	auto begin2 =chrono::high_resolution_clock::now();

	queue <Dugum*> kuyruk;
	kuyruk.push(dugumKok);
	while (!kuyruk.empty())
	{
		dugumKok = kuyruk.front();
		kuyruk.pop();
		if (aranacakVeri == dugumKok->veri)
		{
			auto end2 = chrono::high_resolution_clock::now();
			auto elapsed2 =chrono::duration_cast<chrono::nanoseconds>(end2 - begin2);
			pastTimeBFS = elapsed2.count();
			return true;
		}
		else {
			if (dugumKok->sol)
			{
				kuyruk.push(dugumKok->sol);
			}
			if (dugumKok->sag)
			{
				kuyruk.push(dugumKok->sag);
			}
		}
	}


	auto end2 = chrono::high_resolution_clock::now();
	auto elapsed2 = chrono::duration_cast<chrono::nanoseconds>(end2 - begin2);
	pastTimeBFS = elapsed2.count();
	return 0;
}

void IkiliSiralamaAgaci::agacKapat()
{

}
