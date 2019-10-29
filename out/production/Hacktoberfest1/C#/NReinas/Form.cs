using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms; // Libreria para Form y MessageBox
using System.Threading; // Librería para los Hilos

namespace _5_Reinas
{
    public partial class Reinas : Form
    {
        private int[] tablero = new int[5]; // Creamos el espacio para el arreglo que contendrá las reinas

        public Reinas() // Constructor
        {
            InitializeComponent();
        }

        private void Reinas_Load(object sender, EventArgs e)
        {

        }

        private void BtnIniciar_Click(object sender, EventArgs e)
        {
            Inicio(); // Llamamos la función que hace todo el proceso
        }

        public void Inicio()
        {
            Point p = new Point(); // Creamos un punto que nos ayudará a mover las reinas

            p.X = 78; // Punto X inicial de la Reina 5
            p.Y = 317; // Punto Y inicial de la Reina 5
            R5.Location = p; // Cambiamos la locación de la Reina 5

            p.X = 78; // Punto X inicial de la Reina 4
            p.Y = 258; // Punto Y inicial de la Reina 4
            R4.Location = p; // Cambiamos la locación de la Reina 4

            p.X = 78; // Punto X inicial de la Reina 3
            p.Y = 199; // Punto Y inicial de la Reina 3
            R3.Location = p; // Cambiamos la locación de la Reina 3

            p.X = 78; // Punto X inicial de la Reina 2
            p.Y = 140; // Punto Y inicial de la Reina 2
            R2.Location = p; // Cambiamos la locación de la Reina 2

            p.X = 78; // Punto X inicial de la Reina 1
            p.Y = 80; // Punto Y inicial de la Reina 1
            R1.Location = p; // Cambiamos la locación de la Reina 1
            R1.Refresh(); // Refrescamos los pictureboxs para tener la imagen actual de como se verían

            for (int i = 0; i < 5; i++) // Ciclo que mueve la Reina 1
            {
                for (int j = 0; j < 5; j++) // Ciclo que mueve la Reina 2
                {
                    for (int k = 0; k < 5; k++) // Cliclo que mueve la Reina 3
                    {
                        for (int l = 0; l < 5; l++) // Ciclo que mueve la Reina 2
                        {
                            for (int m = 0; m < 5; m++) // Ciclo que mueve la Reina 1
                            {
                                tablero[0] = i; // Colocamos la Reina 1
                                tablero[1] = j; // Colocamos la Reina 2
                                tablero[2] = k; // Colocamos la Reina 3
                                tablero[3] = l; // Colocamos la Reina 4
                                tablero[4] = m; // Colocamos la Reina 5

                                Thread.Sleep(20); // Asignamos la velocidad con la que se moverán las reinas

                                // Imprimir picturebox
                                if (Verificar()) // Sí la función devuelve verdadero
                                {
                                    if(MessageBox.Show("Encontró una solución", "!SOLUCION¡", MessageBoxButtons.OKCancel) == DialogResult.Cancel) // Mostramos un mensaje que dice sí queremos continuar o terminar el proceso
                                    {
                                        return; // Sí damos click en "Cancelar" se tendrá que empezar de nuevo
                                    }
                                }

                                Tablero.Refresh(); // Refrescamos a la imagen actual del Tablero

                                if (m + 1 != 5) // Si la Reina 5 está en la posición 5, no moveremos las reina
                                {
                                    p.X = R5.Location.X + 59; // Cambiamos el punto X de la Reina 5
                                    p.Y = R5.Location.Y; // Cambiamos el punto Y de la Reina 5
                                    R5.Location = p; // Movemos la locación de la Reina 5
                                    R5.Refresh(); // Refrescamos a la imagen actual de la Reina 5
                                }
                            } // Fin for de m

                            p.X = 78; // Cambiamos el punto X al inicial de la Reina 5
                            p.Y = 317; // Cambiamos el punto Y al inicial de la Reina 5
                            R5.Location = p; // Movemos la Reina 5 a su punto inicial

                            if (l + 1 != 5) // Si la Reina 4 está en la posición 5, no moveremos las reina
                            {
                                p.X = R4.Location.X + 59; // Cambiamos el punto X de la Reina 4
                                p.Y = R4.Location.Y; // Cambiamos el punto Y de la Reina 4
                                R4.Location = p; // Movemos la locación de la Reina 4
                            }

                            R4.Refresh(); // Refrescamos a la imagen actual de la Reina 4
                            
                        } // Fin for de l

                        p.X = 78; // Cambiamos el punto X al inicial de la Reina 4
                        p.Y = 258; // Cambiamos el punto Y al inicial de la Reina 4
                        R4.Location = p; // Movemos la Reina 4 a su punto inicial

                        if (k + 1 != 5) // Si la Reina 3 está en la posición 5, no moveremos las reina
                        {
                            p.X = R3.Location.X + 59; // Cambiamos el punto X de la Reina 3
                            p.Y = R3.Location.Y; // Cambiamos el punto Y de la Reina 3
                            R3.Location = p; // Movemos la locación de la Reina 3
                        }

                        R3.Refresh(); // Refrescamos a la imagen actual de la Reina 3

                    } // Fin for de k

                    p.X = 78; // Cambiamos el punto X al inicial de la Reina 3
                    p.Y = 199;  // Cambiamos el punto Y al inicial de la Reina 3
                    R3.Location = p; // Movemos la Reina 3 a su punto inicial

                    if (j + 1 != 5) // Si la Reina 2 está en la posición 5, no moveremos las reina
                    {
                        p.X = R2.Location.X + 59; // Cambiamos el punto X de la Reina 2
                        p.Y = R2.Location.Y; // Cambiamos el punto Y de la Reina 2
                        R2.Location = p; // Movemos la locación de la Reina 2
                    }

                    R2.Refresh(); // Refrescamos a la imagen actual de la Reina 2

                } // Fin for de j

                p.X = 78; // Cambiamos el punto X al inicial de la Reina 2
                p.Y = 140;  // Cambiamos el punto Y al inicial de la Reina 2
                R2.Location = p; // Movemos la Reina 2 a su punto inicial

                if (i + 1 != 5) // Si la Reina 1 está en la posición 5, no moveremos las reina
                {
                    p.X = R1.Location.X + 59; // Cambiamos el punto X de la Reina 1
                    p.Y = R1.Location.Y; // Cambiamos el punto Y de la Reina 1
                    R1.Location = p; // Movemos la locación de la Reina 1
                }

                R1.Refresh(); // Refrescamos a la imagen actual de la Reina 1
            } // Fin for de i

            p.X = 78; // Cambiamos el punto X al inicial de la Reina 1
            p.Y = 80;  // Cambiamos el punto Y al inicial de la Reina 1
            R1.Location = p; // Movemos la Reina 1 a su punto inicial
            R1.Refresh(); // Refrescamos la imagen a la inicial
        }

        private Boolean Verificar() // Función que verifica sí hay reinas que se atacan entre sí
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = i + 1; j < 5; j++)                                    //Para que dos reinas, i y j, ocupen la misma diagonal se debe cumplir que la distancia (número de casillas)
                {                                                                  //que hay entre sus respectivas columnas (valores de i y de j) sea igual a la distancia que hay entre sus respectivas filas (valores x[i] y x[j]).
                    if (Math.Abs(i - j) == Math.Abs(tablero[i] - tablero[j]))      //Y dado que la distancia entre dos números cualesquiera es el valor de la diferencia entre ambos,
                        return false;                                              //tenemos que para que dos reinas ocupen la misma diagonal se debe cumplir que |i-j| = |x[i]-x[j]|.
                    if (tablero[i] == tablero[j])
                        return false;
                }
            }
            return true;
        }
    }
}