//Domeniul ales: ANATOMIE

#include <iostream>
#include <fstream>

using namespace std;

//PRIMA CLASA ABSTRACTA

//class CorpAbstract
//{
//public:
//
//	virtual void afisareDescriere() = 0;
//};

//PRIMA CLASA

class Corp
{
private:

	const float id;
	static int nrMembre;
	int inaltime;
	float greutate;
	char* tipCorporal;

public:

	//primul constructor

	Corp() : id(1.1)
	{
		this->inaltime = 172;
		this->greutate = 64.5;
		this->tipCorporal = new char[strlen("ectomorf") + 1];
		strcpy_s(this->tipCorporal, strlen("ectomorf") + 1, "ectomorf");
	}

	//al doilea constructor

	Corp(float idNou, float greutateNoua) : id(idNou)
	{
		this->inaltime = 180;
		this->greutate = greutateNoua;
		this->tipCorporal = new char[strlen("mezomorf") + 1];
		strcpy_s(this->tipCorporal, strlen("mezomorf") + 1, "mezomorf");
	}

	//al treilea constructor

	Corp(float idNou, int inaltimeNoua, float greutateNoua, char* tipCorporalNou) : id(idNou), inaltime(inaltimeNoua), greutate(greutateNoua), tipCorporal(tipCorporalNou)
	{

	}

	//constructor de copiere

	Corp(const Corp& c) :id(c.id)
	{
		this->inaltime = c.inaltime;
		this->greutate = c.greutate;
		this->tipCorporal = new char[strlen("mezomorf") + 1];
		this->tipCorporal = c.tipCorporal;
	}

	//destructor

	 ~Corp()
	{
		delete[]this->tipCorporal;
		this->tipCorporal = NULL;
	}


	//afisare

		/*void afisare()
		{
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			cout << id << endl<<"Aceasta persoana are " << greutate << " kilograme si o inaltme de " << inaltime << " centimetri." << endl;
			cout << "Are " << nrMembre << " membre." << endl;
			cout << "Tipul corporal este " << tipCorporal << "." << endl;
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			cout << endl;
		}*/

		//getteri

	const float getId()
	{
		return this->id;
	}

	static int getNrMembre()
	{
		return nrMembre;
	}

	int getInaltime()
	{
		return this->inaltime;
	}

	float getGreutate()
	{
		return this->greutate;
	}

	char* getTipCorporal()
	{
		return this->tipCorporal;
	}

	//setteri

	static void setNrMembre(int nrMembreN)
	{
		Corp::nrMembre = nrMembreN;
	}

	void setInaltime(int inaltimeN)
	{
		this->inaltime = inaltimeN;
	}

	void setGreutate(float greutateN)
	{
		this->greutate = greutateN;
	}

	void setTipCorporal(char* tipCorporalN)
	{
		if (this->tipCorporal != NULL)
			delete[]this->tipCorporal;
		this->tipCorporal = new char[strlen("mezomorf") + 1];
		this->tipCorporal = tipCorporalN;
	}

	//functiile prietene

	friend ostream& operator<<(ostream& ecran, const Corp& c);
	friend istream& operator>>(istream& tastatura, Corp& c);

	//supraincarcare operator =

	Corp& operator=(const Corp& c)
	{
		if (this != &c)
		{
			if (this->tipCorporal != NULL)
			{
				delete[]this->tipCorporal;

			}
			this->inaltime = c.inaltime;
			this->greutate = c.greutate;
			this->tipCorporal = new char[strlen(c.tipCorporal) + 1];
			strcpy_s(this->tipCorporal, strlen(c.tipCorporal) + 1, c.tipCorporal);

		}

		return *this;
	}

	//supraincarcare operator >

	bool operator>(const Corp& c) const
	{
		return this->inaltime > c.inaltime;
	}

	//supraincarcare operator <

	bool operator<(const Corp& c)const
	{
		return this->greutate < c.greutate;
	}

	//supaincarcare operator ==

	bool operator==(const Corp& c) const
	{
		return this->inaltime == c.inaltime;
	}

	//SCRIERE FISIER TEXT

	friend ofstream& operator<<(ofstream& fisier, const Corp& c)
	{
		fisier << c.inaltime << endl;
		fisier << c.greutate << endl;
		fisier << c.tipCorporal << endl;
		return fisier;
	}

	//CITIRE FISIER TEXT

	friend ifstream& operator>>(ifstream& fisier, Corp& c)
	{
		fisier >> c.inaltime;
		fisier >> c.greutate;
		if (c.tipCorporal != NULL)
			delete[]c.tipCorporal;
		char tip[50] = {};
		fisier >> tip;
		c.tipCorporal = new char[strlen(tip) + 1];
		strcpy_s(c.tipCorporal, strlen(tip) + 1, tip);
		return fisier;
	}
};

int Corp::nrMembre = 4;


//functii globale pietene
//ostream

ostream& operator<<(ostream& ecran, const Corp& c)
{
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << c.id << endl << "Aceasta persoana are " << c.greutate << " kilograme si o inaltme de " << c.inaltime << " centimetri." << endl;
	ecran << "Are " << c.nrMembre << " membre." << endl;
	ecran << "Tipul corporal este " << c.tipCorporal << "." << endl;
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << endl;

	return ecran;
}

//istream

istream& operator>>(istream& tastatura, Corp& c)
{
	c.tipCorporal = new char[50];
	cout << "Intoduceti greutatea persoanei:";
	tastatura >> c.greutate;
	cout << "Intoduceti inaltimea persoanei:";
	tastatura >> c.inaltime;
	cout << "Introduceti tipul corporal (ectomorf, endomorf, mezomorf):";
	tastatura >> c.tipCorporal;
	cout << endl;
	return tastatura;

}





//A DOUA CLASA

class Organ
{
private:

	const float id;
	static int nrOrgan;
	float greutate;
	bool esteSanatos;
	char* denumire;

public:

	//primul constructor

	Organ() : id(2.1)
	{
		this->greutate = 250;
		this->esteSanatos = 1;
		this->denumire = new char[strlen("inima") + 1];
		strcpy_s(denumire, strlen("inima") + 1, "inima");
	}

	//al doilea constructor

	Organ(float idNou, float greutateNoua) : id(2.2)
	{
		this->greutate = greutateNoua;
		this->esteSanatos = 0;
		this->denumire = new char[strlen("pancreas") + 1];
		strcpy_s(denumire, strlen("pancreas") + 1, "pancreas");
	}

	//al treilea constructor

	Organ(float idNou, float greutateNoua, bool esteSanatosNou, char* denumireNoua) : id(idNou), greutate(greutateNoua), esteSanatos(esteSanatosNou), denumire(denumireNoua)
	{

	}

	//constructor de copiere

	Organ(const Organ& o) : id(o.id)
	{
		this->greutate = o.greutate;
		this->esteSanatos = o.esteSanatos;
		this->denumire = new char[40];
		this->denumire = o.denumire;
	}

	//destructor

	~Organ()
	{
		delete[]this->denumire;
	}

	//afisare

		/*void afisare()
		{
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			cout << id << " Organul este: " << denumire << " si are o greutate de aproximativ " << greutate << " de grame. Acesta " << (esteSanatos ? "este" : "nu este") << " sanatos. " << endl;
			cout << "Se afla " << nrOrgan << " in corp." << endl;
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			cout << endl;
		}*/

		//getteri

	const float getId()
	{
		return this->id;
	}

	static int getNrOrgan()
	{
		return nrOrgan;
	}

	float getGreutate()
	{
		return this->greutate;
	}

	bool getEsteSanatos()
	{
		return this->esteSanatos;
	}

	char* getDenumire()
	{
		return this->denumire;
	}

	//setteri

	static void setNrOrgan(int nrOrganN)
	{
		Organ::nrOrgan = nrOrganN;
	}

	void setGreutate(float greutateN)
	{
		this->greutate = greutateN;
	}

	void setEsteSanatos(bool esteSanatosN)
	{
		this->esteSanatos = esteSanatosN;
	}

	void setDenumire(char* denumireN)
	{
		if (this->denumire != NULL)
			delete[]this->denumire;
		this->denumire = new char[40];
		this->denumire = denumireN;
	}

	//functii prietene

	friend ostream& operator<<(ostream& ecran, const Organ& o);
	friend istream& operator>>(istream& tastatura, Organ& o);

	// supraincarcare operator =

	Organ& operator=(const Organ& o)
	{
		if (this != &o)
		{
			if (this->denumire != NULL)
			{
				delete[]this->denumire;

			}
			this->greutate = o.greutate;
			this->esteSanatos = o.esteSanatos;
			this->denumire = new char[strlen(o.denumire) + 1];
			strcpy_s(this->denumire, strlen(o.denumire) + 1, o.denumire);

		}
		return *this;
	}

	//supraincarcare operator !=

	bool operator!=(const Organ& o) const
	{
		return this->greutate != o.greutate;
	}

	//supraincarcare operator +

	friend Organ operator+(float greutate, const Organ& o)
	{
		Organ aux = o;
		aux.greutate = o.greutate + greutate;
		return aux;
	}

	//SCRIERE FISIER TEXT

	friend ofstream& operator<<(ofstream& fisier, const Organ& o)
	{
		fisier << o.greutate << endl;
		fisier << o.esteSanatos << endl;
		fisier << o.denumire << endl;
		return fisier;
	}

	//CITIRE FISIER TEXT

	friend ifstream& operator>>(ifstream& fisier, Organ& o)
	{
		fisier >> o.greutate;
		fisier >> o.esteSanatos;
		if (o.denumire != NULL)
			delete[]o.denumire;
		char den[50] = {};
		fisier >> den;
		o.denumire = new char[strlen(den) + 1];
		strcpy_s(o.denumire, strlen(den) + 1, den);
		return fisier;
	}

};

int Organ::nrOrgan = 1;

ostream& operator<<(ostream& ecran, const Organ& o)
{
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << o.id << " Organul este: " << o.denumire << " si are o greutate de aproximativ " << o.greutate << " de grame. Acesta " << (o.esteSanatos ? "este" : "nu este") << " sanatos. " << endl;
	ecran << "Se afla " << o.nrOrgan << " in corp." << endl;
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << endl;

	return ecran;
}

istream& operator>>(istream& tastatura, Organ& o)
{
	o.denumire = new char[40];
	cout << "Intoduceti denumirea organului: ";
	tastatura >> o.denumire;
	cout << "Introduceti greutatea organului (in grame): ";
	tastatura >> o.greutate;
	cout << "Organul este sanatos? (0-NU , 1-DA): ";
	tastatura >> o.esteSanatos;
	cout << "Introduceti numarul de bucati al organului: (exemplu: 1 pentru creier, 2 pentru rinichi) : ";
	tastatura >> o.nrOrgan;

	return tastatura;
}





//A TREIA CLASA

class Muschi
{
private:
	const float id;
	static int nrMuschi;
	int masa;
	float lungime;
	char* nume;

public:

	//primul constructor

	Muschi() : id(3.1)
	{
		this->masa = 250;
		this->lungime = 10.3;
		this->nume = new char[strlen("biceps") + 1];
		strcpy_s(nume, strlen("biceps") + 1, "biceps");
	}

	//al doilea constructor 

	Muschi(float idNou, int masaNoua) : id(idNou), masa(masaNoua)
	{
		this->lungime = 10;
		this->nume = new char[strlen("triceps") + 1];
		strcpy_s(nume, strlen("triceps") + 1, "triceps");
	}

	//al treilea constructor

	Muschi(float idNou, int masaNoua, float lungimeNoua, char* numeNou) : id(idNou), masa(masaNoua), lungime(lungimeNoua), nume(numeNou)
	{

	}

	//constructor de copiere

	Muschi(const Muschi& m) : id(m.id)
	{
		this->masa = m.masa;
		this->lungime = m.lungime;
		this->nume = new char[25];
		this->nume = m.nume;
	}

	//destructor

	~Muschi()
	{
		delete[]this->nume;
	}

	//afisre

		//void afisare()
		//{
		//	cout << "-----------------------------------------------------------------------------------------------------" << endl;
		//	cout << id << ". Denumirea muschiului este: " << nume << " are o greutate de " << masa << " grame si o lungime de " << lungime << " cm. " << endl;
		//	cout << "Numarul aproximativ de muschi din corp este: " << nrMuschi << endl;
		//	cout << "-----------------------------------------------------------------------------------------------------" << endl;
		//	cout << endl;
		//}

	//getteri

	const float getId()
	{
		return this->id;
	}

	static int getNrMuschi()
	{
		return nrMuschi;
	}

	int getMasa()
	{
		return this->masa;
	}

	float getLungime()
	{
		return this->lungime;
	}

	char* getNume()
	{
		return this->nume;
	}

	//setteri

	static void setNrMuschi(int nrMuschiN)
	{
		nrMuschi = nrMuschiN;
	}

	void setMasa(int masaN)
	{
		this->masa = masaN;
	}

	void setLungime(float lungimeN)
	{
		this->lungime = lungimeN;
	}

	void setNume(char* numeN)
	{
		if (this->nume != NULL)
			delete[]this->nume;
		this->nume = new char[25];
		this->nume = numeN;
	}


	//functii prietene

	friend istream& operator>>(istream& tastatura, Muschi& m);
	friend ostream& operator<<(ostream& ecran, const Muschi& m);

	//supraincarcare operator =

	Muschi& operator=(const Muschi& m)
	{
		if (this != &m)
		{
			if (this->nume != NULL)
			{
				delete[]this->nume;

			}
			this->masa = m.masa;
			this->lungime = m.lungime;
			this->nume = new char[strlen(m.nume) + 1];
			strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);

		}
		return *this;
	}

	//supraincarcare operator ++

		/*Muschi& operator++(int)
		{
			Muschi copie = *this;
			this->masa = masa + 1;
			if(nume!=NULL)
				delete[]this->nume;
			nume = new char[strlen(copie.nume) + 1];
			strcpy_s(nume, strlen(copie.nume) + 1, copie.nume);
			return *this;
		}*/


		//supraincarcare operator >=

	bool operator >=(const Muschi& m)const
	{
		return this->masa >= m.masa;
	}

	//SCRIERE FISIER 

	friend ofstream& operator<<(ofstream& fisier, const Muschi& m)
	{
		fisier << m.masa << endl;
		fisier << m.lungime << endl;
		fisier << m.nume << endl;
		return fisier;
	}

	//CITIRE FISIER 

	friend ifstream& operator>>(ifstream& fisier, Muschi &m)
	{
		fisier >> m.masa;
		fisier >> m.lungime;
		if (m.nume != NULL)
			delete[]m.nume;
		char num[50] = {};
		fisier >> num;
		m.nume = new char[strlen(num) + 1];
		strcpy_s(m.nume, strlen(num) + 1, num);
		return fisier;
	}

};

int Muschi::nrMuschi = 500;

//functii globale prietene
//ostream

ostream& operator<<(ostream& ecran, const Muschi& m)
{
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << m.id << ". Denumirea muschiului este: " << m.nume << " are o greutate de " << m.masa << " grame si o lungime de " << m.lungime << " cm. " << endl;
	ecran << "Numarul aproximativ de muschi din corp este: " << m.nrMuschi << endl;
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << endl;

	return ecran;
}

//istream

istream& operator>>(istream& tastatura, Muschi& m)
{
	m.nume = new char[25];
	cout << "Introduceti denumirea muschiului: ";
	tastatura >> m.nume;
	cout << "Introduceti greutatea muschiului: ";
	tastatura >> m.masa;
	cout << "Introduceti lungimea muschiului: ";
	tastatura >> m.lungime;

	return tastatura;
}

//relatie has-a
//A PATRA CLASA

class Os : public Corp
{
private:
	int nrOaseRupte;
	int* nrRupturiOs;
	float lungimeOs;

public:

	//getteri

	int getNrOaseRupte()
	{
		return this->nrOaseRupte;
	}

	float getLungimeOs()
	{
		return this->lungimeOs;
	}

	int* getNrRupturiOs()
	{
		return this->nrRupturiOs;
	}

	//setteri

	void setNrOaseRupte(int nrOaseRupteN)
	{
		this->nrOaseRupte = nrOaseRupteN;
	}

	void setLungimeOs(float lungimeOsN)
	{
		this->lungimeOs = lungimeOsN;
	}

	void setNrRupturiOs(int* nrRupturiOsN)
	{
		if (this->nrRupturiOs != NULL)
			delete[]this->nrRupturiOs;
		this->nrRupturiOs = new int[nrOaseRupte];
		this->nrRupturiOs = nrRupturiOsN;
	}

	//functii prietene



	//constructor fara parametri

	Os() : Corp(4.1, 65)
	{
		this->nrOaseRupte = 2;
		this->nrRupturiOs = new int[this->nrOaseRupte];
		for (int i = 0; i < this->nrOaseRupte; i++)
		{
			this->nrRupturiOs[i] = 1;
		}
		this->lungimeOs = 15;
	}

	//constructor cu doi parametri

	Os(int nrOaseRupteN, float lungimeOsN) : Corp(4.2, 84)
	{
		this->nrOaseRupte = nrOaseRupteN;
		this->nrRupturiOs = new int[this->nrOaseRupte];
		for (int i = 0; i < this->nrOaseRupte; i++)
		{
			this->nrRupturiOs[i] = 1;
		}
		this->lungimeOs = lungimeOsN;
	}

	//destructor

	~Os()
	{
		if (this->nrRupturiOs != NULL)
			delete[]this->nrRupturiOs;
	}

	//constructor de copiere

	Os(const Os& o) :Corp(o)
	{
		this->nrOaseRupte = o.nrOaseRupte;
		this->lungimeOs = o.lungimeOs;
		this->nrRupturiOs = new int[this->nrOaseRupte];
		for (int i = 0; i < this->nrOaseRupte; i++)
		{
			this->nrRupturiOs[i] = o.nrRupturiOs[i];
		}
	}

	//operatorul =

	Os operator=(const Os& o)
	{
		if (this != &o)
			Corp::operator=(o);
		this->nrOaseRupte = o.nrOaseRupte;
		this->lungimeOs = o.lungimeOs;
		if (this->nrRupturiOs != NULL)
			delete[]this->nrRupturiOs;
		if (this->nrOaseRupte > 0)
		{
			this->nrRupturiOs = new int[this->nrOaseRupte];
			for (int i = 0; i < this->nrOaseRupte; i++)
			{
				this->nrRupturiOs[i] = o.nrRupturiOs[i];
			}
		}
		else
		{
			this->nrRupturiOs = NULL;
		}
		return *this;
	}

	//ostream

	friend ostream& operator<<(ostream& out, const Os& o)
	{
		out << "-----------------------------------------------------------------------------------------------------" << endl;

		out << "Lungimea osului este de " << o.lungimeOs << " centimetri." << endl;
		if (o.nrOaseRupte == 1)
		{
			out << "Persoana are un os rupt." << endl;
		}
		else
		{
			out << "Persoana are " << o.nrOaseRupte << " oase rupte";
			out << endl;
		}
		if (o.nrOaseRupte == 0)
		{
			out << "Persoana nu are oase rupte." << endl;
		}
		else
		{
			out << "Numarul de rupturi al fiecarui os: " << endl;
			for (int i = 0; i < o.nrOaseRupte; i++)
			{
				out << o.nrRupturiOs[i] << " ";
			}
			out << endl;
		}
		out << "-----------------------------------------------------------------------------------------------------" << endl;

		return out;

	}

	//istream

	friend istream& operator<<(istream& citire, Os& o)
	{
		o.nrRupturiOs = new int[o.nrOaseRupte];
		cout << "Introduceti lungimea osului: ";
		citire >> o.lungimeOs;
		cout << "Introduceti numarul de oase rupte din corp: ";
		citire >> o.nrOaseRupte;
		if (o.nrOaseRupte > 0)
		{
			cout << "Introduceti numarul de rupturi al fiecarui os: ";
			for (int i = 0; i < o.nrOaseRupte; i++)
			{
				cout << "osul[" << i + 1 << "] = ";
				citire >> o.nrRupturiOs[i];
				cout << endl;
			}
		}
		return citire;
	}

	//Operator + IMI DA EROARE LA MEMORIE!!!!!!!!!!

	//Os operator+(const Os& o)
	//{
	//	Os aux = *this;
	//	aux.lungimeOs = this->lungimeOs + o.lungimeOs;
	//	aux.nrOaseRupte = this->nrOaseRupte + o.nrOaseRupte;
	//	/*if (aux.nrRupturiOs != NULL)
	//		delete[]aux.nrRupturiOs;*/
	//	aux.nrRupturiOs = new int[aux.nrOaseRupte];
	//	for (int i = 0; i < this->nrOaseRupte; i++)
	//	{
	//		aux.nrRupturiOs[i] = this->nrRupturiOs[i];
	//	}
	//	for (int i = this->nrOaseRupte; i < aux.nrOaseRupte; i++)
	//	{
	//		aux.nrRupturiOs[i] = o.nrRupturiOs[i - this->nrOaseRupte];
	//	}
	//	return aux;
	//}

	//SCRIERE FISIER 

	friend ofstream& operator<<(ofstream& fisier, const Os& os)
	{
		fisier << os.nrOaseRupte << endl;
		fisier << os.lungimeOs << endl;
		fisier << os.nrRupturiOs << endl;
		return fisier;
	}

	//CITIRE FISIER 

	friend ifstream& operator>>(ifstream& fisier, Os& os)
	{
		int a;
		fisier >> os.nrOaseRupte;
		fisier >> os.lungimeOs;
		fisier >> a;
		if (os.nrRupturiOs != NULL)
			delete[]os.nrRupturiOs;
		if (os.nrOaseRupte != NULL)
		{
			delete[]os.nrRupturiOs;
		}
		if (os.nrOaseRupte > 0)
		{
			os.nrRupturiOs = new int[os.nrOaseRupte];
			for (int i = 0; i < os.nrOaseRupte; i++)
			{
				fisier >> os.nrRupturiOs[i];
			}
		}
		else
		{
			os.nrRupturiOs = NULL;
		}
		return fisier;
	}
};
	//Relatie is-a
	//A CINCEA CLASA 

	class Organism
	{
	private: 

		int nrOrganisme;
		Corp* corp;

	public:

		//constructor fara parametri

		Organism()
		{
			this->nrOrganisme= 3;
			this->corp = new Corp[nrOrganisme];
		}

		//constructor cu un parametru

		Organism(int organismeN): nrOrganisme(organismeN)
		{
			this->corp = new Corp[nrOrganisme];
		}

		//destructor

		~Organism()
		{
			if (this->corp!=NULL)
			{
				delete[]this->corp;
			}
		}

		//getteri

		int getNrOrganisme()
		{
			return this->nrOrganisme;
		}

		Corp* getCorp()
		{
			return this->corp;
		}

		//setteri

		void setNrOrganisme(int organismeN)
		{
			this->nrOrganisme = organismeN;
		}

		//Operator =

		Organism& operator=(const Organism& org)
		{
			if (this != &org)
			{
				nrOrganisme = org.nrOrganisme;
				if(this->corp!=NULL)
					delete[]corp;
				corp = new Corp[org.nrOrganisme];
			}
			return *this;
		}

		//Constructor de copiere

		Organism(const Organism& org)
		{
			this->nrOrganisme = org.nrOrganisme;
			this->corp = new Corp[org.nrOrganisme];
			for (int i = 0; i < org.nrOrganisme; i++)
			{
				corp[i] = org.corp[i];
			}
		}

		//Operatorul []

		Corp& operator[](int index)
		{
			if (index >= 0 && index < nrOrganisme)
			{
				return this->corp[index];
			}
		}

		void afiseazaOrganism()
		{
			cout << "Numarul de organisme este " << nrOrganisme << endl;
			cout << "Detaliile despre fiecare organism/corp sunt: ";
			for (int i = 0; i < nrOrganisme; i++)
			{
				cout << endl << corp[i];
			}
		}
		
	};

	//A SASEA CLASA

	class SistemMuscular
	{
	private: 

		int nrMuschiVerificati;
		Muschi* m;

	public:

		//constructor fara parametri

		SistemMuscular()
		{
			this->nrMuschiVerificati = 5;
			this->m = new Muschi[nrMuschiVerificati];
		}

		//constructor cu un parametru

		SistemMuscular(int nrMuschiVerificatiN): nrMuschiVerificati(nrMuschiVerificatiN)
		{
			this->m = new Muschi[nrMuschiVerificatiN];
		}

		//destructor

		~SistemMuscular()
		{
			if (this->m != NULL)
			{
				delete[]this->m;
			}
		}

		//getteri

		int getNrMuschiVerificati()
		{
			return this->nrMuschiVerificati;
		}

		Muschi* GetM()
		{
			return this->m;
		}

		//setteri

		void setNrMuschiVerificati(int nrMuschiVerificatiN)
		{
			this->nrMuschiVerificati = nrMuschiVerificatiN;
		}

		//Operator =

		SistemMuscular& operator=(const SistemMuscular& mus)
		{
			if (this != &mus)
			{
				nrMuschiVerificati = mus.nrMuschiVerificati;
				if (this->m != NULL)
					delete[]this->m;
				m = new Muschi[mus.nrMuschiVerificati];
			}
			return *this;
		}

		//Constructor de copiere

		SistemMuscular(const SistemMuscular& mus)
		{
			this->nrMuschiVerificati = mus.nrMuschiVerificati;
			this->m = new Muschi[mus.nrMuschiVerificati];
			for (int i = 0; i < this->nrMuschiVerificati; i++)
			{
				m[i] = mus.m[i];
			}
		}

		//Operatorul[]

		Muschi& operator[](int index)
		{
			if (index >= 0 && index < nrMuschiVerificati)
			{
				return this->m[index];
			}
		}

		//afisare

		void afisareSistemMuscular()
		{
			cout << "Numarul de muschi verificati din corp sunt: " << nrMuschiVerificati << endl;
			cout << "Detaliile despre fiecare muschi sunt: ";
			for (int i = 0; i < nrMuschiVerificati; i++)
			{
				cout << endl << m[i];
			}
		}
	};

	




void main()
{

	//PRIMA CLASA

	//apelare + afisare constructor1

	cout << "Apel primul constructor:" << endl << endl;

	Corp persoana1;
	cout << persoana1;

	//apelare + afisare constructor2

	cout << "Apel al doilea constructor:" << endl << endl;

	Corp persoana2(1.2, 48.7);
	cout << persoana2;

	char* tipCorporal = new char[strlen("endomorf") + 1];
	strcpy_s(tipCorporal, strlen("endomorf") + 1, "endomorf");

	//apelare + afisare constructor3

	cout << "Apel al treilea constructor:" << endl << endl;

	Corp persoana3(1.3, 193, 80.4, tipCorporal);
	persoana3.setNrMembre(3);
	cout << persoana3;

	//getteri si setteri

	cout << "Getter:" << endl << endl;

	Corp persoana4;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << persoana4.getId() << endl << "Aceasta persoana are " << persoana4.getGreutate() << " kilograme si o inaltme de " << persoana4.getInaltime() << " centimetri." << endl;
	cout << "Are " << persoana4.getNrMembre() << " membre." << endl;
	cout << "Tipul corporal este " << persoana4.getTipCorporal() << "." << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Setter:" << endl << endl;
	char* tipCorporal1 = new char[strlen("mezomorf") + 1];
	strcpy_s(tipCorporal1, strlen("mezomorf") + 1, "mezomorf");

	persoana4.setGreutate(73.1);
	persoana4.setInaltime(175);
	persoana4.setNrMembre(4);
	persoana4.setTipCorporal(tipCorporal1);

	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << persoana4.getId() << endl << "Aceasta persoana are " << persoana4.getGreutate() << " kilograme si o inaltme de " << persoana4.getInaltime() << " centimetri." << endl;
	cout << "Are " << persoana4.getNrMembre() << " membre." << endl;
	cout << "Tipul corporal este " << persoana4.getTipCorporal() << "." << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	//apel functii prietene
	//ostream

	Corp persoana5;
	cout << "Apel ostream:" << endl << endl;
	cout << persoana5;

	//istream

	Corp persoana6;
	cout << "Apel istream:" << endl << endl;
	cin >> persoana6;
	cout << persoana6;

	//operator =

	cout << "Operator =: " << endl << endl;
	persoana6 = persoana2;
	cout << persoana6;

	//operator >

	cout << "Operator >: " << endl << endl;
	cout << "Prima persoana (persoana1): " << endl << endl;
	cout << persoana1 << endl;
	cout << "A doua persoana (persoana2): " << endl << endl;
	cout << persoana2 << endl;
	if (persoana2 > persoana1)
		cout << "A doua persoana este mai inalta decat prima persoana." << endl;
	else
		cout << "Prima persoana este mai inalta decat a doua persoana." << endl;

	//operator <

	cout << " Operator <: " << endl << endl;
	cout << "Prima persoana (persoana6): " << endl << endl;
	cout << persoana6 << endl;
	cout << "A doua persoana (persoana3): " << endl << endl;
	cout << persoana3 << endl;
	if (persoana6 < persoana3)
		cout << "Prima persoana este mai slaba decat a doua." << endl;
	else
		cout << "A doua persoana este mai slaba decat prima." << endl;

	//operator ==

	cout << " Operator ==: " << endl << endl;
	cout << "Prima persoana (persoana4): " << endl << endl;
	cout << persoana4 << endl;
	cout << "A doua persoana (persoana5): " << endl << endl;
	cout << persoana5 << endl;
	if (persoana4 == persoana5)
		cout << "Cele doua persoane au aceeasi inaltime" << endl;
	else
		cout << "Cele doua persoane nu au aceeasi inaltime" << endl;





	//A DOUA CLASA

	cout << endl << endl;
	cout << "A doua clasa:" << endl << endl;

	//apel + afisare constructor1

	cout << "Apel primul constructor:" << endl << endl;
	Organ organ1;
	cout << organ1;

	//apel + afisare constructor2

	cout << "Apel al doilea constructor:" << endl << endl;
	Organ organ2(2.2, 70);
	cout << organ2;

	//apel + afisare constructor3

	cout << "Apel al treilea constructor:" << endl << endl;
	char* denumire = new char[strlen("plaman") + 1];
	strcpy_s(denumire, strlen("plaman") + 1, "plaman");
	Organ organ3(2.3, 600, 1, denumire);
	organ3.setNrOrgan(2);
	cout << organ3;

	//getteri si setteri

	cout << "Getter:" << endl << endl;

	Organ organ4;
	organ4.setNrOrgan(1);
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << organ4.getId() << " Organul este: " << organ4.getDenumire() << " si are o greutate de aproximativ " << organ4.getGreutate() << " de grame. Acesta " << (organ4.getEsteSanatos() ? "este" : "nu este") << " sanatos. " << endl;
	cout << "Se afla " << organ4.getNrOrgan() << " in corp." << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Setter:" << endl << endl;
	char* denumire1 = new char[strlen("creier") + 1];
	strcpy_s(denumire1, strlen("creier") + 1, "creier");

	organ4.setDenumire(denumire1);
	organ4.setEsteSanatos(1);
	organ4.setGreutate(1400);
	organ4.setNrOrgan(1);

	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << organ4.getId() << " Organul este: " << organ4.getDenumire() << " si are o greutate de aproximativ " << organ4.getGreutate() << " de grame. Acesta " << (organ4.getEsteSanatos() ? "este" : "nu este") << " sanatos. " << endl;
	cout << "Se afla " << organ4.getNrOrgan() << " in corp." << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	//apel functii prietene
	//ostream

	Organ organ5;
	cout << "Apel ostream: " << endl << endl;
	cout << organ5;

	//istream

	Organ organ6;
	cout << "Apel istream: " << endl << endl;
	cin >> organ6;
	cout << organ6;

	//operator =

	cout << "Operator =: " << endl << endl;
	organ2 = organ6;
	cout << organ6;

	//supraincarcare operator !=

	cout << "Operator !=: " << endl << endl;
	cout << "Primul organ (organ2): " << endl << endl;
	cout << organ2 << endl;
	cout << "Al doilea organ (organ6): " << endl << endl;
	cout << organ6 << endl;
	if (organ2 != organ6)
		cout << "Greutatea primului organ este diferita de greutatea celui de-al doilea organ.";
	else
		cout << "Cele doua organe au aceeasi greutate." << endl << endl;

	//supraincarcare operator +

		/*cout << "Operator +: " << endl << endl;
		cout << "Organul (organ5): " << endl << endl;
		cout << organ5 << endl;
		cout << "Dupa modificarea greutatii organului: ";
		organ5 = 10.3 + organ5;
		cout << organ5<<endl;*/





		//A TREIA CLASA

	cout << endl << endl;
	cout << "A treia clasa: " << endl << endl;

	//apel + afisare constructor1

	cout << "Primul constructor: " << endl << endl;
	Muschi muschi1;
	cout << muschi1;

	//apel + afisare constructor2

	cout << "Al doilea constructor: " << endl << endl;
	Muschi muschi2(3.2, 200);
	cout << muschi2;

	//apel + afisare constructor3

	cout << "Al treilea constructor" << endl << endl;
	char* nume = new char[strlen("cvadriceps") + 1];
	strcpy_s(nume, strlen("cvadriceps") + 1, "cvadriceps");
	Muschi muschi3(3.3, 400, 40.5, nume);
	muschi3.setNrMuschi(498);
	cout << muschi3;

	//getteri si setteri

	cout << "Getter: " << endl << endl;

	Muschi muschi4;
	muschi4.setNrMuschi(500);
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << muschi4.getId() << ". Denumirea muschiului este: " << muschi4.getNume() << " are o greutate de " << muschi4.getMasa() << " grame si o lungime de " << muschi4.getLungime() << " cm. " << endl;
	cout << "Numarul aproximativ de muschi din corp este: " << muschi4.getNrMuschi() << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Setter: " << endl << endl;
	char* nume1 = new char[strlen("trapez") + 1];
	strcpy_s(nume1, strlen("trapez") + 1, "trapez");

	muschi4.setNume(nume1);
	muschi4.setMasa(50);
	muschi4.setLungime(20);
	muschi4.setNrMuschi(499);

	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << muschi4.getId() << ". Denumirea muschiului este: " << muschi4.getNume() << " are o greutate de " << muschi4.getMasa() << " grame si o lungime de " << muschi4.getLungime() << " cm. " << endl;
	cout << "Numarul aproximativ de muschi din corp este: " << muschi4.getNrMuschi() << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	//apel functii prietene 
	//ostream

	Muschi muschi5;
	cout << "Apel ostream: " << endl << endl;
	cout << muschi5;

	//istream

	Muschi muschi6;
	muschi6.setNrMuschi(500);
	cout << "Apel istream: " << endl << endl;
	cin >> muschi6;
	cout << muschi6;

	//supraincarcare operator =

	cout << "Operator =: " << endl << endl;
	muschi1 = muschi6;
	cout << muschi1;

	//supraincarcare operator ++

		/*cout << "Operator ++:" << endl << endl;
		cout << "Muschiul este:" << endl;
		cout << muschi1<<endl;
		cout << "Adunam masa muschiului cu 1. Noua masa este:" << endl;
		muschi1++;
		cout << muschi1;*/

		//supraincarcare operator>=    ceva nu e bine

	cout << "Operator >=: " << endl << endl;
	cout << "Primul muschi (muschi3): " << endl << endl;
	cout << muschi3 << endl;
	cout << "Al doilea muschi (muschi2): " << endl << endl;
	cout << muschi2 << endl;
	if (muschi2 >= muschi1)
		cout << "Primul muschi este mai greu sau egal cu al doilea muschi." << endl;
	else
		cout << "Al doilea muschi este mai greu sau egal cu primul muschi." << endl;


	cout << endl << endl << endl << endl;
	cout << "Vectori de obiecte:" << endl << endl;

	//Vector prima clasa

	cout << "Vector cu obiecte prima clasa(corp):" << endl;

	Corp* c_corp = new Corp[3];
	c_corp[0] = persoana1;
	c_corp[1] = persoana2;
	c_corp[2] = persoana3;
	for (int i = 0; i < 3; i++)
	{
		cout << "Persoana " << i + 1 << " :" << endl;
		cout << c_corp[i] << endl;
	}

	delete[]c_corp;

	//Vector a doua clasa

	cout << "Vector cu obiecte a doua clasa(organ):" << endl;

	Organ* o_organ = new Organ[4];
	o_organ[0] = organ1;
	o_organ[1] = organ2;
	o_organ[2] = organ3;
	o_organ[3] = organ4;
	for (int i = 0; i < 4; i++)
	{
		cout << "Organul " << i + 1 << " :" << endl;
		cout << o_organ[i] << endl;
	}

	delete[]o_organ;

	//Vector a treia clasa

	cout << "Vector cu obiecte a treia clasa(muschi):" << endl;

	Muschi* m_muschi = new Muschi[3];
	m_muschi[0] = muschi1;
	m_muschi[1] = muschi2;
	m_muschi[2] = muschi5;
	for (int i = 0; i < 3; i++)
	{
		cout << "Muschiul " << i + 1 << " :" << endl;
		cout << m_muschi[i] << endl;
	}

	delete[]m_muschi;

	//Matrice a treia clasa

	cout << endl << endl << "Matrice clasa(muschi): " << endl << endl;
	Muschi** matrice = new Muschi * [3];
	for (int i = 0; i < 3; i++)
		matrice[i] = new Muschi[3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrice[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		delete[] matrice[i];
	}
	delete[]matrice;

	//A PATRA CLASA

	Os os1;
	cout << "Primul os :" << endl;
	cout << os1;

	cout << endl<<endl;
	cout << "Al doilea os :" << endl;
	Os os2(4, 5);
	cout << os2;

	os1.setLungimeOs(40);
	cout << endl << endl;
	cout << "Primul os modificat : " << endl;
	cout << os1;
	cout << endl<<endl;

	//Operator +

	/*Os os3 = os1 + os2;
	cout << os3;*/

	//Fisier1 text

	cout << "Am creat primul fisier text."<<endl<<endl;
	Corp p7;
	ofstream c("Corp.txt", ios::app);
	c << p7;
	c.close();

	ifstream c1("Corp.txt", ios::in);
	c1 >> persoana1;
	cout << persoana1;
	c1.close();

	//Fisier2 text

	cout << "Am creat al doilea fisier text." << endl << endl;
	ofstream o("Organ.txt", ios::app);
	o << organ3;
	o.close();

	ifstream o1("Organ.txt", ios::in);
	Organ organ7(7.1, 600);
	o1 >> organ7;
	cout << organ7;
	o1.close();
	cout << endl;

	//Fisier1 binar

	cout << "Am creat primul fisier binar." << endl << endl;
	fstream m("Muschi.bin", ios::out | ios::binary);
	m.write((char*)&muschi1, sizeof(Muschi));
	m.close();

	fstream m1("Muschi.bin", ios::in | ios::binary);
	m1.read((char*)&muschi1, sizeof(Muschi));
	m1.close();

	//Fisier2 binar
	
	cout << "Am creat al doilea fisier binar." << endl << endl;
	fstream o11("Os.bin", ios::out | ios::binary);
	o11.write((char*)&os1, sizeof(Os));
	o11.close();

	fstream o12("Os.bin", ios::in | ios::binary);
	o12.read((char*)&os1, sizeof(Os));
	o12.close();

	//A cincea clasa


	//apelare + afisare primul constructror;

	Organism org1;
	org1.afiseazaOrganism();

	//apelare + afisare al doilea constructor

	Organism org2(5);
	org2.afiseazaOrganism();



	//A sasea clasa

	//apelare + afisare primul constructor

	SistemMuscular mus1;
	mus1.afisareSistemMuscular();

	//apelare + afisare al doilea constructor

	SistemMuscular mus2(2);
	mus2.afisareSistemMuscular();

	//CLASA ABSTRACTA

	//Corp corp;
	//corp.afisareDescriere();
	


}
