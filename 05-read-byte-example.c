//////////////////////////////////////////////////////////////////////////////
// READ_BYTE - reads a byte from the one-wire bus.
//
unsigned char read_byte(void)
{
    unsigned char i;
    unsigned char value = 0;
    for (i = 0; i < 8; i++)
    {
        if (read_bit())
            value |= 0x01 << i; // reads byte in, one byte at a time and then
        // shifts it left
        delay(6); // wait for rest of timeslot
    }
    return (value);
}