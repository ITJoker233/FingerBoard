/***************************************************
  This is a sample code for my Fingerprint-Keyboard
  Designed specifically to work with the FPM3X fingerprint sensor
  ----> https://item.taobao.com/item.htm?spm=a230r.1.14.16.1d0f7d23CO42c0&id=570338891909

  The Arduino board used here must be Arduino Micro (or other Mega32U4 chip board)
  Arduino     FPM3X
  Tx1 <-----> Rx
  Rx1 <-----> Tx

  more detail please visit this page:
  ---->  https://zhuanlan.zhihu.com/p/64809151

  @Pengzhihui 2019-5-13
 ****************************************************/

#include "fingerprintWrapper.h"

FingerBoard fingerBoard(&Serial1);

void setup()
{
  Serial.begin(115200);

  // Begin(&Serial) means debug mode, will output messages using Serial
  // Use fingerBoard.Begin() to begin without debug message output

  FbStatus status = fingerBoard.Begin(&Serial); 

  if (status == FbStatus::ERROR_SENSOR_NOT_FOUND)
  {
    Serial.println("Did not find fingerprint sensor :(");
  }
}

void loop()
{
  // Serial CMD routine...
  fingerBoard.CmdCheck();

  /* 
   *  Add finger using Serial comand:
   *  Send "A,3" (without ", and need \n or ENTER) and put on your finger to add finger as NO.3
   *  Send "D" (without ", and need \n or ENTER)to delete all finger
   *  more commads to be add later...
   */

  // Run this as often as possible, if there is a finger detected, 
  // the id will be returned, otherwise returns -1
  
  int id = fingerBoard.GetFingerID();

  switch (id)
  {
  case 1: case 2: case 3:
    fingerBoard.InputPassword("12345678");
    break;

  case 4: case 5: case 6:
    fingerBoard.InputPassword("123456789");
    break;

  case 7: case 8: case 9:
    fingerBoard.InputPassword("aaabbbccc");
    break;

    /* 

    you can also use like this:

    // The keyboard will type the string and perform an enter.
    fingerBoard.TypeString("www.pengzhihui.com", true);

    // The keyboard will press ctrl+v and then release.
    fingerBoard.PressKey(KEY_LEFT_CTRL);
    fingerBoard.PressKey('v');
    fingerBoard.ReleaseAll();
     
    */
  }
}
