#include <project.h>
#include <stdbool.h>

#include "TDC1000_Regs.h"
#include "TDC1000_Funcs.h"

#define TDC1000_EN_POS      1
#define TDC1000_RST_POS     2
#define TDC1000_CHSEL_POS   3
#define TDC1000_nSS_POS     4
#define TDC1000_TRGG_POS    6

#define SET_PIN(INDEX)      (Ctrl_Control = Ctrl_Control | (1 << INDEX))
#define CLEAR_PIN(INDEX)    (Ctrl_Control = Ctrl_Control & ~(1 << INDEX))
#define TOGGLE_PIN(INDEX)   do{SET_PIN(INDEX); \
                                CyDelay(1); \
                                CLEAR_PIN(INDEX); \
                                }while(0)

/*
Error reporting:
El TDC1000 reportara un error cuando las señales recibidas no
sean las que esperaba dada su configuracion.
El pin ERRB se pondrá en estado bajo para indicar la presencia
de una condicion de error.
Leer el registro ERROR_FLAGS proveera informacion acerca de la
condicion que ocaciono el error.
Bit             Condicion de error
ERR_SIG_WEAK    El numero de zero-crossing es menor al número esperado,
                configurado en el registro NUM_RX y ocurrio un timeout.
                El error se borra cuando el bit0 es escrito con un 1

ERR_NO_SIG      Indica que no se recibieron señales y ocurrio un timeout
                Escribiendo un 1 en este bit reinicia la maquina de estados,
                detiene las mediciones activas y retorna el dispositivo a los modos
                SLEEP o READY y reinicia el contador de promedios y automatic channel
                selection en mediciones modo2.
                El error se limpia escribiendo el bit0 con un 1

ERR_SIG_HIGH    Indica que la amplitud del eco excede el threshold de eco mas grande
                en la entrada de los comparadores. solo se reporta cuando el registro 
                ECHO_QUAL_THDL esta configurado en 0x07.

NOTA: Es recomendable resetear la maquina de estados cuando los flags de los erroes son limpiadas
Esto puede hacerse simultaneamente escribiendo el valor 0x03 al registro ERROR_FLAGS
*/

/* Functions */
void TDC1000_Start(TDC1000_INIT_t* tdc){
    TDC1000_setConfig(tdc, true);
    TDC1000_Enable();
}

void TDC1000_Enable(void){
    SET_PIN(TDC1000_EN_POS);
}

void TDC1000_Trigger(void){
    TOGGLE_PIN(TDC1000_TRGG_POS);
}

void TDC1000_setConfig(TDC1000_INIT_t* tdc, bool continuous){
    SPI_ClearFIFO();
    CLEAR_PIN(TDC1000_nSS_POS);
    if(continuous == true){
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_CONFIG_0_ADDR);
        SPI_WriteTxData((tdc->CONFIG_0 & TDC1000_CONFIG_0_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_CONFIG_1_ADDR);
        SPI_WriteTxData((tdc->CONFIG_1 & TDC1000_CONFIG_1_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_CONFIG_2_ADDR);
        SPI_WriteTxData((tdc->CONFIG_2 & TDC1000_CONFIG_2_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_CONFIG_3_ADDR);
        SPI_WriteTxData((tdc->CONFIG_3 & TDC1000_CONFIG_3_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_CONFIG_4_ADDR);
        SPI_WriteTxData((tdc->CONFIG_4 & TDC1000_CONFIG_4_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_TOF_0_ADDR);
        SPI_WriteTxData((tdc->TOF_0 & TDC1000_TOF_0_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_TOF_1_ADDR);
        SPI_WriteTxData((tdc->TOF_1 & TDC1000_TOF_1_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_ERROR_FLAGS_ADDR);
        SPI_WriteTxData((tdc->ERROR_FLAGS & TDC1000_ERROR_FLAGS_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_TIMEOUT_ADDR);
        SPI_WriteTxData((tdc->TIMEOUT & TDC1000_TIMEOUT_MASK));
        SPI_WriteTxData(TDC1000_WRITE_CMD | TDC1000_CLOCK_RATE_ADDR);
        SPI_WriteTxData((tdc->CLOCK_RATE & TDC1000_CLOCK_RATE_MASK));
        while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    }else{
        TDC1000_setCONFIG_0((tdc->CONFIG_0 & TDC1000_CONFIG_0_MASK));
        TDC1000_setCONFIG_1((tdc->CONFIG_1 & TDC1000_CONFIG_1_MASK));
        TDC1000_setCONFIG_2((tdc->CONFIG_2 & TDC1000_CONFIG_2_MASK));
        TDC1000_setCONFIG_3((tdc->CONFIG_3 & TDC1000_CONFIG_3_MASK));
        TDC1000_setCONFIG_4((tdc->CONFIG_4 & TDC1000_CONFIG_4_MASK));
        TDC1000_setTOF_1((tdc->TOF_1 & TDC1000_TOF_1_MASK));
        TDC1000_setTOF_0((tdc->TOF_0 & TDC1000_TOF_0_MASK));
        TDC1000_setERROR_FLAGS((tdc->ERROR_FLAGS & TDC1000_ERROR_FLAGS_MASK));
        TDC1000_setTIMEOUT((tdc->TIMEOUT & TDC1000_TIMEOUT_MASK));
        TDC1000_setCLOCK_RATE((tdc->CLOCK_RATE & TDC1000_CLOCK_RATE_MASK));
    }
    SET_PIN(TDC1000_nSS_POS);
}

void TDC1000_getConfig(TDC1000_INIT_t* tdc, bool continuous){
    SPI_ClearFIFO();
    CLEAR_PIN(TDC1000_nSS_POS);
    if(continuous == true){
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_CONFIG_0_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_CONFIG_1_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_CONFIG_2_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_CONFIG_3_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_CONFIG_4_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_TOF_0_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_TOF_1_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_ERROR_FLAGS_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_TIMEOUT_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);        
        SPI_WriteTxData(TDC1000_READ_CMD | TDC1000_CLOCK_RATE_ADDR);
        SPI_WriteTxData(TDC1000_DUMMY_BYTE);
        while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
        tdc->CLOCK_RATE = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->TIMEOUT = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->ERROR_FLAGS = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->TOF_1 = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->TOF_0 = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CONFIG_4 = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CONFIG_3 = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CONFIG_2 = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CONFIG_1 = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
        tdc->CONFIG_0 = SPI_ReadRxData();
        (void)SPI_ReadRxData(); // Dummy read
    }else{
        tdc->CONFIG_0 = TDC1000_getCONFIG_0();
        tdc->CONFIG_1 = TDC1000_getCONFIG_1();
        tdc->CONFIG_2 = TDC1000_getCONFIG_2();
        tdc->CONFIG_3 = TDC1000_getCONFIG_3();
        tdc->CONFIG_4 = TDC1000_getCONFIG_4();
        tdc->TOF_1 = TDC1000_getTOF_1();
        tdc->TOF_0 = TDC1000_getTOF_0();
        tdc->ERROR_FLAGS = TDC1000_getERROR_FLAGS();
        tdc->TIMEOUT = TDC1000_getTIMEOUT();
        tdc->CLOCK_RATE = TDC1000_getCLOCK_RATE();
    }
    SET_PIN(TDC1000_nSS_POS);
}

void TDC1000_setCONFIG_0(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_0_ADDR, (data & TDC1000_CONFIG_0_MASK));
}

void TDC1000_setCONFIG_1(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_1_ADDR, (data & TDC1000_CONFIG_1_MASK));
}

void TDC1000_setCONFIG_2(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_2_ADDR, (data & TDC1000_CONFIG_2_MASK));
}

void TDC1000_setCONFIG_3(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_3_ADDR, (data & TDC1000_CONFIG_3_MASK));
}

void TDC1000_setCONFIG_4(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_4_ADDR, (data & TDC1000_CONFIG_4_MASK));
}

void TDC1000_setTOF_1(uint8_t data){    
    TDC1000_WriteSingleRegister(TDC1000_TOF_1_ADDR, (data & TDC1000_TOF_1_MASK));
}

void TDC1000_setTOF_0(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_TOF_0_ADDR, (data & TDC1000_TOF_0_MASK));
}

void TDC1000_setERROR_FLAGS(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_ERROR_FLAGS_ADDR, (data & TDC1000_ERROR_FLAGS_MASK));
}

void TDC1000_setTIMEOUT(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_TIMEOUT_ADDR, (data & TDC1000_TIMEOUT_MASK));
}

void TDC1000_setCLOCK_RATE(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CLOCK_RATE_ADDR, (data & TDC1000_CLOCK_RATE_MASK));
}

uint8_t TDC1000_getCONFIG_0(void){
    return TDC1000_ReadSingleRegister(TDC1000_CONFIG_0_ADDR);
}

uint8_t TDC1000_getCONFIG_1(void){
    return TDC1000_ReadSingleRegister(TDC1000_CONFIG_1_ADDR);
}

uint8_t TDC1000_getCONFIG_2(void){
    return TDC1000_ReadSingleRegister(TDC1000_CONFIG_2_ADDR);
}

uint8_t TDC1000_getCONFIG_3(void){
    return TDC1000_ReadSingleRegister(TDC1000_CONFIG_3_ADDR);
}

uint8_t TDC1000_getCONFIG_4(void){
    return TDC1000_ReadSingleRegister(TDC1000_CONFIG_4_ADDR);
}

uint8_t TDC1000_getTOF_1(void){
    return TDC1000_ReadSingleRegister(TDC1000_TOF_1_ADDR);
}

uint8_t TDC1000_getTOF_0(void){
    return TDC1000_ReadSingleRegister(TDC1000_TOF_0_ADDR);
}

uint8_t TDC1000_getERROR_FLAGS(void){
    return TDC1000_ReadSingleRegister(TDC1000_ERROR_FLAGS_ADDR);
}

uint8_t TDC1000_getTIMEOUT(void){
    return TDC1000_ReadSingleRegister(TDC1000_TIMEOUT_ADDR);
}

uint8_t TDC1000_getCLOCK_RATE(void){
    return TDC1000_ReadSingleRegister(TDC1000_CLOCK_RATE_ADDR);
}

uint8_t TDC1000_readModeSelect(void){
    return 0x00;
}

uint8_t TDC1000_readTXFreqDiv(void){
    return 0x00;
}

uint8_t TDC1000_readNumTX(void){
    return 0x00;
}

uint8_t TDC1000_readNumAvg(void){
    return 0x00;
}

uint8_t TDC1000_readNumRX(void){
    return 0x00;
}

uint8_t TDC1000_readEchoQualThld(void){
    return 0x00;
}

uint8_t TDC1000_readTXPhShiftPos(void){
    return 0x00;
}

uint8_t TDC1000_readPGAGain(void){
    return 0x00;
}

uint8_t TDC1000_readTimingReg(void){
    return 0x00;
}

uint8_t TDC1000_readShortToFBlankPeriod(void){
    return 0x00;
}

uint8_t TDC1000_readToFTimeoutCtrl(void){
    return 0x00;
}

uint8_t TDC1000_readAutozeroPeriod(void){
    return 0x00;
}

void TDC1000_setEnable(bool enable){
    if(true == enable){
        SET_PIN(TDC1000_EN_POS);
    }else{
        CLEAR_PIN(TDC1000_EN_POS);
    }
}

bool TDC1000_getEnable(void){
    static uint8_t i;
    i = Ctrl_Read();
    if(0x02 && i){
        return true;
    }else{
        return false;
    }
}

void TDC1000_Reset(void){
    SET_PIN(TDC1000_RST_POS);
    CyDelayUs(50);
    CLEAR_PIN(TDC1000_RST_POS);
}

bool TDC1000_readChannelSelect(void){
    static uint8_t i;
    i = Ctrl_Read();
    if(0x04 && i){
        return true;
    }else{
        return false;
    }
}

uint8_t TDC1000_readClockFreqIn(void){
    return 0x00;
}

void TDC1000_setClockFreqIn(uint32_t freq){
    freq = 0;
}

/* Funciones primitivas */
void TDC1000_WriteSingleRegister(uint8_t regAddr, uint8_t data){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    CLEAR_PIN(TDC1000_nSS_POS);
    SPI_WriteTxData(TDC1000_WRITE_CMD | regAddr);
    SPI_WriteTxData(data);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(TDC1000_nSS_POS);
}

uint8_t TDC1000_ReadSingleRegister(uint8_t regAddr){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    CLEAR_PIN(TDC1000_nSS_POS);
    SPI_WriteTxData(TDC1000_READ_CMD | regAddr);
    SPI_WriteTxData(TDC1000_DUMMY_BYTE);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    SET_PIN(TDC1000_nSS_POS);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

/* [] END OF FILE */
