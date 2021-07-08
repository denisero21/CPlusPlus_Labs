//---------------------------------------------------------------------------

#pragma hdrstop

#include "node.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Node::Node(char x)
{
    symbol = x;
    ptrPrevious = nullptr;
}

char Node::Symbol()
{
    return symbol;
}

