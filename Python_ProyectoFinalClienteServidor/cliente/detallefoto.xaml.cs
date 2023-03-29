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
	public partial class detallefoto : ContentPage
	{
		public detallefoto (string id,string usuarioActual,string ruta)
		{
			
            init(this, id, ruta,usuarioActual);
		}
        async public void init(detallefoto esto , string id,string ruta,string usuarioAcutal)
        {
            String [] texto = new  String[99];
            await peticiones.getPuntuacion(id, texto);
            InitializeComponent();
          

            Image img=  esto.FindByName<Image>("ImgimagenPrincipal");
            img.Source = ruta;
            Entry entcomentario = esto.FindByName<Entry>("entCometario");
            entcomentario.Completed += ( async (sender, e) =>
            {
                
                await peticiones.comentarFoto(id, usuarioAcutal, entcomentario.Text);
                entcomentario.Text = "";
            });
            Device.StartTimer(TimeSpan.FromSeconds(3),  () =>
            {
                ObservableCollection<string> comentarios = new ObservableCollection<string>();
                ObservableCollection<string> usuarios = new ObservableCollection<string>();
                peticiones.GetComentariosDeFoto(id, comentarios, usuarios);
                Label nombre = new Label();
                StackLayout lyComentarios = esto.FindByName<StackLayout>("lyComentarios");
                lyComentarios.Children.Clear();
                Label comentario = new Label();
                for (int i = 0; i < comentarios.Count; i++) { 
                    nombre.Text = usuarios[i];
                    comentario.Text = comentarios[i]+":";
                    lyComentarios.Children.Add(comentario);
                    lyComentarios.Children.Add(nombre);
                    
                }


                return true;
            });
            Button like = esto.FindByName<Button>("like");
            Button dislike = esto.FindByName<Button>("dislike");
            Label txtNumeroDeBotos = esto.FindByName<Label>("txtNumeroDeBotos");
            like.Clicked += (async  (sender, e) =>
            {
                await peticiones.enviarVoto(id, 1, usuarioAcutal);
           
            });
           
            dislike.Clicked += (async (sender, e) =>
            {
                await peticiones.enviarVoto(id, -1, usuarioAcutal);

              
            });
            txtNumeroDeBotos.Text = texto[0];
        }
       
	}
}