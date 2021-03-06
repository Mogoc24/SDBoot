/*******************************************************************************
* File Name: emFile_mosi0.c  
* Version 1.60
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "emFile_mosi0.h"


/*******************************************************************************
* Function Name: emFile_mosi0_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void emFile_mosi0_Write(uint8 value) 
{
    uint8 staticBits = emFile_mosi0_DR & ~emFile_mosi0_MASK;
    emFile_mosi0_DR = staticBits | ((value << emFile_mosi0_SHIFT) & emFile_mosi0_MASK);
}


/*******************************************************************************
* Function Name: emFile_mosi0_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void emFile_mosi0_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(emFile_mosi0_0, mode);
}


/*******************************************************************************
* Function Name: emFile_mosi0_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro emFile_mosi0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 emFile_mosi0_Read(void) 
{
    return (emFile_mosi0_PS & emFile_mosi0_MASK) >> emFile_mosi0_SHIFT;
}


/*******************************************************************************
* Function Name: emFile_mosi0_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 emFile_mosi0_ReadDataReg(void) 
{
    return (emFile_mosi0_DR & emFile_mosi0_MASK) >> emFile_mosi0_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(emFile_mosi0_INTSTAT) 

    /*******************************************************************************
    * Function Name: emFile_mosi0_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 emFile_mosi0_ClearInterrupt(void) 
    {
        return (emFile_mosi0_INTSTAT & emFile_mosi0_MASK) >> emFile_mosi0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
