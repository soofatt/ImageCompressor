#include "unity.h"
#include "ColorConversion.h"

RGB colorRGB;
YCbCr lumaChrom;
RGB returnRGB;

uint8 red[8][8] = {{48, 176, 191, 112, 212, 194, 24, 173},
                   {123, 233, 148, 224, 196, 12, 147, 8},
                   {21, 7, 41, 112, 213, 31, 183, 5},
                   {170, 234, 83, 229, 42, 226, 107, 242},
                   {30, 187, 27, 224, 40, 86, 57, 192},
                   {202, 31, 42, 240, 54, 211, 221, 9},
                   {43, 147, 24, 51, 60, 165, 251, 36},
                   {42, 179, 93, 223, 31, 7, 73, 215}};
                         
uint8 green[8][8] = {{113, 134, 73, 246, 255, 3, 116, 18},
                     {92, 36, 203, 51, 173, 127, 207, 232},
                     {226, 63, 13, 236, 18, 67, 55, 8},
                     {185, 101, 225, 48, 14, 29, 247, 245},
                     {72, 129, 172, 2, 106, 7, 151, 78},
                     {169, 13, 220, 194, 18, 44, 119, 237},
                     {249, 190, 147, 205, 242, 70, 251, 67},
                     {61, 6, 204, 255, 58, 87, 22, 50}};
                           
uint8 blue[8][8] = {{127, 52, 169, 177, 74, 60, 66, 135},
                    {226, 201, 142, 99, 136, 105, 187, 207},
                    {181, 230, 171, 217, 96, 252, 199, 3},
                    {247, 46, 144, 100, 180, 251, 231, 145},
                    {35, 230, 185, 187, 196, 56, 173, 220},
                    {47, 70, 252, 10, 205, 140, 14, 129},
                    {180, 252, 66, 177, 204, 70, 38, 49},
                    {148, 180, 232, 191, 40, 26, 18, 144}};

uint8 Y[8][8];
uint8 Cb[8][8];
uint8 Cr[8][8];
uint8 returnRed[8][8];
uint8 returnBlue[8][8];
uint8 returnGreen[8][8];

void setUp(void){					
  colorRGB.red = &red;
  colorRGB.green = &green;
  colorRGB.blue = &blue;
  returnRGB.red = &returnRed;
  returnRGB.green = &returnGreen;
  returnRGB.blue = &returnBlue;
  lumaChrom.Y = &Y;
  lumaChrom.Cb = &Cb;
  lumaChrom.Cr = &Cr;
}

void tearDown(void){}


void test_convertToLuma_given_rgb_should_obtain_Y(void){
  convertToLuma(&colorRGB, &lumaChrom);
  
  TEST_ASSERT_EQUAL(95, (*(lumaChrom.Y))[0][0]);
  TEST_ASSERT_EQUAL(137, (*(lumaChrom.Y))[0][1]);
}

void test_convertToChromaB_given_rgb_and_Y_should_obtain_Cb(void){
  convertToLuma(&colorRGB, &lumaChrom);
  convertToChromaB(&colorRGB, &lumaChrom);
  
  TEST_ASSERT_EQUAL(146, (*(lumaChrom.Cb))[0][0]);
  TEST_ASSERT_EQUAL(80, (*(lumaChrom.Cb))[0][1]);
}

void test_convertToChromaR_given_rgb_and_Y_should_obtain_Cr(void){
  convertToLuma(&colorRGB, &lumaChrom);
  convertToChromaR(&colorRGB, &lumaChrom);
  
  TEST_ASSERT_EQUAL(94, (*(lumaChrom.Cr))[0][0]);
  TEST_ASSERT_EQUAL(156,(*(lumaChrom.Cr))[0][1]);
}

void test_convertToRed_given_ChromaR_and_Y_should_obtain_Red(void){
  convertToLuma(&colorRGB, &lumaChrom);
  convertToChromaR(&colorRGB, &lumaChrom);
  
  TEST_ASSERT_EQUAL(94, (*(lumaChrom.Cr))[0][0]);
  TEST_ASSERT_EQUAL(156,(*(lumaChrom.Cr))[0][1]);
  
  convertToRed(&returnRGB, &lumaChrom);
  TEST_ASSERT_EQUAL(47, (*(returnRGB.red))[0][0]);
  TEST_ASSERT_EQUAL(176, (*(returnRGB.red))[0][1]);
}

void test_convertToBlue_given_ChromaB_and_Y_should_obtain_Blue(void){
  convertToLuma(&colorRGB, &lumaChrom);
  convertToChromaB(&colorRGB, &lumaChrom);
  
  TEST_ASSERT_EQUAL(146, (*(lumaChrom.Cb))[0][0]);
  TEST_ASSERT_EQUAL(80, (*(lumaChrom.Cb))[0][1]);
  
  convertToBlue(&returnRGB, &lumaChrom);
  TEST_ASSERT_EQUAL(126, (*(returnRGB.blue))[0][0]);
  TEST_ASSERT_EQUAL(51, (*(returnRGB.blue))[0][1]);
}

void test_convertToGreen_given_red_return_blue_return_and_Y_should_obtain_Green(void){
  convertToLuma(&colorRGB, &lumaChrom);
  convertToChromaB(&colorRGB, &lumaChrom);
  TEST_ASSERT_EQUAL(146, (*(lumaChrom.Cb))[0][0]);
  TEST_ASSERT_EQUAL(80, (*(lumaChrom.Cb))[0][1]);
  
  convertToChromaR(&colorRGB, &lumaChrom);
  TEST_ASSERT_EQUAL(94, (*(lumaChrom.Cr))[0][0]);
  TEST_ASSERT_EQUAL(156,(*(lumaChrom.Cr))[0][1]);
  
  convertToBlue(&returnRGB, &lumaChrom);
  TEST_ASSERT_EQUAL(126, (*(returnRGB.blue))[0][0]);
  TEST_ASSERT_EQUAL(51, (*(returnRGB.blue))[0][1]);
  
  convertToRed(&returnRGB, &lumaChrom);
  TEST_ASSERT_EQUAL(47, (*(returnRGB.red))[0][0]);
  TEST_ASSERT_EQUAL(176, (*(returnRGB.red))[0][1]);
  
  convertToGreen(&returnRGB, &lumaChrom);
  TEST_ASSERT_EQUAL(113, (*(returnRGB.green))[0][0]);
  TEST_ASSERT_EQUAL(133, (*(returnRGB.green))[0][1]);
}



