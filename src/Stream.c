#include "Stream.h"

/*  openStream
 *
 *  Function      : To open or create a file and create Stream structure.
 *
 *  Arguments
 *  f_Name(in)    : The file name going to open or create
 *  openMethod(in): The operate method for file, either read ("r") or write ("w")
 *
 *  Return
 *  newStream     : Stream structure that create recently.
 */
Stream *openStream(char *f_Name, char *openMethod){

  Stream* newStream = calloc(sizeof(Stream),1);
  newStream->file = fopen(f_Name,openMethod);
  if(newStream->file == NULL){
    printf("Error: cannot open the file %s\n",f_Name);
    Throw(ERR_FILE_NOT_EXIST);
  }
  newStream->bitIndex = 0;
  newStream->byteIndex = 0;
  newStream->filename = f_Name;

  return newStream;
}

/*  closeStream
 *
 *  Function : Close the file and free the Stream structure.
 *
 *  Arguments
 *  stream(in)  : Stream structure that contain the message related file and buffer.
 */
void closeStream(Stream *stream){
  fclose(stream->file);
  free(stream);
}

/*  streamReadBits
 *  Function  : To read the file based on the bit size needed
 *
 *  Arguments
 *  in(in)      : Contain the input file for read
 *  bitSize(in) : To determine read in 1 byte or 1 bit
 *  tempChar    : To store the data read from file
 *
 *  return
 *  readChar  : Data read from file
 */
uint32 streamReadBits(Stream *in, int bitSize){
  uint32 readChar;
  char tempChar;
  if(bitSize == 8){
    if(fgetc(in->file) == EOF)
      Throw(ERR_END_OF_FILE);
    else{
      fseek(in->file, -1, SEEK_CUR); //move the file pointer backward by 1
      readChar = fgetc(in->file);
    }
  }
  else if(bitSize == 1){
    fseek(in->file, in->byteIndex, SEEK_SET);
    if(fgetc(in->file) == EOF){
      Throw(ERR_END_OF_FILE);}
    else{
      fseek(in->file, in->byteIndex, SEEK_SET);
      tempChar = fgetc(in->file);
      tempChar = tempChar << in->bitIndex;
      in->buffer = &tempChar;
      readChar = streamReadBit(in);
      in->bitIndex = in->bitIndex + 1;
      if(in->bitIndex == 8){
        in->byteIndex = in->byteIndex + 1;
        in->bitIndex = 0;
      }
    }
  }
  return readChar;
}

/*  streamReadBit
 *  Function  : To get 1 bit MSB and return it in LSB
 *
 *  Argument
 *  in(in)    : Contain the buffer where point to the data
 *  readChar  : temp variable to store the content in address where buffer point to
 *
 *  return
 *  readChar  : Contain the LSB bit
 */
uint32 streamReadBit(Stream *in){
  char readChar = *(in->buffer);
  readChar = mask1ByteMSB(readChar) >> 7;

  return readChar;
}

/*  streamWriteBit
 *  Function  : To send a byte of data formed by 8 bits to file
 *  
 *  Argument
 *  out(out)        : Contain file info where data write inside
 *  inputBit(in)    : One bit data either '0' or '1'
 *  shiftToLeft(in) : This value required to shift the inputBit in order to arrange
 *                    them from MSB to LSB before send to file
 *  output(out)     : To store the inputBit after shifting
 */
void streamWriteBit(Stream *out, int inputBit){
  int shiftToLeft;
  shiftToLeft = 8 - out->bitIndex;
  if(out->bitIndex == 0)
    out->currentByte = 0;
  if(shiftToLeft != 0)
    shiftToLeft = shiftToLeft - 1;
  inputBit = inputBit << shiftToLeft;
  //printf("IB: %d\n",inputBit);
  out->currentByte = out->currentByte | inputBit;
  out->buffer = &(out->currentByte);
  out->bitIndex = out->bitIndex + 1;
  if(out->bitIndex == 8){
    streamFlush(out);
    out->bitIndex = 0;
  }
}

/*  streamWriteByte
 *  Function  : To send the 1 byte data to file
 *
 *  Arguments
 *  out(out)        : Contain the buffer to store the address of data and file info
 *  decodeSymbol(in): The data required send out
 */
void streamWriteByte(Stream *out, char decodeSymbol){
  out->buffer = &decodeSymbol;
  streamFlush(out);
}

/*  streamFlush
 *  Function  : To send out the data to file.
 *
 *  Arguments
 *  out(in)   : Contain the address of data and and file info.
 */
void streamFlush(Stream *out){
  //printf("Flush out : %d\n",*(out->buffer));
  fputc(*(out->buffer),out->file);
}

/*  writeStuffedByte
 *  Desc.  : Function to check if a byte to be written to file is 0xFF and stuff it with 0x00
 *
 *  Input
 *    out   : The output stream handler. Contains output buffer that stores the data to be
 *             written out to file.
 *    byte  : The byte to be checked if it is 0xFF and to be written to file
 *
 */
void writeStuffedByte(Stream *out, uint8 byte){
  char zeroByte = 0x00;
  
  if(byte == 0xFF){
    out->buffer = &byte;
    streamFlush(out);
    out->buffer = &zeroByte;
    streamFlush(out);
  }
  else{
    out->buffer = &byte;
    streamFlush(out);
  }
}

/*  readStuffedByte
 *  Desc.  : Function to check if a byte read is 0xFF and check if the next byte read is 0x00
 *
 *  Input
 *    in   : The in stream handler.
 *
 *  Output
 *    readByte : The read byte. Will return 0xFF only when the next byte read is 0x00.
 *    
 */
uint8 readStuffedByte(Stream *in){
  unsigned char readByte, tempByte;
  
  readByte = streamReadBits(in, 8);
  
  if(readByte == 0xFF){
    tempByte = streamReadBits(in, 8);
    if(tempByte == 0x00){
    }
    else{}
  }
  
  return readByte;
}

/*  write4Bytes
 *  Desc.  : Function to chop 32 bits into 8 bit chunks to be written out
 *
 *  Input
 *    out   : The output stream handler. Contains output buffer that stores the data to be
 *             written out to file.
 *    byte  : The byte to be chopped.
 *
 */
void write4Bytes(Stream *out, uint32 byte){
  int shift, i;
  uint8 byteToWrite;
  
  for(i = 0, shift = 24; i < 4; i++){
    byteToWrite = ((byte >> shift) & 0xff);
    writeStuffedByte(out, byteToWrite);
    shift -= 8;
  }
}

/*  read4Bytes
 *  Desc.  : Function to read 32 bits
 *
 *  Input
 *    in   : The input stream handler
 *
 *  Output
 *    bytesToRead : 32 bits concatenated together
 *
 */
uint32 read4Bytes(Stream *in){
  int i;
  uint8 byteRead;
  uint32 bytesToRead;
  
  for(i = 0; i < 4; i++){
    byteRead = readStuffedByte(in);
    bytesToRead |= byteRead;
    if(i != 3)
      bytesToRead <<= 8;
  }
  return bytesToRead;
}
