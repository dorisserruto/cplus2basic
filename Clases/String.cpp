#include <string.h>
/*
    int s_size;  //tamaño (real en caracteres)
    char * pointer_start; //puntero a contenido
*/

//Constructor por defecto
String::String (){
    char * pointer_start = new char[1];
    pointer_start[0] = '\0';
    s_size = 0;
}

//Constructor desde un puntero a char
String::String ( const char * str, int size ){
    char * pointer_start = new char[size + 1];
    int i = 0;
    //while (str[i] != '\0'){
    while (i <= size){
        pointer_start[i] = str[i];
        i++;
    }
	//pointer_start[size] = '\0';
	pointer_start[i] = '\0';
    s_size = size;
}

//Constructor desde un char
String::String ( char ch ){
    char * pointer_start = new char[2];
    pointer_start[0] = ch;
    pointer_start[1] = '\0';
    s_size = 1;
}

//Constructor desde un char con un tamaño determinado
String::String ( int size, char ch ){
    int i = 0;
    char * pointer_start = new char[size + 1];
    for (; i < size ; i++){
        pointer_start[i] = ch;
    }
    pointer_start[i] = '\0';
    s_size = size;
}

//Constructor copia de un objeto String
String::String ( const String & other ){
    char * pointer_start = new char[other.capacity() + 1];
    for (int i = 0; i <= other.count() ; i++){
        pointer_start[i] = other.pointer_start[i];
    }
    pointer_start[other.count() + 1] = '\0';
    s_size = other.capacity();
}

//Constructor desde un puntero a char*
String::String ( const char * str ){
    int isize = 0;
    while (str[isize] != '\0'){
        isize++;
    }
    char * pointer_start = new char[isize + 1];
    for (int i = 0; i < isize ; i++){
        pointer_start[i] = str[i];
    }
	s_size = isize;
}

//Destructor
String::~String (){
    delete [] pointer_start;
	s_size=0;
}

//Añadir un String al final de este String
String &  String::append ( const String & str ){

    int i = 0;
    String sTemporal(this);

    s_size = this.count() + str.count();
    delete [] this.pointer_start;

    pointer_start = new char[s_size + 1];

    for ( ; i <= sTemporal.count();i++){
        pointer_start[i] = sTemporal.pointer_start[i];
    }
    for ( ; i <= str.count();i++){
        pointer_start[i] = str[i];
    }
    pointer_start[s_size] = '\0';
    return this;
}

//Añadir un puntero a char al final de este String *
String &  String::append ( const char * str ){

    //Obtiene tamaño de str
    int isize = 0;
    while (str[isize] != '\0'){
        isize++;
    }

    String sTemporal(this);
    delete [] this.pointer_start;
    s_size = this.count() + isize;

    int i = 0;
    pointer_start = new char[s_size + 1];

    for ( ; i<= sTemporal.count();i++){
        pointer_start[i] = sTemporal.pointer_start[i];
    }
    for ( ; i<= isize;i++){
        pointer_start[i] = str[i];
    }
    pointer_start[s_size] = '\0';
    return this;
}

//Añadir un char al final de este String
String & String::append ( char ch ){

    String sTemporal(this);
    s_size = this.count() + 1;
    delete [] pointer_start;

    pointer_start = new char[s_size + 1];

    int i = 0;
    //Recorre primera cadena
    for ( ; i<= sTemporal.count();i++){
        pointer_start[i] = sTemporal.pointer_start[i];
    }
    pointer_start[i] = ch;
    pointer_start[s_size] = '\0';
    //Retorna el mismo objeto
    return this;
}

// Devuelve la capacidad de caracteres que puede almacenar
int String::capacity () const{
    return s_size;
}

// Limpia el String
void String::clear (){
    for (int i = 0; i <= s_size ; i++){
        pointer_start[i] = ' ';
    }
}

// Compara dos Strings en su contenido
int String::compare ( const String & other ) const{
    for (int i = 0; i < this.count() ; i++){
        if (pointer_start[i] != other.pointer_start[i]){
            return -1;
        }
    }
    return 0;
}

// Cuenta la cantidad de char que ocupan este String
int String::count () const{
    int iused = 0;
    while (pointer_start[iused] != '\0'){
        i++;
    }
    return iused;
}

// Retorna la dirección de la data en un puntero variable
char * String::data (){
    return pointer_start;
}

// Retorna la dirección de la data en un puntero constante
const char * String::data () const{
    return pointer_start;
}

// Llena el objeto String con el caracter, segun la cantidad indicada
String & String::fill ( char ch, int size = -1 ){
    if (size >= 1){
        this.clear();
        delete [] pointer_start;

        this = new String(size,ch);
        return this;
    }
}

// Obtiene la posicion desde la cual inicia el objeto String buscado
int String::indexOf ( const String & str, int from = 0) const{

}

//Inserta un objeto String desde la posicion indicada
String & String::insert ( int position, const String & str ){

}

//Inserta array de char desde la posicion indicada
String & String::insert ( int position, const char * unicode, int size ){

}

//Inserta un char desde la posicion indicada
String & String::insert ( int position, char ch ){

}

bool String::isEmpty () const{

}

bool String::isNull () const{

}
