#include <project.h>
#include "TDC1000.h"

/* Functions */
void TDC1000_setCONFIG_0(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_CONFIG_0_ADDR);
    SPI_WriteTxData(value);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setCONFIG_1(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_CONFIG_1_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setCONFIG_2(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_CONFIG_2_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setCONFIG_3(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_CONFIG_3_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setCONFIG_4(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_CONFIG_4_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setTOF_1(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_TOF_1_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setTOF_0(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_TOF_0_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setERROR_FLAGS(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_ERROR_FLAGS_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setTIMEOUT(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_TIMEOUT_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

void TDC1000_setCLOCK_RATE(uint8_t value){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(WRITE_CMD | TDC1000_CLOCK_RATE_ADDR);
    SPI_WriteTxData(value);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
}

uint8_t TDC1000_getCONFIG_0(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_CONFIG_0_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getCONFIG_1(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_CONFIG_1_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getCONFIG_2(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_CONFIG_2_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getCONFIG_3(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_CONFIG_3_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getCONFIG_4(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_CONFIG_4_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getTOF_1(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_TOF_1_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getTOF_0(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_TOF_0_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getERROR_FLAGS(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_ERROR_FLAGS_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getTIMEOUT(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_TIMEOUT_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

uint8_t TDC1000_getCLOCK_RATE(void){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctlr_Write(0);
    SPI_WriteTxData(READ_CMD | TDC1000_CLOCK_RATE_ADDR);
    SPI_WriteTxData(DUMMY_BYTE);
    while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
    Ctlr_Write(1);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();    
}

uint8_t TDC1000_readModeSelect(void){
}

uint8_t TDC1000_readTXFreqDiv(void){
}

uint8_t TDC1000_readNumTX(void){
}

uint8_t TDC1000_readNumAvg(void){
}

uint8_t TDC1000_readNumRX(void){
}

uint8_t TDC1000_readEchoQualThld(void){
}

uint8_t TDC1000_readTXPhShiftPos(void){
}

uint8_t TDC1000_readPGAGain(void){
}

uint8_t TDC1000_readTimingReg(void){
}

uint8_t TDC1000_readShortToFBlankPeriod(void){
}

uint8_t TDC1000_readToFTimeoutCtrl(void){
}

uint8_t TDC1000_readAutozeroPeriod(void){
}

void TDC1000_setEnable(bool enable){
}

bool TDC1000_getEnable(void){
}

void TDC1000_reset(void){
}

bool TDC1000_readChannelSelect(void){
}

uint8_t TDC1000_readClockFreqIn(void){
}

void TDC1000_setClockFreqIn(uint32_t freq){
}

/* [] END OF FILE */
