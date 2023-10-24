#include <iostream>

using namespace std;

class Corp
{
public:
	float greutate;
	int inaltime;
	static int nrMembre;
	const float id;
	char* tipCorporal;

	Corp() :id(1.1)
	{
		this->greutate = 64.5;
		this->inaltime = 172;
		this->tipCorporal = new char[strlen("ectomorf") + 1];
		strcpy_s(tipCorporal, strlen("ectomorf") + 1, "ectomorf");
	}

	Corp(float idNou, float greutateNoua) : id(idNou), greutate(greutateNoua)
	{
		this->inaltime = 180;
		this->tipCorporal = new char[strlen("mezomorf") + 1];
		strcpy_s(tipCorporal, strlen("mezomorf") + 1, "mezomorf");
	}

	Corp(float idNou, float greutateNoua, int inaltimeNoua, char* tipCorporalNou) : id(idNou), greutate(greutateNoua), inaltime(inaltimeNoua)
	{
		this->tipCorporal = new char[strlen(tipCorporalNou) + 1];
		strcpy_s(tipCorporal, strlen(tipCorporalNou) + 1, tipCorporalNou);
	}

	~Corp()
	{
		delete[]this->tipCorporal;
	}

	void afisare()
	{
		cout << id << ". " << "O persoana are " << greutate << " kilograme si o inaltme de " << inaltime << " centimetri." << endl;
		cout << "Are " << nrMembre << " membre." << endl;
		cout << "Tipul corporal este " << tipCorporal << "." << endl;
		cout << endl;
	}

	static void setnrMembre(int nrMembreNou)
	{
		nrMembre = nrMembreNou;
	}
};

int Corp::nrMembre = 4;







class Organ
{
public:
	const float id;
	char* denumire;
	float greutate;
	static int nrOrgan;
	bool esteSanatos;

	Organ() :id(2.1)
	{
		this->denumire = new char[strlen("inima") + 1];
		strcpy_s(denumire, strlen("inima") + 1, "inima");
		this->greutate = 250;
		this->esteSanatos = 1;
	}

	Organ(float idNou, bool esteSanatosNou) : id(idNou)
	{
		this->greutate = 80;
		this->denumire = new char[strlen("pancreas") + 1];
		strcpy_s(denumire, strlen("pancreas") + 1, "pancreas");
		this->esteSanatos = esteSanatosNou;
	}

	Organ(float idNou, char* denumireNoua, float greutateNoua, bool esteSanatosNou) : id(idNou), greutate(greutateNoua), esteSanatos(esteSanatosNou)
	{
		this->denumire = new char[strlen(denumireNoua) + 1];
		strcpy_s(denumire, strlen(denumireNoua) + 1, denumireNoua);
	}

	~Organ()
	{
		delete[]this->denumire;
	}


	void afisare()
	{
		cout << id << " Organul este: " << denumire << " si are o greutate de " << greutate << " grame. Acesta " << (esteSanatos ? "este" : "nu este") << " sanatos. " << endl;
		cout << "Se afla " << nrOrgan << " in corp."<<endl;
		cout << endl;
	}

	static void setnrOrgan(int nrOrganNou)
	{
		nrOrgan = nrOrganNou;
	}
};

int Organ::nrOrgan = 1;







class Muschi
{
public:
	static int nrMuschi;
	char* nume;
	const float id;
	int masa;
	float lungime;

	Muschi() :id(3.1)
	{
		this->nume = new char[strlen("biceps") + 1];
		strcpy_s(nume, strlen("biceps") + 1,"biceps");
		this->masa = 300;
		this->lungime = 40;
	}

	Muschi(float idNou,  float lungimeNoua) : id(idNou)
	{
		this->nume = new char[strlen("triceps") + 1];
		strcpy_s(nume, strlen("triceps") + 1, "triceps");
		this->masa = 150.5;
		this->lungime =lungimeNoua;
	}

	Muschi(float idNou, char* numeNou, int masaNoua, float lungimeNoua) : id(idNou), masa(masaNoua), lungime(lungimeNoua)
	{
		this->nume = new char[strlen(numeNou) + 1];
		strcpy_s(nume, strlen(numeNou) + 1, numeNou);
	}

	~Muschi()
	{
		delete[]this->nume;
	}

	void afisare()
	{
		cout << id << ". Muschiul este: " << nume << " . Are o masa de " << masa << "de grame si o lungime/circumferinta de " << lungime << " centimetri." << endl;
		cout << "O persoana are " << nrMuschi << " muschi." << endl;
		cout << endl;
	}

	static void setnrMuschi(int nrMuschiNou)
	{
		nrMuschi = nrMuschiNou;
	}
};

int Muschi::nrMuschi = 500;





void main()
{
	Corp persoana1;
	persoana1.afisare();

	Corp persoana2(1.2, 70.1);
	persoana2.afisare();
	
	char* tipCorporal = new char[strlen("endomorf") + 1];
	strcpy_s(tipCorporal, strlen("endomorf") + 1, "endomorf");
	
	Corp persoana3(1.3, 80, 195, tipCorporal);
	persoana3.setnrMembre(3);
	persoana3.afisare();


	Organ organ1;
	organ1.afisare();
	
	Organ organ2(2.2,0);
	organ2.afisare();
	
	char* denumire = new char[strlen("plamani") + 1];
	strcpy_s(denumire, strlen("plamani") + 1, "plamani");
	
	Organ organ3(2.3, denumire, 680, 0);
	Organ::setnrOrgan(2);
	organ3.afisare();

	Muschi muschi1;
	muschi1.afisare();

	Muschi muschi2(3.2, 8);
	muschi2.afisare();

	char* nume = new char[strlen("pectoral") + 1];
	strcpy_s(nume, strlen("pectoral") + 1, "pectoral");

	Muschi muschi3(3.3, nume, 245, 15);
	Muschi::setnrMuschi(503);
	muschi3.afisare();
}