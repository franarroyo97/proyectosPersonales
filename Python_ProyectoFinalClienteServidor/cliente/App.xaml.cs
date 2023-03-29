using System;
using System.Net.Sockets;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

[assembly: XamlCompilation (XamlCompilationOptions.Compile)]
namespace cliente
{
	public partial class App : Application
	{
		public App ()
		{
            Boolean a = true;
      
           

            MainPage = new NavigationPage(new PaginaLogin());
		}

		protected override void OnStart ()
		{
			// Handle when your app starts
		}

		protected override void OnSleep ()
		{
			// Handle when your app sleeps
		}

		protected override void OnResume ()
		{
			// Handle when your app resumes
		}
	}
}
