#include <cmath>
#include <iostream>

#define PI 3.14159

using std::ceil;
using std::cin;
using std::cout;
using std::endl;
using std::floor;

// Ricardo Adolfo Fernández Alvarado A01704813
// Damariz Licea Carrisoza A01369045

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
  int shirtsToProduce;
  float line1Production, line2Production;
  cout << "Ingrese las playeras a producir: ";
  cin >> shirtsToProduce;
  cout << "Ingrese la producción de la línea uno: ";
  cin >> line1Production;
  cout << "Ingrese la producción de la línea dos: ";
  cin >> line2Production;

  cout << "Cuantos días necesito para poder hacer "
       << shirtsToProduce
       << " playeras, si una de las máquinas "
       << "produce " << line1Production
       << " playeras al día, y la otra "
       << line2Production << " playeras al día: "
       << endl;
  cout << numberOfDays(line1Production, line2Production, shirtsToProduce) << " días\n\n";

  float bottleCapacity, baseRadius, height;
  cout << "Ingrese la capacidad (en mL) de la botella de refresco: ";
  cin >> bottleCapacity;
  cout << "Ingresa el radio del contenedor en metros: ";
  cin >> baseRadius;
  cout << "Ingresa la altura del contender en metros: ";
  cin >> height;

  cout << "Cuantas botellas de refresco puedo llenar, si cada botella contiene "
       << bottleCapacity << "mL "
       << "y mi tanque de refresco tiene unas medidas de " << baseRadius
       << "m de radio por " << height << "m de alto: "
       << endl;

  cout << numberOfSodaBottles(bottleCapacity, baseRadius, height) << " botellas\n\n";
}