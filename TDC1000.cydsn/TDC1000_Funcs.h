/*
 * @file TDC1000.h
 * @author Carlos Diaz
 * @version v0_1
 * @date 2016
 * @brief Este archivo contiene todos los prototipos
 * de las funciones para el driver del AFE TDC1000
*/

#ifndef TDC1000_H_
#define TDC1000_H_

#ifdef __cplusplus
 extern "C"
{
#endif

/* External includes  */
#include <cytypes.h>
#include <stdbool.h>
#include <stdlib.h>

/* Contants */

/* SPI Commands */
#define TDC1000_READ_CMD    0x00
#define TDC1000_WRITE_CMD   0x40
#define TDC1000_DUMMY_BYTE  0x00

typedef struct{
    uint8_t CONFIG_0;
    uint8_t CONFIG_1;
    uint8_t CONFIG_2;
    uint8_t CONFIG_3;
    uint8_t CONFIG_4;
    uint8_t TOF_1;
    uint8_t TOF_0;
    uint8_t ERROR_FLAGS;
    uint8_t TIMEOUT;
    uint8_t CLOCK_RATE;
}TDC1000_INIT_t;

/* Functions */
void TDC1000_Start(TDC1000_INIT_t* tdc);
void TDC1000_Enable(void);
void TDC1000_setConfig(TDC1000_INIT_t* tdc, bool continuous);
void TDC1000_getConfig(TDC1000_INIT_t* tdc, bool continuous);
void TDC1000_Reset(void);
uint8_t TDC1000_readModeSelect(void);
uint8_t TDC1000_readTXFreqDiv(void);
uint8_t TDC1000_readNumTX(void);
uint8_t TDC1000_readNumAvg(void);
uint8_t TDC1000_readNumRX(void);
uint8_t TDC1000_readEchoQualThld(void);
uint8_t TDC1000_readTXPhShiftPos(void);
uint8_t TDC1000_readPGAGain(void);
uint8_t TDC1000_readTimingReg(void);
uint8_t TDC1000_readShortToFBlankPeriod(void);
uint8_t TDC1000_readToFTimeoutCtrl(void);
uint8_t TDC1000_readAutozeroPeriod(void);
void TDC1000_setEnable(bool enable);
bool TDC1000_getEnable(void);
bool TDC1000_readChannelSelect(void);
uint8_t TDC1000_readClockFreqIn(void);
void TDC1000_setClockFreqIn(uint32_t freq);

void TDC1000_Trigger(void);

void TDC1000_setCONFIG_0(uint8_t data);
void TDC1000_setCONFIG_1(uint8_t data);
void TDC1000_setCONFIG_2(uint8_t data);
void TDC1000_setCONFIG_3(uint8_t data);
void TDC1000_setCONFIG_4(uint8_t data);
void TDC1000_setTOF_1(uint8_t data);
void TDC1000_setTOF_0(uint8_t data);
void TDC1000_setERROR_FLAGS(uint8_t data);
void TDC1000_setTIMEOUT(uint8_t data);
void TDC1000_setCLOCK_RATE(uint8_t data);
uint8_t TDC1000_getCONFIG_0(void);
uint8_t TDC1000_getCONFIG_1(void);
uint8_t TDC1000_getCONFIG_2(void);
uint8_t TDC1000_getCONFIG_3(void);
uint8_t TDC1000_getCONFIG_4(void);
uint8_t TDC1000_getTOF_1(void);
uint8_t TDC1000_getTOF_0(void);
uint8_t TDC1000_getERROR_FLAGS(void);
uint8_t TDC1000_getTIMEOUT(void);
uint8_t TDC1000_getCLOCK_RATE(void);

void TDC1000_WriteSingleRegister(uint8_t regAddr, uint8_t data);
uint8_t TDC1000_ReadSingleRegister(uint8_t regAddr);

#ifdef __cplusplus
}
#endif

#endif	/* TDC1000_H_  */

/* End of file  */
