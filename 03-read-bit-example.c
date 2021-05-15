//////////////////////////////////////////////////////////////////////////////
// READ_BIT - reads a bit from the one-wire bus. The delay
// required for a read is 15us, so the DELAY routine won't work.
// We put our own delay function in this routine in the form of a
// for() loop.
//
unsigned char read_bit(void)
{
    unsigned char i;
    DQ = 0; // pull DQ low to start timeslot
    DQ = 1; // then return high
    for (i = 0; i < 3; i++)
        ;        // delay 15us from start of timeslot
    return (DQ); // return value of DQ line
}