#line 1 "c:\\Users\\54911\\Documents\\GitHub\\C\\Proyecto 9 - IoT\\Esp\\WsCmd\\cmdPage.cpp"
String cmdPage() {
  String index = R"(HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n
  <!DOCTYPE html>
  <html>

  <head>
      <title>Consola ESP32</title>
      <!-- Con el icono de la pesatana te ahorras intercambio de mensajes -->
      <link rel="shortcut icon" href="https://cdn.icon-icons.com/icons2/350/PNG/512/bash_36261.png">
  </head>

  <body>
      <style>
          #send {
            width: 114px;
          }
        </style>

      <h2 style="text-align: center">Consola Esp32</h2> 
      <div id="mi-contenedor" style="display: flex; margin-bottom: 20px;">
          <textarea id='console' rows='10' cols='50' style="flex: 1;"></textarea> 
      </div>
      <div id="mi-contenedor" style="display: flex;">
          <input id='command' style="flex: 1"></input> 
          <button id='send' style="width: auto" onclick='cmd.send()'>Enviar mensaje</button>
      </div>
      
      <script>     
          
          const PING_INTERVAL = 1000;

          class Cmd {
              constructor() {
                  this.connect();
              }

              connect() {
                  this.write('Conectando...');
                  this.socket !== undefined && this.socket.close();
                  this.socket = new WebSocket('ws://192.168.0.14:8080'); 
                  this.socket.onmessage = (e) => { this.write(e.data); }; 
                  this.socket.onclose = (e) => { this.connect(); };
                  setInterval(() => { this.ping() }, PING_INTERVAL);
              }
              
              send() { 
                  if (this.socket.readyState === 1) {
                      this.socket.send(document.getElementById('command').value); 
                      document.getElementById('command').value = "";
                  } else if (this.socket.readyState !== 0)
                      this.connect();
              }

              write(mensaje) { 
                  let cmd = document.getElementById('console'); 
                  cmd.textContent += mensaje.toString() + '\n';
                  cmd.scrollTop = cmd.scrollHeight;
              }

              ping() {
                  this.socket.send("");
              }
          }

          let cmd = new Cmd();

          // Enviar cuando se presiona enter
          const input = document.getElementById("command");
          input.addEventListener("keyup", function(event) {
              if (event.keyCode === 13) {
                  cmd.send();
              }
          });

          // Para calcular el ancho del input
          const boton = document.getElementById("send");
          const anchoBoton = getComputedStyle(boton).width;
          document.documentElement.style.setProperty("--ancho-boton", anchoBoton);
                  
      </script>
  </body>

  </html>)";
  return index;
}