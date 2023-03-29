using System;   
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
#if !__MOBILE__
using Windows.Storage;
#endif 
using Xamarin.Forms;

namespace cliente
{
    class peticiones
    {
        static private String ip = "192.168.1.133";
        private static int puerto = 777;
        public static bool NuevoUsuaro(string usuario, string contrasena, string descripcion, Plugin.Media.Abstractions.MediaFile imagen)
        {
            Int32 port = puerto;
            String serverIP =ip ;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#registro#" + usuario + "#" + contrasena + "#"+ descripcion);
            NetworkStream stream = client.GetStream();
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);


            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('#');
            if (salidaFsplit[1].Equals("user_Registrado"))
            {
                int thisRead = 0;
                int blockSize = 1024;
                Byte[] dataByte = new Byte[blockSize];
                {
                    
                    //tramitirImagenes
                    byte[] b = System.IO.File.ReadAllBytes(imagen.Path);
                    String s = Convert.ToBase64String(b);
                    Stream streamImg = new MemoryStream(b);
                
                  
                    int cont = 0;
                    int numBytesToRead=new int();
                    int LD;
                    while ((LD = streamImg.Read(dataByte, 0, dataByte.Length))>0)
                    {
                        
                        stream.Write(dataByte, cont, blockSize);

                        numBytesToRead += dataByte.Length;


                    }
                    byte[] msgOK = Encoding.ASCII.GetBytes("FINDETRANSMISION");
                    stream.Write(msgOK, 0, msgOK.Length);                 
                }
                return true;

            }
            else
            {
                return false;
            }
          
        }
        public static bool Conectar(string usuario)
        {
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#conectar#" + usuario);
            NetworkStream stream = client.GetStream();
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);
            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('#');
            if (salidaFsplit[1].Equals("user_conectado")){
                return true;
            }
            else
            {
                return false;
            }
        }
        public static async Task Desonectar(string usuario)
        {
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#desconectar#" + usuario);
            NetworkStream stream = client.GetStream();
            Debug.Print("mensaje enviado");
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);
            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('#');
            Debug.WriteLine(salida[1]);

        }
        public static async Task GetUsuariosConectadosAsync(ObservableCollection<UsuariosConectadosChat> userd) ///tener en cuenta simpre que aunque el servidor no envie el paquete de 1024 el cliente lee de 1024 en 1024
        {
            ObservableCollection<UsuariosConectadosChat> usuarios = userd;
            UsuariosConectadosChat usuario1 = new UsuariosConectadosChat();
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#GetUsuariosConectadsos");
            NetworkStream stream = client.GetStream();
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);
            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            Debug.WriteLine(responseData);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('0');
            List<byte[]> bytesDeLaImagen = new List<byte[]>();
           
            while (!salidaFsplit[0].Contains("fin de transmision"))
            {
         
                

                   

                    UsuariosConectadosChat user = new UsuariosConectadosChat();
                   
                    usuarios.Add(user);
                   


                    usuarios[usuarios.Count -1].nombreDeUsuario = salidaFsplit[0];
                    Xamarin.Forms.Image img = new Xamarin.Forms.Image();
                    string result;
                    MemoryStream ms = new MemoryStream();
                bool fin = false;
         await Task.Run(() =>
               {
                   stream.Read(salida, 0, salida.Length);
                   responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                   Debug.WriteLine(responseData);
                  
                   string [] cadena = responseData.Split('#');
                   cadena = cadena[3].Split('u');
                   string cadena2 = cadena[0];
                   int longuid = Convert.ToInt32(cadena[0]);
                   byte [] BY = new byte[1];
                   int cont=0;
                   do
                   {
                       Int32 paquete = stream.Read(BY, 0, 1);
                    
                       ms.Write(BY,0,1);

                       
                       responseData = Encoding.ASCII.GetString(BY);
                     
                       if (responseData =="")
                           break;
                       cont++;
                   } while ( cont< longuid);
                   
                   Debug.WriteLine("fin de imagen->"+ms.Length);
              });
              
               
               
#if !__MOBILE__
                    if (Device.OS == TargetPlatform.Windows)
                      await  crearArchivoAsync(ms, img, usuarios[usuarios.Count -1],usuarios.Count);
#endif
                    if (Device.OS == TargetPlatform.Android || Device.OS == TargetPlatform.iOS)
                       await crearArvhicivosEnMovilAsync(ms, img, usuarios[usuarios.Count -1], usuarios.Count);


                    usuarios[usuarios.Count -1 ].imagen = new Xamarin.Forms.Image();
                    usuarios[usuarios.Count -1 ].imagen = img;

                    bytesDeLaImagen.Clear();
                    bytes = stream.Read(salida, 0, salida.Length);
                    responseData = String.Empty;
                    responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                    salidaF = responseData;
                    salidaFsplit = salidaF.Split('0');
                    Debug.WriteLine(usuarios[usuarios.Count - 1].nombreDeUsuario);
                    Debug.WriteLine(responseData);
                
               
            }  


        }
#if ! __MOBILE__
        public static async System.Threading.Tasks.Task crearArchivoAsync(MemoryStream ms , Image test , UsuariosConectadosChat usr , int  numeroDeUsuarios)
        {
            StorageFolder localFolder = ApplicationData.Current.LocalFolder;
            StorageFile sampleFile = await localFolder.CreateFileAsync("img"+ numeroDeUsuarios + ".jpg", CreationCollisionOption.ReplaceExisting);
            await FileIO.WriteBytesAsync(sampleFile, ms.ToArray());
            test.Source = ImageSource.FromFile(localFolder.Path+ "/img "+ numeroDeUsuarios + ".jpg");
            usr.ruta = localFolder.Path + "\\img"+ numeroDeUsuarios + ".jpg";

            Debug.WriteLine("ruta antes de salir de la calse peticiones::" + usr.ruta);


        }
#endif
        public static async System.Threading.Tasks.Task crearArvhicivosEnMovilAsync(MemoryStream ms , Image test,UsuariosConectadosChat  usr , int numeroDeUsuarios)
        {
            var documentsPath = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            var filePath = Path.Combine(documentsPath, "img"+ numeroDeUsuarios + ".jpg");
             File.WriteAllBytes(filePath, ms.ToArray());
         
            usr.ruta = filePath;
            Debug.WriteLine("ruta antes de salir de la calse peticiones::" + usr.ruta);
            test.Source = ImageSource.FromFile(filePath);
            
        }
        //FIN DE TRANSMISION USUARIOS DEL CHAT Y SUS METODOS ASOCIOADOS
        public static string getHistoria(string usuario)
        {
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#gethistoria#" + usuario);
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);

            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            Debug.WriteLine(responseData);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('#');
            return salidaFsplit[2];
            
        }
        public static void enviarMensajeAlChat(string mensaje)
        {
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#mensajePoraElChat#" + mensaje);
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);

            

        }
       public static void getLogDelChat(List<string> mensajesDelServidor)
        {
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[100024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#getLogDelChat#");
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);

            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            string[] log = responseData.Split('#');
            
            int cont = 0;
            foreach ( string i in log) {
                if(cont > 2)
                    mensajesDelServidor.Add(i);
                    Debug.WriteLine("mesg_>" + i);
                    cont++;
            }
            stream.Close();
            client.Close();
        }
        public static async Task GetUsuariosAsync(ObservableCollection<UsuariosConectadosChat> userd) ///tener en cuenta simpre que aunque el servidor no envie el paquete de 1024 el cliente lee de 1024 en 1024
        {
            ObservableCollection<UsuariosConectadosChat> usuarios = userd;
            UsuariosConectadosChat usuario1 = new UsuariosConectadosChat();
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#GetAllUsuarios");
            NetworkStream stream = client.GetStream();
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);
            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            Debug.WriteLine(responseData);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('0');
            List<byte[]> bytesDeLaImagen = new List<byte[]>();

            while (!salidaFsplit[0].Contains("fin de transmision"))
            {





                UsuariosConectadosChat user = new UsuariosConectadosChat();

                usuarios.Add(user);



                usuarios[usuarios.Count - 1].nombreDeUsuario = salidaFsplit[0];
                Xamarin.Forms.Image img = new Xamarin.Forms.Image();
                string result;
                MemoryStream ms = new MemoryStream();
                bool fin = false;
                await Task.Run(() =>
                {
                    stream.Read(salida, 0, salida.Length);
                    responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                    Debug.WriteLine(responseData);

                    string[] cadena = responseData.Split('#');
                    cadena = cadena[3].Split('u');
                    string cadena2 = cadena[0];
                    int longuid = Convert.ToInt32(cadena[0]);
                    byte[] BY = new byte[1];
                    int cont = 0;
                    do
                    {
                        Int32 paquete = stream.Read(BY, 0, 1);

                        ms.Write(BY, 0, 1);


                        responseData = Encoding.ASCII.GetString(BY);

                        if (responseData == "")
                            break;
                        cont++;
                    } while (cont < longuid);

                    Debug.WriteLine("fin de imagen->" + ms.Length);
                });



#if !__MOBILE__
                if (Device.OS == TargetPlatform.Windows)
                    await crearArchivoAsync(ms, img, usuarios[usuarios.Count - 1], usuarios.Count);
#endif
                if (Device.OS == TargetPlatform.Android || Device.OS == TargetPlatform.iOS)
                    await crearArvhicivosEnMovilAsync(ms, img, usuarios[usuarios.Count - 1], usuarios.Count);


                usuarios[usuarios.Count - 1].imagen = new Xamarin.Forms.Image();
                usuarios[usuarios.Count - 1].imagen = img;

                bytesDeLaImagen.Clear();
                bytes = stream.Read(salida, 0, salida.Length);
                responseData = String.Empty;
                responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                salidaF = responseData;
                salidaFsplit = salidaF.Split('0');
                Debug.WriteLine(usuarios[usuarios.Count - 1].nombreDeUsuario);
                Debug.WriteLine(responseData);


            }
            

        }
       async public static Task petecionDeAmistad(string UsuarioQueMandaLaPetecion, String UsuarioQueRecibeLaPetecion)
        {
            UsuariosConectadosChat usuario1 = new UsuariosConectadosChat();
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#PeticionDeAmistad#"+UsuarioQueMandaLaPetecion+"#"+UsuarioQueRecibeLaPetecion);
            NetworkStream stream = client.GetStream();
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);
        }
        async public static Task getPecticionesDeAmistadSinAtender(String UsuarioActual, ObservableCollection<String> usuarios)
        {
            UsuariosConectadosChat usuario1 = new UsuariosConectadosChat();
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#getPeticionesDeAmistadSinAtender#" + UsuarioActual );
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);
           
            String responseData = String.Empty;
            Int32 bytes = stream.Read(salida, 0, salida.Length);
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            Debug.WriteLine(responseData);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('#');//#protoclo#tusPeticiones#usu1#usu3
            int longitud = salidaFsplit.Length - 2;
            string[] resultadoFinal = new string[longitud];
            int cont = 0;
            foreach (string i in salidaFsplit)
            {
                if (cont >2)
                {
                    usuarios.Add(i);
                };
                cont++;
            }
            client.Close();
        }
        async public static Task aceptarAmistad(string usuarioActual,string item)
        {
            UsuariosConectadosChat usuario1 = new UsuariosConectadosChat();
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#aceptarAmistad#" + usuarioActual+"#"+item);
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);

            
           
            client.Close();
        }
        async public  static Task subirImagen(string usuario, Plugin.Media.Abstractions.MediaFile imagen)
        {
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#subirImagen#" + usuario );
            NetworkStream stream = client.GetStream();
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);


            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('#');
            if (salidaFsplit[2].Equals("imagen?"))
            {
                int thisRead = 0;
                int blockSize = 1024;
                Byte[] dataByte = new Byte[blockSize];
                {

                    //tramitirImagenes
                    byte[] b = System.IO.File.ReadAllBytes(imagen.Path);
                    String s = Convert.ToBase64String(b);
                    Stream streamImg = new MemoryStream(b);


                    int cont = 0;
                    int numBytesToRead = new int();
                    int LD;
                    while ((LD = streamImg.Read(dataByte, 0, dataByte.Length)) > 0)
                    {

                        stream.Write(dataByte, cont, blockSize);

                        numBytesToRead += dataByte.Length;


                    }
                    byte[] msgOK = Encoding.ASCII.GetBytes("FINDETRANSMISION");
                    stream.Write(msgOK, 0, msgOK.Length);
                }
              

            }
            

        }
        public static async Task GetFotos(ObservableCollection<UsuariosConectadosChat> userd, string usuarioActual) ///tener en cuenta simpre que aunque el servidor no envie el paquete de 1024 el cliente lee de 1024 en 1024
        {
            ObservableCollection<UsuariosConectadosChat> usuarios = userd;
            UsuariosConectadosChat usuario1 = new UsuariosConectadosChat();
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#GetFotos#"+usuarioActual);
            NetworkStream stream = client.GetStream();
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);
            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            Debug.WriteLine(responseData);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('0');
            List<byte[]> bytesDeLaImagen = new List<byte[]>();

            while (!salidaFsplit[0].Contains("fin de transmision"))
            {





                UsuariosConectadosChat user = new UsuariosConectadosChat();

                usuarios.Add(user);



                usuarios[usuarios.Count - 1].nombreDeUsuario = salidaFsplit[0];
                Xamarin.Forms.Image img = new Xamarin.Forms.Image();
                string result;
                MemoryStream ms = new MemoryStream();
                bool fin = false;
                await Task.Run(() =>
                {
                    stream.Read(salida, 0, salida.Length);
                    responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                    Debug.WriteLine(responseData);

                    string[] cadena = responseData.Split('#');
                    cadena = cadena[3].Split('u');
                    string cadena2 = cadena[0];
                    int longuid = Convert.ToInt32(cadena[0]);
                    byte[] BY = new byte[1];
                    int cont = 0;
                    do
                    {
                        Int32 paquete = stream.Read(BY, 0, 1);

                        ms.Write(BY, 0, 1);


                        responseData = Encoding.ASCII.GetString(BY);

                        if (responseData == "")
                            break;
                        cont++;
                    } while (cont < longuid);

                    Debug.WriteLine("fin de imagen->" + ms.Length);
                });



#if !__MOBILE__
                if (Device.OS == TargetPlatform.Windows)
                    await crearArchivoAsync(ms, img, usuarios[usuarios.Count - 1], usuarios.Count);
#endif
                if (Device.OS == TargetPlatform.Android || Device.OS == TargetPlatform.iOS)
                    await crearArvhicivosEnMovilAsync(ms, img, usuarios[usuarios.Count - 1], usuarios.Count);


                usuarios[usuarios.Count - 1].imagen = new Xamarin.Forms.Image();
                usuarios[usuarios.Count - 1].imagen = img;

                bytesDeLaImagen.Clear();
                bytes = stream.Read(salida, 0, salida.Length);
                responseData = String.Empty;
                responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                salidaF = responseData;
                salidaFsplit = salidaF.Split('0');
                Debug.WriteLine(usuarios[usuarios.Count - 1].nombreDeUsuario);
                Debug.WriteLine(responseData);

            }
            }
        public static async Task GetFotosDeMisAmigos(ObservableCollection<UsuariosConectadosChat> userd, string usuarioActual) ///tener en cuenta simpre que aunque el servidor no envie el paquete de 1024 el cliente lee de 1024 en 1024
        {
            ObservableCollection<UsuariosConectadosChat> usuarios = userd;
            UsuariosConectadosChat usuario1 = new UsuariosConectadosChat();
            Int32 port = puerto;
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, port);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#GetFotosDeMisAmigos#" + usuarioActual);
            NetworkStream stream = client.GetStream();
            // Send the message to the connected TcpServer. 
            stream.Write(entrada, 0, entrada.Length);
            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            Debug.WriteLine(responseData);
            string salidaF = responseData;
            String[] salidaFsplit = salidaF.Split('0');
            List<byte[]> bytesDeLaImagen = new List<byte[]>();

            while (!salidaFsplit[0].Contains("fin de transmision"))
            {





                UsuariosConectadosChat user = new UsuariosConectadosChat();

                usuarios.Add(user);



                usuarios[usuarios.Count - 1].nombreDeUsuario = salidaFsplit[0];
                Xamarin.Forms.Image img = new Xamarin.Forms.Image();
                string result;
                MemoryStream ms = new MemoryStream();
                bool fin = false;
                await Task.Run(() =>
                {
                    stream.Read(salida, 0, salida.Length);
                    responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                    Debug.WriteLine(responseData);

                    string[] cadena = responseData.Split('#');
                    cadena = cadena[3].Split('u');
                    string cadena2 = cadena[0];
                    int longuid = Convert.ToInt32(cadena[0]);
                    byte[] BY = new byte[1];
                    int cont = 0;
                    do
                    {
                        Int32 paquete = stream.Read(BY, 0, 1);

                        ms.Write(BY, 0, 1);


                        responseData = Encoding.ASCII.GetString(BY);

                        if (responseData == "")
                            break;
                        cont++;
                    } while (cont < longuid);

                    Debug.WriteLine("fin de imagen->" + ms.Length);
                    stream.Read(salida, 0, salida.Length);
                    responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                    
                    usuarios[usuarios.Count - 1].idDeLaImagen = responseData.Split('0')[0];
                });



#if !__MOBILE__
                if (Device.OS == TargetPlatform.Windows)
                    await crearArchivoAsync(ms, img, usuarios[usuarios.Count - 1], usuarios.Count);
#endif
                if (Device.OS == TargetPlatform.Android || Device.OS == TargetPlatform.iOS)
                    await crearArvhicivosEnMovilAsync(ms, img, usuarios[usuarios.Count - 1], usuarios.Count);


                usuarios[usuarios.Count - 1].imagen = new Xamarin.Forms.Image();
                usuarios[usuarios.Count - 1].imagen = img;

                bytesDeLaImagen.Clear();
                bytes = stream.Read(salida, 0, salida.Length);
                responseData = String.Empty;
                responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                salidaF = responseData;
                salidaFsplit = salidaF.Split('0');
                Debug.WriteLine(usuarios[usuarios.Count - 1].nombreDeUsuario);
                Debug.WriteLine(responseData);

            }
           
        }
        async public static Task comentarFoto(string id,string usuario,string comentario)
        {
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, puerto);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[1024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#comentar#" + id+"#"+comentario+"#"+usuario);
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);
        }
         static public void  GetComentariosDeFoto(string id , ObservableCollection<string> comentarios , ObservableCollection<string> usuarios) {
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, puerto);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[10024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#getComentarios#" + id );
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);

            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            string[] dat = responseData.Split('#');
            int cont = 0;
            foreach(string i in dat)
            {
                if (cont > 1)
                {
                    if (cont % 2 != 0)//si no es par es decir la 3º vez la 5º ....
                        usuarios.Add(i);
                    else
                        comentarios.Add(i);
                   
                }
                cont++;
            }
        }
    async   public static Task enviarVoto(string id , int boto, string usuario)
        {
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, puerto);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[10024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#enviarBoto#" + id+"#"+boto+"#"+usuario);
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);
        }
     async public static Task getPuntuacion(string id ,  string [] numero)
     {
            String serverIP = ip;
            TcpClient client = new TcpClient(serverIP, puerto);
            Byte[] entrada = new Byte[1024];
            Byte[] salida = new Byte[10024];
            entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#getPuntuacion#" + id);
            NetworkStream stream = client.GetStream();
            stream.Write(entrada, 0, entrada.Length);
            List<int> puntos = new List<int>();
            Int32 bytes = stream.Read(salida, 0, salida.Length);
            String responseData = String.Empty;
            responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
            string[] dat = responseData.Split('#');
            int cont = 0;
            foreach (string i in dat)
            {
                if (cont > 1)
                {

                    puntos.Add(Int32.Parse(dat[cont]));

                }
                cont++;
            }
            int sum = 0; 
            foreach(int i in puntos)
            {
                sum += i;
            }
            numero[0] = sum.ToString();
        }
    }
   
 

}

