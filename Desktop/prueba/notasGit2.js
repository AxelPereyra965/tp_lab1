//-----------repositorio local (git)

//primero pararme en la carpeta
cd NombreCarpeta
//crear un repositorio local
git init
//ver el estado (me dice los cambios y si hay que comitear algo)
git status
//subir el archivo a stage area
git  add  NombreArchivo /o git add .
//hacer el commit del archivo/s
git commit /o git  commit  - m  "mensaje del commit" //para comitear todo

//si no tenes un usuario configurado luego del commit te lo pide

//en el caso de que hagas un commit de un solo archivo
primero poner i (dejar un comentario de lo que hiciste)
segundo tocar "esc" y poner :wq


//---------repositorio en la nube (github)
//primero crear el repositorio en github
pones en crear repositorio
//anclear el repositorio de github con el local
git remote add LinkGithub
//hacer el push
git push 

//--------convertir nuestro repositorio en una githubPage
//primero instalar el componente gh Pages npm
eta dependencia deploya por nosotros nuestro proyecto en GitHub
//para instalarlo (se pone en la consola)
npm i gh-pages --save
//luego hacer un bill de la app (un build es hacer un enpaquetado)
npm run build //hace el build
//configurar en el archivo vite.config
base:"UrlGitHubPage",
//agregar en pakage jason (en la parte de scripts)
"predeploy": "npm run build",
"deploy": "gh-pages -d dist"
//hacer el deploy
npm run deploy

//despues al compartir mi github page ya se puede usar

//para cuando haga cambios
npm run deploy //estoy actualiza los cambios instantaneamente

//https://Axelpereyra12.github.io/"summer2024", milink




