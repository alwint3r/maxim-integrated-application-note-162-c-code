//////////////////////////////////////////////////////////////////////////////
// WRITE_BIT - writes a bit to the one-wire bus, passed in bitval.
//
void write_bit(char bitval)
{
    DQ = 0; // pull DQ low to start timeslot
    if (bitval == 1)
        DQ = 1; // return DQ high if write 1
    delay(5);   // hold value for remainder of timeslot
    DQ = 1;
} // Delay provides 16us per loop, plus 24us. Therefore delay(5) = 104us