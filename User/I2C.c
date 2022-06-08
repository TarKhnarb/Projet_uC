#include "I2C.h"


void initI2C0(){
        
        LPC_PINCON->PINSEL1 |= ~((1 << 23) | (1 << 25));
        LPC_PINCON->PINSEL1 &= (1 << 22) | (1 << 24);
        I2C_Init(LPC_I2C0, 1000000);
        I2C_Cmd(LPC_I2C0, ENABLE);
}

void ecrire(uint32_t adresse, uint8_t *data, uint32_t length){
        
        I2C_M_SETUP_Type I2CSetup;
        I2CSetup.sl_addr7bit = adresse;
        I2CSetup.tx_data = data;
        I2CSetup.tx_length = length;
        I2CSetup.rx_data = NULL;
        I2CSetup.retransmissions_max = 3;
        
        I2C_MasterTransferData(LPC_I2C0, &I2CSetup, I2C_TRANSFER_POLLING);
}

void lire(uint32_t adresse, uint8_t *data, uint32_t length, uint8_t *receivedData, uint32_t receivedLength){
        
        I2C_M_SETUP_Type I2CSetup;
        I2CSetup.sl_addr7bit = adresse;
        I2CSetup.rx_data = receivedData;
        I2CSetup.rx_length = receivedLength;
        I2CSetup.tx_data = data;
        I2CSetup.tx_length = length;
        I2CSetup.retransmissions_max = 3;
        
        I2C_MasterTransferData(LPC_I2C0, &I2CSetup, I2C_TRANSFER_POLLING);

}