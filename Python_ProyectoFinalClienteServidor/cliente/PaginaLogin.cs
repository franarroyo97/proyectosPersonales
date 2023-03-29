
using Plugin.Media;
using Plugin.Media.Abstractions;
using Plugin.Permissions;
using Plugin.Permissions.Abstractions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;

using Xamarin.Forms;

namespace cliente
{
	public class PaginaLogin : ContentPage
	{
        
        public PaginaLogin ()
		{
            string UsuarioActual = String.Empty;
            var EtiquetaUsuario = new Label
            {
                Text = "nombre de usuario"
            };
            var txtUsuario = new Entry
            {
                Placeholder = "escriba su nombre de usuario"
            };
            Device.BeginInvokeOnMainThread(() =>
            {

                DisplayAlert("Test", "Test Successful", "Ok");

            });
            var EtiquetaContrasena = new Label
            {
                Text = "contraseña "
            };
            var txtContrasena = new Entry
            {
                Placeholder = "escriba su nombre de usuario",
                IsPassword = true
            };
            var btnLogin = new Button { Text = "logerse" };
            var btnRegistro = new Button { Text = "registrarse" };
            Image imge = new Image();
            btnLogin.Clicked +=(sender,e)=>
            {
                Device.BeginInvokeOnMainThread(async () =>
                {
                    Int32 port = 777;
                    String serverIP = "192.168.1.133";
                    TcpClient client = new TcpClient(serverIP, port);
                    NetworkStream stream = client.GetStream();
                    Byte[] entrada = new Byte[1024];
                    Byte[] salida = new Byte[1024];
                    entrada = System.Text.Encoding.ASCII.GetBytes("protoclo#login#" + txtUsuario.Text + "#" + txtContrasena.Text + "");
                   
                    // Send the message to the connected TcpServer. 
                    stream.Write(entrada, 0, entrada.Length);

                   
                    Int32 bytes = stream.Read(salida, 0, salida.Length);
                    String responseData = String.Empty;
                    responseData = System.Text.Encoding.ASCII.GetString(salida, 0, bytes);
                    string salidaF = responseData;
                    String[] salidaFsplit = salidaF.Split('#');
                    if (salidaFsplit[1] == "login_ok")
                    {
                        UsuarioActual = txtUsuario.Text;
                        peticiones.Conectar(UsuarioActual);
                        Device.BeginInvokeOnMainThread(() =>
                        {
                            Navigation.PopAsync();
                            Navigation.PushAsync(new PaginaPrincipal(UsuarioActual));
                        });

                    }
                    else
                    {
                        await DisplayAlert("Test", "fallo de autenticacion ", "Ok");
                    }
                    stream.Close();
                    client.Close();

                });
            };
            btnRegistro.Clicked +=  (sender, e) =>
            {
                Device.BeginInvokeOnMainThread(() =>
                {
                    Navigation.PopAsync();
                    Navigation.PushAsync(new Registro());
                });
            };

            Content = new StackLayout
            {
                Padding = 30,
                Spacing = 10,
                Children = { EtiquetaUsuario, txtUsuario, EtiquetaContrasena, txtContrasena, btnLogin,btnRegistro, imge }
            };
         
        }
        string usuario;
        string contrasena;
        
          
      
    }
}