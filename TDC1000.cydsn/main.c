#include <project.h>
#include "TDC1000.h"

int main(){

    CyGlobalIntEnable;
    
    SPI_Start();
    
    for(;;){
        TDC1000_setCONFIG_0(0xDE);
        TDC1000_setCONFIG_1(0xAD);
        TDC1000_setCONFIG_2(0xc0);
        TDC1000_setCONFIG_3(0xde);
        TDC1000_setCONFIG_4(0xde);
        TDC1000_setTOF_0(0xc0);
        TDC1000_setTOF_1(0x0f);
        TDC1000_setERROR_FLAGS(0xfe);
        TDC1000_setTIMEOUT(0xba);
        TDC1000_setCLOCK_RATE(0xbe);
        (void)TDC1000_getCONFIG_0();
        (void)TDC1000_getCONFIG_1();
        (void)TDC1000_getCONFIG_2();
        (void)TDC1000_getCONFIG_3();
        (void)TDC1000_getCONFIG_4();
        (void)TDC1000_getTOF_0();
        (void)TDC1000_getTOF_1();
        (void)TDC1000_getERROR_FLAGS();
        (void)TDC1000_getTIMEOUT();
        (void)TDC1000_getCLOCK_RATE();
        
        SPI_ClearRxBuffer();
        SPI_ClearTxBuffer();
        Ctlr_Write(0);
        SPI_WriteTxData(WRITE_CMD | 0x0A);
        SPI_WriteTxData(0xff);
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
        Ctlr_Write(1);
        SPI_ClearRxBuffer();
        SPI_ClearTxBuffer();
        Ctlr_Write(0);
        SPI_WriteTxData(READ_CMD | 0x0A);
        SPI_WriteTxData(DUMMY_BYTE);
        (void)SPI_ReadRxData(); // Dummy read
        (void)SPI_ReadRxData();
        while(!(SPI_ReadTxStatus() & SPI_STS_SPI_IDLE));
        Ctlr_Write(1);
        CyDelayUs(10);
    }
}

/* [] END OF FILE */
