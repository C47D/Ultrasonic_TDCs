/******************************************************************************  
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#include <project.h>
#include "TDC7200_Regs.h"
#include "TDC7200_Funcs.h"

#include "stdbool.h"

#define EN_7200_POS     0
#define CH_SEL_POS      3
#define SS_7200_POS     5

#define SET_PIN(INDEX)      (Ctrl_Control = Ctrl_Control | (1 << INDEX))
#define CLEAR_PIN(INDEX)    (Ctrl_Control = Ctrl_Control & ~(1 << INDEX))

void TDC7200_Start(TDC7200_INIT_t* tdc){
    TDC7200_setConfig(tdc, true);
    TDC7200_Enable();
}

void TDC7200_Enable(void){
    /* El pin EN del TDC7200 debe estar a 1 lógico para poder usarlo*/
    SET_PIN(EN_7200_POS);
}

void TDC7200_setConfig(TDC7200_INIT_t* tdc, bool continuous){
    SPI_ClearFIFO();
    CLEAR_PIN(SS_7200_POS);
    if(continuous == true){
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_CONFIG1_ADDR);
        SPI_WriteTxData((tdc->CONFIG1 & TDC7200_CONFIG1_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_CONFIG2_ADDR);
        SPI_WriteTxData((tdc->CONFIG2 & TDC7200_CONFIG2_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_INT_STATUS_ADDR);
        SPI_WriteTxData((tdc->INT_STATUS & TDC7200_INT_STATUS_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_INT_MASK_ADDR);
        SPI_WriteTxData((tdc->INT_MASK & TDC7200_INT_MASK_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_COARSE_CNTR_OVF_H_ADDR);
        SPI_WriteTxData((tdc->COARSE_CNTR_OVF_H & TDC7200_COARSE_CNTR_OVF_H_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_COARSE_CNTR_OVF_L_ADDR);
        SPI_WriteTxData((tdc->COARSE_CNTR_OVF_L & TDC7200_COARSE_CNTR_OVF_L_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_CLOCK_CNTR_OVF_H_ADDR);
        SPI_WriteTxData((tdc->CLOCK_CNTR_OVF_H & TDC7200_CLOCK_CNTR_OVF_H_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_CLOCK_CNTR_OVF_L_ADDR);
        SPI_WriteTxData((tdc->CLOCK_CNTR_OVF_L & TDC7200_CLOCK_CNTR_OVF_L_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_CLOCK_CNTR_STOP_MASK_H_ADDR);
        SPI_WriteTxData((tdc->CLOCK_CNTR_STOP_MASK_H & TDC7200_CLOCK_CNTR_STOP_MASK_H_MASK));
        SPI_WriteTxData(TDC7200_WRITE_CMD | TDC7200_CLOCK_CNTR_STOP_MASK_L_ADDR);
        SPI_WriteTxData((tdc->CLOCK_CNTR_STOP_MASK_L & TDC7200_CLOCK_CNTR_STOP_MASK_L_MASK));
    }else{
        TDC7200_setCONFIG1((tdc->CONFIG1 & TDC7200_CONFIG1_MASK));
        TDC7200_setCONFIG2((tdc->CONFIG2 & TDC7200_CONFIG2_MASK));
        TDC7200_setINT_STATUS((tdc->INT_STATUS & TDC7200_INT_STATUS_MASK));
        TDC7200_setINT_MASK((tdc->INT_MASK & TDC7200_INT_MASK_MASK));
        TDC7200_setCOARSE_CNTR_OVF_H((tdc->COARSE_CNTR_OVF_H & TDC7200_COARSE_CNTR_OVF_H_MASK));
        TDC7200_setCOARSE_CNTR_OVF_L((tdc->COARSE_CNTR_OVF_L & TDC7200_COARSE_CNTR_OVF_L_MASK));
        TDC7200_setCLOCK_CNTR_OVF_H((tdc->CLOCK_CNTR_OVF_H & TDC7200_CLOCK_CNTR_OVF_H_MASK));
        TDC7200_setCLOCK_CNTR_OVF_L((tdc->CLOCK_CNTR_OVF_L & TDC7200_CLOCK_CNTR_OVF_L_MASK));
        TDC7200_setCLOCK_CNTR_STOP_MASK_H((tdc->CLOCK_CNTR_STOP_MASK_H & TDC7200_CLOCK_CNTR_STOP_MASK_H_MASK));
        TDC7200_setCLOCK_CNTR_STOP_MASK_L((tdc->CLOCK_CNTR_STOP_MASK_L & TDC7200_CLOCK_CNTR_STOP_MASK_L_MASK));
    }
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(SS_7200_POS);
}

void TDC7200_getConfig(TDC7200_INIT_t* tdc, bool continuous){
    SPI_ClearFIFO();
    CLEAR_PIN(SS_7200_POS);
    if(continuous == true){
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_CONFIG1_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CONFIG1 = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_CONFIG2_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CONFIG2 = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_INT_STATUS_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->INT_STATUS = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_INT_MASK_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->INT_MASK = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_COARSE_CNTR_OVF_H_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->COARSE_CNTR_OVF_H = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_COARSE_CNTR_OVF_L_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->COARSE_CNTR_OVF_L = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_CLOCK_CNTR_OVF_H_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CLOCK_CNTR_OVF_H = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_CLOCK_CNTR_OVF_L_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CLOCK_CNTR_OVF_L = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_CLOCK_CNTR_STOP_MASK_H_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CLOCK_CNTR_STOP_MASK_H = SPI_ReadRxData();
        SPI_WriteTxData(TDC7200_READ_CMD | TDC7200_CLOCK_CNTR_STOP_MASK_L_ADDR);
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CLOCK_CNTR_STOP_MASK_L = SPI_ReadRxData();
    }else{
        tdc->CONFIG1 = TDC7200_getCONFIG1();
        tdc->CONFIG2 = TDC7200_getCONFIG2();
        tdc->INT_STATUS = TDC7200_getINT_STATUS();
        tdc->INT_MASK = TDC7200_getINT_MASK();
        tdc->COARSE_CNTR_OVF_H = TDC7200_getCOARSE_CNTR_OVF_H();
        tdc->COARSE_CNTR_OVF_L = TDC7200_getCOARSE_CNTR_OVF_L();
        tdc->CLOCK_CNTR_OVF_H = TDC7200_getCLOCK_CNTR_OVF_H();
        tdc->CLOCK_CNTR_OVF_L = TDC7200_getCLOCK_CNTR_OVF_L();
        tdc->CLOCK_CNTR_STOP_MASK_H = TDC7200_getCLOCK_CNTR_STOP_MASK_H();
        tdc->CLOCK_CNTR_STOP_MASK_L = TDC7200_getCLOCK_CNTR_STOP_MASK_L();
    }
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(SS_7200_POS);
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
    return TDC7200_ReadSingleRegister(TDC7200_COARSE_CNTR_OVF_H_ADDR);
}

uint8_t TDC7200_getCOARSE_CNTR_OVF_L(void){
    return TDC7200_ReadSingleRegister(TDC7200_COARSE_CNTR_OVF_L_ADDR);
}

uint8_t TDC7200_getCLOCK_CNTR_OVF_H(void){
    return TDC7200_ReadSingleRegister(TDC7200_CLOCK_CNTR_OVF_H_ADDR);
}

uint8_t TDC7200_getCLOCK_CNTR_OVF_L(void){
    return TDC7200_ReadSingleRegister(TDC7200_CLOCK_CNTR_OVF_L_ADDR);
}

uint8_t TDC7200_getCLOCK_CNTR_STOP_MASK_H(void){
    return TDC7200_ReadSingleRegister(TDC7200_CLOCK_CNTR_STOP_MASK_H_ADDR);
}

uint8_t TDC7200_getCLOCK_CNTR_STOP_MASK_L(void){
    return TDC7200_ReadSingleRegister(TDC7200_CLOCK_CNTR_STOP_MASK_L_ADDR);
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
    TDC7200_WriteSingleRegister(TDC7200_COARSE_CNTR_OVF_H_ADDR, data);
}

void TDC7200_setCOARSE_CNTR_OVF_L(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_COARSE_CNTR_OVF_L_ADDR, data);
}

void TDC7200_setCLOCK_CNTR_OVF_H(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CLOCK_CNTR_OVF_H_ADDR, data);
}

void TDC7200_setCLOCK_CNTR_OVF_L(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CLOCK_CNTR_OVF_L_ADDR, data);
}

void TDC7200_setCLOCK_CNTR_STOP_MASK_H(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CLOCK_CNTR_STOP_MASK_H_ADDR, data);
}

void TDC7200_setCLOCK_CNTR_STOP_MASK_L(uint8_t data){
    TDC7200_WriteSingleRegister(TDC7200_CLOCK_CNTR_STOP_MASK_L_ADDR, data);
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

/* Low Level Functions */
void TDC7200_WriteSingleRegister(uint8_t regAddr, uint8_t data){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    CLEAR_PIN(SS_7200_POS);
    SPI_WriteTxData(TDC7200_WRITE_CMD | regAddr);
    SPI_WriteTxData(data);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(SS_7200_POS);
}

void TDC7200_WriteAutoincrementRegister(uint8_t regAddr, uint8_t *data, size_t size){
    static uint8_t i = 0;

    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    CLEAR_PIN(SS_7200_POS);
    SPI_WriteTxData(TDC7200_AUTO_INCREMENT | TDC7200_WRITE_CMD | regAddr);
    for(; i < size; i++){
        SPI_WriteTxData(data[i]);
    }
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(SS_7200_POS);
}

uint8_t TDC7200_ReadSingleRegister(uint8_t regAddr){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    CLEAR_PIN(SS_7200_POS);
    SPI_WriteTxData(TDC7200_READ_CMD | regAddr);
    SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(SS_7200_POS);
    (void)SPI_ReadRxData(); /* Dummy read */
    return SPI_ReadRxData();
}

uint32_t TDC7200_Read24bitRegister(uint32_t regAddr){
    uint8_t d1, d2, d3;

    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    CLEAR_PIN(SS_7200_POS);
    SPI_WriteTxData(TDC7200_READ_CMD | regAddr);
    SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(SS_7200_POS);
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
    CLEAR_PIN(SS_7200_POS);
    SPI_WriteTxData(TDC7200_AUTO_INCREMENT | TDC7200_READ_CMD | regAddr);
    for(; i < size; i++){
        SPI_WriteTxData(TDC7200_DUMMY_BYTE);
    }
    (void)SPI_ReadRxData();
    for(; j < size; j++){
        *(data + j) = SPI_ReadRxData();;
    }
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(SS_7200_POS);
}

/* [] END OF FILE */
