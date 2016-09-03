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

/***** Register addresses *****/
#define TDC7200_CONFIG1_ADDR            0x00u
#define TDC7200_CONFIG2_ADDR            0x01u
#define TDC7200_INT_STATUS_ADDR         0x02u
#define TDC7200_INT_MASK_ADDR           0x03u
#define TDC7200_COARSE_CNTR_OVF_H       0x04u
#define TDC7200_COARSE_CNTR_OVF_L       0x05u
#define TDC7200_CLOCK_CNTR_OVF_H        0x06u
#define TDC7200_CLOCK_CNTR_OVF_L        0x07u
#define TDC7200_CLOCK_CNTR_STOP_MASK_H  0x08u
#define TDC7200_CLOCK_CNTR_STOP_MASK_L  0x09u
#define TDC7200_TIME1_ADDR              0x10u // Solo lectura
#define TDC7200_CLOCK_COUNT1_ADDR       0x11u // Solo lectura
#define TDC7200_TIME2_ADDR              0x12u // Solo lectura
#define TDC7200_CLOCK_COUNT2_ADDR       0x13u // Solo lectura
#define TDC7200_TIME3_ADDR              0x14u // Solo lectura
#define TDC7200_CLOCK_COUNT3_ADDR       0x15u // Solo lectura
#define TDC7200_TIME4_ADDR              0x16u // Solo lectura
#define TDC7200_CLOCK_COUNT4_ADDR       0x17u // Solo lectura
#define TDC7200_TIME5_ADDR              0x18u // Solo lectura
#define TDC7200_CLOCK_COUNT5_ADDR       0x19u // Solo lectura
#define TDC7200_TIME6_ADDR              0x1Au // Solo lectura
#define TDC7200_CALIBRATION1_ADDR       0x1Bu // Solo lectura
#define TDC7200_CALIBRATION2_ADDR       0x1Cu // Solo lectura

/***** CONFIG1 Register *****/

/* Start new measurement */
#define TDC7200_CONFIG1_START_MEAS 0x01 /* Writing 1 will clear all bits in the interrupt status register */
/* Measurement mode */
#define TDC7200_CONFIG1_MEAS_MODE_Pos 1
#define TDC7200_CONFIG1_MEAS_MODE_MODE1 ((uint32_t)0x00 << TDC7200_CONFIG1_MEAS_MODE_Pos)
#define TDC7200_CONFIG1_MEAS_MODE_MODE2 ((uint32_t)0x01 << TDC7200_CONFIG1_MEAS_MODE_Pos)
/* Start a new measurement at given Start signal edge */
#define TDC7200_CONFIG1_START_EDGE_Pos 3
#define TDC7200_CONFIG1_START_EDGE_RISING_EDGE ((uint32_t)0x00 << TDC7200_CONFIG1_START_EDGE_Pos)
#define TDC7200_CONFIG1_START_EDGE_FALLING_EDGE ((uint32_t)0x01 << TDC7200_CONFIG1_START_EDGE_Pos)
/* Stop the measurement at given Stop signal edge */
#define TDC7200_CONFIG1_STOP_EDGE_Pos 4
#define TDC7200_CONFIG1_STOP_EDGE_RISING_EDGE ((uint32_t)0x00 << TDC7200_CONFIG1_STOP_EDGE_Pos)
#define TDC7200_CONFIG1_STOP_EDGE_FALLING_EDGE ((uint32_t)0x01 << TDC7200_CONFIG1_STOP_EDGE_Pos)
/* TRIGG is output as a edge signal */
#define TDC7200_CONFIG1_TRIGG_EDGE_Pos 5
#define TDC7200_CONFIG1_TRIGG_EDGE_RISING_EDGE ((uint32_t)0x00 << TDC7200_CONFIG1_TRIGG_EDGE_Pos)
#define TDC7200_CONFIG1_TRIGG_EDGE_FALLING_EDGE ((uint32_t)0x01 << TDC7200_CONFIG1_TRIGG_EDGE_Pos)
/* Parity bit for Measurement Result Registers */
#define TDC7200_CONFIG1_PARITY_EN_Pos 6
#define TDC7200_CONFIG1_PARITY_EN_DISABLED ((uint32_t)0x00 << TDC7200_CONFIG1_PARITY_EN_Pos)
#define TDC7200_CONFIG1_PARITY_EN_ENABLED ((uint32_t)0x01 << TDC7200_CONFIG1_PARITY_EN_Pos)
/* Calibration at an interrupted measurement */
#define TDC7200_CONFIG1_FORCE_CAL_Pos 7
#define TDC7200_CONFIG1_FORCE_CAL_DISABLED ((uint32_t)0x00 << TDC7200_CONFIG1_FORCE_CAL_Pos)
#define TDC7200_CONFIG1_FORCE_CAL_ENABLED ((uint32_t)0x01 << TDC7200_CONFIG1_FORCE_CAL_Pos)

/* CONFIG2 Register */
#define TDC7200_CONFIG2_NUM_STOP_SINGLE_STOP    0x00
#define TDC7200_CONFIG2_NUM_STOP_TWO_STOPS      0x01
#define TDC7200_CONFIG2_NUM_STOP_THREE_STOPS    0x02
#define TDC7200_CONFIG2_NUM_STOP_FOUR_STOPS     0x03
#define TDC7200_CONFIG2_NUM_STOP_FIVE_STOPS     0x04
#define TDC7200_CONFIG2_AVG_CYCLES_Pos 3
#define TDC7200_CONFIG2_AVG_CYCLES_1_CYCLES     ((uint32_t)0x00 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_2_CYCLES     ((uint32_t)0x01 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_4_CYCLES     ((uint32_t)0x02 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_8_CYCLES     ((uint32_t)0x03 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_16_CYCLES    ((uint32_t)0x04 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_32_CYCLES    ((uint32_t)0x05 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_64_CYCLES    ((uint32_t)0x06 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_128_CYCLES   ((uint32_t)0x07 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos 6
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_2_CLOCKS   ((uint32_t)0x00 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_10_CLOCKS  ((uint32_t)0x01 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_20_CLOCKS  ((uint32_t)0x02 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_40_CLOCKS  ((uint32_t)0x03 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)

/***** INT_STATUS Register *****/
/* Requires writing a 1 to clear interrupt status */
#define TDC7200_INT_STATUS_NEW_MEAS_INT_NOT_DETECTED 0x00
#define TDC7200_INT_STATUS_NEW_MEAS_INT_DETECTED     0x01
/* Requires writing a 1 to clear interrupt status */
#define TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_Pos 1
#define TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_NO_OVERFLOW          ((uint32_t)0x00 << TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_Pos)
#define TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_OVERFLOW_DETECTED    ((uint32_t)0x01 << TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_Pos)
/* Requires writing a 1 to clear interrupt status */
#define TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_Pos 2
#define TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_NO_OVERFLOW       ((uint32_t)0x00 << TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_Pos)
#define TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_OVERFLOW_DETECTED ((uint32_t)0x01 << TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_Pos)
/* Write 1 will clear the status */
#define TDC7200_INT_STATUS_MEAS_STARTED_FLAG_Pos 3
#define TDC7200_INT_STATUS_MEAS_STARTED_FLAG_MEAS_NOT_OCCURED ((uint32_t)0x00 << TDC7200_INT_STATUS_MEAS_STARTED_FLAG_Pos)
#define TDC7200_INT_STATUS_MEAS_STARTED_FLAG_MEAS_COMPLETED   ((uint32_t)0x01 << TDC7200_INT_STATUS_MEAS_STARTED_FLAG_Pos)
/* Write 1 will clear the status */
#define TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_Pos 4
#define TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_NOT_COMPLETED ((uint32_t)0x00 << TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_Pos)
#define TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_COMPLETED     ((uint32_t)0x01 << TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_Pos)

/***** INT_MASK Register *****/
#define TDC7200_INT_MASK_NEW_MEAS_MASK_DISABLED 0x00
#define TDC7200_INT_MASK_NEW_MEAS_MASK_ENABLED  0x01
#define TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_Pos
#define TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_DISABLED  ((uint32_t)0x00 << TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_Pos)
#define TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_ENABLED   ((uint32_t)0x01 << TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_Pos)
#define TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_Pos 2
#define TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_DISABLED   ((uint32_t)0x00 << TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_Pos)
#define TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_ENABLED   ((uint32_t)0x01 << TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_Pos)

#define TDC7200_AUTO_INCREMENT  (0x01 << 7)
//#define TDC7200_AUTO_INCREMENT_OFF  (0x00 << 7)
#define TDC7200_READ_CMD        (0x00 << 6)
#define TDC7200_WRITE_CMD       (0x01 << 6)
#define TDC7200_DUMMY_BYTE      0x00

typedef struct{
    uint8_t CONFIG_1;
    uint8_t CONFIG_2;
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
void TDC7200_setConfig(TDC7200_INIT_t* tdc);
void TDC7200_getConfig(TDC7200_INIT_t* tdc);
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
uint32_t TDC7200_Read24bitRegister(uint8_t regAddr);
void TDC7200_ReadAutoincrementRegister(uint8_t regAddr, uint8_t *data, size_t size);


#ifdef __cplusplus
}
#endif

#endif	/* TDC7200_H  */

/* End of file  */
