//////////////////////////////////////////////////////////////////////////////
// OW_RESET - performs a reset on the one-wire bus and
// returns the presence detect. Reset is 480us, so delay
// value is (480-24)/16 = 28.5 - we use 29. Presence checked
// another 70us later, so delay is (70-24)/16 = 2.875 - we use 3.
//
unsigned char ow_reset(void)
{
    unsigned char presence;
    DQ = 0;            //pull DQ line low
    delay(29);         // leave it low for 480us
    DQ = 1;            // allow line to return high
    delay(3);          // wait for presence
    presence = DQ;     // get presence signal
    delay(25);         // wait for end of timeslot
    return (presence); // presence signal returned
} // 0=presence, 1 = no part
