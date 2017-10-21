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

O_Stream& O_Stream::operator<< (unsigned char c){
    put(c);
    return *this;
}

O_Stream& O_Stream::operator<< (char c){
    if(c < 0){
        put('-');
    }
    put(c);
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned short number){
    unsigned char shortCharArray[5];

    unsigned char countOfDigits = 0;

    if (number == 0){
        put('0');
        return *this;
    }

    for(unsigned char counter = 0; counter < 5 && number !=0; counter++){
        countOfDigits++;
        shortCharArray[counter] = (char) (number % 10);
        number = number / 10;
    }

    for(unsigned char counter = countOfDigits + 1; counter >=0; counter--){
        put(shortCharArray[counter - 1]);
    }
    return *this;

}
/* Hier muesst ihr selbst Code vervollstaendigen */ 
