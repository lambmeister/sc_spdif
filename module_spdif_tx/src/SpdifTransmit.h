// Copyright (c) 2011, XMOS Ltd, All rights reserved
// This software is freely distributable under a derivative of the
// University of Illinois/NCSA Open Source License posted in
// LICENSE.txt and at <http://github.xcore.com/>


#ifndef _SPDIF_TRANSMIT_
#define _SPDIF_TRANSMIT_

/** 
 * @brief   S/PDIF transmitter thread 
 * @brief   p           S/PDIF tx port 
 * @param   c           Channel-end for sample freq and samples
 * @return  void
 * 
 * Function expects a buffered single bit port clock from the master clock 
 * 
 * All channel communication is done via builtins (e.g. 
 * outuint, outct etc.)
 * 
 * On startup expects two words over the channel:
 *
 * 1) Desired sample frequency (in Hz)
 * 2) Master clock frequency (in Hz)
 *
 * Then sample pairs:
 *
 * 1) Left sample
 * 2) Right sample
 *
 *
 * If a XS1_CT_END token is received, the thread stops and waits for new sample/master freq pair
 *
 */
void SpdifTransmit(buffered out port:32 p, chanend c);

void SpdifTransmitPortConfig(out buffered port:32 p, clock cl, in port p_mclk);

#endif

