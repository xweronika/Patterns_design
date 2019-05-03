/*Zadanie 3 (obserwator)
Wprowadzenie
W domu chcieliby�my zainstalowa� kilka zegar�w w r�nych pomieszczeniach. 
Zale�y nam na tym �eby wszystkie zegary wy�wietla�y dok�adnie t� sam� godzin�. 
Dodatkowo chcieliby�my unikn�� uci��liwego dostosowywania godziny na ka�dym z 
nich podczas zmiany czasu. Z tego wzgl�du zamiast kupowa� N zegark�w, to kupimy 
jeden zegar centralny, kt�ry b�dzie odpowiedzialny tylko za odmierzanie czasu, 
a osobno dokupimy N wy�wietlaczy, kt�re b�d� ��czy� si� z zegarem centralnym 
i pobiera� z niego informacj� o aktualnej godzinie.

Zadanie
Stw�rz aplikacj� na�laduj�c� zachowanie zegara centralnego i pod��czonych do niego 
wy�wietlaczy cyfrowych. Oczywi�cie trzeba w tym celu wykorzysta� wzorzec projektowy 
"Obserwator". Program mo�e sk�ada� si� z trzech klas reprezentuj�cych wy�wietlacze 
czasu w formacie hh:mm (b�d�cych obserwatorami):
WyswietlaczPokojowy
WyswietlaczKuchenny
WyswietlaczOgrodowy
Oraz jednej klasy obserwowanej ZegarCentralny, kt�ra symuluje zachowanie zegara 
centralnego i s�u�y jedynie do odmierzania czasu (nie posiada on mechanizmu wy�wietlania). 
Za wy�wietlanie aktualnego czasu s� odpowiedzialne klasy wy�wietlaczy i tylko one maj� 
realizowa� t� funkcjonalno��. Klasa ZegarCentralny ma by� obserwowana przez klasy 
wy�wietlaczy i ma te obiekty informowa� o zmianie czasu.


Uwagi:
Program powinien umo�liwia� pod��czenie/od��czenie danego wy�wietlacza (obserwatora) 
od zegara centralnego (obiektu obserwowanego) w trakcie dzia�ania programu.  
Zak�adamy, �e aktualizacja wy�wietlanego czasu odbywa si� co 1 minut�. 
Prosz� pami�ta� o wykorzystaniu interfejs�w!*/

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

class Obserwator {
public:
    virtual void update() = 0;
};

class Obserwowany {
protected:
    list <Obserwator*> obserwatorzy;
public:
    void dodaj(Obserwator *o) {
        obserwatorzy.push_back (o);
    }
    void usun() {
       // obserwatorzy.remove (o);
        
        obserwatorzy.clear();
        
    }
 
    void powiadom () {
        list<Obserwator *>::iterator it;
        for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) {
            (*it)->update ();
        }
    }
};

class ZegarCentralny : public Obserwowany{
	string czas;
	public:
	string pobierzCzas(){
		
		return czas;
	}

	void ustawCzas(){
		
	time_t now = time(0);
		
  	 char* dt = ctime(&now);
  	 string data(dt);
  	 
  	czas = data;
  	 cout << endl<< "Uruchomiono zegar centralny." << endl;
  	        
		powiadom();
	}
	
};


class ObserwatorZegar : public Obserwator {

protected:
    string zegarId;
        ZegarCentralny *zegar;
public:
    ObserwatorZegar (ZegarCentralny *h, string id) {
        zegar = h;
        zegarId = id;
    }
    void update () {
        string czas = zegar->pobierzCzas();
        cout<<zegarId<<", godzina: "<<czas;
    }
    
};


main(){
	
	char znak;
	int choice;
	
	cout<<"Menu"<<endl;
	
cout<<"0. Aby zatrzyma� dzia�anie programu naci�nij '0'."<<endl;
cout<<"1. Aby uruchomi� zegar centralny naci�nij '1'."<<endl;
cout<<"2. W celu dodania wyswietlacza pokojowego naci�nij '2'."<<endl;
cout<<"3. W celu dodania wyswietlacza kuchennego naci�nij '3'."<<endl;
cout<<"4. W celu dodania wyswietlacza ogrodowego naci�nij '4'."<<endl;
cout<<"5. Aby usunac wszystkie wyswietlacze naci�nij '5'."<<endl;
	
	
	ZegarCentralny zegar ;



	do{
		cin>>choice;

		if (choice==1){
		
			while(1){
				zegar.ustawCzas();
				Sleep(1000*2); // timer
			
				if (kbhit()){
		        	znak=getch();
		        break;
		    	}
			}
		}
		if (choice==2){
			Obserwator *zegar1 = new ObserwatorZegar(&zegar, "Wy�wietlacz pokojowy");
			zegar.dodaj(zegar1);
			cout<<"Dodano wyswietlacz pokojowy."<<endl;
		}
		
		if (choice==3){
			Obserwator *zegar2 = new ObserwatorZegar(&zegar, "Wy�wietlacz kuchenny");
			zegar.dodaj(zegar2);
			cout<<"Dodano wyswietlacz kuchenny."<<endl;
		}
		if (choice==4){
			Obserwator *zegar3 = new ObserwatorZegar(&zegar, "Wy�wietlacz ogrodowy");
			zegar.dodaj(zegar3);
			cout<<"Dodano wy�wietlacz ogrodowy."<<endl;
		}
		
		if(choice==5){
			zegar.usun();
			cout<<"Usunieto wszystkie wyswietlacze."<<endl;
		}
		
	
	}while(choice!=0);

}

