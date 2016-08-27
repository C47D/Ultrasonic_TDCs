#include <project.h>
#include "cyapicallbacks.h"

#include "TDC7200.h"
#include "TDC1000.h"

#define ENABLE_TDC7200 0x01

int main(){

    /* Start UART interface */
    UART_Start();
    /* Start SPI interface */
    SPI_Start();
    /* Start INTB interrupt */
    isr_INTB_Start();
    /* Start ERRB interrupt */
    isr_ERRB_Start();

    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* El pin EN del TDC7200 debe estar a 1 lógico para poder usarlo*/
    Ctrl_Write(ENABLE_TDC7200);

    for(;;){
        TDC1000_getCONFIG_0();
        TDC1000_getCONFIG_1();
        TDC1000_getCONFIG_2();
        TDC1000_getCONFIG_3();
        TDC1000_getCONFIG_4();
        TDC1000_getTOF_1();
        TDC1000_getTOF_0();
        TDC1000_getERROR_FLAGS();
        TDC1000_getTIMEOUT();
        TDC1000_getCLOCK_RATE();
        TDC7200_getCONFIG1();
        TDC7200_getCONFIG2();
        TDC7200_getINT_MASK();
        TDC7200_getINT_STATUS();
        TDC7200_getCOARSE_CNTR_OVF_H();
        TDC7200_getCOARSE_CNTR_OVF_L();
        TDC7200_getCLOCK_CNTR_OVF_H();
        TDC7200_getCLOCK_CNTR_OVF_L();
        TDC7200_getCLOCK_CNTR_STOP_MASK_H();
        TDC7200_getCLOCK_CNTR_STOP_MASK_L();
        /*
        UART_PutString("TDC1000_CONFIG_0: ");
        UART_PutHexByte(TDC1000_getCONFIG_0());
        UART_PutCRLF();
        UART_PutString("TDC1000_CONFIG_1: ");
        UART_PutHexByte(TDC1000_getCONFIG_1());
        UART_PutCRLF();
        UART_PutString("TDC1000_CONFIG_2: ");
        UART_PutHexByte(TDC1000_getCONFIG_2());
        UART_PutCRLF();
        UART_PutString("TDC1000_CONFIG_3: ");
        UART_PutHexByte(TDC1000_getCONFIG_3());
        UART_PutCRLF();
        UART_PutString("TDC1000_CONFIG_4: ");
        UART_PutHexByte(TDC1000_getCONFIG_4());
        UART_PutCRLF();
        UART_PutString("TDC1000_TOF_1: ");
        UART_PutHexByte(TDC1000_getTOF_1());
        UART_PutCRLF();
        UART_PutString("TDC1000_TOF_0: ");
        UART_PutHexByte(TDC1000_getTOF_0());
        UART_PutCRLF();
        UART_PutString("TDC1000_ERROR_FLAGS: ");
        UART_PutHexByte(TDC1000_getERROR_FLAGS());
        UART_PutCRLF();
        UART_PutString("TDC1000_TIMEOUT: ");
        UART_PutHexByte(TDC1000_getTIMEOUT());
        UART_PutCRLF();
        UART_PutString("TDC1000_CLOCK_RATE: ");
        UART_PutHexByte(TDC1000_getCLOCK_RATE());
        UART_PutCRLF();
        UART_PutString("TDC7200_CONFIG1: ");
        UART_PutHexByte(TDC7200_getCONFIG1());
        UART_PutCRLF();
        UART_PutString("TDC7200_CONFIG2: ");
        UART_PutHexByte(TDC7200_getCONFIG2());
        UART_PutCRLF();
        UART_PutString("TDC7200_INT_MASK: ");
        UART_PutHexByte(TDC7200_getINT_MASK());
        UART_PutCRLF();
        UART_PutString("TDC7200_INT_STATUS: ");
        UART_PutHexByte(TDC7200_getINT_STATUS());
        UART_PutCRLF();
        UART_PutString("TDC7200_COARSE_CNTR_OVF_H: ");
        UART_PutHexByte(TDC7200_getCOARSE_CNTR_OVF_H());
        UART_PutCRLF();
        UART_PutString("TDC7200_COARSE_CNTR_OVF_L: ");
        UART_PutHexByte(TDC7200_getCOARSE_CNTR_OVF_L());
        UART_PutCRLF();
        UART_PutString("TDC7200_CLOCK_CNTR_OVF_H: ");
        UART_PutHexByte(TDC7200_getCLOCK_CNTR_OVF_H());
        UART_PutCRLF();
        UART_PutString("TDC7200_CLOCK_CNTR_OVF_L: ");
        UART_PutHexByte(TDC7200_getCLOCK_CNTR_OVF_L());
        UART_PutCRLF();
        UART_PutString("TDC7200_CLOCK_CNTR_STOP_MASK_H: ");
        UART_PutHexByte(TDC7200_getCLOCK_CNTR_STOP_MASK_H());
        UART_PutCRLF();
        UART_PutString("TDC7200_CLOCK_CNTR_STOP_MASK_L: ");
        UART_PutHexByte(TDC7200_getCLOCK_CNTR_STOP_MASK_L());
        UART_PutCRLF();
        */
    }
}

void isr_INTB_Interrupt_InterruptCallback(void){
    
}

void isr_ERRB_Interrupt_InterruptCallback(void){
    
}

/* [] END OF FILE */
