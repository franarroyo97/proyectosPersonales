using Plugin.Media;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace cliente
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class Registro : ContentPage
    {
        public Registro()
        {
            InitializeComponent();
            setCmp();

        }
        public void setCmp()
        {
            this.FindByName<Button>("btnAceptar");
            this.FindByName<Button>("btnSubirImagen");
            
            btnAceptar.Clicked += BtnAceptar_Clicked;

            btnSubirImagen.Clicked += BtnSubirImagen_Clicked;
            


        }

       async private void BtnSubirImagen_Clicked(object sender, EventArgs e)
        {
            this.FindByName<Image>("imgSubir");

            
              await  selecionarImagenAsync(imgSubir);
           
        }
        Plugin.Media.Abstractions.MediaFile img;
        private async Task selecionarImagenAsync (Image imgSubir)
        {
            if (Device.OS == TargetPlatform.iOS)
            {
                await DisplayAlert("fallo", "en IOS  no se pude acceder a recursos externos... ", "Ok");
                await CrossMedia.Current.Initialize();
                img = await ServicioFoto.Instancia.CapturarFotoAsync();

                imgSubir.Source = ImageSource.FromStream(() => { return img.GetStream(); });
            }
            else
            {
                await CrossMedia.Current.Initialize();
                img = await ServicioFoto.Instancia.SeleccionarFotoAsync();
                imgSubir.Source = ImageSource.FromStream(() => { return img.GetStream(); });
            }
        }
        private void BtnAceptar_Clicked(object sender, EventArgs e)
        {
            this.FindByName<Image>("imgSubir");
            this.FindByName<Entry>("txtNuevoUsuario");
           this.FindByName<Entry>("txtNuevaContrasena");
            this.FindByName<Entry>("txtInformacion");
            if (imgSubir == null)
            {
                DisplayAlert("fallo", "es obligatorio subir una imagen", "ok");
            }
            else if (String.IsNullOrEmpty(txtNuevoUsuario.Text))
            {
                DisplayAlert("fallo", "es obligatorio un nombre de usuario", "ok");
            }
           else  if (String.IsNullOrEmpty(txtNuevaContrasena.Text))
            {
                DisplayAlert("fallo", "es obligatorio una contraseña", "ok");
            }
           else  if (String.IsNullOrEmpty(txtInformacion.Text))
            {
                DisplayAlert("fallo", "es obligatorio una descripcion", "ok");
            }
            else
            {
                bool a;
               
              peticiones.NuevoUsuaro(txtNuevoUsuario.Text, txtNuevaContrasena.Text, txtInformacion.Text, img);
                DisplayAlert("fin de tarea", "registrado con exito", "ok");

            }
        }
    }
   
}