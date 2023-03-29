using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace cliente
{
	[XamlCompilation(XamlCompilationOptions.Compile)]
	public partial class peticionesDeAmistad : ContentPage
	{
		public peticionesDeAmistad (string usuarioActual)
		{
			InitializeComponent ();
            llamadasAMetodos(this, usuarioActual);

        }
        async private void llamadasAMetodos(peticionesDeAmistad esto,String usuarioActual)
        {
            ObservableCollection<string> peticionesDeAmistadSinAtender = new ObservableCollection<string>();
           await peticiones.getPecticionesDeAmistadSinAtender(usuarioActual, peticionesDeAmistadSinAtender);
            esto.ListViewPeticionesDeAmitad.ItemsSource = peticionesDeAmistadSinAtender;
            esto.ListViewPeticionesDeAmitad.BindingContext = peticionesDeAmistadSinAtender;
            ListViewPeticionesDeAmitad.ItemSelected += (async (sender, e) =>
            {
                var item = (string)e.SelectedItem;
                var respuesta = await DisplayAlert("peticion de amistad", "quire confirmar Peticion De amistad de  " + item + "?", "si", "no");

                if (respuesta == true)
                {
                    await peticiones.aceptarAmistad(usuarioActual, item);

                }
            });
        }
	}
}
