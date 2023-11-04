#ifndef plan1xpower_h
#define plan1xpower_h
#include <Arduino.h>

 

class Boost
{
  private:
#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0
uint8_t _mode, _registr, _port_out, _mode1;

uint8_t get_reg(uint8_t pin)
{
  if(pin >= 0 && pin <= 7)
  {
    return 0x0A;
  }
  else if(pin > 7 && pin < 14)
  {
    return 0x04;
  }
  else if(pin > 13 &&  pin < 20)
  {
    return 0x07;
  }
}
uint8_t get_port(uint8_t pin)
{
  if(pin >= 0 && pin <= 7)
  {
    return 0x0B;
  } 
  else if(pin > 7 && pin < 14)
  {
    return 0x05;
  }
  else if(pin > 13 && pin < 20)
  {
    return 0x08;
  }



}

uint8_t validation(uint8_t mode)
{
    while(mode != 1 && mode != 0 )
    {
        return 0;
    }
}

uint8_t convert_to_port(uint8_t pin)
{
  if(pin >= 0 && pin <=7)
  {
      return pin;
  }
  else if(pin > 7 && pin < 14)
  {
   uint8_t temp = pin - 8;
    return temp;
  }
   else if(pin > 13 &&  pin < 20)
   {
    uint8_t temp_1;
    temp_1 = pin - 14;
    return temp_1;
   }

}


void out_or_in(uint8_t  mode, uint8_t  port, uint8_t reg)
{

  switch(mode)
  {
      case 0:

        _SFR_IO8(reg) &= ~(1 << port);
      
      break;
      case 1:
      
       _SFR_IO8(reg) |= (1 << port);
       
      break;
    }
   }


 void mode_go(uint8_t pin_out, uint8_t mode, uint8_t port)//PORTx |= (1 << PORTxnum)&
 {
    switch(mode)
    {
        case 1:
        
        _SFR_IO8(pin_out)|=  (1 << port);
         
        break;
                case 0:
        
                _SFR_IO8(pin_out) &= ~(1 << port);
        
                break;
   }
  }  

 
  

public:
Boost()
{
  
}
 void pin_init (uint8_t  pin , uint8_t mode)
{
  _mode = validation(mode);
  _registr = get_reg(pin);
  uint8_t _port = convert_to_port(pin);
  out_or_in(mode,_port,_registr);
}

void write(uint8_t pin, uint8_t on_off )
{
  _mode1 = validation(on_off);
  _port_out = get_port(pin);
  uint8_t port = convert_to_port(pin);
   mode_go(_port_out,on_off,port);
}
};
#endif


