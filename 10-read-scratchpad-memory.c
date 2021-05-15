void Read_ScratchPad(void)
{
    int j;
    char pad[10];
    printf("\nReading ScratchPad Data\n");
    write_byte(0xBE);
    for (j = 0; j < 9; j++)
    {
        pad[j] = read_byte();
    }
    printf("\n ScratchPAD DATA = %X%X%X%X%X%X\n", pad[8], pad[7], pad[6], pad[5], pad[4], pad[3], pad[2], pad[1], pad[0]);
}

void Read_ROMCode(void)
{
    int n;
    char dat[9];
    printf("\nReading ROM Code\n");
    ow_reset();
    write_byte(0x33);
    for (n = 0; n < 8; n++)
    {
        dat[n] = read_byte();
    }
    printf("\n ROM Code = %X%X%X%X\n", dat[7], dat[6], dat[5], dat[4], dat[3], dat[2], dat[1], dat[0]);
}

// Perform Match ROM
//
unsigned char Send_MatchRom(void)
{
    unsigned char i;
    if (ow_reset())
        return false;
    write_byte(0x55); // match ROM
    for (i = 0; i < 8; i++)
    {
        write_byte(FoundROM[numROMs][i]); //send ROM code
    }
    return true;
}