#include <project.h>
#include "TDC7200.h"

/* Functions */
void WriteSingleRegister(uint8_t regAddr, uint8_t data);
void WriteAutoincrementRegister(uint8_t regAddr, uint8_t *data, uint8_t size);
void ReadSingleRegister(uint8_t regAddr, uint8_t *data);
void ReadAutoincrementRegister(uint8_t regAddr, uint8_t *data, uint8_t size);

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
