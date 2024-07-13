#include "engine.h"

int main()
{
    event_loop(&setup, &draw, &prerender, &postrender);
    return 0;
}
