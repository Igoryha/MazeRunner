//  Раскомментируйте для программной реализации шины I2C:   //
//  #define pin_SW_SDA 3                                    // Назначение любого вывода Arduino для работы в качестве линии SDA программной шины I2C.
//  #define pin_SW_SCL 9                                    // Назначение любого вывода Arduino для работы в качестве линии SCL программной шины I2C.
//  Раскомментируйте для совместимости с большинством плат: //
//  #include <Wire.h>                                       // Библиотека iarduino_Position_BMX055 будет использовать методы и функции библиотеки Wire.
//  Ссылки для ознакомления:                                //
//  Подробная информация о подключении модуля к шине I2C:   // http://wiki.iarduino.ru/page/i2c_connection/
//  Подробная информация о функциях и методах библиотеки:   // http://wiki.iarduino.ru/page/Trema_IMU9/
                                                            //
/* ЧТЕНИЕ ДАННЫХ МАГНИТОМЕТРА      */                       // 
                                                            //
#define BMX055_DISABLE_BMA                                  // Не использовать акселерометр (данную строку можно и не писать, но её наличие освобождает память программ за счет неиспользуемого датчика)
#define BMX055_DISABLE_BMG                                  // Не использовать гироскоп     (данную строку можно и не писать, но её наличие освобождает память программ за счет неиспользуемого датчика)
                                                            //
#include <iarduino_Position_BMX055.h>                       // Подключаем библиотеку iarduino_Position_BMX055 для работы с Trema-модулем IMU 9 DOF.
iarduino_Position_BMX055 sensor(BMM);                       // Создаём объект sensor указывая что ему требуется работать только с магнитометром.
                                                            // Если указать параметр BMA - то объект будет работать только с акселерометром.
                                                            // Если указать параметр BMG - то объект будет работать только с гироскопом.
                                                            // Если указать параметр BMM - то объект будет работать только с магнитометром.
                                                            // Если указать параметр BMX - то объект будет работать со всеми датчиками сразу.
                                                            // 
void setup(){                                               // 
     Serial.begin(9600);                                    // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек.
     while(!Serial){}                                       // Ждём готовность Serial к передаче данных в монитор последовательного порта.
     sensor.begin();                                        // Инициируем работу с магнитометром, так как именно для работы с ним создан объект sensor
}                                                           //
void loop(){                                                // 
     sensor.read();                                         // Функция read() читает данные того датчика, для которого был создан объект.
                                                            // Для объекта работающего с магнитометром, функция read() может принять
                                                            // один из двух параметров: BMM_MG или BMM_MCT.
                                                            // Если параметра нет, то используется параметр по умолчанию
                                                            // sensor.read(BMM_MG);  читать индукцию магнитного поля в мГс. (по умолчанию).
                                                            // sensor.read(BMM_MCT); читать индукцию магнитного поля в мкТл.
                                                            // Данные прочитанные функцией read() сохраняются в переменных axisX, axisY, axisZ и temp.
     Serial.print("X="); Serial.print(sensor.axisX); Serial.print(", ");
     Serial.print("Y="); Serial.print(sensor.axisY); Serial.print(", ");
     Serial.print("Z="); Serial.print(sensor.axisZ); Serial.print(" мГс \r\n");
}
