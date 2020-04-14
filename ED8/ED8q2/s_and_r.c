static unsigned long int next = 1; // seed

int rand1(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) ((((next/65536) % 32768) % 10)+1); // Changed for [1-10] range
}

void srand1(unsigned int seed)
{
    next = seed;
}