#include <cmath>
#include <iostream>

#define PI 3.14159

using std::ceil;
using std::cout;
using std::endl;
using std::floor;

// PROBLEMA 1

/**
 * @brief Calcula la cantidad de días necesarios para producir n camisas, dada la producción diaria de dos líneas de producción.
 *
 * @param line1Production producción diaria de la línea 1
 * @param line2Production producción diaria de la línea 2
 * @param numberOfShirts cantidad de camisas a producir
 * @return los días de producción
 */
int numberOfDays(float line1Production, float line2Production, int numberOfShirts)
{
  // En este caso, sumamos la producción de ambas líneas, y luego dividimos la cantidad
  // de las playeras entre la producción. Finalmente, usamos ceil, dado que, si solo
  // podemos producir 8.5 playeras en 2 días pero requerimos nueve, no podemos entregar
  // la producción de esa manera, si no que habría que usar otro día de producción.
  return ceil((float)numberOfShirts / (line1Production + line2Production));
}

// PROBLEMA 2

/**
 * @brief Calcula el volumen de un cilindro con su base y su altura en mL
 *
 * @param baseRadius el radio de la base del cilindro en m
 * @param height la altura del cilindro en m
 * @return el volúmen del cilindro en mL
 */
float volumeOfCilinderCm(float baseRadius, float height)
{
  // Multiplicamos por 100 para cambiar los m por cm, para obtener cm3, que equivalen a
  // exactamente un mL.
  float baseRadiusCm = baseRadius * 100;
  float heightCm = height * 100;
  return PI * baseRadiusCm * baseRadiusCm * heightCm;
}

/**
 * @brief La cantidad de botellas que se pueden llenar con un cilindro, dadas las medidas del cilindro y el volumen de las botellas
 *
 * @param bottleCapacity la capacidad en mL de la botella de refresco
 * @param baseRadius el radio de la base del cilindro en m
 * @param height la altura del cilindro en m
 * @return la cantidad de botellas
 */
int numberOfSodaBottles(float bottleCapacity, float baseRadius, float height)
{
  // En este caso, usamos floor porque nos interesa saber cuantas botellas podemos rellenar
  // completamente antes de necesitar rellenar la máquina. Básicamente, si podemos llenar
  // 2.5 botellas con un tanque, solo podemos llenar 2 botellas completas
  return floor(volumeOfCilinderCm(baseRadius, height) / bottleCapacity);
}

int main()
{
  cout << "Cuantos días necesito para poder hacer 10 playeras, si una de las máquinas "
       << "produce 3.3 playeras al día, y la otra 0.8 playeras al día: " << endl;
  cout << numberOfDays(3.3, 0.8, 10) << " días\n\n";

  cout << "Cuantas botellas de refresco puedo llenar, si cada botella contiene 650 mL "
       << "y mi tanque de refresco tiene unas medidas de 0.5m de radio por 1.5m de alto: "
       << endl;

  cout << numberOfSodaBottles(650, 0.5, 1.5) << " botellas\n\n";
}