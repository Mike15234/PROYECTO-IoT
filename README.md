# PROYECTO-IoT

**Descripción**

Este proyecto de aplicación IoT recopila datos de temperatura, humedad, presión y altitud mediante una tarjeta ESP-32 conectada a un sensor DHT-11 y un BMP-180. Los datos se envían a la nube de Thingspeak, donde se almacenan en un dashboard privado en el cual se realiza el análisis por parte del modulo de reglas el cual activa el sistema de alertas y envía un mensaje de texto al número del cliente si la temperatura supera los 29 grados o baja de los 18 grados Para lo cual se utiliza la API de la red de Twilio. Por otra parte, se tiene un dashboard público en el cual se permite a los clientes ver los datos actuales de forma amigable.


**Objetivos**

Los objetivos de este proyecto son:

* Recopilar datos de temperatura, humedad, presión y altitud de forma remota.
* Almacenar los datos en la nube para su análisis.
* Proporcionar a los clientes una interfaz visual para ver los datos actuales.
* Enviar alertas a los clientes si se detectan condiciones extremas.

**Requisitos**

Para ejecutar este proyecto, se necesita lo siguiente:

* Una tarjeta ESP-32
* Un sensor DHT-11
* Un sensor BMP-180
* Una cuenta de Thingspeak
* Una cuenta de Twilio

**Instalación**

Para instalar el proyecto, siga estos pasos:

1. Descargue el código fuente localizado en la documentación del repositorio de GitHub.
2. Instale las librerías y dependencias necesarias.
3. Configure la tarjeta ESP-32.
4. Suba el código fuente a la tarjeta ESP-32.

**Uso**

Una vez que el proyecto esté instalado, siga estos pasos para utilizarlo:

1. Conecte la tarjeta ESP-32 a una fuente de alimentación.
2. Espere a que la tarjeta ESP-32 se inicie y se conecte a WiFi.
3. Abra el dashboard de Thingspeak.
4. Vea los datos actuales en el dashboard público o solicite los datos registrados desde el dashboard privado.

**Documentación**

La documentación del proyecto se encuentra en la carpeta DOCUMENTACION del repositorio de GitHub.

**Ejemplo de datos**

![image](https://github.com/Mike15234/PROYECTO-IoT/assets/46784943/abb7743a-f1e5-46d1-a0fd-bbd8eb4a785c)

**Ejemplo de alerta**

El siguiente es un ejemplo de un mensaje de texto que se envía como alerta:

```
¡Alerta! La temperatura ha superado los 29 grados. Hidratate.
```
