#include "web_server.h"
#include <UIPEthernet.h>       // Include the Ethernet library
#include <SPI.h>
#include "config.h"
#include "wdt.h"

EthernetServer server(WEB_SERVER_PORT); // создаем сервер
EthernetClient client; // объект клиент

static float TemperatureC         = 1111;                                     // read-only (static)
static float Humidity             = 2222;                                     // read-only (static)
static float HeatIndexC           = 3333;                                     // read-only (static)

uint8_t web_server_init(void){
    server.begin(); // включаем ожидание входящих соединений
}

static inline uint8_t web_json(void){
    client.print("{");
    client.print("\"TemperatureC\":");
    client.print(TemperatureC);
    client.print(",\"Humidity\":");
    client.print(Humidity);
    client.print(",\"HeatIndexC\":");
    client.print(HeatIndexC); 
    client.print("}");
    return 0;
}
static uint8_t web_head(void){
    return 0;
    client.println(F("HTTP/1.1 200 OK")); // стартовая строка
    client.println(F("Content-Type: text/html; charset=utf-8")); // тело передается в коде HTML, кодировка UTF-8
    client.println(F("Connection: close")); // закрыть сессию после ответа
    client.println(); // пустая строка отделяет тело сообщения
}

static inline uint8_t web_http(void){
    web_head();
    client.println(F("<!DOCTYPE HTML>")); // тело сообщения
    client.println(F(
        "<html>"
            "<head>"
                "<meta charset=\"utf-8\">"
                "<title>" WEB_SERVER_TITLE "</title>"
                "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css\">"
                "<script src=\"https://ajax.googleapis.com/ajax/libs/angularjs/1.6.9/angular.min.js\"></script>"
            "</head>"
            "<body>"
                "<div ng-app=\"myApp\" ng-controller=\"myCtrl\">"
                    "<div style=\"text-align: center;\"><font size=\"9\"><b>" WEB_SERVER_TITLE "</b></font></div>"
                    "<table width=\"100%\">"
                        "<tbody>"
                            "<tr>"
                                "<td style=\"text-align: center;\"><font size=\"8\"><b><font color=\"#0000ff\">Температура</font></b></font></td>"
                                "<td style=\"text-align: center;\"><font size=\"8\" color=\"#800080\"><b style=\"\">Влажность</b></font></td>"
                            "</tr>"
                            "<tr>"
                                "<td style=\"text-align: center;\">"
                                    "<font size=\"8\" color=\"#0000ff\">"
                                        "<b style=\"\">"
                                            "<span style=\"letter-spacing: 1.4px; text-align: start;\">"
                                                "{{myData.TemperatureC}}С°"
                                            "</span>"
                                            ""
                                        "</b>"
                                    "</font>"
                                "</td>"
                                "<td style=\"text-align: center;\">"
                                    "<font size=\"8\" color=\"#800080\">"
                                        "<b style=\"\">"
                                            ""
                                            "{{myData.Humidity}}%"
                                        "</b>"
                                    "</font>"
                                "</td>"
                            "</tr>"
                        "</tbody>"
                    "</table>"
                "</div>"
                "\n"
                "<script>\n"
                    "   var App = angular.module('myApp', []);\n"
                    "   App.controller('myCtrl', function($scope, $http) {\n"
                    "       getJSON = function(){\n"
                    "            $http.get('./json/').then(function(response){\n"
                    "               $scope.myData = response.data; \n"              
                    "           });\n"
                    "       };\n"
                    "       setInterval(function(){\n"
                    "           getJSON();\n"
                    "       }, 30000);\n"
                    "       getJSON();\n"
                    "   });\n"
                "</script>\n"
                "\n"
            "</body>"
        "</html>"
    ));
    return 0;
}


uint8_t web_server_job(void){

    bool flagEmptyLine = true; // признак строка пустая
    char tempChar;

    char urnFromRequest[51]; // строка URN из запроса
    bool urnReceived= false; // признак URN принят
    unsigned int indUrn; // адрес в строке URN

    client = server.available(); // ожидаем объект клиент
    if (client) {
        flagEmptyLine = true;
        Serial.println("New request from client:");
        indUrn = 0;

        while (client.connected()) {
            if (client.available()) {
                tempChar = client.read();
                //Serial.write(tempChar);

                // прием URN
                if( urnReceived == false ) {
                    urnFromRequest[indUrn++] = tempChar;
                    if (indUrn > 49){
                        indUrn = 49;
                        urnFromRequest[50] = 0;
                    }
                    if (tempChar == ' '){
                        urnFromRequest[indUrn-1] = 0;
                        if (!strcmp(urnFromRequest,"GET")){
                            indUrn = 0;
                        } else {
                            urnReceived = true;
                        }
                    }
                }

                if (tempChar == '\n' && flagEmptyLine) {
                    // пустая строка, ответ клиенту
                    if (!strcmp(urnFromRequest,"/")){
                        web_http();
                    }else if (!strcmp(urnFromRequest,"/json/")){
                        web_json();
                    }else if (!strcmp(urnFromRequest,"/favicon.ico")){
                    }
                    break;
                }
                if (tempChar == '\n') {
                    // новая строка
                    flagEmptyLine = true;
                } else if (tempChar != '\r') {
                    // в строке хотя бы один символ
                    flagEmptyLine = false;
                }
            }
            wdt_reset_request();
            delay(1);
        }
        // разрываем соединение
        client.stop();
        Serial.println("Break");
        Serial.println(urnFromRequest);
    }
    return 0;
}

uint8_t web_server_set_params (dht_read_t *dht_read_r){
    TemperatureC = dht_read_r->dht_temperature;
    Humidity = dht_read_r->dht_humidity;
    HeatIndexC = dht_read_r->dht_hic;
    return 0;
}