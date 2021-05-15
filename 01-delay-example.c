// DELAY - with an 11.059MHz crystal.
// Calling the routine takes about 24us, and then
// each count takes another 16us.

void delay(int useconds)
{
    int s;
    for (s = 0; s < useconds; s++)
        ;
}
