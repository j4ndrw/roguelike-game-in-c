#include "engine.h"
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    event_loop(&setup, &draw, &prerender, &postrender);
    return 0;
}
