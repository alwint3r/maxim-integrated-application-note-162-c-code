//////////////////////////////////////////////////////////////////////////////
// WRITE_BYTE - writes a byte to the one-wire bus.
//
void write_byte(char val)
{
    unsigned char i;
    unsigned char temp;
    for (i = 0; i < 8; i++) // writes byte, one bit at a time
    {
        temp = val >> i; // shifts val right 'i' spaces
        temp &= 0x01;    // copy that bit to temp
        write_bit(temp); // write bit in temp into
    }
    delay(5);
}