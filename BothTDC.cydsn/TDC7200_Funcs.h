/*
 * @file TDC7200.h
 * @author Carlos Diaz
 * @version v0_1
 * @date 2016
 * @brief Este archivo contiene todos los prototipos
 * de las funciones para el driver del TDC TDC7200
*/

#ifndef TDC7200_H
#define TDC7200_H

#ifdef __cplusplus
 extern "C"
{
#endif

/* External includes  */
#include <cytypes.h>
#include <stdbool.h>
#include <stdlib.h>

#define TDC7200_AUTO_INCREMENT  (0x01 << 7)
#define TDC7200_READ_CMD        (0x00 << 6)
#define TDC7200_WRITE_CMD       (0x01 << 6)
#define TDC7200_DUMMY_BYTE      0x00

typedef enum{
    CONFIG_1 = 0x00,
    CONFIG_2 = 0x01,
    INT_STATUS = 0x02,
    INT_MASK = 0x03,
    COARSE_CNTR_OVF_H = 0x04,
    COARSE_CNTR_OVF_L = 0x05,
    CLOCK_CNTR_OVF_H = 0x06,
    CLOCK_CNTR_OVF_L = 0x07,
    CLOCK_CNTR_STOP_MASK_H = 0x08,
    CLOCK_CNTR_STOP_MASK_L = 0x09
}TDC7200_REG_t;

typedef struct{
    uint8_t CONFIG1;
    uint8_t CONFIG2;
    uint8_t INT_STATUS;
    uint8_t INT_MASK;
    uint8_t COARSE_CNTR_OVF_H;
    uint8_t COARSE_CNTR_OVF_L;
    uint8_t CLOCK_CNTR_OVF_H;
    uint8_t CLOCK_CNTR_OVF_L;
    uint8_t CLOCK_CNTR_STOP_MASK_H;
    uint8_t CLOCK_CNTR_STOP_MASK_L;
}TDC7200_INIT_t;

/* Funciones especiales, diseñadas para ser las unicas usadas por el usuario */
void TDC7200_Start(TDC7200_INIT_t* tdc);
void TDC7200_setConfig(TDC7200_INIT_t* tdc, bool continuous);
void TDC7200_getConfig(TDC7200_INIT_t* tdc, bool continuous);
void TDC7200_Enable(void);

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

/* Funciones para establecer el valor de los registros */
void TDC7200_setCONFIG1(uint8_t data);
void TDC7200_setCONFIG2(uint8_t data);
void TDC7200_setINT_STATUS(uint8_t data);
void TDC7200_setINT_MASK(uint8_t data);
void TDC7200_setCOARSE_CNTR_OVF_H(uint8_t data);
void TDC7200_setCOARSE_CNTR_OVF_L(uint8_t data);
void TDC7200_setCLOCK_CNTR_OVF_H(uint8_t data);
void TDC7200_setCLOCK_CNTR_OVF_L(uint8_t data);
void TDC7200_setCLOCK_CNTR_STOP_MASK_H(uint8_t data);
void TDC7200_setCLOCK_CNTR_STOP_MASK_L(uint8_t data);

/* Funciones para obtener el valor de los registros */
uint8_t TDC7200_getCONFIG1(void);
uint8_t TDC7200_getCONFIG2(void);
uint8_t TDC7200_getINT_STATUS(void);
uint8_t TDC7200_getINT_MASK(void);
uint8_t TDC7200_getCOARSE_CNTR_OVF_H(void);
uint8_t TDC7200_getCOARSE_CNTR_OVF_L(void);
uint8_t TDC7200_getCLOCK_CNTR_OVF_H(void);
uint8_t TDC7200_getCLOCK_CNTR_OVF_L(void);
uint8_t TDC7200_getCLOCK_CNTR_STOP_MASK_H(void);
uint8_t TDC7200_getCLOCK_CNTR_STOP_MASK_L(void);

/* Los siguientes registros tienen un tamaño de 24 bites */
uint32_t TDC7200_getTIME1(void);
uint32_t TDC7200_getCLOCK_COUNT1(void);
uint32_t TDC7200_getTIME2(void);
uint32_t TDC7200_getCLOCK_COUNT2(void);
uint32_t TDC7200_getTIME3(void);
uint32_t TDC7200_getCLOCK_COUNT3(void);
uint32_t TDC7200_getTIME4(void);
uint32_t TDC7200_getCLOCK_COUNT4(void);
uint32_t TDC7200_getTIME5(void);
uint32_t TDC7200_getCLOCK_COUNT5(void);
uint32_t TDC7200_getTIME6(void);
uint32_t TDC7200_getCALIBRATION1(void);
uint32_t TDC7200_getCALIBRATION2(void);

/* Funciones generales */
void TDC7200_WriteSingleRegister(uint8_t regAddr, uint8_t data);
void TDC7200_WriteAutoincrementRegister(uint8_t regAddr, uint8_t *data, size_t size);
uint8_t TDC7200_ReadSingleRegister(uint8_t regAddr);
uint32_t TDC7200_Read24bitRegister(uint32_t regAddr);
void TDC7200_ReadAutoincrementRegister(uint8_t regAddr, uint8_t *data, size_t size);


#ifdef __cplusplus
}
#endif

#endif	/* TDC7200_H  */

/* End of file  */
