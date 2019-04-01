/*
Stwórz aplikację umożliwiającą wymienne stosowanie algorytmów
 sortowania na liście typu Integer. Należy w tym celu wykorzystać
 wzorzec projektowy Strategia, aby umożliwić dynamiczną 
 (w trakcie działania programu) zmianę algorytmu sortującego.

Należy zaimplementować 3 następujące algorytmy sortujące: 

sortowanie bąbelkowe,
sortowanie przez wstawianie,
sortowanie przez wybieranie.
Po uruchomieniu programu musi się wyświetlić menu, które umożliwi:

Wprowadzenie wartości do listy, która będzie sortowana.
Wybranie algorytmu sortującego.
Program oczywiście musi w pełni działać! 
Czyli algorytmy sortowania muszą być faktycznie zaimplementowane. 
Nie można tutaj stosować gotowej biblioteki implementujący dany 
algorytm sortujący (trzeba go zaimplementować samemu).

*/

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class IFiltr
{
public:
    virtual void sprawdz( vector <int> t ) = 0;
}; //class IFiltr

class Sortowanie1
    : public IFiltr
{
    Sortowanie1() { };
public:
    virtual void sprawdz( vector <int> t )
    {
    	//implementacja sortowania 1
 	 for (int i=0; i<t.size()-1; i++)
        for (int j=0; j<t.size()-1; j++)
            if (t[j]>t[j+1])
                swap(t[j], t[j+1]);

	 
	cout << "Sortowanie babelkowe: ";
    for (int i = 0; i<t.size(); i++)
        cout<<t[i] << " ";
	cout<<endl;

    }
    
    static IFiltr * getSingleton()
    {
        static Sortowanie1 singleton;
        return & singleton;
    }
    
}; //class Sortowanie1

class Sortowanie2
    : public IFiltr
{
    Sortowanie2() { };
public:
    virtual void sprawdz( vector <int> t )
    {
        //implementacja sortowania 2
        
           int temp, j;
    
    for( int i=1; i<t.size(); i++ )
    {
        temp = t[i];
        
        for( j=i-1; j>=0 && t[j]>temp; j-- )
             t[j+1] = t[j];
        t[j+1] = temp;
    }
    
    	cout<<"Sortowanie przez wstawianie: ";
        for (int i = 0; i<t.size(); i++)
        	cout<<t[i] << " ";
		cout<<endl;
    }
    
    static IFiltr * getSingleton()
    {
        static Sortowanie2 singleton;
        return & singleton;
    }
}; //class Sortowanie2

class Sortowanie3
    : public IFiltr
{
    Sortowanie3() { };
public:
    virtual void sprawdz( vector <int> t )
    {
        //implementacja sortowania 3
    int k;
    for( int i = 0; i < t.size(); i++ )
    {
        k = i;
        for( int j = i + 1; j < t.size(); j++ )
	        if( t[ j ] < t[ k ] )
	             k = j;
        
        swap( t[ k ], t[ i ] );
    }
    
    
    	cout<<"Sortowanie przez wybieranie: ";
        for (int i = 0; i<t.size(); i++)
        	cout<<t[i] << " ";
		cout<<endl;
    }
    
    static IFiltr * getSingleton()
    {
        static Sortowanie3 singleton;
        return & singleton;
    }
}; //class Sortowanie3



class CLiczby
{
  	
    IFiltr * m_pFiltr;
    vector <int> tab ;
public:
    CLiczby()
        : m_pFiltr( NULL )
    {
    }
    

    
    void ustawFiltr( IFiltr * pFiltr, vector <int> t )
    {
        m_pFiltr = pFiltr;
        tab = t;
    }
    
    void wypisz()
    {
       if(NULL == m_pFiltr)
       {
	       	cout<< "Wskaznik jest nie ustawiony!"<<endl;
	       	return;
	   }
	   else 
	   {
	   		m_pFiltr->sprawdz(tab );
	   }
        
          
    }
    
}; //class CLiczby

int main()
{
    CLiczby liczby;
 	vector < int > tablica;
 
 	
 	

	int n;
	cout<<"Ile liczb posortowac? ";
	cin>>n;
		
	for(int i=0;i<n;i++){
		int liczba;
		cout<<"Podaj liczbe numer "<<i+1<<": ";
		cin>>liczba;
		tablica.push_back(liczba);
	}
	
	system( "cls" );
	int choice;

		cout<<endl<<"Twoje liczby: ";
		for(int j=0; j< n; j++)
		{
	         cout<<tablica[j]<<" ";	
		} 	
		cout<<endl<<endl<<"Jakim algorytmem posortowac liczby?"<<endl;
		cout<<"1.Sortowanie babelkowe."<<endl<<"2.Sortowanie przez wstawianie."<<endl<<"3.Sortowanie przez wybieranie."<<endl<<"4.Koniec.";
		
	do{
		cout<<endl<<endl<<"Wybierz 1/2/3/4: ";
		
	
		cin>>choice;
		if(choice!=1 && choice!=2 && choice!=3 && choice!=4 )
			cout<<"Prosze wpisac poprawna cyfre!";

		
		
		if(choice==1){
		    liczby.ustawFiltr( Sortowanie1::getSingleton(), tablica);
		    liczby.wypisz();
		}
	    if(choice==2){
		    liczby.ustawFiltr( Sortowanie2::getSingleton(), tablica );
		    liczby.wypisz();
		}
	    if(choice==3){
		    liczby.ustawFiltr( Sortowanie3::getSingleton(), tablica );
		    liczby.wypisz();
		}	

		

	}while(choice!=4);

    return 0;
}
