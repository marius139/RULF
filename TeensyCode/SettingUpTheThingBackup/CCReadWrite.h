/*
 * In this we are going to set up a connection to a RS-485 based
 * Dynamixel bus on Serial1. The physical serial port Serial1 is on pins 0 and 1
 * on the Teensy 3.5. We will also set up a transmit enable pin on pin 2 to
 * enable transmitting with the RS-485 transceiver board
 */

#include <Arduino.h>

// Using Arduino Mega? Uncomment this:
// #define ARDUINOMEMUSE

// Buffers for transmitting (tx) and receiving (rx).
// NB: If you transmit or receive packages longer than 30 bytes, then change the
// length definitions below.
#define TX_BUFFER_LEN 30
#define RX_BUFFER_LEN 30
uint8_t tx_buffer[TX_BUFFER_LEN];
uint8_t rx_buffer[RX_BUFFER_LEN];


// Low-level functions for setting individual bytes in the buffers.
void putInt8t(int8_t value, uint8_t* buffer, size_t pos)
{
  buffer[pos] = value;
}

int8_t getInt8t(uint8_t* buffer, size_t pos)
{
  return buffer[pos];
}

void putUint8t(uint8_t value, uint8_t* buffer, size_t pos)
{
  buffer[pos] = value;
}

uint8_t getUint8t(uint8_t* buffer, size_t pos)
{
  return buffer[pos];
}

void putInt16t(int16_t value, uint8_t* buffer, size_t pos)
{
  buffer[pos] = (uint8_t)(value & 0x00ff);
  buffer[pos + 1] = (uint8_t)(value >> 8);
}

void putUint16t(uint16_t value, uint8_t* buffer, size_t pos)
{
  buffer[pos] = (uint8_t)(value & 0x00ff);
  buffer[pos + 1] = (uint8_t)(value >> 8);
}

int16_t getInt16t(uint8_t* buffer, size_t pos)
{
  int16_t v = 0;
  v = buffer[pos + 1];
  v = v << 8;
  v = v | buffer[pos];
  return v;
}

uint16_t getUint16t(uint8_t* buffer, size_t pos)
{
  uint16_t v = 0;
  v = buffer[pos + 1];
  v = v << 8;
  v = v | buffer[pos];
  return v;
}

void putInt32t(int32_t val, uint8_t* buffer, size_t pos)
{
  for (int16_t i = 0; i < 4 ; i++) {
    buffer[pos + i] = (uint8_t)(val & 0x000000ff);
    val = val >> 8;
  }
}

int32_t getInt32t(uint8_t* buffer, size_t pos)
{
  int32_t v = 0;
  for (int16_t i = 3; i > -1 ; --i) {
    v = v << 8;
    v = v | (int32_t)buffer[pos + i];
  }
  return v;
}


// Dynamixel Protocol 2.0
// The protocol defines a header with fixed positions for the instruction and
// length fields:
#define DXL_LENGTH_POS 5
#define DXL_INSTRUCTION_POS 7

inline size_t getPackageLength(uint8_t* buffer)
{
  return getUint16t(buffer, DXL_LENGTH_POS);
}

// Cyclic Redundancy Check (CRC)
// The protocol uses CRC to check for faults in the transmissions, see:
// https://en.wikipedia.org/wiki/Cyclic_redundancy_check. Specifically
// Dynamixel uses a variant of the CRC16 algorithm used in MODBUS also called
// CRC-16-IBM, see http://emanual.robotis.com/docs/en/dxl/crc/.
#ifdef ARDUINOMEMUSE
const uint16_t  crc_table[] PROGMEM = {
#else
const uint16_t  crc_table[] = {
#endif

  0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
  0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
  0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
  0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
  0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
  0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
  0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
  0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
  0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
  0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
  0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
  0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
  0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
  0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
  0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
  0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
  0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
  0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
  0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
  0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
  0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
  0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
  0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
  0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
  0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
  0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
  0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
  0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
  0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
  0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
  0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
  0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202
};


uint16_t calculateCrc(uint16_t crc_accum, uint8_t* data_blk_ptr, size_t data_blk_size)
{
  size_t i, j;

  for (j = 0; j < data_blk_size; j++)
  {
    i = ((uint16_t)(crc_accum >> 8) ^ data_blk_ptr[j]) & 0xFF;
#ifdef ARDUINOMEMUSE
    crc_accum = (crc_accum << 8) ^  pgm_read_word_near(crc_table + i);
#else
    crc_accum = (crc_accum << 8) ^ crc_table[i];
#endif
  }
  return crc_accum;
}

// Add CRC to a buffer
// Calculates the CRC and appends it to the buffer.
//
// @param buffer    The buffer to calculate CRC for.
// @param data_size The number of bytes in the buffer to calculate the CRC for.
//                  Incidentally, this is also the position in the array where
//                  the CRC will be added.
void addCrc(uint8_t* buffer, size_t data_size)
{
  uint16_t crc;
  crc = calculateCrc(0, buffer, data_size);
  putInt16t(crc, tx_buffer, data_size);
}

// Check the CRC of a package
// Calculates the CRC of the data in the buffer and compares it to the received
// CRC checksum.
//
// @param buffer the buffer holding the package.
// @param pos the position of the first CRC byte in the buffer.
// @return true if the CRC check is successful.
boolean checkCrc(uint8_t* buffer, int16_t pos)
{
  uint16_t incomming_crc = getUint16t(buffer, pos);
  uint16_t calculated_crc = calculateCrc(0, buffer, pos);
  return (calculated_crc == incomming_crc);
}

void setHdrAndID(uint8_t id)
{
  tx_buffer[0] = 0xff;
  tx_buffer[1] = 0xff;
  tx_buffer[2] = 0xfd;
  tx_buffer[3] = 0x00;
  tx_buffer[4] = id;
}


void dumpPackage(uint8_t *buffer)
{
  size_t l = getPackageLength(buffer) + 7;
  for (size_t i = 0; i < l; i++) {
    Serial.print((int)buffer[i], HEX); Serial.print(" ");
  }
  Serial.println("");
}

// Transmit the package in the tx_buffer
void transmitPackage()
{
  size_t pgk_length = getPackageLength(tx_buffer) + 7;
  Serial1.write(tx_buffer, pgk_length);
}

// Try to receive a package
//
// @param timeout milliseconds to wait for a reply.
// @returns true if a package was received and the CRC checks out.
bool receivePackage(size_t timeout = 100)
{
  elapsedMillis since_start = 0;
  size_t bytecount = 0;
  size_t remaining_read = 1;
  while (remaining_read > 0 && since_start < timeout)
  {
    if (Serial1.available())
    {
      uint8_t incomming_byte = Serial1.read();
      switch (bytecount)
      {
        case 0:
        case 1: if (incomming_byte == 0xFF) {
                  rx_buffer[bytecount] = incomming_byte;
                  ++bytecount;
                } else {
                  bytecount = 0;
                }
                break;
        case 2: if (incomming_byte == 0xFD)
                {
                  rx_buffer[bytecount] = incomming_byte;
                  ++bytecount;
                } else {
                  bytecount = 0;
                }
                break;
        case 3:
        case 4:
        case 5: rx_buffer[bytecount] = incomming_byte;
                ++bytecount;
                break;
        case 6: rx_buffer[bytecount] = incomming_byte;
                remaining_read = getPackageLength(rx_buffer);
                ++bytecount;
                break;
        default: rx_buffer[bytecount] = incomming_byte;
                 ++bytecount;
                 --remaining_read;
                 break;
      }
    }
  }
  if (remaining_read == 0)
  {
    //dumpPackage(rx_buffer, getPackageLength(rx_buffer));
    return checkCrc(rx_buffer, bytecount-2);
  }
  else
  {
    return false;
  }
}

// Send a READ instruction to the servo
void sendReadInstruction(uint8_t id, uint16_t from_addr, uint16_t data_length)
{
  /* Read instruction package
  0     1     2     3     4    5      6     7     8      9       10      11      12    13
  H1    H2    H3    RSRV  ID   LEN1   LEN2  INST  PARAM1 PARAM2  PARAM3  PARAM4  CRC1  CRC2
  0xFF  0xFF  0xFD  0x00  0x01  0x07  0x00  0x02  0x84   0x00    0x04    0x00    0x1D  0x15
  */
  setHdrAndID(id);
  putUint16t(7, tx_buffer, DXL_LENGTH_POS);
  putUint8t(0x02, tx_buffer, DXL_INSTRUCTION_POS);
  putUint16t(from_addr, tx_buffer, 8);
  putUint16t(data_length, tx_buffer, 10);
  addCrc(tx_buffer, 12);

  transmitPackage();
}

// Send a 1 byte WRITE instruction to the servo
void sendWriteInstruction1(uint8_t id, uint16_t address, uint8_t data)
{
  setHdrAndID(id);
  putUint16t(6, tx_buffer, DXL_LENGTH_POS);
  putUint8t(0x03, tx_buffer, DXL_INSTRUCTION_POS);
  putUint16t(address, tx_buffer, 8);
  putUint8t(data, tx_buffer, 10);
  addCrc(tx_buffer, 11);

  transmitPackage();
}

// Send a 2 byte WRITE instruction to the servo
void sendWriteInstruction2(uint8_t id, uint16_t address, uint8_t data)
{
  setHdrAndID(id);
  putUint16t(7, tx_buffer, DXL_LENGTH_POS);
  putUint8t(0x03, tx_buffer, DXL_INSTRUCTION_POS);
  putUint16t(address, tx_buffer, 8);
  putUint8t(data, tx_buffer, 10);
  addCrc(tx_buffer, 12);

  transmitPackage();
}

// Send a 4 byte WRITE instruction to the servo
void sendWriteInstruction4(uint8_t id, uint16_t address, int32_t data)
{
  /* Read instruction package
  0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
  H1   H2   H3   RSRV ID   LEN1 LEN2 INST P1   P2   P3   P4   P5   P6   CRC1 CRC2
  0xFF 0xFF 0xFD 0x00 0x01 0x09 0x00 0x03 0x74 0x00 0x00 0x02 0x00 0x00 0xCA 0x89
  */
  setHdrAndID(id);
  putUint16t(9, tx_buffer, DXL_LENGTH_POS);
  putUint8t(0x03, tx_buffer, DXL_INSTRUCTION_POS);
  putUint16t(address, tx_buffer, 8);
  putInt32t(data, tx_buffer, 10);
  addCrc(tx_buffer, 14);

  transmitPackage();
}


void sendWriteInstruction69(uint8_t id, uint16_t address, int32_t data)
{
  /* Read instruction package
  0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
  H1   H2   H3   RSRV ID   LEN1 LEN2 INST P1   P2   P3   P4   P5   P6   CRC1 CRC2
  0xFF 0xFF 0xFD 0x00 0x01 0x09 0x00 0x03 0x74 0x00 0x00 0x02 0x00 0x00 0xCA 0x89
  */
  setHdrAndID(id);
  putInt16t(9, tx_buffer, DXL_LENGTH_POS);
  putInt8t(0x03, tx_buffer, DXL_INSTRUCTION_POS);
  putInt16t(address, tx_buffer, 8);
  putInt32t(data, tx_buffer, 10);
  addCrc(tx_buffer, 14);

  transmitPackage();
}

// Ping a servo
// Pings the servo and waits for a response. If none is received within the
// timeout, the ping fails. There is no check as to whether the response is
// appropriate. When sending a ping to broadcast (0xFE), several packages may be
// received. The user should look into the received package to see if the result
// is satisfactory.
//
// @param  id      the servo ID to ping.
// @param  timeout milliseconds before timing out.
// @return true if response is received.
bool doPing(uint8_t id, size_t timeout = 100)
{
  /* Ping Instruction Packet
    0     1     2     3     4     5     6     7     8     9
    H1    H2    H3    RSRV  ID    LEN1  LEN2  INST  CRC1  CRC2
    0xFF  0xFF  0xFD  0x00  0x01  0x03  0x00  0x01  0x19  0x4E
  */
  setHdrAndID(id);
  putUint16t(3, tx_buffer, DXL_LENGTH_POS); // length is at pos 5 and 6
  putUint8t(0x01, tx_buffer, DXL_INSTRUCTION_POS); // ping instruction (0x01) at pos 7
  addCrc(tx_buffer, 8); // CRC at pos 8 and 9
  transmitPackage();

  bool package_received = receivePackage(timeout);

  return package_received;
}

// Set the goal position of a servo
// Reads the position of a servo, if no response is read, the function does not
// modify the value of the position variable.
//
// @param id the servo ID to get the position of.
// @param position a reference to store the read position in.
// @return true if the servo responded.
bool readPosition(uint8_t id, int32_t &pos)
{
  sendReadInstruction(id, 132, 4);
  if (receivePackage(100))
  {
    pos = getInt32t(rx_buffer, 9);

    if(pos<30000 && pos != 3233 && pos != 3113 && pos > -10000){
    return true;
    }
    else{return false;}
    }
  else{return false;}
}

bool readVelocity(uint8_t id, int32_t &velocity)
{
  sendReadInstruction(id, 128, 4);
  if (receivePackage(100))
  {
    velocity = getInt32t(rx_buffer, 9);

    if(velocity<30000 && velocity != 3233 && velocity != 3113 && velocity > -10000){
    return true;
    }
    else{return false;}
  }
  else
  {
    return false;
  }
}

// Read the position of a servo
//
// @param id       the servo ID to set the position of.
// @param position the position to go to.
// @return true if the servo responded.
bool setGoalPosition(uint8_t id, int32_t position)
{
  sendWriteInstruction4(id, 116, position);
  if (receivePackage(100))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Enable torque on the servo
// The torque must be enabled for the motor to move.
//
// @param id     the servo ID to set the position of.
// @param enable whether the torque should be enabled or not.
// @return true if the servo responded.
bool torqueEnable(uint8_t id, bool enable)
{
	uint8_t enable_data = 0x01;
	if (!enable)
	{
		enable_data = 0x00;
	}
	sendWriteInstruction1(id, 64, enable_data);
	if (receivePackage(100))
	{
		return true;
	}
	else
	{
		return false;
	}
}
