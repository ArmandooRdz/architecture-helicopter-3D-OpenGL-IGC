NombreProgramaFuente=helicopter
NombreFichero=helicopter
rm $NombreProgramaFuente
g++ $NombreProgramaFuente.cpp -o $NombreProgramaFuente -lGL -lglut -lGLEW -lm
./$NombreProgramaFuente
