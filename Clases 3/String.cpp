#include <string.h>
/*
    int us_size; //tamaño ocupado ln_size = 0 y máximo = m_size
    int tt_size;  //tamaño (real en caracteres)
    char * pointer_start; //puntero a contenido
*/

String::String (){
    char * pointer_start = new char[1];
    pointer_start[0] = '\0';
    s_size = 0;
}
String::String ( const char * str, int size ){
    char * pointer_start = new char[size + 1];
    for (int i=0;i < size;i++){
		pointer_start[i] = str[i];
    }
	pointer_start[size] = '\0';
    s_size = size;
}
String::String ( char ch ){
    char * pointer_start = new char[2];
    pointer_start[0] = ch;
    pointer_start[1] = '\\0\';
    s_size = 1;
}
String::String ( int size, char ch ){
    char * pointer_start = new char[size + 1];
    for (int i = 0; i < size ; i++){
        pointer_start[i] = ch;
    }
    pointer_start[size] = '\0';
    s_size = size;
}
String::String ( const String & other ){
    char * pointer_start = new char[other.capacity() + 1];
    for (int i = 0; i < size ; i++){
        pointer_start[i] = other.pointer_start[i];
    }
    pointer_start[other.count()] = '\0';
    s_size = other.count();
}
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
String::~String (){
    delete [] pointer_start;
	s_size=0;
}

String & append ( const String & str ){

}

String & append ( const char * str ){

}

String & append ( char ch ){

}


int String::capacity () const{
    return s_size;
}

void clear (){
    for (int i = 0; i < s_size ; i++){
        pointer_start[i] = '\0';
    }
}

int compare ( const String & other ) const{
    for (int i = 0; i < other.count() ; i++){
        if (pointer_start[i] != other.pointer_start[i]){
            return -1;
        }
    }
    return 0;
}

int String::count () const{
    int isize = 0;
    while (str[isize] != '\0'){
        isize++;
    }
    return isize;
}

String & fill ( char ch, int size = -1 ){
    String sNueva(size,ch);
    return * sNueva;
}

int indexOf ( const String & str, int from = 0) const{

}

