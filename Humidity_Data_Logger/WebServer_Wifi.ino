

void Web_Service_Wifi(){

  
//  if(esp8266.available()) // check if the esp is sending a message 
//  {
//    
//    if(esp8266.find("+IPD,"))
//    {
//     delay(1000);
// 
//     int connectionId = esp8266.read()-48; // subtract 48 because the read() function returns 
//                                           // the ASCII decimal value and 0 (the first decimal number) starts at 48
//     
//     String webpage = "<h1>Hello</h1>&lth2>World!</h2><button>LED1</button>";
// 
//     String cipSend = "AT+CIPSEND=";
//     cipSend += connectionId;
//     cipSend += ",";
//     cipSend +=webpage.length();
//     cipSend +="\r\n";
//     
//     sendData(cipSend,1000,DEBUG);
//     sendData(webpage,1000,DEBUG);
//     
//     webpage="<button>LED2</button>";
//     
//     cipSend = "AT+CIPSEND=";
//     cipSend += connectionId;
//     cipSend += ",";
//     cipSend +=webpage.length();
//     cipSend +="\r\n";
//     
//     sendData(cipSend,1000,DEBUG);
//     sendData(webpage,1000,DEBUG);
// 
//     String closeCommand = "AT+CIPCLOSE="; 
//     closeCommand+=connectionId; // append connection id
//     closeCommand+="\r\n";
//     
//     sendData(closeCommand,3000,DEBUG);
//    }
//  }
} 
  
  
  
  
  
  
  
//  
//  
//  
//  
//  
//  
//   // listen for incoming web clients
//  EthernetClient client = server.available();
//  if (client) {
//   
//    client.println("<head>");
//    client.print("<meta http-equiv=\"refresh\" content=\"5\">");
//    client.println("<title>Crawl Space Humidity Monitor</title>");
//    client.println("</head>");
//    client.println("<meta name=\"viewport\" content=\"width=device-width\" />");
////    client.println("<script>");
////    client.println("function gtu(path, params, method) {");
////    client.println("    method = method || \"GET\";");
////    client.println("    var form = document.createElement(\"form\");");
////    client.println("    form.setAttribute(\"method\", method);");
////    client.println("    form.setAttribute(\"action\", path);");
////    client.println("    for(var key in params) {");
////    client.println("        if(params.hasOwnProperty(key)) {");
////    client.println("            var hF = document.createElement(\"input\");");
////    client.println("            hF.setAttribute(\"type\", \"hidden\");");
////    client.println("            hF.setAttribute(\"name\", key);");
////    client.println("            hF.setAttribute(\"value\", params[key]);");
////    client.println("            form.appendChild(hF);");
////    client.println("         }");
////    client.println("    }");
////    client.println("    document.body.appendChild(form);");
////    client.println("    form.submit();");
////    client.println("}");
////    client.println("</script>");
//    client.println("<body>");
//    client.println("<h1>Crawl Space Humidity Monitor</h1>");
//    
//    client.println("<table width=\"768\" height=\"100\" border=\"1\">");
//    client.println("  <tr>");
//    client.println("    <th width=\"150\" scope=\"col\">Location</th>");
//    client.println("    <th width=\"170\" scope=\"col\">Device</th>");
//    client.println("    <th width=\"175\" scope=\"col\"><div align=\"center\">Humidity(%)</div></th>");
//    client.println("    <th width=\"175\" scope=\"col\">Temperature (F)</th>");
//    client.println("    <th width=\"100\" scope=\"col\">Voltage (V)</th>");
//    
//    client.println("    <th width=\"50\" scope=\"col\">Comments</th>");
//    client.println("  </tr>");
//    client.println("  ");
//    client.println("  <tr>");
//    
//    
//   
//    
//    
//    for (int i=0;i<Num_Pipe;i++){
//        client.println("  <tr>");
//        client.println("    <td>"); 
//         client.println(Sensor_Location[i]);
//        client.println(" </td>");
//        client.println("    <td>Humidity Sensor</td>");
//        
//        
//        //client.println("    <td>Humidity Sensor</td>");
//        client.println("    <td>"); 
//        //client.println(WebServer_Counter++);
//        client.println(humidity[i]);
//        //client.print(Humidity_Sensor_Data[i]);
//        client.println("    </td>");
//        client.println("    <td>");
//        client.println(temperature[i]);
//        client.println("    </td>");
//        client.println("    <td>");
//        client.println(Sensor_Station_Source_Voltage[i]);
//        client.println("    </td>");
//        client.println("  </tr>");
//    }//end of for loop
//    
//    client.println("</table>");
//    client.println("</body>");
//    break;
//        }//HTML END
//        
//       if (c == '\n') {
//          // you're starting a new line
//          currentLineIsBlank = true;
//        }
//        else if (c != '\r') {
//          // you've gotten a character on the current line
//          currentLineIsBlank = false;
//        }
//       
//          
//      }//
//      delay(1);
//      
//      
//      
//    }//End of while
//    
//    client.stop();
//    //Serial.println("client disonnected");
//      
//    
//  }//end of if - Client Available
//}//end of Web_Service
