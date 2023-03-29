using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Xamarin.Forms;

namespace cliente
{
	public class Page1 : ContentPage
	{
		public Page1 ()
		{
            public PaginaDeLogin()
            {
                var EtiquetaUsuario = new Label
                {
                    Text = "nombre de usuario"
                };
                var txtUsuario = new Entry
                {
                    Placeholder = "escriba su nombre de usuario"
                };
                var EtiquetaContrasena = new Label
                {
                    Text = "contraseña "
                };
                var txtContrasena = new Entry
                {
                    Placeholder = "escriba su nombre de usuario",
                    IsPassword = true
                };
                Button btnLogin = new Button { Text = "logerse" };

                Content = new StackLayout
                {
                    Padding = 30,
                    Spacing = 10,
                    Children = { EtiquetaUsuario, txtUsuario, EtiquetaContrasena, txtContrasena, btnLogin }
                };
            }
	}
}