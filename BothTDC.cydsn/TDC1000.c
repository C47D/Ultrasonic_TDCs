#include <project.h>
#include "TDC1000.h"

#define SLAVE_TDC1000 0x02
#define SLAVE_DESELECT 0x03

/*
Error reporting:
El TDC1000 reportara un error cuando las señales recividas no
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
void TDC1000_Start(TDC1000_INIT_t tdc){
    Ctrl_Write(0x02); // TDC1000 Enable pin set to 1
}

void TDC1000_setCONFIG_0(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_0_ADDR, data);
}

void TDC1000_setCONFIG_1(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_1_ADDR, data);
}

void TDC1000_setCONFIG_2(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_2_ADDR, data);
}

void TDC1000_setCONFIG_3(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_3_ADDR, data);
}

void TDC1000_setCONFIG_4(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CONFIG_4_ADDR, data);
}

void TDC1000_setTOF_1(uint8_t data){    
    TDC1000_WriteSingleRegister(TDC1000_TOF_1_ADDR, data);
}

void TDC1000_setTOF_0(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_TOF_0_ADDR, data);
}

void TDC1000_setERROR_FLAGS(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_ERROR_FLAGS_ADDR, data);
}

void TDC1000_setTIMEOUT(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_TIMEOUT_ADDR, data);
}

void TDC1000_setCLOCK_RATE(uint8_t data){
    TDC1000_WriteSingleRegister(TDC1000_CLOCK_RATE_ADDR, data);
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
    static uint8_t i;
    i = Ctrl_Read();
    if(enable){
        i |= (0x02);
        Ctrl_Write(i);
    }else{
        i &= ~(0x02);
        Ctrl_Write(i);
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

void TDC1000_reset(void){
    Ctrl_Write(Ctrl_Read() | 0x04);
    CyDelayUs(100);
    Ctrl_Write(Ctrl_Read() & ~(0x04));
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
    Ctrl_S_Write(SLAVE_TDC1000);
    SPI_WriteTxData(TDC1000_WRITE_CMD | regAddr);
    SPI_WriteTxData(data);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    Ctrl_S_Write(SLAVE_DESELECT);
}

uint8_t TDC1000_ReadSingleRegister(uint8_t regAddr){
    SPI_ClearRxBuffer();
    SPI_ClearTxBuffer();
    Ctrl_S_Write(SLAVE_TDC1000);
    SPI_WriteTxData(TDC1000_READ_CMD | regAddr);
    SPI_WriteTxData(TDC1000_DUMMY_BYTE);
    while(!(SPI_TX_STATUS_REG & SPI_STS_SPI_DONE));
    Ctrl_S_Write(SLAVE_DESELECT);
    (void)SPI_ReadRxData(); // Dummy read
    return SPI_ReadRxData();
}

/* [] END OF FILE */
