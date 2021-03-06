//  Раскомментируйте для программной реализации шины I2C:   //
//  #define pin_SW_SDA 3                                    // Назначение любого вывода Arduino для работы в качестве линии SDA программной шины I2C.
//  #define pin_SW_SCL 9                                    // Назначение любого вывода Arduino для работы в качестве линии SCL программной шины I2C.
//  Раскомментируйте для совместимости с большинством плат: //
//  #include <Wire.h>                                       // Библиотека iarduino_Position_BMX055 будет использовать методы и функции библиотеки Wire.
//  Ссылки для ознакомления:                                //
//  Подробная информация о подключении модуля к шине I2C:   // http://wiki.iarduino.ru/page/i2c_connection/
//  Подробная информация о функциях и методах библиотеки:   // http://wiki.iarduino.ru/page/Trema_IMU9/
                                                            //
/* ЧТЕНИЕ ДАННЫХ АКСЕЛЕРОМЕТРА В БОЛЕЕ ШИРОКОМ ДИАПАЗОНЕ */ // Акселерометр будет работать в диапазоне ±39.24 м/с².
                                                            //
#define BMX055_DISABLE_BMG                                  // Не использовать гироскоп     (данную строку можно и не писать, но её наличие освобождает память программ за счет неиспользуемого датчика)
#define BMX055_DISABLE_BMM                                  // Не использовать магнитометр  (данную строку можно и не писать, но её наличие освобождает память программ за счет неиспользуемого датчика)
                                                            //
#include <iarduino_Position_BMX055.h>                       // Подключаем библиотеку iarduino_Position_BMX055 для работы с Trema-модулем IMU 9 DOF.
iarduino_Position_BMX055 sensor(BMA);                       // Создаём объект sensor указывая что ему требуется работать только с акселерометром.
                                                            // 
void setup(){                                               // 
     Serial.begin(9600);                                    // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек.
     while(!Serial){}                                       // Ждём готовность Serial к передаче данных в монитор последовательного порта.
     sensor.begin();                                        // Инициируем работу с акселерометром, так как именно для работы с ним создан объект sensor
     sensor.setScale(BMA_4G);                               // Указываем акселерометру производить измерения в новом диапазоне ±4g, где g=9.81 м/с².
     sensor.setFastOffset();                                // Выполняем калибровку акселерометра (быструю компенсацию смещения данных) после установки нового диапазона.
}                                                           // Акселерометр способен работать в диапазонах: BMA_2G, BMA_4G, BMA_8G, BMA_16G.
void loop(){                                                // 
     sensor.read();                                         // Читаем данные акселерометра в единицах по умолчанию (м/с²).
     Serial.print("X="); Serial.print(sensor.axisX); Serial.print(", ");
     Serial.print("Y="); Serial.print(sensor.axisY); Serial.print(", ");
     Serial.print("Z="); Serial.print(sensor.axisZ); Serial.print(" м/с²)\r\n");
}
