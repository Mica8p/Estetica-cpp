#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

//1ra opcion me funciona en version dev c++ 4.9.9.2
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

/*//2da opcion por si no funcionan las teclas direccionales(arriba y abajo)
#define TECLA_ARRIBA 'i'
#define TECLA_ABAJO 'k'
#define ENTER 13*/


typedef char cadena[80];

/* //para hacer funcionar las teclas direccionales (arriba y abajo) con la 2da opcion de #define
char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
 
   // Desactivamos escritura en terminal
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
 
   ReadConsoleA (ih, &c, 1, &contador, NULL);
 
   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }
 
   SetConsoleMode (ih, modo); // Devolvemos control normal
 
   return c;
}*/
enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color más claro que su antecesor).
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGREY = 7,
 DGREY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};

void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

 // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
 // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
 int    New_Color= Text + (Background * 16);

 SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

}
void gotoxy(int x, int y)
{
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y = y;
     SetConsoleCursorPosition(hcon, dwPos);
}
void RectanguloError(int x, int y, int ancho, int alto)
{
     for(int i=0; i<=ancho; i++)
     {
         system("COLOR 0F"); 
             gotoxy(x + i, y);
             Color(BLACK, RED); printf("%c", 205);
             gotoxy(x + i, y + alto);
             Color(BLACK, RED); printf("%c", 205);
     }
     for(int i=0; i<=alto; i++)
     {   
         system("COLOR 0F");   
             gotoxy(x, y + i);
             Color(BLACK, RED); printf("%c", 186);
             
             gotoxy(x + ancho, y + i);
             Color(BLACK, RED); printf("%c", 186);
     }

     gotoxy(x, y);
     Color(BLACK, WHITE); printf("%c", 201);
     
     gotoxy(x + ancho, y);
     printf("%c", 187);
     
     gotoxy(x, y + alto);
     printf("%c", 200);
     
     gotoxy(x + ancho, y + alto);
     printf("%c", 188);
}
void Rectangulo(int x, int y, int ancho, int alto)
{
     for(int i=0; i<=ancho; i++)
     {
         system("COLOR 5F"); 
         gotoxy(x + i, y);
         printf("%c", 205);
         gotoxy(x + i, y + alto);
         printf("%c", 205);
     }
     for(int i=0; i<=alto; i++)
     {   
         system("COLOR 5F");  
         gotoxy(x, y + i);
         printf("%c", 186);
             
         gotoxy(x + ancho, y + i);
         printf("%c", 186);
     }

     gotoxy(x, y);
     printf("%c", 201);
     
     gotoxy(x + ancho, y);
     printf("%c", 187);
     
     gotoxy(x, y + alto);
     printf("%c", 200);
     
     gotoxy(x + ancho, y + alto);
     printf("%c", 188);
}
int menu(cadena titulo, cadena opciones[], int N)
{
    int opcionSeleccionada = 1; //opcion que selecciona el usuario
    int tecla; //tecla precionada por el usuario
    bool repite = true; //controla las repeticiones para que la flecha este en movimiento
    
    do
    {
         system("cls");
         gotoxy(17, 8 + opcionSeleccionada); printf(" ==> ");
         
         //imprimir el titulo
         gotoxy(27, 7);
         printf("  %s", titulo);
         gotoxy(12, 6); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
         gotoxy(12, 16); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
         //imprimir las opciones
         for(int i=0; i<N; i++)
         {     
             gotoxy(22, 9 + i); printf("%d)%s", i+1, opciones[i]);
         }
         
         do
         {
             tecla = getch();//para que funcionen las teclas direccionales (arriba y abajo)
         }while((tecla != TECLA_ARRIBA) && (tecla != TECLA_ABAJO) && (tecla != ENTER));
         
         switch(tecla)
         {
             case TECLA_ARRIBA:
             {
                  opcionSeleccionada--;
                  if(opcionSeleccionada < 1)
                  {
                      opcionSeleccionada = N;
                  }
                  break;
             }
             case TECLA_ABAJO:
             {
                  opcionSeleccionada++;
                  if(opcionSeleccionada > N)
                  {
                     opcionSeleccionada = 1;
                  }
                  break;
             }
             case ENTER:
             {
                  repite = false;
                  break;
             }
         }
    }while(repite); //repite mientras la variable repite sea verdadera
    return opcionSeleccionada;
}

