#include "AString.h"

int main(int argc, char** argv)
{
    AString name = "Alex's";
    cout << name << endl;
    name.shift( -5 );
    cout << name << endl;
    name.shift( 2 );
    cout << name << endl;
    name.shift( 3 );
    cout << name << endl;
    return 0;
}
