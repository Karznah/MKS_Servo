/******************************************
*
 * Functions for the RS485 commands described in the MKS Servo57D User Manual
 *
 * For use with the Raspberry Pi Pico C/C++ SDK for uart write
 * Future development planned to support Arduino Serial write
 *
 ******************************************/

/*******************************************
 * CHANGELOG
 * V.0.0 - Initial Development from User Manual/MKS SERVO42&57D_RS485 User Manual V1.0.6.pdf
 ******************************************/

#include <stdio.h>
#include <stdint.h>

/******************************************************************
 * Takes an array of uint8_t and returns the module8 checksum
 *****************************************************************/
uint8_t calcChecksum(const uint8_t *buffer, int buf_len)
    {
        uint16_t sum = 0;
        for (int i = 0; i < buf_len; i++)
        {
            sum += buffer[i];
        }
        return (sum & 0xFF);
    }

/******************************************************************
 * Takes an array of uint8_t and transmits on the selected UART interface
 * Currently this only supports UART blocking for
 *****************************************************************/
uint8_t transmitRS485(const uint8_t *buffer, int buf_len)
    {

        return 255;
    }

/******************************************************************
 * Takes an array of uint8_t and transmits on the selected UART interface
 * Currently this only supports UART blocking for
 *****************************************************************/
uint8_t receiveRS485(uint8_t *buffer, int buf_len)
    {
        return 255;
    }

uint8_t readEncoderCarry(uint8_t address, int32_t *carry, uint16_t *value)
{
    return 255;
}

uint8_t readEncoderAddition(uint8_t address, int64_t *value)
{
    return 255;
}

uint8_t readMotorSpeed(uint8_t address, int16_t * speed)
{
    return 255;
}
uint8_t readEncoderPulseCount(uint8_t address, int32_t *pulses)
{
    return 255;
}
uint8_t readIOPortStatus(uint8_t address, uint8_t *status) // May wish to consider rewriting this one to return status of each port individually
{
    return 255;
}
uint8_t readEncoderRaw(uint8_t address, int64_t *value)
{
    return 255;
}
uint8_t readEncoderError(uint8_t address, int32_t *error)
{
    return 255;
}
uint8_t readEnPinStatus(uint8_t address, uint8_t *status)
{
    return 255;
}
uint8_t readGo0Status(uint8_t address, uint8_t *status)
{
    return 255;
}
uint8_t readMotorRealaseStatus(uint8_t address, uint8_t *status)
{
    return 255;
}
uint8_t readMotorShaftProtectionStatus(uint8_t address, uint8_t *status)
{
    return 255;
}
uint8_t calibrateMotor(uint8_t address)
{
    return 255;
}
uint8_t setWorkMode(uint8_t address, uint8_t mode)
{
    return 255;
}
uint8_t setWorkCurrent(uint8_t address, uint16_t current)
{
    return 255;
}
uint8_t setHoldCurrent(uint8_t address, uint8_t current)
{
    return 255;
}
uint8_t setSubdivision(uint8_t address, uint8_t micstep)
{
    return 255;
}
uint8_t setEnPin(uint8_t address, uint8_t enable)
{
    return 255;
}
uint8_t setDir(uint8_t address, uint8_t dir)
{
    return 255;
}
uint8_t setAutoSSD(uint8_t address, uint8_t enable)
{
    return 255;
}
uint8_t setMotorShaftProtection(uint8_t address, uint8_t enable)
{
    return 255;
}
uint8_t setInterpolation(uint8_t address, uint8_t enable)
{
    return 255;
}
uint8_t setBaudrate(uint8_t address, uint8_t baud)
{
    return 255;
}
uint8_t setAddress(uint8_t address, uint8_t newAddress)
{
    return 255;
}
uint8_t setRespondActive(uint8_t address, uint8_t respond, uint8_t active)
{
    return 255;
}
uint8_t setModbusRTU(uint8_t address, uint8_t enable)
{
    return 255;
}
uint8_t setKeyLock(uint8_t address, uint8_t enable)
{
    return 255;
}
uint8_t setGroupAddress(uint8_t address, uint8_t groupAddr)
{
    return 255;
}
uint8_t writeIOPort(uint8_t address, uint8_t data)
{
    return 255;
}
uint8_t setParameterHome(uint8_t address, uint8_t data)
{
    return 255;
}
uint8_t goHome(uint8_t address)
{
    return 255;
}
uint8_t setCurrentAxisZero(uint8_t address)
{
    return 255;
}
uint8_t setNoLimitGoHome(uint8_t address, uint8_t retAngle, uint8_t mode, uint16_t maLimit)
{
    return 255;
}
uint8_t setLimitPortRemap(uint8_t address, uint8_t enable)
{
    return 255;
}
uint8_t set0ModeParamater(uint8_t address, uint8_t mode, uint8_t enable, uint8_t speed, uint8_t direction)
{
    return 255;
}
uint8_t restoreDefaults(uint8_t address)
{
    return 255;
}
uint8_t restartMotor(uint8_t address)
{
    return 255;
}
uint8_t writeConfig(uint8_t address, uint8_t *config)
{
return 255;
}
uint8_t readConfig(uint8_t address, uint8_t *config)
{
return 255;
}
uint8_t readAllStatus(uint8_t address, uint8_t *status)
{
return 255;
}
uint8_t setEnTrigger0(uint8_t address)
{
    return 255;
}
uint8_t readMotorStatus(uint8_t address, uint8_t status)
{
    return 255;
}
uint8_t enableMotor(uint8_t address, uint8_t enable)
{
    return 255;
}
uint8_t emergencyStop(uint8_t address)
{
    return 255;
}
uint8_t runSpeedMode(uint8_t address, uint8_t direction, uint16_t speed, uint8_t acceleration)
{
    uint8_t txBuffer[7];
    uint8_t rxBuffer[5];

    txBuffer[0] = 0xFA;
    txBuffer[1] = address;
    txBuffer[2] = 0xF6;
    txBuffer[3] = (direction << 7) | ((speed >> 8) & 0X0F);
    txBuffer[4] = speed & 0x00FF;
    txBuffer[5] = acceleration;
    txBuffer[6] = calcChecksum(txBuffer, 6);

    transmitRS485(txBuffer, 7);

    receiveRS485(rxBuffer, 5);
}
uint8_t stopSpeedMode(uint8_t address, uint8_t acceleration)
{
    return 255;
}
uint8_t saveSpeedMode(uint8_t address, uint8_t state)
{
    return 255;
}