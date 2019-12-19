/** See a brief introduction (right-hand button) */
#include "_Gyro.h"

/* Private typedef -----------------------------------------------------------*/
typedef uint16_t uint14_t;
typedef struct GyroReadReg__
{
  uint16_t _angleRateX;
  uint16_t _angleRateY;
  uint16_t _angleRateZ;
  uint14_t _angleX;
  uint14_t _angleY;
  uint14_t _angleZ;
} GyroReg_t;

typedef union GyroDataStruct__
{
  GyroReg_t _struct;
  uint8_t   _8byteBuffer[12];
  uint16_t  _16byteBuffer[6];
} GyroUnion_t;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define	SlaveAddress2100	    0x20	
#define	SlaveAddress8700	    0x1E
#define CTRL_REG1_2100        0x13
#define CTRL_REG0_2100        0x0D
#define CTRL_REG1_8700        0x2A  //PDF << FXOS8700 >> P.38

// PDF << FXOS8700 >> - P.25
#define OUT_X_MSB_REG         0x01
#define OUT_X_LSB_REG         0x02
#define OUT_Y_MSB_REG         0x03
#define OUT_Y_LSB_REG         0x04
#define OUT_Z_MSB_REG         0x05
#define OUT_Z_LSB_REG         0x06

#define _IIC                  I2C0

/* Private variables ---------------------------------------------------------*/
static GyroUnion_t _gyroData;

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
#ifdef _SOFT_IIC_SIMULATION_
/**
  * @brief  
  * @param  None
  * @retval None
  */
void GyroInit(void)
{
  IIC_init();

  simiic_write_reg(SlaveAddress2100, CTRL_REG0_2100, 0x03);//设置工作模式，最大量程等                                       
  simiic_write_reg(SlaveAddress2100, CTRL_REG1_2100, 0x03);//输出模式，输出率400HZ                                       
  simiic_write_reg(SlaveAddress8700, CTRL_REG1_8700, 0x05);//读取  输出模式
}

/**
  * @brief  
  * @param  None
  * @retval None
  */
uint8_t * UpdateGyroData(void)
{
  /* 16bits Gyro read angular rate */
	simiic_read_regs(SlaveAddress2100, OUT_X_MSB_REG,  _gyroData._8byteBuffer,    6, IIC);
	/* 14bits Acc read angle */
	simiic_read_regs(SlaveAddress8700, OUT_X_MSB_REG, &_gyroData._8byteBuffer[6], 6, IIC);  
  
  return _gyroData._8byteBuffer;
}

#else  // if not define(_SOFT_IIC_SIMULATION_)
/**
  * @brief  
  * @param  None
  * @retval None
  */
void GyroInit(void)
{
  
  i2c_init(i2c0, 400);

  i2c_write_reg(i2c0, SlaveAddress2100, CTRL_REG0_2100, 0x03);//设置工作模式，最大量程等                                       
  i2c_write_reg(i2c0, SlaveAddress2100, CTRL_REG1_2100, 0x03);//输出模式，输出率400HZ                                       
  i2c_write_reg(i2c0, SlaveAddress8700, CTRL_REG1_8700, 0x05);//读取  输出模式
}

/**
  * @brief  
  * @param  None
  * @retval None
  */
uint16_t * UpdateGyroData(void)
{
  /* 16bits Gyro read angular rate */
	i2c_read_reg_bytes(i2c0, SlaveAddress2100, OUT_X_MSB_REG, 6,  _gyroData._8byteBuffer);
	/* 14bits Acc read angle */
	i2c_read_reg_bytes(i2c0, SlaveAddress8700, OUT_X_MSB_REG, 6, &_gyroData._8byteBuffer[6]);
  /*
  _Kalman_Filter(-(asin((float)(_gyroData._struct._angleZ) / 4096)*57.2958), 
  (((float)(_gyroData._struct._angleRateY >> 4))*7.820) / 1000.0 
  - (((float)-43.678)*7.820 / 1000.0));
  */
  return _gyroData._16byteBuffer;
}


#endif // !_SOFT_IIC_SIMULATION_
