#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

class String{
    private:
        int us_size; //tamaño ocupado ln_size = 0 y máximo = m_size
        int tt_size;  //tamaño (real en caracteres)
        char * pointer_start; //puntero a contenido

    public:
    /*CONSTRUCTORES Y DESTRUCTORES*/
    String ();
    String ( const char * str, int size );
    String ( char ch );
    String ( int size, char ch );
    String ( const String & other );
    String ( const char * str );
    ~String ();

    /*FUNCIONES APPEND: (Inserta el contenido al final del String)*/
    String & append ( const String & str );
    String & append ( const char * str );
    String & append ( char ch );

    int capacity () const; //(Retorna el tamaño de la candena)
    void clear ();  //(Limpia la cadena)
    int compare ( const String & other ) const; //(compara 2 cadenas)
    int count () const; //(retorna el número de caracteres)

    char * data (); //(retorna la dirección de la data en un puntero variable)*
    const char * data () const; //(retorna la dirección de la data en un puntero constante)*

    String & fill ( char ch, int size = -1 ); //(Llena la cadena con el caracter ch, size veces)
    int indexOf ( const String & str, int from = 0) const; //(Retorna el la posición desde donde se encuentra str dentro de toda la cadena, iniciando en from)

    //(Similar a append, pero desde una posición)
    String & insert ( int position, const String & str );
    String & insert ( int position, const char * unicode, int size );
    String & insert ( int position, char ch );

    bool isEmpty () const;
    bool isNull () const;

    //(Inserta al final)
    void push_back ( const String & other );
    void push_back ( char ch );

    //(Inserta al inicio)
    void push_front ( const String & other );
    void push_front ( char ch );

    String & remove ( int position, int n ); //(Remueve n carecteres desde una posición)
    String repeated ( int times ) const; //(Repite toda la cadena times veces)
    String & replace ( int position, int n, const String & after ); //(Remplaza una cadena)

    //Sobrecarga de operadores
    bool operator!= ( const String & other ) const;
    bool operator!= ( const char * other ) const;
    String & operator+= ( const String & other );
    String & operator+= ( const char * str );
    String & operator+= ( char ch );
    //String & operator+= ( char ch );
    bool operator< ( const String & other ) const;
    bool operator< ( const char * other ) const;
    bool operator<= ( const String & other ) const;
    bool operator<= ( const char * other ) const;
    String & operator= ( const String & other );
    String & operator= ( const char * str );
    String & operator= ( char ch );
    //String & operator= ( char ch );
    bool operator== ( const String & other ) const;
    bool operator== ( const char * other ) const;
    bool operator> ( const String & other ) const;
    bool operator> ( const char * other ) const;
    bool operator>= ( const String & other ) const;
    bool operator>= ( const char * other ) const;
    //charRef operator[] ( int position );
    const char operator[] ( int position ) const;
    //charRef operator[] ( uint position );
    //const char operator[] ( int position ) const;
}

#endif // STRING_H_INCLUDED
