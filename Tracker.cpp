#pragma once

#include <iostream>

struct Allocation 
{
    uint32_t Allocated = 0;
    uint32_t Freed = 0;

    uint32_t usage() { return Allocated - Freed; }
};

static Allocation s_allocation;

void* operator new (size_t size) 
{
    s_allocation.Allocated += size;
    return malloc(size);
}

void operator delete (void* memory, size_t size) 
{
    s_allocation.Freed += size; 
    free(memory);
}

void printUsage () 
{
    std::cout << "Allocated: " << s_allocation.Allocated << " Bytes \n";
    std::cout << "Freed: " << s_allocation.Freed << " Bytes \n";
    std::cout << "Still in use: " << s_allocation.usage() << " Bytes \n";
}