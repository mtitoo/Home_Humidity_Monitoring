

void Web_Service(){

   // listen for incoming web clients
  EthernetClient client = server.available();
  if (client) {
   // Serial.println("new client");
    
    //Check Server (LED) Voltage
    int sensorValue = analogRead(A0); // read the input on analog pin 0:
    float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
      
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    String buffer = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
          //Serial.print(c);
          buffer+=c;
          
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          
          // send a standard http response header
              //HTML START        
    client.println("<head>");
    client.print("<meta http-equiv=\"refresh\" content=\"5\">");
    client.println("<title>Crawl Space Humidity Monitor</title>");
    client.println("</head>");
    client.println("<meta name=\"viewport\" content=\"width=device-width\" />");
//    client.println("<script>");
//    client.println("function gtu(path, params, method) {");
//    client.println("    method = method || \"GET\";");
//    client.println("    var form = document.createElement(\"form\");");
//    client.println("    form.setAttribute(\"method\", method);");
//    client.println("    form.setAttribute(\"action\", path);");
//    client.println("    for(var key in params) {");
//    client.println("        if(params.hasOwnProperty(key)) {");
//    client.println("            var hF = document.createElement(\"input\");");
//    client.println("            hF.setAttribute(\"type\", \"hidden\");");
//    client.println("            hF.setAttribute(\"name\", key);");
//    client.println("            hF.setAttribute(\"value\", params[key]);");
//    client.println("            form.appendChild(hF);");
//    client.println("         }");
//    client.println("    }");
//    client.println("    document.body.appendChild(form);");
//    client.println("    form.submit();");
//    client.println("}");
//    client.println("</script>");
    client.println("<body>");
    client.println("<h1>Crawl Space Humidity Monitor</h1>");
    
    client.println("<table width=\"768\" height=\"100\" border=\"1\">");
    client.println("  <tr>");
    client.println("    <th width=\"150\" scope=\"col\">Location</th>");
    client.println("    <th width=\"170\" scope=\"col\">Device</th>");
    client.println("    <th width=\"175\" scope=\"col\"><div align=\"center\">Humidity(%)</div></th>");
    client.println("    <th width=\"175\" scope=\"col\">Temperature (F)</th>");
    client.println("    <th width=\"100\" scope=\"col\">Voltage (V)</th>");
    
    client.println("    <th width=\"50\" scope=\"col\">Comments</th>");
    client.println("  </tr>");
    client.println("  ");
    client.println("  <tr>");
    
    
   
    
    
    for (int i=0;i<Num_Pipe;i++){
        client.println("  <tr>");
        client.println("    <td>"); 
         client.println(Sensor_Location[i]);
        client.println(" </td>");
        client.println("    <td>Humidity Sensor</td>");
        
        
        //client.println("    <td>Humidity Sensor</td>");
        client.println("    <td>"); 
        //client.println(WebServer_Counter++);
        client.println(humidity[i]);
        //client.print(Humidity_Sensor_Data[i]);
        client.println("    </td>");
        client.println("    <td>");
        client.println(temperature[i]);
        client.println("    </td>");
        client.println("    <td>");
        client.println(Sensor_Station_Source_Voltage[i]);
        client.println("    </td>");
        client.println("  </tr>");
    }//end of for loop
    
    client.println("</table>");
    client.println("</body>");
    break;
        }//HTML END
        
       if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
       
          
      }//
      delay(1);
      
      
      
    }//End of while
    
    client.stop();
    //Serial.println("client disonnected");
      
    
  }//end of if - Client Available
}//end of Web_Service
