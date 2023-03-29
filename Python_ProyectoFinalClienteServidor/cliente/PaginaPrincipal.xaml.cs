using Plugin.Media;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;
namespace cliente
{

    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PaginaPrincipal : TabbedPage
    {
        Image imagen1;
        Image imagen2;
        ObservableCollection<UsuariosConectadosChat> User  { set; get; }
        ObservableCollection<UsuariosConectadosChat> TodosLosUsuarios { set; get; }
        string usuario = "";
        public  PaginaPrincipal (string usuarioActual)
        {
              usuario = usuarioActual;

              SlcImgAsync(usuarioActual , this);
         

        }
        Plugin.Media.Abstractions.MediaFile imge;
        public async Task SlcImgAsync(string usuarioActual, PaginaPrincipal esto)
        {
            User = new ObservableCollection<UsuariosConectadosChat>();
            TodosLosUsuarios = new ObservableCollection<UsuariosConectadosChat>();

            ObservableCollection<UsuariosConectadosChat> listaDeMisFotos = new ObservableCollection<UsuariosConectadosChat>();
            ObservableCollection<UsuariosConectadosChat> fotosDeMisAmifos = new ObservableCollection<UsuariosConectadosChat>();
            await peticiones.GetFotos(listaDeMisFotos, usuarioActual);
            await peticiones.GetFotosDeMisAmigos(fotosDeMisAmifos, usuarioActual);
            await Task.Run(async () =>
            {
               await peticiones.GetUsuariosAsync(TodosLosUsuarios);
                Debug.Print("FIN DE TAREAS");
            });
            await Task.Run(async () =>
            {
                await peticiones.GetUsuariosConectadosAsync(User);
                Debug.Print("FIN DE TAREAS");
            });
            foreach(UsuariosConectadosChat i in TodosLosUsuarios )
            {
                if (i.nombreDeUsuario.ToLower() == usuarioActual.ToLower())
                {
                    TodosLosUsuarios.Remove(i);

                    break;
                }
                Debug.WriteLine("loop");
            }
            InitializeComponent();

            ListViewUsuariosConectados.ItemsSource = User;
            ListViewUsuariosConectados.BindingContext = User;
            ListViewUsuarios.ItemsSource = TodosLosUsuarios;
            ListViewUsuarios.BindingContext = TodosLosUsuarios;

            for (int i = 0; i < User.Count; i++)
            {
                Debug.Write(User[i].nombreDeUsuario + "->?" + usuarioActual);
                if (User[i].nombreDeUsuario.ToLower() == usuarioActual.ToLower())
                {


                    esto.btnPerfil.Image = User[i].ruta;

                    Debug.Write("ruta" + User[i].ruta);
                }
            }
            esto.txtHistoria.Text = peticiones.getHistoria(usuarioActual);
            esto.btnPerfil.Clicked+= btnPerfil_Click;//definicion aparte
            esto.entradaChat.Completed += (sender, e) => {
                peticiones.enviarMensajeAlChat(usuarioActual+":"+ esto.entradaChat.Text);
                esto.entradaChat.Text = "";
            };
            ListViewUsuariosConectados.ItemSelected += ((sender, e) =>
            {
                ((ListView)sender).SelectedItem = null;
            });
              ListViewUsuarios.ItemSelected += (async (sender , e) =>
            {
                var item = (UsuariosConectadosChat)e.SelectedItem;
                var respuesta = await DisplayAlert("enviar petecion de amistad", "quire enviar peticion a " + item.nombreDeUsuario + "?", "si", "no");

                if (respuesta==true)
                {
                    await peticiones.petecionDeAmistad(usuarioActual, item.nombreDeUsuario);
                
                }
                
            });
            esto.btnPeticionesDeAmistad.Clicked += ((sender, e) =>
            {
                Navigation.PushAsync(new peticionesDeAmistad(usuarioActual));
            });
            esto.btnsubirFoto.Clicked += ( async (sender, e) =>
            {
                Image imgSubir = new Image();
               await selecionarImagenAsync(imgSubir);
               await peticiones.subirImagen(usuarioActual, img);
            });
            Device.StartTimer(TimeSpan.FromSeconds(1),  () =>
            {
                List<string> mensajesDelServidor = new List<string>();
               
                    peticiones.getLogDelChat(mensajesDelServidor);
              
                
                List <Label> listaDeMensajes = new List<Label>();
               
                foreach( string i in mensajesDelServidor) {
                    Label lv = new Label();
                    lv.Text = i;
                    listaDeMensajes.Add(lv);
                    Debug.WriteLine("i------>"+i+"log->"+ mensajesDelServidor.Count);
                }
                ventanaDeMensajes.Children.Clear();
                foreach (Label i in listaDeMensajes) {
                    ventanaDeMensajes.Children.Add(i);
                 }
                return true; 
            });
           
            for(int i = 0; i < listaDeMisFotos.Count; i++)
            {
                Image imagene = new Image();
                imagene.Source= listaDeMisFotos[i].ruta;
                
                layoutCarruselDeImagenes.Children.Add(imagene);
            }
            for (int i = 0; i < fotosDeMisAmifos.Count; i++)
            {
                Button imagene = new Button();
                Label nombre = new Label();

                imagene.Image = fotosDeMisAmifos[i].ruta;
                imagene.BackgroundColor = Color.Transparent;
                nombre.Text ="nombre:" +fotosDeMisAmifos[i].nombreDeUsuario;
                imagene.Clicked += ((sender, e) =>
                {
                Button item =(Button)sender ;
                    string id = string.Empty;
                    Boolean encontrado = false;
                    for (i = 0; i < fotosDeMisAmifos.Count && encontrado==false; i++)
                    {
                        if (item.Image == fotosDeMisAmifos[i].ruta)
                        {
                            id = fotosDeMisAmifos[i].idDeLaImagen;
                            encontrado = true;
                        }
                    }
                    Navigation.PushAsync(new detallefoto(id,usuarioActual,item.Image));
                });
                layoutFotosDeMisAmigos.Children.Add(nombre);
                layoutFotosDeMisAmigos.Children.Add(imagene);
            }

        }
         Plugin.Media.Abstractions.MediaFile img;
            public async Task selecionarImagenAsync(Image imgSubir)
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
        async void btnPerfil_Click(object sender, System.EventArgs e){
            var respuesta =await  DisplayActionSheet("¿que desea hacer?", "Cancelar", null, "salir");
            if(respuesta == "salir")
            {
                Debug.WriteLine("entro en el if");
                await peticiones.Desonectar(usuario);
                Debug.Print("ok");
                System.Diagnostics.Process.GetCurrentProcess().Kill();

            }
           
        }
    }
}