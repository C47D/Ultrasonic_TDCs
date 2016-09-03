#include <project.h>
#include "TDC7200_Regs.h"
#include "TDC7200_Funcs.h"

#define SLAVE_TDC7200 0x01
#define SLAVE_DESELECT 0x03

#define ENABLE_TDC7200 0x01

void TDC7200_Start(TDC7200_INIT_t* tdc){
    TDC7200_setConfig(tdc);
    TDC7200_Enable();
}

void TDC7200_Enable(void){
    /* El pin EN del TDC7200 debe estar a 1 lógico para poder usarlo*/
    Ctrl_Write(ENABLE_TDC7200);
}

void TDC7200_setConfig(TDC7200_INIT_t* tdc){
    TDC7200_setCONFIG1(tdc->CONFIG_1);
    TDC7200_setCONFIG2(tdc->CONFIG_2);
    TDC7200_setINT_STATUS(tdc->INT_STATUS);
    TDC7200_setINT_MASK(tdc->INT_MASK);
    TDC7200_setCOARSE_CNTR_OVF_H(tdc->COARSE_CNTR_OVF_H);
    TDC7200_setCOARSE_CNTR_OVF_L(tdc->COARSE_CNTR_OVF_L);
    TDC7200_setCLOCK_CNTR_OVF_H(tdc->CLOCK_CNTR_OVF_H);
    TDC7200_setCLOCK_CNTR_OVF_L(tdc->CLOCK_CNTR_OVF_L);
    TDC7200_setCLOCK_CNTR_STOP_MASK_H(tdc->CLOCK_CNTR_STOP_MASK_H);
    TDC7200_setCLOCK_CNTR_STOP_MASK_L(tdc->CLOCK_CNTR_STOP_MASK_L);
}

void TDC7200_getConfig(TDC7200_INIT_t* tdc){
    tdc->CONFIG_1 = TDC7200_getCONFIG1();
    tdc->CONFIG_2 = TDC7200_getCONFIG2();
    tdc->INT_STATUS = TDC7200_getINT_STATUS();
    tdc->INT_MASK = TDC7200_getINT_MASK();
    tdc->COARSE_CNTR_OVF_H = TDC7200_getCOARSE_CNTR_OVF_H();
    tdc->COARSE_CNTR_OVF_L = TDC7200_getCOARSE_CNTR_OVF_L();
    tdc->CLOCK_CNTR_OVF_H = TDC7200_getCLOCK_CNTR_OVF_H();
    tdc->CLOCK_CNTR_OVF_L = TDC7200_getCLOCK_CNTR_OVF_L();
    tdc->CLOCK_CNTR_STOP_MASK_H = TDC7200_getCLOCK_CNTR_STOP_MASK_H();
    tdc->CLOCK_CNTR_STOP_MASK_L = TDC7200_getCLOCK_CNTR_STOP_MASK_L();
}

/* Funciones para obtener el valor de los registros */
uint8_t TDC7200_getCONFIG1(void){
    return TDC7200_ReadSingleRegister(TDC7200_CONFIG1_ADDR);
}

uint8_t TDC7200_getCONFIG2(void){
    return TDC7200_ReadSingleRegister(TDC7200_CONFIG2_ADDR);
}

uint8_t TDC7200_getINT_STATUS(void){
    return TDC7200_ReadSingleRegister(TDC7200_INT_STATUS_ADDR);
}

uint8_t TDC7200_getINT_MASK(void){
    return TDC7200_ReadSingleRegister(TDC7200_INT_MASK_ADDR);
}

uint8_t TDC7200_getCOARSE_CNTR_OVF_H(void){
    return TDC7200_ReadSingleRegister(TDC7200_COARSE_CNTR_OVF_H);
}

uint8_t TDC7200_getCOARSE_CNTR_OVF_L(void){
    return TDC7200_ReadSingleRegister(TDC7200_COARSE_CNTR_OVF_L);
}

uint8_t TDC7200_getCLOCK_CNTR_OVF_H(void){
    return TDC7200_ReadSingleRegister(TDC7200_CLOCK_CNTR_OVF_H);
}

uint8_t TDC7200_getCLOCK_CNTR_OVF_L(void){
    return TDC7200_ReadSingleRegister(TDC7200_CLOCK_CNTR_OVF_L);
}

uint8_t TDC7200_getCLOCK_CNTR_STOP_MASK_H(void){
    return TDC7200_ReadSingleRegister(TDC7200_CLOCK_CNTR_STOP_MASK_H);
}

uint8_t TDC7200_getCLOCK_CNTR_STOP_MASK_L(void){
    return TDC7200_ReadSingleRegister(TDC7200_CLOCK_CNTR_STOP_MASK_L);
}

/* Los siguientes registros tienen un tamaño de 24 bites */
uint32_t TDC7200_getTIME1(void){
    return TDC7200_Read24bitRegister(TDC7200_TIME1_ADDR);
}

uint32_t TDC7200_getCLOCK_COUNT1(void){
    return TDC7200_Read24bitRegister(TDC7200_CLOCK_COUNT1_ADDR);
}

uint32_t TDC7200_getTIME2(void){
    return TDC7200_Read24bitRegister(TDC7200_TIME2_ADDR);
}

uint32_t TDC7200_getCLOCK_COUNT2(void){
    return TDC7200_Read24bitRegister(TDC7200_CLOCK_COUNT2_ADDR);
}

uint32_t TDC7200_getTIME3(void){
    return TDC7200_Read24bitRegister(TDC7200_TIME3_ADDR);
}

uint32_t TDC7200_getCLOCK_COUNT3(void){
    return TDC7200_Read24bitRegister(TDC7200_CLOCK_COUNT3_ADDR);
}

uint32_t TDC7200_getTIME4(void){
    return TDC7200_Read24bitRegister(TDC7200_TIME4_ADDR);
}

uint32_t TDC7200_getCLOCK_COUNT4(void){
    return TDC7200_Read24bitRegister(TDC7200_CLOCK_COUNT4_ADDR);
}

uint32_t TDC7200_getTIME5(void){
    return TDC7200_Read24bitRegister(TDC7200_TIME5_ADDR);
}

uint32_t TDC7200_getCLOCK_COUNT5(void){
    return TDC7200_Read24bitRegister(TDC7200_CLOCK_COUNT5_ADDR);
}

uint32_t TDC7200_getTIME6(void){
    return TDC7200_Read24bitRegister(TDC7200_TIME6_ADDR);
}

uint32_t TDC7200_getCALIBRATION1(void){
    return TDC7200_Read24bitRegister(TDC7200_CALIBRATION1_ADDR);
}

uint32_t TDC7200_getCALIBRATION2(void){
    return TDC7200_Read24bitRegister(TDC7200_CALIBRATION2_ADDR);
}

/* Funciones para establecer el valor de los registros */
void TDC7200_setCONFIG1(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CONFIG1_ADDR, data);
}

void TDC7200_setCONFIG2(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CONFIG2_ADDR, data);
}

void TDC7200_setINT_STATUS(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_INT_STATUS_ADDR, data);
}

void TDC7200_setINT_MASK(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_INT_MASK_ADDR, data);
}

void TDC7200_setCOARSE_CNTR_OVF_H(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_COARSE_CNTR_OVF_H, data);
}

void TDC7200_setCOARSE_CNTR_OVF_L(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_COARSE_CNTR_OVF_L, data);
}

void TDC7200_setCLOCK_CNTR_OVF_H(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CLOCK_CNTR_OVF_H, data);
}

void TDC7200_setCLOCK_CNTR_OVF_L(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CLOCK_CNTR_OVF_L, data);
}

void TDC7200_setCLOCK_CNTR_STOP_MASK_H(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CLOCK_CNTR_STOP_MASK_H, data);
}

void TDC7200_setCLOCK_CNTR_STOP_MASK_L(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CLOCK_CNTR_STOP_MASK_L, data);
}

/* Functions */
void TDC7200_WriteSingleRegister(uint8_t regAddr, uint8_t data){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctrl_S_Write(SLAVE_TDC7200);
    SPI_WriteTxData(TDC7200_WRITE_CMD | regAddr);
    SPI_WriteTxData(data);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    Ctrl_S_Write(SLAVE_DESELECT);
}

void TDC7200_WriteAutoincrementRegister(uint8_t regAddr, uint8_t *data, size_t size){
    static uint8_t i = 0;
    
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctrl_S_Write(SLAVE_TDC7200);
    SPI_WriteTxData(TDC7200_AUTO_INCREMENT | TDC7200_WRITE_CMD | regAddr);
    for(; i < size; i++){
        SPI_WriteTxData(data[i]);
    }
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    Ctrl_S_Write(SLAVE_DESELECT);
}
uint8_t TDC7200_ReadSingleRegister(uint8_t regAddr){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctrl_S_Write(SLAVE_TDC7200);
    SPI_WriteTxData(TDC7200_READ_CMD | regAddr);
    SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    Ctrl_S_Write(SLAVE_DESELECT);
    (void)SPI_ReadRxData(); /* Dummy read */
    return SPI_ReadRxData();
}

uint32_t TDC7200_Read24bitRegister(uint8_t regAddr){
    uint8_t d1, d2, d3;
    
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctrl_S_Write(SLAVE_TDC7200);
    SPI_WriteTxData(TDC7200_READ_CMD | regAddr);
    SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    Ctrl_S_Write(SLAVE_DESELECT);
    (void)SPI_ReadRxData(); /* Dummy read */
    d1 = SPI_ReadRxData();
    d2 = SPI_ReadRxData();
    d3 = SPI_ReadRxData();
    return (d1 << 16) | (d2 << 8) | d3;
}

void TDC7200_ReadAutoincrementRegister(uint8_t regAddr, uint8_t *data, size_t size){
    static uint8_t i = 0, j = 0;

    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctrl_S_Write(SLAVE_TDC7200);
    SPI_WriteTxData(TDC7200_AUTO_INCREMENT | TDC7200_READ_CMD | regAddr);
    for(; i < size; i++){
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    }
    (void)SPI_ReadRxData();
    for(; j < size; j++){
        *(data + j) = SPI_ReadRxData();;
    }
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    Ctrl_S_Write(SLAVE_DESELECT);
}

bool TDC7200_readToggleSetting(uint8_t toggle);
void TDC7200_setToggle(uint8_t toogle);
uint8_t TDC7200_readMode(void);
uint8_t TDC7200_readCalibration2Periods(void);
uint8_t TDC7200_readAvgCycles(void);
uint8_t TCD7200_readNumStop(void);
bool TDC7200_readEnable(void);
void TDC7200_setEnable(bool enable);
void TDC7200_setClockFreqIn(uint32_t freq);
uint8_t TDC7200_readCalibrationPeriods(void);
double TDC7200_readToF(void);
void TDC7200_forceMeasurementRead(void);

/* [] END OF FILE */
