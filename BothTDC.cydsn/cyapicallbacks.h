/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef CYAPICALLBACKS_H
#define CYAPICALLBACKS_H
    
    /*Define your macro callbacks here */
    /*For more information, refer to the Macro Callbacks topic in the PSoC Creator Help.*/
    #define isr_INTB_INTERRUPT_INTERRUPT_CALLBACK
    void isr_INTB_Interrupt_InterruptCallback(void);

    #define isr_ERRB_INTERRUPT_INTERRUPT_CALLBACK
    void isr_ERRB_Interrupt_InterruptCallback(void);

#endif /* CYAPICALLBACKS_H */   
/* [] */
