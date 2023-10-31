#include <iostream>

using namespace std;

class Corp
{
private:
	float greutate;
	int inaltime;
	static int nrMembre;
	const float id;
	char* tipCorporal;


public:
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

	Corp(const Corp& c) : id(c.id)
	{
		greutate = c.greutate;
		inaltime = c.inaltime;
		this->tipCorporal = new char[strlen("aaaaaaaa") + 1];
		this->tipCorporal = c.tipCorporal;
	}

	Corp operator=(const Corp& c)
	{
		if (this != &c)
		{
			delete[]this->tipCorporal;
			greutate = c.greutate;
			inaltime = c.inaltime;
			this->tipCorporal = new char[strlen("aaaaaaaa") + 1];
			this->tipCorporal = c.tipCorporal;
			return *this;
		}
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

	void setGreutate(float greutate)
	{
		this->greutate = greutate;
	}

	float getGreutate()
	{
		return this->greutate;
	}

	void setInaltime(int inaltime)
	{
		this->inaltime = inaltime;
	}

	int getInaltime()
	{
		return this->inaltime;
	}

	static int getNrMembre()
	{
		return Corp::nrMembre;
	}

	static void setnrMembre(int nrMembreNou)
	{
		nrMembre = nrMembreNou;
	}

	const int getId()
	{
		return this->id;
	}

	char* getTipCorporal()
	{
		return this->tipCorporal;
	}

	void setTipCorporal(char* tipCorporal)
	{
		delete[]this->tipCorporal;
		this->tipCorporal = new char[strlen("aaaaaaaa") + 1];
		this->tipCorporal = tipCorporal;
	}
};

int Corp::nrMembre = 4;







class Organ
{
private:
	const float id;
	char* denumire;
	float greutate;
	static int nrOrgan;
	bool esteSanatos;

public:

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

	Organ(const Organ& o) :id(o.id)
	{
		greutate = o.greutate;
		esteSanatos = o.esteSanatos;
		this->denumire= new char[strlen("aaaaaaaaaaaaa") + 1];
		this->denumire = o.denumire;
	}

	Organ operator=(const Organ& o)
	{
		if (this != 0)
		{
			delete[]this->denumire;
		}
		greutate = o.greutate;
		esteSanatos = o.esteSanatos;
		this->denumire = new char[strlen("aaaaaaaaaaaaa") + 1];
		this->denumire = o.denumire;
		return *this;

	}
	~Organ()
	{
		delete[]this->denumire;
	}


	void afisare()
	{
		cout << id << " Organul este: " << denumire << " si are o greutate de " << greutate << " grame. Acesta " << (esteSanatos ? "este" : "nu este") << " sanatos. " << endl;
		cout << "Se afla " << nrOrgan << " in corp." << endl;
		cout << endl;
	}

	void setGreutate(float greutate)
	{
		this->greutate = greutate;
	}

	float getGreutate()
	{
		return this->greutate;
	}

	static int getNrOrgan()
	{
		return Organ::nrOrgan;
	}

	static void setnrOrgan(int nrOrganNou)
	{
		nrOrgan = nrOrganNou;
	}

	void setEsteSanatos(bool esteSanatos)
	{
		this->esteSanatos = esteSanatos;
	}

	bool getEsteSanatos()
	{
		return this->esteSanatos;
	}

	char* getDenumire()
	{
		return this->denumire;
	}

	void setDenumire(char* denumire)
	{
		delete[]this->denumire;
		this->denumire = new char[strlen("aaaaaaaaaaaa") + 1];
		this->denumire = denumire;
	}
	
	const int getId()
	{
		return this->id;
	}

};

int Organ::nrOrgan = 1;







class Muschi
{
private:
	static int nrMuschi;
	char* nume;
	const float id;
	int masa;
	float lungime;


public:
	Muschi() :id(3.1)
	{
		this->nume = new char[strlen("biceps") + 1];
		strcpy_s(nume, strlen("biceps") + 1, "biceps");
		this->masa = 300;
		this->lungime = 40;
	}

	Muschi(float idNou, float lungimeNoua) : id(idNou)
	{
		this->nume = new char[strlen("triceps") + 1];
		strcpy_s(nume, strlen("triceps") + 1, "triceps");
		this->masa = 150.5;
		this->lungime = lungimeNoua;
	}

	Muschi(float idNou, char* numeNou, int masaNoua, float lungimeNoua) : id(idNou), masa(masaNoua), lungime(lungimeNoua)
	{
		this->nume = new char[strlen(numeNou) + 1];
		strcpy_s(nume, strlen(numeNou) + 1, numeNou);
	}

	Muschi(const Muschi& m) :id(m.id)
	{
		masa = m.masa;
		lungime = m.lungime;
		this->nume = new char[strlen("aaaaaaaaaaaaa") + 1];
		this->nume = m.nume;
	}

	Muschi operator=(const Muschi& m)
	{
		if (this != &m)
		{
			delete[]this->nume;
			masa = m.masa;
			lungime = m.lungime;
			this->nume = new char[strlen("aaaaaaaaaaaaa") + 1];
			this->nume = m.nume;

		}
		return *this;
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

	static int getNrMuschi()
	{
		return Muschi::nrMuschi;
	}

	static void setnrMuschi(int nrMuschiNou)
	{
		nrMuschi = nrMuschiNou;
	}
	char* getNume()
	{
		return this->nume;
	}

	void setNume(char* nume)
	{
		delete[]this->nume;
		this->nume = new char[strlen("aaaaaaaaaaaa") + 1];
		this->nume= nume;
	}
	const int getId()
	{
		return this->id;
	}

	void setMasa(int masa)
	{
		this->masa = masa;
	}

	int getInaltime()
	{
		return this->masa;
	}


	void setLungime(float lungime)
	{
		this->lungime = lungime;
	}

	float getLungime()
	{
		return this->lungime;
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

	Organ organ2(2.2, 0);
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




	/*Corp persoana4(persoana1);
	Corp persoana5 = persoana1;
	Corp persoana6;
	persoana6 = persoana1;
	persoana2.afisare();
	persoana2 = persoana2;
	persoana2.afisare();
	persoana6.setGreutate(35.8);
	cout << persoana6.getGreutate() << endl;


	delete[]tipCorporal;



	Organ organ5(organ1);
	Organ organ4 = organ1;
	Organ organ6;
	organ5 = organ2;
	organ2.afisare();
	organ2 = organ2;
	organ2.afisare();
	organ6.setGreutate(2.3);
	cout << organ6.getGreutate() << endl;

	delete[]denumire;



	Muschi muschi5(muschi2);
	muschi3 = muschi2;
	Muschi muschi4;
	muschi4=muschi1;
	muschi1.afisare();
	muschi3 = muschi3;
	muschi3.afisare();
	muschi5.getInaltime();
	cout << muschi5.getInaltime() << endl;

	delete[]nume;*/
}
