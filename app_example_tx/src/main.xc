// Copyright (c) 2011, XMOS Ltd, All rights reserved
// This software is freely distributable under a derivative of the
// University of Illinois/NCSA Open Source License posted in
// LICENSE.txt and at <http://github.xcore.com/>

#include <xs1.h>
#include "SpdifTransmit.h"

buffered out port:32 oneBitPort = XS1_PORT_1F;
in port masterClockPort = XS1_PORT_1E;
clock clockblock = XS1_CLKBLK_1;

void transmitSpdif(chanend c)  {
    SpdifTransmitPortConfig(oneBitPort, clockblock, masterClockPort);
    SpdifTransmit(oneBitPort, c);
}

void generate(chanend c) {
    for(int i = 0; i < 10; i++) {
        outuint(c, i);
    }
    outct(c, 1);
}

int main(void) {
    chan c;
    par {
        transmitSpdif(c);
        generate(c);
    }
    return 0;
}
