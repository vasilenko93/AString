#include <string>
#include "AString.h"

AString::AString(  )
:_array(NULL), _size(0), _alloc(0)
{
}

AString::AString( const char c )
:_array(NULL), _size(0), _alloc(0)
{
    append(c);
}

AString::AString( const char* c )
:_array(NULL), _size(0), _alloc(0)
{
    unsigned i = 0;
    while(c[i] != '\0')
    {
        append(c[i]);
        i++;
    }
}

AString::AString( const char* c, const int l )
:_array(NULL), _size(0), _alloc(0)
{
    for(int i = 0; i < l; i++ )
        append(c[i]);
}

AString::AString( const string& s )
:_array(NULL), _size(0), _alloc(0)
{
    for(unsigned i = 0; i < s.length(); i++)
        append(s[i]);
}

AString::AString( const AString& s )
:_array(NULL), _size(0), _alloc(0)
{
    for(unsigned i = 0; i < s._size; i++)
        append(s._array[i]);
}

AString::~AString(  )
{
    delete [] _array;
    _size = 0;
    _alloc = 0;
}

const unsigned AString::length(  ) const
{
    return _size;
}

const unsigned AString::max_length(  ) const
{
    return _alloc;
}

void AString::append( const char c )
{
    if( _size == _alloc)
    {
        _alloc = 2 * _alloc + 1;
        char* temp = new char[ _alloc ];
        for ( unsigned i=0; i < _size; i++ )
            temp[i] = _array[i];
        delete [] _array;
        _array = temp;
    }
    _array[_size++] = c;
}

void AString::append( const char* c)
{
    unsigned i = 0;
    while(c[i] != '\0')
    {
        append(c[i]);
        i++;
    }
}

void AString::append( const char* c, int l )
{
    for(int i = 0; i < l; i++ )
        append(c[i]);
}

void AString::append( const string& s )
{
    for(unsigned i = 0; i < s.length(); i++)
        append(s[i]);
}

void AString::append( const AString& s )
{
    for(unsigned i = 0; i < s._size; i++)
        append(s._array[i]);
}


void AString::insert( const char c, const unsigned lc )
{
    AString temp;
    for( unsigned i =0; i < _size; i++ )
    {
        if (i == lc)
            temp.append(c);
        temp.append(_array[i]);
    }

    *this = temp;
}

void AString::insert( const char* s, const unsigned lc )
{
    AString temp;
    for( unsigned i = 0; i < _size; i++ )
    {
        if (i == lc)
        {
            unsigned cnt = 0;
            while(s[cnt] != '\0')
            {
                temp.append(s[cnt]);
                cnt++;
            }
        }
        temp.append(_array[i]);
    }

    *this = temp;
}

void AString::insert( const char* s, unsigned int l, const unsigned lc )
{
    AString temp;
    for( unsigned i = 0; i < _size; i++ )
    {
        if (i == lc)
        {
            for(unsigned j = 0; j <= l; j++)
                temp.append(s[j]);
        }
        temp.append(_array[i]);
    }

    *this = temp;
}

void AString::insert( const string& s, const unsigned lc )
{
    AString temp;
    for( unsigned i = 0; i < _size; i++ )
    {
        if (i == lc)
        {
            for(unsigned j = 0; j <= s.length(); j++)
                temp.append(s[j]);
        }
        temp.append(_array[i]);
    }

    *this = temp;
}

void AString::insert( const AString& s, const unsigned lc )
{
    AString temp;
    for( unsigned i = 0; i < _size; i++ )
    {
        if (i == lc)
        {
            for(unsigned j = 0; j < s._size; j++)
                temp.append(s._array[j]);
        }
        temp.append(_array[i]);
    }

    *this = temp;
}


void AString::remove(  )
{
    remove(_size - 1);
}

void AString::remove( unsigned ind )
{
    AString temp;
    for(unsigned i = 0; i < _size; i++)
    {
        if(i != ind)
            temp.append(_array[i]);
    }
    delete [] _array;
    _array = NULL;
    _size = 0;
    _alloc = 0;

    *this = temp;
}

void AString::remove( unsigned indF, unsigned indL )
{
    AString temp;
    for(unsigned i = 0; i < _size; i++)
    {
        if(i < indF || i > indL )
            temp.append(_array[i]);
    }
    delete [] _array;
    _array = NULL;
    _size = 0;
    _alloc = 0;

    *this = temp;
}


char AString::charAt( const int ind ) const
{
    return _array[ind];
}

void AString::swap( const unsigned ind1, const unsigned ind2 )
{
    char temp;
    if(ind1 != ind2)
    {
        temp = _array[ind1];
        _array[ind1] = _array[ind2];
        _array[ind2] = temp;
    }
}

void AString::shift( const int ammount )
{
    int amnt = ammount;
    if( amnt > (int)_size )
        amnt = amnt % _size;
    if( ammount > 0 )
    {
        char *temp = new char[amnt];
        for( int i = 0; i < amnt; i++ )
            temp[i] = _array[ (_size - amnt) + i ];

        for( int i = _size - amnt - 1; i >= 0; i-- )
            _array[i + amnt] = _array[i];

        for( int i = 0; i < amnt; i++ )
            _array[i] = temp[i];
        delete[] temp;
    }
    else if( ammount < 0 )
    {
        amnt = amnt * -1;
        char *temp = new char[amnt];
        for( int i = 0; i < amnt; i++ )
            temp[i] = _array[i];

        for( int i = amnt; i <= (int)_size - 1; i++ )
            _array[i - amnt] = _array[i];

        for( int i = 0, j = _size - amnt; i < amnt; i++, j++)
            _array[j] = temp[i];
        delete[] temp;
    }
}


AString& AString::operator= ( const AString& rhs )
{
    if ( this == &rhs )
        return *this;

    delete [] _array;
    _array = NULL;
    _size = 0;
    _alloc = 0;

    for (unsigned i = 0; i < rhs._size; i++)
        append(rhs._array[i]);

    return *this;
}

AString& AString::operator= ( const string& s )
{
    delete [] _array;
    _array = NULL;
    _size = 0;
    _alloc = 0;

    for(unsigned i = 0; i < s.length(); i++)
        append(s[i]);
    return *this;
}

AString& AString::operator= ( const char* s )
{
    delete [] _array;
    _array = NULL;
    _size = 0;
    _alloc = 0;

    int i = 0;
    while(s[i] != '\0')
    {
        append(s[i]);
        i++;
    }
    return *this;
}

AString& AString::operator= ( const char c )
{
    delete [] _array;
    _array = NULL;
    _size = 0;
    _alloc = 0;

    append(c);
    return *this;
}

AString AString::operator+ ( const AString& rhs ) const
{
    AString temp(*this);
    for(unsigned i = 0; i < rhs._size; i++)
        temp.append(rhs._array[i]);
    return temp;
}

AString AString::operator+ ( const string& rhs ) const
{
    AString temp(*this);
    for(unsigned i = 0; i < rhs.length(); i++)
        temp.append(rhs[i]);
    return temp;
}

AString AString::operator+ ( const char* rhs ) const
{
    AString temp(*this);
    unsigned i = 0;
    while( rhs[i] != '\0')
        temp.append(rhs[i++]);
    return temp;
}

AString AString::operator+ ( const char rhs ) const
{
    AString temp(*this);
    temp.append(rhs);
    return temp;
}


AString& AString::operator+= ( const AString& rhs )
{
    append(rhs);
    return *this;
}

AString& AString::operator+= ( const string& rhs )
{
    append(rhs);
    return *this;
}

AString& AString::operator+= ( const char* rhs )
{
    append(rhs);
    return *this;
}

AString& AString::operator+= ( const char rhs )
{
    append(rhs);
    return *this;
}


char& AString::operator[] ( int ind )
{
    return _array[ind];
}

const char& AString::operator[] ( int ind ) const
{
    return _array[ind];
}

AString AString::operator( ) ( unsigned indF, unsigned indL ) const
{
    AString temp;
    unsigned limit = indL;
    if( limit > _size - 1 )
        limit = _size;
    for(unsigned i = indF; i <= limit; i++)
        temp.append(_array[i]);
    return temp;
}


ostream& operator<< ( ostream& os, const AString& arr )
{
    for (unsigned i = 0; i < arr._size; i++)
        os << arr._array[i];
    return os;
}

ostream& operator<< ( ostream& os, const AString* arr )
{
    return os;
}

ifstream& operator>> ( ifstream& is, const AString& arr )
{
    return is;
}
