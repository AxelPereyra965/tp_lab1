// comandos de consola

cd  nombre  de  la  carpeta //para pararme sobre una carpeta
pwd  //para saber en que carpeta estoy parado
npm en eso  //
npm  i  axios-- ​save  // instala axios en mi proyecto
npm  react  -​ save  // instala reaccionar al proyecto
npm  create  vite @ last  // instala la última versión de vite al proyecto
npm  run  dev  //me permite ejecutar el programa en un servidor

- almacenamiento local -

// comandos consola visual
los  3  puntitos  //ahi podes abrir la consola
cd  // tenes que pararte en el archivo (el nombre del archivo no la carpeta)
npm  run  dev  // arrancas el proyecto


//package-lok.JSON (carpeta donde se guarda todo lo que se va instalando)
//package-JSON (carpeta donde se guarda la información de las dependencias del proyecto)
//con npm se instalan las cosas necesarias
//para que reaccionar funcione necesita muchas cosas y para eso esta vite que es el empaquetado de esas cosas

-- -- -- -- -- -- -- -- -- -- -- -- -- -- - ordenar  carpetas -- -- -- -- -- -- -- -- -- -- -- - - -- -- -- -- -- -- -- -- -- -
//antes de empezar es recomendable ordenar las carpetas

active  //aca iran los archivos estaticos, haga las siguientes carpetas:
 - estilos //donde irán los estilos (archivos css)
 - statics  //aca iran las imagenes y react.svg

 contenedores  //aca iran las paginas

 componentes  //aca iran los componentes que cree


-- -- -- -- -- -- -- -- -- componentes -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
//un componente es una función, que se exporta al main
//el nombre de la función tiene que ser igual al componente
//los componentes tienen que empezar con mayuscula
ffc  // para crear un componente nuevo


//para que el componente se vea
- primero  se  exporta  en  la aplicación
- dentro  del  return  < poner  el  nombre  del  componente >  < / > //entre esas llaves

// < > componentes < > para escribir mas de una cosa en un componente

//como se debe escribir el componente para que no haya error
función Compo2
() {  //con esta parte abajo así como se ve
    retorno  (  <p> compo2 </p> ) ;​​​​​ 
}

//carpetas (para mover componentes a carpetas)
los app no ​​se mueven, sino los componentes que creen yo
y en la dirección poner .jsx al final

--------------------módulos (estilos)-------------------------- -------------
//para cada componente hacer su módulo (seria como su propio css)


// 1ro vas a crear archivo nuevo y pones:
NombreDelComponente.module.css
importar {  useState  } desde "reaccionar"
// 2do dentro del componente tenes que hacer un import del módulo
importar formulario de estilo './NombreDelModulo.style.css' //(esto seria como su url)

//dentro del módulo creas las clases
//para definir una clase en el componente se usa className= { style . nombreDeLaClase }

--------------------funciones-------------------------------- ---
//se declara dentro de la función pero antes del retorno


--------------------ganchos (herramientas)-------------------------- --------
//para usar las herramientas primero se incluso importa en el componente
//es una puerta trasera que avisa que esta pasandoalgo
import { NombreHerramienta } from 'react' //asi se importa

//herramientas:
useState //esta herramienta sirve para manejar el estado de un componente
//le avisa a reaccionar que algo en el dom cambio y lo acualiza para que se vea


//como usar componentes:
//al principio de la funcion tengo que fijar el estado de los componentes
const [NombreComponente, setNombreComponente] = useState (0 o "") //indica como va a arrancar

//despues tengo que usar el conjunto de esos componentes en la funcion setNombreComponente();


-------------------------------accesorios------------------ --------------
// Los props son la posibilidad de pasar datos de un componente a otro (del padre al hijo).
// Se pueden usar en useState.

// En el componente padre, cuando llamo al hijo se coloca lo que le voy a mandar:
< Componente  nombre = { setNombreNombrePersona }  txtbtn = { "Entrar" } / > // En este caso, pasé dos cosas.
// Este es usando useState, y este es normal.

// En el componente hijo:
// En la función se pone props.
function Componente(props) { } ;

// Luego se deconstruyen:
const {  nombre  } = accesorios;
const {  txtbtn  } = accesorios;

// A menos que uses en la llamada del padre:
// { ... ElNombre }
// Para usarlos se ponen entre llaves {Nombre}.
