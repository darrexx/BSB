/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ IO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#include "object/o_stream.h"

O_Stream& O_Stream::operator<< (unsigned long number){

    if (number == 0){
        put('0');
        flush();
        return *this;
    }

	char buffer[150];
	unsigned char countOfDigits=0;

    for(unsigned char counter = 0; counter < 150 && number !=0; counter++){
        countOfDigits++;
        int modNumber = (number % system);
        if(system==16){

        	if(modNumber <10){
        		buffer[counter]= '0' + modNumber;
        	}else{
        		buffer[counter]= 'A' + modNumber-10;
        	}
        }
        else{
            buffer[counter] = '0' + (modNumber);
        }
        number = number / system;
    }


    for(char counter = countOfDigits-1; counter >=0; counter--){
    	put(buffer[counter]);
    }
    flush();
	return *this;
}

O_Stream& O_Stream::operator<< (long number){
	if(number<0){
		if(system!=10){
			number= ((number*-1)^0xFFFFFFFF)+1;
		}
		else{
			number = number * -1;
			put('-');
		}
	}
	return *this<< (unsigned long)number;
}

O_Stream& O_Stream::operator<< (unsigned char c){
    put(c);
    flush();
    return *this;
}

O_Stream& O_Stream::operator<< (char c){
    put(c);
    flush();
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned short number){
    return *this << (unsigned long)number;

}

O_Stream& O_Stream::operator<<(short number){
	return *this<< (long) number;
}

O_Stream& O_Stream::operator<<(unsigned int number){
    return *this << (unsigned long)number;
}

O_Stream& O_Stream::operator<<(int number){
	return *this<< (long) number;
}

O_Stream& O_Stream::operator<<(void* pointer){
	Zahlensystem copy= system;
	system = hexa;
	*this << (long) &pointer;
	system = copy;
	flush();
	return *this;
}

O_Stream& O_Stream::operator<<(char* text){
	bool terminated=false;
	int counter=0;
	while(!terminated){
		if(text[counter]!='\0'){
			put(text[counter]);
			counter++;
		}else{
			terminated=true;
		}
	}
	flush();
	return *this;
}

O_Stream& O_Stream::operator<<(O_Stream& (*fkt) (O_Stream&)){
	fkt(*this);
	return *this;
}

O_Stream& endl(O_Stream& os){
	os<<'\n';
	return os;
}

O_Stream& bin(O_Stream& os){
	os.system = O_Stream::binaer;
	return os;
}

O_Stream& oct(O_Stream& os){
	os.system = O_Stream::oktal;
	return os;
}

O_Stream& dec(O_Stream& os){
	os.system = O_Stream::dezimal;
	return os;
}

O_Stream& hex(O_Stream& os){
	os.system = O_Stream::hexa;
	return os;
}
