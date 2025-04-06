#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include "teclasDire.h"  

typedef char cadena[80];
const int TAMANO = 15;

//STRUCTS
struct Fecha
{
     int dd; //dia
     int mm; //mes
     int aaaa; //año  
};  
struct Usuario
{
     cadena usuario;
     cadena clave;
     cadena apeyNom; 
 
};   
struct Profesional
{
	 cadena idProfesional;	  
	 int cantidadDeAtenciones; //contador de atenciones por profesional
	 Fecha fechaDeAtencion;
	 cadena clienteAAtender; 
}; 
struct Cliente
{ 
	cadena apeyNom;
	cadena domicilio;
	int dniCliente;
	cadena localidad;
	Fecha fechaDeNac;
	float peso;
	int telefono;
	char evolTratam[380];  
};

struct Turnos
{ 
	cadena idProfesional; //nombre del profesional que atenderá al cliente
	Fecha fechaDelTurno;
	cadena apeyNomCli;
	int dniCliente;
	cadena detalleDeAtencion; 
};
 
//FUNCIONES
//USUARIOS PROFESIONALES Y RECEPCIONISTAS
void AgregarUsuarios(FILE *archivo)	
{
     Usuario regi;
     int longUsuari = 0;
     int longContra = 0;
     int mayus = 0;
     int digit = 0;
     int minusC = 0;
     int mayusC = 0;
     int digitC = 0;
     int noTener = 0;
     bool resp2 = false;
     bool resp1 = false;
     bool respuestaMinuscula = false;
     
     printf("\nNombre y apellido-------|");
     _flushall();
     gets(regi.apeyNom);
     
     system("cls");
     //VALIDAR NOMBRE DE USUARIO
     printf("1) Nombre de Usuario------|");
     _flushall();
     gets(regi.usuario);
                                  
     longUsuari = strlen(regi.usuario);
     for(int i=0; i<longUsuari; i++)
     {
        if(islower(regi.usuario[0]) != 0)
        {
           respuestaMinuscula = true;
        }
        if(isupper(regi.usuario[i]) != 0)
        {
           mayus++;
        }
        if(isdigit(regi.usuario[i]) != 0)
        {
           digit++;
        }     
     }
     if((respuestaMinuscula == true) && (mayus >= 2) && ( digit <= 3))
     {
         resp1 = true;
         if((longUsuari >= 6 && longUsuari <= 10) && (resp1 == true))
         {
            Color(BLACK, YELLOW); 
            printf("\n %c",223);   
            Color(BLACK, WHITE);   
            printf(" Usuario correcto");
         }
     }
     else
     {
         resp1 = false;
         printf("\n error");
     
     	 do
         {
            RectanguloError(37,7,35,6);
            gotoxy(1, 9);Color(WHITE, RED); printf("<><><><><><><Error...><><><><><><>");
            gotoxy(38, 8); Color(WHITE, RED); printf("Usuario debe tener:");
            gotoxy(38, 9); Color(WHITE, RED); printf("Entre 6 y 10 caracteres");
            gotoxy(38, 10); Color(WHITE, RED); printf("comenzar con letra minuscula");
            gotoxy(38, 11); Color(WHITE, RED); printf("tener al menos 2 letras mayusculas");
            gotoxy(38, 12); Color(WHITE, RED); printf("tener como maximo 3 digitos");
                                      
            system("COLOR 0F");
            Color(BLACK, WHITE); 
            printf("\n\n Nombre de usuario------|");
            _flushall();
            gets(regi.usuario);
                                               
            longUsuari = strlen(regi.usuario);
            for(int i=0; i<longUsuari; i++)
            {
               if(islower(regi.usuario[0]) != 0)
               {
                  respuestaMinuscula = true;
               }
               if(isupper(regi.usuario[i]) != 0)
               {
                  mayus++;
               }
               if(isdigit(regi.usuario[i]) != 0)
               {
                  digit++;
               }  
            }
            if((respuestaMinuscula == true) && (mayus >= 2) && ( digit <= 3))
            {
                resp1 = true;
                if((longUsuari >= 6 && longUsuari <= 10) && (resp1 == true))
				{
                   Color(BLACK, YELLOW); 
                   printf("\n %c",223);   
                   Color(BLACK, WHITE); 
                   printf(" Usuario correcto");
        
                }
            }
            else
            {
               resp1 = false;
            }
         }while((longUsuari < 6) || (longUsuari > 10) || (resp1 == false));
     } 
     getch();
     
     //VALIDAR CONTRASEÑA
     system("cls");
     system("COLOR 6B");
     printf("\n\n2) Crear contraseña:------------|");
     _flushall();
     gets(regi.clave);
      
     longContra = strlen(regi.clave);
     for(int i=0; i<longContra; i++){
       if(islower(regi.clave[i]) != 0){minusC++;}
       if(isupper(regi.clave[i]) != 0){mayusC++;}
       if(isdigit(regi.clave[i]) != 0){digitC++;}
       if((regi.clave[i] == '´') || (regi.clave[i] == ' ') || (regi.clave[i] == '.') || (regi.clave[i] == ':') || (regi.clave[i] == ',') || (regi.clave[i] == ';') || (regi.clave[i] == '¿') || (regi.clave[i] == '?') || (regi.clave[i] == '¡') || (regi.clave[i] == '!') )
       {
          noTener++;       
       }
    }
    if((minusC >= 1) && (mayusC >= 1) && ( digitC >= 1) && (noTener == 0)){
        resp2 = true;
    }
    else{
        resp2 = false;
    }
    if((6 <= longContra) && (longContra <= 32) && (resp2 == true)){
          Color(BLACK, YELLOW); 
          printf("\n %c",223);
          Color(BLACK, WHITE);
          printf(" Contraseña correcta");
      }
      
      while((6 > longContra) || (longContra > 32) || (resp2 == false)){
          RectanguloError(30,7,48,10);
          gotoxy(1, 9);Color(WHITE, RED); printf("<><><><><Error...><><><><>");
          gotoxy(31, 8); Color(WHITE, RED); printf("La contraseña debe tener:");
          gotoxy(31, 9); Color(WHITE, RED); printf("Entre 6 y 32 caracteres");
          gotoxy(31, 10); Color(WHITE, RED); printf("tener almenor 1 letra minuscula,");
          gotoxy(31, 11); Color(WHITE, RED); printf("1 mayuscula y 1 numero");
          gotoxy(31, 12); Color(WHITE, RED); printf("No puede tener: signos de puntuacion,"); 
          gotoxy(31, 13); Color(WHITE, RED); printf("ni acentos, ni espacios"); 
          gotoxy(31, 14); Color(WHITE, RED); printf("no puede tener mas de 3 numeros consecutivos,"); 
          gotoxy(31, 15); Color(WHITE, RED); printf("y tampoco 2 letras alfabeticamente consecutivas"); 
          
          gotoxy(1, 16);Color(BLACK, WHITE);printf("\n\n Contraseña:------------|");
          _flushall();
          gets(regi.clave);
          
          longContra = strlen(regi.clave);
          for(int i=0; i<longContra; i++){
             if(islower(regi.clave[i]) != 0){minusC++;}
             if(isupper(regi.clave[i]) != 0){mayusC++;}
             if(isdigit(regi.clave[i]) != 0){digitC++;}
             if((regi.clave[i] == '´') || (regi.clave[i] == ' ') || (regi.clave[i] == '.') || (regi.clave[i] == ':') || (regi.clave[i] == ',') || (regi.clave[i] == ';') || (regi.clave[i] == '¿') || (regi.clave[i] == '?') || (regi.clave[i] == '¡') || (regi.clave[i] == '!') )
             {
                 noTener++;       
             }
          }
        if((minusC >= 1) && (mayusC >= 1) && ( digitC >= 1) && (noTener == 0)){
            resp2 = true;
        }
        else{
            resp2 = false;
        }
        if((6 <= longContra) && (longContra <= 32) && (resp2 == true)){
            Color(BLACK, YELLOW); 
            printf("\n %c",223);   
            Color(BLACK, WHITE);   
            printf(" Contraseña correcta");
          }
      } 
      //MOVER EL PUNTERO DEL ARCHIVO AL FINAL
      fseek(archivo, 0, SEEK_END);
      fwrite(&regi, sizeof(regi), 1, archivo);
     
     printf("\n\t\t <><><><><><><><><><><><><><><><><><><><><>\n");
     printf("\n\t\t <><><><><><>< USUARIO CREADO ><><><><><><>\n");
     printf("\n\t\t <><><><><><><><><><><><><><><><><><><><><>\n"); 
}
void ListarUsuarios(FILE *archivo)
{
     Usuario regi;
     //Profesionales
     rewind(archivo);
     fread(&regi, sizeof(regi), 1, archivo);
     while(!feof(archivo))
     { 
           printf("\n Nombre y apellido---|%s", regi.apeyNom); 
		   printf("\n Usuario-------------|%s", regi.usuario); 
		   printf("\n Contrasena----------|%s", regi.clave);          
           printf("\n==================================================\n");
           fread(&regi, sizeof(regi), 1, archivo); 
     } 
}
 
//CLIENTES 
void AgregarCliente(FILE *archivo)
{
	Cliente reg;
	
	printf("\n Apellido y Nombre-----|");
	_flushall();
	gets(reg.apeyNom);
	
	printf("\n Domicilio-------------|");
	_flushall();
	gets(reg.domicilio);
	
	printf("\n DNI-------------------|");
	scanf("%d", &reg.dniCliente);
	
	printf("\n Localidad-------------|");
	_flushall();
	gets(reg.localidad);
	
	printf("\n Fecha de Nacimiento");
	printf("\n Dia-------------------|");
	scanf("%d", &reg.fechaDeNac.dd);
	
	printf("\n Mes-------------------|");
	scanf("%d", &reg.fechaDeNac.mm);
	
	printf("\n Año-------------------|");
	scanf("%d", &reg.fechaDeNac.aaaa);
	
	printf("\n Peso------------------|");
	scanf("%f", &reg.peso);
	
	printf("\n Telefono--------------|");
	scanf("%d", &reg.telefono);
	
	fseek(archivo, 0, SEEK_END);
     
    fwrite(&reg, sizeof(reg), 1, archivo);
    
    printf(" \n\t\t <><><><><><><><><><><><><><><><><><><><><><\n");
    printf(" \n\t\t <><><><><>< CLIENTE REGISTRADO  ><><><><><>\n");
    printf(" \n\t\t <><><><><><><><><><><><><><><><><><><><><><\n"); 
}

void ListarClientes(FILE *arc)
{
     Cliente regis;
      
     rewind(arc);
     fread(&regis, sizeof(regis), 1, arc);
     while(!feof(arc))
     {  
	    printf("\n Apellido y Nombre-----|%s", regis.apeyNom);
		printf("\n Domicilio-------------|%s", regis.domicilio);
		printf("\n DNI-------------------|%d", regis.dniCliente);
		printf("\n Localidad-------------|%s", regis.localidad);
		printf("\n Fecha de Nacimiento---|%d/%d/%d", regis.fechaDeNac.dd, regis.fechaDeNac.mm, regis.fechaDeNac.aaaa);
		printf("\n Peso------------------|%.2f", regis.peso);
		printf("\n Telefono--------------|%d", regis.telefono);
        printf("\n==================================================\n");
        fread(&regis, sizeof(regis), 1, arc);
     }
     fclose(arc);
}

bool validarCliente(FILE *arch, Turnos cli)
{
	Cliente reg;
	 
	int comparacion1 = 0;
	bool validacion = true;
	
	//validar si el cliente se encuentra registrado para registrar su turno
	arch  = fopen("Clientes.dat","rb");
	while(!feof(arch))
    {
	     fread(&reg, sizeof(Cliente), 1, arch);
         if(!feof(arch))
         { 
	       comparacion1 = strcmp(reg.apeyNom, cli.apeyNomCli);  
	       if( comparacion1==0 )
	       {
			 validacion = true;
			 break;
	       }
	       else
	       {
	         validacion = false; 
	       } 
	     } 
    }
    return validacion;
    fclose(arch);
}
//TURNOS
void AgregarTurnos(FILE *archiTur)
{
	FILE *archCli;
	Turnos cli; 
	bool v  = true;
  
	
	printf("\n Nombre del profesional-------|");
	_flushall();
	gets(cli.idProfesional);
	
	printf("\n Fecha del turno");
	
	printf("\n Dia--------------------------|");
	scanf("%d", &cli.fechaDelTurno.dd);
	
	printf("\n Mes--------------------------|");
	scanf("%d", &cli.fechaDelTurno.mm);
	
	printf("\n Año--------------------------|");
	scanf("%d", &cli.fechaDelTurno.aaaa);
	 
	printf("\n Nombre del cliente-----------|");  
	_flushall();
	gets(cli.apeyNomCli);
	
	//validar si el cliente se encuentra registrado para registrar su turno
	v = validarCliente(archCli, cli);  
    if(v == true)  
	{ 
	   printf("\n EL CLIENTE SE ENCUENTRA EN LA BASE DE DATOS....!");
	   printf("\n DNI del cliente--------------|");
       scanf("%d", &cli.dniCliente);
	
	   printf("\n Detalle de la atencion: \n");
	   _flushall();
	   gets(cli.detalleDeAtencion);
	     	 
	   fseek(archiTur, 0, SEEK_END);
     
       fwrite(&cli, sizeof(cli), 1, archiTur);
    
       printf(" \n\n <><><><><><><><><><><><><><><><><><><><><>\n");
       printf(" \n\n <><><><><>< TURNO REGISTRADO ><><><><><><>\n");
       printf(" \n\n <><><><><><><><><><><><><><><><><><><><><>\n");
    }
    else
    {
       printf("\n ERROR.... EL CLIENTE NO SE ENCUENTRA REGISTRADO EN LA BASE DE DATOS.....!");
        
    }  
	    
}

void ListarTurnos(FILE *ar)
{ 
    Turnos re;
     
	rewind(ar);
    fread(&re, sizeof(re), 1, ar);
    while(!feof(ar))
    { 
		printf("\n Nombre del profesional-------|%s", re.idProfesional);
		printf("\n Fecha del turno--------------|%d/%d/%d", re.fechaDelTurno.dd, re.fechaDelTurno.mm, re.fechaDelTurno.aaaa);
		printf("\n Nombre del cliente-----------|%s", re.apeyNomCli);
		printf("\n DNI del cliente--------------|%d", re.dniCliente);
		printf("\n Detalle de la atencion: \n %s", re.detalleDeAtencion);
		 
	    printf(" \n\n <><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
	    fread(&re, sizeof(re), 1, ar);
    }
	fclose(ar);	
}
 
void validarUsuario(FILE *archi, cadena busqUsu, cadena busqContra) 
{
	int comparacion1 = 0;
    int comparacion2 = 0;
    Usuario regi;
    bool validacion = true; 
     
	while(!feof(archi))
    {  
         fread(&regi, sizeof(Usuario), 1, archi);
         if(!feof(archi))
         { 
	       comparacion1 = strcmp(regi.usuario, busqUsu); 
	       comparacion2 = strcmp(regi.clave, busqContra);
	       if( (comparacion1==0) && ( comparacion2==0 ))
	       {
			 validacion = true;
			 break;
	       }
	       else
	       {
	         validacion = false; 
	       } 
	     } 
    } 
    if(validacion == true)  
	{ 
	   printf("\n INGRESO EXITOSO....!");
    }
    else
    {
       printf("\n El usuario y contraseña INEXISTENTE.....!");
    }   
} 

void TurnosEnEspera(FILE *arch)
{
	FILE *archivo;
	Turnos re;
	cadena prof;
	int comparacion = 0;
	int comparacion1 = 0;
	Usuario reg;
	bool validacion = true;
	  
	
	printf("\n Profesional:  ");
	_flushall();
	gets(prof);
	
	archivo = fopen("Profesionales.dat", "rb");
	while(!feof(archivo))
    {  
         fread(&reg, sizeof(Usuario), 1, archivo);
         
         if(!feof(archivo))
         {  
	       comparacion = strcmp(reg.apeyNom, prof);  
	       if(comparacion==0)  
	       {
			 validacion = true;    
			 break;
	       }
	       else
	       {
	         validacion = false; 
	       } 
	     } 
    } 
    if(validacion == true)  
    {
	    printf ("\n DNI  \t\t   Apellido y nombre  \t\t  Fecha del turno");
        printf ("\n=================================================================");
	  
        while(!feof(arch))
        { 
	       fread(&re, sizeof(Turnos), 1, arch); 
	       if(!feof(arch))
	       { 
             comparacion1 = strcmp(re.idProfesional, prof); 
	         if(comparacion1==0)  
	         { 
		          printf("\n %d", re.dniCliente);
		          printf("\t\t   %s  ", re.apeyNomCli);
		          printf("\t\t %d/%d/%d", re.fechaDelTurno.dd, re.fechaDelTurno.mm, re.fechaDelTurno.aaaa);  
	              
	              
	         }
	       }
        } 
	}
	else
	{ 
	    printf("\n NO SE ENCUENTRA REGISTRADO EN LA BASE DE DATOS\n O NO INICIO SESION.....!");
	  
    }
	fclose(archivo);
}
// MENUS

void ModuloEspacios()
{
	 bool resp;
     bool repite = true;
     int opcion;
     cadena titulo = "MENU MODULO ESPACIOS";
     cadena opciones[] = {"Iniciar sesion","Informe de atencion", "Lista de turnos en espera(INFORME)", "Registrar evolucion del tratamiento", "Salir"};
     int n = 5;
     
     int comp = 0; 
     FILE *archivo;
     FILE *archivo7;
     FILE *archCli;
     FILE *archTurn;
     cadena usuar;
     cadena contras, profes, respuesta;
     Profesional registro; 
     Cliente reg;
     Turnos r;
     int dia, mes, anio, edad, comparacion, cantidadDeAtenciones; 
     bool validacion;
     
     do
      {
         system("cls");
         system("COLOR 3F");
         opcion = menu(titulo, opciones, n);
         system("cls");
         
         switch(opcion)
         {
                    case 1:
                           {
                               printf(" \n\t\t <><><><><><><><><><><><><>\n"); 
                               printf(" \n\t\t <><>< INICIAR SESION ><><>\n");
                               printf(" \n\t\t <><><><><><><><><><><><><>\n");
                                 
							   printf("\n Usuario:------|");
                               _flushall();
                               gets(usuar);
                               
                               printf("\n Contraseña:---|");
                               _flushall();
                               gets(contras);
                               archivo = fopen("Profesionales.dat", "rb");
                               validarUsuario(archivo, usuar, contras);  
							   fclose(archivo); 
                               break;
                           }
                    case 2: 
					       {
                    	       printf(" \n\t <><><><><><><><><><><><><><><><><><><><>< \n");
                               printf(" \n\t <><><><><  INFORME DE ATENCION   ><><><>< \n");
                               printf(" \n\t <><><><><><><><><><><><><><><><><><><><><  \n");  
							    	
							   archivo7 = fopen("AtencionesPorProfesional.dat", "r+b");
							   if(archivo7 == NULL)
							   { 
						           archivo7 = fopen("AtencionesPorProfesional.dat","w+b");
						           if(archivo7 == NULL)
							       {
							     	  printf("\nError... No se pudo crear el archivo");
								      exit(1);  
							       } 
						       }
							   printf("\n atender si o no?:  ");
							   _flushall();
							   gets(respuesta);
							   while(respuesta == "no"); 
							   {     
								       printf("Profesional: ");
								       _flushall();
								       gets(registro.idProfesional);
								       printf("\n Fecha de Atencion");
								       printf("\n Dia: ");
								       scanf("%d", &registro.fechaDeAtencion.dd);
								       printf("\n Mes: ");
								       scanf("%d", &registro.fechaDeAtencion.mm);
								       printf("\n Anio: ");
								       scanf("%d", &registro.fechaDeAtencion.aaaa);
								       printf("\n Cliente por atender: ");
								       _flushall();
								       gets(registro.clienteAAtender);
								       registro.cantidadDeAtenciones++; 
								       fwrite(&registro, sizeof(Profesional), 1, archivo7);
								       printf("\n atender si o no?:  ");
								       _flushall();
								       gets(respuesta);
									}  
							   fclose(archivo7);  
                    	       break;
                           }       
                    case 3:
                           {
                           	   printf(" \n\t <><><><><><><><><><><><><><><><><><><><><><><> \n");
                               printf(" \n\t <><><><><  LISTA DE TURNOS EN ESPERA  ><><><>< \n");
                               printf(" \n\t <><><><><><><><><><><><><><><><><><><><><><><> \n");
                               
                               archTurn = fopen("Turnos.dat", "rb");
                                
                               TurnosEnEspera(archTurn);
							    
							   fclose(archCli);
							   
							     
							    
                               break; 
                           }
                    case 4:
                           {
                           	   printf(" \n\t ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
                               printf(" \n\t <><><><><>< REGISTRAR EVOLUCION DEL TRATAMIENTO ><><><><><\n");
                               printf(" \n\t ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
                               cadena nombre;
                               printf("\n Fecha   ");
							   printf("\n Dia----|");
							   scanf("%d", &dia);
							   printf("\n Mes----|");
							   scanf("%d", &mes);
							   printf("\n Anio---|");
							   scanf("%d", &anio); 
                               printf("\n Nombre del paciente: ");
                               _flushall();
                               gets(nombre);
                               archCli = fopen("Clientes.dat","a+b");
                               
                               while(!feof(archCli))
					           { 
						         fread(&reg, sizeof(Cliente), 1, archCli); 
						         if(!feof(archCli))
						         { 
					                comp = strcmp(reg.apeyNom, nombre); 
						            if(comp==0)  
						            { 
						              printf("\n Apellido y Nombre-----|%s", reg.apeyNom);
							          printf("\n Domicilio-------------|%s", reg.domicilio);
								      printf("\n DNI-------------------|%d", reg.dniCliente);
									  if(reg.fechaDeNac.mm < mes) 
									  {
									  	 edad = anio - reg.fechaDeNac.aaaa;
									  }
									  else
									  {
									  	  if(reg.fechaDeNac.mm == mes)
									  	  {
									  	  	 if(reg.fechaDeNac.dd <= dia) 
									  	  	 {
									  	  	 	edad = anio - reg.fechaDeNac.aaaa;
									  	  	 }
									  	  	 else
									  	  	 {
									  	  	 	edad = (anio - reg.fechaDeNac.aaaa) - 1;
									  	  	 }
									  	  }
									  } 
									  if(reg.fechaDeNac.mm > mes)
									  {
									  	  edad = (anio - reg.fechaDeNac.aaaa) - 1;
									  } 
								      printf("\n Edad------------------|%d", edad);
								      
								      printf("\n Peso------------------|%.2f", reg.peso); 
						              printf("\n==================================================\n");
							          printf("\n\n\t Evolucion del tratamiento \n\n");
                                      _flushall();
                                      gets(reg.evolTratam);
                               
                                      fwrite(&reg, sizeof(Cliente), 1, archCli);  
						              
						            }
						         }
					           }  
                               fclose(archCli);
                               break;
                           }
					 	                               
                    case 5:
                           {
                              Rectangulo(20,8,30,8);
                              gotoxy(21, 12);
                              printf("   \"FIN DEL MENU ESPACIOS\"");
                              getch();
                              repite = false;
                        
                              break;
                           }
                    default:
                           {
                              printf("\n\n           \"Opcion INCORRECTA\".......");
                              break;
                           }                                
         }//FIN SWITCH
         _flushall();
         getch();
      }while(repite);     
}

void ModuloAdministracion()
{
	 bool repite = true;
     int opcion;
     cadena titulo = "MENU MODULO ADMINISTRACION";
     cadena opciones[] = {"Registrar Profesional", "Listar Profes", "Registrar usuario Recepcionista", "Listar Recep", "Atenciones por personal", "Ranking de atenciones", "Salir"};
     int n = 7;
     
     FILE *archi1;
	 FILE *archi2;
	 FILE *archivo6;
	 FILE *archi;
	 FILE *arc;
	 Profesional regi;
	 cadena pr;
	 int cantidadDeAtenciones;
	 
	 int comparacion = 0;
	 bool validacion; 
	 //Apertura de archivo para profesionales
     archi1 = fopen("Profesionales.dat","r+b");
	 if(archi1 == NULL)
	 {
	 	archi1 = fopen("Profesionales.dat","w+b");
	    if(archi1 == NULL)
	    {
		   printf("\nError... No se pudo crear el archivo");
		   exit(1); 
	    }
	 }  
	  
	 //Apertura de archivo para recepcionistas
	 archi2 = fopen("Recepcionistas.dat","r+b");
	 if(archi2 == NULL)
	 {
	     archi2 = fopen("Recepcionistas.dat","w+b");
	     if(archi2 == NULL)
	     {
		     printf("\nError... No se pudo crear el archivo");
	         exit(1);  
	     }  
	 } 
     do
      {
         system("cls");
         system("COLOR 6B");
         opcion = menu(titulo, opciones, n);
         system("cls");
         
         switch(opcion)
         {
              case 1:
              {
                  printf(" \n\t\t <><><><><><><><><><><><><><><><><><><><><><><\n");
                  printf(" \n\t\t <><><><><>< REGISTRAR PROFESIONAL ><><><><><>\n");
                  printf(" \n\t\t <><><><><><><><><><><><><><><><><><><><><><><\n");
                  AgregarUsuarios(archi1); 
                  break;
              }
              case 2: {
                        printf(" \n\t <><><><><><><><><><><><><><><><><><><><><><><><>\n");
                        printf(" \n\t <><><><><>< LISTADO DE PROFESIONALES ><><><><><>\n");
                        printf(" \n\t <><><><><><><><><><><><><><><><><><><><><><><><>\n");
                         
						ListarUsuarios(archi1);
                        break;
                      }
              case 3: { 
                        printf(" \n\t<><><><><><><><><><><><><><><><><><><><><><><><>\n");
                        printf(" \n\t <><><><><>< REGISTRAR RECEPCIONISTA ><><><><><>\n");
                        printf(" \n\t<><><><><><><><><><><><><><><><><><><><><><><><>\n");
                          
						AgregarUsuarios(archi2); 
                        break;
                      }
              case 4: {
                        printf(" \n\t <><><><><><><><><><><><><><><><><><><><><><><><><\n");
                        printf(" \n\t <><><><><>< LISTADO DE RECEPCIONISTAS ><><><><><>\n");
                        printf(" \n\t <><><><><><><><><><><><><><><><><><><><><><><><><\n");
                         
						ListarUsuarios(archi2);
                        break;
                      }
              case 5: {
                        printf(" \n\t <><><><><>< Atenciones por personal ><><><><><>\n");
                        printf(" \n\t<><><><><><><><><><><><><><><><><><><><><><><><><\n");
                               archi = fopen("AtencionesPorProfesional.dat", "rb");
							   printf ("\n Profesional \t Cliente \tFecha de atencion ");
       						   printf ("\n=================================================================");
							   while(!feof(archi))
							   {  
								   fread(&regi, sizeof(Profesional), 1, archi);
								         
								   if(!feof(archi))
								   {   
								       printf ("\n %s", regi.idProfesional);
								       printf ("\t  %s: ", regi.clienteAAtender);
								       printf ("\t  %d/%d/%d", regi.fechaDeAtencion.dd, regi.fechaDeAtencion.mm, regi.fechaDeAtencion.aaaa);
								        
									} 
								} 
						 
							   fclose(archi); 
                        break;
                      }  
              case 6: {
                        printf(" \n\t <><><><><>< Ranking de atenciones ><><><><><>\n");
                        printf(" \n\t<><><><><><><><><><><><><><><><><><><><><><><><\n");
                        
                        printf("Profesional: ");
                        _flushall();
                        gets(pr);
                        arc = fopen("AtencionesPorProfesional.dat", "r+b");
                         
                        while(!feof(arc))
					    {  
					         fread(&regi, sizeof(Profesional), 1, arc);
					         
					         if(!feof(arc))
					         {  
						       comparacion = strcmp(regi.idProfesional, pr);  
						       if(comparacion==0)  
						       {
								 validacion = true;    
								 break;
						       }
						       else
						       {
						         validacion = false; 
						       } 
						     } 
					    } 
					    if(validacion == true)  
					    {
						    printf ("Cantidad de atenciones: %d", regi.cantidadDeAtenciones);
						}
						else
						{ 
						    printf("\n NO SE ENCUENTRA REGISTRADO EN LA BASE DE DATOS\n O NO INICIO SESION.....!");
						  
					    }
					    fclose(arc);
                        break;
                      }                          
              case 7: {
                        Rectangulo(20,8,30,8);
                        gotoxy(21, 12); printf("\"FIN DEL MENU ADMINISTRACION\"");
                        getch();
                        repite = false;
                        break;
                      }
              default:{
                        Rectangulo(20,8,30,8);
                        gotoxy(21, 12); printf("   \"Opcion INCORRECTA\".....");
                        break;
                      }                                
         }//FIN SWITCH
         _flushall();
         getch();
      }while(repite); 
	  fclose(archi1); 
	  fclose(archi2); 
}

 
void ModuloRecepcion()
{
	 bool repite = true;
     int opcion;
     cadena titulo = "MENU MODULO RECEPCION";
     cadena opciones[] = {"Iniciar sesion", "Registrar cliente", "Registrar turno", "Listar Clientes", "Listar Tunos","Lista de atencion por profesional", "Salir"};
     int n = 7;
      
	 FILE *archCliente;
	 FILE *archiTurno;
	 FILE *archivo; 
     Profesional regi; 
     bool v;
     FILE *archivo1;
     cadena usu;
     cadena contrasena;
     
      
     do
      {
         system("cls");
         system("COLOR B0");
         opcion = menu(titulo, opciones, n);
         system("cls");
         
         switch(opcion)
         {
                    case 1:
                           {
                               printf(" \n\t <><><><><><><><><><><><><>\n"); 
                               printf(" \n\t <><>< INICIAR SESION ><><>\n");
                               printf(" \n\t <><><><><><><><><><><><><>\n"); 
                                
                               archivo1 = fopen("Recepcionistas.dat","rb");
							   if(archivo1 == NULL)
							   { 
								    printf("\nError... No se pudo crear el archivo");
								    exit(1);  
							   }
							   printf("\n Usuario:------|");
                               _flushall();
                               gets(usu);
                               
                               printf("\n Contraseña:---|");
                               _flushall();
                               gets(contrasena);
                               validarUsuario(archivo1, usu, contrasena);
                                 
							   fclose(archivo1);
                               break;
                           }
                    case 2:
                           {
                               printf(" \n\t<><><><><><><><><><><><><><><><\n");
                               printf(" \n\t <><>< REGISTRAR CLIENTES ><><>\n");
                               printf(" \n\t<><><><><><><><><><><><><><><><\n");
                               
				               archCliente = fopen("Clientes.dat","r+b");
					           if(archCliente == NULL)
							   {  
						           archCliente = fopen("Clientes.dat","w+b");
						           if(archCliente == NULL)
							       {
							     	  printf("\nError... No se pudo crear el archivo");
								      exit(1);  
							       } 
						       }
							   AgregarCliente(archCliente);
							   fclose(archCliente);
                               break;
                           }
                    case 3:
                           {
                               printf(" \n\t <><><><><><><><><><><><><><>\n");
                               printf(" \n\t <><>< REGISTRAR TURNOS ><><>\n");
                               printf(" \n\t <><><><><><><><><><><><><><>\n"); 
                               
				               archiTurno = fopen("Turnos.dat","r+b");
					           if(archiTurno == NULL)
							   { 
						           archiTurno = fopen("Turnos.dat","w+b");
						           if(archiTurno == NULL)
							       {
							     	  printf("\nError... No se pudo crear el archivo");
								      exit(1);  
							       } 
						       }
							   AgregarTurnos(archiTurno);
							   fclose(archiTurno);
                               break;
                           }  
                    case 4:
                           {
                               printf(" \n\t <><>< Listar clientes ><><>\n");
                               printf(" \n\t<><><><><><><><><><><><><><>\n");
                               archCliente = fopen("Clientes.dat", "rb");
                               if(archCliente == NULL)
				               {
				               	  printf("\nError... Aun no se registraron turnos");
				                  exit(1);  
				               }
							   ListarClientes(archCliente);
							   fclose(archCliente);
                               break;
                           }  
					case 5:
                           {
                               printf(" \n\t <><>< Listar Turnos ><><>\n");
                               printf(" \n\t<><><><><><><><><><><><><><>\n");
                               archiTurno = fopen("Turnos.dat", "rb");
                               if(archiTurno == NULL)
				               {
				               	  printf("\nError... Aun no se registraron turnos");
				               	  printf("\n\n");
								  system("pause");
				                  break; 
				               }
							   ListarTurnos(archiTurno);
							   fclose(archiTurno);
                               break;
                           }
					case 6:
					       {
					       	   printf(" \n\t<><><><><><><><><><><><><><><><><><><><><><><><\n");
					       	   printf(" \n\t <><>< Lista de atencion por profesional ><><>\n");
                               printf(" \n\t<><><><><><><><><><><><><><><><><><><><><><><><\n");
                                	
							   archivo = fopen("AtencionesPorProfesional.dat", "rb");
							   printf ("\n Profesional \t Cliente \tFecha de atencion ");
       						   printf ("\n=================================================================");
							   while(!feof(archivo))
							   {  
								   fread(&regi, sizeof(Profesional), 1, archivo);
								         
								   if(!feof(archivo))
								   {   
								       printf ("\n %s", regi.idProfesional);
								       printf ("\t  %s: ", regi.clienteAAtender);
								       printf ("\t  %d/%d/%d", regi.fechaDeAtencion.dd, regi.fechaDeAtencion.mm, regi.fechaDeAtencion.aaaa);
								        
									} 
								} 
						 
							   fclose(archivo);
						       break;
					       }
						   	                           
                    case 7:
                           {
                              Rectangulo(20,8,30,8);
                              gotoxy(21, 12);
                              printf("\"FIN DEL MENU RECEPCIONISTA\"");
                              getch();
                              repite = false;
                        
                              break;
                           }
                    default:
                           {
                              printf("\n\n           \"Opcion INCORRECTA\".......");
                              break;
                           }                                           
         }//FIN SWITCH
         _flushall();
         getch();
      }while(repite); 
}

main()
{    
     int opcion;
     cadena titulo = "MENU PRINCIPAL";
     cadena opciones[] = {"Modulo Espacios", "Modulo del Recepcion", "Modulo Administrador","Salir"};
     int n = 4;
     bool repite = true;
     
     Rectangulo(22,8,26,8);
     gotoxy(27, 11);
     printf(" BIENVENIDOS A");
     gotoxy(27, 12);
     printf("CENTRO ESTETICA");
     getch();
     
     system("cls");
      
      do
      {
         system("cls");
         system("COLOR 2F");
         opcion = menu(titulo, opciones, n);
         system("cls");
         
         switch(opcion)
         {
                    case 1:
                           {
                               printf("\n\tModulo espacios");
                               ModuloEspacios();
                               break;
                           }
                    case 2:
                           {
                               printf("\n\tModulo del recepcion");
                               ModuloRecepcion();
                               break;
                           }
                    case 3:
                           {
                               printf("\n\tModulos Administracion");
                               ModuloAdministracion();
                               break;
                           }                     
                    case 4:
                           {
                              Rectangulo(22,8,26,8);
                              gotoxy(27, 11);
                              printf(" \"FIN DEL MENU");
                              gotoxy(27, 12);
                              printf("   PRINCIPAL\"");
                              getch();                   
                              break;
                           }
                    default:
                           {
                              printf("\n\n           \"Opcion INCORRECTA\".......");
                              break;
                           }                                
         }//FIN SWITCH
         getch();
         _flushall();
         printf("\n\n");
         system("cls");
      }while(opcion != 4);       
}
