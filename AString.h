#ifndef A_STRING_H
#define A_STRING_H
#include <iostream>

using namespace std;

class AString
{
    char* _array;
    unsigned _size;
    unsigned _alloc;

public:
    AString(  );
    AString( const char );
    AString( const char* );
    AString( const char*, const int );
    AString( const string& );
    AString( const AString& );
    ~AString(  );

    const unsigned length(  ) const;
    const unsigned max_length(  ) const;

    void append( const char );
    void append( const char* );
    void append( const char*, int );
    void append( const string& );
    void append( const AString& );

    void insert( const char, const unsigned );
    void insert( const char*, const unsigned );
    void insert( const char*, const unsigned, const unsigned );
    void insert( const string&, const unsigned );
    void insert( const AString&, const unsigned );

    void remove(  );
    void remove( unsigned );
    void remove( unsigned, unsigned );

    char charAt( const int ) const;
    void swap( const unsigned, const unsigned );
    void shift( const int );

    AString& operator= ( const AString& );
    AString& operator= ( const string& );
    AString& operator= ( const char* );
    AString& operator= ( const char );

    AString operator+ ( const AString& ) const;
    AString operator+ ( const string& ) const;
    AString operator+ ( const char* ) const;
    AString operator+ ( const char ) const;

    AString& operator+= ( const AString& );
    AString& operator+= ( const string& );
	AString& operator+= ( const char* );
	AString& operator+= ( const char );

    char& operator[] ( int );
    const char& operator[] ( int ) const;

    AString operator( ) ( unsigned, unsigned ) const;

    bool operator== ( const AString& ) const;
    bool operator== ( const string ) const;
    bool operator== ( const char* ) const;

	friend bool operator== ( const string, const AString& );
	friend bool operator== ( const char*, const AString& );

    friend ostream& operator<< ( ostream&, const AString& );
    friend ostream& operator<< ( ostream&, const AString* );

    friend ifstream& operator>> ( ifstream&, const AString& );

};

#endif
