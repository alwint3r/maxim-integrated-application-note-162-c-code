// FIRST
// The First function resets the current state of a ROM search and calls
// Next to find the first device on the 1-Wire bus.
//
unsigned char First(void)
{
    lastDiscrep = 0; // reset the rom search last discrepancy global
    doneFlag = FALSE;
    return Next(); // call Next and return its return value
}

// NEXT
// The Next function searches for the next device on the 1-Wire bus. If
// there are no more devices on the 1-Wire then false is returned.
//
unsigned char Next(void)
{
    unsigned char m = 1; // ROM Bit index
    unsigned char n = 0; // ROM Byte index
    unsigned char k = 1; // bit mask
    unsigned char x = 0;
    unsigned char discrepMarker = 0; // discrepancy marker
    unsigned char g;                 // Output bit
    unsigned char nxt;               // return value
    int flag;
    nxt = FALSE;          // set the next flag to false
    dowcrc = 0;           // reset the dowcrc
    flag = ow_reset();    // reset the 1-Wire
    if (flag || doneFlag) // no parts -> return false
    {
        lastDiscrep = 0; // reset the search
        return FALSE;
    }
    write_byte(0xF0); // send SearchROM command
    do
    // for all eight bytes
    {
        x = 0;
        if (read_bit() == 1)
            x = 2;
        delay(6);
        if (read_bit() == 1)
            x |= 1; // and its complement
        if (x == 3) // there are no devices on the 1-Wire
            break;

        else
        {
            if (x > 0)      // all devices coupled have 0 or 1
                g = x >> 1; // bit write value for search
            else
            {
                // if this discrepancy is before the last
                // discrepancy on a previous Next then pick
                // the same as last time
                if (m < lastDiscrep)
                    g = ((ROM[n] & k) > 0);
                else                        // if equal to last pick 1
                    g = (m == lastDiscrep); // if not then pick 0
                // if 0 was picked then record
                // position with mask k
                if (g == 0)
                    discrepMarker = m;
            }
            if (g == 1) // isolate bit in ROM[n] with mask k
                ROM[n] |= k;
            else
                ROM[n] &= ~k;
            write_bit(g);       // ROM search write
            m++;                // increment bit counter m
            k = k << 1;         // and shift the bit mask k
            if (k == 0)         // if the mask is 0 then go to new ROM
            {                   // byte n and reset mask
                ow_crc(ROM[n]); // accumulate the CRC
                n++;
                k++;
            }
        }
    } while (n < 8);      //loop until through all ROM bytes 0-7
    if (m < 65 || dowcrc) // if search was unsuccessful then
        lastDiscrep = 0;  // reset the last discrepancy to 0
    else
    {
        // search was successful, so set lastDiscrep,
        // lastOne, nxt
        lastDiscrep = discrepMarker;
        doneFlag = (lastDiscrep == 0);
        nxt = TRUE; // indicates search is not complete yet, more
        // parts remain
    }
    return nxt;
}

// FIND DEVICES
void FindDevices(void)
{
    unsigned char m;
    if (!ow_reset()) //Begins when a presence is detected
    {
        if (First()) //Begins when at least one part is found
        {
            numROMs = 0;
            do
            {
                numROMs++;
                for (m = 0; m < 8; m++)
                {
                    FoundROM[numROMs][m] = ROM[m]; //Identifies ROM
                    \\number on found device
                }
                printf("\nROM CODE =%02X%02X%02X%02X\n",
                       FoundROM[5][7], FoundROM[5][6], FoundROM[5][5], FoundROM[5][4],
                       FoundROM[5][3], FoundROM[5][2], FoundROM[5][1], FoundROM[5][0]);
            } while (Next() && (numROMs < 10)); //Continues until no additional devices are found
        }
    }
}
