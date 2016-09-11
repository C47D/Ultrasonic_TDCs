#include <project.h>
#include "cyapicallbacks.h"

#include "TDC7200_Regs.h"
#include "TDC7200_Funcs.h"
#include "TDC1000_Regs.h"
#include "TDC1000_Funcs.h"

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
    
    TDC1000_INIT_t tdc1000;
    TDC7200_INIT_t tdc7200;
    
    tdc1000.CLOCK_RATE = 0x05;
    tdc1000.CONFIG_0 = 0x05;
    tdc1000.CONFIG_1 = 0x05;
    tdc1000.CONFIG_2 = 0x05;
    tdc1000.CONFIG_3 = 0x05;
    tdc1000.CONFIG_4 = 0x05;
    tdc1000.ERROR_FLAGS = 0x05;
    tdc1000.TIMEOUT = 0x05;
    tdc1000.TOF_1 = 0x05;
    tdc1000.TOF_0 = 0x05;

    tdc7200.CLOCK_CNTR_OVF_H = 0x05;
    tdc7200.CLOCK_CNTR_OVF_L = 0x05;
    tdc7200.CLOCK_CNTR_STOP_MASK_H = 0x05;
    tdc7200.CLOCK_CNTR_STOP_MASK_L = 0x05;
    tdc7200.COARSE_CNTR_OVF_H = 0x05;
    tdc7200.COARSE_CNTR_OVF_L = 0x05;
    tdc7200.CONFIG1 = 0x05;
    tdc7200.CONFIG2 = 0x05;
    tdc7200.INT_MASK = 0x05;
    tdc7200.INT_STATUS = 0x05;
    
    TDC7200_Enable();
    
    for(;;){
        TDC1000_getConfig(NULL);
        LED_DBG_Write(1);
        TDC7200_getConfig(NULL);
        LED_DBG_Write(0);
        TDC1000_setConfig(&tdc1000);
        LED_DBG_Write(1);
        TDC7200_setConfig(&tdc7200);
        LED_DBG_Write(0);
    }
}

void isr_INTB_Interrupt_InterruptCallback(void){
    isr_INTB_ClearPending();
}

void isr_ERRB_Interrupt_InterruptCallback(void){
    isr_ERRB_ClearPending();
}

/* [] END OF FILE */
