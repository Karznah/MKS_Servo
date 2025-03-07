/******************************************
 *  
 * Function prototypes for the RS485 commands described in the MKS Servo57D User Manual
 * 
 * For use with the Raspberry Pi Pico C/C++ SDK for uart write
 * Future development planned to support Arduino Serial write
 * 
 ******************************************/

/*******************************************
 * CHANGELOG
 * V.0.0 - Initial Development from User Manual/MKS SERVO42&57D_RS485 User Manual V1.0.6.pdf
 ******************************************/

uint8_t calcChecksum(const uint8_t[] *buffer, int buf_len);

int readEncoderCarry(uint8_t address, int32_t *carry, uint16_t *value);
int readEncoderAddition(uint8_t address, int48_t *value);
int readMotorSpeed(uint8_t address, int16_t * speed);
int readEncoderPulseCount(uint8_t address, int32_t *pulses);
int readIOPortStatus(uint8_t address, uint8_t *status); // May wish to consider rewriting this one to return status of each port individually
int readEncoderRaw(uint8_t address, int48_t *value);
int readEncoderError(uint8_t address, int32_t *error);
int readEnPinStatus(uint8_t address, uint8_t *status);
int readGo0Status(uint8_t address, uint8_t *status);
int readMotorRealaseStatus(uint8_t address, uint8_t *status);
int readMotorShaftProtectionStatus(uint8_t address, uint8_t *status);

int calibrateMotor(uint8_t address);
int setWorkMode(uint8_t address, uint8_t mode);
int setWorkCurrent(uint8_t address, uint16_t current);
int setHoldCurrent(uint8_t address, uint8_t current);
int setSubdivision(uint8_t address, uint8_t micstep);
int setEnPin(uint8_t address, uint8_t enable);
int setDir(uint8_t address, uint8_t dir);
int setAutoSSD(uint8_t address, uint8_t enable);
int setMotorShaftProtection(uint8_t address, uint8_t enable);
int setInterpolation(uint8_t address, uint8_t enable);
int setBaudrate(uint8_t address, uint8_t baud);
int setAddress(uint8_t address, uint8_t newAddress);
int setRespondActive(uint8_t address, uint8_t respond, uint8_t active);
int setModbusRTU(uint8_t address, uint8_t enable);
int setKeyLock(uint8_t address, uint8_t enable);
int setGroupAddress(uint8_t address, uint8_t groupAddr);

int writeIOPort(uint8_t address, uint8_t data);
int setParameterHome(uint8_t address, uint8_t data);
int goHome(uint8_t address);
int setCurrentAxisZero(uint8_t address);
int setNoLimitGoHome(uint8_t address, uint8_t retAngle, uint8_t mode, uint16_t maLimit);
int setLimitPortRemap(uint8_t address, uint8_t enable);
int set0ModeParamater(uint8_t address, uint8_t mode, uint8_t enable, uint8_t speed, uint8_t direction);
int restoreDefaults(uint8_t address);
int restartMotor(uint8_t address);

// Long packets not implemented!

int writeConfig(uint8_t address, uint8_t[] *config);
int readConfig(uint8_t address, uint8_t[] *config);
int readStatus(uint8_t address, uint8_t[] *status);

int setEnTrigger0(uint8_t address);

